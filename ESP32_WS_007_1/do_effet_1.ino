void do_effet_1() {
  if (_Pix_mod >= 0 && _Pix_mod <= 10) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      pi_n_0_r[i] = pi_0_r[i];
      pi_n_0_g[i] = pi_0_g[i];
      pi_n_0_b[i] = pi_0_b[i];
      pi_n_1_r[i] = pi_1_sr[i];
      pi_n_1_g[i] = pi_1_sg[i];
      pi_n_1_b[i] = pi_1_sb[i];
      pi_n_2_r[i] = pi_2_sr[i];
      pi_n_2_g[i] = pi_2_sg[i];
      pi_n_2_b[i] = pi_2_sb[i];
      pi_n_3_r[i] = pi_3_sr[i];
      pi_n_3_g[i] = pi_3_sg[i];
      pi_n_3_b[i] = pi_3_sb[i];
    }//for i
  }//_Pix_mod 0

  if (_Pix_mod >= 11 && _Pix_mod <= 20) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        pi_n_0_r[i] = pi_0_r[i];
        pi_n_0_g[i] = pi_0_g[i];
        pi_n_0_b[i] = pi_0_b[i];
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
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

  if (_Pix_mod >= 21 && _Pix_mod <= 30) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i <= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          pi_n_0_r[i] = pi_0_r[i];
          pi_n_0_g[i] = pi_0_g[i];
          pi_n_0_b[i] = pi_0_b[i];
        } else {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        }
      }
      if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        }
      }
      if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        }
      }
      if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        } else {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 20

  if (_Pix_mod >= 31 && _Pix_mod <= 40) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        pi_n_0_r[i] = pi_0_r[i] * pix_coef;
        pi_n_0_g[i] = pi_0_g[i] * pix_coef;
        pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
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

  if (_Pix_mod >= 41 && _Pix_mod <= 50) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref__Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref__Pix_pos--;

        pi_n_0_r[i] = pi_0_r[i] * pix_coef;
        pi_n_0_g[i] = pi_0_g[i] * pix_coef;
        pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
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

  if (_Pix_mod >= 51 && _Pix_mod <= 60) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref__Pix_pos = ref__Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pi_n_0_r[i] = pi_0_r[i] * pix_coef;
        pi_n_0_g[i] = pi_0_g[i] * pix_coef;
        pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
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

  if (_Pix_mod >= 61 && _Pix_mod <= 70) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_r[i] * pix_coef;
          pi_n_0_g[i] = pi_0_g[i] * pix_coef;
          pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 60

  if (_Pix_mod >= 71 && _Pix_mod <= 80) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref__Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref__Pix_pos--;

        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_r[i] * pix_coef;
          pi_n_0_g[i] = pi_0_g[i] * pix_coef;
          pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 70

  if (_Pix_mod >= 81 && _Pix_mod <= 90) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref__Pix_pos = ref__Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_r[i] * pix_coef;
          pi_n_0_g[i] = pi_0_g[i] * pix_coef;
          pi_n_0_b[i] = pi_0_b[i] * pix_coef;
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 80

  if (_Pix_mod >= 91 && _Pix_mod <= 100) {
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

        pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
        pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
        pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
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

  if (_Pix_mod >= 101 && _Pix_mod <= 110) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref__Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
        pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
        pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
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

  if (_Pix_mod >= 111 && _Pix_mod <= 120) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref__Pix_pos = ref__Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
        pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
        pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        pi_n_1_r[i] = pi_1_sr[i];
        pi_n_1_g[i] = pi_1_sg[i];
        pi_n_1_b[i] = pi_1_sb[i];
        pi_n_2_r[i] = pi_2_sr[i];
        pi_n_2_g[i] = pi_2_sg[i];
        pi_n_2_b[i] = pi_2_sb[i];
        pi_n_3_r[i] = pi_3_sr[i];
        pi_n_3_g[i] = pi_3_sg[i];
        pi_n_3_b[i] = pi_3_sb[i];
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

  if (_Pix_mod >= 121 && _Pix_mod <= 130) {
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
          pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
          pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
          pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 120

  if (_Pix_mod >= 131 && _Pix_mod <= 140) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
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
          pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
          pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
          pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 130

  if (_Pix_mod >= 141 && _Pix_mod <= 150) {
    ref__Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= (_Pix_start + _Pix_pos)) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        if (i <= pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= pix_center) {
          pix_coefi = ((((_Pix_pos - ref__Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref__Pix_pos = ref__Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          pi_n_0_r[i] = (pi_0_r[i] * pix_coef) + (pi_0_sr[i] * pix_coef_fond);
          pi_n_0_g[i] = (pi_0_g[i] * pix_coef) + (pi_0_sg[i] * pix_coef_fond);
          pi_n_0_b[i] = (pi_0_b[i] * pix_coef) + (pi_0_sb[i] * pix_coef_fond);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pi_n_0_r[i] = pi_0_sr[i];
          pi_n_0_g[i] = pi_0_sg[i];
          pi_n_0_b[i] = pi_0_sb[i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pi_n_1_r[i - N_L_P_S] = pi_1_sr[i - N_L_P_S];
          pi_n_1_g[i - N_L_P_S] = pi_1_sg[i - N_L_P_S];
          pi_n_1_b[i - N_L_P_S] = pi_1_sb[i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pi_n_2_r[i - N_L_P_S * 2] = pi_2_sr[i - N_L_P_S * 2];
          pi_n_2_g[i - N_L_P_S * 2] = pi_2_sg[i - N_L_P_S * 2];
          pi_n_2_b[i - N_L_P_S * 2] = pi_2_sb[i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pi_n_3_r[i - N_L_P_S * 3] = pi_3_sr[i - N_L_P_S * 3];
          pi_n_3_g[i - N_L_P_S * 3] = pi_3_sg[i - N_L_P_S * 3];
          pi_n_3_b[i - N_L_P_S * 3] = pi_3_sb[i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 140
}//do_effet_1 ruban 1
