all: lint

lint:
	clang-format -i *.c
