# System Architecture

## 전체 구조

이 프로젝트는 사용자의 실제 동작을 센서로 감지하고, Arduino Leonardo를 통해 컴퓨터 키보드 입력으로 변환하는 구조입니다.

```txt
사용자 펀치 / 킥
        ↓
압력 센서 감지
        ↓
Arduino Leonardo 입력 처리
        ↓
Keyboard HID 신호 전송
        ↓
PC 게임 조작
