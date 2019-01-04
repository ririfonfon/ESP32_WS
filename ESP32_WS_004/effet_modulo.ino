
void eff_modulo() {
  unsigned long t_now = millis();
  if ( type_modulo == 0 ) {
    r = ((rr / 255) * master);
    g = ((gg / 255) * master);
    b = ((bb / 255) * master);
    sr = ((srr / 255) * smaster);
    sg = ((sgg / 255) * smaster);
    sb = ((sbb / 255) * smaster);
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
    r = rr * str * master / 255;
    g = gg * str * master / 255;
    b = bb * str * master / 255;
    sr = srr * str * smaster / 255;
    sg = sgg * str * smaster / 255;
    sb = sbb * str * smaster / 255;
  }//modulo 1

  else if (type_modulo == 2) {
    if (str_ws <= 0) str_ws = 1;
    float time_modulo = str_ws;
    float module = 2 * abs( (t_now % str_ws) - time_modulo / 2) / time_modulo;
    module *= module;
    r = rr * module * master / 255;
    g = gg * module * master / 255;
    b = bb * module * master / 255;
    sr = srr * module * smaster / 255;
    sg = sgg * module * smaster / 255;
    sb = sbb * module * smaster / 255;

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
    r = rr * str * master / 255;
    g = gg * str * master / 255;
    b = bb * str * master / 255;

    int n_led_to_show = (min(numberOfLed - 8, S_seuil));
    int n_strip = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
      } while (strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].r != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].g != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].b != 0 );
      if (n_strip == 0) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
      } else if (n_strip == 1) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
      } else if (n_strip == 2) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
      } else if (n_strip == 3) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
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
    r = rr * str * master / 255;
    g = gg * str * master / 255;
    b = bb * str * master / 255;
    sr = srr * str * smaster / 255;
    sg = sgg * str * smaster / 255;
    sb = sbb * str * smaster / 255;
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
    r = rr * str * master / 255;
    g = gg * str * master / 255;
    b = bb * str * master / 255;

    int n_led_to_show = min(numberOfLed - 8, S_seuil);
    int n_strip = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
      } while (strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].r != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].g != 0 || strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)].b != 0 );
      if (n_strip == 0) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
      } else if (n_strip == 1) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
      } else if (n_strip == 2) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
      } else if (n_strip == 3) {
        strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
      }
    }//for i
  }//modulo 5

  else if ( type_modulo == 6 ) {
    if (old_S_seuil != S_seuil) {
      for (int i = 0; i < numberOfLed; i++) {
        randArray[i] = false;
      }
      old_S_seuil = S_seuil;

      int n_led_to_show = (min(numberOfLed - 8, S_seuil));
      int n_strip = 0;

      for (int i = 0; i < n_led_to_show ; i ++) {
        do {
          a = random( 0 , numberOfLed );
          n_strip = a / NUM_LEDS_PER_STRIP;
        } while (randArray[a]);
        randArray[a] = true;
      }//for i
    }// if old_S_seuil

    r = rr * master / 255;
    g = gg * master / 255;
    b = bb * master / 255;
    Black();
    for (int i = 0; i < numberOfLed; i++) {
      if (randArray[i]) {
        int n_strip = i / NUM_LEDS_PER_STRIP;
        if (n_strip == 0) {
          strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_0_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_0_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_0_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
        } else if (n_strip == 1) {
          strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_1_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_1_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_1_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
        } else if (n_strip == 2) {
          strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_2_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_2_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_2_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
        } else if (n_strip == 3) {
          strands[n_strip]->pixels[a - (NUM_LEDS_PER_STRIP * n_strip)] = pixelFromRGB(pi_3_r[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_3_g[a - (NUM_LEDS_PER_STRIP * n_strip)], pi_3_b[a - (NUM_LEDS_PER_STRIP * n_strip)]);
        }
      }
    }//for i
    return;
  }//modulo 6

}//eff_modulo
