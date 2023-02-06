#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <terminals.h>
#include <threads.h>
#include <unistd.h>

void reader(void *);

int main() {
	if (InitTerminalDriver() == ERROR)
		exit(1);

	if (InitTerminal(1) == ERROR)
		exit(1);

	ThreadCreate(reader, NULL);

	ThreadWaitAll();
	sleep(10);

	exit(0);
}

void reader(void *arg) {
	(void)arg;

	int status;
	char buf[5];

	if (buf == NULL)
		exit(1);

	status = ReadTerminal(-1, buf, 1);
	assert(status == ERROR);

	status = ReadTerminal(100, buf, 1);
	assert(status == ERROR);

	status = ReadTerminal(1, NULL, 5);
	assert(status == ERROR);

	status = ReadTerminal(1, buf, -10);
	assert(status == ERROR);

	// status = ReadTerminal(1, buf, 10);
	// assert(status == ERROR);
}
