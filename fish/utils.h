CRGB fade(CRGB color, float value, float target, float threshold = 30) {
  if (value < target - threshold || value > target + threshold) {
    return CRGB::Black;
  }
  float dist = abs(target - value);
  return color.nscale8(map(dist, 0, threshold, 255, 0));
}

float distance(float x1, float y1, float x2, float y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
