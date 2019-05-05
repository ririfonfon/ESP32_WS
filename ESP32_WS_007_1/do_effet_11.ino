void do_effet_11() {
  if (_Pix_mod == 0) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= M_g_ref && i <= M_g1) {
        pi_n_0_r[i] = pi_0_r[i];
        pi_n_0_g[i] = pi_0_g[i];
        pi_n_0_b[i] = pi_0_b[i];
      } else {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
      }
      if (i > M_g1_ref && i <= M_g2) {
        pi_n_1_r[i] = pi_1_r[i];
        pi_n_1_g[i] = pi_1_g[i];
        pi_n_1_b[i] = pi_1_b[i];
      } else {
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
      }
      if (i > M_g2_ref && i <= M_g3) {
        pi_n_2_r[i] = pi_2_r[i];
        pi_n_2_g[i] = pi_2_g[i];
        pi_n_2_b[i] = pi_2_b[i];
      } else {
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
      }
      if (i > M_g3_ref && i <= M_g4) {
        pi_n_3_r[i] = pi_3_r[i];
        pi_n_3_g[i] = pi_3_g[i];
        pi_n_3_b[i] = pi_3_b[i];
      } else {
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 0

  if (_Pix_mod == 1) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (i >= M_g_ref && i <= M_g1) {
          pi_n_0_r[i] = pi_0_r[i];
          pi_n_0_g[i] = pi_0_g[i];
          pi_n_0_b[i] = pi_0_b[i];
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
        if (i > M_g1_ref && i <= M_g2) {
          pi_n_1_r[i] = pi_1_r[i];
          pi_n_1_g[i] = pi_1_g[i];
          pi_n_1_b[i] = pi_1_b[i];
        } else {
          pi_n_1_r[i] = pi_1_sr[i];
          pi_n_1_g[i] = pi_1_sg[i];
          pi_n_1_b[i] = pi_1_sb[i];
        }
        if (i > M_g2_ref && i <= M_g3) {
          pi_n_2_r[i] = pi_2_r[i];
          pi_n_2_g[i] = pi_2_g[i];
          pi_n_2_b[i] = pi_2_b[i];
        } else {
          pi_n_2_r[i] = pi_2_sr[i];
          pi_n_2_g[i] = pi_2_sg[i];
          pi_n_2_b[i] = pi_2_sb[i];
        }
        if (i > M_g3_ref && i <= M_g4) {
          pi_n_3_r[i] = pi_3_r[i];
          pi_n_3_g[i] = pi_3_g[i];
          pi_n_3_b[i] = pi_3_b[i];
        } else {
          pi_n_3_r[i] = pi_3_sr[i];
          pi_n_3_g[i] = pi_3_sg[i];
          pi_n_3_b[i] = pi_3_sb[i];
        }
      } else  {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 10

  if (_Pix_mod == 2) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i <= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i >= M_g_ref && i <= M_g1) {
            pi_n_0_r[i] = pi_0_r[i];
            pi_n_0_g[i] = pi_0_g[i];
            pi_n_0_b[i] = pi_0_b[i];
          } else {
            pi_n_0_r[i] = pi_0_sr[i];
            pi_n_0_g[i] = pi_0_sg[i];
            pi_n_0_b[i] = pi_0_sb[i];
          }
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
      }
      if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g1_ref + N_L_P_S && i <= M_g2 + N_L_P_S) {
            pi_n_1_r[i - N_L_P_S] = pi_1_r[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_g[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_b[i - N_L_P_S];
          } else {
            pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
          }
        } else {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        }
      }
      if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g2_ref + (N_L_P_S * 2) && i <= M_g3 + (N_L_P_S * 2)) {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_r[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_g[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_b[i - N_L_P_S * 2];
          } else {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
          }
        } else {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        }
      }
      if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g3_ref + (N_L_P_S * 3) && i <= M_g4 + (N_L_P_S * 3)) {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_r[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_g[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_b[i - N_L_P_S * 3];
          } else {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
          }
        } else {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 20

  if (_Pix_mod == 3) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        if (i >= M_g_ref && i <= M_g1) {
          pi_n_0_r[i] = pi_0_r[i] * pix_coef;
          pi_n_0_g[i] = pi_0_g[i] * pix_coef;
          pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
        if (i > M_g1_ref && i <= M_g2) {
          pi_n_1_r[i] = pi_1_r[i] * pix_coef;
          pi_n_1_g[i] = pi_1_g[i] * pix_coef;
          pi_n_1_b[i] = pi_1_b[i] * pix_coef;
        } else {
          pi_n_1_r[i] = pi_1_sr[i];
          pi_n_1_g[i] = pi_1_sg[i];
          pi_n_1_b[i] = pi_1_sb[i];
        }
        if (i > M_g2_ref && i <= M_g3) {
          pi_n_2_r[i] = pi_2_r[i] * pix_coef;
          pi_n_2_g[i] = pi_2_g[i] * pix_coef;
          pi_n_2_b[i] = pi_2_b[i] * pix_coef;
        } else {
          pi_n_2_r[i] = pi_2_sr[i];
          pi_n_2_g[i] = pi_2_sg[i];
          pi_n_2_b[i] = pi_2_sb[i];
        }
        if (i > M_g3_ref && i <= M_g4) {
          pi_n_3_r[i] = pi_3_r[i] * pix_coef;
          pi_n_3_g[i] = pi_3_g[i] * pix_coef;
          pi_n_3_b[i] = pi_3_b[i] * pix_coef;
        } else {
          pi_n_3_r[i] = pi_3_sr[i];
          pi_n_3_g[i] = pi_3_sg[i];
          pi_n_3_b[i] = pi_3_sb[i];
        }
      } else  {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 30

  if (_Pix_mod == 4) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref__Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref__Pix_pos--;

        if (i >= M_g_ref && i <= M_g1) {
          pi_n_0_r[i] = pi_0_r[i] * pix_coef;
          pi_n_0_g[i] = pi_0_g[i] * pix_coef;
          pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
        if (i > M_g1_ref && i <= M_g2) {
          pi_n_1_r[i] = pi_1_r[i] * pix_coef;
          pi_n_1_g[i] = pi_1_g[i] * pix_coef;
          pi_n_1_b[i] = pi_1_b[i] * pix_coef;
        } else {
          pi_n_1_r[i] = pi_1_sr[i];
          pi_n_1_g[i] = pi_1_sg[i];
          pi_n_1_b[i] = pi_1_sb[i];
        }
        if (i > M_g2_ref && i <= M_g3) {
          pi_n_2_r[i] = pi_2_r[i] * pix_coef;
          pi_n_2_g[i] = pi_2_g[i] * pix_coef;
          pi_n_2_b[i] = pi_2_b[i] * pix_coef;
        } else {
          pi_n_2_r[i] = pi_2_sr[i];
          pi_n_2_g[i] = pi_2_sg[i];
          pi_n_2_b[i] = pi_2_sb[i];
        }
        if (i > M_g3_ref && i <= M_g4) {
          pi_n_3_r[i] = pi_3_r[i] * pix_coef;
          pi_n_3_g[i] = pi_3_g[i] * pix_coef;
          pi_n_3_b[i] = pi_3_b[i] * pix_coef;
        } else {
          pi_n_3_r[i] = pi_3_sr[i];
          pi_n_3_g[i] = pi_3_sg[i];
          pi_n_3_b[i] = pi_3_sb[i];
        }
      } else  {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 40

  if (_Pix_mod == 5) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        if (i <= _Pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= _Pix_center) {
          pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref__Pix_pos = ref__Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;
        if (i >= M_g_ref && i <= M_g1) {
          pi_n_0_r[i] = pi_0_r[i] * pix_coef;
          pi_n_0_g[i] = pi_0_g[i] * pix_coef;
          pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
        if (i > M_g1_ref && i <= M_g2) {
          pi_n_1_r[i] = pi_1_r[i] * pix_coef;
          pi_n_1_g[i] = pi_1_g[i] * pix_coef;
          pi_n_1_b[i] = pi_1_b[i] * pix_coef;
        } else {
          pi_n_1_r[i] = pi_1_sr[i];
          pi_n_1_g[i] = pi_1_sg[i];
          pi_n_1_b[i] = pi_1_sb[i];
        }
        if (i > M_g2_ref && i <= M_g3) {
          pi_n_2_r[i] = pi_2_r[i] * pix_coef;
          pi_n_2_g[i] = pi_2_g[i] * pix_coef;
          pi_n_2_b[i] = pi_2_b[i] * pix_coef;
        } else {
          pi_n_2_r[i] = pi_2_sr[i];
          pi_n_2_g[i] = pi_2_sg[i];
          pi_n_2_b[i] = pi_2_sb[i];
        }
        if (i > M_g3_ref && i <= M_g4) {
          pi_n_3_r[i] = pi_3_r[i] * pix_coef;
          pi_n_3_g[i] = pi_3_g[i] * pix_coef;
          pi_n_3_b[i] = pi_3_b[i] * pix_coef;
        } else {
          pi_n_3_r[i] = pi_3_sr[i];
          pi_n_3_g[i] = pi_3_sg[i];
          pi_n_3_b[i] = pi_3_sb[i];
        }
      } else  {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 50

  if (_Pix_mod == 6) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (_Pix_start <= 1) {
        _Pix_start_v = 1;
      } else {
        _Pix_start_v = _Pix_start;
      }
      pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
      pix_coef = pix_coefi * pix_coefi;

      if (i <= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i >= M_g_ref && i <= M_g1) {
            pi_n_0_r[i] = pi_0_r[i] * pix_coef;
            pi_n_0_g[i] = pi_0_g[i] * pix_coef;
            pi_n_0_b[i] = pi_0_b[i] * pix_coef;
          } else {
            pi_n_0_r[i] = pi_0_sr[i];
            pi_n_0_g[i] = pi_0_sg[i];
            pi_n_0_b[i] = pi_0_sb[i];
          }
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
      }
      if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g1_ref + N_L_P_S && i <= M_g2 + N_L_P_S) {
            pi_n_1_r[i - N_L_P_S] = pi_1_r[i - N_L_P_S] * pix_coef;
            pi_n_1_g[i - N_L_P_S] = pi_1_g[i - N_L_P_S] * pix_coef;
            pi_n_1_b[i - N_L_P_S] = pi_1_b[i - N_L_P_S] * pix_coef;
          } else {
            pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
          }
        } else {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        }
      }
      if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g2_ref + (N_L_P_S * 2) && i <= M_g3 + (N_L_P_S * 2)) {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_r[i - N_L_P_S * 2] * pix_coef;
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_g[i - N_L_P_S * 2] * pix_coef;
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_b[i - N_L_P_S * 2] * pix_coef;
          } else {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
          }
        } else {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        }
      }
      if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g3_ref + (N_L_P_S * 3) && i <= M_g4 + (N_L_P_S * 3)) {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_r[i - N_L_P_S * 3] * pix_coef;
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_g[i - N_L_P_S * 3] * pix_coef;
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_b[i - N_L_P_S * 3] * pix_coef;
          } else {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
          }
        } else {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 60

  if (_Pix_mod == 7) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (_Pix_start <= 1) {
        _Pix_start_v = 1;
      } else {
        _Pix_start_v = _Pix_start;
      }
      pix_coefi = (((_Pix_pos - ref__Pix_pos) * 100) / _Pix_start_v) * 0.01;
      pix_coef = pix_coefi * pix_coefi;
      ref__Pix_pos--;

      if (i <= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i >= M_g_ref && i <= M_g1) {
            pi_n_0_r[i] = pi_0_r[i] * pix_coef;
            pi_n_0_g[i] = pi_0_g[i] * pix_coef;
            pi_n_0_b[i] = pi_0_b[i] * pix_coef;
          } else {
            pi_n_0_r[i] = pi_0_sr[i];
            pi_n_0_g[i] = pi_0_sg[i];
            pi_n_0_b[i] = pi_0_sb[i];
          }
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
      }
      if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g1_ref + N_L_P_S && i <= M_g2 + N_L_P_S) {
            pi_n_1_r[i - N_L_P_S] = pi_1_r[i - N_L_P_S] * pix_coef;
            pi_n_1_g[i - N_L_P_S] = pi_1_g[i - N_L_P_S] * pix_coef;
            pi_n_1_b[i - N_L_P_S] = pi_1_b[i - N_L_P_S] * pix_coef;
          } else {
            pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
          }
        } else {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        }
      }
      if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g2_ref + (N_L_P_S * 2) && i <= M_g3 + (N_L_P_S * 2)) {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_r[i - N_L_P_S * 2] * pix_coef;
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_g[i - N_L_P_S * 2] * pix_coef;
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_b[i - N_L_P_S * 2] * pix_coef;
          } else {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
          }
        } else {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        }
      }
      if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g3_ref + (N_L_P_S * 3) && i <= M_g4 + (N_L_P_S * 3)) {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_r[i - N_L_P_S * 3] * pix_coef;
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_g[i - N_L_P_S * 3] * pix_coef;
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_b[i - N_L_P_S * 3] * pix_coef;
          } else {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
          }
        } else {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 70

  if (_Pix_mod == 8) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (_Pix_start <= 1) {
        _Pix_start_v = 1;
      } else {
        _Pix_start_v = _Pix_start;
      }
      if (i <= _Pix_center) {
        pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
      }
      else if (i >= _Pix_center) {
        pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref__Pix_pos = ref__Pix_pos - 2;
      }
      if (pix_coef > 1) pix_coef = 1;

      if (i <= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i >= M_g_ref && i <= M_g1) {
            pi_n_0_r[i] = pi_0_r[i] * pix_coef;
            pi_n_0_g[i] = pi_0_g[i] * pix_coef;
            pi_n_0_b[i] = pi_0_b[i] * pix_coef;
          } else {
            pi_n_0_r[i] = pi_0_sr[i];
            pi_n_0_g[i] = pi_0_sg[i];
            pi_n_0_b[i] = pi_0_sb[i];
          }
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
      }
      if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g1_ref + N_L_P_S && i <= M_g2 + N_L_P_S) {
            pi_n_1_r[i - N_L_P_S] = pi_1_r[i - N_L_P_S] * pix_coef;
            pi_n_1_g[i - N_L_P_S] = pi_1_g[i - N_L_P_S] * pix_coef;
            pi_n_1_b[i - N_L_P_S] = pi_1_b[i - N_L_P_S] * pix_coef;
          } else {
            pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
          }
        } else {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        }
      }
      if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g2_ref + (N_L_P_S * 2) && i <= M_g3 + (N_L_P_S * 2)) {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_r[i - N_L_P_S * 2] * pix_coef;
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_g[i - N_L_P_S * 2] * pix_coef;
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_b[i - N_L_P_S * 2] * pix_coef;
          } else {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
          }
        } else {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        }
      }
      if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          if (i > M_g3_ref + (N_L_P_S * 3) && i <= M_g4 + (N_L_P_S * 3)) {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_r[i - N_L_P_S * 3] * pix_coef;
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_g[i - N_L_P_S * 3] * pix_coef;
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_b[i - N_L_P_S * 3] * pix_coef;
          } else {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
          }
        } else {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 80

  if (_Pix_mod == 9) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i >= M_g_ref && i <= M_g1) {
          pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
          pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
          pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
        if (i > M_g1_ref && i <= M_g2) {
          pi_n_1_r[i] = (pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond);
          pi_n_1_g[i] = (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond);
          pi_n_1_b[i] = (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond);
        } else {
          pi_n_1_r[i] = pi_1_sr[i];
          pi_n_1_g[i] = pi_1_sg[i];
          pi_n_1_b[i] = pi_1_sb[i];
        }
        if (i > M_g2_ref && i <= M_g3) {
          pi_n_2_r[i] = (pi_2_r[i] * pix_coef) + (pi_2_sr[i] * pix_coef_fond);
          pi_n_2_g[i] = (pi_2_g[i] * pix_coef) + (pi_2_sg[i] * pix_coef_fond);
          pi_n_2_b[i] = (pi_2_b[i] * pix_coef) + (pi_2_sb[i] * pix_coef_fond);
        } else {
          pi_n_2_r[i] = pi_2_sr[i];
          pi_n_2_g[i] = pi_2_sg[i];
          pi_n_2_b[i] = pi_2_sb[i];
        }
        if (i > M_g3_ref && i <= M_g4) {
          pi_n_3_r[i] = (pi_3_r[i] * pix_coef) + (pi_3_sr[i] * pix_coef_fond);
          pi_n_3_g[i] = (pi_3_g[i] * pix_coef) + (pi_3_sg[i] * pix_coef_fond);
          pi_n_3_b[i] = (pi_3_b[i] * pix_coef) + (pi_3_sb[i] * pix_coef_fond);
        } else {
          pi_n_3_r[i] = pi_3_sr[i];
          pi_n_3_g[i] = pi_3_sg[i];
          pi_n_3_b[i] = pi_3_sb[i];
        }
      } else  {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 90

  if (_Pix_mod == 10) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref__Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;
        ref__Pix_pos--;

        if (i >= M_g_ref && i <= M_g1) {
          pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
          pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
          pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
        if (i > M_g1_ref && i <= M_g2) {
          pi_n_1_r[i] = (pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond);
          pi_n_1_g[i] = (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond);
          pi_n_1_b[i] = (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond);
        } else {
          pi_n_1_r[i] = pi_1_sr[i];
          pi_n_1_g[i] = pi_1_sg[i];
          pi_n_1_b[i] = pi_1_sb[i];
        }
        if (i > M_g2_ref && i <= M_g3) {
          pi_n_2_r[i] = (pi_2_r[i] * pix_coef) + (pi_2_sr[i] * pix_coef_fond);
          pi_n_2_g[i] = (pi_2_g[i] * pix_coef) + (pi_2_sg[i] * pix_coef_fond);
          pi_n_2_b[i] = (pi_2_b[i] * pix_coef) + (pi_2_sb[i] * pix_coef_fond);
        } else {
          pi_n_2_r[i] = pi_2_sr[i];
          pi_n_2_g[i] = pi_2_sg[i];
          pi_n_2_b[i] = pi_2_sb[i];
        }
        if (i > M_g3_ref && i <= M_g4) {
          pi_n_3_r[i] = (pi_3_r[i] * pix_coef) + (pi_3_sr[i] * pix_coef_fond);
          pi_n_3_g[i] = (pi_3_g[i] * pix_coef) + (pi_3_sg[i] * pix_coef_fond);
          pi_n_3_b[i] = (pi_3_b[i] * pix_coef) + (pi_3_sb[i] * pix_coef_fond);
        } else {
          pi_n_3_r[i] = pi_3_sr[i];
          pi_n_3_g[i] = pi_3_sg[i];
          pi_n_3_b[i] = pi_3_sb[i];
        }
      } else  {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 100

  if (_Pix_mod == 11) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        if (i <= _Pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= _Pix_center) {
          pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref__Pix_pos = ref__Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i >= M_g_ref && i <= M_g1) {
          pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
          pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
          pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
        if (i > M_g1_ref && i <= M_g2) {
          pi_n_1_r[i] = (pi_1_r[i] * pix_coef) + (pi_1_sr[i] * pix_coef_fond);
          pi_n_1_g[i] = (pi_1_g[i] * pix_coef) + (pi_1_sg[i] * pix_coef_fond);
          pi_n_1_b[i] = (pi_1_b[i] * pix_coef) + (pi_1_sb[i] * pix_coef_fond);
        } else {
          pi_n_1_r[i] = pi_1_sr[i];
          pi_n_1_g[i] = pi_1_sg[i];
          pi_n_1_b[i] = pi_1_sb[i];
        }
        if (i > M_g2_ref && i <= M_g3) {
          pi_n_2_r[i] = (pi_2_r[i] * pix_coef) + (pi_2_sr[i] * pix_coef_fond);
          pi_n_2_g[i] = (pi_2_g[i] * pix_coef) + (pi_2_sg[i] * pix_coef_fond);
          pi_n_2_b[i] = (pi_2_b[i] * pix_coef) + (pi_2_sb[i] * pix_coef_fond);
        } else {
          pi_n_2_r[i] = pi_2_sr[i];
          pi_n_2_g[i] = pi_2_sg[i];
          pi_n_2_b[i] = pi_2_sb[i];
        }
        if (i > M_g3_ref && i <= M_g4) {
          pi_n_3_r[i] = (pi_3_r[i] * pix_coef) + (pi_3_sr[i] * pix_coef_fond);
          pi_n_3_g[i] = (pi_3_g[i] * pix_coef) + (pi_3_sg[i] * pix_coef_fond);
          pi_n_3_b[i] = (pi_3_b[i] * pix_coef) + (pi_3_sb[i] * pix_coef_fond);
        } else {
          pi_n_3_r[i] = pi_3_sr[i];
          pi_n_3_g[i] = pi_3_sg[i];
          pi_n_3_b[i] = pi_3_sb[i];
        }
      } else  {
        pi_n_0_r[i] = pi_0_sr[i];
        pi_n_0_g[i] = pi_0_sg[i];
        pi_n_0_b[i] = pi_0_sb[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
      }
    }//for i
  }//_Pix_mod 110

  if (_Pix_mod == 12) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i >= M_g_ref && i <= M_g1) {
              pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
              pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
              pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
            } else {
              pi_n_0_r[i] = pi_0_sr[i];
              pi_n_0_g[i] = pi_0_sg[i];
              pi_n_0_b[i] = pi_0_sb[i];
            }
          } else {
            pi_n_0_r[i] = pi_0_sr[i];
            pi_n_0_g[i] = pi_0_sg[i];
            pi_n_0_b[i] = pi_0_sb[i];
          }
        }
        if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g1_ref + N_L_P_S && i <= M_g2 + N_L_P_S) {
              pi_n_1_r[i - N_L_P_S] = (pi_1_r[i - N_L_P_S] * pix_coef) + (pi_1_sr[i - N_L_P_S] * pix_coef_fond);
              pi_n_1_g[i - N_L_P_S] = (pi_1_g[i - N_L_P_S] * pix_coef) + (pi_1_sg[i - N_L_P_S] * pix_coef_fond);
              pi_n_1_b[i - N_L_P_S] = (pi_1_b[i - N_L_P_S] * pix_coef) + (pi_1_sb[i - N_L_P_S] * pix_coef_fond);
            } else {
              pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
              pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
              pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
            }
          } else {
            pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
          }
        }
        if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g2_ref + (N_L_P_S * 2) && i <= M_g3 + (N_L_P_S * 2)) {
              pi_n_2_r[i - N_L_P_S * 2] = (pi_2_r[i - N_L_P_S * 2] * pix_coef) + (pi_2_sr[i - N_L_P_S * 2] * pix_coef_fond);
              pi_n_2_g[i - N_L_P_S * 2] = (pi_2_g[i - N_L_P_S * 2] * pix_coef) + (pi_2_sg[i - N_L_P_S * 2] * pix_coef_fond);
              pi_n_2_b[i - N_L_P_S * 2] = (pi_2_b[i - N_L_P_S * 2] * pix_coef) + (pi_2_sb[i - N_L_P_S * 2] * pix_coef_fond);
            } else {
              pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
              pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
              pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
            }
          } else {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
          }
        }
        if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g3_ref + (N_L_P_S * 3) && i <= M_g4 + (N_L_P_S * 3)) {
              pi_n_3_r[i - N_L_P_S * 3] = (pi_3_r[i - N_L_P_S * 3] * pix_coef) + (pi_3_sr[i - N_L_P_S * 3] * pix_coef_fond);
              pi_n_3_g[i - N_L_P_S * 3] = (pi_3_g[i - N_L_P_S * 3] * pix_coef) + (pi_3_sg[i - N_L_P_S * 3] * pix_coef_fond);
              pi_n_3_b[i - N_L_P_S * 3] = (pi_3_b[i - N_L_P_S * 3] * pix_coef) + (pi_3_sb[i - N_L_P_S * 3] * pix_coef_fond);
            } else {
              pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
              pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
              pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
            }
          } else {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
          }
        }
      }
    }//for i
  }//_Pix_mod 120

  if (_Pix_mod == 13) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref__Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref__Pix_pos--;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i >= M_g_ref && i <= M_g1) {
              pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
              pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
              pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
            } else {
              pi_n_0_r[i] = pi_0_sr[i];
              pi_n_0_g[i] = pi_0_sg[i];
              pi_n_0_b[i] = pi_0_sb[i];
            }
          } else {
            pi_n_0_r[i] = pi_0_sr[i];
            pi_n_0_g[i] = pi_0_sg[i];
            pi_n_0_b[i] = pi_0_sb[i];
          }
        }
        if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g1_ref + N_L_P_S && i <= M_g2 + N_L_P_S) {
              pi_n_1_r[i - N_L_P_S] = (pi_1_r[i - N_L_P_S] * pix_coef) + (pi_1_sr[i - N_L_P_S] * pix_coef_fond);
              pi_n_1_g[i - N_L_P_S] = (pi_1_g[i - N_L_P_S] * pix_coef) + (pi_1_sg[i - N_L_P_S] * pix_coef_fond);
              pi_n_1_b[i - N_L_P_S] = (pi_1_b[i - N_L_P_S] * pix_coef) + (pi_1_sb[i - N_L_P_S] * pix_coef_fond);
            } else {
              pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
              pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
              pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
            }
          } else {
            pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
          }
        }
        if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g2_ref + (N_L_P_S * 2) && i <= M_g3 + (N_L_P_S * 2)) {
              pi_n_2_r[i - N_L_P_S * 2] = (pi_2_r[i - N_L_P_S * 2] * pix_coef) + (pi_2_sr[i - N_L_P_S * 2] * pix_coef_fond);
              pi_n_2_g[i - N_L_P_S * 2] = (pi_2_g[i - N_L_P_S * 2] * pix_coef) + (pi_2_sg[i - N_L_P_S * 2] * pix_coef_fond);
              pi_n_2_b[i - N_L_P_S * 2] = (pi_2_b[i - N_L_P_S * 2] * pix_coef) + (pi_2_sb[i - N_L_P_S * 2] * pix_coef_fond);
            } else {
              pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
              pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
              pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
            }
          } else {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
          }
        }
        if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g3_ref + (N_L_P_S * 3) && i <= M_g4 + (N_L_P_S * 3)) {
              pi_n_3_r[i - N_L_P_S * 3] = (pi_3_r[i - N_L_P_S * 3] * pix_coef) + (pi_3_sr[i - N_L_P_S * 3] * pix_coef_fond);
              pi_n_3_g[i - N_L_P_S * 3] = (pi_3_g[i - N_L_P_S * 3] * pix_coef) + (pi_3_sg[i - N_L_P_S * 3] * pix_coef_fond);
              pi_n_3_b[i - N_L_P_S * 3] = (pi_3_b[i - N_L_P_S * 3] * pix_coef) + (pi_3_sb[i - N_L_P_S * 3] * pix_coef_fond);
            } else {
              pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
              pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
              pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
            }
          } else {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
          }
        }
      }
    }//for i
  }//_Pix_mod 130

  if (_Pix_mod == 14) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        if (i <= _Pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= _Pix_center) {
          pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref__Pix_pos = ref__Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i >= M_g_ref && i <= M_g1) {
              pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
              pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
              pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
            } else {
              pi_n_0_r[i] = pi_0_sr[i];
              pi_n_0_g[i] = pi_0_sg[i];
              pi_n_0_b[i] = pi_0_sb[i];
            }
          } else {
            pi_n_0_r[i] = pi_0_sr[i];
            pi_n_0_g[i] = pi_0_sg[i];
            pi_n_0_b[i] = pi_0_sb[i];
          }
        }
        if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g1_ref + N_L_P_S && i <= M_g2 + N_L_P_S) {
              pi_n_1_r[i - N_L_P_S] = (pi_1_r[i - N_L_P_S] * pix_coef) + (pi_1_sr[i - N_L_P_S] * pix_coef_fond);
              pi_n_1_g[i - N_L_P_S] = (pi_1_g[i - N_L_P_S] * pix_coef) + (pi_1_sg[i - N_L_P_S] * pix_coef_fond);
              pi_n_1_b[i - N_L_P_S] = (pi_1_b[i - N_L_P_S] * pix_coef) + (pi_1_sb[i - N_L_P_S] * pix_coef_fond);
            } else {
              pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
              pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
              pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
            }
          } else {
            pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
            pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
            pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
          }
        }
        if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g2_ref + (N_L_P_S * 2) && i <= M_g3 + (N_L_P_S * 2)) {
              pi_n_2_r[i - N_L_P_S * 2] = (pi_2_r[i - N_L_P_S * 2] * pix_coef) + (pi_2_sr[i - N_L_P_S * 2] * pix_coef_fond);
              pi_n_2_g[i - N_L_P_S * 2] = (pi_2_g[i - N_L_P_S * 2] * pix_coef) + (pi_2_sg[i - N_L_P_S * 2] * pix_coef_fond);
              pi_n_2_b[i - N_L_P_S * 2] = (pi_2_b[i - N_L_P_S * 2] * pix_coef) + (pi_2_sb[i - N_L_P_S * 2] * pix_coef_fond);
            } else {
              pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
              pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
              pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
            }
          } else {
            pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
            pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
            pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
          }
        }
        if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
            if (i > M_g3_ref + (N_L_P_S * 3) && i <= M_g4 + (N_L_P_S * 3)) {
              pi_n_3_r[i - N_L_P_S * 3] = (pi_3_r[i - N_L_P_S * 3] * pix_coef) + (pi_3_sr[i - N_L_P_S * 3] * pix_coef_fond);
              pi_n_3_g[i - N_L_P_S * 3] = (pi_3_g[i - N_L_P_S * 3] * pix_coef) + (pi_3_sg[i - N_L_P_S * 3] * pix_coef_fond);
              pi_n_3_b[i - N_L_P_S * 3] = (pi_3_b[i - N_L_P_S * 3] * pix_coef) + (pi_3_sb[i - N_L_P_S * 3] * pix_coef_fond);
            } else {
              pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
              pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
              pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
            }
          } else {
            pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
            pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
            pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
          }
        }
      }
    }//for i
  }//_Pix_mod 140
}// do_effet_11 ruban 1/4 2/4 3/4 4/4
