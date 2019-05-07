void effet() {
  if (_Fx_type == 0)
    //    do_effet_0();
    do_effet();
  else if (_Fx_type == 1)
//        do_effet_1();
    do_effet();
  else if (_Fx_type == 2)
//    do_effet_2();
    do_effet();
  else if (_Fx_type == 3)
//    do_effet_3();
    do_effet();
  else if (_Fx_type == 4)
//    do_effet_4();
    do_effet();
  else if (_Fx_type == 5)
//    do_effet_5();
    do_effet();
  else if (_Fx_type == 6)
//    do_effet_6();
    do_effet();
  else if (_Fx_type == 7)
//    do_effet_7();
    do_effet();
  else if (_Fx_type == 8)
//    do_effet_8();
    do_effet();
  else if (_Fx_type == 9)
//    do_effet_9();
    do_effet();
  else if (_Fx_type == 10)
//    do_effet_10();
    do_effet();
  else if (_Fx_type == 11)
    do_effet_11();
  else if (_Fx_type == 12)
    do_effet_12();
  else if (_Fx_type == 255)
    do_effet_255();

  leds_show();
}//effet

bool activeStrip[12][NUM_STRIPS] = {
  {true, true, true, true},     // _Fx_type = 0  ru all
  {true, false, false, false},  // _Fx_type = 1  ru 1
  {false, true, false, false},  // _Fx_type = 2  ru 2
  {false, false, true, false},  // _Fx_type = 3  ru 3
  {false, false, false, true},  // _Fx_type = 4  ru 4
  {true, true, false, false},   // _Fx_type = 5  ru 1 2
  {true, false, true, false},   // _Fx_type = 6  ru 1 3
  {true, false, false, true},   // _Fx_type = 7  ru 1 4
  {false, true, true, false},   // _Fx_type = 8  ru 2 3
  {false, true, false, true},   // _Fx_type = 9  ru 2 4
  {false, false, true, true},   // _Fx_type = 10 ru 3 4
  {true, true, true, true}      // _Fx_type = 11 ?????
};

// Decide if pixel is active or is background
//
bool isActive(int strip, int i) {

  // check if strip is active for this "_Fx_type"
  if (_Fx_type <= 11 && !activeStrip[_Fx_type][strip]) return false;
  if (_Fx_type <= 11 && activeStrip[_Fx_type][strip]) return true;

  // check if i is in range
  if (_Fx_type == 0) return true;
//  else if (_Fx_type <= 10) return (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos));
//  else if (_Fx_type == 11) return (i >= M_g[strip][0] && i <= M_g[strip][1]);

  return true;
}


int ref_pix_pos;

