
////////////////// COLOR THREAD

void color_task( void * pvParameters ) {
  
  while (true) {
    
    // color mode
    if (_Color_mode == 0) {

      for (int strip = 0 ; strip < NUM_STRIPS ; strip++) 
        for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
          pix_colorA[strip][i] = _Color;
          pix_colorB[strip][i] = _Color2;
        }
    }//_Color_mode 0
    

    else if (_Color_mode == 1) {
      
      float P_S = _Color2.r;
      float P_E = _Color2.g;
      float P_S_E;
      float P_S_N;
      float *coef;

      if (P_S < P_E) P_S_E = P_E - P_S;
      else if (P_S > P_E) P_S_E = P_S - P_E;
      else if (P_S == P_E) P_S_E = P_S;

      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
        
        P_S_N = P_S + ((P_S_E / NUM_LEDS_PER_STRIP ) * i);
        
        coef = coefPSN( P_S_N );

        int ci = (_Pix_pos + i) % NUM_LEDS_PER_STRIP;

        if (ci >= 0 && ci <= N_L_P_S)
          for (int s = 0 ; s < NUM_STRIPS ; s++) {
            pix_colorA[s][ci].r = _Color.r * coef[0];
            pix_colorA[s][ci].g = _Color.g * coef[1];
            pix_colorA[s][ci].b = _Color.b * coef[2];

            pix_colorB[s][ci] = pixelFromRGB(0,0,0);
          }
      }//for i

    }//_Color_mode 1


    else if (_Color_mode == 2) {

      float P_S = _Color2.r;
      float P_E = _Color2.g;
      float P_S_E;
      float P_S_N;
      float* coef;
      int ci;

      for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
        
        if (P_S < P_E)        P_S_E = P_E - P_S;
        else if (P_S > P_E)   P_S_E = P_S - P_E;
        else if (P_S == P_E)  P_S_E = P_S;

        P_S_N = P_S + ((P_S_E / NUM_LEDS_TOTAL ) * i);
        coef = coefPSN( P_S_N );
        ci = (_Pix_pos + i) % NUM_LEDS_PER_STRIP;

        int activeStrip = ci / N_L_P_S;

        for (int s = 0 ; s < NUM_STRIPS ; s++) {
          pix_colorA[s][ci].r = _Color.r * coef[0];
          pix_colorA[s][ci].g = _Color.g * coef[1];
          pix_colorA[s][ci].b = _Color.b * coef[2];

          pix_colorB[s][ci] = pixelFromRGB(0,0,0);
        }
      }//for i

    }//_Color_mode 2

  }
  
  yield();
  vTaskDelete(NULL);
}


///////////////////////////////////////   UTILS

float* coefPSN( float PSN ) {
  float coef[3];
  int rrr, ggg, bbb = 0;

  if (PSN >= 0 && PSN < 42.5) {
    rrr = map(PSN, 0, 42.5, 255, 255);
    ggg = map(PSN, 0, 42.5, 0, 255);
    bbb = map(PSN, 0, 42.5, 0, 0);
  } else if (PSN < 85) {
    rrr = map(PSN, 42.5, 85, 255, 0);
    ggg = map(PSN, 42.5, 85, 255, 255);
    bbb = map(PSN, 42.5, 85, 0, 0);
  } else if (PSN < 127.5) {
    rrr = map(PSN, 85, 127.5, 0, 0);
    ggg = map(PSN, 85, 127.5, 255, 255);
    bbb = map(PSN, 85, 127.5, 0, 255);
  } else if (PSN < 170) {
    rrr = map(PSN, 127.5, 170, 0, 0);
    ggg = map(PSN, 127.5, 170, 255, 0);
    bbb = map(PSN, 127.5, 170, 255, 255);
  } else if (PSN < 212.5) {
    rrr = map(PSN, 170, 212.5, 0, 255);
    ggg = map(PSN, 170, 212.5, 0, 0);
    bbb = map(PSN, 170, 212.5, 255, 255);
  } else if (PSN <= 255) {
    rrr = map(PSN, 212.5, 255, 255, 255);
    ggg = map(PSN, 212.5, 255, 0, 0);
    bbb = map(PSN, 212.5, 255, 255, 0);
  }

  coef[0] = (rrr*rrr)/(255*255);
  coef[1] = (ggg*ggg)/(255*255);
  coef[2] = (bbb*bbb)/(255*255);
  
  return coef;
}