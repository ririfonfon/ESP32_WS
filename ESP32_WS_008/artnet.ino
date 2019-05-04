
///////////////////////////////////// Artnet settings /////////////////////////////////////
//const int startUniverse = 0; // CHANGE FOR YOUR SETUP most software this is 1, some software send out artnet first universe as 0.
const int startUniverse = NOEUX; // CHANGE FOR NOEUX.

// Check if we got all universes
const int maxUniverses = numberOfChannels / 512 + ((numberOfChannels % 512) ? 1 : 0);
bool universesReceived[maxUniverses];
bool sendFrame = 1;
int previousDataLength = 0;


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// onDmxFrame //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data) {

#ifdef DEBUG_dmx
  Serial.print("master = ");
  Serial.println(_Master);

  Serial.print("r = ");
  Serial.println(data[adr + 0]);
  Serial.print("g = ");
  Serial.println(data[adr + 1]);
  Serial.print("b = ");
  Serial.println(data[adr + 2]);

  Serial.print("mod = ");
  Serial.println(_Fx_mod);
  Serial.print("_Pix_mod = ");
  Serial.println(_Pix_mod);
  Serial.print("_Pix_start = ");
  Serial.println(_Pix_start);
  Serial.print("_Pix_center = ");
  Serial.println(_Pix_center);
  Serial.print("_Pix_end = ");
  Serial.println(_Pix_end);
  Serial.print("_Pix_pos = ");
  Serial.println(_Pix_pos);
  Serial.print("_Modulo = ");
  Serial.println(_Modulo);
  Serial.print("_Strobe_ws = ");
  Serial.println(_Strobe_ws);

#endif

  // DMX variables
  //
  _Master = data[adr - 1];
  _Color = pixelFromRGB( linear(data[adr + 0]), linear(data[adr + 1]), linear(data[adr + 2]));

  _Fx_mod = abs(data[adr + 3] - 1) / 10;              // (0 -> 10) = 0  //  (11 -> 20) = 1  // ...
  _Pix_mod = abs(data[adr + 4] - 1) / 10;         // (0 -> 10) = 0  //  (11 -> 20) = 1  // ...
  _Pix_start = data[adr + 5] - 1;
  _Pix_pos_v = data[adr + 6];

  _Modulo = data[adr + 7];
  _Strobe_ws = (data[adr + 8] * data[adr + 8]) / 33;

  _Color2 = pixelFromRGB( linear(data[adr + 9]), linear(data[adr + 10]), linear(data[adr + 11]));
  _Color_mode = abs(data[adr + 12] - 1) / 10;     // (0 -> 10) = 0  //  (11 -> 20) = 1  // ...

  _Mirror = abs(data[adr + 13] - 1) / 10 + 1;     // (0 -> 10) = 1  //  (11 -> 20) = 2  // ...


  // DMX derivatives:pix position
  //
  N_L_P_S = NUM_LEDS_PER_STRIP / _Mirror;             // Virtual size of strip with Mirror effect

  _Pix_start_v = (_Pix_start < 1) ? 1 : _Pix_start;
  _Pix_end = _Pix_start * 2;

  if ( is_in(_Pix_mod, {1, 3, 4, 5, 9, 10, 11}) )
    _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
  else if ( is_in(_Pix_mod, {2, 6, 7, 8, 12, 13, 14}) )
    _Pix_pos = (((_Pix_start + NUM_LEDS_TOTAL + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);

  _Pix_center = ((_Pix_start) / 2) + _Pix_pos;

  // if (_Pix_mod >= 11 && _Pix_mod <= 20 || _Pix_mod >= 31 && _Pix_mod <= 60 || _Pix_mod >= 91 && _Pix_mod <= 120) {
  //   _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
  // } else if (_Pix_mod >= 21 && _Pix_mod <= 30 || _Pix_mod >= 61 && _Pix_mod <= 90 || _Pix_mod >= 121 && _Pix_mod <= 150) {
  //   _Pix_pos = (((_Pix_start + NUM_LEDS_TOTAL + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
  // }

  // FX 0 -> 10
  if ( _Fx_mod <= 10 ) _Fx_type = _Fx_mod;    // (0 -> 10) = 0  //  (11 -> 20) = 1  // ...

  // FX 11
  else if (_Fx_mod == 12) {
    _Fx_type  = 11;
    M_g[0][0] = 0;
    M_g[0][1] = MG;
    M_g[1][0] = MG;
    M_g[1][1] = MG * 2;
    M_g[2][0] = MG * 2;
    M_g[2][1] = MG * 3;
    M_g[3][0] = MG * 3;
    M_g[3][1] = MG * 4;
  }//rudan 1/4
  else if (_Fx_mod == 13) {
    _Fx_type  = 11;
    M_g[0][0] = MG * 3;
    M_g[0][1] = MG * 4;
    M_g[1][0] = 0;
    M_g[1][1] = MG;
    M_g[2][0] = MG;
    M_g[2][1] = MG * 2;
    M_g[3][0] = MG * 2;
    M_g[3][1] = MG * 3;
  }//rudan 2/4
  else if (_Fx_mod == 14) {
    _Fx_type  = 11;
    M_g[0][0] = MG * 2;
    M_g[0][1] = MG * 3;
    M_g[1][0] = MG * 3;
    M_g[1][1] = MG * 4;
    M_g[2][0] = 0;
    M_g[2][1] = MG;
    M_g[3][0] = MG;
    M_g[3][1] = MG * 2;
  }//rudan 3/4
  else if (_Fx_mod == 15) {
    _Fx_type  = 11;
    M_g[0][0] = MG;
    M_g[0][1] = MG * 2;
    M_g[1][0] = MG * 2;
    M_g[1][1] = MG * 3;
    M_g[2][0] = MG * 3;
    M_g[2][1] = MG * 4;
    M_g[3][0] = 0;
    M_g[3][1] = MG;
  }//rudan 4/4


  // _Modulo
  if ((_Modulo >= 0) && _Modulo <= 10)
    _Modulo_type = 0;

  else if ((_Modulo >= 11) && _Modulo <= 20)
    _Modulo_type = 1;

  else if ((_Modulo >= 21) && _Modulo <= 30)
    _Modulo_type = 2;

  else if ((_Modulo >= 31) && _Modulo <= 110) {
    black();
    _Modulo_type = 3;
    S_seuil = (_Modulo - 30) * 4;
    //    _Fx_type = 255;
  }

  else if ((_Modulo >= 111) && _Modulo <= 120)
    _Modulo_type = 4;

  else if ((_Modulo >= 121) && _Modulo <= 200) {
    black();
    _Modulo_type = 5;
    S_seuil = (_Modulo - 120) * 4;
    //    _Fx_type = 255;
  }
  else if ((_Modulo >= 201) && _Modulo <= 255) {
    _Modulo_type = 6;
    S_seuil = (_Modulo - 200) * 4;
    //    _Fx_type = 255;
  }


  previousDataLength = length;

  if (sendFrame) {
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}//onframedmx
