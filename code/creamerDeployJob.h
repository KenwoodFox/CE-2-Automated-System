 /*	This task cannot be compiled alone, to compile this program, open src.c
	*	this file will be included.
	*	Tasks are to be called when a job is required and at the time of their completion
	* ALL TASKS must call that they have completed their task by setting a flag true
	*	AND they must also stop themselves to save on CPU time, do not hogCPU();
	*/

task creamerDeployJob()
{
	creamerJobDone = false;	//Set the status of the job to false, the job is not done yet

	if((cycleSinceStart > 1) && (cycleSinceStart <= (stopProduction + 1)))	//With an offset of -one, as long as a cup is poised AND production is not to be stopped
	{
		delay(100);
		while(coffeeJobDone != true)
		{
			delay(300); //Wait untill coffee is done using the air
		}

		while(requestedCream > 0) //If there is creamer left to request
		{
			SensorValue(creamerOut)=true;	//Set the creamer to deploy
			delay(creamerConst);	//delay for a fixed amount of time
			SensorValue(creamerOut)=false;	//turn off the creamer
			delay(200); //A calm down delay
			requestedCream--;
		}
	}
	delay(1000); //Give an extra second
	creamerJobDone = true;	//Set the flag to true, the job is done
	stopTask(creamerDeployJob);	//kermit stop
}
