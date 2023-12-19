#include "Student.h"
#include "keeper.h"
#include <conio.h>
#include <Windows.h>
using namespace std;

int main()
{
	string text;
	Keeper object;
	int action, action1, action2;
	int flag = 1;

	while (flag != 0)
	{

		cout << "Menu:" << endl;
		cout << "1 - Add" << endl;
		cout << "2 - Delete" << endl;
		cout << "3 - Edit" << endl;
		cout << "4 - Show all" << endl;
		cout << "5 - Show students with 2" << endl;
		cout << "6 - GPA increase" << endl;
		cout << "7 - Exit" << endl;

		cout << "Enter option number\n";
		cin >> action;
		switch (action)
		{
		case 1:
		{
			object + 1;

			cout << "0 - Menu ";
			cin >> action1;

			if (action1 == 0) system("cls");

			break;
		}

		case 2:

			system("cls");

			if (object.GetSize() > 0)
			{
				object.Show_all();

				cout << "Select item number to delete: ";
				cin >> action2;

				object - action2;
			}
			else
				cout << "There are no students in the database" << endl;

			cout << "0 - Menu: ";
			cin >> action1;

			if (action1 == 0)
				system("cls");

			break;


		case 3:

			system("cls");

			if (object.GetSize() > 0)
			{
				int n;
				object.Show_all();
				cout << "What change?: ";
				cin >> n;
				object.Edit_all(n);
			}
			else
				cout << "There are no students in the database" << endl;

			cout << "0 - Menu: ";
			cin >> action1;

			if (action1 == 0)
				system("cls");

			break;


		case 4:

			system("cls");

			if (object.GetSize() > 0)
				object.Show_all();
			else
				cout << "There are no students in the database" << endl;

			cout << "0 - Menu: ";
			cin >> action1;

			if (action1 == 0)
				system("cls");

			break;


		case 5:
			system("cls");

			if (object.GetSize() > 0)
				object.Show_grade2();
			else
				cout << "There are no students in the database" << endl;

			cout << "0 - Menu: ";
			cin >> action1;

			if (action1 == 0)
				system("cls");

			break;


		case 6:
			system("cls");

			if (object.GetSize() > 0)
			{
				cout << "Sorting completed successfully" << endl;
				object.Sort();
				object.Show_all();
			}
			else
				cout << "There are no students in the database" << endl;

			cout << "0 - Menu: ";
			cin >> action1;

			if (action1 == 0)
				system("cls");

			break;


		case 7:
			system("cls");
			flag = 0;
			break;


		default:
			break;
		}



	}

	return 0;
}

