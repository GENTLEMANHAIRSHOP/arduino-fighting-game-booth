#include <Keyboard.h>

/*
  Arduino Fighting Game Booth
  Board: Arduino Leonardo

  압력 센서와 버튼 입력을 키보드 입력으로 변환하는 코드입니다.

  압력 센서:
  - A0: 공격 1 → A
  - A1: 공격 2 → S
  - A2: 공격 3 → D

  버튼:
  - D2: 위 방향키
  - D3: 아래 방향키
  - D4: 왼쪽 방향키
  - D5: 오른쪽 방향키
*/

// 압력 센서 핀
const int SENSOR_1 = A0;
const int SENSOR_2 = A1;
const int SENSOR_3 = A2;

// 버튼 핀
const int BUTTON_UP = 2;
const int BUTTON_DOWN = 3;
const int BUTTON_LEFT = 4;
const int BUTTON_RIGHT = 5;

// 압력 감지 기준값
const int PRESS_THRESHOLD = 500;

// 중복 입력 방지 시간
const unsigned long COOLDOWN_MS = 300;

unsigned long lastSensor1Time = 0;
unsigned long lastSensor2Time = 0;
unsigned long lastSensor3Time = 0;

void setup() {
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  unsigned long now = millis();

  int sensor1Value = analogRead(SENSOR_1);
  int sensor2Value = analogRead(SENSOR_2);
  int sensor3Value = analogRead(SENSOR_3);

  // 압력 센서 1 → A 키
  if (sensor1Value > PRESS_THRESHOLD && now - lastSensor1Time > COOLDOWN_MS) {
    tapKey('a');
    lastSensor1Time = now;
  }

  // 압력 센서 2 → S 키
  if (sensor2Value > PRESS_THRESHOLD && now - lastSensor2Time > COOLDOWN_MS) {
    tapKey('s');
    lastSensor2Time = now;
  }

  // 압력 센서 3 → D 키
  if (sensor3Value > PRESS_THRESHOLD && now - lastSensor3Time > COOLDOWN_MS) {
    tapKey('d');
    lastSensor3Time = now;
  }

  // 방향키 버튼
  handleButton(BUTTON_UP, KEY_UP_ARROW);
  handleButton(BUTTON_DOWN, KEY_DOWN_ARROW);
  handleButton(BUTTON_LEFT, KEY_LEFT_ARROW);
  handleButton(BUTTON_RIGHT, KEY_RIGHT_ARROW);

  delay(10);
}

void tapKey(char key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void tapSpecialKey(uint8_t key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void handleButton(int pin, uint8_t key) {
  if (digitalRead(pin) == LOW) {
    Keyboard.press(key);
  } else {
    Keyboard.release(key);
  }
}
