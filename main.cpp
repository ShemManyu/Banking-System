//C++ program to create a banking system
#include<iostream>
#include<cstring>//Used for string library functions
using namespace std;
class Bank_account//Creating a class Bank_account
{
private:
//Data members
    int acc_no;
    char customer_name[100];
    char acc_type[100];
    int pin_no;
    double balance;
public:
//Member functions
    void get_data(int);
    void del_data();
    void print_data();
    void deposit_balance(double);
    int withdrawn_balance(double,int);
    void update_pin_no();
    bool check_acc(int);
    bool check_pin(int);
    char* getName();
    char* get_acctype();
    int check_duplicate(int*,int,int);
};
//This function calculates the number of digits of an account number
    int chk_accdigit(int acc)
    {
        int c=1;
        if(acc<1000000||acc>9999999)
        c=0+;
        return c;
    }
//This function calculates the number of digits of a pin number
    int chk_pindigit(int pin)
    {
        int c=1;
        if(pin<1000||pin>9999)
        c=0;
        return c;
    }
//This function returns type of an account(Current/Savings)
    char* Bank_account::get_acctype()
    {
        return acc_type;
    }
//This function checks uniqueness of an account number
    int Bank_account::check_duplicate(int prev[],int j,int acc_no)
    {
        for(int i=0;i<j;i++)
        {
            if(prev[i]==acc_no)
            return 1;
        }
        return 0;
    }
