//pre-processors

#include<windows.h>       

#include<stdio.h>

#include<conio.h>

#include <stdlib.h>

#include<string.h>                 

#include<ctype.h>                   

#include<dos.h>                    

#include<time.h>



#define RETURNTIME 15   //return time macros

//functions

int adminsec();

int studentsec();

void searchstudent();

char catagories[][15] = { "Student"};

void returnfunc(void);

void mainmenu(void);

void addstaff(void);

void deletestaff(void);

void editstaff(void);

void searchstaff(void);

void viewstaff(void);

void closeapplication(void);

int  getdata();

int  checkid(int);

int t(void);



void Password();

void issuerecord();

void loaderanim();




//file pointers

FILE* fp, * ft, * fs;


COORD coord = { 0, 0 };



int s;

char findstaff;

char password[10] = { "pass" };



void gotoxy(int x, int y)

{

	coord.X = x; coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //coordinate system created in the screen 

}



struct meroDate //structure used to display time

{

	int mm, dd, yy;

};

struct staff //required details for the students

{

	int id;

	char stname[20];

	char name[20];

	char Teacher[20];
	
	char Collegeinfo[20];

	char Subjectlist[20];

	char ClassSchedule[10];

	char BusInfo[10];

	int count;

	char* cat;

	struct meroDate issued; //variables in merodate

	struct meroDate duedate;

};

struct staff a;

int main()
{

	system("cls");//to clear screen 

	int i;

	gotoxy(20, 3);

	printf(" PES INFORMATION SYSTEM\n ");

	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");


	gotoxy(20, 5);

	printf("<1> Student   ");

	gotoxy(20, 7);

	printf("<2> Admin     ");

	gotoxy(20, 9);

	printf("<3> Close Application");

	gotoxy(20, 11);

	t(); //time is called

	gotoxy(20, 18);

	printf("Enter your choice:");



	switch (getch())

	{

	case '1':

		studentsec();

		break;

	case '2':

		adminsec();

		break;

	case '3':

	{

		system("cls");

		gotoxy(16, 3);

		printf("\tThank You");

		exit(0);

	}

	default:

	{

		gotoxy(10, 25);

		printf("\aWrong Entry!!Please re-entered correct option");

		if (getch())

			main();
	}
}
}	

int adminsec()

{

	Password();

	getch();

	return 0;



}

int studentsec()

{

	searchstudent();

	return 0;


}

void searchstudent()
{
	
	system("cls");

	int d;

	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbSearch Record\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");


	gotoxy(20, 10);

	printf("1. Search By ID");

	gotoxy(20, 14);

	printf("2. Search By Name");

	gotoxy(15, 20);

	printf("Enter Your Choice");

	fp = fopen("stf.dat", "rb+");

	rewind(fp); //takes you to the beginning of the file

	switch (getch())

	{

	case '1':

	{

		system("cls");

		gotoxy(25, 4);

		printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch By Id\xdb\xdb\xdb\xdb\xdb\xdb");

		gotoxy(20, 5);

		printf("Enter the id:");

		scanf("%d", &d);

		gotoxy(20, 7);

		while (fread(&a, sizeof(a), 1, fp) == 1) //to check if it exists

		{

			if (a.id == d)

			{

				Sleep(2);

				gotoxy(20, 6);

				printf("The Record is available\n");

				gotoxy(20, 8);

				printf("ID:%d", a.id);

				gotoxy(20, 9);

				printf("Category:%s", a.cat);

				gotoxy(20, 10);

				printf("Name:%s", a.name);

				gotoxy(20, 11);

				printf("Teacher:%s ", a.Teacher);

				gotoxy(20, 12);

				printf("BusInfo:%s ", a.BusInfo);

				gotoxy(20, 13);

				printf("ClassSchedule:%s", a.ClassSchedule);

				gotoxy(20, 14);

				printf("College Info:%s", a.Collegeinfo);

				gotoxy(20, 15);

				printf("Subject List:%s ", a.Subjectlist);
				
				gotoxy(20, 16);

				findstaff = 't'; 


			}



		}

		if (findstaff != 't') //counter variable to check if record is found 

		{

			printf("\aNo Record Found");

		}

		gotoxy(20, 17);

		printf("Try another search?(Y/N)");

		if (getch() == 'y')

			searchstudent();

		else

			main();

		break;

	}

	case '2':

	{

		char s[15];

		system("cls");

		gotoxy(25, 4);

		printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch Record By Name\xdb\xdb\xdb\xdb\xdb\xdb");

		gotoxy(20, 5);

		printf("Enter the Name:");

		scanf("%s", s);

		int d = 0;

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (strcmp(a.name, (s)) == 0) //checks if the student is existing

			{

				gotoxy(20, d + 7);

				//printf("The Staff is available");

				gotoxy(20, d + 8);

				printf("ID:%d", a.id);

				gotoxy(20, d + 10);

				printf("Name:%s", a.name);

				gotoxy(20, d + 11);

				printf("Teacher:%s", a.Teacher);

				gotoxy(20, d + 12);

				printf("BusInfo:%s", a.BusInfo);

				gotoxy(20, d + 13);

				printf("ClassSchedule:%s", a.ClassSchedule);

				gotoxy(20, d + 14);

				printf("College Info:%s", a.Collegeinfo);

				gotoxy(20, d + 15);

				printf("Subject List:%s", a.Subjectlist);

				gotoxy(20, d + 16);

				getch();

				d += 6;

			}



		}

		if (d == 0)



			printf("\aNo Record Found");



		gotoxy(20, d + 11);

		printf("Try another search?(Y/N)");

		if (getch() == 'y')

			searchstudent();

		else

			main();

		break;

	}

	default:

	{	getch();

		searchstudent();

	}

	fclose(fp);

}
}

