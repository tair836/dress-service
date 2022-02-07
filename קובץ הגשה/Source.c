#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>
#include <time.h>

#define randnum(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))


#define SIZE 300

typedef enum { WOMEN = 0, MAN = 1 }Gender;
typedef enum { FALSE = 0, TRUE = 1 }Bool;


typedef struct {
	int count;
	char numOfItem[7];
}Item;

//////////////////////////////
/////////////////////////////
typedef struct {
	int day, month, year;
}Date;
//////////////////////////////////////////
Date createDate(Date* day);
//////////////////////////////
/////////////////////////////
typedef struct {
	char city[15];
	int postcode;
	char phoneNumber[15];
	char street[15];
	char country[15];
}Address;
//////////////////////////////////////////
Address createAddress();
Bool numberCheck(char str[]);
//////////////////////////////////////////
//////////////////////////////////////////
typedef struct {
	char answer[SIZE];
	int numOfQu;//1-what was the last name of your mother before her marriage?
			   //2-what is the name of your first pet ?
			   //3-where did you learn in elementary school ?
}Question;
//////////////////////////////////////////
Question createQuestion();
//////////////////////////////
/////////////////////////////
typedef struct {
	char userName[SIZE];
	char password[SIZE];
	char firstName[SIZE];
	char lastName[SIZE];
	Date birthDate;
	Gender gender;
	Address address;
	Question question;


}Person;


//////////////////////////////
/////////////////////////////
typedef struct
{
	char numOfTicket[7];
	Date creationDate;
	Person *clientDetails;
	int category;//1-product & stuck
				//2-payment
				//3-returns & refund
				//4-ordered issues
				//5-delivery

	int subcategory;//1.1-I have a question about an item
					//1.2-Are  you getting more stock?
					//------------------------------------
					//2.1-I have a problem at the checkout
					//2.2-Payment options
					//------------------------------------
					//3.1-I have a question about a return/ refund
					//3.2-I need a new return note
					//3.3-How can I return an order?
					//------------------------------------
					//4.1-My item is faulty
					//4.2-Something is missing
					//4.3-I have received the wrong item
					//4.4-I want to cancel an order
					//------------------------------------
					//5.1-where is my order?
					//5.2-I want to change my order
					//5.3-customs charges
					//5.4-Delivery options

	char userDescription[200];
	int status;//1-In process,
			  //2-escalated
			  //3-closed
			  //4-open
	char EmployeeDesctiption[100];
	int severity;//1-urgent
				//2-low severity
				//3-high severity
				//4-normal severity

	char nameEmployee[15];
	char numOfOrder[7];
	char numOfItem[7];


}Ticket;



///////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
char* createPassword(char* password);
Gender createGender();
char* createName(char* name);
///////////////////////////////////////////////////////////////////

Bool run(Person **customerDataBase, Person **employeeDataBase, Person **managerDataBase, Ticket** ticketDataBase, char** itemDataBase, char** orderDataBase);
Bool customerRegister(Person **customerDataBase);
///////////////////////////////////////////////////////////////////

Bool fillDefaultCustomerDataBase(Person **customerDataBase);
Bool fillDefaultEmployeeDataBase(Person **employeeDataBase);
Bool fillDefaultManagerDataBase(Person **managerDataBase);
Bool fillDefaultTicketDataBase(Ticket **ticketDataBase, Person **customerDataBase);
void freeAll(Person **customerDataBase, Person **employeeDataBase, Person **managerDataBase, Ticket **ticketDataBase);
void freeCustomerDateBase(Person **customerDataBase);
void freeEmployeeDateBase(Person **employeeDataBase);
void freeManagerDateBase(Person **managerDataBase);
void freeTicketDateBase(Ticket **ticketDataBase);

///////////////////////////////////////////////////////////////////
Bool logIn(Person **customerDataBase, Person **employeeDataBase, Person **managerDataBase, Ticket **ticketDataBase, char** itemDataBase, char** orderDataBase);
Bool forgatPassword(Person* p);
///////////////////////////////////////////////////////////////////
Bool menuCustomer(Person *pointer, Ticket** ticketDataBase, char** itemDataBase, char** orderDataBase);
Bool menuEmployee(Person *pointer, Ticket** ticketDataBase);
Bool menuManager(Person *pointer, Ticket** ticketDataBase);

///////////////////////////////////////////////////////////////////
//customer
Bool createTicket(Person *pointer, Ticket** ticketDataBase, char** itemDataBase, char** orderDataBase);
char* alphanum(char* st);
void robot();
void previuosTic(Ticket **ticketDataBase, Person *person);
void customerWatchTic(Ticket *ticketDataBase);
void printStatus(Ticket *ticketDataBase);
void searchByUserNameEmp(Ticket **ticketDataBase, Person *pointer);
///////////////////////////////////////////////////////////////////
//employee
void ticketForToday(pointer, ticketDataBase);
void employeeWatchTic(Ticket *ticketDataBase);
void printCustomer(Ticket* ticDataBase);
void printSeverity(Ticket*tic);
void changeTicket(Ticket *ticket, Person* emp);
void searchBy(Person *pointer, Ticket **ticketDataBase);
void searchByDate(Ticket **ticketDataBase, Person*p);
void searchByStatus(Ticket **ticketDataBase, Person*p);
void searchByNumTic(Ticket **ticketDataBase, Person*p);
void searchByCategory(Ticket **ticketDataBase, Person*p);
void searchByFree(Ticket **ticketDataBase, Person*p);
void ticketsInformation(Ticket** ticketDataBase, Person *p);
void searchByOrder(Ticket** ticketDataBase, Person *p);
void searchByItem(Ticket** ticketDataBase, Person *p);

void searchByUserName(Ticket **ticketDataBase, Person *p);
Bool findWords(char str[], char word[]);
///////////////////////////////////////////////////////////////////


sizeCDB = 0; //size of customer database
sizeMDB = 0;//manager
sizeEDB = 0;//Employee
sizeTDB = 0;
numTic = 1;
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
Bool menuCustomer(pointer, ticketDataBase, itemDataBase, orderDataBase);
///////////////////////////////////////////////////////////////////
void red() {
	printf("\033[0;31m");
}
void boldred() {
	printf("\033[1;31m");
}
void green() {
	printf("\033[0;32m");
}
void boldgreen() {
	printf("\033[1;32m");
}
void yellow() {
	printf("\033[0;33m");
}
void boldyellow() {
	printf("\033[1;33m");
}
void blue() {
	printf("\033[0;34m");
}
void boldblue() {
	printf("\033[1;34m");
}
void magenta() {
	printf("\033[0;35m");
}
void boldmagenta() {
	printf("\033[1;35m");
}
void cyan() {
	printf("\033[0;36m");
}
void boldcyan() {
	printf("\033[1;36m");
}

void reset() {
	printf("\033[0m");
}

