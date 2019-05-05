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
  Serial.print("pix_mod = ");
  Serial.println(pix_mod);
  Serial.print("pix_start = ");
  Serial.println(pix_start);
  Serial.print("pix_center = ");
  Serial.println(pix_center);
  Serial.print("pix_end = ");
  Serial.println(pix_end);
  Serial.print("pix_pos = ");
  Serial.println(pix_pos);
  Serial.print("modulo = ");
  Serial.println(modulo);
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
  pix_mod = data[adr + 4];
  pix_start = data[adr + 5] - 1;
  pix_pos_v = data[adr + 6];

  pix_end = pix_start + pix_start;
  if (pix_mod >= 11 && pix_mod <= 20 || pix_mod >= 31 && pix_mod <= 60 || pix_mod >= 91 && pix_mod <= 120) {
    pix_pos = (((pix_start + N_L_P_S + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
  } else if (pix_mod >= 21 && pix_mod <= 30 || pix_mod >= 61 && pix_mod <= 90 || pix_mod >= 121 && pix_mod <= 150) {
    pix_pos = (((pix_start + numberOfLed + pix_end) * data[adr + 6]) / 255) - (pix_end + 1);
  }
  modulo = data[adr + 7];
  str_ws = (data[adr + 8] * data[adr + 8]) / 33;
  pix_center = ((pix_start) / 2) + pix_pos;
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

  //  // modulo mode
  //  if ((modulo >= 0) && modulo <= 10) {
  //    type_modulo = 0;
  //  } else if ((modulo >= 11) && modulo <= 20) {
  //    type_modulo = 1;
  //  } else if ((modulo >= 21) && modulo <= 30) {
  //    type_modulo = 2;
  //  } else if ((modulo >= 31) && modulo <= 110) {
  //    Black();
  //    type_modulo = 3;
  //    S_seuil = (modulo - 30) * 4;
  //    //    type_effet = 255;
  //  } else if ((modulo >= 111) && modulo <= 120) {
  //    type_modulo = 4;
  //  } else if ((modulo >= 121) && modulo <= 200) {
  //    Black();
  //    type_modulo = 5;
  //    S_seuil = (modulo - 120) * 4;
  //    //    type_effet = 255;
  //  } else if ((modulo >= 201) && modulo <= 255) {
  //    type_modulo = 6;
  //    S_seuil = (modulo - 200) * 4;
  //    //    type_effet = 255;
  //  }

  // modulo mode && mirror
  if (mirror >= 0 && mirror <= 10) {
    N_L_P_S = (NUM_LEDS_PER_STRIP);
    if ((modulo >= 0) && modulo <= 10) {
      type_modulo = 0;
    } else if ((modulo >= 11) && modulo <= 20) {
      type_modulo = 1;
    } else if ((modulo >= 21) && modulo <= 30) {
      type_modulo = 2;
    } else if ((modulo >= 31) && modulo <= 110) {
      Black();
      type_modulo = 3;
      S_seuil = (modulo - 30) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 111) && modulo <= 120) {
      type_modulo = 4;
    } else if ((modulo >= 121) && modulo <= 200) {
      Black();
      type_modulo = 5;
      S_seuil = (modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 201) && modulo <= 255) {
      type_modulo = 6;
      S_seuil = (modulo - 200) * 4;
      //    type_effet = 255;
    }
  } else if (mirror >= 11 && mirror <= 20) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 2);
    if ((modulo >= 0) && modulo <= 10) {
      type_modulo = 10;
    } else if ((modulo >= 11) && modulo <= 20) {
      type_modulo = 11;
    } else if ((modulo >= 21) && modulo <= 30) {
      type_modulo = 12;
    } else if ((modulo >= 31) && modulo <= 110) {
      Black();
      type_modulo = 13;
      S_seuil = (modulo - 30) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 111) && modulo <= 120) {
      type_modulo = 14;
    } else if ((modulo >= 121) && modulo <= 200) {
      Black();
      type_modulo = 15;
      S_seuil = (modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 201) && modulo <= 255) {
      type_modulo = 16;
      S_seuil = (modulo - 200) * 4;
      //    type_effet = 255;
    }
  } else if (mirror >= 21 && mirror <= 30) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 3);
    if ((modulo >= 0) && modulo <= 10) {
      type_modulo = 20;
    } else if ((modulo >= 11) && modulo <= 20) {
      type_modulo = 21;
    } else if ((modulo >= 21) && modulo <= 30) {
      type_modulo = 22;
    } else if ((modulo >= 31) && modulo <= 110) {
      Black();
      type_modulo = 23;
      S_seuil = (modulo - 30) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 111) && modulo <= 120) {
      type_modulo = 24;
    } else if ((modulo >= 121) && modulo <= 200) {
      Black();
      type_modulo = 25;
      S_seuil = (modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 201) && modulo <= 255) {
      type_modulo = 26;
      S_seuil = (modulo - 200) * 4;
      //    type_effet = 255;
    }
  } else if (mirror >= 31 && mirror <= 40) {
    N_L_P_S = (NUM_LEDS_PER_STRIP / 4);
    if ((modulo >= 0) && modulo <= 10) {
      type_modulo = 30;
    } else if ((modulo >= 11) && modulo <= 20) {
      type_modulo = 31;
    } else if ((modulo >= 21) && modulo <= 30) {
      type_modulo = 32;
    } else if ((modulo >= 31) && modulo <= 110) {
      Black();
      type_modulo = 3;
      S_seuil = (modulo - 30) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 111) && modulo <= 120) {
      type_modulo = 34;
    } else if ((modulo >= 121) && modulo <= 200) {
      Black();
      type_modulo = 35;
      S_seuil = (modulo - 120) * 4;
      //    type_effet = 255;
    } else if ((modulo >= 201) && modulo <= 255) {
      type_modulo = 36;
      S_seuil = (modulo - 200) * 4;
      //    type_effet = 255;
    }
  }

  previousDataLength = length;

  if (sendFrame) {
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}//onframedmx
