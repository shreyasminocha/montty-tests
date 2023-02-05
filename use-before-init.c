#include <assert.h>
#include <hardware.h>
#include <stdio.h>
#include <stdlib.h>
#include <terminals.h>
#include <unistd.h>

int main() {
	/**
	 * Before `InitTerminalDriver`
	 */

	int status = WriteTerminal(1, "foo", 1);
	assert(status == ERROR);

	char *buf = malloc(5);
	if (buf == NULL)
		exit(1);
	status = ReadTerminal(1, buf, 1);
	assert(status == ERROR);

	struct termstat *statistics =
	    malloc(sizeof(struct termstat) * NUM_TERMINALS);
	if (statistics == NULL)
		exit(1);
	status = TerminalDriverStatistics(statistics);
	assert(status == ERROR);

	if (InitTerminalDriver() == ERROR)
		exit(1);

	/**
	 * After `InitTerminalDriver`, but before the relevant `InitTerminal`
	 */

	status = WriteTerminal(1, "foo", 1);
	assert(status == ERROR);

	buf = malloc(5);
	if (buf == NULL)
		exit(1);
	status = ReadTerminal(1, buf, 1);
	assert(status == ERROR);

	statistics = malloc(sizeof(struct termstat) * NUM_TERMINALS);
	if (statistics == NULL)
		exit(1);
	status = TerminalDriverStatistics(statistics);
	assert(status == 0);

	exit(0);
}
