#pragma config(Sensor, dgtl2,  TurntableEndOfTravel, sensorTouch)
#pragma config(Sensor, dgtl3,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  startButton,    sensorTouch)
#pragma config(Sensor, dgtl5,  sonicCoffeeSensor, sensorSONAR_inch)
#pragma config(Sensor, dgtl12, creamerOut,     sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, coffeeOut,      sensorLEDtoVCC)
#pragma config(Motor,  port1,           turnTable,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port9,           sugarServo,    tmotorVex269_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "headers/moveTable.h"					//Include the moveTable header
#include "headers/ce2libraries/init.h"	//Include the startup header
#include "headers/ce2libraries/blink.h"	//Include the blink header

//Consts
int requestedSugar; 			//the number of sugar tumbles to add
int requestedCream; 			//the units of creamer to add
int creamerConst = 4000; 	//the number of time units to deploy cream for
int sugarTurnConst = 975; //The time in ms for the sugar motor to run
int coffeeConst = 14000;		//The time in ms for the coffee to be deployed safely
int cycleSinceStart; 			//Counts the current cycle since start
int stopProduction = 5;		//The max number of full production mode untits

//Jobs
bool cupJobDone = true;					//Init job as done
bool sugarJobDone = true;				//Init job as done
bool creamerJobDone = true;			//Init job as done
bool coffeeJobDone = true;			//Init job as done
#include "coffeeDeployJob.h";		//include the coffee job
#include "creamerDeployJob.h";	//include the creamer job
#include "cupDeployJob.h";			//include the cup job
#include "sugarDeployJob.h";		//include the sugar job
#include "headers/jobs.h" 			//Include job command structures

task main()
{
	while(true)
	{
		cycleSinceStart = 1; //Set the current cycle to 0

		startup(startButton,LED);	//Wait till the startup button enableBot Is pressed
		moveTable(1);	//Move one space

		while(cycleSinceStart <= stopProduction + 4)
		{
			//These values will be populated by reading sensors
			requestedSugar = 2; //the number of sugar tumbles to add
			requestedCream = 1; //the units of creamer to add

			startAllTasks();	//Start all of the tasks

			while ((cupJobDone == false) || (sugarJobDone == false) || (creamerJobDone == false) || (coffeeJobDone == false))	//Wait for every task to tell us that it is complete
			{
				blink(LED, 3);	//Tripple blink the LED
			}
			moveTable(1);	//Move one space
			cycleSinceStart++; //Count this as a completed cycle
		}
		moveTable(stopProduction + 1);	//Move the number of spaces of cups left
	}
}
