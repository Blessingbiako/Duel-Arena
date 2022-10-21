#ifndef __ROLLINGDIE_H__
#define __ROLLINGDIE_H__

class RollingDie
{
public:
	RollingDie();
	RollingDie(int sides_count);
	~RollingDie();
	int roll();
	int sides_count;
};
#endif