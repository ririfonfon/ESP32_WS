void effet() {
  if (_Fx_type == 0)
    //    do_effet_0();
    do_effet();
  else if (_Fx_type == 1)
    do_effet_1();
  else if (_Fx_type == 2)
    do_effet_2();
  else if (_Fx_type == 3)
    do_effet_3();
  else if (_Fx_type == 4)
    do_effet_4();
  else if (_Fx_type == 5)
    do_effet_5();
  else if (_Fx_type == 6)
    do_effet_6();
  else if (_Fx_type == 7)
    do_effet_7();
  else if (_Fx_type == 8)
    do_effet_8();
  else if (_Fx_type == 9)
    do_effet_9();
  else if (_Fx_type == 10)
    do_effet_10();
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

  // check if i is in range
  if (_Fx_type == 0) return true;
  else if (_Fx_type <= 10) return (i >= (_Pix_pos) && i <= _Pix_start + (_Pix_pos));
  else if (_Fx_type == 11) return (i >= M_g[strip][0] && i <= M_g[strip][1]);

  return true;
}


int ref_pix_pos;

void do_effet() {

  if (_Pix_mod == 0) {
    for (int s = 0 ; s < NUM_STRIPS ; s++)
      for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++)
        if (isActive(s, i))
          pix_buffer[s][i] = pix_colorA[s][i];
        else
          pix_buffer[s][i] = pix_colorB[s][i];

  }//_Pix_mod 0
}
