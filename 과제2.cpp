#include <iostream>
#include<string>
using namespace std;

class PhoneBook
{
private:
	string number;   // 전화번호
	string name;     // 이름
public:
	PhoneBook();     // 생성자
	void setPnum(string number);    // 전화번호 저장
	void setName(string name);      // 이름 저장
	void addPhone(string name, string number);    // 이름, 전화번호 저장
	string getPnum();     // 전화번호 가져오기
	string getName();     // 이름 가져오기
	void editPnum(string number);     // 전화번호 수정
};

class PhoneBookManager
{
private:
	PhoneBook* phoneB;    // 객체 배열 생성을 위한 선언
	int size;    // 객체 배열의 크기
public:
	PhoneBookManager(int num);    // 생성자 - PhoneBook으로 객체 배열 생성
	void showAll();       // 전화번호부 목록 보기
	void searchPnum();    // 전화번호 찾기
	void addPnum();       // 전화번호 객체 추가 생성(배열의 원소 개수 +1 되어야 한다)
	void editPnum();      // 전화번호 수정
};

int main()
{
	int num;       // 전화번호 수
	int list = 0;  // 무슨 작업 할 지 선택 

	cout << " --- SWING 전화번호부 ---" << endl;
	cout << "저장할 전화번호의 수를 입력해주세요 >> ";
	cin >> num;
	PhoneBookManager manager(num);
	while (list != 5)   // 5번 선택하기 전까지 반복
	{
		cout << endl << " --- SWING 전화번호부 --- " << endl;
		cout << "1. 전화번호부 보기" << endl;
		cout << "2. 전화번호 검색" << endl;
		cout << "3. 전화번호 추가하기" << endl;
		cout << "4. 전화번호 수정하기" << endl;
		cout << "5. 종료" << endl;

		cout << "번호를 입력해주세요 >> ";
		cin >> list;

		switch (list)
		{
		case 1: manager.showAll(); break;  // 전화번호 목록 보기
		case 2: manager.searchPnum(); break;   // 전화번호 찾기
		case 3: manager.addPnum(); break;   // 전화번호 추가
		case 4: manager.editPnum(); break;   // 전화번호 수정
		case 5: cout << endl << endl << "프로그램을 종료합니다." << endl; break;  // 전화번호부 종료
		default: cout << endl << endl << "잘못 입력하셨습니다." << endl;   // 1~5 이외의 숫자 입력할 경우
		}
	}
}

PhoneBook::PhoneBook()
{}

void PhoneBook::setPnum(string number)   // 전화번호 저장
{
	this->number = number;
}

void PhoneBook::setName(string name)   // 이름 저장
{
	this->name = name;
}

void PhoneBook::addPhone(string name, string number)   // 이름과 전화번호 저장
{
	this->number = number;
	this->name = name;
}

string PhoneBook::getPnum()   // 전화번호 가져오기
{
	return number;
}

string PhoneBook::getName()  // 이름 가져오기
{
	return name;
}

void PhoneBook::editPnum(string number)   // 전화번호 수정하기
{
	this->number.replace(0, 13, number); //  0~13까지의 인자를, 입력받은 전화번호로 수정
}

PhoneBookManager::PhoneBookManager(int num)
{
	int i;
	string name, number;
	size = num; 
	phoneB = new PhoneBook[size]; // size만큼 객체 배열을 동적으로 생성

	for (i = 0; i < num; i++) // 이름, 전화번호 입력
	{
		cout << i + 1 << "번째 사람의 이름을 입력해주세요 >> ";
		cin >> name;
		phoneB[i].setName(name);
		cout << i + 1 << "번째 사람의 전화번호를 입력해주세요 >> ";
		cin >> number;
		phoneB[i].setPnum(number);
		cout << endl;
	}
}

void PhoneBookManager::showAll()   // 전화번호부 목록 보기
{
	cout << endl << endl;
	int i;
	for (i = 0; i < size; i++)   // 반복문으로 이름과 전화번호 출력
	{
		cout << i + 1 << ". " << phoneB[i].getName();   //이름
		cout << "::" << phoneB[i].getPnum() << endl;    // 전화번호
	}
}

void PhoneBookManager::searchPnum()   // 전화번호 찾기
{
	int i, k = 100;
	string search;
	cout << endl << endl << "누구의 번호를 검색하겠습니까? >> ";
	cin >> search;
	for (i = 0; i < size; i++)
	{
		if (search == phoneB[i].getName())   // 입력한 이름이 같다면
			k = i; // 입력한 이름의 인덱스 값을 k에 대입
	}

	if (k < size) // k가 size보다 작으면 해당하는 인덱스 값의 전화번호 출력
		cout << phoneB[k].getName() << "님의 전화번호 : " << phoneB[k].getPnum() << endl;

	if (k == 100) // k값이 바뀌지 않는다면, 해당하는 이름이 없는 것
		cout << "연락처가 존재하지 않습니다." << endl;
}

void PhoneBookManager::addPnum()  // 전화번호 추가
{
	string n_name, n_number;   // 추가할 이름과 전화번호
	int i;

	cout << endl << endl << "이름을 입력해주세요 >> ";
	cin >> n_name;  // 추가할 사람의 이름
	cout << "전화번호를 입력해주세요 >> ";
	cin >> n_number;   // 추가할 사람의 전화번호

	PhoneBook* tmp = new PhoneBook[size + 1]; // 임시 객체 배열 tmp를 생성한다

	for (i = 0; i < size; i++) 
		tmp[i] = phoneB[i];   // tmp 배열에 phoneB 배열을 복사한다

	delete[] phoneB; // phoneB 배열 메모리를 반환한다
	size++;   // size = size + 1 -> 1씩 증가

	phoneB = new PhoneBook[size]; //  1 증가된 size로 다시 메모리에 할당
	for (i = 0; i < size; i++) 
		phoneB[i] = tmp[i];   // phoneB 배열에 tmp 배열을 복사한다

	phoneB[size - 1].addPhone(n_name,n_number); // 전화번호 추가

	cout << "전화번호가 추가되었습니다." << endl;
}

void PhoneBookManager::editPnum()   // 전화번호 수정
{
	int i, k = 100;
	string e_name, e_number;   // 수정할 사람의 이름과 전화번호
	cout << endl << endl << "누구의 번호를 수정하겠습니까? >> ";
	cin >> e_name;  // 수정할 사람의 이름 입력
	for (i = 0; i < size; i++)
	{
		if (e_name == phoneB[i].getName())  
			k = i; // 입력한 이름의 인덱스 값을 k에 대입
	}

	if (k < size) // k가 size보다 작으면 해당하는 인덱스 값의 전화번호를 수정할 수 있도록
	{
		cout << "변경할 번호를 입력해주세요 >> ";
		cin >> e_number;  // 수정할 사람의 전화번호 입력
		phoneB[k].editPnum(e_number);
		cout << "전화번호가 변경되었습니다." << endl;
	}

	if (k == 100)     //k값이 바뀌지 않는다면, 해당하는 이름이 없는 것
		cout << "연락처가 존재하지 않습니다." << endl;
}