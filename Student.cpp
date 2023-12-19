#include "Student.h"

Student::Student() {

};

Student::~Student() {
};

Student::Student(const Student& other)
{
	name = other.name;
	group = other.group;
	numOfSubjects = other.numOfSubjects;
	subjects = new Subject[numOfSubjects];
	for (int i = 0; i < numOfSubjects; i++)
	{
		subjects[i].grade = other.subjects[i].grade;
		subjects[i].name_subject = other.subjects[i].name_subject;
	}
}

Student::Student(int val)
{

	int num;
	string text;
	cout << "name: ";
	cin >> text;
	SetName(text);
	cout << "group: ";
	cin >> text;
	SetGroup(text);


	cout << "number subjects: ";
	cin >> num;
	try
	{
		SetNumOfSubjects(num);
	}
	catch (const invalid_argument& ex)
	{
		cout << "You did not enter a number: " << ex.what() << endl;
		cin >> num;
		SetNumOfSubjects(num);

	}
	catch (const exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}
	subjects = new Subject[GetNumOfSubjects()];

	for (int i = 0; i < GetNumOfSubjects(); i++)
	{
		cout << "name subject: ";
		cin >> text;
		string name_sbj = text;

		cout << "grade: ";
		int grd;
		cin >> grd;

		AddSubjectGrade(name_sbj, grd, i);
	}


}
Student Student::operator = (const Student& other)

{
	name = other.name;
	group = other.group;
	numOfSubjects = other.numOfSubjects;
	subjects = new Subject[numOfSubjects];
	for (int i = 0; i < numOfSubjects; i++)
	{
		subjects[i].grade = other.subjects[i].grade;
		subjects[i].name_subject = other.subjects[i].name_subject;
	}
	return*this;

}

void Student::add()
{
	int num;
	string text;
	cout << "name: ";

	cin >> text;
	SetName(text);
	cout << "group: ";
	cin >> text;
	SetGroup(text);


	cout << "number subjects: ";
	cin >> num;
	try
	{
		SetNumOfSubjects(num);
	}
	catch (const invalid_argument& ex)
	{
		cout << "You did not enter a number: " << ex.what() << endl;
		cin >> num;
		SetNumOfSubjects(num);

	}
	catch (const exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}

	subjects = new Subject[GetNumOfSubjects()];

	for (int i = 0; i < GetNumOfSubjects(); i++)
	{
		cout << "name subject: ";
		cin >> text;
		string name_sbj = text;
		cout << "grade: ";
		int grd;
		cin >> grd;

		AddSubjectGrade(name_sbj, grd, i);
	}
}


void Student::AddSubjectGrade(string name_subject, int grade, int num)
{
	this->subjects[num].name_subject = name_subject;
	this->subjects[num].grade = grade;
}

void Student::SetName(string name) { this->name = name; };

void Student::SetGroup(string group) { this->group = group; };

void Student::SetNumOfSubjects(int number_subjects) { this->numOfSubjects = number_subjects; };



string Student::GetName() { return name; }

string Student::GetGroup() { return group; };

int Student::GetNumOfSubjects() { return numOfSubjects; };


void Student::Show()
{
	cout << "name: " << GetName() << endl;
	cout << "group: " << GetGroup() << endl;
	cout << "subjects: " << endl;
	for (int i = 0; i < GetNumOfSubjects(); i++)
		cout << subjects[i].name_subject << ": " << subjects[i].grade << endl;

}

ostream& operator <<(ostream& os, const Student& el)
{
	os << el.name << ' ' << el.group << endl;
	for (int i = 0; i < el.numOfSubjects; i++)
	{
		os << "subject: " << el.subjects[i].name_subject << endl << " Grade: " << el.subjects[i].grade << endl;//tyt menyti vivod
	}
	os << endl;
	return os;
}


istream& operator >>(istream& os, Student& el)
{
	string buf, buf2;
	int num;
	int grd;
	cout << "Input name" << endl;
	os >> buf;
	el.name = buf;

	cout << "group" << endl;
	os >> buf;
	el.group = buf;


	cout << "number subject" << endl;
	os >> num;
	try
	{
		el.numOfSubjects = num;
	}
	catch (const invalid_argument& ex)
	{
		cout << "You did not enter a number: " << ex.what() << endl;
		el.numOfSubjects = 0;

	}
	catch (const exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}


	el.subjects = new Subject[el.numOfSubjects];
	for (int i = 0; i < el.numOfSubjects; i++)
	{
		cout << "name_subject" << endl;
		os >> buf2;

		el.subjects[i].name_subject = buf2;


		cout << "grade" << endl;
		os >> grd;
		el.subjects[i].grade = grd;

	}
	return os;
}
float Student::CalculateAverage()
{
	float sum = 0;
	float average = 0;

	for (int i = 0; i < GetNumOfSubjects(); i++)
	{
		sum += subjects[i].grade;
	}
	average = sum / GetNumOfSubjects();

	return average;
}
void Student::Edit()
{
	Show();
	cout << "What change?: " << endl << "1. name" << endl << "2. group" << endl << "3. subjects" << endl;
	int number_change;
	string text;
	cout << endl << "number: ";
	cin >> number_change;
	switch (number_change)
	{
	case 1:
	{
		cout << "name: ";
		cin >> text;
		SetName(text);
		break;
	}
	case 2:
	{
		cout << "group: ";
		cin >> text;
		SetGroup(text);
		break;
	}

	case 3:
	{
		int newNum;
		cout << "number subjects: ";
		cin >> newNum;
		SetNumOfSubjects(newNum);
		for (int i = 0; i < GetNumOfSubjects(); i++)
		{
			cout << "name subject: ";
			cin >> text;
			string name_sbj = text;
			cout << "grade: ";
			int grd;
			cin >> grd;

			AddSubjectGrade(name_sbj, grd, i);
		}

		break;
	}
	}
}

