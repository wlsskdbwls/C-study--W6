#include <iostream>
#include<string>
using namespace std;

class PhoneBook
{
private:
	string number;   // ��ȭ��ȣ
	string name;     // �̸�
public:
	PhoneBook();     // ������
	void setPnum(string number);    // ��ȭ��ȣ ����
	void setName(string name);      // �̸� ����
	void addPhone(string name, string number);    // �̸�, ��ȭ��ȣ ����
	string getPnum();     // ��ȭ��ȣ ��������
	string getName();     // �̸� ��������
	void editPnum(string number);     // ��ȭ��ȣ ����
};

class PhoneBookManager
{
private:
	PhoneBook* phoneB;    // ��ü �迭 ������ ���� ����
	int size;    // ��ü �迭�� ũ��
public:
	PhoneBookManager(int num);    // ������ - PhoneBook���� ��ü �迭 ����
	void showAll();       // ��ȭ��ȣ�� ��� ����
	void searchPnum();    // ��ȭ��ȣ ã��
	void addPnum();       // ��ȭ��ȣ ��ü �߰� ����(�迭�� ���� ���� +1 �Ǿ�� �Ѵ�)
	void editPnum();      // ��ȭ��ȣ ����
};

int main()
{
	int num;       // ��ȭ��ȣ ��
	int list = 0;  // ���� �۾� �� �� ���� 

	cout << " --- SWING ��ȭ��ȣ�� ---" << endl;
	cout << "������ ��ȭ��ȣ�� ���� �Է����ּ��� >> ";
	cin >> num;
	PhoneBookManager manager(num);
	while (list != 5)   // 5�� �����ϱ� ������ �ݺ�
	{
		cout << endl << " --- SWING ��ȭ��ȣ�� --- " << endl;
		cout << "1. ��ȭ��ȣ�� ����" << endl;
		cout << "2. ��ȭ��ȣ �˻�" << endl;
		cout << "3. ��ȭ��ȣ �߰��ϱ�" << endl;
		cout << "4. ��ȭ��ȣ �����ϱ�" << endl;
		cout << "5. ����" << endl;

		cout << "��ȣ�� �Է����ּ��� >> ";
		cin >> list;

		switch (list)
		{
		case 1: manager.showAll(); break;  // ��ȭ��ȣ ��� ����
		case 2: manager.searchPnum(); break;   // ��ȭ��ȣ ã��
		case 3: manager.addPnum(); break;   // ��ȭ��ȣ �߰�
		case 4: manager.editPnum(); break;   // ��ȭ��ȣ ����
		case 5: cout << endl << endl << "���α׷��� �����մϴ�." << endl; break;  // ��ȭ��ȣ�� ����
		default: cout << endl << endl << "�߸� �Է��ϼ̽��ϴ�." << endl;   // 1~5 �̿��� ���� �Է��� ���
		}
	}
}

PhoneBook::PhoneBook()
{}

void PhoneBook::setPnum(string number)   // ��ȭ��ȣ ����
{
	this->number = number;
}

void PhoneBook::setName(string name)   // �̸� ����
{
	this->name = name;
}

void PhoneBook::addPhone(string name, string number)   // �̸��� ��ȭ��ȣ ����
{
	this->number = number;
	this->name = name;
}

string PhoneBook::getPnum()   // ��ȭ��ȣ ��������
{
	return number;
}

string PhoneBook::getName()  // �̸� ��������
{
	return name;
}

void PhoneBook::editPnum(string number)   // ��ȭ��ȣ �����ϱ�
{
	this->number.replace(0, 13, number); //  0~13������ ���ڸ�, �Է¹��� ��ȭ��ȣ�� ����
}

PhoneBookManager::PhoneBookManager(int num)
{
	int i;
	string name, number;
	size = num; 
	phoneB = new PhoneBook[size]; // size��ŭ ��ü �迭�� �������� ����

	for (i = 0; i < num; i++) // �̸�, ��ȭ��ȣ �Է�
	{
		cout << i + 1 << "��° ����� �̸��� �Է����ּ��� >> ";
		cin >> name;
		phoneB[i].setName(name);
		cout << i + 1 << "��° ����� ��ȭ��ȣ�� �Է����ּ��� >> ";
		cin >> number;
		phoneB[i].setPnum(number);
		cout << endl;
	}
}

