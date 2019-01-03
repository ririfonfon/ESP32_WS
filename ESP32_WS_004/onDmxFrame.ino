//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// onDmxFrame //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data) {
  boolean tail = false;

#ifdef DEBUG_dmx
  Serial.print("master = ");
  Serial.println(master);
  Serial.print("r = ");
  Serial.println(r);
  Serial.print("g = ");
  Serial.println(g);
  Serial.print("b = ");
  Serial.println(b);
  Serial.print("mod = ");
  Serial.println(mod);
  Serial.print("pix_mod = ");
  Serial.println(pix_mod);
  Serial.print("pix_start = ");
  Serial.println(pix_start);
  Serial.print("pix_center = ");
  Serial.println(pix_center);
  Serial.print("pix_end = ");
  Serial.println(pix_end);
  Serial.print("pix_pos = ");
  Serial.println(pix_pos);
  Serial.print("modulo = ");
  Serial.println(modulo);
  Serial.print("str_ws = ");
  Serial.println(str_ws);
  Serial.print("M_g = ");
  Serial.println(M_g);
#endif

  master = data[adr - 1];
  rr = (data[adr] * data[adr]) / 255;
  gg = (data[adr + 1] * data[adr + 1]) / 255;
  bb = (data[adr + 2] * data[adr + 2]) / 255;
  mod = data[adr + 3];
  pix_mod = data[adr + 4];
  pix_start = data[adr + 5] - 1;

  pix_end = pix_start + pix_start;
  if (pix_mod >= 11 && pix_mod <= 20 || pix_mod >= 31 && pix_mod <= 60 || pix_mod >= 91 && pix_mod <= 120) {
    pix_pos = (((pix_start + N_L_P_S + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
  } else if (pix_mod >= 21 && pix_mod <= 30 || pix_mod >= 61 && pix_mod <= 90 || pix_mod >= 121 && pix_mod <= 150) {
    pix_pos = (((pix_start + numberOfLed + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
  }
  modulo = data[adr + 7];
  str_ws = (data[adr + 8] * data[adr + 8]) / 33;
  pix_center = ((pix_start) / 2) + pix_pos;
  M_g = ((NUM_LEDS_PER_STRIP / 2) + 1) / NUM_STRIPS;
  smaster = data[adr + 9];
  srr = (data[adr + 10] * data[adr + 10]) / 255;
  sgg = (data[adr + 11] * data[adr + 11]) / 255;
  sbb = (data[adr + 12] * data[adr + 12]) / 255;
  color_mode = data[adr + 13];
  mirror = data[adr + 14];

  // mirror mode
  if (mirror >= 0 && mirror <= 10) {
    N_L_P_S = (NUM_LEDS_PER_STRIP);
  } else if (mirror >= 11 && mirror <= 20) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 2);
  } else if (mirror >= 21 && mirror <= 30) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 3);
  } else if (mirror >= 31 && mirror <= 40) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 4);
  }

  // color mode
  if (color_mode >= 0 && color_mode <= 10) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      pi_0_r[i] = r;
      pi_0_g[i] = g;
      pi_0_b[i] = b;
      pi_1_r[i] = r;
      pi_1_g[i] = g;
      pi_1_b[i] = b;
      pi_2_r[i] = r;
      pi_2_g[i] = g;
      pi_2_b[i] = b;
      pi_3_r[i] = r;
      pi_3_g[i] = g;
      pi_3_b[i] = b;
      pi_0_sr[i] = sr;
      pi_0_sg[i] = sg;
      pi_0_sb[i] = sb;
      pi_1_sr[i] = sr;
      pi_1_sg[i] = sg;
      pi_1_sb[i] = sb;
      pi_2_sr[i] = sr;
      pi_2_sg[i] = sg;
      pi_2_sb[i] = sb;
      pi_3_sr[i] = sr;
      pi_3_sg[i] = sg;
      pi_3_sb[i] = sb;
    }
  } else if (color_mode >= 11 && color_mode <= 20) {
    if (pix_mod >= 11 && pix_mod <= 20 || pix_mod >= 31 && pix_mod <= 60 || pix_mod >= 91 && pix_mod <= 120) {
      pix_pos = (((pix_start + N_L_P_S + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
    } else if (pix_mod >= 21 && pix_mod <= 30 || pix_mod >= 61 && pix_mod <= 90 || pix_mod >= 121 && pix_mod <= 150) {
      pix_pos = (((pix_start + numberOfLed + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
    } else {
      pix_pos = (((pix_start + N_L_P_S + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
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

      int ci = pix_pos + i - 1;
      if (ci > NUM_LEDS_PER_STRIP) {
        ci = ci - NUM_LEDS_PER_STRIP - 1;
      }

      if (ci >= 0 && ci <= N_L_P_S) {
        pi_0_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_0_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_0_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_0_sr[ci] = 0;
        pi_0_sg[ci] = 0;
        pi_0_sb[ci] = 0;
        pi_1_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_1_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_1_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_1_sr[ci] = 0;
        pi_1_sg[ci] = 0;
        pi_1_sb[ci] = 0;
        pi_2_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_2_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_2_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_2_sr[ci] = 0;
        pi_2_sg[ci] = 0;
        pi_2_sb[ci] = 0;
        pi_3_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_3_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_3_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_3_sr[ci] = 0;
        pi_3_sg[ci] = 0;
        pi_3_sb[ci] = 0;
      }
    }//for (i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
  }//(color_mode >= 11 && color_mode <= 20)




  else if (color_mode >= 21 && color_mode <= 30) {
    if (pix_mod >= 11 && pix_mod <= 20 || pix_mod >= 31 && pix_mod <= 60 || pix_mod >= 91 && pix_mod <= 120) {
      pix_pos = (((pix_start + N_L_P_S + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
    } else if (pix_mod >= 21 && pix_mod <= 30 || pix_mod >= 61 && pix_mod <= 90 || pix_mod >= 121 && pix_mod <= 150) {
      pix_pos = (((pix_start + numberOfLed + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
    } else {
      pix_pos = (((pix_start + N_L_P_S + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
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

      int ci = pix_pos + i - 1;
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
        pi_0_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_0_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_0_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_0_sr[ci] = 0;
        pi_0_sg[ci] = 0;
        pi_0_sb[ci] = 0;
      } else if (ci > N_L_P_S && ci <= N_L_P_S * 2) {
        pi_1_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_1_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_1_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_1_sr[ci] = 0;
        pi_1_sg[ci] = 0;
        pi_1_sb[ci] = 0;
      } else if (ci > N_L_P_S * 2 && ci <= N_L_P_S * 3) {
        pi_2_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_2_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_2_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_2_sr[ci] = 0;
        pi_2_sg[ci] = 0;
        pi_2_sb[ci] = 0;
      } else if (ci > N_L_P_S * 3 && ci <= N_L_P_S * 4) {
        pi_3_r[ci] = (( rrr * rrr / 255 )  * rr) / 255 * master / 255;
        pi_3_g[ci] = (( ggg * ggg / 255 )  * gg) / 255 * master / 255;
        pi_3_b[ci] = (( bbb * bbb / 255 )  * bb) / 255 * master / 255;
        pi_3_sr[ci] = 0;
        pi_3_sg[ci] = 0;
        pi_3_sb[ci] = 0;
      }
    }//for (int i = 0 ; i < numberOfLed ; i++) {
  }//else if (color_mode >= 21 && color_mode <= 30)


  if ((mod >= 0) && (mod <= 10)) {
    type_effet = 0;
  }//mod fix
  else if ((mod >= 11) && (mod <= 20)) {
    type_effet  = 1;
  }//rudan 1
  else if ((mod >= 21) && (mod <= 30)) {
    type_effet  = 2;
  }//rudan 2
  else if ((mod >= 31) && (mod <= 40)) {
    type_effet  = 3;
  }//rudan 3
  else if ((mod >= 41) && (mod <= 50)) {
    type_effet  = 4;
  }//rudan 4
  else if ((mod >= 51) && (mod <= 60)) {
    type_effet  = 5;
  }//rudan 12
  else if ((mod >= 61) && (mod <= 70)) {
    type_effet  = 6;
  }//rudan 13
  else if ((mod >= 71) && (mod <= 80)) {
    type_effet  = 7;
  }//rudan 14
  else if ((mod >= 81) && (mod <= 90)) {
    type_effet  = 8;
  }//rudan 23
  else if ((mod >= 91) && (mod <= 100)) {
    type_effet  = 9;
  }//rudan 24
  else if ((mod >= 101) && (mod <= 110)) {
    type_effet  = 10;
  }//rudan 34
  else if ((mod >= 111) && (mod <= 120)) {
    type_effet  = 11;
    M_g_ref = 0;
    M_g1 = M_g;
    M_g1_ref = M_g;
    M_g2 = M_g * 2;
    M_g2_ref = M_g * 2;
    M_g3 = M_g * 3;
    M_g3_ref = M_g * 3;
    M_g4 = M_g * 4;
  }//rudan 1/4
  else if ((mod >= 121) && (mod <= 130)) {
    type_effet  = 11;
    M_g_ref = M_g * 3;
    M_g1 = M_g * 4;
    M_g1_ref = 0;
    M_g2 = M_g;
    M_g2_ref = M_g;
    M_g3 = M_g * 2;
    M_g3_ref = M_g * 2;
    M_g4 = M_g * 3;
  }//rudan 2/4
  else if ((mod >= 131) && (mod <= 140)) {
    type_effet  = 11;
    M_g_ref = M_g * 2;
    M_g1 = M_g * 3;
    M_g1_ref = M_g * 3;
    M_g2 = M_g * 4;
    M_g2_ref = 0;
    M_g3 = M_g;
    M_g3_ref = M_g;
    M_g4 = M_g * 2;
  }//rudan 3/4
  else if ((mod >= 141) && (mod <= 150)) {
    type_effet  = 11;
    M_g_ref = M_g;
    M_g1 = M_g * 2;
    M_g1_ref = M_g * 2;
    M_g2 = M_g * 3;
    M_g2_ref = M_g * 3;
    M_g3 = M_g * 4;
    M_g3_ref = 0;
    M_g4 = M_g;
  }//rudan 4/4

  // modulo mode
  if ((modulo >= 0) && modulo <= 10) {
    type_modulo = 0;
  } else if ((modulo >= 11) && modulo <= 20) {
    type_modulo = 1;
  } else if ((modulo >= 21) && modulo <= 30) {
    type_modulo = 2;
  } else if ((modulo >= 31) && modulo <= 110) {
    Black();
    type_modulo = 3;
    S_seuil = (modulo - 30) * 4;
    type_effet = 255;
  } else if ((modulo >= 111) && modulo <= 120) {
    type_modulo = 4;
  } else if ((modulo >= 121) && modulo <= 200) {
    Black();
    type_modulo = 5;
    S_seuil = (modulo - 120) * 4;
    type_effet = 255;
  } else if ((modulo >= 201) && modulo <= 255) {
    type_modulo = 6;
    S_seuil = (modulo - 200) * 4;
    type_effet = 255;
  }

  previousDataLength = length;

  if (sendFrame) {
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}//onframedmx
