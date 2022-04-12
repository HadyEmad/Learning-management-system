#include "student.h"
#include<fstream>
#include <string>
#include<math.h>

int j = 0;
string fileName, expFile;

void importGrades(student[]);
void importData(student[]);
void linesData();
void linesGrades();
void normalize(student[], student[]);
void exportall(student[], ofstream&);
void exportData(student[], ofstream&);
void exportGrades(student[], ofstream&);
void printGPA(student[], ofstream&);
string GPA(float);
void percentage(student[]);
void info(student[]);

int main()
{
	cout << "\t\t\t\t\t *Learning Managment System*" << endl;
	int a = 0, b = 0, c = 0, d = 0, e = 0, h = 0;
	int flag_data = 0, flag_grade = 0;
	char f;
	student* st = new student[2];
	student* normal;

menu:
	cout << "\n1-Import/Export student data\n2-Import/Export student grades\n3-Modify grades\n4-Others\n5-Exit\n";
	cout << "\nSelect:";
	cin >> a;

	if (a == 1)
	{
		cout << "1-Import student data\n2-Export student data\n";
		cout << "\nSelect:";
		cin >> b;

		if (b == 1) {
			if (flag_grade == 0)
			{
				linesData();
				st = new student[j];
				flag_data = 1;
				importData(st);
				c = 1;
			restart:
				cout << "Do you want to return to the menu ? (y/n)\n";
				cin >> f;
				if (f == 'y') { goto menu; }
				else if (f == 'n') { goto exit; }
				else { goto restart; }
			}
			else {
				linesData();
				importData(st);
				c = 1;
			restart1:
				cout << "Do you want to return to the menu ? (y/n)\n";
				cin >> f;
				if (f == 'y') { goto menu; }
				else if (f == 'n') { goto exit; }
				else { goto restart1; }
			}

		}


		else if (b == 2)
		{
			if (c == 0)
			{
				cout << "No file to be exported!!\n" << endl;
				goto menu;
			}
			cout << "Please enter outputfile name and directory: ";
			cin.ignore(10, '\n');
			getline(cin, expFile);
			ofstream op(expFile);
			exportData(st, op);
		restart2:
			cout << "Do you want to return to the menu ? (y/n)\n";
			cin >> f;
			if (f == 'y') { goto menu; }
			else if (f == 'n') { goto exit; }
			else { goto restart2; }
		}
	}

	else if (a == 2)
	{
		cout << "1-Import student grades\n2-Export student grades\n";
		cout << "\nSelect:";
		cin >> b;

		if (b == 1) {
			if (flag_data == 0)
			{

				linesGrades();
				st = new student[j];
				flag_grade = 1;
				importGrades(st);
				d = 1;
			restart3:;
				cout << "Do you want to return to the menu ? (y/n)\n";
				cin >> f;
				if (f == 'y') { goto menu; }
				else if (f == 'n') { goto exit; }
				else { goto restart3; }

			}
			else
			{
				linesGrades();
				importGrades(st);
				d = 1;
			restart31:
				cout << "Do you want to return to the menu ? (y/n)\n";
				cin >> f;
				if (f == 'y') { goto menu; }
				else if (f == 'n') { goto exit; }
				else { goto restart31; }
			}
		}


		else if (b == 2)
		{
			if (d == 0)
			{
				cout << "No grades to be exported!!\n" << endl;
				goto menu;
			}
			cout << "Please enter outputfile name and directory: ";
			cin.ignore(10, '\n');
			getline(cin, expFile);
			ofstream op(expFile);
			exportGrades(st, op);
		restart4:
			cout << "Do you want to return to the menu ? (y/n)\n";
			cin >> f;
			if (f == 'y') { goto menu; }
			else if (f == 'n') { goto exit; }
			else { goto restart4; }
		}
	}

	else if (a == 3)
	{
		if (d == 0)
		{
			cout << "No grades to be modified!!\n" << endl;
			goto menu;
		}

		cout << "What is the modification you would like to perform on the grades?\n1-Normaliziation\n2-GPA\n";
		cout << "Select: ";
		cin >> e;
		cin.ignore(10, '\n');
		if (e == 1)
		{
			normal = new student[j];
			for (int q = 0; q < j; q++)
				normal[q] = st[q];
			normalize(st, normal);
			cout << "Please enter outputfile name and directory: ";
			getline(cin, expFile);
			ofstream op(expFile);
			exportGrades(normal, op);
		restart6:
			cout << "Do you want to return to the menu ? (y/n)\n";
			cin >> f;
			if (f == 'y') { goto menu; }
			else if (f == 'n') { goto exit; }
			else { goto restart6; }
		}

		else if (e == 2)
		{
			cout << "Please enter outputfile name and directory: ";
			getline(cin, expFile);
			ofstream op(expFile);
			printGPA(st, op);
		restart5:
			cout << "Do you want to return to the menu ? (y/n)\n";
			cin >> f;
			if (f == 'y') { goto menu; }
			else if (f == 'n') { goto exit; }
			else { goto restart5; }
		}

	}

	else if (a == 4)
	{
		cout << "\n1-Printing the percentage of the GPA of each subject\n2-Printing a student's data and grades using his ID\n3-Exporting students data and grades in one file\n";
		cout << "Select:";
		cin >> h;
		if (h == 1)
		{
			if (d == 0)
			{
				cout << "No grades to be modified!!\n" << endl;
				goto menu;
			}
			percentage(st);
		restart7:
			cout << "Do you want to return to the menu ? (y/n)\n";
			cin >> f;
			if (f == 'y') { goto menu; }
			else if (f == 'n') { goto exit; }
			else { goto restart7; }
		}

		else if (h == 2)
		{
			if (c == 0 || d == 0)
			{
				cout << "The data or the grades weren't imported!!\n" << endl;
				goto menu;
			}
			info(st);

		restart8:
			cout << "Do you want to return to the menu ? (y/n)\n";
			cin >> f;
			if (f == 'y') { goto menu; }
			else if (f == 'n') { goto exit; }
			else { goto restart8; }
		}

		else if (h == 3)
		{
			if (c == 0 || d == 0)
			{
				cout << "The data or the grades weren't imported!!\n" << endl;
				goto menu;
			}
			cout << "Please enter outputfile name and directory: ";
			cin.ignore(10, '\n');
			getline(cin, expFile);
			ofstream op(expFile);
			exportall(st, op);
		restart9:
			cout << "Do you want to return to the menu ? (y/n)\n";
			cin >> f;
			if (f == 'y') { goto menu; }
			else if (f == 'n') { goto exit; }
			else { goto restart9; }
		}
	}
	else if (a == 5) { goto exit; }
	else { goto menu; }
exit:
	cout << "\nThanks for using our LMS ...\n";
	return 0;

}


