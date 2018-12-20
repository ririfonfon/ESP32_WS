void do_effet_12() {
  //  if (pix_mod >= 0 && pix_mod <= 10) {
  //    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
  //      if (i >= 0 && i < CYCLE || i >= 0 + N_L_P_S && i < CYCLE + N_L_P_S) {
  //        r = ((1 * master) * rr) / 255;
  //        ggg = map(i, 0, CYCLE, 0, 255);
  //        g = (((ggg * ggg / 255 ) / 255 * master) * gg) / 255;
  //        b = 0;
  //      } else if (i >= CYCLE && i < CYCLE * 2 || i >= CYCLE + N_L_P_S && i < (CYCLE * 2) + N_L_P_S) {
  //        rrr = map(i, CYCLE, CYCLE * 2, 255, 0);
  //        r = (((rrr * rrr / 255 ) / 255 * master) * rr) / 255;
  //        g = ((1 * master) * gg) / 255;
  //        b = 0;
  //      } else if (i >= CYCLE * 2 && i < CYCLE * 3 || i >= (CYCLE * 2) + N_L_P_S && i < (CYCLE * 3) + N_L_P_S) {
  //        r = 0;
  //        g = ((1 * master) * gg) / 255;
  //        bbb = map(i, CYCLE * 2, CYCLE * 3, 0, 255);
  //        b = (((bbb * bbb / 255) / 255 * master) * bb) / 255;
  //      } else if (i >= CYCLE * 3 && i < CYCLE * 4 || i >= (CYCLE * 3) + N_L_P_S && i < (CYCLE * 4) + N_L_P_S) {
  //        r = 0;
  //        ggg = map(i, CYCLE * 3, CYCLE * 4, 255, 0);
  //        g = ((( ggg * ggg / 255 ) / 255 * master) * gg) / 255;
  //        b = ((1 * master) * bb) / 255;
  //      } else if (i >= CYCLE * 4 && i < CYCLE * 5 || i >= (CYCLE * 4) + N_L_P_S && i < (CYCLE * 5) + N_L_P_S) {
  //        rrr = map(i, CYCLE * 4, CYCLE * 5, 0, 255);
  //        r = ((( rrr * rrr / 255 ) / 255 * master) * rr) / 255;
  //        g = 0;
  //        b = ((1 * master) * bb) / 255;
  //      } else if (i >= CYCLE * 5 && i <= CYCLE * 6 || i >= (CYCLE * 5) + N_L_P_S && i <= (CYCLE * 6) + N_L_P_S) {
  //        r = ((1 * master) * rr) / 255;
  //        g = 0;
  //        bbb = map(i, CYCLE * 5, CYCLE * 6, 255, 0);
  //        b = ((( bbb * bbb / 255 ) / 255 * master) * bb) / 255;
  //      }
  //      int ci = pix_pos + i;
  //      if (ci > NUM_LEDS_PER_STRIP) {
  //        ci = ci - NUM_LEDS_PER_STRIP;
  //      }
  //      strands[0]->pixels[ci] = pixelFromRGB(r, g, b);
  //      strands[1]->pixels[ci] = pixelFromRGB(r, g, b);
  //    }//for i
  //  }//pix_mod 0

  if (pix_mod >= 0 && pix_mod <= 10) {
    float P_S = srr;
    float P_E = sgg;
    float P_S_E;
    float P_S_N;

    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {

      if (P_S < P_E) {
        P_S_E = P_E - P_S;
        P_S_N = P_S + (P_S_E * i);
      } else if (P_S > P_E) {
        P_S_E = P_S - P_E;
        P_S_N = P_S + (P_S_E * i);
      } else if (P_S == P_E) {
        P_S_E = P_S;
        P_S_N = P_S + (P_S_E * i);
      }
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
      r = ((( rrr * rrr / 255 ) / 255 * master) * rr) / 255;
      g = ((( ggg * ggg / 255 ) / 255 * master) * gg) / 255;
      b = ((( bbb * bbb / 255 ) / 255 * master) * bb) / 255;
      int ci = pix_pos + i;
      if (ci > NUM_LEDS_PER_STRIP) {
        ci = ci - NUM_LEDS_PER_STRIP;
      }
      strands[0]->pixels[ci] = pixelFromRGB(r, g, b);
      strands[1]->pixels[ci] = pixelFromRGB(r, g, b);
    }//for i
  }//pix_mod 0
}//do_effet_12()
