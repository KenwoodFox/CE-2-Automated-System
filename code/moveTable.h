void moveTable(int places)
{
	int retraction = 24; //The slop retraction const

	while(places > 0)
	{

		while(SensorValue[TurntableEndOfTravel] == 1) //for as long as the value of TurntableEndOfTravel is pressed
		{
			motor[turnTable] = (34); //turn the motor
			delay(1); //scan every 1ms
		}
		motor[turnTable] = (-100); //jerk in reverse for the delay of the slop retraction
		delay(retraction);
		motor[turnTable] = (0);
		delay(1800);

		while(SensorValue[TurntableEndOfTravel] != 1)
		{
			motor[turnTable] = (60);
			delay(1);
		}
		places--;
	}
}
