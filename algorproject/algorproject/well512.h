#pragma once

class Well512Random {
protected:
	unsigned int state[16];
	unsigned int index;
private:
	enum {
		DIFFER_VALUE = 100,
	};
public:
	Well512Random();
	Well512Random(unsigned int nSeed);
	~Well512Random();
	unsigned int GetValue();
	unsigned int GetValue(unsigned long minValue, unsigned long maxValue);
	unsigned int GetValue(unsigned long maxValue);
};