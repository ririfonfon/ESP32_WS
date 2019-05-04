
///////////////////////////////////  MODULO THREAD

//void modulo_task( void * pvParameters ) {
//void modulo_task() {
//#ifdef DEBUG
//  Serial.println("modulo_task()");
//#endif
//  while (true) {
//    eff_modulo();
//    yield(); // rend la main
//  }
//
//  vTaskDelete(NULL);
//}


///////////////////////////////////  UTILS

// Get PIXEL
// Pixel from pix_buffer with MASTER, MIRROR and MODULATION applied
//
pixelColor_t getPix_n( int strip, int i, float modulation = 1.0) {
  if (modulation == 0) return pixelFromRGB(0, 0, 0);
  pixelColor_t p;
  p = pix_buffer[strip][getMirroredPixNum(i)] * (_Master / 255.0);
  if (modulation != 1.0) p = p * modulation;
  return p;
}


// MIRROR FX
// Change pixel position to apply Mirror effect
//
int getMirroredPixNum(int i) {
  if ((i / N_L_P_S) % 2 == 0) return (i % N_L_P_S);                   // paire = dans le bon sens
  if ((i / N_L_P_S) % 2 == 1) return N_L_P_S - (i % N_L_P_S) - 1;  // impaire = inversé
}


bool strobe = false;
int old_S_seuil = 0;
float str_blind_ws = 1;
int ran;

///////////////////////////////////  MODULO FONCTION

// EFFECT MODULO
//
void eff_modulo()
{
 #ifdef DEBUG
    Serial.println("void eff_modulo()");
    Serial.print(" _Modulo_type ==");
    Serial.println(_Modulo_type);
#endif
  unsigned long t_now = millis();

  // NO MODULO
  if ( _Modulo_type == 0 ) {

    for (int strip = 0 ; strip < NUM_STRIPS ; strip++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        strands[strip]->pixels[i] = getPix_n( strip, i );

  }//modulo 0

  // STROBE
  else if ( _Modulo_type == 1) {

    if (!strobe && t_now - _Strobe_ws_last > _Strobe_ws) {
      _Strobe_ws_last = t_now;
      strobe = true;
    }
    else if (strobe && t_now - _Strobe_ws_last > STROB_ON_MS) {
      _Strobe_ws_last = t_now;
      strobe = false;
    }
    else return;

    for (int strip = 0 ; strip < NUM_STRIPS ; strip++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        strands[strip]->pixels[i] = getPix_n(strip, i, strobe);

  }//modulo 1

  // TIME MODULO
  else if (_Modulo_type == 2) {

    if (_Strobe_ws <= 0) _Strobe_ws = 1;
    float time_modulo = _Strobe_ws;
    float module = 2 * abs( (t_now % _Strobe_ws) - time_modulo / 2) / time_modulo;
    module *= module;

    for (int strip = 0 ; strip < NUM_STRIPS ; strip++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        strands[strip]->pixels[i] = getPix_n(strip, i, module);

  }// modulo 2

  // RANDOM BLINK
  else if ( _Modulo_type == 3 ) {
    if (!strobe && t_now - _Strobe_ws_last > _Strobe_ws) {
      _Strobe_ws_last = t_now;
      strobe = true;
    }
    else if (strobe && t_now - _Strobe_ws_last > STROB_ON_MS) {
      _Strobe_ws_last = t_now;
      strobe = false;
      black();
    }
    else return;

    int n_led_to_show = (min(NUM_LEDS_TOTAL - 8, S_seuil));
    int n_strip = 0;
    int p = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        ran = random( 0 , NUM_LEDS_TOTAL );
        n_strip = ran / NUM_LEDS_PER_STRIP;
        p = ran - (NUM_LEDS_PER_STRIP * n_strip);
      } while (strands[n_strip]->pixels[p].r != 0 || strands[n_strip]->pixels[p].g != 0 || strands[n_strip]->pixels[p].b != 0);

      strands[n_strip]->pixels[p] = getPix_n(n_strip, p, strobe);

    }//for i

  }//modulo 3

  // ANOTHER STROBE
  else if ( _Modulo_type == 4) {

    if (!strobe && _Strobe_ws_last < t_now && t_now - _Strobe_ws_last > _Strobe_ws / (str_blind_ws * str_blind_ws)) {
      _Strobe_ws_last = t_now;
      strobe = true;
      str_blind_ws = str_blind_ws + 0.05;
      if (str_blind_ws >= 3) {
        str_blind_ws = 1;
        // Noir pendant 1 sec (dans le futur)
        strobe = false;
        _Strobe_ws_last = t_now + 1000;
      }
    }
    else if (strobe && _Strobe_ws_last < t_now && t_now - _Strobe_ws_last > (STROB_ON_MS)) {
      _Strobe_ws_last = t_now;
      strobe = false;
    }
    else return;

    for (int strip = 0 ; strip < NUM_STRIPS ; strip++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        strands[strip]->pixels[i] = getPix_n(strip, i, strobe);

  }//modulo 4

  // ANOTHER RANDOM BLINK
  else if ( _Modulo_type == 5 ) {

    int S_seuil_B;
    if (!strobe && _Strobe_ws_last < t_now && t_now - _Strobe_ws_last > _Strobe_ws / (str_blind_ws * str_blind_ws)) {
      _Strobe_ws_last = t_now;
      strobe = true;
      str_blind_ws = str_blind_ws + 0.05;
      if (str_blind_ws >= 3) {
        str_blind_ws = 1;
        // Noir pendant 1 sec (dans le futur)
        strobe = false;
        _Strobe_ws_last = t_now + 1000;
      }
    }
    else if (strobe && _Strobe_ws_last < t_now && t_now - _Strobe_ws_last > (STROB_ON_MS)) {
      _Strobe_ws_last = t_now;
      strobe = false;
      black();
    }
    else return;

    int n_led_to_show = min(NUM_LEDS_TOTAL - 8, S_seuil);
    int n_strip = 0;
    int p = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        ran = random( 0 , NUM_LEDS_TOTAL );
        n_strip = ran / NUM_LEDS_PER_STRIP;
        p = ran - (NUM_LEDS_PER_STRIP * n_strip);
      } while (strands[n_strip]->pixels[p].r != 0 || strands[n_strip]->pixels[p].g != 0 || strands[n_strip]->pixels[p].b != 0);

      strands[n_strip]->pixels[p] = getPix_n(n_strip, p, strobe);
    }

  }//modulo 5

  // RANDOM FILL
  else if ( _Modulo_type == 6 ) {

    if (old_S_seuil != S_seuil) {
      black();
      old_S_seuil = S_seuil;
    }
    int S_seuil_B;

    int n_led_to_show = min(NUM_LEDS_TOTAL - 8, S_seuil);
    int n_strip = 0;
    int p = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        ran = random( 0 , NUM_LEDS_TOTAL );
        n_strip = ran / NUM_LEDS_PER_STRIP;
        p = ran - (NUM_LEDS_PER_STRIP * n_strip);
      } while (strands[n_strip]->pixels[p].r != 0 || strands[n_strip]->pixels[p].g != 0 || strands[n_strip]->pixels[p].b != 0);

      strands[n_strip]->pixels[p] = getPix_n(n_strip, p);
    }//for i
    old_S_seuil = S_seuil - 1;

  }//modulo 6

}//eff_modulo
