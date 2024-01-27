// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char* argv[])
{	spsmInitialize();
	spsmShutdown(true);
    return 0;
}