void clear() {
	int c;
	while ((c = getchar()) != '\n' &&c != EOF);
}
int main() {

	Bool exit = FALSE;
	int zed;
	Person **customerDataBase = (Person**)malloc(sizeof(Person*)*SIZE);
	Person **employeeDataBase = (Person**)malloc(sizeof(Person*)*SIZE);
	Person **managerDataBase = (Person**)malloc(sizeof(Person*)*SIZE);
	Ticket **ticketDataBase = (Ticket**)malloc(sizeof(Ticket*)*SIZE);
	char * itemDataBase[200] = { "dress01","dress02","dress03", "dress04","dress05","dress06","dress07" ,
		"skirt01", "skirt02","skirt03", "skirt04","skirt05", "skirt06","skirt07"
	"shoe01", "shoe02", "ear01","ear02","ear03","ear04","jacket01","jacket02","jacket03","jacket04" };
	char * orderDataBase[200] = { "ord01","ord02", "ord03","ord04", "ord05", "ord06", "ord07", "ord08", "ord09", "ord10",
		"ord11", "ord12", "ord13", "ord14", "ord15", "ord16", "ord17" ,"ord18" ,"ord19" ,"ord20" ,"ord21" ,"ord22" ,"ord23","ord24", "ord25", "ord26", "ord27" ,
		"ord28" ,"ord29" ,"ord30" ,"ord31" ,"ord32" ,"ord33" };
	if (customerDataBase == NULL || employeeDataBase == NULL || managerDataBase == NULL || ticketDataBase == NULL) {
		printf("sorry there is no option to create the database\n");
		freeAll(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase);
		return 1;
	}
	if (fillDefaultCustomerDataBase(customerDataBase) == FALSE) {
		freeAll(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase);

		return 1;
	}
	if (fillDefaultEmployeeDataBase(employeeDataBase) == FALSE) {
		freeAll(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase);

		return 1;
	}
	if (fillDefaultTicketDataBase(ticketDataBase, customerDataBase) == FALSE) {
		freeAll(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase);

		return 1;
	}

	if (fillDefaultManagerDataBase(managerDataBase) == FALSE) {
		freeAll(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase);
		return 1;
	}
	boldred();
	printf("Wellcome to our system\n\n");
	reset();
	while (exit == FALSE)
	{

		if (run(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase, itemDataBase, orderDataBase) == FALSE) {
			freeAll(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase);
			return 1;
		}
		boldred();
		printf("press 1=exit,press diffrent number=enter the program again: ");
		reset();
		int tav;
		do {
			tav = scanf("%d", &zed);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		if (zed == 1) {
			exit = TRUE;
		}
	}

	freeCustomerDateBase(customerDataBase);
	return 0;
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//******************fill in functions*******************

Bool fillDefaultCustomerDataBase(Person **customerDataBase) {

	//customer 1
	customerDataBase[sizeCDB] = (Person*)malloc(sizeof(Person));
	if (customerDataBase[sizeCDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(customerDataBase[sizeCDB]->firstName, "Moria");
	strcpy(customerDataBase[sizeCDB]->lastName, "Amit");
	strcpy(customerDataBase[sizeCDB]->userName, "moria@gmail.com");
	strcpy(customerDataBase[sizeCDB]->password, "moriaamit123#");
	Date d = { 1,1,2000 };
	customerDataBase[sizeCDB]->birthDate = d;
	customerDataBase[sizeCDB]->gender = WOMEN;
	Address a = { "Ashdod",4551,"0594555678","Rashi","Israel" };
	customerDataBase[sizeCDB]->address = a;
	Question q = { "levi",1 };
	customerDataBase[sizeCDB]->question = q;

	sizeCDB++;


	//customer 2
	customerDataBase[sizeCDB] = (Person*)malloc(sizeof(Person));
	if (customerDataBase[sizeCDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(customerDataBase[sizeCDB]->firstName, "Shalom");
	strcpy(customerDataBase[sizeCDB]->lastName, "Choen");
	strcpy(customerDataBase[sizeCDB]->userName, "shalom@gmail.com");
	strcpy(customerDataBase[sizeCDB]->password, "shalom987!");
	Date d1 = { 2,2,1980 };
	customerDataBase[sizeCDB]->birthDate = d1;
	customerDataBase[sizeCDB]->gender = MAN;
	Address a2 = { "NY",1221,"0534567891","Maple","US" };
	customerDataBase[sizeCDB]->address = a2;
	Question q2 = { "dogi",2 };
	customerDataBase[sizeCDB]->question = q2;
	sizeCDB++;

	//customer 3
	customerDataBase[sizeCDB] = (Person*)malloc(sizeof(Person));
	if (customerDataBase[sizeCDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(customerDataBase[sizeCDB]->firstName, "Valdemir");
	strcpy(customerDataBase[sizeCDB]->lastName, "Putin");
	strcpy(customerDataBase[sizeCDB]->userName, "valdmirp@walla.com");
	strcpy(customerDataBase[sizeCDB]->password, "valdemirPut34@");
	Date d2 = { 7,11,1952 };
	customerDataBase[sizeCDB]->birthDate = d2;
	customerDataBase[sizeCDB]->gender = MAN;
	Address a3 = { " Moscow",1221,"0526479509","Bolshaya","Russia" };
	customerDataBase[sizeCDB]->address = a3;
	Question q3 = { "Amoledet",3 };
	customerDataBase[sizeCDB]->question = q3;
	sizeCDB++;




	return TRUE;
}


Bool fillDefaultEmployeeDataBase(Person **employeeDataBase) {

	//employee 1
	employeeDataBase[sizeEDB] = (Person*)malloc(sizeof(Person));
	if (employeeDataBase[sizeEDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(employeeDataBase[sizeEDB]->firstName, "Dani");
	strcpy(employeeDataBase[sizeEDB]->lastName, "Zaguri");
	strcpy(employeeDataBase[sizeEDB]->userName, "dani@gmail.com");
	strcpy(employeeDataBase[sizeEDB]->password, "daniZguri890$");
	Date d = { 10,2,1999 };
	employeeDataBase[sizeEDB]->birthDate = d;
	employeeDataBase[sizeEDB]->gender = MAN;
	Address a = { "Ofakim",7800,"0522985869","Aamasa","Israel" };
	employeeDataBase[sizeEDB]->address = a;
	Question q = { "Meni",3 };
	employeeDataBase[sizeEDB]->question = q;

	sizeEDB++;

	//employee 2
	employeeDataBase[sizeEDB] = (Person*)malloc(sizeof(Person));
	if (employeeDataBase[sizeEDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(employeeDataBase[sizeEDB]->firstName, "Tair");
	strcpy(employeeDataBase[sizeEDB]->lastName, "Shriki");
	strcpy(employeeDataBase[sizeEDB]->userName, "tair@gmail.com");
	strcpy(employeeDataBase[sizeEDB]->password, "tairshriki1!");
	Date d1 = { 24,5,2000 };
	employeeDataBase[sizeEDB]->birthDate = d1;
	employeeDataBase[sizeEDB]->gender = WOMEN;
	Address a2 = { "paris",1246,"0538750432","Oilve","Franch" };
	employeeDataBase[sizeEDB]->address = a2;
	Question q2 = { "Shoki",2 };
	employeeDataBase[sizeEDB]->question = q2;
	sizeEDB++;

	//employee 3
	employeeDataBase[sizeEDB] = (Person*)malloc(sizeof(Person));
	if (employeeDataBase[sizeEDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(employeeDataBase[sizeEDB]->firstName, "Miki");
	strcpy(employeeDataBase[sizeEDB]->lastName, "Mause");
	strcpy(employeeDataBase[sizeEDB]->userName, "Mikma@yahoo.com");
	strcpy(employeeDataBase[sizeEDB]->password, "Mikima89#");
	Date d2 = { 8,12,2001 };
	employeeDataBase[sizeEDB]->birthDate = d2;
	employeeDataBase[sizeEDB]->gender = MAN;
	Address a3 = { "London",1246,"0580645197","Carniby","England" };
	employeeDataBase[sizeEDB]->address = a2;
	Question q3 = { "Doland",1 };
	employeeDataBase[sizeEDB]->question = q3;
	sizeEDB++;


	return TRUE;

}
Bool fillDefaultManagerDataBase(Person **managerDataBase) {
	//mannager 1
	managerDataBase[sizeMDB] = (Person*)malloc(sizeof(Person));
	if (managerDataBase[sizeMDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(managerDataBase[sizeMDB]->firstName, "Yoshef");
	strcpy(managerDataBase[sizeMDB]->lastName, "Hatzdik");
	strcpy(managerDataBase[sizeMDB]->userName, "yoshff@walla.com");
	strcpy(managerDataBase[sizeMDB]->password, "yosefha23%");
	Date d = { 14,1,1998 };
	managerDataBase[sizeMDB]->birthDate = d;
	managerDataBase[sizeMDB]->gender = MAN;
	Address a = { "Milano",4589,"0527529807","Assa","Italy" };
	managerDataBase[sizeMDB]->address = a;
	Question q = { "Maalot",3 };
	managerDataBase[sizeMDB]->question = q;

	sizeMDB++;

	//mannager 2
	managerDataBase[sizeMDB] = (Person*)malloc(sizeof(Person));
	if (managerDataBase[sizeMDB] == NULL) {
		printf("sorry, can't make the customer data base\n");
		return FALSE;
	}
	strcpy(managerDataBase[sizeMDB]->firstName, "Sara");
	strcpy(managerDataBase[sizeMDB]->lastName, "lugasi");
	strcpy(managerDataBase[sizeMDB]->userName, "saralu@yahoo.com");
	strcpy(managerDataBase[sizeMDB]->password, "saralug987!");
	Date d1 = { 23,4,1980 };
	managerDataBase[sizeMDB]->birthDate = d1;
	managerDataBase[sizeMDB]->gender = WOMEN;
	Address a2 = { "Sidney",1221,"0534438907","Agass","Australia" };
	managerDataBase[sizeMDB]->address = a2;
	Question q2 = { "Choen",1 };
	managerDataBase[sizeMDB]->question = q2;
	sizeMDB++;
	return TRUE;
}
Bool fillDefaultTicketDataBase(Ticket **ticketDataBase, Person **customerDataBase) {
	//tic1
	char temp1[7];
	char temp2[7];
	char temp3[7];
	char temp4[7];

	ticketDataBase[sizeTDB] = (Ticket*)malloc(sizeof(Ticket));
	if (ticketDataBase[sizeTDB] == NULL)
		return FALSE;
	strcpy(ticketDataBase[sizeTDB]->numOfTicket, alphanum(temp1));
	Date d = { 1,12, 2015 };
	ticketDataBase[sizeTDB]->creationDate = d;
	ticketDataBase[sizeTDB]->clientDetails = customerDataBase[0];
	ticketDataBase[sizeTDB]->category = 3;
	ticketDataBase[sizeTDB]->subcategory = 3;
	strcpy(ticketDataBase[sizeTDB]->userDescription, "I want to return my product. I purchased a dress how do i do it?");
	ticketDataBase[sizeTDB]->status = 3;
	strcpy(ticketDataBase[sizeTDB]->EmployeeDesctiption, "has been sent an answer to the customer");
	//ticketDataBase[sizeTDB]->EmployeeDesctiption[0] = '\0';
	ticketDataBase[sizeTDB]->severity = 2;
	strcpy(ticketDataBase[sizeTDB]->nameEmployee, "tair@gmail.com");
	strcpy(ticketDataBase[sizeTDB]->numOfOrder, "ord03");
	ticketDataBase[sizeTDB]->numOfItem[0] = '\0';
	sizeTDB++;
	numTic++;

	//tic2
	ticketDataBase[sizeTDB] = (Ticket*)malloc(sizeof(Ticket));
	if (ticketDataBase[sizeTDB] == NULL)
		return FALSE;
	strcpy(ticketDataBase[sizeTDB]->numOfTicket, alphanum(temp2));
	Date d2 = { 12,1, 2017 };
	ticketDataBase[sizeTDB]->creationDate = d2;
	ticketDataBase[sizeTDB]->clientDetails = customerDataBase[0];
	ticketDataBase[sizeTDB]->category = 2;
	ticketDataBase[sizeTDB]->subcategory = 2;
	strcpy(ticketDataBase[sizeTDB]->userDescription, "Hi, what are the payment options on this site?");
	ticketDataBase[sizeTDB]->status = 1;
	strcpy(ticketDataBase[sizeTDB]->EmployeeDesctiption, "");
	ticketDataBase[sizeTDB]->severity = 1;
	strcpy(ticketDataBase[sizeTDB]->nameEmployee, "dani@gmail.com");
	ticketDataBase[sizeTDB]->numOfOrder[0] = '\0';
	ticketDataBase[sizeTDB]->numOfItem[0] = '\0';
	sizeTDB++;
	numTic++;

	//tic3
	ticketDataBase[sizeTDB] = (Ticket*)malloc(sizeof(Ticket));
	if (ticketDataBase[sizeTDB] == NULL)
		return FALSE;
	strcpy(ticketDataBase[sizeTDB]->numOfTicket, alphanum(temp3));
	Date d3 = { 4,5, 2019 };
	ticketDataBase[sizeTDB]->creationDate = d3;
	ticketDataBase[sizeTDB]->clientDetails = customerDataBase[1];
	ticketDataBase[sizeTDB]->category = 1;
	ticketDataBase[sizeTDB]->subcategory = 2;
	ticketDataBase[sizeTDB]->userDescription[0] = '\0';
	ticketDataBase[sizeTDB]->status = 4;
	ticketDataBase[sizeTDB]->EmployeeDesctiption[0] = '\0';
	ticketDataBase[sizeTDB]->severity = 2;
	ticketDataBase[sizeTDB]->nameEmployee[0] = '\0';
	ticketDataBase[sizeTDB]->numOfOrder[0] = '\0';
	strcpy(ticketDataBase[sizeTDB]->numOfItem, "skirt03");
	sizeTDB++;
	numTic++;

	//tic4
	ticketDataBase[sizeTDB] = (Ticket*)malloc(sizeof(Ticket));
	if (ticketDataBase[sizeTDB] == NULL)
		return FALSE;
	strcpy(ticketDataBase[sizeTDB]->numOfTicket, alphanum(temp4));
	Date d4 = { 24,7, 2019 };
	ticketDataBase[sizeTDB]->creationDate = d4;
	ticketDataBase[sizeTDB]->clientDetails = customerDataBase[2];
	ticketDataBase[sizeTDB]->category = 4;
	ticketDataBase[sizeTDB]->subcategory = 2;
	strcpy(ticketDataBase[sizeTDB]->userDescription, "The shoes I ordered did not arrived.");
	ticketDataBase[sizeTDB]->status = 2;
	ticketDataBase[sizeTDB]->EmployeeDesctiption[0] = '\0';
	ticketDataBase[sizeTDB]->severity = 3;
	strcpy(ticketDataBase[sizeTDB]->nameEmployee, "tair@gmail.com");
	strcpy(ticketDataBase[sizeTDB]->numOfOrder, "Ord16");
	strcpy(ticketDataBase[sizeTDB]->numOfItem, "shoe02");
	sizeTDB++;
	numTic++;


	return TRUE;
}

//******************end fill in functions*******************

///////////////////////////////////////////////////////////////////

Bool run(Person **customerDataBase, Person **employeeDataBase, Person **managerDataBase, Ticket**ticketDataBase, char** itemDataBase, char** orderDataBase) {
	int choice;
	int tav;
	reset();
	printf("press 1= register, diffrent number = login: ");
	do {
		tav = scanf("%d", &choice);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);

	if (choice == 1) {
		if (customerRegister(customerDataBase) == FALSE)
			return FALSE;
	}



	printf("\nplease login \n");
	if (!logIn(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase, itemDataBase, orderDataBase)) {
		return FALSE;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////

//******************register functions*******************
Bool customerRegister(Person **customerDataBase) {
	int flag = 1;
	int i;
	char t_username[SIZE];
	char t_password[SIZE];
	char t_name1[SIZE];
	char t_name2[SIZE];

	Date day;
	printf("Hey new customer \n");
	printf("Please enter down here all your details\n");
	customerDataBase[sizeCDB] = (Person*)malloc(sizeof(Person));
	if (customerDataBase[sizeCDB] == NULL || sizeCDB >= SIZE) {
		printf("\nsorry, there is no option to add you to the customer data base\n");
		return FALSE;
	}
	//create username
	int flag1 = 0, count = 0;
	int len = strlen(t_username);
	do
	{
		flag1 = 0;
		boldblue();
		printf("~~Enter username- email address: ");
		reset();
		while (flag1 == 0) {
			count = 0;
			scanf("%s", &t_username);
			clear();

			//;
			for (i = 0; i < len; ++i)
				if (t_username[i] == '@')
					++count;
			if (count == 1)
				flag1 = 1;
			else
				printf("Error input, Please try again\n");
		}
		flag = 1;
		for (i = 0; i < sizeCDB &&flag == 1; i++)
		{
			if (strcmp(t_username, customerDataBase[i]->userName) == 0) {
				printf("\nthe email is already in use please enter diffrent one\n");
				flag = 0;
			}

		}
	} while (flag == 0);
	strcpy(customerDataBase[sizeCDB]->userName, t_username);
	//create password
	strcpy(customerDataBase[sizeCDB]->password, createPassword(t_password));

	//create first name 
	boldblue();
	printf("~~Enter your first name: ");
	reset();
	//;
	strcpy(customerDataBase[sizeCDB]->firstName, createName(t_name1));
	//create last name
	boldblue();
	printf("~~Enter your last name: ");
	reset();
	strcpy(customerDataBase[sizeCDB]->lastName, createName(t_name2));
	//create birthDate
	customerDataBase[sizeCDB]->birthDate = createDate(&day);

	//create Gender 
	customerDataBase[sizeCDB]->gender = createGender();

	//create adrress
	customerDataBase[sizeCDB]->address = createAddress();

	//create question
	customerDataBase[sizeCDB]->question = createQuestion();


	printf("You have successfully registered in the system \n");

	sizeCDB++;
	return TRUE;
}


Date createDate(Date* day) {

	//The function gets a variable from type Date, receices a date from the user, verifies its validity, and returns it.
	int flag = 0;
	boldblue();
	printf("~~Enter your birth date by this order dd/mm/yyyy: \n");
	reset();
	while (flag == 0) {
		//if the date is an invalid date.
		flag = 1;
		int tav;
		printf("Day: ");
		do {
			tav = scanf("%d", &(day->day));
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		printf("Month: ");
		do {
			tav = scanf("%d", &(day->month));
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		printf("Year: ");
		do {
			tav = scanf("%d", &(day->year));
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		if (day->month < 0 || day->month>12)
			flag = 0;
		if (day->month == 1 || day->month == 3 || day->month == 5 || day->month == 7 || day->month == 8 || day->month == 10 || day->month == 12)
			if (day->day < 0 || day->day>31)
				flag = 0;
		if (day->month == 4 || day->month == 6 || day->month == 9 || day->month == 11)
			if (day->day < 0 || day->day>30)
				flag = 0;
		if (day->year < 1900 || day->year>2003) //If the customer is less than 16 or bigger than 120.
			flag = 0;
		if (((day->year % 100 != 0 && day->year % 4 == 0) || (day->year % 400 == 0))) {
			if (day->month == 2) {
				if (day->day < 0 || day->day>29) {
					flag = 0;
				}
			}
		}
		else if (day->month == 2)
			if (day->day < 0 || day->day>28)
				flag = 0;
		if (flag == 0)
			printf("Error input, PLease try again\n");
	}
	return *day;
}

Question createQuestion()
{
	Question qu;
	boldblue();
	printf("~~As part of signing up you must answer security questions:\n");
	printf("Select a security question:\n");
	boldcyan();
	printf("1-what was the last name of your mother before her marriage?\n");
	printf("2-what is the name of your first pet ?\n");
	printf("3-where did you learn in elementary school ?\n");
	reset();
	do
	{
		int tav;
		do {
			tav = scanf("%d", &qu.numOfQu);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		switch (qu.numOfQu)
		{
		case 1:
			printf("Enter what was the last name of your mother before her marriage?: ");
			do {
				gets(qu.answer);
			} while (strlen(qu.answer) == 0);
			break;
		case 2:
			printf("Enter what is the name of your first pet ?: ");
			do {
				gets(qu.answer);
			} while (strlen(qu.answer) == 0);
			break;
		case 3:
			printf("Enter where did you learn in elementary school ?: ");
			do {
				gets(qu.answer);
			} while (strlen(qu.answer) == 0);
			break;
		default://
			printf("Error input, PLease try again\n");
			break;
		}
	} while (qu.numOfQu != 1 && qu.numOfQu != 2 && qu.numOfQu != 3);
	return qu;

}
Address createAddress()
{
	Address add;
	boldblue();
	printf("~~Enter your address:\n");
	blue();
	printf("Country: ");
	reset();
	do {
		gets(add.country);
	} while (strlen(add.country) == 0);
	blue();
	printf("City: ");
	reset();
	do {
		gets(add.city);
	} while (strlen(add.city) == 0);
	blue();
	printf("Street: ");
	reset();
	do {
		gets(add.street);
	} while (strlen(add.street) == 0);
	blue();
	printf("Enter your phone number: ");
	reset();
	do {
		scanf("%s", &(add.phoneNumber));
	} while (!numberCheck(add.phoneNumber));
	clear();
	while (strlen(add.phoneNumber) != 10)
	{
		printf("Wrong input, please enter again\n");
		scanf("%s", &(add.phoneNumber));
		clear();
	}
	blue();
	printf("PostCode: ");
	reset();
	int tav;
	do {
		tav = scanf("%d", &(add.postcode));
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	return add;
}
Bool numberCheck(char str[])
{
	int i, len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i]<'0' || str[i]>'9') {
			printf("Invalid number was entered.\n Enter again: ");
			return FALSE;
		}
	}
	return TRUE;
}

char* createPassword(char* password)
{
	int flag = 0, flagContainNumber, flagContainLetter, flagContainSigns, len;
	boldblue();
	printf("~~Enter a password (8 characters at least, including letters, numbers and signs): ");
	reset();
	scanf("%s", password);
	clear();
	while (!flag)
	{
		flagContainNumber = 0;
		flagContainLetter = 0;
		flagContainSigns = 0;
		len = strlen(password);
		if (len >= 8) {
			for (int i = 0; i < len && !flag; i++)
			{
				if (password[i] >= '0'&&password[i] <= '9')
					flagContainNumber = 1;
				else if ((password[i] >= 'A'&&password[i] <= 'Z') || (password[i] >= 'a'&&password[i] <= 'z'))
					flagContainLetter = 1;
				else if ((password[i] >= '!'&&password[i] <= '/') || (password[i] >= ':'&&password[i] <= '@') || (password[i] >= '['&&password[i] <= '`') || (password[i] >= '{'&&password[i] <= '~'))
					flagContainSigns = 1;
				if (flagContainLetter == 1 && flagContainNumber == 1 && flagContainSigns == 1)
					flag = 1;
			}

		}
		if (!flag)
		{
			printf("The password is invalid, write one with 8 characters at least and letters, numbers and signs: ");
			scanf("%s", password);
			clear();
		}

	}

	return password;
}

Gender createGender() {
	Gender g;
	int flag = 1;
	boldblue();
	printf("~~Enter your gender WOMEN=0, MAN=1: ");
	reset();
	do
	{
		flag = 1;
		int tav;
		do {
			tav = scanf("%d", &g);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		if (g != 1 && g != 0) {
			printf("error input try again: ");
			flag = 0;
		}

	} while (flag == 0);
	return g;

}

char* createName(char* name)
{
	do {
		gets(name);
	} while (strlen(name) == 0);
	int flag = 0;
	int i, length;
	while (!flag)
	{
		while (strlen(name) == 0)
		{
			printf("Illegal name, enter again: ");
			do {
				gets(name);
			} while (strlen(name) == 0);
		}
		length = strlen(name);
		for (i = 0; i < length && !flag; i++)
		{
			if ((name[i]<'A' || name[i]>'Z') && (name[i]<'a' || name[i]>'z')) {
				if (name[i] == ' ') {}
				else {
					flag = 1;
				}
			}
		}
		if (flag)
		{
			printf("Illegal name, enter again: ");
			do {
				gets(name);
			} while (strlen(name) == 0);

			flag = 0;
		}
		else
			flag = 1;
	}

	return name;
}

//******************end register functions*******************




//******************free functions*******************


void freeAll(Person **customerDataBase, Person **employeeDataBase, Person **managerDataBase, Ticket** ticketDataBase) {
	freeCustomerDateBase(customerDataBase);
	freeEmployeeDateBase(employeeDataBase);
	freeManagerDateBase(managerDataBase);
	freeTicketDateBase(ticketDataBase);

}


void freeCustomerDateBase(Person **customerDataBase) {
	for (int i = 0; i < sizeCDB; i++)
	{
		if (customerDataBase[i] != NULL)
			free(customerDataBase[i]);
	}
	if (customerDataBase != NULL)
		free(customerDataBase);
}

void freeEmployeeDateBase(Person **employeeDataBase) {
	for (int i = 0; i < sizeEDB; i++)
	{
		if (employeeDataBase[i] != NULL)
			free(employeeDataBase[i]);
	}
	if (employeeDataBase != NULL)
		free(employeeDataBase);
}

void freeManagerDateBase(Person **managerDataBase) {
	for (int i = 0; i < sizeMDB; i++)
	{
		if (managerDataBase[i] != NULL)
			free(managerDataBase[i]);
	}
	if (managerDataBase != NULL)
		free(managerDataBase);
}
void freeTicketDateBase(Ticket **ticketDataBase) {
	for (int i = 0; i < sizeTDB; i++)
	{
		if (ticketDataBase[i] != NULL)
			free(ticketDataBase[i]);
	}
	if (ticketDataBase != NULL)
		free(ticketDataBase);
}
//******************end free functions*******************



//******************login functions*******************

Bool logIn(Person **customerDataBase, Person **employeeDataBase, Person **managerDataBase, Ticket **ticketDataBase, char** itemDataBase, char** orderDataBase) {
	char t_username[SIZE];
	char t_password[SIZE];
	int flag = 0;
	int myflag = 1;
	int counter = 0, i;
	int iAm = 0;/*0=doesnt exist
			  1=customer
			  2=employee
			  3=manager*/
	Person *pointer = NULL;
	boldgreen();
	printf("\n~Please enter your username: ");
	reset();
	//do
	//{
	for (counter = 0; counter < 3 && myflag == 1; counter++)
	{

		scanf("%s", t_username);
		clear();
		for (i = 0; i < sizeCDB &&iAm == 0; i++)
		{
			if (strcmp(customerDataBase[i]->userName, t_username) == 0) {
				pointer = customerDataBase[i];
				iAm = 1;
				myflag = 0;
			}
		}
		if (iAm == 0) {
			for (i = 0; i < sizeEDB&&iAm == 0; i++)
			{
				if (strcmp(employeeDataBase[i]->userName, t_username) == 0) {
					pointer = employeeDataBase[i];
					iAm = 2;
					myflag = 0;
				}
			}
		}
		if (iAm == 0) {
			for (i = 0; i < sizeMDB&&iAm == 0; i++)
			{
				if (strcmp(managerDataBase[i]->userName, t_username) == 0) {
					pointer = managerDataBase[i];
					iAm = 3;
					myflag = 0;
				}
			}
		}
		if (iAm == 0 && counter < 2 && myflag == 1) {
			printf("please try diffrent email: ");
		}


		//} while (iAm == 0 && counter < 3);
	}

	if (counter == 3 && myflag == 1) {
		printf("we didnt found you email try to register\n");
		if (!run(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase, itemDataBase, orderDataBase)) {
			return FALSE;
		}
	}
	else {


		//check password
		boldgreen();
		printf("~please enter your password: ");
		reset();
		scanf("%s", t_password);
		clear();
		counter = 0;
		flag = 1;
		//do
		//{
		myflag = 1;
		for (counter = 0; counter < 3 && myflag == 1; counter++)
		{


			if (strcmp(t_password, pointer->password) == 0) {
				myflag = 0;
			}
			else if (counter < 2 && myflag == 1) {
				printf("the password is incorrect please try again: ");
				scanf("%s", t_password);
				clear();
			}
			//counter++;

		} //while (flag == 1 && counter < 3);
		if (counter == 3 && myflag == 1) {
			if (forgatPassword(pointer) == FALSE) {
				return FALSE;
			}
			else {
				if (!logIn(customerDataBase, employeeDataBase, managerDataBase, ticketDataBase, itemDataBase, orderDataBase))
					return FALSE;
				else
					return TRUE;

			}

		}


		robot();
		flag = 1;
		if (iAm == 1)
		{
			printf("\n\nHey, Wellcome to the customer manu!\n");

			while (flag == 1) {
				if (!(menuCustomer(pointer, ticketDataBase, itemDataBase, orderDataBase)))
					return FALSE;
				boldyellow();
				printf("To choose again from the customer menu press 1, for log out enter diffrent number:");
				reset();
				int tav;
				do {
					tav = scanf("%d", &i);
					clear();
					if (tav == 0) {
						printf("invalid input,please enter number \n");
					}
				} while (tav == 0);
				if (i != 1)
					flag = 0;
			}
		}
		else if (iAm == 2)
		{
			printf("\n\nHey, Wellcome to the employee manu!\n");

			while (flag == 1) {
				if (!(menuEmployee(pointer, ticketDataBase)))
					return FALSE;
				boldyellow();
				printf("To choose again from the employee menu press 1, for log out enter diffrent number: ");
				reset();
				int tav;
				do {
					tav = scanf("%d", &i);
					clear();
					if (tav == 0) {
						printf("invalid input,please enter number \n");
					}
				} while (tav == 0);
				if (i != 1)
					flag = 0;
			}
		}
		else
		{
			printf("\n\nHey, Wellcome to the manager manu!\n");

			while (flag == 1) {
				if (!(menuManager(pointer, ticketDataBase)))
					return FALSE;
				boldyellow();
				printf("To choose again from the manager menu press 1, for log out enter diffrent number: ");
				reset();
				int tav;
				do {
					tav = scanf("%d", &i);
					clear();
					if (tav == 0) {
						printf("invalid input,please enter number \n");
					}
				} while (tav == 0);
				if (i != 1)
					flag = 0;
			}
		}


	}
	return TRUE;

}

Bool forgatPassword(Person* p) {
	printf("If you forgat your password, answer the question you chose.\n");
	int num_ans = p->question.numOfQu;
	char ans[SIZE];
	if (num_ans == 1)
	{
		printf("what was the last name of your mother before her marriage? ");
		do {
			gets(ans);
		} while (strlen(ans) == 0);
		if (strcmp(ans, p->question.answer) == 0) {
			printf("You succeeded!\nyour password is: %s", p->password);
		}
		else {
			printf("Sorry the answer you entered is invalid, the system is turning off\n");
			return FALSE;
		}
	}
	else if (num_ans == 2)
	{
		printf("what is the name of your first pet? ");
		do {
			gets(ans);
		} while (strlen(ans) == 0);
		if (strcmp(ans, p->question.answer) == 0) {
			printf("You succeeded!\nyour password is: %s", p->password);
		}
		else {
			printf("Sorry the answer you entered is invalid, the system is turning off\n");

			return FALSE;
		}
	}
	else// num_ans=3
	{

		printf("where did you learn in elementary school? ");
		do {
			gets(ans);
		} while (strlen(ans) == 0);
		if (strcmp(ans, p->question.answer) == 0) {
			printf("You succeeded!\nyour password is: %s", p->password);
		}
		else {
			printf("Sorry the answer you entered is invalid,the system is turning off\n");
			return FALSE;
		}
	}
	return TRUE;
}

//******************end login functions*******************


Bool menuCustomer(Person *pointer, Ticket** ticketDataBase, char** itemDataBase, char** orderDataBase) {
	int choice;
	printf("what do you want to do?\n");
	printf("1=Watch previous tickets or 2=Create new ticket: ");
	int tav;
	do {
		tav = scanf("%d", &choice);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	do {
		if (choice == 1) {
			previuosTic(ticketDataBase, pointer);
		}
		else if (choice == 2) {
			//while (!createTicket(pointer, ticketDataBase));
			if (!createTicket(pointer, ticketDataBase, itemDataBase, orderDataBase))
				return FALSE;
		}
		else {
			printf("wrong input\n");
			choice = 2;

		}
	} while (choice != 1 && choice != 2);
	return TRUE;
}


Bool menuEmployee(Person *pointer, Ticket** ticketDataBase) {
	int choice;
	printf("what do you want to do?\n");
	printf("1=Watch the ticket you need to work on today or 2=search ticket by indexes: ");
	int tav;
	do {
		tav = scanf("%d", &choice);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	do {
		if (choice == 1) {
			ticketForToday(pointer, ticketDataBase);
		}
		else if (choice == 2) {
			searchBy(pointer, ticketDataBase);
		}
		else {
			printf("wrong input\n");
			choice = 2;

		}
	} while (choice != 1 && choice != 2);
	return TRUE;
}
Bool menuManager(Person *pointer, Ticket** ticketDataBase)
{
	int choice;
	printf("what do you want to do?\n");
	printf("1=Watch the ticket you need to work on today, 2=search ticket by indexes or 3=watch tickets information: ");
	int tav;
	do {
		tav = scanf("%d", &choice);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	do {
		if (choice == 1) {
			ticketForToday(pointer, ticketDataBase);
		}
		else if (choice == 2) {
			searchBy(pointer, ticketDataBase);

		}
		else if (choice == 3) {
			ticketsInformation(ticketDataBase, pointer);
		}
		else {
			printf("wrong input\n");
			choice = 2;

		}
	} while (choice != 1 && choice != 2 && choice != 3);
	return TRUE;
}




void printStatus(Ticket *ticketDataBase) {
	switch (ticketDataBase->status)
	{
	case 1:
		printf("In process\n");
		break;
	case 2:
		printf("Escalated\n");
		break;
	case 3:
		printf("Closed\n");
		break;
	case 4:
		printf("Open\n");
		break;
	}
}

Bool createTicket(Person *pointer, Ticket** ticketDataBase, char** itemDataBase, char** orderDataBase)
{
	char st[SIZE], ch = 'a';
	int flag = 0, ordFlag = 0, itemFlag = 0;
	int myflag = 1;
	int tav;
	Date today;
	time_t now;
	time_t*ptr_now = &now;
	time(ptr_now);
	struct tm *time = localtime(ptr_now);
	today.year = time->tm_year + 1900;
	today.month = time->tm_mon + 1;
	today.day = time->tm_mday;


	Ticket* currentTicket = (Ticket*)malloc(sizeof(Ticket));
	if (currentTicket == NULL || sizeTDB >= SIZE)
	{
		if (currentTicket == NULL)
			free(currentTicket);

		printf("The ticket creation process failed\n");
		return FALSE;
	}

	(currentTicket->creationDate).day = today.day;
	(currentTicket->creationDate).month = today.month;
	(currentTicket->creationDate).year = today.year;

	currentTicket->clientDetails = pointer;

	currentTicket->numOfTicket[0] = '\0';
	currentTicket->userDescription[0] = '\0';
	currentTicket->numOfItem[0] = '\0';
	currentTicket->nameEmployee[0] = '\0';
	currentTicket->numOfOrder[0] = '\0';
	currentTicket->EmployeeDesctiption[0] = '\0';

	for (int i = 0; myflag == 1; i++)
	{
		myflag = 0, ordFlag = 0, itemFlag = 0;
		printf("~~Enter catgory of this ticket:\n");
		printf("-For product & stuck press 1\n-For payment press 2\n");
		printf("-For returns & refund press 3\n-For ordered issues press 4\n");
		printf("-For delivery press 5\n");
		do {
			tav = scanf("%d", &(currentTicket->category));
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
				myflag = 1;
			}
		} while (tav == 0);
		while (currentTicket->category < 1 || currentTicket->category > 5)
		{
			printf("Category did not found, try again\n");
			do {
				tav = scanf("%d", &(currentTicket->category));
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
		}
		printf("*You chose ");
		switch (currentTicket->category)
		{
		case 1:
			printf("product & stuck, now select a specific category:\n");
			printf("1-I have a question about an item\n");
			printf("2-Are  you getting more stock?\n");
			do {
				tav = scanf("%d", &(currentTicket->subcategory));
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			switch (currentTicket->subcategory)
			{
			case 1:
				printf("*You chose 'I have a question about an item'\n");
				printf("Enter item number: ");
				scanf("%s", &(currentTicket->numOfItem));
				clear();
				for (int i = 0; i < 23 && itemFlag == 0; i++)
				{
					if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
						itemFlag = 1;
				}
				while (itemFlag == 0)
				{
					printf("Wrong item number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfItem));
					clear();
					for (int i = 0; i < 23 && itemFlag == 0; i++)
					{
						if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
							itemFlag = 1;
					}
				}
				printf("Enter a description box:\n");
				do {
					gets(currentTicket->userDescription);
				} while (strlen(currentTicket->userDescription) == 0);
				break;
			case 2:
				printf("*You chose 'Are  you getting more stock?'\n");
				printf("Enter number of item: ");
				scanf("%s", &(currentTicket->numOfItem));
				clear();
				for (int i = 0; i < 23 && itemFlag == 0; i++)
				{
					if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
						itemFlag = 1;
				}
				while (itemFlag == 0)
				{
					printf("Wrong item number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfItem));
					clear();
					for (int i = 0; i < 23 && itemFlag == 0; i++)
					{
						if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
							itemFlag = 1;
					}
				}
				printf("Enter a description box:\n");
				cyan();
				printf("[This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				scanf("%c", &ch);
				clear();
				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);
				}
				break;
			default:
				printf("Input error!!!\nTicket creation process failed, please try opening another ticket again.\n");
				myflag = 1;
				break;
			}
			break;
		case 2:
			printf("payment, now select a specific category:\n");
			printf("1-I have a problem at the checkout\n");
			printf("2-Payment options\n");
			do {
				tav = scanf("%d", &(currentTicket->subcategory));
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			switch (currentTicket->subcategory)
			{
			case 1:
				printf("*You chose 'I have a problem at the checkout'\n");
				printf("Enter a description box:\n");
				do {
					gets(currentTicket->userDescription);
				} while (strlen(currentTicket->userDescription) == 0);

				break;
			case 2:
				printf("*You chose 'Payment options'\n");
				printf("Enter a description box:\n");
				do {
					gets(currentTicket->userDescription);
				} while (strlen(currentTicket->userDescription) == 0);

				break;
			default:
				printf("Input error!!!\nTicket creation process failed, please try opening another ticket again.\n");
				myflag = 1;
				break;
			}
			break;
		case 3:
			printf("returns & refund, now select a specific category:\n");
			printf("1-I have a question about a return/ refund\n");
			printf("2-I need a new return note\n");
			printf("3-How can I return an order?\n");
			do {
				tav = scanf("%d", &(currentTicket->subcategory));
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			switch (currentTicket->subcategory)
			{
			case 1:
				printf("*You chose 'I have a question about a return/ refund'\n");
				printf("Enter number of order: ");
				scanf("%s", &(currentTicket->numOfOrder));
				clear();
				for (int i = 0; i < 33 && ordFlag == 0; i++)
				{
					if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
						ordFlag = 1;
				}
				while (ordFlag == 0)
				{
					printf("Wrong order number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfOrder));
					clear();
					for (int i = 0; i < 33 && ordFlag == 0; i++)
					{
						if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
							ordFlag = 1;
					}
				}
				printf("Enter a description box:\n");
				do {
					gets(currentTicket->userDescription);
				} while (strlen(currentTicket->userDescription) == 0);

				break;
			case 2:
				printf("*You chose 'I need a new return note'\n");
				printf("Enter number of order: ");
				scanf("%s", &(currentTicket->numOfOrder));
				clear();
				for (int i = 0; i < 33 && ordFlag == 0; i++)
				{
					if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
						ordFlag = 1;
				}
				while (ordFlag == 0)
				{
					printf("Wrong order number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfOrder));
					clear();
					for (int i = 0; i < 33 && ordFlag == 0; i++)
					{
						if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
							ordFlag = 1;
					}
				}
				printf("Enter a description box:\n");
				cyan();
				printf("[This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				scanf("%c", &ch);
				clear();
				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);

				}
				break;
			case 3:
				printf("*You chose 'How can I return an order?'\n");
				printf("Enter number of order: ");
				scanf("%s", &(currentTicket->numOfOrder));
				clear();
				for (int i = 0; i < 33 && ordFlag == 0; i++)
				{
					if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
						ordFlag = 1;
				}
				while (ordFlag == 0)
				{
					printf("Wrong order number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfOrder));
					clear();
					for (int i = 0; i < 33 && ordFlag == 0; i++)
					{
						if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
							ordFlag = 1;
					}
				}
				printf("Enter a description box:\n");
				cyan();
				printf("[This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				scanf("%c", &ch);
				clear();
				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);
				}


				break;
			default:
				printf("Input error!!!\nTicket creation process failed, please try opening another ticket again.\n");
				myflag = 1;
				break;
			}
			break;
		case 4:
			printf("ordered issues, now select a specific category:\n");
			printf("1-My item is faulty\n");
			printf("2-Something is missing\n");
			printf("3-I have received the wrong item\n");
			printf("4-I want to cancel an order\n");
			do {
				tav = scanf("%d", &(currentTicket->subcategory));
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			switch (currentTicket->subcategory)
			{
			case 1:
				printf("*You chose 'My item is faulty'\n");
				printf("Enter number of item: ");
				scanf("%s", &(currentTicket->numOfItem));
				clear();
				for (int i = 0; i < 23 && itemFlag == 0; i++)
				{
					if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
						itemFlag = 1;
				}
				while (itemFlag == 0)
				{
					printf("Wrong item number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfItem));
					clear();
					for (int i = 0; i < 23 && itemFlag == 0; i++)
					{
						if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
							itemFlag = 1;
					}
				}
				printf("Enter a description box:\n");
				cyan();
				printf("[ This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				//;
				scanf("%c", &ch);
				clear();

				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);

				}


				break;
			case 2:
				printf("*You chose 'Something is missing'\n");
				printf("Enter number of order: ");
				scanf("%s", &(currentTicket->numOfOrder));
				clear();
				for (int i = 0; i < 33 && ordFlag == 0; i++)
				{
					if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
						ordFlag = 1;
				}
				while (ordFlag == 0)
				{
					printf("Wrong order number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfOrder));
					clear();
					for (int i = 0; i < 33 && ordFlag == 0; i++)
					{
						if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
							ordFlag = 1;
					}
				}
				printf("Enter number of item: ");
				scanf("%s", &(currentTicket->numOfItem));
				clear();
				for (int i = 0; i < 23 && itemFlag == 0; i++)
				{
					if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
						itemFlag = 1;
				}
				while (itemFlag == 0)
				{
					printf("Wrong item number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfItem));
					clear();
					for (int i = 0; i < 23 && itemFlag == 0; i++)
					{
						if (strcmp((itemDataBase)[i], currentTicket->numOfItem) == 0)
							itemFlag = 1;
					}
				}
				printf("Enter a description box:\n");
				cyan();
				printf("[This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				scanf("%c", &ch);
				clear();

				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);

				}

				break;
			case 3:
				printf("*You chose 'I have received the wrong item'\n");
				printf("Enter a description box:\n");
				cyan();
				printf("[This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				//;
				scanf("%c", &ch);
				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);

				}
				break;
			case 4:
				printf("*You chose 'I want to cancel an order'\n");
				printf("Enter number of order: ");
				scanf("%s", &(currentTicket->numOfOrder));
				clear();
				for (int i = 0; i < 33 && ordFlag == 0; i++)
				{
					if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
						ordFlag = 1;
				}
				while (ordFlag == 0)
				{
					printf("Wrong order number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfOrder));
					clear();
					for (int i = 0; i < 33 && ordFlag == 0; i++)
					{
						if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
							ordFlag = 1;
					}
				}
				//;

				printf("Enter a description box:\n");
				cyan();
				printf("[ This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				//;
				scanf("%c", &ch);
				clear();

				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);

				}

				break;
			default:
				printf("Input error!!!\nTicket creation process failed, please try opening another ticket again.\n");
				myflag = 1;
				break;
			}
			break;
		case 5:
			printf("delivery, now select a specific category:\n");
			printf("1-Where is my order?\n");
			printf("2-I want to change my order\n");
			printf("3-Customs charges\n");
			printf("4-Delivery options\n");
			do {
				tav = scanf("%d", &(currentTicket->subcategory));
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			switch (currentTicket->subcategory)
			{
			case 1:
				printf("*You chose 'Where is my order?'\n");
				printf("Enter number of order: ");
				scanf("%s", &(currentTicket->numOfOrder));
				clear();
				for (int i = 0; i < 33 && ordFlag == 0; i++)
				{
					if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
						ordFlag = 1;
				}
				while (ordFlag == 0)
				{
					printf("Wrong order number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfOrder));
					clear();
					for (int i = 0; i < 33 && ordFlag == 0; i++)
					{
						if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
							ordFlag = 1;
					}
				}

				printf("Enter a description box:\n");
				cyan();
				printf("[ This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				//;
				scanf("%c", &ch);
				clear();

				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);
				}

				break;
			case 2:
				printf("*You chose 'I want to change my order'\n");
				printf("Enter number of order: ");
				scanf("%s", &(currentTicket->numOfOrder));
				clear();
				for (int i = 0; i < 33 && ordFlag == 0; i++)
				{
					if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
						ordFlag = 1;
				}
				while (ordFlag == 0)
				{
					printf("Wrong order number was entered, enter again: ");
					scanf("%s", &(currentTicket->numOfOrder));
					clear();
					for (int i = 0; i < 33 && ordFlag == 0; i++)
					{
						if (strcmp((orderDataBase)[i], currentTicket->numOfOrder) == 0)
							ordFlag = 1;
					}
				}
				//;

				printf("Enter a description box:\n");
				cyan();
				printf("[ This is an optional field - to not fill the field press x, otherwise press any char] -->  ");
				reset();
				//;
				scanf("%c", &ch);
				clear();

				if (ch != 'x'&&ch != 'X') {
					printf("Textbox: ");
					do {
						gets(currentTicket->userDescription);
					} while (strlen(currentTicket->userDescription) == 0);

				}

				break;
			case 3:
				printf("*You chose 'Customs charges'\n");
				printf("Enter a description box:\n");
				do {
					gets(currentTicket->userDescription);
				} while (strlen(currentTicket->userDescription) == 0);
				break;
			case 4:
				printf("*You chose 'Delivery options'\n");
				printf("Enter a description box:\n");
				do {
					gets(currentTicket->userDescription);
				} while (strlen(currentTicket->userDescription) == 0);
				break;
			default:
				printf("Input error!!!\nTicket creation process failed, please try opening another ticket again.\n");
				myflag = 1;
				break;
			}
			break;
		default:
			printf("Input error!!!\nTicket creation process failed, please try opening another ticket again.\n");
			myflag = 1;
			break;
		}
	}


	ticketDataBase[sizeTDB] = currentTicket;
	strcpy(ticketDataBase[sizeTDB]->numOfTicket, alphanum(st));
	sizeTDB++;
	numTic++;
	printf("Ticket successfully created your ticket number is %s \n", st);
	currentTicket->nameEmployee[0] = '\0';


	return TRUE;

}

char* alphanum(char* st) {
	int num = numTic;
	st[0] = 't';
	st[1] = 'i';
	st[2] = 'c';
	int j = 3;

	if (num > 0 && num < 10) {
		st[3] = '0';
		st[4] = '0';
		st[5] = num + '0';
	}
	else if (num > 9 && num < 100) {
		st[3] = '0';
		st[4] = num / 10 + '0';
		st[5] = num % 10 + '0';
	}
	else if (num > 99 && num < 1000) {
		st[5] = num % 10 + '0';

		st[3] = num / 100 + '0';
		num = num / 10;
		st[4] = num % 10 + '0';
	}

	st[6] = '\0';

	return st;
}


void robot() {
	long number = 0;
	long you = 0;
	printf("Hey it is a small test to check that you are not a robot\n");
	printf("please write the following number: ");
	number = randnum(10000, 100000);
	printf("%ld \n", number);
	printf("here: ");
	scanf("%ld", &you);
	clear();

	while (number != you)
	{
		printf("try again \n");
		printf("please write the following number: ");
		number = randnum(1000, 10000);
		printf("%ld \n", number);
		printf("here: ");
		scanf("%ld", &you);
		clear();

	}



}

void previuosTic(Ticket **ticketDataBase, Person *person) {
	int choose;
	int flag = 0;
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (strcmp(ticketDataBase[i]->clientDetails->userName, person->userName) == 0) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, otherwise enter diffrent number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);


			if (choose == 1)
				customerWatchTic(ticketDataBase[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("No previous tickets exist \n");
}
void customerWatchTic(Ticket *ticketDataBase) {
	cyan();
	printf("^^^^^^^^^^^^^^^^^^^^^^\n");
	reset();
	printf("Num of ticket: %s\n", ticketDataBase->numOfTicket);
	switch (ticketDataBase->category)
	{
	case 1://product & stuck
		printf("Category: product & stuck\n");
		if (ticketDataBase->subcategory == 1)
		{//1.1
			printf("Subcategory:I have a question about an item:\n");
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			printf("Description box: %s\n", ticketDataBase->userDescription);
			printStatus(ticketDataBase);
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			else
				printf("Number of order: --\n");
		}
		else
		{//1.2
			printf("Subcategory: Are you getting more stock?.\n");
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);

		}
		break;
	case 2://payment
		printf("Category: payment.\n");
		if (ticketDataBase->subcategory == 1)
			printf("Subcategory: I have a problem at the checkout.\n");
		else
			printf("Subcategory:Payment options\n");
		printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
		if (ticketDataBase->userDescription != '\0')//2.1 & 2.2
			printf("Description box: %s\n", ticketDataBase->userDescription);
		else
			printf("Description box: -- \n");
		if (ticketDataBase->numOfOrder != '\0')
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
		else
			printf("Number of order: --\n");
		if (ticketDataBase->numOfItem != '\0')
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
		else
			printf("Number of item: --\n");

		break;
	case 3://returns & refund
	//3.1 || 3.2 ||3.3
		printf("Category:returns & refund\n");
		if (ticketDataBase->subcategory == 1)
			printf("Subcategory:I have a question about a return/ refund.\n");
		else if (ticketDataBase->subcategory == 2)
			printf("Subcategory:I need a new return note");
		else
			printf("How can I return an order?\n");
		printf("Number of order: %s\n", ticketDataBase->numOfOrder);
		printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
		if (ticketDataBase->userDescription != '\0')
			printf("Description box: %s\n", ticketDataBase->userDescription);
		else
			printf("Description box: -- \n");
		if (ticketDataBase->numOfItem != '\0')
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
		else
			printf("Number of item: --\n");
		break;
	case 4://ordered issues
		printf("Category:ordered issues\n");
		if (ticketDataBase->subcategory == 1)
		{//4.1
			printf("Subcategory:My item is faulty\n");
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			else
				printf("Number of order: --\n");
		}
		else if (ticketDataBase->subcategory == 2)
		{
			printf("Subcategory:Something is missing\n");
			printf("Number of order: %s\t", ticketDataBase->numOfOrder);
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
		}
		else if (ticketDataBase->subcategory == 3)
		{
			printf("Subcategory:I have received the wrong item\n");
			printf("%d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			else
				printf("Number of order: --\n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");

		}
		else {
			printf("Subcategory:I want to cancel an order\n");
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");

		}
		break;
	case 5://delivery
		printf("Category:delivery\n");
		if (ticketDataBase->subcategory == 1 || ticketDataBase->subcategory == 2)
		{
			if (ticketDataBase->subcategory == 1)
				printf("Subcategory:where is my order?\n");
			else
				printf("Subcategory:I want to change my order\n");
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");

		}
		else if (ticketDataBase->subcategory == 3 || ticketDataBase->subcategory == 4)
		{
			if (ticketDataBase->subcategory == 3)
				printf("Subcategory:customs charges\n");
			else
				printf("Subcategory:delivery options\n");
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");

		}
		break;
	}
	printf("Status: ");
	printStatus(ticketDataBase);
	printf("\n");
	cyan();
	printf("^^^^^^^^^^^^^^^^^^^^^^\n");
	reset();

}



void employeeWatchTic(Ticket *ticketDataBase) {
	cyan();
	printf("^^^^^^^^^^^^^^^^^^^^^^\n");
	reset();
	printCustomer(ticketDataBase);
	printf("Num of ticket: %s\n", ticketDataBase->numOfTicket);
	switch (ticketDataBase->category)
	{
	case 1://product & stuck
		printf("Category: product & stuck\n");
		if (ticketDataBase->subcategory == 1)
		{//1.1
			printf("Subcategory: I have a question about an item:\n");
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			printf("Description box: %s\n", ticketDataBase->userDescription);
			printStatus(ticketDataBase);
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			else
				printf("Number of order: --\n");
		}
		else
		{//1.2
			printf("Subcategory: Are you getting more stock?.\n");
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			printf("Status: ");
			printStatus(ticketDataBase);
		}
		break;
	case 2://payment
		printf("Category: payment.\n");
		if (ticketDataBase->subcategory == 1)
			printf("Subcategory: I have a problem at the checkout.\n");
		else
			printf("Subcategory:Payment options\n");
		printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
		if (ticketDataBase->userDescription != '\0')//2.1 & 2.2
			printf("Description box: %s\n", ticketDataBase->userDescription);
		else
			printf("Description box: -- \n");
		if (ticketDataBase->numOfOrder != '\0')
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
		else
			printf("Number of order: --\n");
		if (ticketDataBase->numOfItem != '\0')
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
		else
			printf("Number of item: --\n");
		printf("Status: ");
		printStatus(ticketDataBase);
		break;
	case 3://returns & refund
	//3.1 || 3.2 ||3.3
		printf("Category:returns & refund\n");
		if (ticketDataBase->subcategory == 1)
			printf("Subcategory:I have a question about a return/ refund.\n");
		else if (ticketDataBase->subcategory == 2)
			printf("Subcategory:I need a new return note");
		else
			printf("How can I return an order?\n");
		printf("Number of order: %s\n", ticketDataBase->numOfOrder);
		printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
		if (ticketDataBase->userDescription != '\0')
			printf("Description box: %s\n", ticketDataBase->userDescription);
		else
			printf("Description box: -- \n");
		if (ticketDataBase->numOfItem != '\0')
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
		else
			printf("Number of item: --\n");
		printStatus(ticketDataBase);
		break;
	case 4://ordered issues
		printf("Category:ordered issues\n");
		if (ticketDataBase->subcategory == 1)
		{//4.1
			printf("Subcategory:My item is faulty\n");
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			else
				printf("Number of order: --\n");
			printStatus(ticketDataBase);
		}
		else if (ticketDataBase->subcategory == 2)
		{
			printf("Subcategory:Something is missing\n");
			printf("Number of order: %s\t", ticketDataBase->numOfOrder);
			printf("Number of item: %s\n", ticketDataBase->numOfItem);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			printf("Status: ");
			printStatus(ticketDataBase);
		}
		else if (ticketDataBase->subcategory == 3)
		{
			printf("Subcategory:I have received the wrong item\n");
			printf("%d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfOrder != '\0')
				printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			else
				printf("Number of order: --\n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");
			printf("Status: ");
			printStatus(ticketDataBase);
		}
		else {
			printf("Subcategory:I want to cancel an order\n");
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");
			printf("Status: ");
			printStatus(ticketDataBase);
		}
		break;
	case 5://delivery
		printf("Category:delivery\n");
		if (ticketDataBase->subcategory == 1 || ticketDataBase->subcategory == 2)
		{
			if (ticketDataBase->subcategory == 1)
				printf("Subcategory:where is my order?\n");
			else
				printf("Subcategory:I want to change my order\n");
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");
			printf("Status: ");
			printStatus(ticketDataBase);
		}
		else if (ticketDataBase->subcategory == 3 || ticketDataBase->subcategory == 4)
		{
			if (ticketDataBase->subcategory == 3)
				printf("Subcategory:customs charges\n");
			else
				printf("Subcategory:delivery options\n");
			printf("Number of order: %s\n", ticketDataBase->numOfOrder);
			printf("Date: %d/%d/%d\n", ticketDataBase->creationDate.day, ticketDataBase->creationDate.month, ticketDataBase->creationDate.year);
			if (ticketDataBase->userDescription != '\0')
				printf("Description box: %s\n", ticketDataBase->userDescription);
			else
				printf("Description box: -- \n");
			if (ticketDataBase->numOfItem != '\0')
				printf("Number of item: %s\n", ticketDataBase->numOfItem);
			else
				printf("Number of item: --\n");
			printf("Status: ");
			printStatus(ticketDataBase);
		}
		break;
	}
	printf("Severity: ");
	printSeverity(ticketDataBase);
	if (ticketDataBase->EmployeeDesctiption != '\0')
		printf("Employee Desctiption: %s\n", ticketDataBase->EmployeeDesctiption);
	else
		printf("Employee Desctiption:--\n");
	cyan();
	printf("^^^^^^^^^^^^^^^^^^^^^^\n");
	reset();

}
void printCustomer(Ticket* ticDataBase) {
	cyan();
	printf("^^\n");
	reset();
	printf("Customer details:\n");
	printf("Username: %s\n", ticDataBase->clientDetails->userName);
	printf("First name: %s\n", ticDataBase->clientDetails->firstName);
	printf("Last name: %s\n", ticDataBase->clientDetails->lastName);
	printf("address:\nCountry: %s\nCity: %s\nPostcode: %d\nStreet: %s\nPhone: %s\n",
		ticDataBase->clientDetails->address.country, ticDataBase->clientDetails->address.city,
		ticDataBase->clientDetails->address.postcode, ticDataBase->clientDetails->address.street,
		ticDataBase->clientDetails->address.phoneNumber);
	cyan();
	printf("^^\n");
	reset();
}
void printSeverity(Ticket*tic) {
	switch (tic->severity)
	{
	case 1:
		printf("Urgent\n");
		break;
	case 2:
		printf("low severity\n");
		break;
	case 3:
		printf("high severity\n");
		break;
	case 4:
		printf("normal severity\n");
		break;
	}
}



void ticketForToday(Person *pointer, Ticket **ticketDataBase) {
	int choose;
	int flag = 0;
	int flag2 = 0;
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		flag = 0;
		if (ticketDataBase[i]->status != 3) {//close
			if (strcmp(ticketDataBase[i]->nameEmployee, pointer->userName) == 0) { //same person
				flag = 1;
				flag2 = 1;
			}
		}
		if (ticketDataBase[i]->status == 4)//open
			if (ticketDataBase[i]->nameEmployee[0] == '\0') {
				flag = 1;
				flag2 = 1;

			}
		if (flag == 1) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, otherwise enter any number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			printf("if you want to change the ticket press 1,otherwise enter any number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag2 == 0)
		printf("There are not ticket for you to work today \n");
}
void changeTicket(Ticket *ticket, Person* emp) {
	int tav;
	strcpy(ticket->nameEmployee, emp->userName);
	int choose;
	printf("If you want to change status of ticket press 1, otherwise enter any number:\n");
	do {
		tav = scanf("%d", &choose);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	if (choose == 1) {
		printf("Enter status please: ");
		printf("1-In process\n");
		printf("2-Escalated\n");
		printf("3-Closed\n");
		printf("4-Open\n");
		do {
			tav = scanf("%d", &(ticket->status));
			clear();
			if (tav == 0 || ticket->status > 4 || ticket->status < 1) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0 || ticket->status > 4 || ticket->status < 1);
	}
	printf("If you want to change severity of ticket press 1,otherwise enter any number:\n");
	do {
		tav = scanf("%d", &choose);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	if (choose == 1) {
		printf("Enter severity please: ");
		printf("1-Urgent\n");
		printf("2-low severity\n");
		printf("3-high severity\n");
		printf("4-normal severity\n");
		do {
			tav = scanf("%d", &ticket->severity);
			clear();
			if (tav == 0 || ticket->severity > 4 || ticket->severity < 1) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0 || ticket->severity > 4 || ticket->severity < 1);
	}
	printf("If you want to change description-employee of ticket press 1, for exit enter any diffrent number:\n");
	do {
		tav = scanf("%d", &choose);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	if (choose == 1) {
		printf("Enter description:\n ");
		do {
			gets(ticket->EmployeeDesctiption);
		} while (strlen(ticket->EmployeeDesctiption) == 0);

	}
}




void searchBy(Person *pointer, Ticket **ticketDataBase) {
	int choice;
	printf("How do you want to search? \n");
	printf("by creation date press 1\n");
	printf("by status press 2\n");
	printf("by number of the ticket press 3\n");
	printf("by category press 4\n");
	printf("by user name press 5\n");
	printf("by the name of the employee that work on it press 6\n");
	printf("by free words press 7\n");
	printf("by product number press 8\n");
	printf("by order number press 9\n");
	int tav;
	do {
		tav = scanf("%d", &choice);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	do {
		switch (choice)
		{
		case 1:
			searchByDate(ticketDataBase, pointer);
			break;
		case 2:
			searchByStatus(ticketDataBase, pointer);
			break;
		case 3:
			searchByNumTic(ticketDataBase, pointer);
			break;
		case 4:
			searchByCategory(ticketDataBase, pointer);
			break;
		case 5:
			searchByUserName(ticketDataBase, pointer);
			break;
		case 6:
			searchByUserNameEmp(ticketDataBase, pointer);
			break;
		case 7:
			searchByFree(ticketDataBase, pointer);
			break;
		case 8:
			searchByItem(ticketDataBase, pointer);
			break;
		case 9:
			searchByOrder(ticketDataBase, pointer);
			break;

		default:
			printf("the number is invalid try again later\n");
			do {
				tav = scanf("%d", &choice);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			break;
		}
	} while (choice > 9 || choice < 1);
}

void searchByDate(Ticket **ticketDataBase, Person * pointer) {
	int choose;
	int day, mon, year;
	int flag = 0;
	int tav;
	printf("enter the date you are looking for by this order dd/mm/yyyy: \n");
	printf("Day: ");
	do {
		tav = scanf("%d", &day);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	printf("Month: ");
	do {
		tav = scanf("%d", &mon);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	printf("Year: ");
	do {
		tav = scanf("%d", &year);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (ticketDataBase[i]->creationDate.day == day && ticketDataBase[i]->creationDate.month == mon && ticketDataBase[i]->creationDate.year == year) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1,  otherwise press any number: ");
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag == 0)
		printf("There are not tickets from this day \n");
}
void searchByStatus(Ticket **ticketDataBase, Person *pointer) {
	int choose;
	int flag = 0;
	int status;
	printf("enter the status you are looking for: \n");
	printf("1= in process, 2=escalated, 3=closed, 4=open: ");
	int tav;
	do {
		tav = scanf("%d", &status);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (ticketDataBase[i]->status == status) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, otherwise press any number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag == 0)
		printf("There are no tickets in this status \n");
}
void searchByNumTic(Ticket **ticketDataBase, Person *pointer) {
	int choose;
	int flag = 0;
	char num[7];
	printf("enter the number of ticket you are looking for: \n");
	scanf("%s", &num);
	clear();

	//;

	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (strcmp(ticketDataBase[i]->numOfTicket, num) == 0) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, for exit enter any diffrent number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag == 0)
		printf("There are no tickets with this number \n");
}
void searchByCategory(Ticket **ticketDataBase, Person *pointer) {
	int choose;
	int flag = 0;
	int cat, subcat;
	int tav;
	printf("enter the category you are looking for: \n");
	printf("1- product & stuck\n");
	printf("2- payment.\n");
	printf("3-returns & refund\n");
	printf("4-ordered issues\n");
	printf("5-delivery\n");
	do {
		tav = scanf("%d", &cat);
		clear();
		if (tav == 0) {
			printf("invalid input,please enter number \n");
		}
	} while (tav == 0);
	printf("enter the subcategory you are looking for:\n ");
	switch (cat) {
	case 1:
		printf("1-I have a question about an item\n");
		printf("2-Are  you getting more stock?\n");
		do {
			tav = scanf("%d", &subcat);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		break;
	case 2:
		printf("1-I have a problem at the checkout\n");
		printf("2-Payment options\n");
		do {
			tav = scanf("%d", &subcat);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		break;
	case 3:
		printf("1-I have a question about a return/ refund\n");
		printf("2-I need a new return note\n");
		printf("3-How can I return an order?\n");
		do {
			tav = scanf("%d", &subcat);
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		break;
	case 4:
		printf("1-My item is faulty\n");
		printf("2-Something is missing\n");
		printf("3-I have received the wrong item\n");
		printf("4-I want to cancel an order\n");
		do {
			tav = scanf("%d", &subcat);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		break;
	case 5:
		printf("1-where is my order?\n");
		printf("2-I want to change my order\n");
		printf("3-customs charges\n");
		printf("4-Delivery options\n");
		do {
			tav = scanf("%d", &subcat);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		break;
	default:
		printf("No found.\n");
		break;
	}
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (ticketDataBase[i]->category == cat && ticketDataBase[i]->subcategory == subcat) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag == 0)
		printf("There are not tickets in this category \n");
}
void searchByUserName(Ticket **ticketDataBase, Person *pointer) {
	int choose;
	int flag = 0;
	char num[50];
	printf("enter the user name you are looking for: \n");
	scanf("%s", num);
	clear();

	//;

	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (strcmp(ticketDataBase[i]->clientDetails->userName, num) == 0) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1,  otherwise press any diffrent number : ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag == 0)
		printf("There are no tickets with this user name \n");
}
void searchByUserNameEmp(Ticket **ticketDataBase, Person *pointer) {
	int choose;
	int flag = 0;
	char num[50];
	printf("enter the employee name you are looking for: \n");
	scanf("%s", num);
	clear();

	//;

	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (strcmp(ticketDataBase[i]->nameEmployee, num) == 0) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1,  otherwise press any diffrent number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag == 0)
		printf("There are no tickets with this user name \n");



}
void searchByFree(Ticket **ticketDataBase, Person *pointer) {
	int choose;
	int flag = 0;
	char num[50];
	printf("enter the word you are looking for: \n");
	scanf("%s", num);
	clear();
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (findWords(ticketDataBase[i]->userDescription, num) == 1) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, otherwise press any diffrent number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], pointer);
		}
	}
	if (flag == 0)
		printf("There are no tickets with this word \n");
}


void searchByOrder(Ticket** ticketDataBase, Person *p) {
	int choose;
	int flag = 0;
	char num[50];
	printf("enter the order number you are looking for: \n");
	scanf("%s", num);
	clear();
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (strcmp(ticketDataBase[i]->numOfOrder, num) == 0) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, otherwise press any diffrent number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], p);
		}
	}
	if (flag == 0)
		printf("There are no tickets with this order number \n");
}
void searchByItem(Ticket** ticketDataBase, Person *p) {
	int choose;
	int flag = 0;
	char num[50];
	printf("enter the product number you are looking for: \n");
	scanf("%s", num);
	clear();
	printf("Choose ticket to view: \n");
	for (int i = 0; i < sizeTDB; i++) {
		if (strcmp(ticketDataBase[i]->numOfItem, num) == 0) {
			yellow();
			printf("Ticket number: %s.\n", ticketDataBase[i]->numOfTicket);
			reset();
			printf("if you want to see the whole ticket press 1, otherwise press any diffrent number: ");
			int tav;
			do {
				tav = scanf("%d", &choose);
				clear();
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				employeeWatchTic(ticketDataBase[i]);
			flag = 1;
			printf("if you want to change the ticket press 1,otherwise press any diffrent number: ");
			do {
				tav = scanf("%d", &choose);
				if (tav == 0) {
					printf("invalid input,please enter number \n");
				}
			} while (tav == 0);
			if (choose == 1)
				changeTicket(ticketDataBase[i], p);
		}
	}
	if (flag == 0)
		printf("There are no tickets with this product number \n");
}

Bool findWords(char str2[], char word2[]) {
	if (str2[0] == '\0') {
		return FALSE;
	}
	char *str = NULL;
	char *word = NULL;
	str = _strlwr(str2);
	word = _strlwr(word2);
	int count = 0;
	int i = 0, j = 0;
	//checking the first index. Without checking a spacious before
	while (str[i] == word[j] && word[j] != '\0')
	{
		++i;
		++j;

		if (word[j] == '\0' && (str[i] == ' ' || str[i] == '\0' || str[i] == ',' || str[i] == '.' || str[i] == '?' || str[i] == '!'))
			//if (it's the end of the word)
		{
			++count;
		}

	}

	for (; str[i] != '\0';)
	{
		//checking the other indexes
		j = 0;

		if (str[i] == ' ' && (str[i + 1] == word[j]))
			/*if(there is no spacious before) */
		{
			++i;
			while (str[i] == word[j] && word[j] != '\0')
			{
				++i;
				++j;
				if (word[j] == '\0' && (str[i] == ' ' || str[i] == '\0' || str[i] == ',' || str[i] == '.' || str[i] == '?' || str[i] == '!'))
					++count;
			}
		}
		else
			++i;
	}
	if (count > 0)
		return TRUE;
	return FALSE;
}


void ticketsInformation(Ticket** ticketDataBase, Person *pointer) {
	int choise, j, flag = 1, flag1 = 0, i, count = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count11 = 0, count12 = 0, count21 = 0, count22 = 0, count31 = 0, count32 = 0, count33 = 0, count41 = 0, count42 = 0, count43 = 0, count44 = 0, count51 = 0, count52 = 0, count53 = 0, count54 = 0;

	Item item[100];
	for (i = 0; i < 100; ++i)
		item[i].count = 0;
	int size = 0, max = 0;

	printf("What do you want to know?\n1.How many tickets there are in each category.\n2.How many tickets need to be solved.\n");
	printf("3.Particular item that has the most tickets.\n4.Particular category that has the most tickets.\n");
	while (flag == 1) {
		flag = 0;
		int tav;
		do {
			tav = scanf("%d", &choise);
			clear();
			if (tav == 0) {
				printf("invalid input,please enter number \n");
			}
		} while (tav == 0);
		switch (choise) {
		case(1): {
			for (i = 0; i < sizeTDB; ++i) {
				if (ticketDataBase[i]->category == 1) {
					++count1;
					if (ticketDataBase[i]->subcategory == 1)
						++count11;
					if (ticketDataBase[i]->subcategory == 2)
						++count12;
				}
				if (ticketDataBase[i]->category == 2) {
					++count2;
					if (ticketDataBase[i]->subcategory == 1)
						++count21;
					if (ticketDataBase[i]->subcategory == 2)
						++count22;
				}
				if (ticketDataBase[i]->category == 3) {
					++count3;
					if (ticketDataBase[i]->subcategory == 1)
						++count31;
					if (ticketDataBase[i]->subcategory == 2)
						++count32;
					if (ticketDataBase[i]->subcategory == 3)
						++count33;
				}
				if (ticketDataBase[i]->category == 4) {
					++count4;
					if (ticketDataBase[i]->subcategory == 1)
						++count41;
					if (ticketDataBase[i]->subcategory == 2)
						++count42;
					if (ticketDataBase[i]->subcategory == 3)
						++count43;
					if (ticketDataBase[i]->subcategory == 4)
						++count44;
				}
				if (ticketDataBase[i]->category == 5) {
					++count5;
					if (ticketDataBase[i]->subcategory == 1)
						++count51;
					if (ticketDataBase[i]->subcategory == 2)
						++count52;
					if (ticketDataBase[i]->subcategory == 3)
						++count53;
					if (ticketDataBase[i]->subcategory == 4)
						++count54;
				}
			}
			printf("1-product & stuck:%d\n\t1.1-I have a question about an item:%d\n\t1.2-Are  you getting more stock?:%d\n2-payment:%d\n\t2.1-I have a problem at the checkout:%d\n\t2.2-Payment options:%d\n3-returns & refund:%d\n\t3.1 - I have a question about a return / refund:%d\n\t3.2-I need a new return note:%d\n\t3.3-How can I return an order?:%d\n4-ordered issues:%d\n\t4.1-My item is faulty:%d\n\t4.2-Something is missing:%d\n\t4.3-I have received the wrong item:%d\n\t4.4-I want to cancel an order:%d\n5-delivery:%d\n\t5.1-where is my order?:%d\n\t5.2-I want to change my order:%d\n\t5.3-customs charges:%d\n\t5.4-Delivery options:%d\n", count1, count11, count12, count2, count21, count22, count3, count31, count32, count33, count4, count41, count42, count43, count44, count5, count51, count52, count53, count54);
			break;
		}
		case(2): {
			count = 0;
			for (i = 0; i < sizeTDB; ++i) {
				if (ticketDataBase[i]->status != 3)
					++count;
			}
			printf("There are %d problems that need to be solved\n", count);
			break;
		}
		case(3): {
			char max_item[8] = { "no item\0" };
			size = 0;
			for (i = 0; i < sizeTDB && i < 100; ++i) {
				flag1 = 0;
				if (ticketDataBase[i]->numOfItem[0]) {
					for (j = 0; j < size; ++j) {
						if (!(strcmp(ticketDataBase[i]->numOfItem, item[j].numOfItem))) {
							flag1 = 1;
							(item[j].count)++;
						}
					}
					if (flag1 == 0) {
						strcpy(item[j].numOfItem, ticketDataBase[i]->numOfItem);
						++size;
						(item[j].count)++;
					}
				}
			}
			for (i = 0; i < size; ++i) {
				if (max < item[i].count) {
					max = item[i].count;
					strcpy(max_item, item[i].numOfItem);
				}
			}
			printf("The item that has the most tickets is %s\n", max_item);
			break;
		}
		case(4): {
			count1 = 0;
			count2 = 0;
			count3 = 0;
			count4 = 0;
			count5 = 0;
			for (i = 0; i < sizeTDB; ++i) {
				if (ticketDataBase[i]->category == 1)
					++count1;
				if (ticketDataBase[i]->category == 2)
					++count2;
				if (ticketDataBase[i]->category == 3)
					++count3;
				if (ticketDataBase[i]->category == 4)
					++count4;
				if (ticketDataBase[i]->category == 5)
					++count5;
			}
			printf("The category that has the most tickets is ");
			if (count1 >= count2 && count1 >= count3 && count1 >= count4 && count1 >= count5)
				printf("product & stuck\n");
			if (count2 >= count1 && count2 >= count3 && count2 >= count4 && count2 >= count5)
				printf("payment\n");
			if (count3 >= count2 && count3 >= count1 && count3 >= count4 && count3 >= count5)
				printf("returns & refund\n");
			if (count4 >= count2 && count4 >= count3 && count4 >= count1 && count4 >= count5)
				printf("ordered issues\n");
			if (count5 >= count2 && count5 >= count3 && count5 >= count4 && count5 >= count1)
				printf("delivery\n");
			break;
		}
		default: {
			printf("Error input, Please try again\n");
			flag = 1;
		}
		}
	}

}