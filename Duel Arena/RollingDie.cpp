#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RollingDie.h"

using namespace std;

RollingDie::RollingDie() : RollingDie(6)
{
}

RollingDie::RollingDie(int sides_count)
{
	this->sides_count = sides_count;
	srand(time(NULL));
}

RollingDie::~RollingDie()
{
	cout << "Calling the destructor for the die with " << sides_count << " sides" << endl;
}

int RollingDie::roll()
{
	return rand() % sides_count + 1;
}