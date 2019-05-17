 /*	This task cannot be compiled alone, to compile this program, open src.c
	*	this file will be included.
	*	Tasks are to be called when a job is required and at the time of their completion
	* ALL TASKS must call that they have completed their task by setting a flag true
	*	AND they must also stop themselves to save on CPU time, do not hogCPU();
	*/

task coffeeDeployJob()
{
	coffeeJobDone = false;	//Set the status of the job to false, the job is not done yet
	if(((cycleSinceStart - 3) > 0) && ((cycleSinceStart - 3) < stopProduction))	//With an offset of -3, as long as a cup is poised AND production is not to be stopped
	{
		SensorValue(coffeeOut)=true;	//Set the coffee to deploy
		delay(coffeeConst);	//delay for a fixed amount of time
		SensorValue(coffeeOut)=false; //turn off the coffee
	}
	coffeeJobDone = true;	//Set the flag to true, the job is done
	stopTask(coffeeDeployJob);	//kermit stop
}
