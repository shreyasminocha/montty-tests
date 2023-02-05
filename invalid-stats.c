#include <stdio.h>
#include <stdlib.h>
#include <terminals.h>
#include <unistd.h>

int main() {
	InitTerminalDriver();

	InitTerminal(1);
	int status = TerminalDriverStatistics(NULL);
	assert(status == ERROR);

	exit(0);
}
