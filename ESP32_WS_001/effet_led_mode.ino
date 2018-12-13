void effet_led_mode() {
  if ((led_mode >= 0) && (led_mode <= 10)) {
    led_a = led_master;
    led_b = led_master;
    led_c = led_master;
  }//ALL
  else if ((led_mode >= 11) && (led_mode <= 20)) {
    led_a = led_master;
    led_b = 0;
    led_c = 0;
  }//1
  else if ((led_mode >= 21) && (led_mode <= 30)) {
    led_a = 0;
    led_b = led_master;
    led_c = 0;
  }//2
  else if ((led_mode >= 31) && (led_mode <= 40)) {
    led_a = 0;
    led_b = 0;
    led_c = led_master;
  }//3
  else if ((led_mode >= 41) && (led_mode <= 50)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_now_l - t_last_l > led_str) {
      t_last_l = t_now_l;
      str_l = 1;
    } else if (str_l == 1 && t_now_l - t_last_l > STROB_ON_MS_L) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = str_l * led_master ;
    led_b = str_l * led_master ;
    led_c = str_l * led_master ;
  }//ALL Str
  else if ((led_mode >= 51) && (led_mode <= 60)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_now_l - t_last_l > led_str) {
      t_last_l = t_now_l;
      str_l = 1;
    } else if (str_l == 1 && t_now_l - t_last_l > STROB_ON_MS_L) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = str_l * led_master ;
    led_b = 0 ;
    led_c = 0 ;
  }//1 Str
  else if ((led_mode >= 61) && (led_mode <= 70)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_now_l - t_last_l > led_str) {
      t_last_l = t_now_l;
      str_l = 1;
    } else if (str_l == 1 && t_now_l - t_last_l > STROB_ON_MS_L) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = 0 ;
    led_b = str_l * led_master ;
    led_c = 0 ;
  }//2 Str
  else if ((led_mode >= 71) && (led_mode <= 80)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_now_l - t_last_l > led_str) {
      t_last_l = t_now_l;
      // ALLUMER LED
      str_l = 1;
    } else if (str_l == 1 && t_now_l - t_last_l > STROB_ON_MS_L) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = 0 ;
    led_b = 0 ;
    led_c = str_l * led_master ;
  }//3 Str
  else if ((led_mode >= 81) && (led_mode <= 90)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_now_l - t_last_l > led_str) {
      t_last_l = t_now_l;
      str_l = 1;
    } else if (str_l == 1 && t_now_l - t_last_l > STROB_ON_MS_L) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    if (l_s_count == 1) {
      led_a = str_l * led_master ;
      led_b = 0 ;
      led_c = 0 ;
    } else if (l_s_count == 2) {
      led_a = 0 ;
      led_b = str_l * led_master ;
      led_c = 0 ;
    } else if (l_s_count == 3) {
      led_a = 0 ;
      led_b = 0 ;
      led_c = str_l * led_master ;
    }
    l_s_count = l_s_count + 1;
    if (l_s_count > 3) l_s_count = 1;
  }//123 Str
  else if ((led_mode >= 91) && (led_mode <= 100)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_last_l < t_now_l && t_now_l - t_last_l > led_str / (str_blind_l * str_blind_l)) {
      t_last_l = t_now_l;
      str_l = 1;
      str_blind_l = str_blind_l + 0.05;
      if (str_blind_l >= 3) {
        str_blind_l = 1;
        // Noir pendant 1 sec (dans le futur)
        str_l = 0;
        t_last_l = t_now_l + 1000;
      }
    } else if (str_l == 1 && t_last_l < t_now_l && t_now_l - t_last_l > (STROB_ON_MS_L)) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = str_l * led_master ;
    led_b = str_l * led_master ;
    led_c = str_l * led_master ;
  }//ALL Blink Str
  else if ((led_mode >= 101) && (led_mode <= 110)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_last_l < t_now_l && t_now_l - t_last_l > led_str / (str_blind_l * str_blind_l)) {
      t_last_l = t_now_l;
      str_l = 1;
      str_blind_l = str_blind_l + 0.05;
      if (str_blind_l >= 3) {
        str_blind_l = 1;
        // Noir pendant 1 sec (dans le futur)
        str_l = 0;
        t_last_l = t_now_l + 1000;
      }
    } else if (str_l == 1 && t_last_l < t_now_l && t_now_l - t_last_l > (STROB_ON_MS_L)) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = str_l * led_master ;
    led_b = 0 ;
    led_c = 0 ;
  }//1 Blink Str
  else if ((led_mode >= 111) && (led_mode <= 120)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_last_l < t_now_l && t_now_l - t_last_l > led_str / (str_blind_l * str_blind_l)) {
      t_last_l = t_now_l;
      str_l = 1;
      str_blind_l = str_blind_l + 0.05;
      if (str_blind_l >= 3) {
        str_blind_l = 1;
        // Noir pendant 1 sec (dans le futur)
        str_l = 0;
        t_last_l = t_now_l + 1000;
      }
    } else if (str_l == 1 && t_last_l < t_now_l && t_now_l - t_last_l > (STROB_ON_MS_L)) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = 0 ;
    led_b = str_l * led_master ;
    led_c = 0 ;
  }//2 Blink Str
  else if ((led_mode >= 121) && (led_mode <= 130)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_last_l < t_now_l && t_now_l - t_last_l > led_str / (str_blind_l * str_blind_l)) {
      t_last_l = t_now_l;
      str_l = 1;
      str_blind_l = str_blind_l + 0.05;
      if (str_blind_l >= 3) {
        str_blind_l = 1;
        // Noir pendant 1 sec (dans le futur)
        str_l = 0;
        t_last_l = t_now_l + 1000;
      }
    } else if (str_l == 1 && t_last_l < t_now_l && t_now_l - t_last_l > (STROB_ON_MS_L)) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    led_a = 0 ;
    led_b = 0 ;
    led_c = str_l * led_master ;
  }//3 Blink Str
  else if ((led_mode >= 131) && (led_mode <= 140)) {
    unsigned long t_now_l = millis();
    if (str_l == 0 && t_last_l < t_now_l && t_now_l - t_last_l > led_str / (str_blind_l * str_blind_l)) {
      t_last_l = t_now_l;
      str_l = 1;
      str_blind_l = str_blind_l + 0.05;
      if (str_blind_l >= 3) {
        str_blind_l = 1;
        // Noir pendant 1 sec (dans le futur)
        str_l = 0;
        t_last_l = t_now_l + 1000;
      }
    } else if (str_l == 1 && t_last_l < t_now_l && t_now_l - t_last_l > (STROB_ON_MS_L)) {
      t_last_l = t_now_l;
      str_l = 0;
    } else {
      return;
    }
    if (l_s_count == 1) {
      led_a = str_l * led_master ;
      led_b = 0 ;
      led_c = 0 ;
    } else if (l_s_count == 2) {
      led_a = 0 ;
      led_b = str_l * led_master ;
      led_c = 0 ;
    } else if (l_s_count == 3) {
      led_a = 0 ;
      led_b = 0 ;
      led_c = str_l * led_master ;
    }
    l_s_count = l_s_count + 1;
    if (l_s_count > 3) l_s_count = 1;
  }//123 Blink Str
}//effet_led_mode

