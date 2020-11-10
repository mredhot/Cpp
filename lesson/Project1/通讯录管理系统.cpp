#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

void showmenu()
{
	cout << "*******************************" << endl;
	cout << "*****    1. �����ϵ��    *****" << endl;
	cout << "*****    2. ��ʾ��ϵ��    *****" << endl;
	cout << "*****    3. ɾ����ϵ��    *****" << endl;
	cout << "*****    4. ������ϵ��    *****" << endl;
	cout << "*****    5. �޸���ϵ��    *****" << endl;
	cout << "*****    6. �����ϵ��    *****" << endl;
	cout << "*****    0. �˳�ͨѶ¼    *****" << endl;
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
			cout << "�Ѿ��ﵽ���洢�����������Ҫ����ϵ��" << endl;
			break;
		}
		else {
			// ����
			string name;
			cout << "��������ϵ������: " << endl;
			cin >> name;
			abs->personArray[abs->m_Size].m_Name = name;
			// �Ա�
			int sex;
			cout << "��������ϵ���Ա�: 1 --- �У�2 --- Ů " << endl;
			cin >> sex;
			while (true)
			{
				if (sex == 1 || sex == 2) {
					abs->personArray[abs->m_Size].m_Sex = sex;
					break;
				}
				else {
					cout << "������������������" << endl;
					cin >> sex;
				}
			}
			// ����
			int age;
			cout << "����������:  " << endl;
			cin >> age;
			abs->personArray[abs->m_Size].m_Age = age;
			// ��ϵ�绰
			string phone;
			cout << "��������ϵ�绰:  " << endl;
			cin >> phone;
			abs->personArray[abs->m_Size].m_Phone = phone;
			// ��ͥ��ַ
			string address;
			cout << "�������ͥסַ:  " << endl;
			cin >> address;
			abs->personArray[abs->m_Size].m_Address = address;
			cout << "¼��ɹ�!" << endl;
			// ������ϵ��
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
		cout << "ͨѶ¼��û����ϵ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�: " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů")<< "\t";
			cout << "����: " << abs->personArray[i].m_Age << "\t";
			cout << "��ϵ�绰: " << abs->personArray[i].m_Phone << "\t";
			cout << "��ͥסַ:  " << abs->personArray[i].m_Address << endl;
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
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ������:  " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "����:  " << abs->personArray[ret].m_Name << "\t"
			<< "�Ա�:  " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů")	<< "\t"
			<< "����:  " << abs->personArray[ret].m_Age	<< "\t"
			<< "��ϵ�绰:  " << abs->personArray[ret].m_Phone	<< "\t"
			<< "��ͥסַ:  " << abs->personArray[ret].m_Address
			<< endl;
	}
	else {
		cout << "���޴���!" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ������:  " << endl;
	string  name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {

		cout << "�޸���ϵ������:  " << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�޸���ϵ���Ա�: 1 --- ��  2 --- Ů " << endl;
		int sex;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "�������������Ƿ�����" << endl;
			}
		}

		cout << "�޸���ϵ�绰:  " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "�޸ļ�ͥסַ:  " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;

		cout << "�޸ĳɹ�!" << endl;
	}
	else {
		cout << "��ͨѶ¼��û���ҵ�����ϵ��!" << endl;
	}
	system("pause");
	system("cls");

}
void clearPerson(Addressbooks* abs)
{
	cout << "��ȷ�������ϵ����? 1 --- ȷ��  2 --- ȡ��" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1) {
			abs->m_Size = 0;
			cout << "ͨѶ¼�����" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 2) {
			cout << "��ѡ����ȡ��" << endl;
			break;

		}
		else {
			cout << "�������������Ƿ�����" << endl;
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
		showmenu(); // ��ʾ�˵�
		cin >> select;
		switch (select)
		{
		case 1: // �����ϵ��
			Addperson(&abs);
			break;
		case 2: // ��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3: // ɾ����ϵ�� 
		/*{
			cout << "������Ҫ���ҵ���ϵ������:  " << endl;
			string name;  
			cin >> name;
			isExist(&abs, name);
			if (isExist(&abs, name) == -1) {
				cout << "��ͨѶ¼��û���ҵ�����ϵ��" << endl;
			}
			else
			{
				cout << "�ҵ�����!" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4: // ������ϵ��
			findPerson(&abs);
			break;
		case 5: // �޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: // �����ϵ��
			clearPerson(&abs);
			break;
		case 0: // �˳�ͨѶ¼
			system("pause");
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}
	}





	


	system("pause"); //���д���ʵ�� ����������� ����
	return 0;
}

