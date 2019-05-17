void moveTable(int places)	//Create moveTable routine and init integer places
{
	int retraction = 24;	//The slop retraction constant

	while(places > 0)	//For as long as there are places left to move
	{
		while(SensorValue[TurntableEndOfTravel] != 1)	//As long as the switch is not pressed...
		{
			motor[turnTable] = (60);	//..advance until the switch becomes pressed
			delay(1);	//Scan every 1ms
		}

		while(SensorValue[TurntableEndOfTravel] == 1)	//Once pressed...
		{
			motor[turnTable] = (34);	//...Slow the motor down
			delay(1); //Scan every 1ms
		}
		motor[turnTable] = (-100);	//Jerk in reverse for the delay of the slop retraction once the limit switch toggles out of the loop
		delay(retraction);	//Jerk
		motor[turnTable] = (0);	//Stop the motor

		places--;	//Subtract one from the places left to move
	}

	if(SensorValue(sonicCoffeeSensor) < 5) //if a sensor reports that a cup is present
	{
		//hangup
		delay(100);
	}
	delay(800);
}
