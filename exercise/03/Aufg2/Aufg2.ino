#include <LiquidCrystal.h>

#define INTERRUPT_PIN 2

#define LCD_COLS 16
#define LCD_ROWS 2

#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 7

#define STATE_DISPLAY 1
#define STATE_RUNNING 2

volatile int state = STATE_RUNNING;
volatile int test;
unsigned long start;
unsigned long end_time;


LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(INTERRUPT_PIN, INPUT_PULLUP);
    state = STATE_DISPLAY;
    
    lcd.begin(LCD_COLS, LCD_ROWS);

    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), onInterrupt, RISING);
}

// the loop function runs over and over again forever
void loop() {
    unsigned int diff;
    lcd.setCursor(0, 0); 
    if (state == STATE_RUNNING) {
      unsigned int now = millis(); 
      diff = now - start;
    } else { 
        diff = end_time - start;
    }


    lcd.print(diff);   

}

void onInterrupt() {
    lcd.clear();
    if (state == STATE_DISPLAY) {
        onStart();
    } else {
        onStop();
    }
}

void onStop() {
    state = STATE_DISPLAY;
    end_time = millis();
}

void onStart() {
    state = STATE_RUNNING;
    start = millis();
    end_time = 0;
}
