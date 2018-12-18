void effet() {
  if (type_effet == 0)
    do_effet_0();
  else if (type_effet == 1)
    do_effet_1();
  else if (type_effet == 2)
    do_effet_2();
  else if (type_effet == 3)
    do_effet_3();
  else if (type_effet == 4)
    do_effet_4();
  else if (type_effet == 5)
    do_effet_5();
  else if (type_effet == 6)
    do_effet_6();
  else if (type_effet == 7)
    do_effet_7();
  else if (type_effet == 8)
    do_effet_8();
  else if (type_effet == 9)
    do_effet_9();
  else if (type_effet == 10)
    do_effet_10();
  else if (type_effet == 11)
    do_effet_11();
  else if (type_effet == 12)
    do_effet_12();
  else if (type_effet == 255)
    do_effet_255();

  leds_show();
}//effet
