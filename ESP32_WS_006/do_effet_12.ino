void do_effet_12() {
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
      int ci = pix_pos + i;
      if (ci > NUM_LEDS_PER_STRIP) {
        ci = ci - NUM_LEDS_PER_STRIP;
      }
      pi_n_0_r[ci] = (( rrr * rrr / 255 )  * rr) / 255;
      pi_n_0_g[ci] = (( ggg * ggg / 255 )  * gg) / 255;
      pi_n_0_b[ci] = (( bbb * bbb / 255 )  * bb) / 255;
      pi_n_1_r[ci] = (( rrr * rrr / 255 )  * rr) / 255;
      pi_n_1_g[ci] = (( ggg * ggg / 255 )  * gg) / 255;
      pi_n_1_b[ci] = (( bbb * bbb / 255 )  * bb) / 255;
      pi_n_2_r[ci] = (( rrr * rrr / 255 )  * rr) / 255;
      pi_n_2_g[ci] = (( ggg * ggg / 255 )  * gg) / 255;
      pi_n_2_b[ci] = (( bbb * bbb / 255 )  * bb) / 255;
      pi_n_3_r[ci] = (( rrr * rrr / 255 )  * rr) / 255;
      pi_n_3_g[ci] = (( ggg * ggg / 255 )  * gg) / 255;
      pi_n_3_b[ci] = (( bbb * bbb / 255 )  * bb) / 255;
    }//for i
  }//pix_mod 0
}//do_effet_12()
