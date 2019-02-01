
void eff_modulo() {
  unsigned long t_now = millis();
  if ( type_modulo == 0 ) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[i] / 255) * master), ((pi_n_0_g[i] / 255) * master), ((pi_n_0_b[i] / 255) * master));
      strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[i] / 255) * master), ((pi_n_1_g[i] / 255) * master), ((pi_n_1_b[i] / 255) * master));
      strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[i] / 255) * master), ((pi_n_2_g[i] / 255) * master), ((pi_n_2_b[i] / 255) * master));
      strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[i] / 255) * master), ((pi_n_3_g[i] / 255) * master), ((pi_n_3_b[i] / 255) * master));
    }

  }
  else if ( type_modulo == 1) {
    if (str == 0 && t_now - str_ws_last > str_ws) {
      str_ws_last = t_now;
      str = 1;
    } else if (str == 1 && t_now - str_ws_last > STROB_ON_MS) {
      str_ws_last = t_now;
      str = 0;
    } else {
      return;
    }
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * master / 255), (pi_n_0_g[i] * str * master / 255), (pi_n_0_b[i] * str * master / 255));
      strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * master / 255), (pi_n_1_g[i] * str * master / 255), (pi_n_1_b[i] * str * master / 255));
      strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * master / 255), (pi_n_2_g[i] * str * master / 255), (pi_n_2_b[i] * str * master / 255));
      strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * master / 255), (pi_n_3_g[i] * str * master / 255), (pi_n_3_b[i] * str * master / 255));
    }

  }//modulo 1

  else if (type_modulo == 2) {
    if (str_ws <= 0) str_ws = 1;
    float time_modulo = str_ws;
    float module = 2 * abs( (t_now % str_ws) - time_modulo / 2) / time_modulo;
    module *= module;
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * module * master / 255), (pi_n_0_g[i] * module * master / 255), (pi_n_0_b[i] * module * master / 255));
      strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * module * master / 255), (pi_n_1_g[i] * module * master / 255), (pi_n_1_b[i] * module * master / 255));
      strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * module * master / 255), (pi_n_2_g[i] * module * master / 255), (pi_n_2_b[i] * module * master / 255));
      strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * module * master / 255), (pi_n_3_g[i] * module * master / 255), (pi_n_3_b[i] * module * master / 255));
    }

  }// modulo 2

  else if ( type_modulo == 3 ) {
    if (str == 0 && t_now - str_ws_last > str_ws) {
      str_ws_last = t_now;
      str = 1;
    } else if (str == 1 && t_now - str_ws_last > STROB_ON_MS) {
      str_ws_last = t_now;
      str = 0;
      Black();
    } else {
      return;
    }

    int n_led_to_show = (min(numberOfLed - 8, S_seuil));
    int n_strip = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
      } while (strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].r != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].g != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].b != 0);

      if (n_strip == 0) {
        strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      } else if (n_strip == 1) {
        strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      } else if (n_strip == 2) {
        strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      } else if (n_strip == 3) {
        strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      }
    }//for i
  }//modulo 3

  else if ( type_modulo == 4) {
    if (str == 0 && str_ws_last < t_now && t_now - str_ws_last > str_ws / (str_blind_ws * str_blind_ws)) {
      str_ws_last = t_now;
      str = 1;
      str_blind_ws = str_blind_ws + 0.05;
      if (str_blind_ws >= 3) {
        str_blind_ws = 1;
        // Noir pendant 1 sec (dans le futur)
        str = 0;
        str_ws_last = t_now + 1000;
      }
    } else if (str == 1 && str_ws_last < t_now && t_now - str_ws_last > (STROB_ON_MS)) {
      str_ws_last = t_now;
      str = 0;
    } else {
      return;
    }
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * master / 255), (pi_n_0_g[i] * str * master / 255), (pi_n_0_b[i] * str * master / 255));
      strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * master / 255), (pi_n_1_g[i] * str * master / 255), (pi_n_1_b[i] * str * master / 255));
      strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * master / 255), (pi_n_2_g[i] * str * master / 255), (pi_n_2_b[i] * str * master / 255));
      strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * master / 255), (pi_n_3_g[i] * str * master / 255), (pi_n_3_b[i] * str * master / 255));
    }

  }//modulo 4
  else if ( type_modulo == 5 ) {
    int S_seuil_B;
    if (str == 0 && str_ws_last < t_now && t_now - str_ws_last > str_ws / (str_blind_ws * str_blind_ws)) {
      str_ws_last = t_now;
      str = 1;
      str_blind_ws = str_blind_ws + 0.05;
      if (str_blind_ws >= 3) {
        str_blind_ws = 1;
        // Noir pendant 1 sec (dans le futur)
        str = 0;
        str_ws_last = t_now + 1000;
      }
    } else if (str == 1 && str_ws_last < t_now && t_now - str_ws_last > (STROB_ON_MS)) {
      str_ws_last = t_now;
      str = 0;
      Black();
    } else {
      return;
    }

    int n_led_to_show = min(numberOfLed - 8, S_seuil);
    int n_strip = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
      } while (strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].r != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].g != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].b != 0 );
      if (n_strip == 0) {
        strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      } else if (n_strip == 1) {
        strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      } else if (n_strip == 2) {
        strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      } else if (n_strip == 3) {
        strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * master / 255));
      }
    }//for i
  }//modulo 5

  else if ( type_modulo == 6 ) {
    if (old_S_seuil != S_seuil) {
      Black();
      old_S_seuil = S_seuil;
    }
    int S_seuil_B;
    int n_led_to_show = min(numberOfLed - 8, S_seuil);
    int n_strip = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
      } while (strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].r != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].g != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].b != 0 );
      if (n_strip == 0) {
        strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255));
      } else if (n_strip == 1) {
        strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255));
      } else if (n_strip == 2) {
        strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255));
      } else if (n_strip == 3) {
        strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * master / 255));
      }
    }//for i
    old_S_seuil = S_seuil - 1;
  }//modulo 6

  //  else if ( type_modulo == 6 ) {
  //    if (old_S_seuil != S_seuil) {
  //      for (int i = 0; i < numberOfLed; i++) {
  //        randArray[i] = false;
  //      }
  //      old_S_seuil = S_seuil;
  //
  //      int n_led_to_show = (min(numberOfLed - 8, S_seuil));
  //      int n_strip = 0;
  //
  //      for (int i = 0; i < n_led_to_show ; i ++) {
  //        do {
  //          a = random( 0 , numberOfLed );
  //          n_strip = a / NUM_LEDS_PER_STRIP;
  //        } while (randArray[a]);
  //        randArray[a] = true;
  //      }//for i
  //    }// if old_S_seuil
  //
  //    Black();
  //    for (int i = 0; i < numberOfLed; i++) {
  //      if (randArray[i]) {
  //        int n_strip = i / NUM_LEDS_PER_STRIP;
  //        if (n_strip == 0) {
  //          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255));
  //        } else if (n_strip == 1) {
  //          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255));
  //        } else if (n_strip == 2) {
  //          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255));
  //        } else if (n_strip == 3) {
  //          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  master / 255));
  //        }
  //      }
  //    }//for i
  //    return;
  //  }//modulo 6
}//eff_modulo
