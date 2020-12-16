### NH candle

---

모드에 따라서 LED의 색깔을 제어한다.



각 모드에 대한 설명

| mode | explain                           |
| ---- | --------------------------------- |
| 1    | control according to temperature  |
| 2    | control accoding to humidity      |
| 3    | control according to User setting |



핀 연결

| sensor           | pin    |
| ---------------- | ------ |
| DHT 11           | PD0    |
| cds              | PF0    |
| touch sensor     | PF1    |
| RGB LED R        | PB5    |
| RGB LED G        | PB6    |
| RGB LED B        | PB7    |
| LCD data pins    | PORT A |
| LCD control pins | PORT C |



터치 센서를 터치할 때마다 1~3의 모드로 변경된다.
각 모드의 조건에 맞는 색깔을 RGB LED에 출력한다.

PyQt GUI를 통해서 현재의 온/습도, 조도, 모드를 값과 그래프를 통해서 확인할 수 있다.
GUI의 Set 페이지를 통해서 RGB값을 0~255로 설정할 수 있다.

모드 3에서는 설정된 값을 RGB LED에 출력한다.



##### 모드 1

```c
if(I_Temp > 30) pwm_led(255, 0, 0); # 빨간색
else if(I_Temp > 25) pwm_led(0, 255, 0); # 초록색
else pwm_led(0, 0, 255); # 파란색
```



##### 모드 2

```
if(cds_value > 800) pwm_led(0, 0, 255); # 파란색
else if(cds_value > 600) pwm_led(0, 255, 0); # 초록색
else pwm_led(255, 0, 0); # 빨간색
```



