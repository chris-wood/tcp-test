#include "tcp-util.h"

void LogFatal(char *errorMessage)
{
	perror(errorMessage);
	exit(1);
}