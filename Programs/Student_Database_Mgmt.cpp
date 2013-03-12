//CS101 Course Project, Autumn Semester, Lab Group 542
//File Student_Database_Mgmt.cpp

#include <iostream>
#include <cstring>
#include <cstdio>
#include<cstdlib>
using namespace std;

struct student
{
	char username[50]; //Username is the name of the student without spaces and fullstops and everything in small letters
	char password[20]; //Max length of password is 20 characters
	char firstName[20];
	char lastName[20];
	char rollNo[10];
	long int mobile;
	char email[40];
	int hostel;
	int roomNo;
	char dept[3]; //Just a 2 letter dept code e.g. CS for Computer Science, CL for Chemical etc., one extra null
	int dobDate; //DOB - Date
	int dobMonth; //DOB - Month
	int dobYear; //DOB - Year
	int courseProg; //Type of programme e.g. 4 year B. Tech., 5 year B. Tech. + M. Tech. Dual Degree, 2 year M. Sc. Refer Course_Prog.txt for the codes
	int semOfStudy; //1st semester, 2nd semester etc.
	int yearOfJoin; //Which year the student joins
	int noOfCourses; //Number of courses the student has taken
	char course[10][6]; //5 letter course code e.g. MA105, CS101; one extra null
	int marks[10]; //Marks attained in each course
	char grade[10][3]; // AA, AB etc., one extra null
	int maxCredit[10]; //Credits alloted for each course
	int semCredit[10]; //Credits for each semester
	float spi[10];
	float cpi;
	float attendance[10]; //Percentage of attendance in each course. Hence, float
};

struct professor
{
	char username[20]; //Username for professor. It is name without spaces and fullstops and all in small letters
	char password[20]; //Max length of password is 20 characters
	char firstName[20];
	char lastName[20];
	char emailId[40];
	int officeNo;
	char myDept[3]; //Two-letter department code e.g. CS, MA etc.
	int myCoursesNo; //Number of courses the professor teaches
	char myCourses[10][6]; //CH103, MA105...etc
};

struct administrator
{
	char username[20];
	char password[20];
};

void funcStudent (struct student s[], int, int, char user[], struct professor p[], struct administrator a, FILE *);

void funcProfessor (struct student s[], int count1, int count2, char user[], struct professor p[], struct administrator a, FILE *);

void funcAdmin (struct administrator a, int count1, int count2, struct student s[], struct professor p[], FILE *);

void login (struct student[], struct professor p[], struct administrator a, int, int, FILE *);

