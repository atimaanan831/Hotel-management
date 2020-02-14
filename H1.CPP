#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<iostream.h>

class Hotel
{
	public:
	int room_number;
	char name[30];
	char address[50];
	char phone[10];
 
	public:     
     int getRoomNumber()
     {
     	return room_number;
     }
     char* getName()
     {
     	return name;
     }
     char* getAddress()
     {
     	return address;
     }
     
     char* getPhone()
     {
     	return phone;
     }
     void report()
     {
	 	cout<<room_number<<setw(10)<<name<<setw(20)<<address<<setw(20)<<phone<<endl;
     }
};
