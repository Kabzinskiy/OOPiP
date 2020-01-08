#include <iostream>
using namespace std;


class student                         // реализуем класс "student"
{
private:                               
	                                  // создаем 3 приватные переменные, в которые мы сможем записать имя, курс и пол студента
	char *name;                       // первая переменная представляет собой указатель на массив чаров, куда мы будем записывать поле-имя объекта
	int	course;                       // вторая переменная - обычный int
	bool male;                        // третья переменная является булевой

public:
	student();                        // прототип конструктора без параметров       
	student(char *, int, bool);       // прототип конструктора с параметрами
	student(student  &);              // прототип конструктора копирования
	~student();                       // прототип деструктора

	void print_student();             // прототип метода, выполняющего вывод данных объекта класса "student" на экран

	void set_name(char *);            // прототипы методов, которые позволяют установить значения объекту
	void set_course(int );
	void set_male(bool );


	char* get_name();                 // прототип методов, которые позволяют получить параметры объекта 
	int get_course();
	bool get_male();
};



student::student()                   // реализация конструктора без параметров
{
	name = new char[strlen("noname")+1];               // выделяем память для массива чаров
	strcpy_s(this->name, strlen("noname")+1, "noname"); // заполняем массив предполагаемым именем
	course = 0;                                         // инициализируем переменные курса и пола
	male = false;
	                                                 // выводим на экран используемый конструктор, адрес и имя объекта
	cout << "Called constructor without parameters for student " << this->name << " "  << this << endl; 
}

student::student(char *name, int course, bool male) // реализация конструктора с параметрами
{
	this->name = new char[strlen(name) + 1];         // выделяем память для массива чаров
	strcpy_s(this->name, strlen(name) + 1, name);    // заполняем массив предполагаемым именем
	this->course = course;                           // инициализируем переменные курса и пола
	this->male = male;
	                                                 // выводим на экран используемый конструктор, адрес и имя объекта
	cout << "Called constructor with parameters for student " << this->name << " " << this << endl;
}

student::student(student  &otherStudent)               // реализация конструктора копирования
{
	this->name = new char[strlen(otherStudent.name) + 1];   // выделяем память для массива чаров 
	strcpy_s(this->name, strlen(otherStudent.name) + 1, otherStudent.name);  // заполняем массив предполагаемым именем
	this->course = otherStudent.course;              // инициализируем переменные курса и пола
	this->male = otherStudent.male;
	                                                 // выводим на экран используемый конструктор, адрес и имя объекта
	cout << "Called constructor of copy for student " << this->name << " " << this << endl;
}

student::~student()                                  // реализация деструктора копирования
{                                    
	                                       // выводим на экран используемый деструктор, адрес и имя удаляемого объекта
	cout << "Called destruktor for student " << this->name << " " << this << endl;
	delete name;                           // непосредственно удаляем память
}



void student::print_student()              // реализуем метод вывода параметров объекта на монитор
{
	cout << "Name: " << name << endl;
	cout << "Course: " << course << endl;
	cout << "Male: " << male << endl;
}



void student::set_name(char *name)         // реализуем метод для замены поля с именем объекта
{
	this->name = new char[strlen(name) + 1];  // выделяем память для массива чаров
	strcpy_s(this->name, strlen(name) + 1, name);  // заполняем массив новым полем-именем
}

void student::set_course(int course)       // реализуем метод для замены поля курса объекта
{
	this->course = course;
}

void student::set_male(bool male)         // реализуем метод для замены пола объекта
{
	this->male = male;
}



char* student::get_name()                 // реализуем метод получения поля с именем объекта
{
	return name;
}

int student::get_course()                 // реализуем метод для получения поля-курса объекта
{
	return course;
}

bool student::get_male()                  // реализуем метод для получения с именем объекта
{
	return male;
}




void main_func()                          // функция, проверяющая наш класс, его реализацию и методы
{
	student stud1, stud2("Masha", 3, 1), stud3(stud2); // создаем три объекта и инициализируем их разными способами
	stud1.print_student();                             // выводим их на монитор при помощи специального метода
	stud2.print_student();
	stud3.print_student();
	stud3.set_course(2);                               // меняем параметры объекта при помощи методов, устанавливающих параметры объекта
	stud3.set_male(1);
	stud3.set_name("Jenya");

	// выводим их на экран при помощи гет-методов, для их проверки
	cout << stud3.get_name() << " " << stud3.get_course() << " " << stud3.get_male() << endl; 
	// при окончании работы функции деструктор сработает автоматически
}




int main()
{
	main_func();     // вызываем проверяющую функцию
	system("pause");
	return 0;
}