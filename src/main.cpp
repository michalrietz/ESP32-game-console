#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BTN_A 13
#define BTN_B 14
#define BTN_START 27
#define BTN_SELECT 26
#define JOY_X 32 
#define JOY_Y 33 

void setup() {
  Serial.begin(115200);
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_START, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Brak OLED");
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("TEST");
  display.display();
  delay(1500);
}

String checkBtn(int pin) {
  if(digitalRead(pin) == LOW) return "[X]";
  return "[ ]";
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  
  int x = analogRead(JOY_X);
  int y = analogRead(JOY_Y);
  int x_centered = x - 2048;
  int y_centered = y - 2048;

  display.println("JOYSTICK: ");
  if (abs(x_centered) < 300 && abs(y_centered) < 300) {
    display.println("CENTER");
  } 
  else if (y_centered > abs(x_centered)) {
    display.println("DOWN");
  } 
  else if (y_centered < -abs(x_centered)) {
    display.println("UP");
  } 
  else if (x_centered > abs(y_centered)) {
    display.println("RIGHT");
  } 
  else if (x_centered < -abs(y_centered)) {
    display.println("LEFT");
  }

  display.print("A:"); display.print(checkBtn(BTN_A));
  display.print("  B:"); display.println(checkBtn(BTN_B));
  display.print("START:"); display.print(checkBtn(BTN_START));
  display.print(" SELECT:"); display.println(checkBtn(BTN_SELECT));
  display.display();
  delay(30);
}