# **Obstacle Avoiding Robot**

Obstacle Avoiding Robot using Microcontroller ATMega32


## About The Robot
- The Robot starts moving forward randomly, once detecting an obstacle the Robot stops.
- The Ultrasonic Sensor starts rotating by the Servo Motor, measuring the left and right distances, and the Robot turns either left or right according to the measured distance.
- **Input Capture Unit (ICU)** in Timer1 immediately captures the Rising and the Falling edges of the Echo Pin in Ultrasonic Sensor, which helps in measuring the distance accurately.
- Timer0 Fast PWM Mode controls the speed of the Robot while moving (around 60% duty cycle), and during turning left or right (around 40% duty cycle).

## Hardware Components
1. ATMega32
2. Ultrasonic Sensor (HC-SR04)
3. Servo Motor (SG90)
4. DC Motors
5. DC Motor Driver (L298N)

## Microcontroller Peripherals
1. DIO
2. Timer0 ==> (Fast PWM mode), for Controlling Speed of Robot when Turning
3. Timer1 ==> (Fast PWM OCRA Top Mode), for Servo Motor and Ultrasonic Sensor

![IMG_20230826_234131](https://github.com/YoussefSamy21/Obstacle-Avoiding-Robot/assets/139294056/e2da6c0c-d736-4ad8-8fa3-9af759398be5)

![IMG_20230826_233758](https://github.com/YoussefSamy21/Obstacle-Avoiding-Robot/assets/139294056/2154e09d-8196-4296-b653-2ed9c1db1004)