void linesData()
{
	cin.ignore(10, '\n');
check:
	cout << "Please enter the students data file name and directory:";
	getline(cin, fileName);
	ifstream data(fileName);
	if (!data.is_open())
	{
		cout << "Can't open the file.";
		goto check;
	}
	int i = 0;
	string y;
	getline(data, y);
	while (!data.eof())
	{
		getline(data, y);
		i++;
	}
	data.close();
	j = i - 1;
}

void importData(student st[])
{
	ifstream data(fileName);
	string impd;
	int t = 0;
	getline(data, impd);
	while (t < j)
	{
		getline(data, st[t].ID, ',');
		getline(data, st[t].name, ',');
		getline(data, st[t].age, ',');
		getline(data, st[t].gender);
		t++;
	}
	data.close();
	cout << "Data has been imported successfully... \n\n";
}

void linesGrades()
{
	cin.ignore(10, '\n');
check:
	cout << "Please enter the students grades file name and directory: ";
	getline(cin, fileName);
	ifstream data(fileName);
	if (!data.is_open())
	{
		cout << "Can't open the file.";
		goto check;
	}
	int i = 0;
	string y;
	getline(data, y);
	while (!data.eof())
	{
		getline(data, y);
		i++;
	}
	data.close();
	j = i - 1;
}

void importGrades(student x[])
{
	ifstream grades(fileName);
	string k;
	int a = 0;
	getline(grades, k);
	while (a < j)
	{
		getline(grades, x[a].ID, ',');
		getline(grades, k, ',');
		x[a].math = stof(k);
		getline(grades, k, ',');
		x[a].phy = stof(k);
		getline(grades, k, ',');
		x[a].draw = stof(k);
		getline(grades, k, ',');
		x[a].comp = stof(k);
		getline(grades, k);
		x[a].chem = stof(k);
		a++;
	}
	grades.close();

	cout << "Grades has been imported successfully...\n\n";
}

