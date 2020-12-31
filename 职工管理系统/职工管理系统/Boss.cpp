#include "Boss.h"

Boss::Boss(int id,string name,int department)
{
	this->Worker_ID = id;
	this->Worker_Name = name;
	this->Department_Num = department;
}
Boss::~Boss()
{

}
void Boss::Show_Info()
{
	cout << "职工编号：" << this->Worker_ID
		<< "\t职工姓名：" << this->Worker_Name
		<< "\t职工岗位：" << this->Get_Department()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::Get_Department()
{
	return string("总裁");
}