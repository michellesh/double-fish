#define NUM_BLOBS 10
#define BLOB_FADE_WIDTH 20 // how far past the radius to fade

struct Blob {
  float radius;
  float x;
  float y;
  float xSpeed;
  float ySpeed;

  void update() {
    x += xSpeed;
    y += ySpeed;
    if (x > X_MAX + radius + BLOB_FADE_WIDTH ||
        x < X_MIN - radius - BLOB_FADE_WIDTH)
      xSpeed *= -1;
    if (y > Y_MAX + radius + BLOB_FADE_WIDTH ||
        y < Y_MIN - radius - BLOB_FADE_WIDTH)
      ySpeed *= -1;
  }
};

Blob blobs[NUM_BLOBS];

void setupBlobs() {
  for (int i = 0; i < NUM_BLOBS; i++) {
    float radius = random(30, 100);
    float x = random(X_MIN, X_MAX);
    float y = random(Y_MIN, Y_MAX);
    float xSpeed = float(random(1, 6)) / 10;
    float ySpeed = float(random(1, 10)) / 10;
    blobs[i] = {radius, x, y, xSpeed, ySpeed};
  }
}

void showBlobs() {
  for (int i = 0; i < NUM_LEDS; i++) {
    int brightness = 0;
    for (int j = 0; j < NUM_BLOBS; j++) {
      float d = distance(ledX[i], ledY[i], blobs[j].x, blobs[j].y);
      int b = fadeBrightness(d, blobs[j].radius, BLOB_FADE_WIDTH);
      if (b > brightness) {
        //leds[i] = palette.mapToColor(j, 0, NUM_BLOBS).nscale8(b);
        leds[i] = palette.getColor(i).nscale8(b);
        brightness = b;
      }
    }
  }

  for (int i = 0; i < NUM_BLOBS; i++) {
    blobs[i].update();
  }
}