void mainmenu()

{

	system("cls");

	int i;

	gotoxy(20, 3);

	printf(" PES admin section \n ");

	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");



	gotoxy(20, 5);

	printf("<1> Add Records   ");

	gotoxy(20, 7);

	printf("<2> Remove Records");

	gotoxy(20, 9);

	printf("<3> Search Records");

	gotoxy(20, 11);

	printf("<4> View Record's list");

	gotoxy(20, 13);

	printf("<5> Modify Record");

	gotoxy(20, 15);

	printf("<6> Back to Main Menu");

	gotoxy(20, 22);

	t();

	gotoxy(20, 18);

	printf("Enter your choice:");



	switch (getch())

	{

	case '1':

		addstaff();

		break;

	case '2':

		deletestaff();

		break;

	case '3':

		searchstaff();

		break;

	case '4':

		viewstaff();

		break;

	case '5':

		editstaff();

		break;

	case '6':

	{

		system("cls");

		gotoxy(16, 3);

                main();

	}

	default:

	{

		gotoxy(10, 25);

		printf("\aWrong Entry!!Please re-entered correct option");

		if (getch())

			mainmenu();

	}



	}

}

void addstaff(void)

{

	system("cls");

	int i;

	gotoxy(20, 5);

	printf("SELECT CATEGORIES");

	gotoxy(20, 7);

	printf("<1> Student");

	gotoxy(20, 9);



	printf("<2> Back to main menu");

	gotoxy(20, 21);



	printf("Enter your choice:");

	scanf("%d", &s);

	if (s == 2)



		mainmenu();

	system("cls");

	fp = fopen("stf.dat", "ab+");

	if (getdata() == 1)

	{

		a.cat = catagories[s - 1];

		fseek(fp, 0, SEEK_END); // to move cursor to end of file 

		fwrite(&a, sizeof(a), 1, fp);

		fclose(fp);

		gotoxy(21, 14);

		printf("The record is sucessfully saved");

		gotoxy(21, 15);

		printf("Save any more?(Y / N):");

		if (getch() == 'n')

			mainmenu();

		else

			system("cls");

		addstaff();

	}

}

void deletestaff()

{

	system("cls");

	int d;

	char another = 'y';

	while (another == 'y')

	{

		system("cls");

		gotoxy(10, 5);

		printf("Enter the ID to  remove:");

		scanf("%d", &d);

		fp = fopen("stf.dat", "rb+");

		rewind(fp);

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (a.id == d)

			{



				gotoxy(10, 7);

				printf("The record is available");

				gotoxy(10, 8);

				printf("Name is %s", a.name);

				gotoxy(10, 9);

				findstaff = 't';

			}

		}

		if (findstaff != 't')

		{

			gotoxy(10, 10);

			printf("No record is found modify the search");

			if (getch())

				mainmenu();

		}

		if (findstaff == 't')

		{

			gotoxy(10, 9);

			printf("Do you want to delete it?(Y/N):");

			if (getch() == 'y')

			{

				ft = fopen("test.dat", "wb+");

				rewind(fp);

				while (fread(&a, sizeof(a), 1, fp) == 1)

				{

					if (a.id != d)

					{

						fseek(ft, 0, SEEK_CUR);//cursor goes to the current position

						fwrite(&a, sizeof(a), 1, ft);

					}

				}

				fclose(ft);

				fclose(fp);

				remove("stf.dat"); //replacing the current file with the temporary file

				rename("test.dat", "stf.dat");

				fp = fopen("stf.dat", "rb+");

				if (findstaff == 't')

				{

					gotoxy(10, 10);

					printf("The record is sucessfully deleted");

					gotoxy(10, 11);

					printf("\n\tDelete another record?(Y/N)");

				}

			}

			else

				mainmenu();

			fflush(stdin);

			another = getch();

		}

	}

	gotoxy(10, 15);

	mainmenu();

}

