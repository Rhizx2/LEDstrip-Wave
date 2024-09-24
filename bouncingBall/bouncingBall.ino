#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define BALL_SIZE   5
#define SPEED       20  // Speed of the bouncing ball

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  static int ballPosition = 0;
  static int direction = 1;  // 1 means moving right, -1 means moving left

  // Fade all LEDs slightly to simulate a trail
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(50);
  }

  // Draw the ball
  for (int i = 0; i < BALL_SIZE; i++) {
    leds[(ballPosition + i) % NUM_LEDS] = CRGB::Blue;
  }

  FastLED.show();
  
  // Update the ball position
  ballPosition += direction;

  // Reverse direction at the ends
  if (ballPosition <= 0 || ballPosition >= (NUM_LEDS - BALL_SIZE)) {
    direction *= -1;
  }

  delay(SPEED);
}