int main()
{
	int *file1, *file2;
	int temp;
	int i = 0, j = 0, count1 = 0, count2 = 0;
	struct student *s;
	struct professor *p;
	struct administrator a;
	FILE *stud, *prof, *administrator_file;
	stud = fopen ("Stu_File.txt", "r");
	if (stud == NULL)
	{
		cout << "Couldn't open student file\n";
	}
	while (!feof (stud))
	{
		temp = fgetc (stud);
		j++;
	}
	file1 = new int[j];
	rewind (stud);
	while (!feof (stud))
	{
		file1[i] = fgetc (stud);
		i++;
	}
	for (i = 0; file1[i] != -1; i++)
	{
		if (file1[i] == 10)
		{
			++count1;
		}
	}
	s = new struct student[count1];
	rewind (stud);
	for (i = 0; i < count1; i++)
	{
		fscanf (stud, "%s %s", s[i].username, s[i].password);
		fscanf (stud, "%s %s %s %ld %s %d %d %s %d %d %d %d %d %d %d", s[i].firstName, s[i].lastName, s[i].rollNo, &s[i].mobile, s[i].email, &s[i].hostel, &s[i].roomNo, s[i].dept, &s[i].dobDate, &s[i].dobMonth, &s[i].dobYear, &s[i].courseProg, &s[i].semOfStudy, &s[i].yearOfJoin, &s[i].noOfCourses);
		fscanf (stud, "%s %s %s %s %s %s %s %s %s %s", s[i].course[0], s[i].course[1], s[i].course[2], s[i].course[3], s[i].course[4], s[i].course[5], s[i].course[6], s[i].course[7], s[i].course[8], s[i].course[9]);
		fscanf (stud, "%d %d %d %d %d %d %d %d %d %d", &s[i].marks[0], &s[i].marks[1], &s[i].marks[2], &s[i].marks[3], &s[i].marks[4], &s[i].marks[5], &s[i].marks[6], &s[i].marks[7], &s[i].marks[8], &s[i].marks[9]);
		fscanf (stud, "%s %s %s %s %s %s %s %s %s %s", s[i].grade[0], s[i].grade[1], s[i].grade[2], s[i].grade[3], s[i].grade[4], s[i].grade[5], s[i].grade[6], s[i].grade[7], s[i].grade[8], s[i].grade[9]);
		fscanf (stud, "%d %d %d %d %d %d %d %d %d %d", &s[i].maxCredit[0], &s[i].maxCredit[1], &s[i].maxCredit[2], &s[i].maxCredit[3], &s[i].maxCredit[4], &s[i].maxCredit[5], &s[i].maxCredit[6], &s[i].maxCredit[7], &s[i].maxCredit[8], &s[i].maxCredit[9]);
		fscanf (stud, "%d %d %d %d %d %d %d %d %d %d", &s[i].semCredit[0], &s[i].semCredit[1], &s[i].semCredit[2], &s[i].semCredit[3], &s[i].semCredit[4], &s[i].semCredit[5], &s[i].semCredit[6], &s[i].semCredit[7], &s[i].semCredit[8], &s[i].semCredit[9]);
		fscanf (stud, "%f %f %f %f %f %f %f %f %f %f %f", &s[i].spi[0], &s[i].spi[1], &s[i].spi[2], &s[i].spi[3], &s[i].spi[4], &s[i].spi[5], &s[i].spi[6], &s[i].spi[7], &s[i].spi[8], &s[i].spi[9], &s[i].cpi);
		fscanf (stud, "%f %f %f %f %f %f %f %f %f %f", &s[i].attendance[0], &s[i].attendance[1], &s[i].attendance[2], &s[i].attendance[3], &s[i].attendance[4], &s[i].attendance[5], &s[i].attendance[6], &s[i].attendance[7], &s[i].attendance[8], &s[i].attendance[9]);
	}
	prof = fopen ("Prof_File.txt", "r");
	j = 0;
	if (prof == NULL)
	{
		cout << "Couldn't open professor file\n";
	}
	while (!feof (prof))
	{
		temp = fgetc (prof);
		j++;                       //Calculating the total characters in the file
	}
	file2 = new int[j];               //Dynamically alocating the pointer a new array having the calculated number of characters
	rewind (prof);
	while (!feof (prof))
	{
		file2[i] = fgetc (prof);
		i++;
	}
	for (i = 0; file2[i] != -1; i++)
	{
		if (file2[i] == 10)
		{
			++count2;            //  Calculating the number of lines the file or in other words the number of students
		}
	}
	p = new struct professor[count2];     //   Dynamically creating an array of type 'struct student' having 'count' number of fields
	rewind (prof);
	for (i = 0; i < count2; i++)
	{
		fscanf(prof, "%s %s %s %s", p[i].username, p[i].password, p[i].firstName, p[i].lastName);
		fscanf(prof, "%s %d %s %d", p[i].emailId, &p[i].officeNo, p[i].myDept, &p[i].myCoursesNo);
		fscanf(prof, "%s %s %s %s %s %s %s %s %s %s", p[i].myCourses[0], p[i].myCourses[1], p[i].myCourses[2], p[i].myCourses[3], p[i].myCourses[4], p[i].myCourses[5], p[i].myCourses[6], p[i].myCourses[7], p[i].myCourses[8], p[i].myCourses[9]);
	}
	administrator_file = fopen ("Admin_File.txt", "r+");
	fscanf (administrator_file, "%s %s", a.username, a.password);
	fclose (stud);
	fclose (prof);
	login (s, p, a, count1, count2, administrator_file);
	return 0;
}

void login (struct student s[], struct professor p[], struct administrator a, int count1, int count2, FILE *administrator_file)
{
	int typeOfUser;
	int i;
	int loginFlag = 0;
	char user[20], pass[20];
	cout << "\n\n***************************************************************\n";
	cout << "\tWelcome to IIT Bombay Student Management System\n";
	cout << "***************************************************************\n";
	while (loginFlag == 0)
	{
		cout << "\nAre you a student, professor or administrator?\n";
		cout << "\nPress 1 for Student\n";
		cout << "Press 2 for Professor\n";
		cout << "Press 3 for Administrator\n";
		cin >> typeOfUser;
		if ((typeOfUser != 1) && (typeOfUser != 2) && (typeOfUser != 3))
		{
			cout << "\nWrong number. Try again\n";
			continue;
		}
		cout << "\n\nEnter your username and password\n";
		cout << "\nUsername:\t";
		cin >> user;
		cout << "Password:\t";
		cin >> pass;
		switch (typeOfUser)
		{
			case 1:
				for (i = 0; i < count1; i++)
				{
					if (strcmp (s[i].username, user) == 0)
					{
						if (strcmp (s[i].password, pass) == 0)
						{
							cout << "\nLogin successful\n";
							loginFlag = 1;
							break;
						}
						else
						{
							break;
						}
					}
					else
					{
						continue;
					}
				}
				if (loginFlag == 0)
				{
					cout << "\nLogin failed\n";
					cout << "Please try again\n";
					continue;
				}
				funcStudent (s, count1, count2, user, p, a, administrator_file);
				break;
			case 2:
				for (i = 0; i < count2; i++)
				{
					if (strcmp (p[i].username, user) == 0)
					{
						if (strcmp (p[i].password, pass) == 0)
						{
							cout << "\nLogin successful\n";
							loginFlag = 1;
							break;
						}
						else
						{
							break;
						}
					}
					else
					{
						continue;
					}
				}
				if (loginFlag == 0)
				{
					cout << "\nLogin failed\n";
					cout << "Please try again\n";
					continue;
				}
				funcProfessor (s, count1, count2, user, p, a, administrator_file);
				break;
			case 3:
				if (strcmp (a.username, user) == 0)
				{
					if (strcmp (a.password, pass) == 0)
					{
						cout << "\nLogin successful\n";
						loginFlag = 1;
					}
				}
				if (loginFlag == 0)
				{
					cout << "\nLogin failed\n";
					cout << "Please try again\n";
					continue;
				}
				funcAdmin (a, count1, count2, s, p, administrator_file);
				break;
		}
	}
}

