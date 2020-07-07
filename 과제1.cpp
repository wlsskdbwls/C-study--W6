#include <iostream>
#include <string>
using namespace std;

class ATM
{
private:
	string name;    // ������ �̸�
	int pw = 0;     // ���� ��й�ȣ
	int money = 0;  // ���� �ܾ�
	int confirm = 0;  // ���� ��й�ȣ Ȯ��

public:
	ATM();    // ������
	void deposit();    // �Ա�
	void withdraw();    // ����
	void send(string receiver, int sendMon);    // ��ü - ����
	void receive(int receiveMon);   // ��ü - ����
	int getMoney();    // �� �ִ��� ���
	string getName();    // �̸� �ҷ�����

	void setName();    // ������ �̸� �Է�
	void setPw();    // ������ ��й�ȣ �Է�
	void setMoney();    // ������ �ܾ� �Է�
	void pwConfirm();    // ��й�ȣ ��Ȯ��
	void pwConfirm2();
};

int main()
{
	int num;    // ������ �ο� ��
	int i, j, k = 100, m = 100;
	string Name = " ";    // �̸�
	string receiver = " ";
	int number;   // ��ȣ ����
	int sendMoney;    // ���� �ݾ�

	cout << "���࿡ ������ �ο��� �Է����ּ��� > ";
	cin >> num;
	ATM* account = new ATM[num];    // �ο� ����ŭ ��ü �迭�� ���� ����

	for (i = 0; i < num; i++)
	{
		cout << endl << i + 1 << "��° �մ�" << endl << endl;
		cout << "������ �����ֽʽÿ� >> ";
		(account + i)->setName();   // ������ �̸�
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		(account + i)->setPw();    // ������ ��й�ȣ
		cout << "�� �� �� �Է����ּ��� >> ";
		(account + i)->pwConfirm();   // ��й�ȣ ��Ȯ��
		cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
		(account + i)->setMoney();   // ������ �ܾ�
		cout << endl;
	}

	while (1)
	{
		while (1)
		{
			cout << endl << " --- SWING ATM ---" << endl;
			cout << "������ �Է����ּ��� (������ x�� �Է����ּ���) >> ";
			cin >> Name;

			if (Name == "x") // x �Է� �� �ش��ϴ� while�� Ż��
				break;

			k = 100;   // k���� �ʱ�ȭ
			for (j = 0; j < num; j++)
			{
				if (Name == (account + j)->getName())
					k = j;    // �Է��� �̸��� �������� �̸��� ������ �ش� �ε��� ���� k�� ����
			}
			
			if (k == 100 && Name != "x")   // Name != "x"�� �߰��Ͽ� �Ʒ� ������ ��µ��� �ʵ��� �Ѵ�.
				cout << "�������� �ʴ� �������Դϴ�." << endl;    // �Է��� �̸��� �������� ������, ������ ���� ���� ���
			else
				break;   // ������ �̸��� �����ϸ� �������� �Ѿ
		}

		if (Name == "x")    // while������ �������� ��, x�� �ԷµǸ� ���� while�� Ż���Ͽ� ���α׷��� ����
			break;

		number = 0;  

		while (number != 5)   // 5���� ���� ������ �ݺ�
		{
			cout << endl << " --- SWING ATM " << (account + k)->getName() << "�� ---" << endl;
			cout << "1. �Ա�" << endl;
			cout << "2. ����" << endl;
			cout << "3. ��ü" << endl;
			cout << "4. �ܾ� Ȯ��" << endl;
			cout << "5. ����" << endl << endl;
			cout << "��ȣ�� �������ּ��� >> ";
			cin >> number;   // �۾��� ��ȣ �Է�

			switch (number)  // 1~5 �߿� ����
			{
			case 1:   // �Ա�
			{
				cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
				(account + k)->deposit();   // �Ա��� �ݾ�
				cout << endl << "���� " << (account + k)->getName() << "���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl;  //  �ܾ� ���
				break;
			}
			case 2:   // ����
			{
				cout << "�󸶸� �����Ͻðڽ��ϱ�? >> ";
				(account + k)->withdraw();   // ������ �ݾ�
				cout << "��й�ȣ�� �Է����ּ��� >> ";
				(account + k)->pwConfirm2();
				cout << endl << "���� " << (account + k)->getName() << "���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl;   // �ܾ� ���
				break;
			}
			case 3:   // ��ü
			{
				cout << "�������� �����ڽ��ϱ�? >> ";
				cin >> receiver;   // ��ü�� ���

				m = 100; // m�� �ʱ�ȭ

				for (j = 0; j < num; j++)
				{
					if (receiver == (account + j)->getName())
						m = j;    // �Է��� �̸��� �������� �̸��� ������ �ش� �ε��� ���� m�� ����
				}

				if (m == 100)  // �Է��� �̸��� �������� ���� ���
					break;

				cout << "�󸶸� �����ڽ��ϱ�? >> ";
				cin >> sendMoney;  // ���� �ݾ�
				(account + k)->send((account + m)->getName(), sendMoney);
				cout << "��й�ȣ�� �Է����ּ��� >> ";
				(account + k)->pwConfirm2();   // ��й�ȣ �Է�
				cout << endl << (account + m)->getName() << "�Բ� " << sendMoney << "���� ���½��ϴ�." << endl;
				(account + m)->receive(sendMoney);
				cout << endl << "���� " << (account + k)->getName() << "���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl;   // �ܾ� ���
				break;
			}
			case 4:  // �ܾ� Ȯ��
				cout << (account + k)->getName() << "���� ���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl; break;
			case 5: break;   // ���α׷� ����
			}
		}
	}

	cout << "ATM�� �����մϴ�." << endl;

	return 0;
}

ATM::ATM()
{};

void ATM::deposit()   // �Ա�
{
	int dep;
	cin >> dep;   // �Ա��� �ݾ� �Է�
	money += dep;   // �⺻�� ���� �Ա��� �ݾ� ����
}

void ATM::withdraw()   // ����
{
	int wit;    
	cin >> wit;    // ������ �ݾ� �Է�
	money -= wit;   // �⺻�� ���� ������ �ݾ� ��
}

void ATM::send(string receiver, int sendMon)   // ��ü - ����
{
	money -= sendMon;   
}

void ATM::receive(int receiveMon)   //��ü - ����
{
	money += receiveMon;
}

int ATM::getMoney()   // �� �ִ��� ���
{
	return money;
}

string ATM::getName()   // �̸� �ҷ�����
{
	return name;
}

void ATM::setName()   // ������ �̸�
{
	cin >> name;
}
 
void ATM::setPw()   // ������ ��й�ȣ
{
	cin >> pw;
}

void ATM::setMoney()  // ������ �ܾ�
{
	cin >> money;
}

void ATM::pwConfirm()   // ��й�ȣ Ȯ��
{
	cin >> confirm;   // ��й�ȣ �Է�

	if (confirm != pw)
	{
		while (confirm != pw) // �Է��� ��й�ȣ�� pw�� �ٸ��� �ݺ�
		{
			cout << "��й�ȣ�� ���� �ٸ��ϴ�." << endl << endl;
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> confirm;
		}
	}
}

void ATM::pwConfirm2()    // ��й�ȣ Ȯ��
{
	cin >> confirm;    // ��й�ȣ �Է�

	if (confirm != pw)
	{
		while (confirm != pw) // �Է��� ��й�ȣ�� pw�� �ٸ��� �ݺ�
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> confirm;
		}
	}
}