#include "keeper.h"


Keeper::Keeper(const Keeper& other)
{
	array = new Student[other.size];
	for (int i = 0; i < other.size; i++)
	{
		array[i] = other.array[i];
	}

}


Keeper::~Keeper()
{
	delete[] array;
}


void Keeper::Sort()
{
	Keeper buffer(*this);
	array = new Student[GetSize()];

	for (int i = 0; i < GetSize(); i++)
	{
		array[i] = buffer.array[i];
	}

	for (int i = 0; i < size; i++) {

		int min_index = i;
		float min_GPA = array[i].CalculateAverage();

		for (int j = i + 1; j < size; j++) {
			float curr_GPA = array[j].CalculateAverage();
			if (curr_GPA < min_GPA) {
				min_GPA = curr_GPA;
				min_index = j;
			}
		}

		Student temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}
}

int Keeper::GetSize() { return size; };

void Keeper::Show_grade2()
{

	int count = 0;
	for (int i = 0; i < GetSize(); i++)
	{
		for (int j = 0; j < array[i].GetNumOfSubjects(); j++)
		{
			if (array[i].subjects[j].grade == 2)
			{
				cout << i + 1 << endl;
				array[i].Show();
				count++;
				break;
			}
		}

	}
	if (count == 0)
		cout << "No students with grade 2" << endl;
}


void Keeper::SetSize(int size) { this->size = size; };

void Keeper::Show_all()
{
	cout << "All the students:" << endl;
	for (int i = 0; i < GetSize(); i++)
	{
		cout << i + 1 << endl;
		cout << array[i];
	}
}


Keeper Keeper::operator +(int number)
{

	cout << "Add:" << endl;
	Keeper buffer = *this;

	SetSize(GetSize() + 1);

	array = new Student[GetSize()];

	for (int i = 0; i < GetSize() - 1; i++)
	{
		array[i] = buffer.array[i];
	}
	cin >> array[GetSize() - 1];
	return *this;
}


Keeper Keeper::operator -(int number)
{
	Keeper buffer = *this;

	SetSize(GetSize() - 1);
	array = new Student[GetSize()];

	for (int i = 0; i < number - 1; i++)
	{
		array[i] = buffer.array[i];
	}

	for (int i = number - 1; i < GetSize(); i++)
	{
		array[i] = buffer.array[i + 1];
	}


	return *this;


}


void Keeper::Edit_all(int number)
{
	array[number - 1].Edit();
}
