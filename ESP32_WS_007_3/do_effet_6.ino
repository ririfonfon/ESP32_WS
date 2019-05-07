void do_effet_6() {
  if (_Pix_mod == 0) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      pix_buffer[0][i] = pix_colorA[0][i];
      pix_buffer[1][i] = pix_colorB[1][i];
      pix_buffer[2][i] = pix_colorA[2][i];
      pix_buffer[3][i] = pix_colorB[3][i];
    }//for i
  }//_Pix_mod 0

  if (_Pix_mod == 1) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        pix_buffer[0][i] = pix_colorA[0][i];
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = pix_colorA[2][i];
        pix_buffer[3][i] = pix_colorB[3][i];
      } else  {
        pix_buffer[0][i] = pix_colorB[0][i];
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = pix_colorB[2][i];
        pix_buffer[3][i] = pix_colorB[3][i];
      }
    }//for i
  }//_Pix_mod 10

  if (_Pix_mod == 2) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i <= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
          pix_buffer[0][i] = pix_colorA[0][i];
        } else {
          pix_buffer[0][i] = pix_colorB[0][i];
        }
      }
      if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        }
      }
      if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorA[2][i - N_L_P_S * 2];
        } else {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorB[2][i - N_L_P_S * 2];
        }
      }
      if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
        if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        } else {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 20

  if (_Pix_mod == 3) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        pix_buffer[0][i] = pix_colorA[0][i] * pix_coef;
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = pix_colorA[2][i] * pix_coef;
        pix_buffer[3][i] = pix_colorB[3][i];
      } else  {
        pix_buffer[0][i] = pix_colorB[0][i];
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = pix_colorB[2][i];
        pix_buffer[3][i] = pix_colorB[3][i];
      }
    }//for i
  }//_Pix_mod 30

  if (_Pix_mod == 4) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref_Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref_Pix_pos--;

        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorA[0][i] * pix_coef;
          pix_buffer[1][i] = pix_colorB[1][i];
          pix_buffer[2][i] = pix_colorA[2][i] * pix_coef;
          pix_buffer[3][i] = pix_colorB[3][i];
        } else  {
          pix_buffer[0][i] = pix_colorB[0][i];
          pix_buffer[1][i] = pix_colorB[1][i];
          pix_buffer[2][i] = pix_colorB[2][i];
          pix_buffer[3][i] = pix_colorB[3][i];
        }
      }
    }//for i
  }//_Pix_mod 40

  if (_Pix_mod == 5) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
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
          pix_coefi = ((((_Pix_pos - ref_Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_Pix_pos = ref_Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorA[0][i] * pix_coef;
          pix_buffer[1][i] = pix_colorB[1][i];
          pix_buffer[2][i] = pix_colorA[2][i] * pix_coef;
          pix_buffer[3][i] = pix_colorB[3][i];
        } else  {
          pix_buffer[0][i] = pix_colorB[0][i];
          pix_buffer[1][i] = pix_colorB[1][i];
          pix_buffer[2][i] = pix_colorB[2][i];
          pix_buffer[3][i] = pix_colorB[3][i];
        }
      }
    }//for i
  }//_Pix_mod 50

  if (_Pix_mod == 6) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorA[0][i] * pix_coef;
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorA[2][ - N_L_P_S * 2] * pix_coef;
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorB[0][i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorB[2][i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 60

  if (_Pix_mod == 7) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref_Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref_Pix_pos--;

        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorA[0][i] * pix_coef;
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorA[2][ - N_L_P_S * 2] * pix_coef;
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorB[0][i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorB[2][i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 70

  if (_Pix_mod == 8) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
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
          pix_coefi = ((((_Pix_pos - ref_Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_Pix_pos = ref_Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorA[0][i] * pix_coef;
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorA[2][ - N_L_P_S * 2] * pix_coef;
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorB[0][i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorB[2][i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 80

  if (_Pix_mod == 9) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        pix_buffer[0][i] = ( pix_colorA[0][i] * pix_coef) + (pix_colorB[0][i] * pix_coef_fond);
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = ( pix_colorA[2][i] * pix_coef) + (pix_colorB[2][i] * pix_coef_fond);
        pix_buffer[3][i] = pix_colorB[3][i];
      } else  {
        pix_buffer[0][i] = pix_colorB[0][i];
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = pix_colorB[2][i];
        pix_buffer[3][i] = pix_colorB[3][i];
      }
    }//for i
  }//_Pix_mod 90

  if (_Pix_mod == 10) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref_Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;
        ref_Pix_pos--;

        pix_buffer[0][i] = ( pix_colorA[0][i] * pix_coef) + (pix_colorB[0][i] * pix_coef_fond);
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = ( pix_colorA[2][i] * pix_coef) + (pix_colorB[2][i] * pix_coef_fond);
        pix_buffer[3][i] = pix_colorB[3][i];
      } else  {
        pix_buffer[0][i] = pix_colorB[0][i];
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = pix_colorB[2][i];
        pix_buffer[3][i] = pix_colorB[3][i];
      }
    }//for i
  }//_Pix_mod 100

  if (_Pix_mod == 11) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
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
          pix_coefi = ((((_Pix_pos - ref_Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_Pix_pos = ref_Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        pix_buffer[0][i] = ( pix_colorA[0][i] * pix_coef) + (pix_colorB[0][i] * pix_coef_fond);
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = ( pix_colorA[2][i] * pix_coef) + (pix_colorB[2][i] * pix_coef_fond);
        pix_buffer[3][i] = pix_colorB[3][i];
      } else  {
        pix_buffer[0][i] = pix_colorB[0][i];
        pix_buffer[1][i] = pix_colorB[1][i];
        pix_buffer[2][i] = pix_colorB[2][i];
        pix_buffer[3][i] = pix_colorB[3][i];
      }
    }//for i
  }//_Pix_mod 110

  if (_Pix_mod == 12) {
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
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
          pix_buffer[0][i] = ( pix_colorA[0][i] * pix_coef) + (pix_colorB[0][i] * pix_coef_fond);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = ( pix_colorA[2][i - N_L_P_S * 2] * pix_coef) + (pix_colorB[2][i - N_L_P_S * 2] * pix_coef_fond);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      } else  {
        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorB[0][i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorB[2][i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 120

  if (_Pix_mod == 13) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
        if (_Pix_start <= 1) {
          _Pix_start_v = 1;
        } else {
          _Pix_start_v = _Pix_start;
        }
        pix_coefi = (((_Pix_pos - ref_Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref_Pix_pos--;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          pix_buffer[0][i] = ( pix_colorA[0][i] * pix_coef) + (pix_colorB[0][i] * pix_coef_fond);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = ( pix_colorA[2][i - N_L_P_S * 2] * pix_coef) + (pix_colorB[2][i - N_L_P_S * 2] * pix_coef_fond);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorB[0][i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorB[2][i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 130

  if (_Pix_mod == 14) {
    ref_Pix_pos = (_Pix_start + _Pix_pos);
    for (int i = 0 ; i < numberOfLed ; i++) {
      if (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos) ) {
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
          pix_coefi = ((((_Pix_pos - ref_Pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_Pix_pos = ref_Pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        if (i <= N_L_P_S) {
          pix_buffer[0][i] = ( pix_colorA[0][i] * pix_coef) + (pix_colorB[0][i] * pix_coef_fond);
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = ( pix_colorA[2][i - N_L_P_S * 2] * pix_coef) + (pix_colorB[2][i - N_L_P_S * 2] * pix_coef_fond);
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      } else {
        if (i <= N_L_P_S) {
          pix_buffer[0][i] = pix_colorB[0][i];
        } else if (i <= N_L_P_S * 2 & i >= N_L_P_S) {
          pix_buffer[1][i - N_L_P_S] = pix_colorB[1][i - N_L_P_S];
        } else if (i <= N_L_P_S * 3 & i >= N_L_P_S * 2) {
          pix_buffer[2][i - N_L_P_S * 2] = pix_colorB[2][i - N_L_P_S * 2];
        } else if (i <= N_L_P_S * 4 & i >= N_L_P_S * 3) {
          pix_buffer[3][i - N_L_P_S * 3] = pix_colorB[3][i - N_L_P_S * 3];
        }
      }
    }//for i
  }//_Pix_mod 140
}//do_effet_6 ruban 13
