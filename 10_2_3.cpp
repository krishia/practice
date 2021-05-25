#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
	string Name;
	int Number;
	string Major;
	vector<string> Subject;
	vector<char> Grade;
	
public:
	Student(string name_, int number_, string major_) {
		Name = name_;
		Number = number_;
		Major = major_;
		
	}
	Student() :Name("default"), Number(0), Major("depart") {}
	void setName(string name_) {
		Name = name_;
	}
	void setID(int number_) {
		Number = number_;
	}
	void setDpt(string major_) {
		Major = major_;
	}

	void print() {
		cout << Name << " " << Number << " " << Major << endl;
	}


	void addGrade(string subject, char grade) {
		Subject.push_back(subject);
		Grade.push_back(grade);
	}

	void printGrades() {
		int length = Subject.size();
		for (int i = 0; i < length; ++i) {
			cout << Subject[i] << " " << Grade[i] << endl;
		}

		cout << "GPA : "<<getGPA(Grade) << endl;
	}

	float getGPA(const vector<char> grade){
		float sum = 0;
		int length = 0;
		int point = 0;

		for (auto elem:grade) {
			switch (elem) {
			case 'A':
				point = 4;
				break;
			case 'B':
				point = 3;
				break;
			case 'C':
				point = 2;
				break;
			case 'D':
				point = 1;
				break;
			case 'F':
				point = 0;
				break;
			}
			sum += point;
			++length;
		}

		return (float)(sum / length);
	}

	void getYear(int year) {
		int calc_num = Number / 1000000;

		int grade_old = year - calc_num;

		switch (grade_old) {
		case 1:
			cout << "Freshmen(1학년)" << endl;
			break;
		case 2:
			cout << "Sophomore(2학년)" << endl;
			break;
		case 3:
			cout << "Junior(3학년)" << endl;
			break;
		case 4:
			cout << "Senior(4학년)" << endl;
			break;
		case 5:
			cout << "About to graduate(5학년 이상)" << endl;
			break;
		}
	}
}; 
int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}