void funcStudent (struct student s[], int count1, int count2, char user[], struct professor p[], struct administrator a, FILE *administrator_file)
{
	int i, j;
	int input1;
	FILE *stud;
	for (i = 0; i < count1; i++)
	{
		if (strcmp (s[i].username, user) == 0)
		{
			break;
		}
	}
	cout << "\nWelcome " << s[i].firstName << " " << s[i].lastName << "\t" << s[i].rollNo << endl;
	cout << "\nPress 1 for contact details\n";
	cout << "Press 2 for academic details\n";
	cout << "Press 3 to edit your password\n";
	cout << "Press 4 to search for students or professors\n";
	cout << "Press 5 to log out\n";
	cin >> input1;
	switch (input1)
	{
		case 1:
			int input2;
			char response;
			cout << "\nName:\t\t" << s[i].firstName << " " << s[i].lastName << endl;
			cout << "Roll No:\t" << s[i].rollNo << endl;
			cout << "Mobile:\t\t" << s[i].mobile << endl;
			cout << "Email ID:\t" << s[i].email << endl;
			cout << "Department:\t" << s[i].dept << endl;
			cout << "Hostel:\t\t" << s[i].hostel << endl;
			cout << "Room No:\t" << s[i].roomNo << endl;
			cout << "Date of Birth:\t" << s[i].dobDate << "/" << s[i].dobMonth << "/" << s[i].dobYear << endl;
			cout << "\nDo you want to edit? (Y/N)\n";
			cin >> response;
			if (response == 'Y' || response == 'y')
			{
				cout << "\nWhat do you want to edit?\n";
				cout << "\nPress 1 to edit your mobile number\n";
				cout << "Press 2 to edit your email ID\n";
				cout << "To edit any other details, contact the administrator\n";
				cin >> input2;
				switch (input2)
				{
					case 1:
						cout << "\nPlease enter your new mobile number\n";
						cin >> s[i].mobile;
						cout << "\nYour new mobile number is:\t" << s[i].mobile << endl;
						break;
					case 2:
						cout << "\nPlease enter your new email ID\n";
						cin >> s[i].email;
						cout << "\nYour new email ID is:\t" << s[i].email << endl;
						break;
				}
			}
			funcStudent (s, count1, count2, user, p, a, administrator_file);
			break;
		case 2:
			int j;
			cout << "\nCourse Programme:\t" << s[i].courseProg << endl;
			cout << "Semester:\t\t" << s[i].semOfStudy << endl;
			cout << "Year of Join:\t\t" << s[i].yearOfJoin << endl;
			cout << "\nYour Courses followed by your marks, grade and attendance:\n\n";
			for (j = 0; j < s[i].noOfCourses; j++)
			{
				cout << s[i].course[j] << " " << s[i].marks[j] << " " << s[i].grade[j] << " " << s[i].attendance[j] << endl;
			}
			cout << "\nSPI of each semester:\n";
			for (j = 0; j < s[i].semOfStudy; j++)
			{
				cout << "Semester " << j + 1 << ": " << s[i].spi[j] << endl;;
			}
			cout << "Your CPI: \t\t" << s[i].cpi << endl;
			funcStudent (s, count1, count2, user, p, a, administrator_file);
			break;
		case 3:
			cout << "\nPlease enter your new password\n";
			cin >> s[i].password;
			cout << "\nPassword changed\n";
			funcStudent (s, count1, count2, user, p, a, administrator_file);
			break;
		case 4:
			int search, flag;
			char fn[20];
			cout << "\nDo you want to search for student or professor\n";
			cout << "Press 1 for student\n";
			cout << "Press 2 for professor\n";
			cin >> search;
			flag = 0;
			if (search == 1)
			{
				cout << "\nEnter the first name of the student whose contact details you want to search\n";
				cin >> fn;
				for (i = 0; i < count1; i++)
				{
					if (strcmp (s[i].firstName, fn) == 0)
					{
						flag = 1;
						cout << "\n\tName:\t\t" << s[i].firstName << " " << s[i].lastName << endl;
						cout << "\tRoll No:\t" << s[i].rollNo << endl;
						cout << "\tMobile:\t\t" << s[i].mobile << endl;
						cout << "\tEmail ID:\t" << s[i].email << endl;
						cout << "\tHostel No:\t" << s[i].hostel << endl;
						cout << "\tRoom No:\t" << s[i].roomNo << endl;
					}
				}
				if (flag == 0)
				{
					cout << "\nStudent doesn't exist!\n";
				}
			}
			else if (search == 2)
			{
				cout << "\nEnter the first name of the professor whose contact details you want to search\n";
				cin >> fn;
				for (i = 0; i < count2; i++)
				{
					if (strcmp (p[i].firstName, fn) == 0)
					{
						flag = 1;
						cout << "\n\tName:\t\t" << p[i].firstName << " " << p[i].lastName << endl;
						cout << "\tEmail ID:\t" << p[i].emailId << endl;
						cout << "\tOffice No:\t" << p[i].officeNo << endl;
					}
				}
				if (flag == 0)
				{
					cout << "\nProfessor doesn't exist!\n";
				}
			}
			else
			{
				cout << "\nWrong input\n";
			}
			funcStudent (s, count1, count2, user, p, a, administrator_file);
			break;
		case 5:
			cout << "\nLogging out\n";
			stud = fopen ("Stu_File.txt", "w+");
			for (i = 0; i < count1; i++)
			{
				fprintf (stud, "%s %s ", s[i].username, s[i].password);
				fprintf (stud, "%s %s %s %ld %s %d %d %s %d %d %d %d %d %d %d ", s[i].firstName, s[i].lastName, s[i].rollNo, s[i].mobile, s[i].email, s[i].hostel, s[i].roomNo, s[i].dept, s[i].dobDate, s[i].dobMonth, s[i].dobYear, s[i].courseProg, s[i].semOfStudy, s[i].yearOfJoin, s[i].noOfCourses);
				fprintf (stud, "%s %s %s %s %s %s %s %s %s %s ", s[i].course[0], s[i].course[1], s[i].course[2], s[i].course[3], s[i].course[4], s[i].course[5], s[i].course[6], s[i].course[7], s[i].course[8], s[i].course[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].marks[3], s[i].marks[4], s[i].marks[5], s[i].marks[6], s[i].marks[7], s[i].marks[8], s[i].marks[9]);
				fprintf (stud, "%s %s %s %s %s %s %s %s %s %s ", s[i].grade[0], s[i].grade[1], s[i].grade[2], s[i].grade[3], s[i].grade[4], s[i].grade[5], s[i].grade[6], s[i].grade[7], s[i].grade[8], s[i].grade[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].maxCredit[0], s[i].maxCredit[1], s[i].maxCredit[2], s[i].maxCredit[3], s[i].maxCredit[4], s[i].maxCredit[5], s[i].maxCredit[6], s[i].maxCredit[7], s[i].maxCredit[8], s[i].maxCredit[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].semCredit[0], s[i].semCredit[1], s[i].semCredit[2], s[i].semCredit[3], s[i].semCredit[4], s[i].semCredit[5], s[i].semCredit[6], s[i].semCredit[7], s[i].semCredit[8], s[i].semCredit[9]);
				fprintf (stud, "%f %f %f %f %f %f %f %f %f %f %f ", s[i].spi[0], s[i].spi[1], s[i].spi[2], s[i].spi[3], s[i].spi[4], s[i].spi[5], s[i].spi[6], s[i].spi[7], s[i].spi[8], s[i].spi[9], s[i].cpi);
				fprintf (stud, "%f %f %f %f %f %f %f %f %f %f\n", s[i].attendance[0], s[i].attendance[1], s[i].attendance[2], s[i].attendance[3], s[i].attendance[4], s[i].attendance[5], s[i].attendance[6], s[i].attendance[7], s[i].attendance[8], s[i].attendance[9]);
			}
			fclose (stud);
			login (s, p, a, count1, count2, administrator_file);
			break;
	}
}

