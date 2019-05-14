#pragma config(Sensor, in1,    sugarPot,       sensorPotentiometer)
#pragma config(Sensor, in2,    creamerPot,     sensorPotentiometer)
#pragma config(Sensor, in3,    modePot,        sensorPotentiometer)
#pragma config(Sensor, in4,    productionPot,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  startButton,    sensorTouch)
#pragma config(Sensor, dgtl2,  eStop,          sensorTouch)
#pragma config(Sensor, dgtl3,  deployCupConfirm, sensorTouch)
#pragma config(Sensor, dgtl4,  coffeeVentConfirm, sensorTouch)
#pragma config(Sensor, dgtl5,  sugarConfirm,   sensorTouch)
#pragma config(Sensor, dgtl6,  creamerConfirm, sensorTouch)
#pragma config(Sensor, dgtl7,  hopperMax,      sensorTouch)
#pragma config(Sensor, dgtl8,  coffeeLevel,    sensorTouch)
#pragma config(Sensor, dgtl9,  turnTableLimit, sensorNone)
#pragma config(Motor,  port1,           turntable,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           sugarTurn,     tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


int sugarRequest;
int creamerRequest;
int productionMode;
int productionTarget;

bool deployCupComplete;
bool sugarComplete;
bool creamerComplete;
bool coffeeComplete;
bool lidComplete;

task main()
{
	while(true)
	{
		while(SensorValue[startButton] == false) //For as long as the start button is not pressed
		{
			//Display to the screen that the machine is in idle mode, maybe even flash a light or two
			delay(10);
		}

		//Upon exit of this loop, populate these variables
		sugarRequest = SensorValue[sugarPot];
		creamerRequest = SensorValue[creamerPot];
		productionMode = SensorValue[modePot];
		productionTarget = SensorValue[productionPot]


	}
}

void advanceTable(int target, int turntableSpeed, int retract)
{
	//receive a variable and move the turntable that many places
	//There are plans to implement a PID loop!!!!

	motor[turntable] = (turntableSpeed / 2 );
	delay(100); //This delay allows the turntable time to unadvance the limit switch
	while(SensorValue[turnTableLimit] != true)
	{
		motor[turntable] = (turntableSpeed); //revolve the motor untill..
	}

	motor[turntable] = ((turntableSpeed * -1 ) / 2);
	delay(retract);
	motor[turntable] = (0);
}
