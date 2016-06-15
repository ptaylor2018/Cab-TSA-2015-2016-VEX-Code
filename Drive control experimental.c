#pragma config(Motor,  port1,           rightFlyWheel, tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftFlyWheel,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           intakeSpinner, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftFrontDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftBackDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightFrontDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightBackDrive, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int flydebounce=0; //set up variables
	int flyspeed = 0;
	int flybtn=0;

	int liftdebounce = 0;
	int liftspeed = 0;
	int liftbtn = 0;

	int intakedebounce = 0;
	int intakespeed = 0;
	int intakebtn = 0;

	int liftdirspeed = 0;

	int intakedirspeed =0;
	int flydirspeed = 0;


	while(1)
	{
		motor[leftBackDrive] = vexRT[Ch3]; // controls motors
		motor[leftFrontDrive] = vexRT[Ch3];
		motor[rightBackDrive] = vexRT[Ch2];
		motor[rightFrontDrive] = vexRT[Ch2];

		if(vexRT[Btn5U]== true){ //controls flywheel speed with toggle switch
			flydirspeed = 76;
		}
		else{
			flydirspeed = 127;
		}


		if(vexRT[Btn6U]== true){ //intake and lift speed with toggle switch
			liftdirspeed = -127;
			intakedirspeed= 1;
		}
		else if(vexRT[Btn8U] == true){
			liftdirspeed = -127;
			intakedirspeed = -127;
		}

		else{
			liftdirspeed = 127;
			intakedirspeed = 127;
		}



		flybtn = vexRT[Btn5D]; //controls flywheel with toggle switch
		if(flybtn && (flybtn != flydebounce))
			flyspeed = flyspeed?0:flydirspeed;  // speed is modified only if btn is pressed and was unpressed.
		motor[leftFlyWheel] = flyspeed;
		motor[rightFlyWheel] = flyspeed;
		flydebounce = flybtn;

		liftbtn = vexRT[Btn6D]; //controls lift and intake with toggle switch
		if(liftbtn && (liftbtn != liftdebounce))
		{
			intakespeed = intakespeed?0:intakedirspeed;
			liftspeed = liftspeed?0:liftdirspeed; }  // speed is modified only if btn is pressed and was unpressed.
		motor[lift] = liftspeed;
		motor[intakeSpinner] = intakespeed;
		liftdebounce = liftbtn;


	}


}
