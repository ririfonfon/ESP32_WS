//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// onDmxFrame //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data) {
  boolean tail = false;

#ifdef DEBUG_dmx
  Serial.print("_Master = ");
  Serial.println(_Master);
  Serial.print("r = ");
  Serial.println(rr);
  Serial.print("g = ");
  Serial.println(gg);
  Serial.print("b = ");
  Serial.println(bb);
  Serial.print("mod = ");
  Serial.println(mod);
  Serial.print("_Pix_mod = ");
  Serial.println(_Pix_mod);
  Serial.print("_Pix_start = ");
  Serial.println(_Pix_start);
  Serial.print("pix_center = ");
  Serial.println(pix_center);
  Serial.print("_Pix_end = ");
  Serial.println(_Pix_end);
  Serial.print("_Pix_pos = ");
  Serial.println(_Pix_pos);
  Serial.print("_Modulo = ");
  Serial.println(_Modulo);
  Serial.print("str_ws = ");
  Serial.println(str_ws);
  Serial.print("M_g = ");
  Serial.println(M_g);
#endif

  _Master = data[adr - 1];

  rr = (data[adr] * data[adr]) / 255;
  gg = (data[adr + 1] * data[adr + 1]) / 255;
  bb = (data[adr + 2] * data[adr + 2]) / 255;

  mod = data[adr + 3];

  _Pix_mod = data[adr + 4];

  _Pix_start = data[adr + 5] - 1;

  _Pix_pos_v = data[adr + 6];

  _Pix_end = _Pix_start + _Pix_start;
  if (_Pix_mod >= 11 && _Pix_mod <= 20 || _Pix_mod >= 31 && _Pix_mod <= 60 || _Pix_mod >= 91 && _Pix_mod <= 120) {
    _Pix_pos = (((_Pix_start + N_L_P_S + _Pix_end) * data[adr + 6]) / 255) - (_Pix_end + 1);
  } else if (_Pix_mod >= 21 && _Pix_mod <= 30 || _Pix_mod >= 61 && _Pix_mod <= 90 || _Pix_mod >= 121 && _Pix_mod <= 150) {
    _Pix_pos = (((_Pix_start + numberOfLed + _Pix_end) * data[adr + 6]) / 255) - (_Pix_end + 1);
  }
  _Modulo = data[adr + 7];
  str_ws = (data[adr + 8] * data[adr + 8]) / 33;
  pix_center = ((_Pix_start) / 2) + _Pix_pos;
  M_g = (NUM_LEDS_PER_STRIP + 1) / NUM_STRIPS;
  srr = (data[adr + 9] * data[adr + 9]) / 255;
  sgg = (data[adr + 10] * data[adr + 10]) / 255;
  sbb = (data[adr + 11] * data[adr + 11]) / 255;
  color_mode = data[adr + 12];
  mirror = data[adr + 13];

  //  // mirror mode
  //  if (mirror >= 0 && mirror <= 10) {
  //    N_L_P_S = (NUM_LEDS_PER_STRIP);
  //  } else if (mirror >= 11 && mirror <= 20) {
  //    N_L_P_S = (NUM_LEDS_PER_STRIP / 2);
  //  } else if (mirror >= 21 && mirror <= 30) {
  //    N_L_P_S = (NUM_LEDS_PER_STRIP / 3);
  //  } else if (mirror >= 31 && mirror <= 40) {
  //    N_L_P_S = (NUM_LEDS_PER_STRIP / 4);
  //  }



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

  //  // _Modulo mode
  //  if ((_Modulo >= 0) && _Modulo <= 10) {
  //    type__Modulo = 0;
  //  } else if ((_Modulo >= 11) && _Modulo <= 20) {
  //    type__Modulo = 1;
  //  } else if ((_Modulo >= 21) && _Modulo <= 30) {
  //    type__Modulo = 2;
  //  } else if ((_Modulo >= 31) && _Modulo <= 110) {
  //    Black();
  //    type__Modulo = 3;
  //    S_seuil = (_Modulo - 30) * 4;
  //    //    type_effet = 255;
  //  } else if ((_Modulo >= 111) && _Modulo <= 120) {
  //    type__Modulo = 4;
  //  } else if ((_Modulo >= 121) && _Modulo <= 200) {
  //    Black();
  //    type__Modulo = 5;
  //    S_seuil = (_Modulo - 120) * 4;
  //    //    type_effet = 255;
  //  } else if ((_Modulo >= 201) && _Modulo <= 255) {
  //    type__Modulo = 6;
  //    S_seuil = (_Modulo - 200) * 4;
  //    //    type_effet = 255;
  //  }

  // _Modulo mode && mirror
  if (mirror >= 0 && mirror <= 10) {
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
      //    type_effet = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 4;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 5;
      S_seuil = (_Modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 6;
      S_seuil = (_Modulo - 200) * 4;
      //    type_effet = 255;
    }
  } else if (mirror >= 11 && mirror <= 20) {
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
      //    type_effet = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 14;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 15;
      S_seuil = (_Modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 16;
      S_seuil = (_Modulo - 200) * 4;
      //    type_effet = 255;
    }
  } else if (mirror >= 21 && mirror <= 30) {
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
      //    type_effet = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 24;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 25;
      S_seuil = (_Modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 26;
      S_seuil = (_Modulo - 200) * 4;
      //    type_effet = 255;
    }
  } else if (mirror >= 31 && mirror <= 40) {
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
      //    type_effet = 255;
    } else if ((_Modulo >= 111) && _Modulo <= 120) {
      type__Modulo = 34;
    } else if ((_Modulo >= 121) && _Modulo <= 200) {
      Black();
      type__Modulo = 35;
      S_seuil = (_Modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((_Modulo >= 201) && _Modulo <= 255) {
      type__Modulo = 36;
      S_seuil = (_Modulo - 200) * 4;
      //    type_effet = 255;
    }
  }

  previousDataLength = length;

  if (sendFrame) {
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}//onframedmx
