
pixelColor_t piMUL(float* pix, int factor)
{
  pixelColor_t p;
  p.r = pix[R] * factor * master / 255;
  p.g = pix[G] * factor * master / 255;
  p.b = pix[B] * factor * master / 255;
  p.w = pix[W] * factor * master / 255;
  return p;
}

int getMirroredPixNum(int i) {
  if ((i / N_L_P_S) % 2 == 0) return (i % N_L_P_S);               // paire = dans le bon sens
  if ((i / N_L_P_S) % 2 == 1) return N_L_P_S - (i % N_L_P_S) - 1; // impaire = inversé 
}


void eff_modulo() 
{  
  unsigned long t_now = millis();
  
  if ( type_modulo % 10 == 0 ) {
    
    for (int strip = 0 ; strip < NUM_STRIPS ; strip++) 
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) 
        strands[strip]->pixels[i] = piMUL( pi_n[strip][getMirroredPixNum(i)] , 1 );
        
  }//modulo 0

  
  else if ( type_modulo % 10 == 1) {
    
    if (str == 0 && t_now - str_ws_last > str_ws) {
      str_ws_last = t_now;
      str = 1;
    } 
    else if (str == 1 && t_now - str_ws_last > STROB_ON_MS) {
      str_ws_last = t_now;
      str = 0;
    } else {
      return;
    }

    for (int strip = 0 ; strip < NUM_STRIPS ; strip++) 
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) 
        strands[strip]->pixels[i] = piMUL( pi_n[strip][getMirroredPixNum(i)] , str );

  }//modulo 1

  else if (type_modulo % 10 == 2) {
    
    if (str_ws <= 0) str_ws = 1;
    float time_modulo = str_ws;
    float module = 2 * abs( (t_now % str_ws) - time_modulo / 2) / time_modulo;
    module *= module;

    for (int strip = 0 ; strip < NUM_STRIPS ; strip++) 
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) 
        strands[strip]->pixels[i] = piMUL( pi_n[strip][getMirroredPixNum(i)] , module );

  }// modulo 2

  else if ( type_modulo % 10 == 3 ) {
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
    int p = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
        p = a - (NUM_LEDS_PER_STRIP * n_strip);
      } while (strands[n_strip]->pixels[p].r != 0 || strands[n_strip]->pixels[p].g != 0 || strands[n_strip]->pixels[p].b != 0);

      strands[n_strip]->pixels[p] = piMUL( pi_n[n_strip][getMirroredPixNum(p)] , str );
      
    }//for i
    
  }//modulo 3

  else if ( type_modulo % 10 == 4) {
    
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

    for (int strip = 0 ; strip < NUM_STRIPS ; strip++) 
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) 
        strands[strip]->pixels[i] = piMUL( pi_n[strip][getMirroredPixNum(i)] , str );

  }//modulo 4
  
  else if ( type_modulo % 10 == 5 ) {
    
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
    int p = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
        p = a - (NUM_LEDS_PER_STRIP * n_strip);
      } while (strands[n_strip]->pixels[p].r != 0 || strands[n_strip]->pixels[p].g != 0 || strands[n_strip]->pixels[p].b != 0);

      strands[n_strip]->pixels[p] = piMUL( pi_n[n_strip][getMirroredPixNum(p)] , str );
    }

  }//modulo 5

  else if ( type_modulo % 10 == 6 ) {

    if (old_S_seuil != S_seuil) {
      Black();
      old_S_seuil = S_seuil;
    }
    int S_seuil_B;
    
    int n_led_to_show = min(numberOfLed - 8, S_seuil);
    int n_strip = 0;
    int p = 0;
    for (int i = 0; i < n_led_to_show ; i ++) {
      do {
        a = random( 0 , numberOfLed );
        n_strip = a / NUM_LEDS_PER_STRIP;
        p = a - (NUM_LEDS_PER_STRIP * n_strip);
      } while (strands[n_strip]->pixels[p].r != 0 || strands[n_strip]->pixels[p].g != 0 || strands[n_strip]->pixels[p].b != 0);

      strands[n_strip]->pixels[p] = piMUL( pi_n[n_strip][getMirroredPixNum(p)] , str );
    }//for i
    old_S_seuil = S_seuil - 1;

  }//modulo 6

}//eff_modulo
