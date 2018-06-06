#include <iostream>
#include<ctime>
#include<string>
#include "well512.h"

using namespace std;

Well512Random::Well512Random() //랜덤 시드갑 자동 생성
{
	index = 0;
	unsigned int s = static_cast<unsigned int>(time(NULL));
	for (int i = 0; i < 16; i++) {
		state[i] = s;
		s += s + DIFFER_VALUE;
	}
}
Well512Random::Well512Random(unsigned int nSeed) // 시드 값을 받아 초기화
{
	index = 0;
	unsigned int s = nSeed;
	for (int i = 0; i < 16; i++) {
		state[i] = s;
		s += s + DIFFER_VALUE;
	}
}
Well512Random:: ~Well512Random() {}
unsigned int Well512Random::GetValue() {
	unsigned long a, b, c, d;
	a = state[index];
	c = state[(index + 13) & 15];
	b = a ^ c ^ (a << 16) ^ (c << 15);
	c = state[(index + 9) & 15];
	c ^= (c >> 11);
	a = state[index] = b ^ c;
	d = a ^ ((a << 5) & 0xda442d24U);
	index = (index + 15) & 15;
	a = state[index];
	state[index] = a ^ b ^ d ^ (a << 2) ^ (b << 18) ^ (c << 28);
	return state[index];
}
unsigned int Well512Random::GetValue(unsigned long minValue, unsigned long maxValue) {
	return minValue + (GetValue() % (maxValue - minValue));
}
unsigned int Well512Random::GetValue(unsigned long maxValue) {
	return GetValue() % maxValue;
}