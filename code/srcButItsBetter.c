#pragma config(Sensor, dgtl1,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  TurntableEndOfTravel, sensorTouch)
#pragma config(Motor,  port1,           turnTable,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "moveTable.h"

task main()
{
	while(true)
	{
		moveTable();
	}
}