void PhoneBookManager::showAll()   // ��ȭ��ȣ�� ��� ����
{
	cout << endl << endl;
	int i;
	for (i = 0; i < size; i++)   // �ݺ������� �̸��� ��ȭ��ȣ ���
	{
		cout << i + 1 << ". " << phoneB[i].getName();   //�̸�
		cout << "::" << phoneB[i].getPnum() << endl;    // ��ȭ��ȣ
	}
}

void PhoneBookManager::searchPnum()   // ��ȭ��ȣ ã��
{
	int i, k = 100;
	string search;
	cout << endl << endl << "������ ��ȣ�� �˻��ϰڽ��ϱ�? >> ";
	cin >> search;
	for (i = 0; i < size; i++)
	{
		if (search == phoneB[i].getName())   // �Է��� �̸��� ���ٸ�
			k = i; // �Է��� �̸��� �ε��� ���� k�� ����
	}

	if (k < size) // k�� size���� ������ �ش��ϴ� �ε��� ���� ��ȭ��ȣ ���
		cout << phoneB[k].getName() << "���� ��ȭ��ȣ : " << phoneB[k].getPnum() << endl;

	if (k == 100) // k���� �ٲ��� �ʴ´ٸ�, �ش��ϴ� �̸��� ���� ��
		cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}

void PhoneBookManager::addPnum()  // ��ȭ��ȣ �߰�
{
	string n_name, n_number;   // �߰��� �̸��� ��ȭ��ȣ
	int i;

	cout << endl << endl << "�̸��� �Է����ּ��� >> ";
	cin >> n_name;  // �߰��� ����� �̸�
	cout << "��ȭ��ȣ�� �Է����ּ��� >> ";
	cin >> n_number;   // �߰��� ����� ��ȭ��ȣ

	PhoneBook* tmp = new PhoneBook[size + 1]; // �ӽ� ��ü �迭 tmp�� �����Ѵ�

	for (i = 0; i < size; i++) 
		tmp[i] = phoneB[i];   // tmp �迭�� phoneB �迭�� �����Ѵ�

	delete[] phoneB; // phoneB �迭 �޸𸮸� ��ȯ�Ѵ�
	size++;   // size = size + 1 -> 1�� ����

	phoneB = new PhoneBook[size]; //  1 ������ size�� �ٽ� �޸𸮿� �Ҵ�
	for (i = 0; i < size; i++) 
		phoneB[i] = tmp[i];   // phoneB �迭�� tmp �迭�� �����Ѵ�

	phoneB[size - 1].addPhone(n_name,n_number); // ��ȭ��ȣ �߰�

	cout << "��ȭ��ȣ�� �߰��Ǿ����ϴ�." << endl;
}

void PhoneBookManager::editPnum()   // ��ȭ��ȣ ����
{
	int i, k = 100;
	string e_name, e_number;   // ������ ����� �̸��� ��ȭ��ȣ
	cout << endl << endl << "������ ��ȣ�� �����ϰڽ��ϱ�? >> ";
	cin >> e_name;  // ������ ����� �̸� �Է�
	for (i = 0; i < size; i++)
	{
		if (e_name == phoneB[i].getName())  
			k = i; // �Է��� �̸��� �ε��� ���� k�� ����
	}

	if (k < size) // k�� size���� ������ �ش��ϴ� �ε��� ���� ��ȭ��ȣ�� ������ �� �ֵ���
	{
		cout << "������ ��ȣ�� �Է����ּ��� >> ";
		cin >> e_number;  // ������ ����� ��ȭ��ȣ �Է�
		phoneB[k].editPnum(e_number);
		cout << "��ȭ��ȣ�� ����Ǿ����ϴ�." << endl;
	}

	if (k == 100)     //k���� �ٲ��� �ʴ´ٸ�, �ش��ϴ� �̸��� ���� ��
		cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}