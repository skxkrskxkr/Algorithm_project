#pragma once
#include "well512.h"
#include <iostream>

class makeN {
public:
	int N_length;
	Well512Random rannum;
	std::string abc;
	std::string abc_mutate;
	makeN(int n) {
		abc_mutate = "";
		N_length = n;
		abc = "";
	}

	void makeN_txt(std::string name);
	void readN(std::string name);
	void read_mutate(std::string name);

	void make_mutate();
};