
////////////////// FX THREAD


void fx_task( void * pvParameters ) {
#ifdef DEBUG
  Serial.println("fx_task()");
#endif


  while (true) {

    if (_Fx_type <= 11) do_effet();
    else delay(1);

    leds_show();
    yield(); // rend la main
  }

  vTaskDelete(NULL);
}// fx_task( void * pvParameters )


////////////////// FX CONFIG

// Indicate which strip is active (true) or background (false)
// for each "_Fx_type"
//
bool activeStrip[12][NUM_STRIPS] = {
  {true, true, true, true},     // _Fx_type = 0
  {true, false, false, false},  // _Fx_type = 1
  {false, true, false, false},  // _Fx_type = 2
  {false, false, true, false},  // _Fx_type = 3
  {false, false, false, true},  // _Fx_type = 4
  {true, true, false, false},   // _Fx_type = 5
  {true, false, true, false},   // _Fx_type = 6
  {true, false, false, true},   // _Fx_type = 7
  {false, true, true, false},   // _Fx_type = 8
  {false, true, false, true},   // _Fx_type = 9
  {false, false, true, true},   // _Fx_type = 10
  {true, true, true, true}      // _Fx_type = 11
};

// Decide if pixel is active or is background
//
bool isActive(int strip, int i) {

  // check if strip is active for this "_Fx_type"
  if (_Fx_type <= 11 && !activeStrip[_Fx_type][strip]) return false;

  // check if i is in range
  if (_Fx_type == 0) return true;
  else if (_Fx_type <= 10) return (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos));
  else if (_Fx_type == 11) return (i >= M_g[strip][0] && i <= M_g[strip][1]);

  return true;
}


int ref_pix_pos;
float pix_coef;
float pix_coefi;
float pix_coef_fond;
float pix_coefi_fond;


////////////////////  FX FUNTION

void do_effet() {

  if (_Pix_mod == 0) {

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i))
          pix_buffer[s][i] = pix_colorA[s][i];
        else
          pix_buffer[s][i] = pix_colorB[s][i];

  }//_Pix_mod 0


  if (_Pix_mod == 1) {

    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i))
          pix_buffer[s][i] = pix_colorA[s][i];
        else
          pix_buffer[s][i] = pix_colorB[s][i];

  }//_Pix_mod 10


  if (_Pix_mod == 2) {

    int s, p = 0;

    for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
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

    for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
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

    for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
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

    for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
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

    for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
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

    for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
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

    ref_pix_pos = (_Pix_start + _Pix_pos); int s, p = 0;

    for (int i = 0 ; i < NUM_LEDS_TOTAL ; i++) {
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
