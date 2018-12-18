void do_effet_12() {
  if (pix_mod >= 0 && pix_mod <= 10) {
    for (int i = 0 ; i < NUM_LEDS_PER_STRIP ; i++) {
      if (i >= 0 && i < CYCLE) {
        r = ((1 * master) * rr) / 255;
        ggg = map(i, 0, CYCLE, 0, 255);
        g = (((ggg * ggg / 255 ) / 255 * master) * gg) / 255;
        b = 0;
      } else if (i >= CYCLE && i < CYCLE * 2) {
        rrr = map(i, CYCLE, CYCLE * 2, 255, 0);
        r = (((rrr * rrr / 255 ) / 255 * master) * rr) / 255;
        g = ((1 * master) * gg) / 255;
        b = 0;
      } else if (i >= CYCLE * 2 && i < CYCLE * 3) {
        r = 0;
        g = ((1 * master) * gg) / 255;
        bbb = map(i, CYCLE * 2, CYCLE * 3, 0, 255);
        b = (((bbb * bbb / 255) / 255 * master) * bb) / 255;
      } else if (i >= CYCLE * 3 && i < CYCLE * 4) {
        r = 0;
        ggg = map(i, CYCLE * 3, CYCLE * 4, 255, 0);
        g = ((( ggg * ggg / 255 ) / 255 * master) * gg) / 255;
        b = ((1 * master) * bb) / 255;
      } else if (i >= CYCLE * 4 && i < CYCLE * 5) {
        rrr = map(i, CYCLE * 4, CYCLE * 5, 0, 255);
        r = (((rrr * rrr / 255 ) / 255 * master) * rr) / 255;
        g = 0;
        b = ((1 * master) * bb) / 255;
      } else if (i >= CYCLE * 5 && i <= CYCLE * 6) {
        r = ((1 * master) * rr) / 255;
        g = 0;
        bbb = map(i, CYCLE * 5, CYCLE * 6, 255, 0);
        b = ((( bbb * bbb / 255 ) / 255 * master) * bb) / 255;
      }
      int ci = pix_pos + i;
      if (ci > NUM_LEDS_PER_STRIP) {
        ci = ci - NUM_LEDS_PER_STRIP;
      }
      strands[0]->pixels[ci] = pixelFromRGB(r, g, b);
      strands[1]->pixels[ci] = pixelFromRGB(r, g, b);
      strands[2]->pixels[ci] = pixelFromRGB(r, g, b);
      strands[3]->pixels[ci] = pixelFromRGB(r, g, b);
    }//for i
  }//pix_mod 0
}//do_effet_12()
