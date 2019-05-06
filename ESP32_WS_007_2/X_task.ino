
void Map1code( void * pvParameters ) {
  while (1) {
    // color mode
    if (_Color_mode >= 0 && _Color_mode <= 10) {
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
        pix_colorA[0][i] = _Color;
        pix_colorA[1][i] = _Color;
        pix_colorA[2][i] = _Color;
        pix_colorA[3][i] = _Color;

        pix_colorB[0][i] = _Color2;
        pix_colorB[1][i] = _Color2;
        pix_colorB[2][i] = _Color2;
        pix_colorB[3][i] = _Color2;

      }
    } else if (_Color_mode >= 11 && _Color_mode <= 20) {
      if (_Pix_mod >= 11 && _Pix_mod <= 20 || _Pix_mod >= 31 && _Pix_mod <= 60 || _Pix_mod >= 91 && _Pix_mod <= 120) {
        _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
      } else if (_Pix_mod >= 21 && _Pix_mod <= 30 || _Pix_mod >= 61 && _Pix_mod <= 90 || _Pix_mod >= 121 && _Pix_mod <= 150) {
        _Pix_pos = (((_Pix_start + numberOfLed + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
      } else {
        _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
      }
      float P_S = srr;
      float P_E = sgg;
      float P_S_E;
      float P_S_N;

      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
        if (P_S < P_E) {
          P_S_E = P_E - P_S;
        } else if (P_S > P_E) {
          P_S_E = P_S - P_E;
        } else if (P_S == P_E) {
          P_S_E = P_S;
        }
        P_S_N = P_S + ((P_S_E / NUM_LEDS_PER_STRIP ) * i);

        if (P_S_N >= 0 && P_S_N < 42.5) {
          rrr = map(P_S_N, 0, 42.5, 255, 255);
          ggg = map(P_S_N, 0, 42.5, 0, 255);
          bbb = map(P_S_N, 0, 42.5, 0, 0);
        } else if (P_S_N >= 42.5 && P_S_N < 85) {
          rrr = map(P_S_N, 42.5, 85, 255, 0);
          ggg = map(P_S_N, 42.5, 85, 255, 255);
          bbb = map(P_S_N, 42.5, 85, 0, 0);
        } else if (P_S_N >= 85 && P_S_N < 127.5) {
          rrr = map(P_S_N, 85, 127.5, 0, 0);
          ggg = map(P_S_N, 85, 127.5, 255, 255);
          bbb = map(P_S_N, 85, 127.5, 0, 255);
        } else if (P_S_N >= 127.5 && P_S_N < 170) {
          rrr = map(P_S_N, 127.5, 170, 0, 0);
          ggg = map(P_S_N, 127.5, 170, 255, 0);
          bbb = map(P_S_N, 127.5, 170, 255, 255);
        } else if (P_S_N >= 170 && P_S_N < 212.5) {
          rrr = map(P_S_N, 170, 212.5, 0, 255);
          ggg = map(P_S_N, 170, 212.5, 0, 0);
          bbb = map(P_S_N, 170, 212.5, 255, 255);
        } else if (P_S_N >= 212.5 && P_S_N <= 255) {
          rrr = map(P_S_N, 212.5, 255, 255, 255);
          ggg = map(P_S_N, 212.5, 255, 0, 0);
          bbb = map(P_S_N, 212.5, 255, 255, 0);
        }

        int ci = _Pix_pos + i - 1;
        if (ci > NUM_LEDS_PER_STRIP) {
          ci = ci - NUM_LEDS_PER_STRIP - 1;
        }

        if (ci >= 0 && ci <= N_L_P_S) {
          pix_colorA[0][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[0][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[0][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[0][ci] = pixelFromRGB(0, 0, 0);

          pix_colorA[1][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[1][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[1][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[1][ci] = pixelFromRGB(0, 0, 0);

          pix_colorA[2][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[2][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[2][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[2][ci] = pixelFromRGB(0, 0, 0);

          pix_colorA[3][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[3][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[3][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[3][ci] = pixelFromRGB(0, 0, 0);
        }
      }//for (i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
    }//(_Color_mode >= 11 && _Color_mode <= 20)




    else if (_Color_mode >= 21 && _Color_mode <= 30) {
      if (_Pix_mod >= 11 && _Pix_mod <= 20 || _Pix_mod >= 31 && _Pix_mod <= 60 || _Pix_mod >= 91 && _Pix_mod <= 120) {
        _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
      } else if (_Pix_mod >= 21 && _Pix_mod <= 30 || _Pix_mod >= 61 && _Pix_mod <= 90 || _Pix_mod >= 121 && _Pix_mod <= 150) {
        _Pix_pos = (((_Pix_start + numberOfLed + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
      } else {
        _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
      }
      float P_S = srr;
      float P_E = sgg;
      float P_S_E;
      float P_S_N;

      for (int i = 0 ; i < numberOfLed ; i++) {
        if (P_S < P_E) {
          P_S_E = P_E - P_S;
        } else if (P_S > P_E) {
          P_S_E = P_S - P_E;
        } else if (P_S == P_E) {
          P_S_E = P_S;
        }
        P_S_N = P_S + ((P_S_E / numberOfLed ) * i);

        if (P_S_N >= 0 && P_S_N < 42.5) {
          rrr = map(P_S_N, 0, 42.5, 255, 255);
          ggg = map(P_S_N, 0, 42.5, 0, 255);
          bbb = map(P_S_N, 0, 42.5, 0, 0);
        } else if (P_S_N >= 42.5 && P_S_N < 85) {
          rrr = map(P_S_N, 42.5, 85, 255, 0);
          ggg = map(P_S_N, 42.5, 85, 255, 255);
          bbb = map(P_S_N, 42.5, 85, 0, 0);
        } else if (P_S_N >= 85 && P_S_N < 127.5) {
          rrr = map(P_S_N, 85, 127.5, 0, 0);
          ggg = map(P_S_N, 85, 127.5, 255, 255);
          bbb = map(P_S_N, 85, 127.5, 0, 255);
        } else if (P_S_N >= 127.5 && P_S_N < 170) {
          rrr = map(P_S_N, 127.5, 170, 0, 0);
          ggg = map(P_S_N, 127.5, 170, 255, 0);
          bbb = map(P_S_N, 127.5, 170, 255, 255);
        } else if (P_S_N >= 170 && P_S_N < 212.5) {
          rrr = map(P_S_N, 170, 212.5, 0, 255);
          ggg = map(P_S_N, 170, 212.5, 0, 0);
          bbb = map(P_S_N, 170, 212.5, 255, 255);
        } else if (P_S_N >= 212.5 && P_S_N <= 255) {
          rrr = map(P_S_N, 212.5, 255, 255, 255);
          ggg = map(P_S_N, 212.5, 255, 0, 0);
          bbb = map(P_S_N, 212.5, 255, 255, 0);
        }

        int ci = _Pix_pos + i - 1;
        if (ci > NUM_LEDS_PER_STRIP) {
          ci = ci - NUM_LEDS_PER_STRIP - 1;
        } else  if (ci > NUM_LEDS_PER_STRIP * 2) {
          ci = ci - (NUM_LEDS_PER_STRIP * 2) - 1;
        } else  if (ci > NUM_LEDS_PER_STRIP * 3) {
          ci = ci - (NUM_LEDS_PER_STRIP * 3) - 1;
        } else  if (ci > NUM_LEDS_PER_STRIP * 4) {
          ci = ci - (NUM_LEDS_PER_STRIP * 4) - 1;
        }
        if (ci >= 0 && ci <= N_L_P_S) {
          pix_colorA[0][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[0][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[0][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[0][ci] = pixelFromRGB(0, 0, 0);
        } else if (ci > N_L_P_S && ci <= N_L_P_S * 2) {
          pix_colorA[1][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[1][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[1][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[1][ci] = pixelFromRGB(0, 0, 0);
        } else if (ci > N_L_P_S * 2 && ci <= N_L_P_S * 3) {
          pix_colorA[2][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[2][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[2][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[2][ci] = pixelFromRGB(0, 0, 0);
        } else if (ci > N_L_P_S * 3 && ci <= N_L_P_S * 4) {
          pix_colorA[3][ci].r = (( rrr * rrr / 255 )  * rr) / 255;
          pix_colorA[3][ci].g = (( ggg * ggg / 255 )  * gg) / 255;
          pix_colorA[3][ci].b = (( bbb * bbb / 255 )  * bb) / 255;
          pix_colorB[3][ci] = pixelFromRGB(0, 0, 0);
        }
      }//for (int i = 0 ; i < numberOfLed ; i++) {
    }//else if (_Color_mode >= 21 && _Color_mode <= 30)

  }
  yield();
  vTaskDelete(NULL);
}//Map1code( void * pvParameters )

void effTask( void * pvParameters ) {
  while (1) {
    effet();
    yield(); // rend la main
  }
}
