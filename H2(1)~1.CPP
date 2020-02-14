#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<iostream.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include <string.h>
#include "C1.cpp"

static int noOfRecords = 0;
int k=0,bt,memo=1;
union REGS i,o;
long double num=0,accum,m;

void normalbutton(int x1,int x2,int y1,int y2)
{
	setcolor(12);
	rectangle(x1-2,y1-2,x2+1,y2+1);
	rectangle(x1-1,y1-1,x2+2,y2+2);
	setcolor(7);
	rectangle(x1,y1,x2+2,y2+2);
	rectangle(x1,y1,x2+1,y2+1);
	
	setfillstyle(SOLID_FILL,1);
	bar(x1,y1,x2,y2);
}
initmouse()
{
 	i.x.ax=0;
 	int86 (0x33,&i,&o);
 	return(o.x.ax);
}
hidemouseptr()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
	return 0;
}
showmouseptr()
{
 	i.x.ax=1;
 	int86(0x33,&i,&o);
 	return 0;
}
getmousepos(int *button,int *x,int *y)
{
 	i.x.ax=3;
	int86(0x33,&i,&o);
 	*button=o.x.bx;
 	*x=o.x.cx;
 	*y=o.x.dx;
 	return 0;
}
movemouseptr(int *x,int *y)
{
 	i.x.ax=4;
 	int86(0x33,&i,&o);
 	o.x.cx=*x;
 	o.x.dx=*y;
 	return 0;
}
class HotelService : public CustomerService
{
	public:
	int room_number;
	char name[30];
	char address[50];
	char phone[10];

