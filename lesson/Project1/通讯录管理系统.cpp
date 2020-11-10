#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

void showmenu()
{
	cout << "*******************************" << endl;
	cout << "*****    1. 添加联系人    *****" << endl;
	cout << "*****    2. 显示联系人    *****" << endl;
	cout << "*****    3. 删除联系人    *****" << endl;
	cout << "*****    4. 查找联系人    *****" << endl;
	cout << "*****    5. 修改联系人    *****" << endl;
	cout << "*****    6. 清空联系人    *****" << endl;
	cout << "*****    0. 退出通讯录    *****" << endl;
	cout << "*******************************" << endl;
}
struct person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;
};
struct Addressbooks {
	struct person personArray[MAX];
	int m_Size;
};
void Addperson(Addressbooks *abs)
{
	while (true)
	{
		if (abs->m_Size == 1000) {
			cout << "已经达到最大存储，请清除不必要的联系人" << endl;
			break;
		}
		else {
			// 姓名
			string name;
			cout << "请输入联系人姓名: " << endl;
			cin >> name;
			abs->personArray[abs->m_Size].m_Name = name;
			// 性别
			int sex;
			cout << "请输入联系人性别: 1 --- 男，2 --- 女 " << endl;
			cin >> sex;
			while (true)
			{
				if (sex == 1 || sex == 2) {
					abs->personArray[abs->m_Size].m_Sex = sex;
					break;
				}
				else {
					cout << "输入有误，请重新输入" << endl;
					cin >> sex;
				}
			}
			// 年龄
			int age;
			cout << "请输入年龄:  " << endl;
			cin >> age;
			abs->personArray[abs->m_Size].m_Age = age;
			// 联系电话
			string phone;
			cout << "请输入联系电话:  " << endl;
			cin >> phone;
			abs->personArray[abs->m_Size].m_Phone = phone;
			// 家庭地址
			string address;
			cout << "请输入家庭住址:  " << endl;
			cin >> address;
			abs->personArray[abs->m_Size].m_Address = address;
			cout << "录入成功!" << endl;
			// 更新联系人
			abs->m_Size++;
			system("pause");
			system("cls");
			break;
		}
	}
}
void showperson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0) {
		cout << "通讯录中没有联系人" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女")<< "\t";
			cout << "年龄: " << abs->personArray[i].m_Age << "\t";
			cout << "联系电话: " << abs->personArray[i].m_Phone << "\t";
			cout << "家庭住址:  " << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人姓名:  " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名:  " << abs->personArray[ret].m_Name << "\t"
			<< "性别:  " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女")	<< "\t"
			<< "年龄:  " << abs->personArray[ret].m_Age	<< "\t"
			<< "联系电话:  " << abs->personArray[ret].m_Phone	<< "\t"
			<< "家庭住址:  " << abs->personArray[ret].m_Address
			<< endl;
	}
	else {
		cout << "查无此人!" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人名字:  " << endl;
	string  name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {

		cout << "修改联系人姓名:  " << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "修改联系人性别: 1 --- 男  2 --- 女 " << endl;
		int sex;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "请检查您的输入是否有误" << endl;
			}
		}

		cout << "修改联系电话:  " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "修改家庭住址:  " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;

		cout << "修改成功!" << endl;
	}
	else {
		cout << "在通讯录中没有找到此联系人!" << endl;
	}
	system("pause");
	system("cls");

}
void clearPerson(Addressbooks* abs)
{
	cout << "您确定清空联系人吗? 1 --- 确定  2 --- 取消" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1) {
			abs->m_Size = 0;
			cout << "通讯录已清空" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 2) {
			cout << "您选择了取消" << endl;
			break;

		}
		else {
			cout << "请检查您的输入是否有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showmenu(); // 显示菜单
		cin >> select;
		switch (select)
		{
		case 1: // 添加联系人
			Addperson(&abs);
			break;
		case 2: // 显示联系人
			showperson(&abs);
			break;
		case 3: // 删除联系人 
		/*{
			cout << "请输入要查找的联系人姓名:  " << endl;
			string name;  
			cin >> name;
			isExist(&abs, name);
			if (isExist(&abs, name) == -1) {
				cout << "在通讯录中没有找到此联系人" << endl;
			}
			else
			{
				cout << "找到此人!" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4: // 查找联系人
			findPerson(&abs);
			break;
		case 5: // 修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 清空联系人
			clearPerson(&abs);
			break;
		case 0: // 退出通讯录
			system("pause");
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}





	


	system("pause"); //这行代码实现 按任意键继续 功能
	return 0;
}

