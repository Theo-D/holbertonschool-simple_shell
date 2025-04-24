#include "shell.h"
/**
 * exitHandler - Handles exit status according to received error tracking
 * variable.
 * @errTrack: Integer used to track return values throughout the code.
 */
void exitHandler(int errTrack)
{
	if (errTrack == -3)
		exit(127);
}
