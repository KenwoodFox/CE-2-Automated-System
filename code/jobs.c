task cupDeployJob()
{
	cupJobDone = false;
	delay(700);
	cupJobDone = true;
	stopTask(cupDeployJob);
}

task sugarDeployJob()
{
	sugarJobDone = false;
	delay(400);
	sugarJobDone = true;
	stopTask(sugarDeployJob);
}

task creamerDeployJob()
{
	creamerJobDone = false;
	SensorValue(creamerOut)=true;
	delay(1000);
	SensorValue(creamerOut)=false;
	creamerJobDone = true;
	stopTask(creamerDeployJob);
}

task coffeeDeployJob()
{
	coffeeJobDone = false;
	SensorValue(coffeeOut)=true;
	delay(3000);
	SensorValue(coffeeOut)=false;
	coffeeJobDone = true;
	stopTask(coffeeDeployJob);
}

void startAllTasks()
{
	startTask(cupDeployJob);
	startTask(sugarDeployJob);
	startTask(creamerDeployJob);
	startTask(coffeeDeployJob);
	delay(50);
}
