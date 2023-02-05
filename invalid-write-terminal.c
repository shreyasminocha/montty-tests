#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <terminals.h>
#include <threads.h>
#include <unistd.h>

void writer(void *);

int main() {
	if (InitTerminalDriver() == ERROR)
		exit(1);

	if (InitTerminal(1) == ERROR)
		exit(1);

	ThreadCreate(writer, NULL);

	ThreadWaitAll();
	sleep(10);

	exit(0);
}

void writer(void *arg) {
	(void)arg;

	int status;
	status = WriteTerminal(-1, "foo", 1);
	assert(status == ERROR);

	status = WriteTerminal(100, "foo", 1);
	assert(status == ERROR);

	status = WriteTerminal(1, NULL, 5);
	assert(status == ERROR);

	status = WriteTerminal(1, "foo", -10);
	assert(status == ERROR);

	// status = WriteTerminal(1, "foo", 50);
	// assert(status == ERROR);
}
