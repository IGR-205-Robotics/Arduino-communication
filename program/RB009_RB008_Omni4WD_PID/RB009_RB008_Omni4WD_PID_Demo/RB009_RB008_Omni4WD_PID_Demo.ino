
#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <EEPROM.h>
#include <fuzzy_table.h>
#include <PID_Beta6.h>
#include <MotorWheel.h>
#include <Omni4WD.h>

#include <fuzzy_table.h>
#include <PID_Beta6.h>

/*

            \                    /
   wheel1   \                    /   wheel4
   Left     \                    /   Right
    
    
                              power switch
    
            /                    \
   wheel2   /                    \   wheel3
   Right    /                    \   Left

 */

/*
irqISR(irq1,isr1);
MotorWheel wheel1(5,4,12,13,&irq1);

irqISR(irq2,isr2);
MotorWheel wheel2(6,7,14,15,&irq2);

irqISR(irq3,isr3);
MotorWheel wheel3(9,8,16,17,&irq3);

irqISR(irq4,isr4);
MotorWheel wheel4(10,11,18,19,&irq4);

*/
irqISR(irq1,isr1);
MotorWheel wheel1(3,2,4,5,&irq1);

irqISR(irq2,isr2);
MotorWheel wheel2(11,12,14,15,&irq2);

irqISR(irq3,isr3);
MotorWheel wheel3(9,8,16,17,&irq3);

irqISR(irq4,isr4);
MotorWheel wheel4(10,7,18,19,&irq4);
 

Omni4WD Omni(&wheel1,&wheel2,&wheel3,&wheel4);

void setup() {
	//TCCR0B=TCCR0B&0xf8|0x01;    // warning!! it will change millis()
	TCCR1B=TCCR1B&0xf8|0x01;    // Pin9,Pin10 PWM 31250Hz
	TCCR2B=TCCR2B&0xf8|0x01;    // Pin3,Pin11 PWM 31250Hz
    
	Omni.PIDEnable(0.31,0.01,0,10);


 pinMode(10, INPUT);
 pinMode(11, INPUT);
 pinMode(12, INPUT);
 pinMode(13, INPUT);
Serial.begin(9600);    
}

void loop() {

int command = 0;
for(int i=0; i<4;i++) {
  command += digitalRead(10+i) * pow(2,i);
}


Serial.print(digitalRead(10));
Serial.print(digitalRead(11));
Serial.print(digitalRead(12));
Serial.println(digitalRead(13));

switch (command) {
  case 1:
    Omni.setCarAdvance(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200); 
    break;
  case 2:
    Omni.setCarBackoff(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 3:
    Omni.setCarLeft(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 4:
    Omni.setCarRight(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 5:
    Omni.setCarUpperLeft(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 6:
    Omni.setCarLowerRight(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 7:
    Omni.setCarLowerLeft(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 8:
    Omni.setCarUpperRight(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 9:
    Omni.setCarRotateLeft(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  case 10:
    Omni.setCarRotateRight(0);
    Omni.setCarSpeedMMPS(200,500);
    Omni.delayMS(200);
    break;
  default:
  Omni.setCarStop(0);
  Omni.delayMS(200);
    break;
}
//Omni.demoActions(200,5000,500,false);

    
}