	public:
	void show_customer(HotelService* data)
	{
		for(int i = 0; i < noOfRecords; i++) {
			cout<<"\nRecord Number : "<<noOfRecords-1;
			cout<<"\nRoom Number: "<<data[i].room_number;
			cout<<"\nCustomer's Name: "<<data[i].name;
			cout<<"\nCustomer's Address: "<<data[i].address;
			cout<<"\nCustomer's Phone: "<<data[i].phone;
		}
    }
    void add_customer(HotelService* data)
    {
		int roomNumber = 0;
		cout<<endl<<"Enter The Room Number: ";
		rectangle(450,15,180,35);
		cin>>roomNumber;
		if(noOfRecords != 0) {
			for(int index = 0; index < noOfRecords; index++) {
				if(data[index].room_number == roomNumber) {
					cout<<endl<<"Enter correct room number.";
					return;
				}
			}
			data[noOfRecords].room_number = roomNumber;
		}
		else {
			data[noOfRecords].room_number = roomNumber;
		}
		cout<<endl<<"Enter The Customer's name: ";
		rectangle(450,45,210,65);
		cin>>data[noOfRecords].name;
		cout<<endl<<"Enter The Customer's address: ";
		rectangle(450,78,235,98);
		cin>>data[noOfRecords].address;
		cout<<endl<<"Enter The Customer's phone #: ";
		rectangle(450,108,235,128);
		cin>>data[noOfRecords].phone;
      ofstream fp1;
      fp1.open("HostelCustomer.dat",ios::app);
       fp1 << data[noOfRecords].room_number<<"   "<<data[noOfRecords].name<<"   "<<data[noOfRecords].phone<<"   "<<data[noOfRecords].address;
      fp1.close();

		cout<<"\t\t\n\nCustomer added Successfully...";
		noOfRecords++;
    }
    void modify_customer_record()
    {
		cout<<endl<<"Room number : "<<room_number;
		cout<<endl<<"Modify Customer's Name : ";
		cin.ignore();
		rectangle(450,61,198,84);
		cin>>name;
		cout<<endl<<"Modify Customer's address: ";
		cin.ignore();
		rectangle(450,94,208,114);
		cin>>address;
		cout<<endl<<"Modify Customer's phone #: ";
		cin.ignore();
		rectangle(450,126,208,146);
		cin>>phone;
     }
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

fstream fp;

HotelService h;

void save_customer(HotelService data[100])
{
	int option;

	fp.open("hotel.dat",ios::out|ios::app);
	//fp1 << h.getRoomNumber();
	h.add_customer(data);
	fp.write((char*)&h,sizeof(Hotel));
	//fp1.close();
	/*do
	{
		h.add_customer(data);
		fp.write((char*)&h,sizeof(Hotel));
		cout<<"\nPress 1 to add more customer";
		cout<<"\nPress 2 key to return to main menu.\n";
		cout<<"Option: ";
		cin>>option;
	}while(option == 1);*/
	cout<<"\nPress any key to return to main menu.\n";
	getch();
	fp.close();
}
void display_a_customer(HotelService data[100])
{
	int check = 0;
	int r_number;
	cout<<"\nPlease Enter Customer's Room Number: ";
	rectangle(450,15,290,35);
	cin>>r_number;
	for(int i = 0; i < noOfRecords; i++) {
		if(data[i].getRoomNumber() == r_number) {
			cout<<"\nCustomer DETAILS\n";
			check = 1;
			cout<<"\nRecord Number : "<<noOfRecords-1;
			cout<<"\nRoom Number: "<<data[i].room_number;
			cout<<"\nCustomer's Name: "<<data[i].name;
			cout<<"\nCustomer's Address: "<<data[i].address;
			cout<<"\nCustomer's Phone: "<<data[i].phone;
		}
	}
	if(check == 0)
		cout<<"\n\nCustomer does not exist";
	getch();
}
void modify_customer(HotelService data[100])
{
	int r_number;
	cout<<"MODIFY CUSTOMER'S RECORD";
	cout<<"\nEnter The room number: ";
	rectangle(450,15,180,35);
	cin>>r_number;
	int check = 0;
	for(int i = 0; i < noOfRecords; i++) {
		if(data[i].getRoomNumber() == r_number) {
			data[i].modify_customer_record();
			check = 1;
		}
	}
	if(check == 0)
		cout<<"\n\nCustomer does not exist";
	getch();
}
HotelService* delete_customer(HotelService data[100])
{

	cout<<endl<<"address : "<<&data;
	cout<<endl<<"noOfRecords : "<<noOfRecords;
	HotelService newData[100];
	int r_number;
	int flag=0;
	cout<<"\n\nDELETE CUSTOMER";
	cout<<"\nEnter Room No. of the Customer you wan to delete: ";
	cin>>r_number;
	int k = 0;
	for(int i = 0; i < noOfRecords; i++) {
		cout<<endl<<"getRoomNumber():"<<data[i].getRoomNumber();
		cout<<endl<<"r_number : "<<r_number;
		if(data[i].getRoomNumber() != r_number) {
			cout<<endl<<"Match NOT Found";
			newData[k++] = data[i];
		}
		else {
			cout<<endl<<"Match Found";
			flag = 1;
		}
	}
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ...";
	else
		cout<<"\n\nRecord not found";
	data = newData;
	cout<<"\n....................";
	for(i = 0; i < k; i++) {
		cout<<endl<<data[i].room_number;
	}
	noOfRecords = k;
	getch();
	return &data[0];
}
void display_all_customer(HotelService data[100])
{
	system("cls");
	fp.open("hotel.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}
	cout<<"\n\n\t\tCUSTOMER LIST\n\n";
	cout<<"==================================================================\n";
	cout<<"\tRoom Number."<<setw(10)<<"Name"<<setw(20)<<"Address"<<setw(20)<<"Phone"<<endl;
	cout<<"==================================================================\n";
	while(fp.read((char*)&h,sizeof(Hotel)))
	{
		h.report();
	}
	fp.close();
}
void main()
{
    int gd=DETECT,gm,x1,y1,x2,y2,x=0,y=0,button;
    initgraph(&gd,&gm,"..\\bgi");
    int flag=0;

    HotelService* dataa;
    HotelService data[100];
    HotelService hotelService;
    for(int index=0;index<noOfRecords;index++)
    {
	data[index].room_number = 0;
    }

    if(initmouse()==0){
		closegraph();
		restorecrtmode();
		cout<<"Mouse driver not loaded";
		exit(1);
    }
    showmouseptr();
    movemouseptr(&x,&y);

    while(1){
	flag=0;

	setbkcolor(9);
	setcolor(3);
	settextstyle(0,0,2);

	outtextxy(140,30,"Hotel Booking System");

	settextstyle(0,0,0);

	normalbutton(80,200,80,200);
	outtextxy(110,135,"BookRoom");

	normalbutton(250,370,80,200);
	outtextxy(266,135,"AllotRooms");

	normalbutton(420,540,80,200);
	outtextxy(450,135,"CustRecord");

	normalbutton(80,200,250,377);
	outtextxy(110,290,"Modify");

	normalbutton(250,370,250,377);
	outtextxy(266,290,"Delete");

	normalbutton(420,540,250,377);
	outtextxy(450,290,"Exit");

	while(flag==0){

	getmousepos(&button,&x,&y);

	if((x<200&&x>80)&&(y<200&&y>80)){
		if((button & 1)==1){
			flag=1;
			bt=1;
			cleardevice();
			save_customer(data);
			cleardevice();
			clrscr();
		}
	}
	else if((x<370&&x>250)&&(y<200&&y>80)){
		if((button & 1)==1){
			flag=1;
			bt=2;
			cleardevice();
			hotelService.show_customer(data);
			getch();
			cleardevice();
			clrscr();
		}
	}
	else if((x<540&&x>420)&&(y<200&&y>80)){
		if((button & 1)==1){
			flag=1;
			bt=3;
			cleardevice();
			display_a_customer(data);
			getch();
			cleardevice();
			clrscr();
		}
	}
	else if((x<200&&x>80)&&(y<377&&y>250)){
		if((button & 1)==1){
			flag=1;
			bt=4;
			cleardevice();
			modify_customer(data);
			cleardevice();
			clrscr();
		}
	}
	else if((x<370&&x>250)&&(y<377&&y>250)){
		if((button & 1)==1){
			flag=1;
			bt=5;
			cleardevice();
			dataa=delete_customer(data);
			for(int i=0;i<noOfRecords;i++) {
				data[i]=dataa[i];
			}
			cleardevice();
			clrscr();
		}
	}
	else if((x<540&&x>420)&&(y<377&&y>250)){
		if((button & 1)==1){
			flag=1;
			closegraph();
			exit(0);
		}
	}
	}
	flag=0;
    }
}
