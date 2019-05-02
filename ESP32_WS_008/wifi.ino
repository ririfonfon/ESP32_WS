/////////////////////////////////////////lib/////////////////////////////////////////
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArtnetWifi.h>

///////////////////////////////////////// WIFI settings /////////////////////////////////////
const char* ssid = "riri";
const char* password = "288F42E7E8";


////////////////////////////////////////// WIFI
bool wifi_available = false;

void ConnectWifi() {
  IPAddress ip(2, 0, 0, NODE + 100); // Static IP
  IPAddress gateway(2, 0, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  // Enable wifi
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);

  WiFi.onEvent(wifi_event);
//  WiFi.begin(ssid, password);
  WiFi.begin(ssid, password);
#ifdef DEBUG
  Serial.println("");
  Serial.println("Connecting to WiFi");
  // Wait for connection
  Serial.println("Connecting");
#endif
}//ConnectWifi

void wifi_event(WiFiEvent_t event) {
  static byte retry = 0;
  static byte maxRetry = 15;

  switch (event) {
    case SYSTEM_EVENT_STA_DISCONNECTED:
      _Master = 0;
      _Color = pixelFromRGB(0,0,0);
      _Fx_mod= 0;
      _Pix_mod = 0;
      _Pix_start = 0;
      _Pix_start_v = 1;
      _Modulo = 0;
      _Strobe_ws = 0;
      _Pix_center = 0;
      _Color2 = pixelFromRGB(0,0,0);
      _Color_mode = 0;

      _Mirror = 1;
      break;
  }

#ifdef DEBUG
  switch (event) {
    case SYSTEM_EVENT_STA_CONNECTED:
      Serial.print("WiFi connected - ");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      Serial.print("Got IP - ");
      Serial.println(WiFi.localIP());
      break;
    case SYSTEM_EVENT_STA_LOST_IP:
      Serial.print("Lost IP..");
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.print("WiFi lost connection... ");
      break;
  }
#endif

  if (event == SYSTEM_EVENT_STA_DISCONNECTED) {
    wifi_available = false;
    retry += 1;

#ifdef DEBUG
    Serial.print(" reconnecting ");
    Serial.print(retry);
    Serial.print("/");
    Serial.println(maxRetry);
#endif
    WiFi.reconnect();
  }
  else if (event == SYSTEM_EVENT_STA_GOT_IP) {
    wifi_available = true;
    retry = 0;
  }
}// wifi_event

bool wifi_isok() {
  return wifi_available;
}//wifi_isok()


//////////////////////////////////////////   OTA 

#include <ESPmDNS.h>
#include <ArduinoOTA.h>

void ota_setup() {
  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  String nameDevice = "ESP32-";
  //nameDevice += (uint32_t)ESP.getEfuseMac();
  nameDevice += NODE;
  nameDevice += " v ";
  nameDevice += VERSION;
  ArduinoOTA.setHostname(nameDevice.c_str());

  // No authentication by default
  // ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.onStart([]() {
    //LOG("Start");
  });
  ArduinoOTA.onEnd([]() {
    //LOG("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    //LOGF("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    //LOGF("Error[%u]: ", error);
    //if (error == OTA_AUTH_ERROR) LOG("Auth Failed");
    //else if (error == OTA_BEGIN_ERROR) LOG("Begin Failed");
    //else if (error == OTA_CONNECT_ERROR) LOG("Connect Failed");
    //else if (error == OTA_RECEIVE_ERROR) LOG("Receive Failed");
    //else if (error == OTA_END_ERROR) LOG("End Failed");
  });
  ArduinoOTA.begin();
}

void ota_loop() {
  ArduinoOTA.handle();
}
