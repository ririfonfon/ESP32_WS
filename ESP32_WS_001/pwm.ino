

void pwm_init() {
  /////////////////////////////////////////////////PWM setup
  ledcAttachPin(ledPina, ledChannela);
  ledcAttachPin(ledPinb, ledChannelb);
  ledcAttachPin(ledPinc, ledChannelc);
  ledcSetup(ledChannela, freq, resolution);
  ledcSetup(ledChannelb, freq, resolution);
  ledcSetup(ledChannelc, freq, resolution);
}

