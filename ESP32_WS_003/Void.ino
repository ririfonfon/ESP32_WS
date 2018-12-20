void Black() {
  for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
    strands[0]->pixels[i] = pixelFromRGB(0, 0, 0);
    strands[1]->pixels[i] = pixelFromRGB(0, 0, 0);
  }//for i
}

