#include <assert.h>
#include <hardware.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <terminals.h>
#include <unistd.h>

int main() {
	if (InitTerminalDriver() == ERROR)
		exit(1);

	struct termstat *statistics =
	    malloc(sizeof(struct termstat) * NUM_TERMINALS);
	if (statistics == NULL)
		exit(1);

	int status = TerminalDriverStatistics(statistics);
	assert(status == 0);

	int i;
	for (i = 0; i < NUM_TERMINALS; i++) {
		struct termstat expected = {-1, -1, -1, -1};
		assert(memcmp(&statistics[i], &expected, sizeof(struct termstat)) == 0);
	}

	for (i = 0; i < NUM_TERMINALS; i++) {
		if (InitTerminal(i) == ERROR)
			exit(1);

		// don't type anything at the terminal
		status = TerminalDriverStatistics(statistics);
		assert(status == 0);

		struct termstat expected = {0, 0, 0, 0};
		assert(memcmp(&statistics[i], &expected, sizeof(struct termstat)) == 0);
	}

	exit(0);
}