void searchstaff()

{

	system("cls");

	int d;

	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbSearch Record\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");


	gotoxy(20, 10);

	printf("1. Search By ID");

	gotoxy(20, 14);

	printf("2. Search By Name");

	gotoxy(15, 20);

	printf("Enter Your Choice");

	fp = fopen("stf.dat", "rb+");

	rewind(fp);

	switch (getch())

	{

	case '1':

	{

		system("cls");

		gotoxy(25, 4);

		printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch By Id\xdb\xdb\xdb\xdb\xdb\xdb");

		gotoxy(20, 5);

		printf("Enter the id:");

		scanf("%d", &d);

		gotoxy(20, 7);

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (a.id == d)

			{

				Sleep(2);

				gotoxy(20, 6);

				printf("The Record is available\n");

				gotoxy(20, 8);

				printf("ID:%d", a.id);

				gotoxy(20, 9);

				printf("Category:%s", a.cat);

				gotoxy(20, 10);

				printf("Name:%s", a.name);

				gotoxy(20, 11);

				printf("Teacher:%s ", a.Teacher);

				gotoxy(20, 12);

				printf("BusInfo:%s ", a.BusInfo);

				gotoxy(20, 13);

				printf("ClassSchedule:%s", a.ClassSchedule);

				gotoxy(20, 14);

				printf("College Info:%s", a.Collegeinfo);

				gotoxy(20, 15);

				printf("Subject List:%s ", a.Subjectlist);
				
				gotoxy(20, 16);

				findstaff = 't';


			}



		}

		if (findstaff != 't')

		{

			printf("\aNo Record Found");

		}

		gotoxy(20, 17);

		printf("Try another search?(Y/N)");

		if (getch() == 'y')

			searchstaff();

		else

			mainmenu();

		break;

	}

	case '2':

	{

		char s[15];

		system("cls");

		gotoxy(25, 4);

		printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch Record By Name\xdb\xdb\xdb\xdb\xdb\xdb");

		gotoxy(20, 5);

		printf("Enter the Name:");

		scanf("%s", s);

		int d = 0;

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (strcmp(a.name, (s)) == 0)

			{

				gotoxy(20, d + 7);

				//printf("The Staff is available");

				gotoxy(20, d + 8);

				printf("ID:%d", a.id);

				gotoxy(20, d + 10);

				printf("Name:%s", a.name);

				gotoxy(20, d + 11);

				printf("Teacher:%s", a.Teacher);

				gotoxy(20, d + 12);

				printf("BusInfo:%s", a.BusInfo);

				gotoxy(20, d + 13);

				printf("ClassSchedule:%s", a.ClassSchedule);

				gotoxy(20, d + 14);

				printf("College Info:%s", a.Collegeinfo);

				gotoxy(20, d + 15);

				printf("Subject List:%s", a.Subjectlist);

				gotoxy(20, d + 16);

				getch();

				d += 6;

			}



		}

		if (d == 0)



			printf("\aNo Record Found");



		gotoxy(20, d + 11);

		printf("Try another search?(Y/N)");

		if (getch() == 'y')

			searchstaff();

		else

			mainmenu();

		break;

	}

	default:

		getch();

		searchstaff();

	}

	fclose(fp);

}



void viewstaff(void)

{

	int i = 0, j;

	system("cls");

	gotoxy(1, 1);

	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbRecord List\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");

	gotoxy(2, 2);

	printf("\n CATEGORY === ID ==== NAME ======== Teacher ===== BusInfo ===== ClassSchedule ======= College Info ====== Subject List      ");


	j = 4;

	fp = fopen("stf.dat", "rb");

	while (fread(&a, sizeof(a), 1, fp) == 1)

	{

		gotoxy(1, j);

		printf("%s", a.cat);

		gotoxy(14, j);

		printf("%d", a.id);

		gotoxy(22, j);

		printf("%s", a.name);

		gotoxy(36, j);

		printf("%s", a.Teacher);

		gotoxy(50, j);

		printf("%s", a.BusInfo);

		gotoxy(65, j);

		printf("%s", a.ClassSchedule);

		gotoxy(90, j);
		
		printf("%s", a.Collegeinfo);

		gotoxy(108, j);

		printf("%s", a.Subjectlist);

		gotoxy(130, j);

		printf("\n\n");

		j++;

	}

	fclose(fp);

	gotoxy(35, 25);

	returnfunc();

}

