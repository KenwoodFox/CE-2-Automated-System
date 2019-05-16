task cupDeployJob()
{
	cupJobDone = false;	//Set the status of the job to false, the job is not done yet
	delay(700);	//This delay to simulate the job being done

	cupJobDone = true;	//Set the flag to true, the job is done
	stopTask(cupDeployJob);	//kermit stop
}

task sugarDeployJob()
{
	sugarJobDone = false;	//Set the status of the job to false, the job is not done yet
	while(requestedSugar > 0) //For as long as there is sugar requested
	{
		setServo(sugarServo, 0);	//Set servo to 0
		delay(100);	//delay
		setServo(sugarServo, 127);	//Set servo to 180
		delay(100);	//delay
		requestedSugar--;
	}
	sugarJobDone = true;	//Set the flag to true, the job is done
	stopTask(sugarDeployJob);	//kermit stop
}

task creamerDeployJob()
{
	creamerJobDone = false;	//Set the status of the job to false, the job is not done yet
	SensorValue(creamerOut)=true;	//Set the creamer to deploy
	delay(1000);	//delay for a fixed amount of time
	SensorValue(creamerOut)=false;	//turn off the creamer
	creamerJobDone = true;	//Set the flag to true, the job is done
	stopTask(creamerDeployJob);	//kermit stop
}

task coffeeDeployJob()
{
	coffeeJobDone = false;	//Set the status of the job to false, the job is not done yet
	SensorValue(coffeeOut)=true;	//Set the coffee to deploy
	delay(3000);	//delay for a fixed amount of time
	SensorValue(coffeeOut)=false; //turn off the coffee
	coffeeJobDone = true;	//Set the flag to true, the job is done
	stopTask(coffeeDeployJob);	//kermit stop
}

void startAllTasks()
{
	startTask(cupDeployJob);	//Start task
	startTask(sugarDeployJob);	//Start task
	startTask(creamerDeployJob);	//Start task
	startTask(coffeeDeployJob);	//Start task
	delay(50);
}
