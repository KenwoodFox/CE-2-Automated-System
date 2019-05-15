void moveTable(int places)
{
	int retraction = 24; //The slop retraction const

	while(places > 0)
	{
		while(SensorValue[TurntableEndOfTravel] != 1) //As long as the switch is not pressed
		{
			motor[turnTable] = (60); //advance untill it is
			delay(1);
		}

		while(SensorValue[TurntableEndOfTravel] == 1) //Once pressed
		{
			motor[turnTable] = (34); //turn the motor slower
			delay(1); //scan every 1ms
		}
		motor[turnTable] = (-100); //jerk in reverse for the delay of the slop retraction once the limit switch toggles out
		delay(retraction);
		motor[turnTable] = (0);

		places--; //you have moved one place
	}
}
