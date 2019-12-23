#pragma once

class BrainFInterpreter {

public:
	BrainFInterpreter(const char instructions[]);
	void dIncr();
	void dDcr();
	void dValueIncr();
	void dValueDcr();
	void output();
	void input();
	void brOpen();
	void brClose();
	void interpret();
private:
	char data[100000] = {0};
	char *d;
	const char *i;
};

