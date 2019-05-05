
void eff__Modulo() {
  unsigned long t_now = millis();
  if ( type__Modulo == 0 ) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[i] / 255) * _Master), ((pi_n_0_g[i] / 255) * _Master), ((pi_n_0_b[i] / 255) * _Master));
      strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[i] / 255) * _Master), ((pi_n_1_g[i] / 255) * _Master), ((pi_n_1_b[i] / 255) * _Master));
      strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[i] / 255) * _Master), ((pi_n_2_g[i] / 255) * _Master), ((pi_n_2_b[i] / 255) * _Master));
      strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[i] / 255) * _Master), ((pi_n_3_g[i] / 255) * _Master), ((pi_n_3_b[i] / 255) * _Master));
    }

  }
  else if ( type__Modulo == 1) {
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
      strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
      strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
      strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
      strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
    }

  }//_Modulo 1

  else if (type__Modulo == 2) {
    if (str_ws <= 0) str_ws = 1;
    float time__Modulo = str_ws;
    float module = 2 * abs( (t_now % str_ws) - time__Modulo / 2) / time__Modulo;
    module *= module;
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * module * _Master / 255), (pi_n_0_g[i] * module * _Master / 255), (pi_n_0_b[i] * module * _Master / 255));
      strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * module * _Master / 255), (pi_n_1_g[i] * module * _Master / 255), (pi_n_1_b[i] * module * _Master / 255));
      strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * module * _Master / 255), (pi_n_2_g[i] * module * _Master / 255), (pi_n_2_b[i] * module * _Master / 255));
      strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * module * _Master / 255), (pi_n_3_g[i] * module * _Master / 255), (pi_n_3_b[i] * module * _Master / 255));
    }

  }// _Modulo 2

  else if ( type__Modulo == 3 ) {
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
        strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      } else if (n_strip == 1) {
        strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      } else if (n_strip == 2) {
        strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      } else if (n_strip == 3) {
        strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      }
    }//for i
  }//_Modulo 3

  else if ( type__Modulo == 4) {
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
      strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
      strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
      strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
      strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
    }

  }//_Modulo 4
  else if ( type__Modulo == 5 ) {
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
        strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      } else if (n_strip == 1) {
        strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      } else if (n_strip == 2) {
        strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      } else if (n_strip == 3) {
        strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
      }
    }//for i
  }//_Modulo 5

  else if ( type__Modulo == 6 ) {
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
        strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
      } else if (n_strip == 1) {
        strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
      } else if (n_strip == 2) {
        strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
      } else if (n_strip == 3) {
        strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
      }
    }//for i
    old_S_seuil = S_seuil - 1;
  }//_Modulo 6

  //  else if ( type__Modulo == 6 ) {
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
  //          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255));
  //        } else if (n_strip == 1) {
  //          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255));
  //        } else if (n_strip == 2) {
  //          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255));
  //        } else if (n_strip == 3) {
  //          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] *  _Master / 255));
  //        }
  //      }
  //    }//for i
  //    return;
  //  }//_Modulo 6

  if ( type__Modulo == 10 ) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[i] / 255) * _Master), ((pi_n_0_g[i] / 255) * _Master), ((pi_n_0_b[i] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[i] / 255) * _Master), ((pi_n_1_g[i] / 255) * _Master), ((pi_n_1_b[i] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[i] / 255) * _Master), ((pi_n_2_g[i] / 255) * _Master), ((pi_n_2_b[i] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[i] / 255) * _Master), ((pi_n_3_g[i] / 255) * _Master), ((pi_n_3_b[i] / 255) * _Master));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * _Master), ((pi_n_0_g[di] / 255) * _Master), ((pi_n_0_b[di] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * _Master), ((pi_n_1_g[di] / 255) * _Master), ((pi_n_1_b[di] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * _Master), ((pi_n_2_g[di] / 255) * _Master), ((pi_n_2_b[di] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * _Master), ((pi_n_3_g[di] / 255) * _Master), ((pi_n_3_b[di] / 255) * _Master));
      }
    }
  }//_Modulo 10
  else if ( type__Modulo == 11) {
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
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
      }
    }
  }//_Modulo 11

  else if (type__Modulo == 12) {
    if (str_ws <= 0) str_ws = 1;
    float time__Modulo = str_ws;
    float module = 2 * abs( (t_now % str_ws) - time__Modulo / 2) / time__Modulo;
    module *= module;
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * module * _Master / 255), (pi_n_0_g[i] * module * _Master / 255), (pi_n_0_b[i] * module * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * module * _Master / 255), (pi_n_1_g[i] * module * _Master / 255), (pi_n_1_b[i] * module * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * module * _Master / 255), (pi_n_2_g[i] * module * _Master / 255), (pi_n_2_b[i] * module * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * module * _Master / 255), (pi_n_3_g[i] * module * _Master / 255), (pi_n_3_b[i] * module * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * module * _Master / 255), (pi_n_0_g[di] * module * _Master / 255), (pi_n_0_b[di] * module * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * module * _Master / 255), (pi_n_1_g[di] * module * _Master / 255), (pi_n_1_b[di] * module * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * module * _Master / 255), (pi_n_2_g[di] * module * _Master / 255), (pi_n_2_b[di] * module * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * module * _Master / 255), (pi_n_3_g[di] * module * _Master / 255), (pi_n_3_b[di] * module * _Master / 255));
      }
    }
  }// _Modulo 12

  else if ( type__Modulo == 13 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      }
      else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
        }
      }
    }//for i
  }//_Modulo 13

  else if ( type__Modulo == 14) {
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
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
      }
    }

  }//_Modulo 14
  else if ( type__Modulo == 15 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      }
      else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
        }
      }
    }//for i
  }//_Modulo 15

  else if ( type__Modulo == 16 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      }
      else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[di] * _Master / 255), (pi_n_1_g[di] * _Master / 255), (pi_n_1_b[di] * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[di] * _Master / 255), (pi_n_2_g[di] * _Master / 255), (pi_n_2_b[di] * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, NUM_LEDS_PER_STRIP, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[di] * _Master / 255), (pi_n_3_g[di] * _Master / 255), (pi_n_3_b[di] * _Master / 255));
        }
      }
    }//for i
    old_S_seuil = S_seuil - 1;
  }//_Modulo 16

  if ( type__Modulo == 20 ) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[i] / 255) * _Master), ((pi_n_0_g[i] / 255) * _Master), ((pi_n_0_b[i] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[i] / 255) * _Master), ((pi_n_1_g[i] / 255) * _Master), ((pi_n_1_b[i] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[i] / 255) * _Master), ((pi_n_2_g[i] / 255) * _Master), ((pi_n_2_b[i] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[i] / 255) * _Master), ((pi_n_3_g[i] / 255) * _Master), ((pi_n_3_b[i] / 255) * _Master));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * _Master), ((pi_n_0_g[di] / 255) * _Master), ((pi_n_0_b[di] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * _Master), ((pi_n_1_g[di] / 255) * _Master), ((pi_n_1_b[di] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * _Master), ((pi_n_2_g[di] / 255) * _Master), ((pi_n_2_b[di] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * _Master), ((pi_n_3_g[di] / 255) * _Master), ((pi_n_3_b[di] / 255) * _Master));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * _Master), ((pi_n_0_g[di] / 255) * _Master), ((pi_n_0_b[di] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * _Master), ((pi_n_1_g[di] / 255) * _Master), ((pi_n_1_b[di] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * _Master), ((pi_n_2_g[di] / 255) * _Master), ((pi_n_2_b[di] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * _Master), ((pi_n_3_g[di] / 255) * _Master), ((pi_n_3_b[di] / 255) * _Master));
      }
    }
  }//_Modulo 20
  else if ( type__Modulo == 21) {
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
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * str * _Master), ((pi_n_0_g[di] / 255) * str * _Master), ((pi_n_0_b[di] / 255) * str * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * str * _Master), ((pi_n_1_g[di] / 255) * str * _Master), ((pi_n_1_b[di] / 255) * str * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * str * _Master), ((pi_n_2_g[di] / 255) * str * _Master), ((pi_n_2_b[di] / 255) * str * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * str * _Master), ((pi_n_3_g[di] / 255) * str * _Master), ((pi_n_3_b[di] / 255) * str * _Master));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * str * _Master), ((pi_n_0_g[di] / 255) * str * _Master), ((pi_n_0_b[di] / 255) * str * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * str * _Master), ((pi_n_1_g[di] / 255) * str * _Master), ((pi_n_1_b[di] / 255) * str * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * str * _Master), ((pi_n_2_g[di] / 255) * str * _Master), ((pi_n_2_b[di] / 255) * str * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * str * _Master), ((pi_n_3_g[di] / 255) * str * _Master), ((pi_n_3_b[di] / 255) * str * _Master));
      }
    }
  }//_Modulo 21

  else if (type__Modulo == 22) {
    if (str_ws <= 0) str_ws = 1;
    float time__Modulo = str_ws;
    float module = 2 * abs( (t_now % str_ws) - time__Modulo / 2) / time__Modulo;
    module *= module;
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * module * _Master / 255), (pi_n_0_g[i] * module * _Master / 255), (pi_n_0_b[i] * module * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * module * _Master / 255), (pi_n_1_g[i] * module * _Master / 255), (pi_n_1_b[i] * module * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * module * _Master / 255), (pi_n_2_g[i] * module * _Master / 255), (pi_n_2_b[i] * module * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * module * _Master / 255), (pi_n_3_g[i] * module * _Master / 255), (pi_n_3_b[i] * module * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * module * _Master), ((pi_n_0_g[di] / 255) * module * _Master), ((pi_n_0_b[di] / 255) * module * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * module * _Master), ((pi_n_1_g[di] / 255) * module * _Master), ((pi_n_1_b[di] / 255) * module * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * module * _Master), ((pi_n_2_g[di] / 255) * module * _Master), ((pi_n_2_b[di] / 255) * module * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * module * _Master), ((pi_n_3_g[di] / 255) * module * _Master), ((pi_n_3_b[di] / 255) * module * _Master));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * module * _Master), ((pi_n_0_g[di] / 255) * module * _Master), ((pi_n_0_b[di] / 255) * module * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * module * _Master), ((pi_n_1_g[di] / 255) * module * _Master), ((pi_n_1_b[di] / 255) * module * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * module * _Master), ((pi_n_2_g[di] / 255) * module * _Master), ((pi_n_2_b[di] / 255) * module * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * module * _Master), ((pi_n_3_g[di] / 255) * module * _Master), ((pi_n_3_b[di] / 255) * module * _Master));
      }
    }
  }// _Modulo 22

  else if ( type__Modulo == 23 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      }
    }//for i
  }//_Modulo 23

  else if ( type__Modulo == 24) {
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
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
      }
    }

  }//_Modulo 24
  else if ( type__Modulo == 25 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      }
    }//for i
  }//_Modulo 25

  else if ( type__Modulo == 26 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      } else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      }
    }//for i
    old_S_seuil = S_seuil - 1;
  }//_Modulo 26



  if ( type__Modulo == 30 ) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[i] / 255) * _Master), ((pi_n_0_g[i] / 255) * _Master), ((pi_n_0_b[i] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[i] / 255) * _Master), ((pi_n_1_g[i] / 255) * _Master), ((pi_n_1_b[i] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[i] / 255) * _Master), ((pi_n_2_g[i] / 255) * _Master), ((pi_n_2_b[i] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[i] / 255) * _Master), ((pi_n_3_g[i] / 255) * _Master), ((pi_n_3_b[i] / 255) * _Master));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * _Master), ((pi_n_0_g[di] / 255) * _Master), ((pi_n_0_b[di] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * _Master), ((pi_n_1_g[di] / 255) * _Master), ((pi_n_1_b[di] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * _Master), ((pi_n_2_g[di] / 255) * _Master), ((pi_n_2_b[di] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * _Master), ((pi_n_3_g[di] / 255) * _Master), ((pi_n_3_b[di] / 255) * _Master));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * _Master), ((pi_n_0_g[di] / 255) * _Master), ((pi_n_0_b[di] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * _Master), ((pi_n_1_g[di] / 255) * _Master), ((pi_n_1_b[di] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * _Master), ((pi_n_2_g[di] / 255) * _Master), ((pi_n_2_b[di] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * _Master), ((pi_n_3_g[di] / 255) * _Master), ((pi_n_3_b[di] / 255) * _Master));
      } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        int di = map(i, (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * _Master), ((pi_n_0_g[di] / 255) * _Master), ((pi_n_0_b[di] / 255) * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * _Master), ((pi_n_1_g[di] / 255) * _Master), ((pi_n_1_b[di] / 255) * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * _Master), ((pi_n_2_g[di] / 255) * _Master), ((pi_n_2_b[di] / 255) * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * _Master), ((pi_n_3_g[di] / 255) * _Master), ((pi_n_3_b[di] / 255) * _Master));
      }
    }
  }//_Modulo 30
  else if ( type__Modulo == 31) {
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
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * str * _Master), ((pi_n_0_g[di] / 255) * str * _Master), ((pi_n_0_b[di] / 255) * str * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * str * _Master), ((pi_n_1_g[di] / 255) * str * _Master), ((pi_n_1_b[di] / 255) * str * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * str * _Master), ((pi_n_2_g[di] / 255) * str * _Master), ((pi_n_2_b[di] / 255) * str * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * str * _Master), ((pi_n_3_g[di] / 255) * str * _Master), ((pi_n_3_b[di] / 255) * str * _Master));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * str * _Master), ((pi_n_0_g[di] / 255) * str * _Master), ((pi_n_0_b[di] / 255) * str * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * str * _Master), ((pi_n_1_g[di] / 255) * str * _Master), ((pi_n_1_b[di] / 255) * str * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * str * _Master), ((pi_n_2_g[di] / 255) * str * _Master), ((pi_n_2_b[di] / 255) * str * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * str * _Master), ((pi_n_3_g[di] / 255) * str * _Master), ((pi_n_3_b[di] / 255) * str * _Master));
      } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        int di = map(i, (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * str * _Master), ((pi_n_0_g[di] / 255) * str * _Master), ((pi_n_0_b[di] / 255) * str * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * str * _Master), ((pi_n_1_g[di] / 255) * str * _Master), ((pi_n_1_b[di] / 255) * str * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * str * _Master), ((pi_n_2_g[di] / 255) * str * _Master), ((pi_n_2_b[di] / 255) * str * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * str * _Master), ((pi_n_3_g[di] / 255) * str * _Master), ((pi_n_3_b[di] / 255) * str * _Master));
      }
    }
  }//_Modulo 31

  else if (type__Modulo == 32) {
    if (str_ws <= 0) str_ws = 1;
    float time__Modulo = str_ws;
    float module = 2 * abs( (t_now % str_ws) - time__Modulo / 2) / time__Modulo;
    module *= module;
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * module * _Master / 255), (pi_n_0_g[i] * module * _Master / 255), (pi_n_0_b[i] * module * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * module * _Master / 255), (pi_n_1_g[i] * module * _Master / 255), (pi_n_1_b[i] * module * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * module * _Master / 255), (pi_n_2_g[i] * module * _Master / 255), (pi_n_2_b[i] * module * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * module * _Master / 255), (pi_n_3_g[i] * module * _Master / 255), (pi_n_3_b[i] * module * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * module * _Master), ((pi_n_0_g[di] / 255) * module * _Master), ((pi_n_0_b[di] / 255) * module * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * module * _Master), ((pi_n_1_g[di] / 255) * module * _Master), ((pi_n_1_b[di] / 255) * module * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * module * _Master), ((pi_n_2_g[di] / 255) * module * _Master), ((pi_n_2_b[di] / 255) * module * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * module * _Master), ((pi_n_3_g[di] / 255) * module * _Master), ((pi_n_3_b[di] / 255) * module * _Master));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * module * _Master), ((pi_n_0_g[di] / 255) * module * _Master), ((pi_n_0_b[di] / 255) * module * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * module * _Master), ((pi_n_1_g[di] / 255) * module * _Master), ((pi_n_1_b[di] / 255) * module * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * module * _Master), ((pi_n_2_g[di] / 255) * module * _Master), ((pi_n_2_b[di] / 255) * module * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * module * _Master), ((pi_n_3_g[di] / 255) * module * _Master), ((pi_n_3_b[di] / 255) * module * _Master));
      } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        int di = map(i, (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB(((pi_n_0_r[di] / 255) * module * _Master), ((pi_n_0_g[di] / 255) * module * _Master), ((pi_n_0_b[di] / 255) * module * _Master));
        strands[1]->pixels[i] = pixelFromRGB(((pi_n_1_r[di] / 255) * module * _Master), ((pi_n_1_g[di] / 255) * module * _Master), ((pi_n_1_b[di] / 255) * module * _Master));
        strands[2]->pixels[i] = pixelFromRGB(((pi_n_2_r[di] / 255) * module * _Master), ((pi_n_2_g[di] / 255) * module * _Master), ((pi_n_2_b[di] / 255) * module * _Master));
        strands[3]->pixels[i] = pixelFromRGB(((pi_n_3_r[di] / 255) * module * _Master), ((pi_n_3_g[di] / 255) * module * _Master), ((pi_n_3_b[di] / 255) * module * _Master));
      }
    }
  }// _Modulo 32

  else if ( type__Modulo == 33 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }  else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      }
    }//for i
  }//_Modulo 33

  else if ( type__Modulo == 34) {
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
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[i] * str * _Master / 255), (pi_n_0_g[i] * str * _Master / 255), (pi_n_0_b[i] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[i] * str * _Master / 255), (pi_n_1_g[i] * str * _Master / 255), (pi_n_1_b[i] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[i] * str * _Master / 255), (pi_n_2_g[i] * str * _Master / 255), (pi_n_2_b[i] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[i] * str * _Master / 255), (pi_n_3_g[i] * str * _Master / 255), (pi_n_3_b[i] * str * _Master / 255));
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        int di = map(i, N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
      } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        int di = map(i, (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
      } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        int di = map(i, (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
        strands[0]->pixels[i] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        strands[1]->pixels[i] = pixelFromRGB((pi_n_1_r[di] * str * _Master / 255), (pi_n_1_g[di] * str * _Master / 255), (pi_n_1_b[di] * str * _Master / 255));
        strands[2]->pixels[i] = pixelFromRGB((pi_n_2_r[di] * str * _Master / 255), (pi_n_2_g[di] * str * _Master / 255), (pi_n_2_b[di] * str * _Master / 255));
        strands[3]->pixels[i] = pixelFromRGB((pi_n_3_r[di] * str * _Master / 255), (pi_n_3_g[di] * str * _Master / 255), (pi_n_3_b[di] * str * _Master / 255));
      }
    }

  }//_Modulo 34
  else if ( type__Modulo == 35 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }  else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * str * _Master / 255), (pi_n_0_g[di] * str * _Master / 255), (pi_n_0_b[di] * str * _Master / 255));
        }
      }
    }//for i
  }//_Modulo 35

  else if ( type__Modulo == 36 ) {
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
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[0]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      } else if (n_strip == 1) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[1]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      } else if (n_strip == 2) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[2]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      } else if (n_strip == 3) {
        if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S) {
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255), (pi_n_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 2 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), N_L_P_S + 1, N_L_P_S * 2, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 3 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 2)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 2) + 1, N_L_P_S * 3, 0, N_L_P_S);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        } else if (a - (NUM_LEDS_PER_STRIP * n_strip) <= N_L_P_S * 4 & a - (NUM_LEDS_PER_STRIP * n_strip >= N_L_P_S * 3)) {
          int di = map(a - (NUM_LEDS_PER_STRIP * n_strip), (N_L_P_S * 3) + 1, N_L_P_S * 4, N_L_P_S, 0);
          strands[3]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB((pi_n_0_r[di] * _Master / 255), (pi_n_0_g[di] * _Master / 255), (pi_n_0_b[di] * _Master / 255));
        }
      }
    }//for i
    old_S_seuil = S_seuil - 1;
  }//_Modulo 36
}//eff_
