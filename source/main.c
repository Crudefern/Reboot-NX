// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char* argv[])
{
// (Console/Input Device) Initialization
	consoleInit(NULL);
// Configure pad as single player with standard controller styles
	padConfigureInput(1, HidNpadStyleSet_NpadStandard);
	PadState pad;
	padInitializeDefault(&pad);
	printf("Mariko-Friendly Reboot to Payload.\nCode by Crudefern, given an interface by Hydrate\n\n");
	printf("Press [-] to reboot to payload\n");
	printf("Press [L] to exit\n");

// Input Monitor Loop
	while (appletMainLoop())
	{
// Monitor for Input
		padUpdate(&pad);
		u64 kDown = padGetButtonsDown(&pad);
// Break if Left shoulder button
		if (kDown & HidNpadButton_L) {
			break;
		}
// Restart (Reboot to Payload) if Minus
		if (kDown & HidNpadButton_Minus) {
			spsmInitialize();
			spsmShutdown(true);
		}
// Update console while looping
		consoleUpdate(NULL);
	}
// Exit to HBMenu upon reaching
	consoleExit(NULL);
	return 0;
}