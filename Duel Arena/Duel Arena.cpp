#include <iostream>
#include "RollingDie.h"
#include "Arena.h"
#include "Warrior.h"
using namespace std;


int main()
{
	RollingDie die;
	Arena arena(3, die);
	arena.fight();
	arena.print();
	arena.printWinner();
	cin.get(); cin.get();
	return 0;
}