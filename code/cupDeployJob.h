 /*	This task cannot be compiled alone, to compile this program, open src.c
	*	this file will be included.
	*	Tasks are to be called when a job is required and at the time of their completion
	* ALL TASKS must call that they have completed their task by setting a flag true
	*	AND they must also stop themselves to save on CPU time, do not hogCPU();
	*/

task cupDeployJob()
{
	cupJobDone = false;	//Set the status of the job to false, the job is not done yet
	delay(700);	//This delay to simulate the job being done

	cupJobDone = true;	//Set the flag to true, the job is done
	stopTask(cupDeployJob);	//kermit stop
}