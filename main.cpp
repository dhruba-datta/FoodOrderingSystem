#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <sstream>
#define LSIZ 128
#define RSIZ 10

using namespace std;

class Customer
{
    private:
    string Name ;
    int phone;
    protected:
    string tea1="MILK TEA",tea2="GINGER TEA",paratha1="PARATHA",paratha2="ALU PARATHA",dosa1="ONION DOSA",dosa2="MASALA DOSA",
    idli1="RICE IDLI",idli2="RAVA IDLI",egg1="BOILED EGG",egg2="OMLET",sandwich1="CHICKEN SANDWICH",sandwich2="CLUB SANDWICH",
    pizza1="PANEER PIZZA",pizza2="CHICKEN PIZZA",burger1="CHICKEN ZINGER BURGER",burger2="CLASSIC CHICKEN BURGER",biryani1="CHICKEN BIRYANI",
    biryani2="MUTTON BIRYANI",friedrice1="VEG FRIED RICE",friedrice2="CHICKEN FRIED RICE",chicken1="CHICKEN CURRY",chicken2="CHICKEN MANCHURIAN",
    frenchfries="FRENCH FRIES",rolls1="VEG ROLLS",rolls2="CHICKEN ROLLS",drinks1="MOUNTAIN DEW",drinks2="PEPSI",drinks3="COCA COLA";
    public:

    void setname()
    {
	cout<<"\n Please Enter Your Name: ";
	cin>>Name;

    }
    void setphone()
    {
        cout<<"\n Enter your phone number : ";
        cin>>phone;
        system("CLS");
    }
    string getname()
    {
        return Name;
    }
    int getphone()
    {
        return phone;
    }
};

class getData : public Customer
{
private:
    int quantity,sum=0,price,t=0,time;
public:
    void total(int,int);
    void timetaken(int,int);
    string show(int num);


    int resetwaitingtime()
    {
        return t=0;
    }
    int removesum()
    {
        return sum=0;
    }
    int getsum()
    {
        return sum;
    }
    int getTime()
    {
        return t;
    }
};
string getData::show(int num)
{
    if(num==1)
    {
    return tea1;

    }
    if(num==2)
    {
      return tea2;
    }
    if(num==3)
    {
        return paratha1;
    }

    if(num==4)
    {
        return paratha2;
    }
    if(num==5)
    {
      return dosa1;
    }

    if(num==6)
    {
       return dosa2;
    }

    if(num==7)
    {
    return idli1;
    }
    if(num==8)
    {
        return idli2;
    }
    if(num==9)
    {
        return egg1;
    }
    if(num==10)
    {
        return egg2;
    }
    if(num==11)
    {
        return sandwich1;
    }
    if(num==12)
    {
        return sandwich2;
    }
    if(num==13)
    {
        return pizza1;
    }
    if(num==14)
    {
        return pizza2;
    }
    if(num==15)
    {
        return burger1;
    }
    if(num==16)
    {
        return burger2;
    }
    if(num==17)
    {
        return biryani1;
    }
    if(num==18)
    {
        return biryani2;
    }
    if(num==19)
    {
        return friedrice1;
    }
    if(num==20)
    {
        return friedrice2;
    }
    if(num==21)
    {
        return chicken1;
    }
    if(num==22)
    {
        return chicken2;
    }
    if(num==23)
    {
        return frenchfries;
    }
    if(num==24)
    {
        return rolls1;
    }
    if(num==25)
    {
        return rolls2;
    }
    if(num==26)
    {
        return drinks1;
    }

    if(num==27)
    {
        return drinks2;
    }

    if(num==28)
    {
        return drinks3;
    }

}
void getData::total(int price,int quantity)
{
    sum = sum + (price * quantity);
}
void getData::timetaken(int time,int quantity)
{
    t = t + (time * quantity);
    if(t>20)
        t=20;
}
void current_time()
{
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
	cout << "Order Finishing Time : " << tm;

}
void  writeFile(string CustomerName,int phonenum , string foodname, int sizeo, int quantity, int token , int coun )
{
  string word;
  ofstream outfile;
  word = to_string(token) + ".txt";
  outfile.open(word,ios_base::app);
  if (coun == 0)
  {
      outfile<<""+ CustomerName + "- " + to_string (phonenum)<<"\n";
      outfile <<""+ foodname + " - " +to_string(sizeo)+" - " + to_string(quantity) <<"\n";

  }
  else
 {
    outfile <<""+ foodname + " - " +to_string(sizeo)+" - " + to_string(quantity) <<"\n";
 }

}

