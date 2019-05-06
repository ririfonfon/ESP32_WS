//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// onDmxFrame //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data) {
  boolean tail = false;

#ifdef DEBUG_dmx
  Serial.print("_Master = ");
  Serial.println(_Master);
  Serial.print("r = ");
  Serial.println(data[adr + 0]);
  Serial.print("g = ");
  Serial.println(data[adr + 1]);
  Serial.print("b = ");
  Serial.println(data[adr + 2]);
  Serial.print("_Fx_mod = ");
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

  _Master = data[adr - 1];

  //  rr = (data[adr] * data[adr]) / 255;
  //  gg = (data[adr + 1] * data[adr + 1]) / 255;
  //  bb = (data[adr + 2] * data[adr + 2]) / 255;
  _Color = pixelFromRGB( linear(data[adr + 0]), linear(data[adr + 1]), linear(data[adr + 2]));

  _Fx_mod = abs(data[adr + 3] - 1) / 10;              // (0 -> 10) = 0  //  (11 -> 20) = 1  // ...

  //  _Pix_mod = data[adr + 4];
  _Pix_mod = abs(data[adr + 4] - 1) / 10;         // (0 -> 10) = 0  //  (11 -> 20) = 1  // ...

  _Pix_start = data[adr + 5] - 1;

  _Pix_pos_v = data[adr + 6];

  _Pix_end = _Pix_start + _Pix_start;

  if ( is_in(_Pix_mod, {1, 3, 4, 5, 9, 10, 11}) )
    _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);
  else if ( is_in(_Pix_mod, {2, 6, 7, 8, 12, 13, 14}) )
    _Pix_pos = (((_Pix_start + numberOfLed + _Pix_end) * _Pix_pos_v) / 255) - (_Pix_end + 1);

  _Modulo = data[adr + 7];
  _Strobe_ws = (data[adr + 8] * data[adr + 8]) / 33;
  _Pix_center = ((_Pix_start) / 2) + _Pix_pos;
  //  MG = (NUM_LEDS_PER_STRIP + 1) / NUM_STRIPS;
  //  srr = (data[adr + 9] * data[adr + 9]) / 255;
  //  sgg = (data[adr + 10] * data[adr + 10]) / 255;
  //  sbb = (data[adr + 11] * data[adr + 11]) / 255;
  _Color2 = pixelFromRGB( linear(data[adr + 9]), linear(data[adr + 10]), linear(data[adr + 11]));
  _Color_mode = data[adr + 12];
  _Mirror = data[adr + 13];

  // FX 0 -> 10
  if ( _Fx_mod <= 10 ) _Fx_type = _Fx_mod;    // (0 -> 10) = 0  //  (11 -> 20) = 1  // ...

  // 0 fix,1 rudan 1,2 rudan 2,3rudan 3,4 rudan 4,5 rudan 12,6 rudan 13,7 rudan 14,8 rudan 23,9 rudan 24,10 rudan 34

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


  // _Modulo mode && _Mirror
  if (_Mirror >= 0 && _Mirror <= 10) {
    N_L_P_S = (NUM_LEDS_PER_STRIP);
    if ((_Modulo >= 0) && _Modulo <= 10) {
      type__Modulo = 0;
    } else if ((_Modulo >= 11) && _Modulo <= 20) {
      type__Modulo = 1;
    } else if ((_Modulo >= 21) && _Modulo <= 30) {
      type__Modulo = 2;
    } else if ((_Modulo >= 31) && _Modulo <= 110) {
      Black();
      type__Modulo = 3;
      S_seuil = (_Modulo - 30) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 4;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 5;
      S_seuil = (_Modulo - 120) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 6;
      S_seuil = (_Modulo - 200) * 4;
      //    _Fx_type = 255;
    }
  } else if (_Mirror >= 11 && _Mirror <= 20) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 2);
    if ((_Modulo >= 0) && _Modulo <= 10) {
      type__Modulo = 10;
    } else if ((_Modulo >= 11) && _Modulo <= 20) {
      type__Modulo = 11;
    } else if ((_Modulo >= 21) && _Modulo <= 30) {
      type__Modulo = 12;
    } else if ((_Modulo >= 31) && _Modulo <= 110) {
      Black();
      type__Modulo = 13;
      S_seuil = (_Modulo - 30) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 14;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 15;
      S_seuil = (_Modulo - 120) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 16;
      S_seuil = (_Modulo - 200) * 4;
      //    _Fx_type = 255;
    }
  } else if (_Mirror >= 21 && _Mirror <= 30) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 3);
    if ((_Modulo >= 0) && _Modulo <= 10) {
      type__Modulo = 20;
    } else if ((_Modulo >= 11) && _Modulo <= 20) {
      type__Modulo = 21;
    } else if ((_Modulo >= 21) && _Modulo <= 30) {
      type__Modulo = 22;
    } else if ((_Modulo >= 31) && _Modulo <= 110) {
      Black();
      type__Modulo = 23;
      S_seuil = (_Modulo - 30) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 24;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 25;
      S_seuil = (_Modulo - 120) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 26;
      S_seuil = (_Modulo - 200) * 4;
      //    _Fx_type = 255;
    }
  } else if (_Mirror >= 31 && _Mirror <= 40) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 4);
    if ((_Modulo >= 0) && _Modulo <= 10) {
      type__Modulo = 30;
    } else if ((_Modulo >= 11) && _Modulo <= 20) {
      type__Modulo = 31;
    } else if ((_Modulo >= 21) && _Modulo <= 30) {
      type__Modulo = 32;
    } else if ((_Modulo >= 31) && _Modulo <= 110) {
      Black();
      type__Modulo = 3;
      S_seuil = (_Modulo - 30) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 34;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 35;
      S_seuil = (_Modulo - 120) * 4;
      //    _Fx_type = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 36;
      S_seuil = (_Modulo - 200) * 4;
      //    _Fx_type = 255;
    }
  }

  previousDataLength = length;

  if (sendFrame) {
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}//onframedmx
