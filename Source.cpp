#include<iostream>
#include<string>
#include<stdlib.h>
#include<Windows.h>
#include<iomanip>
#include <fstream>
using namespace std;
int totaldaysearning = 0;
struct order_food
{
	string data; int price; order_food* link = NULL;
};
class stack {
	order_food* top = NULL;
public:
	void push() {
		cout << "\n \t\t* * * *  MENU  * * * * ";
		cout << "\n\n\n BURGERS "; cout << "\n \t1> Krunch Burger                     250 PKR ";
		cout << "\n \t2> Zinger Burger                     450 PKR ";
		cout << "\n \t3> JALAPENO Special                  750 PKR ";
		cout << "\n\n PIZZA :"; cout << "\n \t4> Chicken Tikka                     999 PKR ";
		cout << "\n \t5> Chicken Fajita                   1199 PKR ";
		cout << "\n \t6> Chicken Tandoori                 1299 PKR ";
		cout << "\n\n DRINKS :"; cout << "\n \t7> Pepsi                             100 PKR ";
		cout << "\n \t8> Monster Drink                     180 PKR ";
		cout << "\n \t9> Whiskey Red Label                 480 PKR ";
		cout << "\n_____________________________________________________________";
		cout << "\n\n	\tENTER THE OPTION :   "; int nn; cin >> nn; string data; int p = 0;
		switch (nn) {
		case 1:data = "Krunch Burger"; p = 250; break; case 2:data = "Zinger  Burger"; p = 450; break; case 3:data = "JALAPENO Burger"; p = 750; break;
		case 4:data = "Chicken Tikka"; p = 999; break; case 5:data = "Chicken Fajita"; p = 1199; break; case 6:data = "Chicken Tandoori"; p = 1299; break;
		case 7:data = "Pepsi"; p = 100; break; case 8:data = "Monster Drink"; p = 180; break;	case 9:data = "Whiskey Red Label"; p = 480; break;
		}
		order_food* temp = new order_food();
		if (top == NULL) {
			temp->data = data;	temp->price = p;	top = temp;
		}
		else { temp->data = data;	temp->price = p;	temp->link = top;	top = temp; }
	}
	void pop() {
		order_food* current = NULL;
		if (top == NULL) {
			cout << "NO FOOD ORDERED YET" << endl;
		}
		else { current = top; top = top->link; }	delete current;
	}
	int display()
	{
		order_food* current = top;	cout << "\n"; int sumtotal = 0;
		while (current->link != NULL) {
			cout << current->data << "      " << current->price << endl;
			sumtotal += current->price; current = current->link;
		}
		cout << current->data << "      " << current->price << endl;	sumtotal += current->price;
		cout << endl;
		cout << "                   TOTAL BILL : " << sumtotal << "PKR" << endl;
		cout << "__________________________________________" << endl; return sumtotal;
	}
	int totalprice()
	{
		int sumtotal = 0; order_food* current = top;
		while (current->link != NULL) {
			sumtotal += current->price;
			current = current->link;
		}
		sumtotal += current->price; return sumtotal;
	}
};
struct table { int data = 9191; string name; stack x; table* link = NULL; };
class queue {
	int totaltables = 6;	table* front = NULL; table* rear = NULL;
public:	void displaytotalorder() {
	table* temp = front;
	cout << "\n______________________________________________________________" << endl;
	cout << "TOTAL ORDERS RIGHT NOW TO BE SERVED ARE:";
	if (front == NULL)
	{
		cout << "\nNO ORDERES YET.\n";	return;
	}
	if (front != NULL)
	{
		while (temp != NULL) { totaldaysearning += temp->x.display(); temp = temp->link; }
		cout << "THE TOTAL EARNING IS : " << totaldaysearning << endl;
	}
	else { cout << "\nNO ORDERES YET.\n"; }
}
	  void orderontable(string d)
	  {
		  int founder = 0;	table* temp = front; 	if (temp != NULL)
		  {
			  while (temp != NULL)
			  {
				  if (temp->name == d)
				  {
					  founder = 1; break;
				  }	temp = temp->link;
			  }
			  if (founder == 1) if (temp->name == d)
			  {
				  int lx = -0; do {
					  temp->x.push();
					  cout << "ENTER -1 IF YOU DONT WANT TO ORDER MORE FOOD.";	 cin >> lx;
				  } while (lx != -1);
			  }
		  }
		  else { cout << "\nNO ONE IS SITTING ON ANY TABLE. \n"; }
	  }
	  void enqueue(int data) {
		  if (totaltables <= 6) {
			  string x; cout << "\n WHAT IS YOUR NAME SIR : "; cin >> x;
			  table* temp = new table(); if (front == NULL) {
				  temp->data = data;	temp->name = x;	front = temp; rear = temp; rear->link = NULL;
				  cout << "\n YOUR TABLE IS RESERVED .\n NOW KINDLY TAKE A SEAT : MR/MRS  " << temp->name << endl;
			  }

			  else
			  {
				  temp->data = data;	temp->name = x; rear->link = temp; rear = temp;
				  cout << "\n YOUR TABLE IS RESERVED .\n NOW KINDLY TAKE A SEAT : MR/MRS  " << temp->name << endl;
			  }
		  }
		  else {
			  cout << "ALL TABLES ARE RESERVED.";
		  }
	  }
	  void file_save()
	  {
		  ofstream fileb;	table* temp = front;
		  fileb.open("game_savefile.txt", ios::app);
		  fileb << "____________________________________________________________" << endl;
		  fileb << "The CUSTOMER WAS          : " << temp->name;
		  fileb << endl << "The TOTAL BILL is : " << temp->x.totalprice() << " PKR" << endl;
		  fileb << "____________________________________________________________" << endl;
		  fileb.close();
	  }
	  void dequeue(string d) {
		  cout << "\nWelcome TO THE COUNTER . (HOPE YOU LIKED OUR SERVICES)" << endl;
		  table* temp = front;	int s = temp->x.display();
		  if (front->link == NULL)
		  {
			  front = NULL; return;
		  }
		  if (temp != NULL) { front = temp->link; }	delete temp;
	  }
	  void deqprit(string tn)
	  {
		  table* temp = front, * trc = front;
		  if (front != NULL)
		  {
			  while (temp->name != tn)
			  {
				  if (temp->link == NULL)
				  {
					  cout << "THAT CUSTOMER DOES NOT EXIST";	break;
				  }
				  else
				  {
					  trc = temp;	temp = temp->link;
				  }
			  }
			  if (temp->name == tn)
			  {
				  if (temp->link != NULL)
				  {
					  trc->link = temp->link;	temp->link = front;	front = temp;
				  }
				  else {
					  trc->link = NULL;	temp->link = front;	front = temp;
				  }
			  }
		  }
		  else cout << "NO SUCH CUSTOMER";
	  }
};
int main() {
	system("COLOR 7D"); cout << "\n\n\n\n|***************************************************************";
	cout << "*****************|";
	cout << "\n|\t\t\t\t             CREATED BY :                        |";
	cout << "\n|                                                     \t\t\t\t |";
	cout << " \n|\t\t\t\tSYED DURRAIZ AZAM SHAH			         |";
	cout << "\n|                                                     \t\t\t\t |";
	cout << "\n|                                                     \t\t\t\t |";
	cout << "\n|                                                     \t\t\t\t |";
	cout << "\n|***********************************************************";
	cout << "*********************|"; cout << "\n\n\n\n\n\n\n\n\n";
	Sleep(2500); system("CLS");
	system("COLOR 7C");
	for (int i = 0; i <= 100; i++)
	{
		cout << "\n\n\n\n\t\t\t\tNOW LOADING THE  MENU\n";
		cout << "|\t\t\t\t\t\t\t\t\t\t\t\t     |   " << i << "%\n";
		for (int j = 0; j <= i; j++)	cout << "-"; Sleep(25); system("CLS");
	}Sleep(1000);
	system("CLS"); queue x;	int m;
	int  num = 0;	string nn; int run = 0;
	do {
		cout << " \n\n\t\t ___MENU___\n"; cout << "\nPRESS 1 TO BOOK A TABLE"; cout << "\nPRESS 2 TO ORDER FOOD";
		cout << "\nPRESS 3 TO SHOW TOTAL ORDERES"; cout << "\nPRESS 4 TO CHECK OUT."; cout << "\nPRESS -11 TO EXIT FROM MENU\n\n";
		cin >> m;		switch (m)
		{
		case 1: if (num <= 6) { x.enqueue(num);	num++; }
			  else cout << "\n SORRY ALL TABLES ARE BOOKED. NOW GO AWAY.";	break;
		case 2: cout << "ENTER ON WHICH  CUSTOMER HAS ASKED FOR THE MENU\n"; cin >> nn; x.orderontable(nn); break;		case 3:	x.displaytotalorder();	break;
		case 4: cout << "WHATS YOUR NAME SIR : "; string  ss;	cin >> ss;
			x.deqprit(ss);	x.file_save();	x.dequeue(ss);	num--;	break;
		}
	} while (run != -11); return 0;
}

