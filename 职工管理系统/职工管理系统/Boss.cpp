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
	cout << "ְ����ţ�" << this->Worker_ID
		<< "\tְ��������" << this->Worker_Name
		<< "\tְ����λ��" << this->Get_Department()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::Get_Department()
{
	return string("�ܲ�");
}