#include<iostream>
#include<string>
using namespace std;

class CStudent {
	int Number;
	string Name;
	string Major;
public:
	CStudent() { Number = 2018000000, Name = "홍길동", Major = "컴퓨터공학과"; }
	CStudent(int Number_, string Name_, string Major_) { Number = Number_, Name = Name_, Major = Major_; }

	void setNumber(int Number_) {
		Number = Number_;
	}
	void setName(string Name_) {
		Name = Name_;
	}
	void setMajor(string Major_) {
		Major = Major_;
	}

	int getNumber() {
		return Number;
	}
	string getName() {
		return Name;
	}
	string getMajor() {
		return Major;
	}

	void Display() {
		cout << "학번 :" <<Number<< endl;
		cout << "이름 :" <<Name<< endl;
		cout << "전공 :" <<Major << endl;
		cout << endl;
	}
};
int main() {
	CStudent s[3]; // 3명의 학생정보를 저장할 class 배열
	int inputNumber; // 키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
	int length = 0; // 현재 입력된 학생의 수
	CStudent s1, s2, s3;
	while (1) {
		cout << length + 1 << "번째 학생 입력: " << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;
		if (length == 0) {
			s1.setNumber(inputNumber);
			s1.setName(inputName);
			s1.setMajor(inputMajor);
			cout << "※입력완료" << endl;
			s[0] = s1;
		}
		else if (length == 1) {
			if (s1.getNumber() == inputNumber) {
				cout << "중복된 학번이 존재합니다." << endl;
				cout << endl;
				continue;
			}
			s2.setNumber(inputNumber);
			s2.setName(inputName);
			s2.setMajor(inputMajor);
			cout << "※입력완료" << endl;
			s[1] = s2;
		}
		else if (length == 2) {
			if (s1.getNumber() == inputNumber||s2.getNumber()==inputNumber) {
				cout << "중복된 학번이 존재합니다." << endl;
				cout << endl;
				continue;
			}
			s3.setNumber(inputNumber);
			s3.setName(inputName);
			s3.setMajor(inputMajor);
			cout << "※입력완료" << endl;
			s[2] = s3;
		}
		cout << endl;
		++length;
		
		if (length == 3) {
			break;
		}
	
	}

	cout << "----모든 입력이 완료되었습니다----" << endl;
	cout << "1학생정보" << endl;
	s1.Display();
	cout << endl;
	cout << "2학생정보" << endl;
	s2.Display();
	cout << endl;
	cout << "3학생정보" << endl;
	s3.Display();
	cout << endl;
	return 0;
}




