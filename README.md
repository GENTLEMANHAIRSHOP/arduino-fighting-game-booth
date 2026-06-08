# Arduino Fighting Game Booth 🥊🎮

학교 축제에서 사용할 수 있는 인터랙티브 격투 게임 부스 프로젝트입니다.

인형 안에 압력 센서를 넣고, 사용자가 인형을 펀치하거나 발로 차면 Arduino Leonardo가 이를 키보드 입력으로 변환합니다.  
이 입력을 PC 게임에 연결하여 실제 몸동작으로 격투 게임을 조작할 수 있습니다.

## 프로젝트 소개

이 프로젝트는 단순히 키보드로 게임을 조작하는 방식이 아니라,  
몸을 움직여 직접 게임을 플레이할 수 있도록 만든 체험형 게임 부스입니다.

Arduino Leonardo의 Keyboard HID 기능을 활용하여 센서 입력을 컴퓨터의 키보드 입력처럼 인식하게 만들었습니다.

## Demo

사용자가 인형을 펀치하거나 발로 차면 압력 센서가 입력을 감지하고,  
Arduino Leonardo가 이를 키보드 입력으로 변환하여 PC 격투 게임을 조작합니다.

```txt
Punch / Kick
     ↓
Pressure Sensor
     ↓
Arduino Leonardo
     ↓
Keyboard Input
     ↓
PC Fighting Game
```

> 데모 이미지 또는 GIF를 추가하면 프로젝트 완성도를 더 잘 보여줄 수 있습니다.

```md
![demo](docs/demo.gif)
```

## 제작 목적

- 학교 축제에서 관람객이 직접 참여할 수 있는 체험형 부스 제작
- 아두이노와 센서를 활용한 피지컬 컴퓨팅 학습
- 하드웨어 입력을 게임 조작으로 연결하는 시스템 구현
- 압력 센서, 버튼, 키보드 HID 기능 실험

## 주요 기능

- 압력 센서로 펀치/킥 감지
- Arduino Leonardo를 이용한 키보드 입력 전송
- 여러 개의 인형을 각각 다른 공격 키로 연결 가능
- 버튼을 이용한 방향키 입력 가능
- PC 격투 게임 또는 웹 게임과 연동 가능

## 사용 부품

| 부품 | 역할 |
|---|---|
| Arduino Leonardo | 센서 입력을 키보드 입력으로 변환 |
| 압력 감지 센서 | 펀치/킥 입력 감지 |
| 버튼 | 방향키 입력 |
| 점퍼선 | 회로 연결 |
| USB 케이블 | 아두이노와 PC 연결 |
| 인형 또는 쿠션 | 사용자가 직접 타격하는 입력 장치 |
| PC 또는 노트북 | 격투 게임 실행 |

## Hardware Setup

```txt
[Pressure Sensor / Button]
          ↓
[Arduino Leonardo]
          ↓ USB HID Keyboard
[PC Fighting Game]
```

Arduino Leonardo는 HID Keyboard 기능을 지원하기 때문에, 센서 입력을 일반 키보드 입력처럼 PC에 전달할 수 있습니다.

## 실행 방법

1. Arduino IDE를 설치합니다.
2. `arduino/pressure-controller.ino` 파일을 엽니다.
3. 보드를 `Arduino Leonardo`로 선택합니다.
4. 코드를 업로드합니다.
5. PC 게임 또는 웹 게임에서 키 입력이 정상적으로 동작하는지 확인합니다.

## 사용법

| 입력 장치 | 키보드 입력 | 역할 |
|---|---|---|
| 압력 센서 1 | A | 공격 1 |
| 압력 센서 2 | S | 공격 2 |
| 압력 센서 3 | D | 공격 3 |
| 버튼 위 | ↑ | 위 이동 |
| 버튼 아래 | ↓ | 아래 이동 |
| 버튼 왼쪽 | ← | 왼쪽 이동 |
| 버튼 오른쪽 | → | 오른쪽 이동 |

## Project Structure

```txt
arduino-fighting-game-booth/
├─ arduino/
│  └─ pressure-controller.ino
├─ docs/
│  ├─ circuit.png
│  ├─ prototype.jpg
│  └─ demo.gif
└─ README.md
```

## 향후 개선 계획

- [ ] ESP32-CAM을 활용한 동작 인식 추가
- [ ] 게임 화면과 센서 입력 동기화
- [ ] LED 피드백 추가
- [ ] 부저 효과음 추가
- [ ] 모바일 터치 조작 지원
