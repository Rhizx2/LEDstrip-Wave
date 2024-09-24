#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       50  // Speed of the explosion effect

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  int center = random(NUM_LEDS);  // Random explosion center
  int colorHue = random(255);     // Random color hue
  
  // Explosion effect
  for (int radius = 0; radius < NUM_LEDS / 2; radius++) {
    leds[(center + radius) % NUM_LEDS] = CHSV(colorHue, 255, 255);  // Bright color outward
    leds[(center - radius + NUM_LEDS) % NUM_LEDS] = CHSV(colorHue, 255, 255);
    FastLED.show();
    delay(SPEED);
    
    // Fade the previous LED
    leds[(center + radius) % NUM_LEDS].fadeToBlackBy(40);
    leds[(center - radius + NUM_LEDS) % NUM_LEDS].fadeToBlackBy(40);
  }
}