void readFile()
{
  char line[RSIZ][LSIZ];
  char fname[40];
  FILE *fptr = NULL;
  int i = 0;
  int tot = 0;
  cout << "Find out who placed order :" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "Input the filename to be opened : ";
  cin >> fname;

  fptr = fopen(fname, "r");

  while (fgets(line[i], LSIZ, fptr))
  {
    line[i][strlen(line[i]) - 1] = '\0';
    i++;
  }

  tot = i;

  cout << endl;

  for (i = 0; i < tot; ++i)
  {
    cout<<line[i]<<endl;
  }
}

void deleteFile()
{
  char fname[40];
  char rem[40] = "del /f ";
  cout << "Input the filename to be deleted : ";
  cin >> fname;
  system(strcat(rem,fname));
}



 int main()
{
     Customer name1;
     getData order1;
     int quantity,ch,ch1,ch2,coa,coo=0,cop,pc,change,to=1,cou=0;
     string Namee= "Dhruba";
     char again;

    while (coo!=1)
     {
         head:
         system("CLS");
         cout<<"\n";
         cout<<"                     ||         DIGITAL FOOD ORDERING SYSTEM OF A RESTAURANT           ||   \n";
         cout<<"                        ----------------------------------------------------------     \n\n";
         cout<<"\n                               Hope you are having a smile on your face!                      \n";
         cout<<"\n 1.) Are you a Customer?\n 2.) Are you an Administrator?\n 3.) Read me \n 4.) EXIT \nPlease Enter this(1/2/3/4): ";
         cin>>coa;
      if(coa==2)
      {
        haha:
         system("CLS");
         string pass="";
         string nname;
         cout<< "\t\tGive your Name and password to log in ....\n";
         cout<<"\t\tGive your name : ";
         cin>>nname;
         cout<<"\t\tGive your password : ";
         char ch;
         ch = _getch();
         while(ch != 13)
            {
                pass.push_back(ch);
                cout << '*';
                ch = _getch();
            }

         if (nname == Namee && pass == "2020")
         {
         	hoho:
         system("CLS");
         cout<<"1.) See individual customer order\n2.) Total order list \n3.) Delete order \n4.) Go back to previous menu \n Enter your choice (1/2): ";
         cin>>cop;
         if(cop==1)
         {
             system("CLS");
             cout<<"";
             readFile();
             getch();
             goto hoho;
         }
        else if(cop==2)
        { system("CLS");
		 system("dir/s");
        getch();
        goto hoho;
		}
		else if (cop==3)
		{
		system ("CLS");
		deleteFile();
		cout<<"\n Order deleted \n";
		getch();
		}
         else if(cop==4)
         {
             system("CLS");
             goto head;
         }
         else
         {
           cout<<"wrong input ";
           goto head;
         }
         }
         else {
                system("CLS");
                int np;
                cout<<"Invalid Name or Password ...\n";
                cout<<"1.) Wanna try again ? \n2.) Go back to main menu \nChoose your option (1/2) :\n";
                cin>>np;
                if (np==1)
                  {
                    goto haha;
                  }
                else
                  {
                    goto head;
                  }
              }
         }
    else if(coa==1)
     {
         system("CLS");
         int n;
         cout<<"\n";
         cout<<"\n 1.) Do you want to order your food?";
         cout<<"\n 2.) Do you see your order?";
         cout<<"\n Give your choice : ";
         cin>>n;
         if (n==2)
         {
                system("CLS");
                cout<<"";
                readFile();
         	    getch();
         	    goto head;
		 }
		 else
		 {
		  system("CLS");
		  cout<<"\n";
         time_t curr_time1;
	     curr_time1 = time(NULL);
	     char *tm1 = ctime(&curr_time1);
         cout << "Arrival Time : " << tm1;
         name1.setname();
         name1.setphone();

    start:
    system("CLS");
    cout << "\nArrivalTime : " << tm1;
    cout<<"     ----|| WELCOME TO OUR RESTAURANT ||----\n";
    cout<<"----|| HOPE YOU HAVE A SMILE ON YOUR FACE ||----\n\n";
    cout<<"Hello "<<name1.getname()<<"\n";
    cout<<"Phone number : "<<name1.getphone()<<endl<<endl;
    cout<<"--------Food Menu--------\n\n";
	cout<<"01) TEA\n"; //time take t1
	cout<<"02) PARATHA\n"; //time take t2
	cout<<"03) DOSA\n"; //time take t3*quantity
	cout<<"04) IDLI\n"; //time take t4*quantity
	cout<<"05) EGG\n"; //time take t5
	cout<<"06) SANDWICH\n"; //time take t6*quantity
	cout<<"07) PIZZA\n"; //time take t7*quantity
	cout<<"08) BURGER\n"; //time take t8*quantity
	cout<<"09) BIRYANI\n"; //time take t9
	cout<<"10) FRIED RICE\n"; //time take t10
	cout<<"11) CHICKEN\n"; //time take t11
	cout<<"12) FRENCH FRIES\n"; //time take t12*quantity
	cout<<"13) ROLLS\n"; //time take t13*quantity
	cout<<"14) DRINKS\n\n"; //time take t14
	cout<<"15) Do you want to see your order?\n";
	cout<<"16) Go back to previous menu\n\n";
	cout<<"\n Please Enter your Choice: ";
	cin>>ch;
 switch(ch)
        {

       case 1:
           tea:
           system("CLS");
           cout<<"\nThere is 2 choices for tea:\n\n"<<"\n1)"<<order1.show(1)<<endl<<endl;
           cout<<"2)"<<order1.show(2)<<endl<<endl;
           cout<<"3.) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch1;
           if (ch1==3)
            {
                goto start;
            }
           else if(ch1==1 || ch1==2)
           {
            system("CLS");
            cout<<"\n1) Small Rs.50\n"<<"2) Regular Rs.80\n"<<"3) Large Rs.100\n"<<"4) Go back to Previous Menu\n ";
			cout<<"\nChoose Size Please: ";
			cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(50,quantity);
                order1.timetaken(2,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(80,quantity);
                order1.timetaken(2,quantity);
                break;
            case 3:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(100,quantity);
                order1.timetaken(2,quantity);
                break;
            case 4:
                goto tea;
            default:
                cout<<"\n\nPLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}

			 if(ch1==1)
                {
                  writeFile(name1.getname(), name1.getphone() , order1.show(1), ch2, quantity, to , cou);
                  cou++;
                }
               else if(ch1==2)
                {
                  writeFile(name1.getname(), name1.getphone() ,order1.show(2), ch2, quantity, to , cou );
                  cou++;
                }

			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                goto start ;
			}
            else if(again=='n' || again =='N')
            {
             teap:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2 || ch2==3)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2 || ch2==3)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient amount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto teap;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
           }
           else
           {
               cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
           }
            system("CLS");
            break;

       case 2:
           system("CLS");
           cout<<"\nThere is 2 choices for paratha:\n\n"<<"\n1)"<<order1.show(3)<<endl<<endl;
           cout<<"2)"<<order1.show(4)<<endl<<endl;
           cout<<"3) Go to previous menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(10,quantity);
                order1.timetaken(5,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(30,quantity);
                order1.timetaken(5,quantity);
                break;
            case 3 :
                goto start ;

            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
                {
                  writeFile(name1.getname(), name1.getphone(), order1.show(3), ch2, quantity, to, cou );
                  cou++;
                }
               else if(ch2==2)
                {
                  writeFile(name1.getname(), name1.getphone(), order1.show(4), ch2, quantity, to, cou );
                  cou++;
                }

			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
               goto start ;
			}
            else if(again=='n' || again =='N')
            {
             parap:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto parap;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
            system("CLS");
            break;


       case 3:
           system("CLS");
           cout<<"\nThere is 2 choices for dosa:\n\n"<<"\n1)"<<order1.show(5)<<endl<<endl;
           cout<<"2)"<<order1.show(6)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(30,quantity);
                order1.timetaken(7,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(50,quantity);
                order1.timetaken(7,quantity);
                break;
            case 3:
                goto start;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(5), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(6), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
			     goto start ;
			}
            else if(again=='n' || again =='N')
            {
            dosap:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }

             else
             {
 	            cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto dosap;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }

            system("CLS");
            break;

        case 4:
           system("CLS");
           cout<<"\nThere is 2 choices for Idli:\n\n"<<"\n1)"<<order1.show(7)<<endl<<endl;
           cout<<"2)"<<order1.show(8)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(30,quantity);
                order1.timetaken(8,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(50,quantity);
                order1.timetaken(8,quantity);
                break;
            case 3 :
                goto start ;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(7), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(8), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                goto start ;
			}
            else if(again=='n' || again =='N')
            {
              idlip:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }

             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto idlip;
                       break;
                }
             }
         }

            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }

            system("CLS");
            break;

        case 5:
           system("CLS");
           cout<<"\nThere is 2 choices for eggs:\n\n"<<"\n1)"<<order1.show(9)<<endl<<endl;
           cout<<"2)"<<order1.show(10)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(20,quantity);
                order1.timetaken(5,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(30,quantity);
                order1.timetaken(5,quantity);
                break;
            case 3:
                goto start ;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(9), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(10), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                 goto start ;
			}
            else if(again=='n' || again =='N')
            {
            eggp:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }

             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto eggp;
                       break;
                }
             }
        }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }

            system("CLS");
            break;

       case 6:
           system("CLS");
           cout<<"\nThere is 2 choices for Sandwich:\n\n"<<"\n1)"<<order1.show(11)<<endl<<endl;
           cout<<"2)"<<order1.show(12)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(50,quantity);
                order1.timetaken(10,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(60,quantity);
                order1.timetaken(10,quantity);
                break;
            case 3 :
                goto start;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(11), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(12), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                goto start ;
			}
            else if(again=='n' || again =='N')
            {
              sandwichp:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }

             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto sandwichp;
                       break;
                }
             }
         }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
            system("CLS");
            break;

        case 7:
           pizza:
           system("CLS");
           cout<<"\nThere is 2 choices for Pizza:\n\n"<<"\n1)"<<order1.show(13)<<endl<<endl;
           cout<<"2)"<<order1.show(14)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch1;
           if (ch1==3)
           {
               goto start;
           }
           else if(ch1==1)
           {
            system("CLS");
            cout<<"\n1) Small Rs.80\n"<<"2) Regular Rs.120\n"<<"3) Large Rs.150\n4) Go back to main menu ";
			cout<<"\nChoose Size Please: ";
			cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(80,quantity);
                order1.timetaken(15,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(120,quantity);
                order1.timetaken(15,quantity);
                break;
            case 3:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(150,quantity);
                order1.timetaken(15,quantity);
                break;
            case 4 :
                goto pizza ;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch1==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(13), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                 goto start ;
			}
            else if(again=='n' || again =='N')
            {
             pizzap1:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\n\Pay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2 || ch2==3)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2 || ch2==3)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto pizzap1;
                       break;
                }
             }
            }
           }
           else if(ch1==2)
           {
            cout<<"\n1) Small Rs.120\n"<<"2) Regular Rs.200\n"<<"3) Large Rs.250\n4) Go back to main menu ";
			cout<<"\nChoose Size Please: ";
			cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(120,quantity);
                order1.timetaken(15,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(200,quantity);
                order1.timetaken(15,quantity);
                break;
            case 3:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(250,quantity);
                order1.timetaken(15,quantity);
                break;
            case 4 :
                goto pizza;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch1==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(14), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                goto start ;
			}
            else if(again=='n' || again =='N')
            {
            pizzap2:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if( ch2==1 ||ch2==2 || ch2==3)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2 || ch2==3)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto pizzap2;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }

           }
           else
           {
               cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
           }
            system("CLS");
           break;


        case 8:
           system("CLS");
           cout<<"\nThere is 2 choices for Burger:\n\n"<<"\n1) Rs.100"<<order1.show(15)<<endl<<endl;
           cout<<"2) Rs.80"<<order1.show(16)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(100,quantity);
                order1.timetaken(15,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(200,quantity);
                order1.timetaken(15,quantity);
                break;
            case 3:
                goto start;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(15), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(16), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                 goto start ;
			}
            else if(again=='n' || again =='N')
            {
            burgerp:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto burgerp;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
            system("CLS");
            break;

        case 9:
           system("CLS");
           cout<<"\nThere is 2 choices for Biryani:\n\n"<<"\n\1)"<<order1.show(17)<<endl<<endl;
           cout<<"2)"<<order1.show(18)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(50,quantity);
                order1.timetaken(20,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(60,quantity);
                order1.timetaken(20,quantity);
                break;
            case 3 :
                goto start ;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(17), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(18), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                 goto start ;
			}
            else if(again=='n' || again =='N')
            {
             biriyanip:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
               cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient amount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto biriyanip;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
            system("CLS");
            break;

        case 10:
           system("CLS");
           cout<<"\nThere is 2 choices for Fried Rice:\n\n"<<"\n1)"<<order1.show(19)<<endl<<endl;
           cout<<"2)"<<order1.show(20)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(80,quantity);
                order1.timetaken(12,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(120,quantity);
                order1.timetaken(12,quantity);
                break;
            case 3 :
                goto start;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(19), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(20), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                  goto start ;
			}
            else if(again=='n' || again =='N')
            {
             friedricep:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else
             {

                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto friedricep;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
            system("CLS");
            break;

        case 11:
           system("CLS");
           cout<<"\nThere is 2 choices for Chicken:\n\n"<<"\n1)"<<order1.show(21)<<endl<<endl;
           cout<<"2)"<<order1.show(22)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(80,quantity);
                order1.timetaken(20,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(150,quantity);
                order1.timetaken(20,quantity);
                break;
            case 3 :
                goto start;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(21), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(22), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                 goto start ;
			}
            else if(again=='n' || again =='N')
            {
             chickenp:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
               cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto chickenp;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
            system("CLS");
            break;

        case 12:
           frenchfry:
           system("CLS");
          cout<<"\nThere is a choices for Frenchfries:\n\n"<<"\n1) "<<order1.show(23)<<endl<<endl;
           cout<<"2) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch1;
           if (ch1==2)
           {
               goto start ;
           }
           if(ch1==1)
           {
            system("CLS");
            cout<<"\n1) Small Rs.80\n"<<"2) Regular Rs.120\n"<<"3) Large Rs.150\n4) Go back to previous menu \n";
			cout<<"\nChoose Size Please: ";
			cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(80,quantity);
                order1.timetaken(10,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(120,quantity);
                order1.timetaken(10,quantity);
                break;
            case 3:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(150,quantity);
                order1.timetaken(10,quantity);
                break;
            case 4 :
                goto frenchfry;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch1==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(23), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                 goto start ;
			}
            else if(again=='n' || again =='N')
            {
             frenchp:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
               cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto frenchp;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }

           }
           else
           {
               cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
           }
            system("CLS");
            break;

        case 13:
           system("CLS");
           cout<<"\nThere is 2 choices for Rolls:\n\n"<<"\n1) Rs.80 "<<order1.show(24)<<endl<<endl;
           cout<<"2) Rs.150 "<<order1.show(25)<<endl<<endl;
           cout<<"3) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(80,quantity);
                order1.timetaken(15,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(150,quantity);
                order1.timetaken(15,quantity);
                break;
            case 3:
                goto start;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch2==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(24), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch2==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(25), ch2, quantity, to, cou);
              cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                goto start ;
			}
            else if(again=='n' || again =='N')
            {
             rollp:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n ,1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto rollp;
                       break;
                }
             }
            }
            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }
            system("CLS");
            break;

        case 15 :
            {
                system("CLS");
                int ordermore;
                cout<<"";
                readFile();
                om:
                cout<<"\n1.)Do you want to place the order?";
                cout<<"\n2.)Do you want to order more?";
                cout<<"\n Give your choice : ";
                cin>>ordermore;
                if(ordermore==2)
                { goto start;
                getch();
				}
				else if(ordermore==1)
				{ system("CLS");
				break;
				}
				else
				{ cout<<"\nInvalid command! Put the right command";
				goto om;
				}
                getch();
                break;
            }

        case 14:
           drink:
           system("CLS");
           cout<<"\nThere is 3 choices for Softdrinks:\n\n"<<"\n1)"<<order1.show(26)<<endl<<endl;
           cout<<"2)"<<order1.show(27)<<endl<<endl<<"3)"<<order1.show(28)<<endl<<endl;
           cout<<"4) Go back to main menu \n";
           cout<<"\nPlease Enter your Choice: ";
           cin>>ch1;
           if (ch1==4)
           {
               goto start;
           }
           if(ch1==1 || ch1==2 || ch1==3)
           {
            system("CLS");
            cout<<"\n1) 250ml Rs.20\n"<<"2) 500ml Rs.40\n"<<"3) 1000ml Rs.80\n4) Go back to previous menu \n";
			cout<<"\nChoose Size Please: ";
			cin>>ch2;
			switch(ch2)
			{
            case 1:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(20,quantity);
                order1.timetaken(2,quantity);
                break;
            case 2:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(40,quantity);
                order1.timetaken(2,quantity);
                break;
            case 3:
                cout<<"\nPlease Enter Quantity: ";
                cin>>quantity;
                order1.total(80,quantity);
                order1.timetaken(2,quantity);
                break;
            case 4 :
                goto drink;
            default:
                cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
                break;
			}
			if(ch1==1)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(26), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch1==2)
            {
              writeFile(name1.getname(), name1.getphone(), order1.show(27), ch2, quantity, to, cou);
              cou++;
            }
            else if(ch1==3)
            {
                writeFile(name1.getname(), name1.getphone(), order1.show(28), ch2, quantity, to, cou);
                cou++;
            }
			cout<<"\n DO YOU WANT TO ORDER MORE(Y|N)?: ";
			cin>>again;
			if(again=='Y' || again=='y')
			{
                 goto start ;
			}
            else if(again=='n' || again =='N')
            {
             drinksp:
             system("CLS");
             int pay ;
             cout<<"\nYour Total Bill is "<<order1.getsum();
             cout<<"\nPay your Bill : ";
             cin>>pay;
             if(pay == order1.getsum())
             {
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();
                if(ch2==1 || ch2==2 || ch2==3)
			       {to++;}
                getch();
             }
             else if(pay>=order1.getsum())
             {
                change = pay - order1.getsum();
                cout<<"\nYour Change: "<<change<<" Rs.";
                cout<<"\nYour Order Will be delivered in "<<order1.getTime()<<" Minutes";
                cout<<"\n\nYour token number is : "<<to;
			    cout<<"\nThank you For Ordering\n\n\n\n";
                cout << "ArrivalTime : " << tm1;
                current_time();

            if(ch2==1 || ch2==2 || ch==3)
			       {to++;}
                getch();
             }
             else
             {
                cout<<"\nPayment is insufficient ";
                cout<<"\n1)Please pay sufficient ammount : ";
                cin>>pc;
                switch(pc)
                {
                	case 1 :
                       goto drinksp;
                       break;
                }
             }
            }

            else
            {
                cout<<"\n Invalid command! GO back to Menu and order again";
            }

           }

        else
           {
               cout<<"\n\n PLEASE ENTER THE VALID CHOICES!!"<<endl;
           }
            system("CLS");
            break;
          }

        cou = 0;
        order1.resetwaitingtime();
        order1.removesum();
     }
 }
     else if (coa==3)
    { system("CLS");
      cout<<"\nUser Manual";
      cout<<"\n1.For Customer: welcome message  ,  firstly give name  ,  option for food  ,  sub options if required  ,  enter the quantity  ,  give the payment  ,  if insufficient enter payment again  ,  show thank you.";
      cout<<"\n2.For Administrator: user name  ,  password  ,  name of the customer file.txt.";
      cout<<"\n3.Read me: user manual of the restaurant.";
      cout<<"\n4.Exit: exit the system.";
      getch();
    }
    else if(coa==4)
    {
        cout<<"\n\n\t\t THANK YOU FOR TRUSTING US ON ORDERING YOUR FOOD! \n\n";
        exit(0);
    }

 else
  {
     cout<<"\n\t\tThe input is invalid!! The program will exit itself!!\n\n";
     return 0;
  }
 }
}
