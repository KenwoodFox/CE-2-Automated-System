 /*	This task cannot be compiled alone, to compile this program, open src.c
	*	this file will be included.
	*	Tasks are to be called when a job is required and at the time of their completion
	* ALL TASKS must call that they have completed their task by setting a flag true
	*	AND they must also stop themselves to save on CPU time, do not hogCPU();
	*/

task sugarDeployJob()
{
	sugarJobDone = false;	//Set the status of the job to false, the job is not done yet

	if((cycleSinceStart > 2) && (cycleSinceStart <= (stopProduction + 2)))	//With an offset of -2, as long as a cup is poised AND production is not to be stopped
	{
		while(requestedSugar > 0) //For as long as there is sugar requested
		{
			if((requestedSugar % 2) != 0)
			{
				motor(sugarServo) = 127;	//Set motor
			}
			else
			{
				motor(sugarServo) = -127;	//Set motor
			}
			delay(sugarTurnConst);		//delay
			motor(sugarServo) = 0;		//Set motor
			delay(sugarTurnConst);		//delay
			requestedSugar--;
		}
	}
	delay(1000); //Give an extra second
	sugarJobDone = true;	//Set the flag to true, the job is done
	stopTask(sugarDeployJob);	//kermit stop
}