void do_effet() {

  if (_Pix_mod == 0) {
      Serial.println("_Pix_mod == 0 do_effet  ");
    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i))
          pix_buffer[s][i] = pix_colorA[s][i];
        else
          pix_buffer[s][i] = pix_colorB[s][i];

  }//_Pix_mod 0


  if (_Pix_mod == 1) {
    Serial.println("_Pix_mod == 1 do_effet  ");
    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i))
          pix_buffer[s][i] = pix_colorA[s][i];
        else
          pix_buffer[s][i] = pix_colorB[s][i];

  }//_Pix_mod 10


  if (_Pix_mod == 2) {

    int s, p = 0;

    for (int i = 0 ; i < numberOfLed ; i++) {
      s = i / NUM_LEDS_PER_STRIP;
      p = i % NUM_LEDS_PER_STRIP;

      if (isActive(s, i))
        pix_buffer[s][p] = pix_colorA[s][p];
      else
        pix_buffer[s][p] = pix_colorB[s][p];
    }

  }//_Pix_mod 20


  if (_Pix_mod == 3) {

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i)) {
          pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;

          pix_buffer[s][i] = pix_colorA[s][i] * pix_coef;
        }
        else {
          pix_buffer[s][i] = pix_colorB[s][i];
        }

  }//_Pix_mod 30


  if (_Pix_mod == 4) {

    ref_pix_pos = (_Pix_start + _Pix_pos);

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i)) {
          pix_coefi = (((_Pix_pos - ref_pix_pos) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_pix_pos--;

          pix_buffer[s][i] = pix_colorA[s][i] * pix_coef;
        }
        else {
          pix_buffer[s][i] = pix_colorB[s][i];
        }

  }//_Pix_mod 40


  if (_Pix_mod == 5) {

    ref_pix_pos = (_Pix_start + _Pix_pos);

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i)) {
          if (i <= _Pix_center) {
            pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
            pix_coef = pix_coefi * pix_coefi;
          }
          else if (i >= _Pix_center) {
            pix_coefi = ((((_Pix_pos - ref_pix_pos)) * 100) / _Pix_start_v) * 0.01;
            pix_coef = pix_coefi * pix_coefi;
            ref_pix_pos = ref_pix_pos - 2;
          }
          if (pix_coef > 1) pix_coef = 1;

          pix_buffer[s][i] = pix_colorA[s][i] * pix_coef;
        }
        else  {
          pix_buffer[s][i] = pix_colorB[s][i];
        }

  }//_Pix_mod 50


  if (_Pix_mod == 6) {

    int s, p = 0;

    for (int i = 0 ; i < numberOfLed ; i++) {
      s = i / NUM_LEDS_PER_STRIP;
      p = i % NUM_LEDS_PER_STRIP;

      if (isActive(s, i)) {
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        pix_buffer[s][p] = pix_colorA[s][p] * pix_coef;
      }
      else {
        pix_buffer[s][p] = pix_colorB[s][p];
      }
    }//for i

  }//_Pix_mod 60


  if (_Pix_mod == 7) {

    ref_pix_pos = (_Pix_start + _Pix_pos);
    int s, p = 0;

    for (int i = 0 ; i < numberOfLed ; i++) {
      s = i / NUM_LEDS_PER_STRIP;
      p = i % NUM_LEDS_PER_STRIP;

      if (isActive(s, i)) {
        pix_coefi = (((_Pix_pos - ref_pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref_pix_pos--;

        pix_buffer[s][p] = pix_colorA[s][p] * pix_coef;
      }
      else {
        pix_buffer[s][p] = pix_colorB[s][p];
      }
    }//for i

  }//_Pix_mod 70


  if (_Pix_mod == 8) {
    ref_pix_pos = (_Pix_start + _Pix_pos);
    int s, p = 0;

    for (int i = 0 ; i < numberOfLed ; i++) {
      s = i / NUM_LEDS_PER_STRIP;
      p = i % NUM_LEDS_PER_STRIP;

      if (isActive(s, i)) {
        if (i <= _Pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= _Pix_center) {
          pix_coefi = ((((_Pix_pos - ref_pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_pix_pos = ref_pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_buffer[s][p] = pix_colorA[s][p] * pix_coef;
      }
      else {
        pix_buffer[s][p] = pix_colorB[s][p];
      }
    }//for i

  }//_Pix_mod 80


  if (_Pix_mod == 8) {

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i)) {
          pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
          pix_coef_fond = pix_coefi_fond / 100;

          pix_buffer[s][i] = (pix_colorA[s][i] * pix_coef) + (pix_colorB[s][i] * pix_coef_fond);
        }
        else {
          pix_buffer[s][i] = pix_colorB[s][i];
        }

  }//_Pix_mod 90


  if (_Pix_mod == 10) {

    ref_pix_pos = (_Pix_start + _Pix_pos);

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i)) {
          pix_coefi = (((_Pix_pos - ref_pix_pos) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
          pix_coef_fond = pix_coefi_fond / 100;
          ref_pix_pos--;

          pix_buffer[s][i] = (pix_colorA[s][i] * pix_coef) + (pix_colorB[s][i] * pix_coef_fond);
        }
        else {
          pix_buffer[s][i] = pix_colorB[s][i];
        }

  }//_Pix_mod 100


  if (_Pix_mod == 11) {

    ref_pix_pos = (_Pix_start + _Pix_pos);

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i)) {
          if (i <= _Pix_center) {
            pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
            pix_coef = pix_coefi * pix_coefi;
          }
          else if (i >= _Pix_center) {
            pix_coefi = ((((_Pix_pos - ref_pix_pos)) * 100) / _Pix_start_v) * 0.01;
            pix_coef = pix_coefi * pix_coefi;
            ref_pix_pos = ref_pix_pos - 2;
          }
          if (pix_coef > 1) pix_coef = 1;

          pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
          pix_coef_fond = pix_coefi_fond / 100;

          pix_buffer[s][i] = (pix_colorA[s][i] * pix_coef) + (pix_colorB[s][i] * pix_coef_fond);
        }
        else {
          pix_buffer[s][i] = pix_colorB[s][i];
        }

  }//_Pix_mod 110


  if (_Pix_mod == 12) {

    int s, p = 0;

    for (int i = 0 ; i < numberOfLed ; i++) {
      s = i / NUM_LEDS_PER_STRIP;
      p = i % NUM_LEDS_PER_STRIP;

      if (isActive(s, i)) {
        pix_coefi = (((i - _Pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        pix_buffer[s][p] = (pix_colorA[s][p] * pix_coef) + (pix_colorB[s][p] * pix_coef_fond);
      }
      else {
        pix_buffer[s][p] = pix_colorB[s][p];
      }
    }//for i

  }//_Pix_mod 120


  if (_Pix_mod == 13) {

    ref_pix_pos = (_Pix_start + _Pix_pos);
    int s, p = 0;

    for (int i = 0 ; i < numberOfLed ; i++) {
      s = i / NUM_LEDS_PER_STRIP;
      p = i % NUM_LEDS_PER_STRIP;

      if (isActive(s, i)) {
        pix_coefi = (((_Pix_pos - ref_pix_pos) * 100) / _Pix_start_v) * 0.01;
        pix_coef = pix_coefi * pix_coefi;
        ref_pix_pos--;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        pix_buffer[s][p] = (pix_colorA[s][p] * pix_coef) + (pix_colorB[s][p] * pix_coef_fond);
      }
      else {
        pix_buffer[s][p] = pix_colorB[s][p];
      }
    }//for i

  }//_Pix_mod 130


  if (_Pix_mod == 14) {

    ref_pix_pos = (_Pix_start + _Pix_pos);
    int s, p = 0;

    for (int i = 0 ; i < numberOfLed ; i++) {
      s = i / NUM_LEDS_PER_STRIP;
      p = i % NUM_LEDS_PER_STRIP;

      if (isActive(s, i)) {
        if (i <= _Pix_center) {
          pix_coefi = ((((i - _Pix_pos + 1)) * 200) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
        }
        else if (i >= _Pix_center) {
          pix_coefi = ((((_Pix_pos - ref_pix_pos)) * 100) / _Pix_start_v) * 0.01;
          pix_coef = pix_coefi * pix_coefi;
          ref_pix_pos = ref_pix_pos - 2;
        }
        if (pix_coef > 1) pix_coef = 1;

        pix_coefi_fond = map ((pix_coef * 100), 0, 100, 100, 0);
        pix_coef_fond = pix_coefi_fond / 100;

        pix_buffer[s][p] = (pix_colorA[s][p] * pix_coef) + (pix_colorB[s][p] * pix_coef_fond);
      }
      else {
        pix_buffer[s][p] = pix_colorB[s][p];
      }
    }//for i

  }//_Pix_mod 140

}// do_effet
