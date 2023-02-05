#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <terminals.h>
#include <unistd.h>

int main() {
	if (InitTerminalDriver() == ERROR)
		exit(1);

	if (InitTerminal(1) == ERROR)
		exit(1);

	int status = TerminalDriverStatistics(NULL);
	assert(status == ERROR);

	exit(0);
}
