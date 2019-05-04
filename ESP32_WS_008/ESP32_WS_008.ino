/////////////////////////////////////////ID/////////////////////////////////////////
#define NODE 1
#define VERSION 1.02
#define NOEUX 0

//////////////////////////////////////CORE //////////////////////////////////
#if CONFIG_FREERTOS_UNICORE
#define CORE0 0
#define CORE1 0
#else
#define CORE0 0
#define CORE1 1
#endif

/////////////////////////////////////////Adresse/////////////////////////////////////
#define adr (((1+(NODE-1))*15)-14)

/////////////////////////////////////////Debug///////////////////////////////////////
#define DEBUG 1
#define DEBUG_dmx 1
//#define DEBUG_STR 1

/////////////////////////////////////////lib/////////////////////////////////////////
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArtnetWifi.h> //https://github.com/rstephan/ArtnetWifi
#include "esp32_digital_led_lib.h"

#define min(m,n) ((m)<(n)?(m):(n))

#include <algorithm>
#include <initializer_list>
template <typename T>
bool is_in(const T& v, std::initializer_list<T> lst) {
  return std::find(std::begin(lst), std::end(lst), v) != std::end(lst);
}

///////////////////////////////Config//////////////////////////////////

#define NUM_STRIPS  4
#define NUM_LEDS_PER_STRIP  150
#define NUM_LEDS_TOTAL  NUM_STRIPS * NUM_LEDS_PER_STRIP
const int PINS[NUM_STRIPS] = {23, 22, 18, 5};
const int MG = ((NUM_LEDS_PER_STRIP + 1) / NUM_STRIPS);

#define STROB_ON_MS 15          // Strobe duration
#define WIFI_BLACKOUT 10        // Time to check if wifi is still here  OR blackout


///////////////////////////////////leds variables////////////////////////////////////

const int numberOfChannels = NUM_STRIPS * NUM_LEDS_PER_STRIP * 3;
strand_t STRANDS[NUM_STRIPS];
strand_t * strands [] = { &STRANDS[0], &STRANDS[1], &STRANDS[2], &STRANDS[3]};
bool randArray[NUM_LEDS_TOTAL];

///////////////////////////////////dmx variables////////////////////////////////////
ArtnetWifi artnet;

pixelColor_t pix_buffer[NUM_STRIPS][NUM_LEDS_PER_STRIP];  // Buffer principal
pixelColor_t pix_colorA[NUM_STRIPS][NUM_LEDS_PER_STRIP];  // Color
pixelColor_t pix_colorB[NUM_STRIPS][NUM_LEDS_PER_STRIP];  // Color2 (background)

// DMX Variables
//
int _Master;
pixelColor_t _Color;    // rr, gg, bb
int _Fx_mod;
int _Pix_mod;
int _Pix_start;
int _Pix_pos_v;
int _Modulo = 0;
unsigned int _Strobe_ws = 0;
pixelColor_t _Color2;    // srr, sgg, sbb
int _Color_mode;
int _Mirror = 1;

// DMX derivative variables
//
int _Fx_type = 0;
int _Modulo_type = 0;
int _Pix_start_v;
int _Pix_pos;
int _Pix_center;
int _Pix_end;
unsigned long _Strobe_ws_last = 0;

int N_L_P_S = NUM_LEDS_PER_STRIP;
int M_g[NUM_STRIPS][2];
int S_seuil;


///////////////////////////////////////////////// SETUP ////////////////////////////////////////

void setup() {

#ifdef DEBUG
  Serial.begin(115200);
  Serial.printf("Starting NODE %d  @  %d:%d ", NODE, NOEUX, adr);
#endif

  leds_init();
  ConnectWifi();
  ota_setup();
  artnet.begin();
  artnet.setArtDmxCallback(onDmxFrame);
  initTest();

  //xTaskCreatePinnedToCore(modulo_task, "modulo_task", 4096, NULL, 1, NULL, CORE1);    // core 1 = loop
  xTaskCreatePinnedToCore(color_task, "color_task", 4096, NULL, 1, NULL, CORE1);      // core 1 = loop
  xTaskCreatePinnedToCore(fx_task, "fx_task", 4096, NULL, 1, NULL, CORE0);            // core 0 = wifi

}//setup

///////////////////////////////////////// LOOP /////////////////////////////////////////////////
void loop() {
#ifdef DEBUG
  Serial.println("//////////////////////////////void loop() {");
#endif

  // Wifi check
  if (wifi_isok()) {
#ifdef DEBUG
    Serial.println("//////////////////////////////wifi_isok()");
#endif
    artnet.read();
#ifdef DEBUG
    Serial.println("//////////////////////////////artnet.read();");
#endif
    modulo_task();  // SYNC WITH ARTNET
#ifdef DEBUG
    Serial.println("//////////////////////////////modulo_task();");
#endif
    ota_loop();
#ifdef DEBUG
    Serial.println("//////////////////////////////ota_loop();");
#endif
  }

  // Blackout if no wifi
  static unsigned long lastRefresh = 0;
  if (abs(millis() - lastRefresh) > WIFI_BLACKOUT) {
    if (!wifi_isok()) ledBlack(); //passe led noir
    lastRefresh = millis();
  }

}//loop
