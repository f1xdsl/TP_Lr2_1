#pragma once
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
class Keeper
{
	int size;
	Student* array;
public:
	Keeper() {};
	~Keeper();
	Keeper(const Keeper& object);
	Keeper(int i);
	void Sort();
	void SetSize(int size);
	void Edit_all(int number);
	int GetSize();
	void Show_grade2();
	void Show_all();
	Keeper operator +(int number);
	Keeper operator -(int number);
};