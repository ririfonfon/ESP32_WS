void do_effet_6() {
  if (pix_mod >= 0 && pix_mod <= 10) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i <= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i], pi_0_g[i], pi_0_b[i]);
        strands[1]->pixels[i] = pixelFromRGB(pi_1_r[i], pi_1_g[i], pi_1_b[i]);
      } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
      } else  {
        strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
      }
    }//for i
  }//pix_mod 0

  if (pix_mod >= 11 && pix_mod <= 20) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i], pi_0_g[i], pi_0_b[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_r[i], pi_1_g[i], pi_1_b[i]);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        } else  {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        }
      }
    }//for i
  }//pix_mod 10

  if (pix_mod >= 21 && pix_mod <= 30) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i <= N_L_P_S) {
        if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i], pi_0_g[i], pi_0_b[i]);
        } else {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        }
      }
      if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        }
      }
      if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(r, g, b);
        } else {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(sr, sg, sb);
        }
      }
      if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        } else {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      }
    }//for i
  }//pix_mod 20

  if (pix_mod >= 31 && pix_mod <= 40) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((i - pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i] * pix_coef, pi_0_g[i] * pix_coef, pi_0_b[i] * pix_coef);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_r[i] * pix_coef, pi_1_g[i] * pix_coef, pi_1_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        } else  {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        }
      }
    }//for i
  }//pix_mod 30

  if (pix_mod >= 41 && pix_mod <= 50) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((pix_pos - ref_pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i] * pix_coef, pi_0_g[i] * pix_coef, pi_0_b[i] * pix_coef);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_r[i] * pix_coef, pi_1_g[i] * pix_coef, pi_1_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        } else  {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        }
      }
    }//for i
  }//pix_mod 40

  if (pix_mod >= 51 && pix_mod <= 60) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - pix_pos + 1)) * 200) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((pix_pos - ref_pix_pos)) * 100) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_pix_pos = ref_pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i] * pix_coef, pi_0_g[i] * pix_coef, pi_0_b[i] * pix_coef);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_r[i] * pix_coef, pi_1_g[i] * pix_coef, pi_1_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        } else  {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        }
      }
    }//for i
  }//pix_mod 50

  if (pix_mod >= 61 && pix_mod <= 70) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((i - pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i] * pix_coef, pi_0_g[i] * pix_coef, pi_0_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(pi_1_r[i] * pix_coef, pi_1_g[i] * pix_coef, pi_1_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      } else {
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(sr, sg, sb);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      }
    }//for i
  }//pix_mod 60

  if (pix_mod >= 71 && pix_mod <= 80) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((pix_pos - ref_pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref_pix_pos--;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i] * pix_coef, pi_0_g[i] * pix_coef, pi_0_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(pi_1_r[i] * pix_coef, pi_1_g[i] * pix_coef, pi_1_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      } else {
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(sr, sg, sb);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      }
    }//for i
  }//pix_mod 70

  if (pix_mod >= 81 && pix_mod <= 90) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - pix_pos + 1)) * 200) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((pix_pos - ref_pix_pos)) * 100) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_pix_pos = ref_pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_r[i] * pix_coef, pi_0_g[i] * pix_coef, pi_0_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(pi_1_r[i] * pix_coef, pi_1_g[i] * pix_coef, pi_1_b[i] * pix_coef);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      } else {
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(sr, sg, sb);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      }
    }//for i
  }//pix_mod 80

  if (pix_mod >= 91 && pix_mod <= 100) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((i - pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB((pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond), (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond), (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond));
          strands[1]->pixels[i] = pixelFromRGB((pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond), (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond), (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        } else  {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        }
      }
    }//for i
  }//pix_mod 90

  if (pix_mod >= 101 && pix_mod <= 110) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((pix_pos - ref_pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB((pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond), (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond), (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond));
          strands[1]->pixels[i] = pixelFromRGB((pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond), (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond), (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        } else  {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        }
      }
    }//for i
  }//pix_mod 100

  if (pix_mod >= 111 && pix_mod <= 120) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - pix_pos + 1)) * 200) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((pix_pos - ref_pix_pos)) * 100) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_pix_pos = ref_pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;


        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB((pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond), (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond), (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond));
          strands[1]->pixels[i] = pixelFromRGB((pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond), (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond), (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        } else  {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
          strands[1]->pixels[i] = pixelFromRGB(pi_1_sr[i], pi_1_sg[i], pi_1_sb[i]);;
        }
      }
    }//for i
  }//pix_mod 110

  if (pix_mod >= 121 && pix_mod <= 130) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((i - pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB((pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond), (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond), (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB((pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond), (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond), (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      } else {
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(sr, sg, sb);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      }
    }//for i
  }//pix_mod 120

  if (pix_mod >= 131 && pix_mod <= 140) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        pix_coefi = (((pix_pos - ref_pix_pos) * 100) / pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref_pix_pos--;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB((pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond), (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond), (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB((pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond), (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond), (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      } else {
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(sr, sg, sb);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      }
    }//for i
  }//pix_mod 130

  if (pix_mod >= 141 && pix_mod <= 150) {
    ref_pix_pos = (pix_start + pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (pix_pos) && i <= pix_start + (pix_pos) || i >= (pix_pos + N_L_P_S) && i <= pix_start + (pix_pos + N_L_P_S)) {
        if (pix_start <= 1) {
          pix_start_v = 1;
        } else {
          pix_start_v = pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - pix_pos + 1)) * 200) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((pix_pos - ref_pix_pos)) * 100) / pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_pix_pos = ref_pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB((pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond), (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond), (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB((pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond), (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond), (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond));
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      } else {
        if (i <= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          strands[0]->pixels[i] = pixelFromRGB(pi_0_sr[i], pi_0_sg[i], pi_0_sb[i]);
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          strands[1]->pixels[i - N_L_P_S * 2] = pixelFromRGB(sr, sg, sb);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          strands[1]->pixels[i - N_L_P_S * 3] = pixelFromRGB(sr, sg, sb);
        }
      }
    }//for i
  }//pix_mod 140
}//do_effet_6 ruban 13
