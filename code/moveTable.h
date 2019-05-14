void moveTable()
{
	int retraction = 24;

	while(SensorValue[TurntableEndOfTravel] == 1)
	{
		motor[turnTable] = (34);
		delay(1);
	}
	motor[turnTable] = (-100);
	delay(retraction);
	motor[turnTable] = (0);
	delay(1800);

	while(SensorValue[TurntableEndOfTravel] != 1)
	{
		motor[turnTable] = (60);
		delay(1);
	}
}
