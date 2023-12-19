#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Subject
{
	string name_subject;
	int grade;
};


class Student
{
	string name;
	string group;

	int numOfSubjects;

public:


	Subject* subjects;

	~Student();
	Student(int a);
	Student();
	Student(const Student& other);
	void add();
	void SetName(string name);
	void SetGroup(string group);
	void SetNumOfSubjects(int number_subjects);
	Student operator = (const Student& other);
	void Edit();

	float CalculateAverage();

	string GetName();
	string GetGroup();
	int GetNumOfSubjects();
	void AddSubjectGrade(string name_subject, int grade, int num);
	void Show();
	friend istream& operator >>(istream& os, Student& el);
	friend ostream& operator <<(ostream& os, const Student& el);
};