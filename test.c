#pragma config(Sensor, in2,    spin_angle,     sensorPotentiometer)
#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, in4,    push_angle,     sensorPotentiometer)
#pragma config(Sensor, in6,    ,               sensorPotentiometer)
#pragma config(Sensor, in8,    lift_angle,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  right_encoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  alpha,          sensorDigitalIn)
#pragma config(Sensor, dgtl4,  beta,           sensorDigitalIn)
#pragma config(Sensor, dgtl5,  gamma,          sensorDigitalIn)
#pragma config(Sensor, dgtl11, left_encoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           arm_reach,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           right_back_wheel, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           right_front_wheel, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           jack_left,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           crank_left,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           crank_right,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           jack_right,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           left_front_wheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           left_back_wheel, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port10,          catching,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "auto_included.c"

task main()
{
		//***************************INITIALIZE ALL THE STATE*****************************//
	SensorValue[gyro]=0;
	SensorValue[left_encoder]=SensorValue[right_encoder]=0;
	spin_forward = spin_backward = false;
	claw_hold = claw_loose = false;

	//***************************initialize the lift angle****************************//
	deltaJack = 0;
	Target_Jack = JackDown + deltaJack;

  //*************************turn on the jack & arm task****************************//
	JackKeep = true;
	ArmKeep = true;
	BaseKeep = true;

	//***********************frist choose ALPHA BLUE short side***********************//
	check_switch = true;
  jack_choose = false;
  Target_Arm = ARMBACK;
	startTask(PID_Claw);
	startTask(PID_Crank);
	startTask(PID_Jack);
	startTask(PID_Arm);


  startTask(third_peri);
	jack_choose = true;
	delay(200);//time to suck
	spin_backward = true;
	stopTask(third_peri);
	delay(150);//enough time to spin backward
	Target_Jack = JackTri + deltaJack;
	delay(250);
	claw_loose = true;
	delay(70);//enough time to jack down

	//*******************************ALPHA RED REPEAT THE PROCESS**********************//4(2)
  Target_Jack = JackPreD;// 1624;//////////////////////////4
  claw_loose = true;
  delay(120);
  spin_forward = true;
  delay(250);
  claw_hold = true;
  delay(160);
  Target_Jack = JackPreD+200;// 1624;//////////////////////////4
  spin_backward = true;
  delay(200);
  Target_Jack = JackFour;// 1250;
  delay(200);
  claw_loose = true;
  delay(200);

	//*******************************ALPHA RED REPEAT THE PROCESS**********************//5(3)
  Target_Jack = JackPreD + deltaJack;// 1624;//////////////////////////5
  claw_loose = true;
  delay(150);
  spin_forward = true;
  delay(200);
  claw_hold = true;
  delay(250);
  Target_Jack = JackFive + deltaJack;// 1750;
  spin_backward = true;
  delay(200);
  Target_Jack = JackHold + deltaJack;// 1500;
  delay(320);

	//*******************************ALPHA RED REPEAT THE PROCESS**********************//6(4)
  Target_Jack = JackPreD+100 + deltaJack;// 1764;//////////////////////////6
  claw_loose = true;
  delay(250);
  spin_forward = true;
  delay(100);
  Target_Jack = JackPreD + deltaJack;// 1624;
  delay(200);
  claw_hold = true;
  delay(200);
  Target_Jack = JackSix + deltaJack - 100;// 1950;
  spin_backward = true;
  delay(200);
  Target_Jack = JackHold+100 + deltaJack;// 1600;
  delay(200);
  claw_loose = true;
  delay(230);

	//*******************************ALPHA RED REPEAT THE PROCESS**********************//7(5)
  Target_Jack = JackPreD+200 + deltaJack;// 1864;//////////////////////////7
  claw_loose = true;
  delay(250);
  spin_forward = true;
  delay(100);
  Target_Jack = JackPreD + deltaJack;// 1624;
  delay(100);
  claw_hold = true;
  delay(300);
  Target_Jack = JackSeven + deltaJack;//2050;
  claw_hold = true;
  spin_backward = true;
  delay(230);
  Target_Jack = JackHold+200 + deltaJack;//1700;
  delay(200);
  claw_loose = true;
  delay(200);

  //*******************************ALPHA RED REPEAT THE PROCESS**********************//7(5)
  Target_Jack = JackPreD+300 + deltaJack;// 1864;//////////////////////////7
  claw_loose = true;
  delay(390);
  spin_forward = true;
  delay(100);
  Target_Jack = JackPreD + deltaJack;// 1624;
  delay(100);
  claw_hold = true;
  delay(350);
  Target_Jack = JackSeven + deltaJack+200;//2050;
  delay(120);
  claw_hold = true;
  spin_backward = true;
  delay(330);
  Target_Jack = JackHold+200 + deltaJack;//1700;
  delay(200);
  claw_loose = true;
  delay(200);

	//*******************************ALPHA RED REPEAT THE PROCESS**********************//8(6)
  Target_Jack = JackPreD+680;// 2064;//////////////////////////8
  claw_loose = true;
  delay(250);
  claw_loose = true;
  spin_forward = true;
  delay(300);
  Target_Jack = JackPreD;// 1624;
  delay(350);
  claw_hold = true;
  delay(100);
  startTask(eighth_drop);

  while(1)
  {delay(10);}
}
