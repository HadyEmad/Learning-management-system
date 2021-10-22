#include "student.h"
#include<fstream>
#include <string>

int main()
{
	student st[100];
	string x;
	char y;

	ifstream data("studentsData.csv");

	if (!data.is_open())
	{
		cout << "Can't open the file.";
		return 0;
	}
	
	getline(data, x);
	int i = 0;
	while (!data.eof())
	{
		getline(data, st[i].ID, ',');
		cout << st[i].ID << "\t";
		getline(data, st[i].name, ',');
		cout << st[i].name << "\t";
		getline(data, st[i].age, ',');
		cout << st[i].age << "\t";
		getline(data, st[i].gender);
		cout << st[i].gender << "\t" << endl;
		i++;
	}
	data.close();

	ifstream grades("studentsGrade.csv");
	if (!grades.is_open())
	{
		cout << "Can't open the file.";
		return 0;
	}

	int j = 0;

	string k;
	string k1;
	getline(grades, k1);
	while (getline(grades, x,','))
	{
		getline(grades, k, ',');
		st[j].math = stoi(k);
		cout << st[j].math<<"\t";
		getline(grades, k, ',');
		st[j].phy = stoi(k);
		cout << st[j].phy << "\t";
		getline(grades, k, ',');
		st[j].draw = stoi(k);
		cout << st[j].draw << "\t";
		getline(grades, k, ',');
		st[j].comp = stoi(k);
		cout << st[j].comp << "\t";
		getline(grades, k);
		st[j].chem = stoi(k);
		cout << st[j].chem << "\t\n";
		j++;


	}
	


}