void funcProfessor (struct student s[], int count1, int count2, char user[], struct professor p[], struct administrator a, FILE *administrator_file)
{
	int i, j;
	int input1;
	FILE *prof;
	FILE *stud;
	for (i = 0; i < count2; i++)
	{
		if (strcmp (p[i].username, user) == 0)
		{
			break;
		}
	}
	cout << "\nWelcome " << p[i].firstName << " " << p[i].lastName << endl;
	cout << "\nPress 1 for contact details\n";
	cout << "Press 2 for academic details\n";
	cout << "Press 3 to edit your password\n";
	cout << "Press 4 to search for students or professors\n";
	cout << "Press 5 to log out\n";
	cin >> input1;
	switch (input1)
	{
		case 1:
			int input2;
			char response;
			cout << "\nName:\t\t" << p[i].firstName << " " << p[i].lastName << endl;
			cout << "Email ID:\t" << p[i].emailId << endl;
			cout << "Office No:\t" << p[i].officeNo << endl;
			cout << "Department:\t" << p[i].myDept << endl;
			cout << "\nDo you want to edit? (Y/N)\n";
			cin >> response;
			if (response == 'Y' || response == 'y')
			{
				cout << "What do you want to edit?\n";
				cout << "Press 1 for Email ID\n";
				cout << "Press 2 for Office No\n";
				cin >> input2;
				switch (input2)
				{
					case 1:
						cout << "Enter your new email ID\n";
						cin >> p[i].emailId;
						cout << "Your new email ID is:\t" << p[i].emailId << endl;
						break;
					case 2:
						cout << "Enter your new office no\n";
						cin >> p[i].officeNo;
						cout << "Your new office no is:\t" << p[i].officeNo << endl;
				}
				funcProfessor (s, count1, count2, user, p, a, administrator_file);
			}
			funcProfessor (s, count1, count2, user, p, a, administrator_file);
			break;
		case 2:
			int j, k, l;
			int crse;
			int courseFlag;
			char roll[10];
			cout << "\nYour courses are:\n";
			for (j = 0; j < p[i].myCoursesNo; j++)
			{
				cout << j + 1 << ". " << p[i].myCourses[j] << endl;
			}
			cout << "\nEnter the serial no of the course which you want to edit\n";
			cin >> crse;
			crse--;
			cout << "\nEnter the roll no whose grade you want to edit\n";
			cin >> roll;
			courseFlag = 0;
			for (k = 0; k < count1; k++)
			{
				if (strcmp (roll, s[k].rollNo) == 0)
				{
					for (l = 0; l < s[k].noOfCourses; l++)
					{
						if (strcmp (p[i].myCourses[crse], s[k].course[l]) == 0)
						{
							courseFlag = 1;
							break;
						}
					}
				}
				if (courseFlag == 1)
				{
					break;
				}
			}
			if (courseFlag == 0)
			{
				cout << "\nStudent doesn't exist or he is not enrolled in your course\n";
				funcProfessor (s, count1, count2, user, p, a, administrator_file);
			}
			cout << "Current grade of " << s[k].rollNo << " in the course " << s[k].course[l] << " is " << s[k].grade[l];
			cout << "\nEnter the attendance (in percentage) of the student\n";
			cin >> s[k].attendance[l];
			if (s[k].attendance[l] < 80)
			{
				strcpy (s[k].grade[l], "XX");
				s[k].marks[l] = 0;
			}
			else
			{
				cout << "Enter the new grade\n";
				cin >> s[k].grade[l];
				if (strcmp (s[k].grade[l], "AA") == 0 || (s[k].grade[l], "AP") == 0)
				{
					s[k].marks[l] = 10;
				}
				else if(strcmp (s[k].grade[l], "AB") == 0)
				{
					s[k].marks[l] = 9;
				}
				else if(strcmp (s[k].grade[l], "BB") == 0)
				{
					s[k].marks[l] = 8;
				}
				else if(strcmp (s[k].grade[l], "BC") == 0)
				{
					s[k].marks[l] = 7;
				}
				else if(strcmp (s[k].grade[l], "CC") == 0)
				{
					s[k].marks[l] = 6;
				}
				else if(strcmp (s[k].grade[l], "CD") == 0)
				{
					s[k].marks[l] = 5;
				}
				else if(strcmp (s[k].grade[l], "DD") == 0)
				{
					s[k].marks[l] = 4;
				}
				else if(strcmp (s[k].grade[l], "FR") == 0)
				{
					cout << "\nEnter the marks of the student\n";
					cin >> s[k].marks[l];
					if (s[k].marks[l] > 4)
					{
						cout << "Invalid marks!!\n";
						funcProfessor (s, count1, count2, user, p, a, administrator_file);
					}
				}
				else if(strcmp (s[k].grade[l], "XX") == 0)
				{
					s[k].marks[l] = 0;
				}
			}
			cout << "Grade of " << s[k].rollNo << " in the course " << s[k].course[l] << " is " << s[k].grade[l];
			funcProfessor (s, count1, count2, user, p, a, administrator_file);
			break;
		case 3:
			cout << "\nEnter your new password\n";
			cin >> p[i].password;
			cout << "Password changed\n";
			funcProfessor (s, count1, count2, user, p, a, administrator_file);
			break;
		case 4:
			int search, flag;
			char fn[20];
			cout << "\nDo you want to search for student or professor\n";
			cout << "Press 1 for student\n";
			cout << "Press 2 for professor\n";
			cin >> search;
			flag = 0;
			if (search == 1)
			{
				cout << "\nEnter the first name of the student whose contact details you want to search\n";
				cin >> fn;
				for (i = 0; i < count1; i++)
				{
					if (strcmp (s[i].firstName, fn) == 0)
					{
						flag = 1;
						cout << "\n\tName:\t\t" << s[i].firstName << " " << s[i].lastName << endl;
						cout << "\tRoll No:\t" << s[i].rollNo << endl;
						cout << "\tMobile:\t\t" << s[i].mobile << endl;
						cout << "\tEmail ID:\t" << s[i].email << endl;
						cout << "\tHostel No:\t" << s[i].hostel << endl;
						cout << "\tRoom No:\t" << s[i].roomNo << endl;
					}
				}
				if (flag == 0)
				{
					cout << "\nStudent doesn't exist!\n";
				}
			}
			else if (search == 2)
			{
				cout << "\nEnter the first name of the professor whose contact details you want to search\n";
				cin >> fn;
				for (i = 0; i < count2; i++)
				{
					if (strcmp (p[i].firstName, fn) == 0)
					{
						flag = 1;
						cout << "\n\tName:\t\t" << p[i].firstName << " " << p[i].lastName << endl;
						cout << "\tEmail ID:\t" << p[i].emailId << endl;
						cout << "\tOffice No:\t" << p[i].officeNo << endl;
					}
				}
				if (flag == 0)
				{
					cout << "\nProfessor doesn't exist!\n";
				}
			}
			else
			{
				cout << "\nWrong input\n";
			}
			funcStudent (s, count1, count2, user, p, a, administrator_file);
			break;
		case 5:
			cout << "\nLogging out\n";
			prof = fopen ("Prof_File.txt", "w+");
			for (i = 0; i < count2; i++)
			{
				fprintf(prof, "%s %s %s %s ", p[i].username, p[i].password, p[i].firstName, p[i].lastName);
				fprintf(prof, "%s %d %s %d ", p[i].emailId, p[i].officeNo, p[i].myDept, p[i].myCoursesNo);
				fprintf(prof, "%s %s %s %s %s %s %s %s %s %s\n", p[i].myCourses[0], p[i].myCourses[1], p[i].myCourses[2], p[i].myCourses[3], p[i].myCourses[4], p[i].myCourses[5], p[i].myCourses[6], p[i].myCourses[7], p[i].myCourses[8], p[i].myCourses[9]);		
			}
			fclose (prof);
			stud = fopen ("Stu_File.txt", "w+");
			for (i = 0; i < count1; i++)
			{
				fprintf (stud, "%s %s ", s[i].username, s[i].password);
				fprintf (stud, "%s %s %s %ld %s %d %d %s %d %d %d %d %d %d %d ", s[i].firstName, s[i].lastName, s[i].rollNo, s[i].mobile, s[i].email, s[i].hostel, s[i].roomNo, s[i].dept, s[i].dobDate, s[i].dobMonth, s[i].dobYear, s[i].courseProg, s[i].semOfStudy, s[i].yearOfJoin, s[i].noOfCourses);
				fprintf (stud, "%s %s %s %s %s %s %s %s %s %s ", s[i].course[0], s[i].course[1], s[i].course[2], s[i].course[3], s[i].course[4], s[i].course[5], s[i].course[6], s[i].course[7], s[i].course[8], s[i].course[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].marks[3], s[i].marks[4], s[i].marks[5], s[i].marks[6], s[i].marks[7], s[i].marks[8], s[i].marks[9]);
				fprintf (stud, "%s %s %s %s %s %s %s %s %s %s ", s[i].grade[0], s[i].grade[1], s[i].grade[2], s[i].grade[3], s[i].grade[4], s[i].grade[5], s[i].grade[6], s[i].grade[7], s[i].grade[8], s[i].grade[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].maxCredit[0], s[i].maxCredit[1], s[i].maxCredit[2], s[i].maxCredit[3], s[i].maxCredit[4], s[i].maxCredit[5], s[i].maxCredit[6], s[i].maxCredit[7], s[i].maxCredit[8], s[i].maxCredit[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].semCredit[0], s[i].semCredit[1], s[i].semCredit[2], s[i].semCredit[3], s[i].semCredit[4], s[i].semCredit[5], s[i].semCredit[6], s[i].semCredit[7], s[i].semCredit[8], s[i].semCredit[9]);
				fprintf (stud, "%f %f %f %f %f %f %f %f %f %f %f ", s[i].spi[0], s[i].spi[1], s[i].spi[2], s[i].spi[3], s[i].spi[4], s[i].spi[5], s[i].spi[6], s[i].spi[7], s[i].spi[8], s[i].spi[9], s[i].cpi);
				fprintf (stud, "%f %f %f %f %f %f %f %f %f %f\n", s[i].attendance[0], s[i].attendance[1], s[i].attendance[2], s[i].attendance[3], s[i].attendance[4], s[i].attendance[5], s[i].attendance[6], s[i].attendance[7], s[i].attendance[8], s[i].attendance[9]);
			}
			fclose (stud);
			login (s, p, a, count1, count2, administrator_file);
	}
}

