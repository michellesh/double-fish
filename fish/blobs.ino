struct Blob {
  float radius;
  float x;
  float y;
  float xspeed;
  float yspeed;

  void update() {
    x += xspeed;
    y += yspeed;
    if (x > X_MAX || x < X_MIN)
      xspeed *= -1;
    if (y > Y_MAX || y < Y_MIN)
      yspeed *= -1;
  }
};

Blob blob = {15, 100, 100, 0.4, 0.8};

void showBlobs() {
  float sum = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    float diff = distance(leftX[i], leftY[i], blob.x, blob.y);
    leftLEDs[i] = fade(CRGB::White, diff, blob.radius);
  }

  blob.update();
}