void editstaff(void)

{

	system("cls");

	int c = 0;

	int d, e;

	gotoxy(20, 4);

	printf("\xdb\xdb\xdb\xdb\xdb\xdb Edit Record \xdb\xdb\xdb\xdb\xdb\xdb");

	char another = 'y';

	while (another == 'y')

	{

		system("cls");

		gotoxy(15, 6);

		printf("Enter Id to be edited:");

		scanf("%d", &d);

		fp = fopen("stf.dat", "rb+");

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (checkid(d) == 0)

			{

				gotoxy(15, 7);

				printf("This Member is available");

				gotoxy(15, 8);

				printf("The ID:%d", a.id);

				gotoxy(15, 9);

				printf("Enter new name:");

				scanf("%s", a.name);

				gotoxy(15, 10);

				printf("Enter new Teacher:");

				scanf("%s", a.Teacher);

				gotoxy(15, 11);

				printf("Enter new BusInfo:");

				scanf("%s", &a.BusInfo);

				gotoxy(15, 12);

				printf("Enter New ClassSchedule Name:");

				scanf("%s", &a.ClassSchedule);

				gotoxy(15, 13);

				printf("Enter new College info:");

				scanf("%s", a.Collegeinfo);

				gotoxy(15, 14);

				printf("Enter Subject list:");

				scanf("%s", a.Subjectlist);

				gotoxy(15, 15);

				printf("The record is modified");

				fseek(fp, ftell(fp) - sizeof(a), 0);

				fwrite(&a, sizeof(a), 1, fp);

				fclose(fp);

				c = 1;

			}

			if (c == 0)

			{

				gotoxy(15, 9);

				printf("No record found");

			}

		}

		gotoxy(15, 16);

		printf("Modify another Record?(Y/N)");

		fflush(stdin);

		another = getch();

	}

	returnfunc();

}

void returnfunc(void)

{

	{

		gotoxy(15, 20);

		printf("Press ENTER to return to main menu");

	}

a:

	if (getch() == 13)

		mainmenu();

	else

		goto a;

}

int getdata()

{

	int t;

	gotoxy(20, 3);

	printf("Enter the Information Below");

	gotoxy(20, 4);

	printf("Category:");

	gotoxy(31, 5);

	printf("%s", catagories[s - 1]);

	gotoxy(21, 6);

	printf("ID:\t");

	gotoxy(30, 6);

	scanf("%d", &t);

	if (checkid(t) == 0)

	{

		gotoxy(21, 13);

		printf("\aThe id already exists\a");

		getch();

		mainmenu();

		return 0;

	}

	a.id = t;

	gotoxy(21, 7);

	printf("Name:");

	gotoxy(33, 7);

	scanf("%s", a.name);

	gotoxy(21, 8);

	printf("Teacher:");

	gotoxy(30, 8);

	scanf("%s", a.Teacher);

	gotoxy(21, 9);

	printf("BusInfo:");

	gotoxy(31, 9);

	scanf("%s", a.BusInfo);

	gotoxy(21, 10);

	printf("ClassSchedule:");

	gotoxy(36, 10);

	scanf("%s", a.ClassSchedule);

	gotoxy(21, 11);

	printf("College info:");

	gotoxy(36, 11);

	scanf("%s", a.Collegeinfo);

	gotoxy(21, 12);

	printf("Subject list:");

	gotoxy(36, 12);

	scanf("%s", a.Subjectlist);


	return 1;

}

int checkid(int t)

{

	rewind(fp);

	while (fread(&a, sizeof(a), 1, fp) == 1)

		if (a.id == t)

			return 0;

	return 1;

}

int t(void)

{

	time_t t;

	time(&t);

	printf("Date and time:%s\n", ctime(&t));//shows the current time



	return 0;

}



void Password(void)

{



	system("cls");

	char d[25] = "Password Protected";

	char ch, pass[10];

	int i = 0, j;





	printf("\t\t\t\tWELCOME\n\t\t\t\t  To \n\t\t   \xdb\xdb\xdb\xdb\xdb\xdb College Management System \xdb\xdb\xdb\xdb\xdb\xdb\n");

	printf("\t \n\n\n Enter Password:");



	while (ch != 13)

	{

		ch = getch();

		//ascii value of 8 is backspace and 13 is carriage return 

		if (ch != 13 && ch != 8) {

			putch('*');

			pass[i] = ch;

			i++;

		}

	}

	pass[i] = '\0';

	if (strcmp(pass, password) == 0)

	{

		printf("\n\n\n\t\tPassword matched!!");

		printf("\n\n\tPress any key to countinue.....");

		getch();

		mainmenu();

	}

	else

	{

		printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");

		getch();

		Password();

	}

}