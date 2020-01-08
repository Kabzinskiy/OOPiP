#include <iostream>
using namespace std;


class student                         // ��������� ����� "student"
{
private:                               
	                                  // ������� 3 ��������� ����������, � ������� �� ������ �������� ���, ���� � ��� ��������
	char *name;                       // ������ ���������� ������������ ����� ��������� �� ������ �����, ���� �� ����� ���������� ����-��� �������
	int	course;                       // ������ ���������� - ������� int
	bool male;                        // ������ ���������� �������� �������

public:
	student();                        // �������� ������������ ��� ����������       
	student(char *, int, bool);       // �������� ������������ � �����������
	student(student  &);              // �������� ������������ �����������
	~student();                       // �������� �����������

	void print_student();             // �������� ������, ������������ ����� ������ ������� ������ "student" �� �����

	void set_name(char *);            // ��������� �������, ������� ��������� ���������� �������� �������
	void set_course(int );
	void set_male(bool );


	char* get_name();                 // �������� �������, ������� ��������� �������� ��������� ������� 
	int get_course();
	bool get_male();
};



student::student()                   // ���������� ������������ ��� ����������
{
	name = new char[strlen("noname")+1];               // �������� ������ ��� ������� �����
	strcpy_s(this->name, strlen("noname")+1, "noname"); // ��������� ������ �������������� ������
	course = 0;                                         // �������������� ���������� ����� � ����
	male = false;
	                                                 // ������� �� ����� ������������ �����������, ����� � ��� �������
	cout << "Called constructor without parameters for student " << this->name << " "  << this << endl; 
}

student::student(char *name, int course, bool male) // ���������� ������������ � �����������
{
	this->name = new char[strlen(name) + 1];         // �������� ������ ��� ������� �����
	strcpy_s(this->name, strlen(name) + 1, name);    // ��������� ������ �������������� ������
	this->course = course;                           // �������������� ���������� ����� � ����
	this->male = male;
	                                                 // ������� �� ����� ������������ �����������, ����� � ��� �������
	cout << "Called constructor with parameters for student " << this->name << " " << this << endl;
}

student::student(student  &otherStudent)               // ���������� ������������ �����������
{
	this->name = new char[strlen(otherStudent.name) + 1];   // �������� ������ ��� ������� ����� 
	strcpy_s(this->name, strlen(otherStudent.name) + 1, otherStudent.name);  // ��������� ������ �������������� ������
	this->course = otherStudent.course;              // �������������� ���������� ����� � ����
	this->male = otherStudent.male;
	                                                 // ������� �� ����� ������������ �����������, ����� � ��� �������
	cout << "Called constructor of copy for student " << this->name << " " << this << endl;
}

student::~student()                                  // ���������� ����������� �����������
{                                    
	                                       // ������� �� ����� ������������ ����������, ����� � ��� ���������� �������
	cout << "Called destruktor for student " << this->name << " " << this << endl;
	delete name;                           // ��������������� ������� ������
}



void student::print_student()              // ��������� ����� ������ ���������� ������� �� �������
{
	cout << "Name: " << name << endl;
	cout << "Course: " << course << endl;
	cout << "Male: " << male << endl;
}



void student::set_name(char *name)         // ��������� ����� ��� ������ ���� � ������ �������
{
	this->name = new char[strlen(name) + 1];  // �������� ������ ��� ������� �����
	strcpy_s(this->name, strlen(name) + 1, name);  // ��������� ������ ����� �����-������
}

void student::set_course(int course)       // ��������� ����� ��� ������ ���� ����� �������
{
	this->course = course;
}

void student::set_male(bool male)         // ��������� ����� ��� ������ ���� �������
{
	this->male = male;
}



char* student::get_name()                 // ��������� ����� ��������� ���� � ������ �������
{
	return name;
}

int student::get_course()                 // ��������� ����� ��� ��������� ����-����� �������
{
	return course;
}

bool student::get_male()                  // ��������� ����� ��� ��������� � ������ �������
{
	return male;
}




void main_func()                          // �������, ����������� ��� �����, ��� ���������� � ������
{
	student stud1, stud2("Masha", 3, 1), stud3(stud2); // ������� ��� ������� � �������������� �� ������� ���������
	stud1.print_student();                             // ������� �� �� ������� ��� ������ ������������ ������
	stud2.print_student();
	stud3.print_student();
	stud3.set_course(2);                               // ������ ��������� ������� ��� ������ �������, ��������������� ��������� �������
	stud3.set_male(1);
	stud3.set_name("Jenya");

	// ������� �� �� ����� ��� ������ ���-�������, ��� �� ��������
	cout << stud3.get_name() << " " << stud3.get_course() << " " << stud3.get_male() << endl; 
	// ��� ��������� ������ ������� ���������� ��������� �������������
}




int main()
{
	main_func();     // �������� ����������� �������
	system("pause");
	return 0;
}