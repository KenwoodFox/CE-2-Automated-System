 /*	This task cannot be compiled alone, to compile this program, open src.c
	*	this file will be included.
	*	Tasks are to be called when a job is required and at the time of their completion
	* ALL TASKS must call that they have completed their task by setting a flag true
	*	AND they must also stop themselves to save on CPU time, do not hogCPU();
	*/

task sugarDeployJob()
{
	sugarJobDone = false;	//Set the status of the job to false, the job is not done yet
	if(((cycleSinceStart - 2) > 0) && ((cycleSinceStart - 2) < stopProduction))	//With an offset of -2, as long as a cup is poised AND production is not to be stopped
	{
		while(requestedSugar > 0) //For as long as there is sugar requested
		{
			motor(sugarServo) = 127;	//Set servo to 0
			delay(sugarTurnConst);	//delay
			motor(sugarServo) = -0;	//Set servo to 180
			delay(sugarTurnConst);	//delay
			requestedSugar--;
		}
	}
	sugarJobDone = true;	//Set the flag to true, the job is done
	stopTask(sugarDeployJob);	//kermit stop
}
