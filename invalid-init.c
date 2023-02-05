#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <terminals.h>
#include <unistd.h>

int main() {
	if (InitTerminalDriver() == ERROR)
		exit(1);

	int res = InitTerminal(100);
	assert(res == ERROR);

	exit(0);
}
