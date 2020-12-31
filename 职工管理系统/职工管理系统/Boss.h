#pragma once
#include "Worker.h"
class Boss : public Worker
{
public:
	Boss(int id,string name,int department);
	void Show_Info();
	string Get_Department();
	~Boss();
};

