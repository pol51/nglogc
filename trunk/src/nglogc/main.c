
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
//#include "logger.h"


int main(int argc, char *argv[])
{

   logc_registerLogger(0x0001, STDOUT, LOG_WARNING);

   printf("stub main for build system\n");

   return 0;
}
