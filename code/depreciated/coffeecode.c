#pragma config(Sensor, dgtl3,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, creamerOut,     sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, coffeeOut,      sensorLEDtoVCC)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)
	{
		SensorValue(coffeeOut)=true;
		delay(1000);
		SensorValue(creamerOut)=false;
		SensorValue(LED)=true;
		delay(400);
		SensorValue(coffeeOut)=false;
		delay(120);
		SensorValue(creamerOut)=true;
		SensorValue(LED)=false;
		delay(1000);
	}
}