void funcAdmin (struct administrator a, int count1, int count2, struct student s[], struct professor p[], FILE *administrator_file)
{
	int input;
	FILE *stud;
	FILE *prof;
	cout << "\nWelcome administrator\n";
	cout << "Press 1 to edit student details\n";
	cout << "Press 2 to edit professor details\n";
	cout << "Press 3 to calculate CPI of all students and increment semester\n";
	cout << "Press 4 to log out\n";
	cin >> input;
	switch (input)
	{
		case 1:
			char roll[10];
			int i, j, rollFlag;
			int editInput;
			cout << "\nEnter the roll number of the student whose details you want to edit\n";
			cin >> roll;
			rollFlag = 0;
			for (i = 0; i < count1; i++)
			{
				if (strcmp (roll, s[i].rollNo) == 0)
				{
					rollFlag = 1;
					break;
				}
			}
			if (rollFlag == 0)
			{
				cout << "\nStudent not found\n";
				funcAdmin (a, count1, count2, s, p, administrator_file);
			}
			cout << "\nWhat do you want to edit?\n";
			cout << "Press 1 to edit name\n";
			cout << "Press 2 to edit hostel and room number\n";
			cout << "Press 3 to edit department\n";
			cout << "Press 4 to edit academic details\n";
			cin >> editInput;
			switch (editInput)
			{
				case 1:
					cout << "\nEnter the new name of the student\n";
					cout << "First name followed by last name\n";
					cin >> s[i].firstName >> s[i].lastName;
					cout << "\nName set to " << s[i].firstName << " " << s[i].lastName << endl;
					funcAdmin (a, count1, count2, s, p, administrator_file);
					break;
				case 2:
					cout << "\nEnter the new hostel number followed by room number\n";
					cin >> s[i].hostel >> s[i].roomNo;
					cout << "\nHostel set to " << s[i].hostel << " and room number set to " << s[i].roomNo << endl;
					funcAdmin (a, count1, count2, s, p, administrator_file);
					break;
				case 3:
					cout << "\nEnter the new department (2-letter code)\n";
					cin >> s[i].dept;
					cout << "\nDepartment set to " << s[i].dept << endl;
					funcAdmin (a, count1, count2, s, p, administrator_file);
					break;
				case 4:
					cout << "\nEnter the number of courses the student is taking this semester\n";
					cin >> s[i].noOfCourses;
					cout << "Enter the course codes of the courses which the student is taking\n";
					for (j = 0; j < s[i].noOfCourses; j++)
					{
						cin >> s[i].course[j];
					}
					for (j = 0; j < 10; j++)
					{
						s[i].marks[j] = 0;
						strcpy (s[i].grade[j], "a");
						s[i].spi[j] = 0.0;
						s[i].attendance[j] = 0.0;
					}
					cout << "Enter the maximum number of credits for each course\n";
					for (j = 0; j < s[i].noOfCourses; j++)
					{
						cout << "Max credits for " << s[i].course[j] << ": ";
						cin >> s[i].maxCredit[j];
					}
					s[i].semCredit[0] = 0;
					for (j = 0; j < s[count1].noOfCourses; j++)
					{
						s[i].semCredit[0] += s[i].maxCredit[j];
					}
					s[i].cpi = 0.0;
					funcAdmin (a, count1, count2, s, p, administrator_file);
					break;
			}
		case 2:
			char user[20];
			int userFlag, profInput;
			cout << "\nEnter the username of the professor whose details you want to edit\n";
			cin >> user;
			userFlag = 0;
			for (i = 0; i < count2; i++)
			{
				if (strcmp (p[i].username, user) == 0)
				{
					userFlag = 1;
					break;
				}
			}
			if (userFlag == 0)
			{
				cout << "\nProfessor not found\n";
				funcAdmin (a, count1, count2, s, p, administrator_file);
			}
			cout << "\nWhat do you want to edit?\n";
			cout << "Press 1 to edit name\n";
			cout << "Press 2 to edit academic details\n";
			cin >> profInput;
			switch (profInput)
			{
				case 1:
					cout << "\nEnter the professor's new name: First Name followed by Last Name\n";
					cin >> p[i].firstName >> p[i].lastName;
					cout << "\nName of the professor is " << p[i].firstName << " " << p[i].lastName << endl;
					funcAdmin (a, count1, count2, s, p, administrator_file);
					break;
				case 2:
					cout << "\nEnter the number of courses the professor is teaching\n";
					cin >> p[i].myCoursesNo;
					cout << "\nEnter the course codes of the courses the professor teaches\n";
					for (j = 0; j < p[i].myCoursesNo; j++)
					{
						cin >> p[i].myCourses[j];
					}
					funcAdmin (a, count1, count2, s, p, administrator_file);
					break;
			}
		case 3:
			int ctr1, ctr2;
			for (ctr1 = 0; ctr1 < count1; ctr1++)
			{
				s[ctr1].spi[s[ctr1].semOfStudy - 1] = 0.0;
				for (ctr2 = 0; ctr2 < s[ctr1].noOfCourses; ctr2++)
				{
					s[ctr1].spi[s[ctr1].semOfStudy - 1] += s[ctr1].maxCredit[ctr2] * s[ctr1].marks[ctr2];
				}
				s[ctr1].spi[s[ctr1].semOfStudy - 1] /= s[ctr1].semCredit[s[ctr1].semOfStudy - 1];
				s[ctr1].cpi = 0.0;
				for (ctr2 = 0; ctr2 < s[ctr1].semOfStudy; ctr2++)
				{
					s[ctr1].cpi += s[ctr1].semCredit[ctr2] * s[ctr1].spi[ctr2];
				}
				s[ctr1].cpi /= (s[ctr1].semCredit[0] + s[ctr1].semCredit[1] + s[ctr1].semCredit[2] + s[ctr1].semCredit[3] + s[ctr1].semCredit[4] + s[ctr1].semCredit[5] + s[ctr1].semCredit[6] + s[ctr1].semCredit[7] + s[ctr1].semCredit[8] + s[ctr1].semCredit[9]);				
			}
			funcAdmin (a, count1, count2, s, p, administrator_file);
			break;
		case 4:
			prof = fopen ("Prof_File.txt", "w+");
			for (i = 0; i < count2; i++)
			{
				fprintf(prof, "%s %s %s %s ", p[i].username, p[i].password, p[i].firstName, p[i].lastName);
				fprintf(prof, "%s %d %s %d ", p[i].emailId, p[i].officeNo, p[i].myDept, p[i].myCoursesNo);
				fprintf(prof, "%s %s %s %s %s %s %s %s %s %s\n", p[i].myCourses[0], p[i].myCourses[1], p[i].myCourses[2], p[i].myCourses[3], p[i].myCourses[4], p[i].myCourses[5], p[i].myCourses[6], p[i].myCourses[7], p[i].myCourses[8], p[i].myCourses[9]);		
			}
			stud = fopen ("Stu_File.txt", "w+");
			for (i = 0; i < count1; i++)
			{
				fprintf (stud, "%s %s ", s[i].username, s[i].password);
				fprintf (stud, "%s %s %s %ld %s %d %d %s %d %d %d %d %d %d %d ", s[i].firstName, s[i].lastName, s[i].rollNo, s[i].mobile, s[i].email, s[i].hostel, s[i].roomNo, s[i].dept, s[i].dobDate, s[i].dobMonth, s[i].dobYear, s[i].courseProg, s[i].semOfStudy, s[i].yearOfJoin, s[i].noOfCourses);
				fprintf (stud, "%s %s %s %s %s %s %s %s %s %s ", s[i].course[0], s[i].course[1], s[i].course[2], s[i].course[3], s[i].course[4], s[i].course[5], s[i].course[6], s[i].course[7], s[i].course[8], s[i].course[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].marks[3], s[i].marks[4], s[i].marks[5], s[i].marks[6], s[i].marks[7], s[i].marks[8], s[i].marks[9]);
				fprintf (stud, "%s %s %s %s %s %s %s %s %s %s ", s[i].grade[0], s[i].grade[1], s[i].grade[2], s[i].grade[3], s[i].grade[4], s[i].grade[5], s[i].grade[6], s[i].grade[7], s[i].grade[8], s[i].grade[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].maxCredit[0], s[i].maxCredit[1], s[i].maxCredit[2], s[i].maxCredit[3], s[i].maxCredit[4], s[i].maxCredit[5], s[i].maxCredit[6], s[i].maxCredit[7], s[i].maxCredit[8], s[i].maxCredit[9]);
				fprintf (stud, "%d %d %d %d %d %d %d %d %d %d ", s[i].semCredit[0], s[i].semCredit[1], s[i].semCredit[2], s[i].semCredit[3], s[i].semCredit[4], s[i].semCredit[5], s[i].semCredit[6], s[i].semCredit[7], s[i].semCredit[8], s[i].semCredit[9]);
				fprintf (stud, "%f %f %f %f %f %f %f %f %f %f %f ", s[i].spi[0], s[i].spi[1], s[i].spi[2], s[i].spi[3], s[i].spi[4], s[i].spi[5], s[i].spi[6], s[i].spi[7], s[i].spi[8], s[i].spi[9], s[i].cpi);
				fprintf (stud, "%f %f %f %f %f %f %f %f %f %f\n", s[i].attendance[0], s[i].attendance[1], s[i].attendance[2], s[i].attendance[3], s[i].attendance[4], s[i].attendance[5], s[i].attendance[6], s[i].attendance[7], s[i].attendance[8], s[i].attendance[9]);
			}
			fclose (stud);
			fclose (prof);
			rewind (administrator_file);
			fprintf (administrator_file, "%s %s", a.username, a.password);
			login (s, p, a, count1, count2, administrator_file);
			break;
	}
}
