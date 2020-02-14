#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<iostream.h>
#include "H1.cpp"
 
class CustomerService : public Hotel
{
	public:
	void add_customer()
 	{
     	cout<<endl<<"Enter The Room Number: ";
        cin>>room_number;
        cout<<endl<<"Enter The Customer's name: ";
        cin.ignore();
        cin.getline(name,30);
        cout<<endl<<"Enter The Customer's address: ";
        cin.ignore();
        cin.getline(address,50);
        cout<<endl<<"Enter The Customer's phone #: ";
        cin.ignore();
        cin.getline(phone,10);
        cout<<"\t\t\n\nCustomer added Successfully...";
    }
	    
	void modify_customer_record()
    {
        cout<<endl<<"Room number : "<<room_number;
        cout<<endl<<"Modify Customer's Name : ";
        cin.ignore();
        cin.getline(name,30);
        cout<<endl<<"Modify Customer's address: ";
        cin.ignore();
        cin.getline(address,50);
        cout<<endl<<"Modify Customer's phone #: ";
        cin.ignore();
        cin.getline(phone,10);
     }
};
