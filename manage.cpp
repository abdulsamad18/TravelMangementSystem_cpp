#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <unistd.h>

using namespace std;
void menu();

class mangeMenu//encapsulation concept to hide and allow only the admin
{
    protected:
       string userName;//hide admin name
    public:
      mangeMenu()
       {
        cout<<"\n\n\n\n\n\n\tEnter YOur adminID\n";
        cin>>userName;
        system("CLS");
        menu();
       }
       
};
class customers
{
public:
    string name, gender, address;
    int age, mobileNo;
    static int cusID;
    char all[999];

    void getDetails()
    {
        ofstream out("old_customers.txt", ios::app);
        {
            cout << "Enter customer id\n";
            cin >> cusID;
            cout << "Enter your name\n";
            cin >> name;
            cout << "Enter your gender\n";
            cin >> gender;
            cout << "Enter your age\n";
            cin >> age;
            cout << "Enter mobile number\n";
            cin >> mobileNo;
            cout << "Enter your address\n";
            cin >> address;
        }
        out << "\ncustomer id:  " << cusID << "\nName; " << name << "\n age" << age << "\n MObile" << mobileNo << "\n Address" << address << "\n gender" << gender;
        out.close();
                cout<< "\nSAVED\nNOTE: we have saved your details for future purposes\n"<< endl;

    }
    void showDetails()
    {
        ifstream in("old_customers.txt");
        {
            if(!in)
            {
                cout<<"file error!\n";
            }
            while(!in.eof())
            {
                in.getline(all,999);
                cout<<all<<endl;
            }
            in.close();
        }
    }
};
class cabs
{
    public:
      int cabChoice;
      int kms;
      float cabCost;
      static float lastCabCost;
      void cabDetails()
      {
        cout<<"welcome to the cab service"<<endl;
        cout<<"1.Sedan cab-$15 for one kilometer"<<endl;
        cout<<"2.SUV cab-$25 for one kilometre"<<endl;
        cout<<"\nTo calculate the cost of your journey:"<<endl;
        cout<<"Enter the type of vehicle\n";
        cin>>cabChoice;
        cout<<"Enter the total kilometers to be travelled";
        cin>>kms;
        int hireCab;
        if(cabChoice == 1)
        {
            cabCost=kms*15;
            cout <<"\nYour tour cost ="<<cabCost<<"dollars for standard cab"<<endl;
            cout<<"press 1 to hire this cab\n";
            cout<<"press 2 to select another cab\n";
            cin>>hireCab;

            system("CLS");

            if(hireCab == 1)
            {
                lastCabCost = cabCost;
                cout<<"\nyou have successfully hired a sedan\n";
                cout<<"\nGoto menu and take the recipt";
            }
            else if(hireCab==2)
            {
                cabDetails();
            }
            else
            {
                cout<<"INVALID input!\n Redirecting to previous menu \n PLEASE WAIT"<<endl;
                sleep(3);
                system("CLS");
                cabDetails();
            }

        }
        else if(cabChoice==2)
           {
            cabCost=kms*25;
            cout <<"\nYour tour cost ="<<cabCost<<"dollars for standard cab"<<endl;
            cout<<"press 1 to hire this cab\n";
            cout<<"press 2 to select another cab\n";
            cin>>hireCab;

            system("CLS");

            if(hireCab == 1)
            {
                lastCabCost = cabCost;
                cout<<"\nyou have successfully hired a SUV\n";
                cout<<"\nGoto menu and take the recipt";
            }
            else if(hireCab==2)
            {
                cabDetails();
            }
            else
            {
                cout<<"INVALID input!\n Redirecting to previous menu \n PLEASE WAIT"<<endl;
                sleep(2);
                system("CLS");
                cabDetails();
            }

           }
           else
           {
            cout<<"INVALID INPUT !\nredirecting to the main menu\nPLEASE WAIT\n"<<endl;
            sleep(1);
            system("CLS");
            menu();
           }
           cout<<"Press 1 to REDIRECT the main menu\n"<<endl;
           cin>>hireCab;
           system("CLS");
           if(hireCab==1){
            menu();
           }
           else{
            menu();
           }

      }
};
class booking
{
    public:
      int choiceHotel;
      int packChoice;
      static float hotelCOSt;

