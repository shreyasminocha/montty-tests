#include <assert.h>
#include <hardware.h>
#include <stdio.h>
#include <stdlib.h>
#include <terminals.h>
#include <unistd.h>

// Make sure you check the return value of `InitHardware` btw

int main() {
	int status = InitTerminal(1);
	assert(status == ERROR);

	if (InitTerminalDriver() == ERROR)
		exit(1);

	status = InitTerminal(-1);
	assert(status == ERROR);

	status = InitTerminal(NUM_TERMINALS); // it's supposed to be exclusive
	assert(status == ERROR);

	status = InitTerminal(100);
	assert(status == ERROR);

	status = InitTerminal(1);
	assert(status == 0);

	status = InitTerminal(1);
	assert(status == ERROR);

	status = InitTerminalDriver();
	assert(status == ERROR);

	exit(0);
}