void exportall(student x[], ofstream& file)
{
	file << "Student ID,Name,Age,Gender,Math,Physics,Drawing,Computer,Chemistry\n ";
	for (int i = 0; i < j; i++)
	{
		file << x[i].ID << "," << x[i].name << "," << x[i].age << "," << x[i].gender << ",";
		file << x[i].math << "," << x[i].phy << "," << x[i].draw << "," << x[i].comp << "," << x[i].chem << endl;
	}
	file.close();
	cout << "File has been exported successfully...\n\n";
}

void exportData(student st[], ofstream& file)
{
	file << "Student ID,Name ,Age ,Gender \n";
	for (int i = 0; i < j; i++)
	{
		file << st[i].ID << "," << st[i].name << "," << st[i].age << "," << st[i].gender << endl;
	}
	file.close();
	cout << "Data has been exported successfully...\n\n";
}

void exportGrades(student st[], ofstream& file)
{
	file << "Student ID,Math,Physics,Drawing,Computer,Chemistry\n";
	for (int i = 0; i < j; i++)
	{
		file << st[i].ID << "," << st[i].math << "," << st[i].phy << "," << st[i].draw << "," << st[i].comp << "," << st[i].chem << endl;
	}
	file.close();
	cout << "Grades has been successfully exported...\n\n";
}

void normalize(student x[], student z[])
{

	float sum = 0.0, mean, standardDeviation = 0.0;
	for (int i = 0; i < j; ++i)
		sum += x[i].math;

	mean = sum / j;
	for (int i = 0; i < j; ++i)
		standardDeviation += pow(x[i].math - mean, 2);

	standardDeviation = sqrt(standardDeviation / j);
	for (int i = 0; i < j; i++)
		z[i].math = (x[i].math - mean) / standardDeviation;

	sum = 0.0, standardDeviation = 0.0;
	for (int i = 0; i < j; ++i)
		sum += x[i].phy;

	mean = sum / j;
	for (int i = 0; i < j; ++i)
		standardDeviation += pow(x[i].phy - mean, 2);

	standardDeviation = sqrt(standardDeviation / j);
	for (int i = 0; i < j; i++)
		z[i].phy = (x[i].phy - mean) / standardDeviation;

	sum = 0.0, standardDeviation = 0.0;
	for (int i = 0; i < j; ++i)
		sum += x[i].draw;

	mean = sum / j;
	for (int i = 0; i < j; ++i)
		standardDeviation += pow(x[i].draw - mean, 2);

	standardDeviation = sqrt(standardDeviation / j);
	for (int i = 0; i < j; i++)
		z[i].draw = (x[i].draw - mean) / standardDeviation;

	sum = 0.0, standardDeviation = 0.0;
	for (int i = 0; i < j; ++i)
		sum += x[i].comp;

	mean = sum / j;
	for (int i = 0; i < j; ++i)
		standardDeviation += pow(x[i].comp - mean, 2);

	standardDeviation = sqrt(standardDeviation / j);
	for (int i = 0; i < j; i++)
		z[i].comp = (x[i].comp - mean) / standardDeviation;

	sum = 0.0, standardDeviation = 0.0;
	for (int i = 0; i < j; ++i)
		sum += x[i].chem;

	mean = sum / j;
	for (int i = 0; i < j; ++i)
		standardDeviation += pow(x[i].chem - mean, 2);

	standardDeviation = sqrt(standardDeviation / j);
	for (int i = 0; i < j; i++)
		z[i].chem = (x[i].chem - mean) / standardDeviation;
}

string GPA(float x)
{
	if (x >= 90) { return "A"; }
	if (x < 90 && x >= 85) { return "B+"; }
	if (x >= 80 && x < 85) { return "B"; }
	if (x >= 75 && x < 80) { return "C+"; }
	if (x >= 70 && x < 75) { return "C"; }
	if (x >= 65 && x < 70) { return "D+"; }
	if (x >= 60 && x < 65) { return "D"; }
	if (x < 60) { return "F"; }
}

void printGPA(student st[], ofstream& file)
{
	file << "ID,math,physics,drawing,computer,chemistry" << endl;

	for (int u = 0; u < j; u++)
	{
		st[u].gpa_math = GPA(st[u].math);
		st[u].gpa_phy = GPA(st[u].phy);
		st[u].gpa_chem = GPA(st[u].chem);
		st[u].gpa_draw = GPA(st[u].draw);
		st[u].gpa_comp = GPA(st[u].comp);
		file << st[u].ID << ',' << st[u].gpa_math << ',' << st[u].gpa_phy << ',' << st[u].gpa_draw << ',' << st[u].gpa_comp << ',' << st[u].gpa_chem << endl;
	}

	file.close();
	cout << "GPA File has been successfully exported...\n\n";
}