//This function is used to input all the information from user
void Bank_account::get_data(int f)
{
    static int count=0;
    static int prev[99999];
    if(f!=0)
    {
        for(int i=0;i<count;i++)
        {
            if(prev[i]==f)
            prev[i]=0;
        }
    return;
    }
while(1)
{

    cout<<"\nEnter account no.(7 digit)-";
    cin>>acc_no;
    if(chk_accdigit(acc_no)!=1)
    {
        cout<<"Invalid account no. entered!!(check no. of digits)\n";
        continue;
    }
    prev[count]=acc_no;
    if(check_duplicate(prev,count,acc_no)!=0)
    {
        cout<<"\nThis account no. already exists!!Please enter a different account no.\n";
        continue;
    }
    break;
}
count++;
cout<<"\nEnter customer name:";
cin.ignore();
cin.getline(customer_name,100);
while(1)
{
    cout<<"\nEnter account type(Current/Savings):";
    cin.getline(acc_type,100);
    if(strcmp(acc_type,"Current")==0||
    strcmp(acc_type,"Savings")==0)
    break;
    cout<<"Invalid account type entered!!";
}
while(1)
{
    cout<<"\nEnter pin no.(4 digit)-";
    cin>>pin_no;
    if((chk_pindigit(pin_no))==1)
    break;
    cout<<"Invalid pin no. entered!!(check no. of digits)\n";
}
if(strcmp(acc_type,"Savings")==0)
{
    while(1)
    {
    cout<<"\nEnter account balance(Rs.):";
    cin>>balance;
    if(balance>=100)
    break;
    cout<<"Invalid amount given!!Minimum Rs. 100 must be deposited initially... \n";
    }
}
if(strcmp(acc_type,"Current")==0)
{
    while(1)
    {
        cout<<"\nEnter account balance(Rs.):";
        cin>>balance;
        if(balance>=1000)
        break;
        cout<<"Invalid amount given!!Minimum Rs. 1000 must be deposited initially... \n";
    }
}
cout<<"\nCongratulations!"<<customer_name<<",Your account is successfully created.\n";
}
//This function removes all information of an account which is going to be closed
void Bank_account::del_data()
{
    acc_no=0;
    pin_no=0;
    balance=0.0;
}
//This function is used to deposit a valid amount of balance in an account
 void Bank_account::deposit_balance(double blnc)
{
    cout<<"Please wait...\n\n";
    if(blnc<=0)
    {
        cout<<"\nTransaction unsucessful!!Please enter a valid amount.\n";
        return;
    }
    balance+=blnc;
    cout<<"Transaction completed succcessfully.\n";
}
//This function is used to withdraw a valid amount of balance from an account
int Bank_account::withdrawn_balance(double blnc,int f)
{
    char ch;
    cout<<"Please wait...\n\n";
    if(blnc<=0)
    {
        cout<<"\nTransaction unsucessful!!Please enter a valid amount.\n";
        return 0;
    }
    if(blnc>balance)
    {
        cout<<"\nTransaction unsucessful!!Your current balance is:"<<balance<<"\n"<<"you are unable to request for:"<<blnc<<"\n\n";
        return 0;
    }
    if(f==1)
    {
        if((double)(balance-blnc)<100)
        {
            cout<<"\nTransaction unsucessful!!Minimum Rs.100 must be stored to maintain a savings account."<<"\n\n";
            cout<<"Do you want to withdraw all money and close your account?(Y/N):";
            cin>>ch;
            if(ch=='Y'||ch=='y')
            return 1;
            return 0;
        }
    }
    else if(f==0)
    {
        if((double)(balance-blnc)<1000)
            {
                cout<<"\nTransaction unsucessful!!Minimum Rs.1000 must be stored to maintain a current account."<<"\n\n"; cout<<"Do you want to withdraw all money and close your account?(Y/N):";
                cin>>ch;
                if(ch=='Y'||ch=='y')
                return 1;
                return 0;
            }
    }
    balance-=blnc;
    cout<<"Transaction completed successfully.\n";
}
//This function is used to check whether an account number exists or not
bool Bank_account::check_acc(int acc)
{
    if(acc_no==acc)
    return true;
    else
    return false;
}
//This function is used to check whether a pin number exists or not
bool Bank_account::check_pin(int pin)
{
    if(pin_no==pin)
    return true;
    else
    return false;
}
//This function is used to update a customer's pin number
void Bank_account::update_pin_no()
{
    int pin1,pin2;
    while(1)
    {
        cout<<"Enter old pin no.";
        cin>>pin1;
        if(pin1==pin_no)
        break;
        cout<<"Invalid pin no. entered!!\n";
        return;
    }
    while(1)
    {
    cout<<"\nEnter new pin no.(4 digit)-";
    cin>>pin2;
    if((chk_pindigit(pin2))==1)
    break;
    cout<<"Pin no. can't be changed,invalid no. of digits entered!!\n";
    }
    pin_no=pin2;
    cout<<"Pin no. successfully updated.\n";
}
//This function is used to print all the information of a customer
void Bank_account::print_data()
{
    cout<<"\n\nAccount no.-:"<<acc_no;
    cout<<"\n\nAccount type:"<<acc_type;
    cout<<"\n\nAccount balance:Rs."<<balance<<"\n";
}
//This function returns name of a customer
 char* Bank_account::getName()
{
    return customer_name;
}
int main()
{
    int num1=0,i,acc,pin,ch,ac_flag,ch1,ch2,del,cr=0,admin=2016;
    bool flag;
    double amount;
    char c,op;
    Bank_account *cust=new Bank_account[99999];
    cout<<"\n\n";
    while(1)
    {
//Main menu'
        cout<<"\nWELCOME TO BANK\n---------------------\n""\n1.ADMINISTRATOR(create account(s)).\n2.CUSTOMER(View/Modify existing account(s)).\n3.EXIT.\n\nEnter your choice:";
        cin>>ch1;
        switch(ch1)
        {
            case 1:
            cout<<"Enter administrator password:";
            cin>>admin;
            if(admin!=2016)
            {
                cout<<"\nInvalid Password!!!";
                break;
            }
    cust[num1].get_data(0);
    num1++;
    cr++;
    break;
    case 2:
    if(cr<=0)
    {
        cout<<"Operation failed!!There is no account present in the bank.\n";
        break;
    }
    while(1)
    {
    do
    {
        cout<<"\nEnter account no.:";
        cin>>acc;
        for(i=0;i<num1;i++)
        {
            if(flag=cust[i].check_acc(acc))
            break;
        }
    if(i==num1)
    cout<<"\nAccount no. does not exist!!\n";
    }while(flag==false);
    cout<<"\nHello "<<cust[i].getName()<<",welcome to your account...\n";
    cout<<"\nEnter Pin number(Be careful):";
    cin>>pin;
    if((flag=cust[i].check_pin(pin))==false)
    {
        cout<<"Invalid pin no. entered!!\nOperation aborted for this customer!!\n";
        op='N';
        break;
    }
    while(1)
    {
        op='Y';
        del=0;
//Menu for operations to be performed on an account
        cout<<"\nCustomer menu\n---------------------\n""\n1.Account Details.\n2.Depositing Balance.\n3.Withdraw Balance.\n4.Update Pin no.\n5.Exit operation for this customer.\n\nEnter your choice:";
        cin>>ch;
    switch(ch)
    {
        case 1:
        cust[i].print_data(); break;
        case 2:
        cout<<"Enter amount to deposit:";
        cin>>amount;
        cust[i].deposit_balance(amount);
        break;
        case 3:
        cout<<"Enter amount to withdraw;";
        cin>>amount;
        if(strcmp((cust[i].get_acctype()),"Savings"))
        ac_flag=1;
        else
        ac_flag=0;
        del=cust[i].withdrawn_balance(amount,ac_flag);
        if(del==1)
        {
            cout<<"\nAre you sure? (Y/N):";
            cin>>c;
            if(c!='Y'&&c!='y')
            break;
            cust[i].del_data();
            cust[i].get_data(acc);
            cr--;
            cout<<"\nAccount Closed.\n";
        }
        break;
        case 4:
        cust[i].update_pin_no();
        break;
        case 5:
        op='N';
        break;
        default:
        cout<<"Invalid choice!!!!\n";
    }
    if(del==1)
        break;
    if(op=='N')
        break;
}
    if(del==1)
        break;
    op='N';
    cout<<"\nDo you want to continue operation for another customer(Y/N):";
    cin>>op;
    if(op!='Y'&&op!='y')
        break;
}
    break;
    case 3:
    cout<<"\nThank You,visit again..\n"; return 0;
    default:
    cout<<"Invalid choice!!!!\n";
}
}
    delete[]cust;//Deallocate memory space
}