      void hotel()
      {
        string hotelNo[]={"radisson","regenta","countryinn"};
        for(int i=0;i<3;i++)
        {
            cout<<(i+1)<<".hotel"<<hotelNo[i]<<endl;
        }
        cout<<"\nCurrently we collaborated with the above hotels\n Enter the hotelno you want to book\n";
        cin>>choiceHotel;
        system("CLS");
        if (choiceHotel==1)
        {
            cout<<"------------Welcome to Radison Blue Plaza----------------\n"<<endl;
            cout<<"The packages we offer are\n";
            cout<<"1.standard Package\nAll the Basic faciliteis you need at just :Rs-5000.00\n";
            cout<<"2.Premium Package\nAt just: RS-10000.0\n";
            cout<<"3.Luxury Package\nAT just:  RS-15000.00\n";
            cout<<"\nPlease Enter your choice\n";
            cin>> packChoice;

            if(packChoice==1)
            {
                hotelCOSt= 5000.00;
                cout<<"your Successfully Booked a Standard Package at Radison\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else if(packChoice==2)
            {
                hotelCOSt= 10000.00;
                cout<<"your Successfully Booked a preimum Package at Radison\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else if(packChoice==3)
            {
                hotelCOSt= 15000.00;
                cout<<"your Successfully Booked a Luxury Package at Radison\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else
            {
                cout<<"Invalid input\n Redirecting to the main menu\nPlease wait"<<endl;
                sleep(1);
                system("CLS");
                hotel();
            }
            int gotomenu;
            cout<<"\npress 1 to redirect to main menu\n";
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }

        }
        else if (choiceHotel==2)
        {
            cout<<"------------Welcome to Hotel regenta----------------\n"<<endl;
            cout<<"The packages we offer are\n";
            cout<<"1.standard Package\nAll the Basic faciliteis you need at just :Rs-5000.00\n";
            cout<<"2.Premium Package\nAt just: RS-10000.0\n";
            cout<<"3.Luxury Package\nAT just:  RS-15000.00\n";
            cout<<"\nPlease Enter your choice\n";
            cin>> packChoice;

            if(packChoice==1)
            {
                hotelCOSt= 5000.00;
                cout<<"your Successfully Booked a Standard Package at regenta\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else if(packChoice==2)
            {
                hotelCOSt= 10000.00;
                cout<<"your Successfully Booked a preimum Package at regenta\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else if(packChoice==3)
            {
                hotelCOSt= 15000.00;
                cout<<"your Successfully Booked a Luxury Package at regenta\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else
            {
                cout<<"Invalid input\n Redirecting to the main menu\nPlease wait"<<endl;
                sleep(1);
                system("CLS");
                hotel();
            }
            int gotomenu;
            cout<<"\npress 1 to redirect to main menu\n";
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }

        }
        else if (choiceHotel==2)
        {
            cout<<"------------Welcome to CountryINN and suits----------------\n"<<endl;
            cout<<"The packages we offer are\n";
            cout<<"1.standard Package\nAll the Basic faciliteis you need at just :Rs-5000.00\n";
            cout<<"2.Premium Package\nAt just: RS-10000.0\n";
            cout<<"3.Luxury Package\nAT just:  RS-15000.00\n";
            cout<<"\nPlease Enter your choice\n";
            cin>> packChoice;

            if(packChoice==1)
            {
                hotelCOSt= 5000.00;
                cout<<"your Successfully Booked a Standard Package at CountryINN  \n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else if(packChoice==3)
            {
                hotelCOSt= 10000.00;
                cout<<"your Successfully Booked a preimum Package at CountryINN\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else if(packChoice==3)
            {
                hotelCOSt= 15000.00;
                cout<<"your Successfully Booked a Luxury Package at CountryINN\n"<<endl;
                cout<<"Go back to the main menu and take the recipt";
            }
            else
            {
                cout<<"Invalid input\n Redirecting to the main menu\nPlease wait"<<endl;
                sleep(1);
                system("CLS");
                hotel();
            }
            int gotomenu;
            cout<<"\npress 1 to redirect to main menu\n";
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }

        }
        else
        {
            cout<<"Invalid Input!Redirecting to Previous menu\n"<<endl;
            sleep(1);
            system("CLS");
            hotel();
        }
      }
};
float booking::hotelCOSt;
float cabs::lastCabCost;
int customers::cusID;
//------the below class is written using Multilevel Inheritance-----
class charges : public booking,cabs,customers
{

    public:
      void printBill()
      {
        ofstream outf("receipt.txt");
        {
            outf<<"-------our travel company----------"<<endl;
            outf<<"----------receipt---------\n";
            outf<<"___________________________\n";

            outf<<"Customer ID:  "<<customers::cusID<<"\n"<<endl;
            outf<<"Description\t\t Total"<<endl;
            outf<<"Hotel Cost"<<fixed<<setprecision(2)<<booking::hotelCOSt<<endl;
            outf<<"Cab cost"<<fixed<<setprecision(2)<<cabs::lastCabCost<<endl;

            outf<<"___________________________\n";
            outf<<"Total Charge:\t\t"<<fixed<<setprecision(2)<<booking::hotelCOSt+cabs::lastCabCost<<endl;
            outf<<"___________________________\n";
            outf<<"__________THANK YOU_________\n";
        

        }
        outf.close();

      }
      void showBill()
      {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout<<"File empty or opening Error\n";
            }
            while(!inf.eof())
            {
                inf.getline(all,999);
                cout<<all<<endl;
            }
        }
        inf.close();
      }

};
void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;



    cout<<"\t\t------------------main menu------------------";
    cout<<"\t|\t\t\t\t\t\t|"<<endl;
    cout<<"\t|\tCustomer Mangement->1\t|"<<endl;
    cout<<"\t|\tCabs Mangement    ->2\t|"<<endl;
    cout<<"\t|\tBooking Mangement ->3\t|"<<endl;
    cout<<"\t|\tCharges and BILL  ->4\t|"<<endl;
    cout<<"\t|\texit              ->5\t|"<<endl;
    cout<<"\t|\t\t\t\t\t\t|"<<endl;
    cout<<"\t|--------------------------------------|"<<endl;
    cout<<"Enter your Choice\n"<<endl;
    cin>>mainChoice;

    system("CLS"); 

    customers a2;
    cabs a3;
    booking a4;
    charges a5;

    if(mainChoice==1)
    {
        cout<<"--------Customers--------\n";
        cout<<"1.Enter as New Customer\n";
        cout<<"2.see old customers\n";
        cout<<"\nEnter choice\n";
        cin>>inChoice;

        system("CLS");
        if(inChoice==1)
        {
            a2.getDetails();
        }
        else if(inChoice==2)
        {
            a2.showDetails();
        }
        else
        {
            cout<<"INVALID INPUT !\nredirecting to the main menu\nPLEASE WAIT\n"<<endl;
            sleep(1);
            system("CLS");
            menu();

        }
        cout<<"\nPress 1 to redirect main menu:\n";
        cin>>gotoMenu;
        system("CLS");
        if(gotoMenu==1)
        {
            menu();
        }
        else
        {
            menu();
        }


    }
    else if(mainChoice==2)
    {
        a3.cabDetails();
    }
    else if(mainChoice==3)
    {
        cout<<"-----Book a luxuru hotel using this system-----\n";
        a4.hotel();
    }
    else if(mainChoice==4)
    {
        cout<<"------------get your reciept-------------";
        a5.printBill();

        cout <<"Your receipt is already printed\n"<<endl;
        cout<<"To display your reciept press-> 1 or other key to go back to the main menu";
        cin>>gotoMenu;
        if(gotoMenu==1)
        {
            system("CLS");
            a5.showBill();
            cout<<"\npress 1 to redirect to main menu\n";
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu==1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
        system("CLS");
        menu();
        }

    }
    else if(mainChoice==5)
    {
        cout<<"-----have anice time-------"<<endl;
        sleep(2);
        exit(0);
    }
    else{
         cout<<"INVALID INPUT !\nredirecting to the main menu\nPLEASE WAIT\n"<<endl;
            sleep(1);
            system("CLS");
            menu();

    }
    

    

}

int main()
{
    mangeMenu startobj;

    return 0;
}