void percentage(student x[])
{
	float s = j;
	int mathA = 0, mathB = 0, mathC = 0, mathD = 0, mathF = 0;

	int physicsA = 0, physicsB = 0, physicsC = 0, physicsD = 0, physicsF = 0;

	int drawingA = 0, drawingB = 0, drawingC = 0, drawingD = 0, drawingF = 0;

	int computerA = 0, computerB = 0, computerC = 0, computerD = 0, computerF = 0;

	int chemistryA = 0, chemistryB = 0, chemistryC = 0, chemistryD = 0, chemistryF = 0;

	for (int i = 0; i < j; i++)
	{
		if (x[i].math >= 90) { mathA++; }
		else if (x[i].math >= 80 && x[i].math < 90) { mathB++; }
		else if (x[i].math >= 70 && x[i].math < 80) { mathC++; }
		else if (x[i].math >= 60 && x[i].math < 70) { mathD++; }
		else { mathF++; }

		if (x[i].phy >= 90) { physicsA++; }
		else if (x[i].phy >= 80 && x[i].math < 90) { physicsB++; }
		else if (x[i].phy >= 70 && x[i].math < 80) { physicsC++; }
		else if (x[i].phy >= 60 && x[i].math < 70) { physicsD++; }
		else { physicsF++; }

		if (x[i].draw >= 90) { drawingA++; }
		else if (x[i].draw >= 80 && x[i].draw < 90) { drawingB++; }
		else if (x[i].draw >= 70 && x[i].draw < 80) { drawingC++; }
		else if (x[i].draw >= 60 && x[i].draw < 70) { drawingD++; }
		else { drawingF++; }

		if (x[i].comp >= 90) { computerA++; }
		else if (x[i].comp >= 80 && x[i].comp < 90) { computerB++; }
		else if (x[i].comp >= 70 && x[i].comp < 80) { computerC++; }
		else if (x[i].comp >= 60 && x[i].comp < 70) { computerD++; }
		else { computerF++; }

		if (x[i].chem >= 90) { chemistryA++; }
		else if (x[i].chem >= 80 && x[i].chem < 90) { chemistryB++; }
		else if (x[i].chem >= 70 && x[i].chem < 80) { chemistryC++; }
		else if (x[i].chem >= 60 && x[i].chem < 70) { chemistryD++; }
		else { chemistryF++; }
	}
	cout << "\nMaths course: " << (mathA / s) * 100 << "% A,  " << (mathB / s) * 100 << "% B,  "
		<< (mathC / s) * 100 << "% C,  " << (mathD / s) * 100 << "% D,  " << (mathF / s) * 100 << "% F \n\n";

	cout << "Physics course: " << (physicsA / s) * 100 << "% A,  " << (physicsB / s) * 100 << "% B,  "
		<< (physicsC / s) * 100 << "% C,  " << (physicsD / s) * 100 << "% D,  " << (physicsF / s) * 100 << "% F \n\n";

	cout << "Drawing course: " << (drawingA / s) * 100 << "% A,  " << (drawingB / s) * 100 << "% B,  "
		<< (drawingC / s) * 100 << "% C,  " << (drawingD / s) * 100 << "% D,  " << (drawingF / s) * 100 << "% F \n\n";

	cout << "Computer course: " << (computerA / s) * 100 << "% A,  " << (computerB / s) * 100 << "% B,  "
		<< (computerC / s) * 100 << "% C,  " << (computerD / s) * 100 << "% D,  " << (computerF / s) * 100 << "% F \n\n";

	cout << "Chemistry course: " << (chemistryA / s) * 100 << "% A,  " << (chemistryB / s) * 100 << "% B,  "
		<< (chemistryC / s) * 100 << "% C,  " << (chemistryD / s) * 100 << "% D,  " << (chemistryF / s) * 100 << "% F \n\n";

}

void info(student y[])
{
	string x;
	cout << "Please enter an ID: ";
	cin >> x;
	for (int i = 0; i < j; i++)
	{
		if (x == y[i].ID)
		{
			cout << "ID: " << y[i].ID << "\nName: " << y[i].name << "\nAge: " << y[i].age << "\nGender: " << y[i].gender << endl;
			cout << "Maths: " << y[i].math << "\nPhysics: " << y[i].phy << "\nDrawing: " << y[i].draw << "\nComputer: " << y[i].comp << "\nChemistry: " << y[i].chem;
		}
		cout << endl;
	}
}
