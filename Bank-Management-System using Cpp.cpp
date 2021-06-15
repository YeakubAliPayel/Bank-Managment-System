#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include <iostream>
#include<cstdio>
#include <cstdlib>
#include<ctime>
#include <cstring>
using namespace std;
FILE *f1,*f2,*f3;
int choice;
char fixd[20]="fixed";
char current[20]="current",pass[20]="YAP104";
COORD c={0,0};
class information{
    public:
    char name[100];
    char email[50];
    long int accno;
    float ammount;
    long long nid;
    int d,m,y;
    char acctype[20];
    float yrr;
};
information inf,inf1;
void mainmenu();
void coordinate(int x,int y)
{
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void welcome(void)
{
    int i;
    system("cls");
    coordinate(15,10);
    cout<<"WELCOME TO BANK MANAGEMENT SYSTEM";
    coordinate(12,15);
    for(i=0;i<40;i++){
        printf("%c",177);
        Sleep(90);
    }
}
void timedate()
{
    coordinate(2,1);
    time_t a;
    //cout<<"today's time & date:";
    time(&a);
    cout<<ctime(&a);
}
void incorrect(void)
{
    system("cls");
    system("color cf");
    coordinate(12,12);
    cout<<"INCORRECT PASSWORD!";
    printf("\a");
    Sleep(20);
    system("color 9F");
    Sleep(20);
    system("color FA");
    Sleep(20);
    system("color cf");
    Sleep(20);
    system("color 9F");
    Sleep(20);
    system("color FA");
}
void load(void)
{
    int i;
    system("cls");
    coordinate(12,13);
    cout<<"Loading...";
    coordinate(12,15);
    for(i=0;i<20;i++){
        printf("%c",177);
        Sleep(200);
    }
}
void close(void)
{
    cout<<'\a';
    int i;
    system("cls");
    coordinate(12,13);
    cout<<"Closing...";
    coordinate(12,15);
    for(i=0;i<20;i++){
        printf("%c",177);
        Sleep(50);
    }
}
int pos=5,j=0;
void newaccount()
{
    pos=5;
    f1=fopen("inform.dat","a+");
    system("cls");
    timedate();
    coordinate(10,3);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<" ENTER YOUR INFORMATION ";
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    coordinate(12,pos);
    cout<<"DD: ";
    cin>>inf.d;
    while(j!=1)
    {
        if(inf.d<1 || inf.d>31)
        {
            coordinate(12,pos);
            cout<<"Invalid date.....please re enter: ";
            cin>>inf.d;
            pos++;
        }
        else
        {
            j=1;
        }
    }
    j=0;
    pos+=2;
    coordinate(12,pos);
    cout<<"MM: ";
    cin>>inf.m;
    while(j!=1)
    {
        if(inf.m<1 || inf.m>12)
        {
            coordinate(12,pos);
            cout<<"Invalid month.....please re enter: ";
            cin>>inf.m;
            pos++;
        }
        else
        {
            j=1;
        }
    }
    j=0;
    pos+=2;
    coordinate(12,pos);
    cout<<"YYYY: ";
    cin>>inf.y;
    pos=pos+2;
    coordinate(12,pos);
    cout<<"NAME: ";
    scanf(" %[^\n]",&inf.name);
    pos+=2;
    coordinate(12,pos);
    cout<<"ACCOUNT NO: ";
    cin>>inf.accno;
    int d=inf.accno;
    while(fread(&inf1,sizeof(information),1,f1)==1)
    {
        if(inf1.accno==d)
        {
            coordinate(12,pos);
            cout<<"Account no. is already exist....please re enter:";
            cin>>inf.accno;
            d=inf.accno;
            fseek(f1,0,SEEK_SET);
            pos=pos+2;
        }
    }
    pos+=2;
    coordinate(12,pos);
    cout<<"NATIONAL ID/STUDENT ID: ";
    cin>>inf.nid;
    pos=pos+2;
    coordinate(12,pos);
    cout<<"AMMOUNT: ";
    cin>>inf.ammount;
    pos=pos+2;
    coordinate(12,pos);
    cout<<"ACCOUNT TYPE(fixed/current): ";
    cin>>inf.acctype;
    if(strcmp(inf.acctype,fixd)==0)
    {
        float interest,imc;
        pos=pos+2;
        coordinate(12,pos);
        cout<<"For how many year? ";
        cin>>inf.yrr;
        imc=inf.yrr*0.833333;
        interest=inf.ammount*((1.08*inf.yrr)-1);
        pos=pos+2;
        coordinate(12,pos);
        cout<<"Interest after "<<inf.yrr<<"year :"<<interest;
        inf.ammount=inf.ammount+interest;
    }
    pos+=2;
    coordinate(12,pos);
    cout<<"EMAIL ADDRESS: ";
    scanf("%s",inf.email);
    fwrite(&inf,sizeof(inf),1,f1);
    fclose(f1);
    Sleep(500);
    system("cls");
    coordinate(12,15);
    cout<<"        Successfully added!";
    char yn;
    pos=pos+2;
    coordinate(12,pos);
    cout<<"Do you want to back Main Menu?(y/n):";
    pos=5;
    yn=getch();
    Beep(5000,70);
    if(yn=='y')
    {
        mainmenu();
    }
    else close();
}
void deposit()
{
    int da,test=0,dipd,dipm,dipy,dcc,mcc,ycc;
    long int an;
    system("cls");
    coordinate(12,5);
    cout<<"DD:";
    cin>>dipd;
    coordinate(12,7);
    cout<<"MM:";
    cin>>dipm;
    coordinate(12,9);
    cout<<"YYYY:";
    cin>>dipy;
    coordinate(12,11);
    cout<<"Enter Account no:";
    cin>>an;
    coordinate(12,13);
    cout<<"Enter Ammount:";
    cin>>da;
    f1=fopen("inform.dat","rb+");
    while(fread(&inf,sizeof(information),1,f1)==1)
    {
        if(inf.accno==an)
        {
             if(dipd<inf.d)
                {
                    dipd=dipd+30;
                    dcc=dipd-inf.d;
                    dipm=dipm-1;
                }
                else
                {
                    dcc=dipd-inf.d;
                }
                if(dipm<inf.m)
                {
                    dipm=dipm+12;
                    mcc=dipm-inf.m;
                    dipy=dipy-1;
                }
                else
                {
                    mcc=dipm-inf.m;
                }
                ycc=dipy-inf.y;
                mcc=(mcc+(ycc*12));
                if(mcc<inf.yrr && strcmp(inf.acctype,"fixed")==0)
                {
                    coordinate(12,15);
                    cout<<"You are Failed!";
                }
                else
                {
           inf.ammount=inf.ammount+da;
           fseek(f1,ftell(f1)-sizeof(inf),0);
           fwrite(&inf,sizeof(information),1,f1);
                }
           test=1;
           break;
        }
    }
    fclose(f1);
    if(test==0)
    {
        coordinate(12,15);
        cout<<"No Account Found!";
    }
    coordinate(12,17);
    cout<<"Do you want to back Main Menu?(y/n)";
    char yn=getch();
    Beep(5000,70);
    if(yn=='y')
    {
        mainmenu();
    }
    else close();
}
void widthrow()
{
    int date,month,year;
    system("cls");
    coordinate(10,5);
    cout<<"DD:";
    cin>>date;
    coordinate(10,7);
    cout<<"MM:";
    cin>>month;
    coordinate(10,9);
    cout<<"YY:";
    cin>>year;
    long int an,wa,na;
    coordinate(10,10);
    cout<<"Enter account no:";
    cin>>an;
    coordinate(10,11);
    cout<<"Enter ammount that you want to widthrow:";
    cin>>wa;
    f1=fopen("inform.dat","r+");
    while(fread(&inf,sizeof(information),1,f1)==1)
    {
        if(inf.accno==an)
        {
            na=inf.ammount-wa;
            if(strcmp(inf.acctype,"fixed")==0)
            {
                int mc=0,dc=0,yc=0,mm=0,dd=0,yy=0;
                dd=inf.d;
                mm=inf.m;
                yy=inf.y;
                if(date<dd)
                {
                    date=date+30;
                    dc=date-dd;
                    month=month-1;
                }
                else
                {
                    dc=date-dd;
                }
                if(month<mm)
                {
                    month=month+12;
                    mc=month-mm;
                    year=year-1;
                }
                else
                {
                    mc=month-mm;
                }
                yc=year-yy;
                mc=(mc+(yc*12));
                if(mc<inf.yrr)
                {
                    int kk=inf.yrr-mc;
                    coordinate(10,13);
                    cout<<"You can withdthraw after "<<kk<<" month";
                    break;
                }
          else
            {
                if(na<0)
                {
                    coordinate(10,13);
                    cout<<"Faild to withdraw...you have not available ammount!";
                    break;
                }
                else
                {
                    inf.ammount=na;
                    fseek(f1,ftell(f1)-sizeof(inf),0);
                    fwrite(&inf,sizeof(information),1,f1);
                    break;

                }
            }
            }
            else
            {
            if(na<0)
            {
                coordinate(10,13);
                cout<<"Faild to widthraw you have not available ammount!";
            }
            else
            {
                inf.ammount=na;
                fseek(f1,ftell(f1)-sizeof(inf),0);
                fwrite(&inf,sizeof(information),1,f1);
                break;

            }
        }
    }
    }
    fclose(f1);
    coordinate(10,15);
    cout<<"Do you want to back Main Menu?(y/n):";
    if(getch()=='y')
    {
        Beep(5000,70);
        mainmenu();
    }
    else{
        Beep(5000,70);
        close();
    }

}
void blanceenquiry()
{
    system("cls");
    long long int testaccno;
    coordinate(10,5);
    cout<<"enter account number:";
    cin>>testaccno;
    f1=fopen("inform.dat","r");
    fseek(f1,0,SEEK_SET);
    int yy=0;
    while(fread(&inf,sizeof(information),1,f1)==1)
    {
       fseek(f1,0,SEEK_CUR);
       if(inf.accno==testaccno)
       {
           yy=1;
           coordinate(10,7);
           cout<<"Your ammoumt is:"<<inf.ammount;
           fclose(f1);
           break;
       }
    }
    if(yy==0)
    {
        coordinate(20,8);
        cout<<"No Account Found!!";
    }
    char yn;
    coordinate(10,10);
    cout<<"Are you want to back mainmenu(y/n):";
    cin>>yn;
    if(yn=='y')
    {
        mainmenu();
    }
    if(yn=='n')
    {
        return;
    }
}
void searchaccount()
{
    system("cls");
    long long int testaccno;
    coordinate(10,5);
    cout<<"enter account number:";
    cin>>testaccno;
    f1=fopen("inform.dat","r");
    fseek(f1,0,SEEK_SET);
    int yyy=0;
    while(fread(&inf,sizeof(inf),1,f1)==1)
    {
       fseek(f1,0,SEEK_CUR);
       if(inf.accno==testaccno)
       {
           yyy=1;
           coordinate(10,7);
           cout<<"\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2";
           coordinate(10,9);
           cout<<"DD/MM/YYYY:"<<inf.d<<"/"<<inf.m<<"/"<<inf.y;
           coordinate(10,11);
           cout<<"NAME:"<<inf.name;
           coordinate(10,13);
           cout<<"ACCOUNT NO:"<<inf.accno;
           coordinate(10,15);
           cout<<"NID/SID:"<<inf.nid;
           coordinate(10,17);
           cout<<"AMMOUNT:"<<inf.ammount;
           if(strcmp(inf.acctype,"fixed")==0)
           {
           coordinate(10,19);
           cout<<"ACCOUNT TYPE:"<<inf.acctype<<" for"<<inf.yrr<<" month";
           }
           else
           {
           coordinate(10,19);
           cout<<"ACCOUNT TYPE:"<<inf.acctype;
           }
           coordinate(10,21);
           cout<<"\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2";
           fclose(f1);
           break;
       }
    }
    if(yyy==0)
    {
        coordinate(10,7);
        cout<<"No Account Found!!";
    }
    char yn;
    coordinate(10,23);
    cout<<"Are you want to back mainmenu(y/n):";
    cin>>yn;
    if(yn=='y')
    {
        mainmenu();
    }
    if(yn=='n')
    {
        return;
    }
}
void discardaccount()
{
    system("cls");
    long long int testaccno;
    coordinate(10,5);
    cout<<"entre account number:";
    cin>>testaccno;
    f1=fopen("inform.dat","r");
    f2=fopen("info.dat","w");
    rewind(f1);
    fseek(f1,0,SEEK_CUR);
    fseek(f2,0,SEEK_END);
    while(fread(&inf,sizeof(information),1,f1)==1)
    {
       fseek(f1,0,SEEK_CUR);
       fseek(f2,0,SEEK_END);
       fread(&inf,sizeof(inf),1,f1);
       if(inf.accno==testaccno)
       {

       }
       else
       {
           fwrite(&inf,sizeof(information),1,f2);
       }
    }
    fclose(f1);
    fclose(f2);
    remove("inform.dat");
    rename("info.dat","inform.dat");
    coordinate(10,7);
    cout<<"succesfully discard";
    char yn;
    coordinate(10,9);
    cout<<"Are you want to back mainmenu(y/n):";
    cin>>yn;
    if(yn=='y')
    {
        mainmenu();
    }
    if(yn=='n')
    {
        return;
    }
}
char ccc;
void setting()
{
    int cho;
    system("cls");
    coordinate(10,10);
    cout<<"\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2";
    coordinate(12,12);
    cout<<"1. >>Reset";
    coordinate(12,14);
    //cout<<"2. >>change passward";
    coordinate(10,16);
    cout<<"\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2";
    coordinate(10,18);
    cout<<"Enter Your Choice:";
    cin>>cho;
    if(cho==1)
    {
        remove("inform.dat");
        coordinate(10,20);
        cout<<"Successfully reset";
    }
    int j=8,k=0;
    if(cho==2)
    {
        system("cls");
        char cp[20];
        for( ;k!=1; )
        {
        coordinate(10,j);
        cout<<"Enter old passward:";
        cin>>cp;
        f3=fopen("passward.txt","r+");

        if(strcmp(cp,pass)==0)
        {
            for(int l=0;pass[l]!='\0';l++)
            {
                pass[l]='\0';
            }
            j=j+2;
            coordinate(10,j);
            cout<<"Enter new passward:";
            cin>>pass;
            k=1;
            }
        else
        {
            j=j+2;
            coordinate(10,j);
            cout<<"Incorrect old passward";
            j=j+2;
            coordinate(10,j);
            cout<<"are you want to get conformation code(y/n)??? ";
            ccc=getch();
            if(ccc=='y')
            {
                j=j+2;
                coordinate(10,j);
                cout<<"follow code and direct change the value of pass variable line no>>13";
                break;
            }
            else
            {
                j=j+2;
                continue;
            }
        }
    }
}
j=j+2;
coordinate(10,j);
cout<<"Are you want to back mainmenu?(y/n):";
char chh=getch();
if(chh=='y');
{
    mainmenu();
}
}
void holderlist()
{
    system("cls");
    timedate();
    f1=fopen("inform.dat","r");
    coordinate(10,5);
    cout<<"Date";
    coordinate(25,5);
    cout<<"Name";
    coordinate(45,5);
    cout<<"Account No";
    coordinate(60,5);
    cout<<"SID/NID";
    coordinate(75,5);
    cout<<"Account Type";
    coordinate(95,5);
    cout<<"Email Address";
    int jj=7;
    while(fread(&inf,sizeof(information),1,f1)==1)
    {
    coordinate(10,jj);
    printf("%d/%d/%d",inf.d,inf.m,inf.y);
    coordinate(25,jj);
    printf("%s",inf.name);
    coordinate(45,jj);
    printf("%ld",inf.accno);
    coordinate(60,jj);
    printf("%lld",inf.nid);
    coordinate(75,jj);
    printf("%s",inf.acctype);
    coordinate(95,jj);
    printf("%s",inf.email);
    jj+=2;
    }
    fclose(f1);
    coordinate(10,jj);
    cout<<"Do you want to Back Main Menu?(y/n)";
    char chh=getch();
    Beep(5000,70);
    if(chh=='y')
    {
        mainmenu();
    }
    else close();
}
void modify()
{
    int tk=16,cho;
    int acn,testa=0;
    system("cls");
    coordinate(12,6);
    cout<<"Enter Account no:";
    cin>>acn;
    f1=fopen("inform.dat","rb+");
    while(fread(&inf,sizeof(information),1,f1)==1)
    {
        if(inf.accno==acn)
        {
            while(1)
            {
            coordinate(12,8);
            cout<<"1. Name:"<<inf.name;
            coordinate(12,10);
            cout<<"2. Account no:"<<inf.accno;
            coordinate(12,12);
            cout<<"3. SID/NID:"<<inf.nid;
            coordinate(12,14);
            cout<<"4. Account Type:"<<inf.acctype;
            coordinate(12,tk);
            cout<<"What you want to modify?if you mind unnecessery press 0:";
            cin>>cho;
            if(cho==0)
            {
                break;
            }
            if(cho==1)
            {
                tk=tk+2;
                coordinate(12,tk);
                cout<<"New Name:";
                scanf(" %[^\n]",&inf.name);
            }
            if(cho==2)
            {
                tk=tk+2;
                coordinate(12,tk);
                cout<<"New Account No:";
                cin>>inf.accno;
            }
            if(cho==3)
            {
                tk=tk+2;
                coordinate(12,tk);
                cout<<"New NID/SID:";
                cin>>inf.nid;
            }
            if(cho==4)
            {
                tk=tk+2;
                coordinate(12,tk);
                cout<<"New Account Type(fixed/current):";
                cin>>inf.acctype;
                if(strcmp(inf.acctype,"fixed")==0)
                {
                    tk=tk+2;
                    coordinate(12,tk);
                    cout<<"Fixed for How many month?:";
                    cin>>inf.yrr;
                }
            }
            tk=tk+2;
            }
            testa=1;
        }

    }
    fseek(f1,ftell(f1)-sizeof(inf),0);
    fwrite(&inf,sizeof(information),1,f1);
    fclose(f1);
    if(testa==0)
    {
        coordinate(12,10);
        cout<<"No Account Found!";
    }
    tk=tk+2;
    coordinate(12,tk);
    cout<<"Are you want to back Main Menu?(y/n):";
    char ynyn=getch();
    if(ynyn=='y')
    {
        mainmenu();
    }

}
 void mainmenu()
{
    system("cls");
    timedate();
    coordinate(10,5);
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<" MAIN MENU ";
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    coordinate(12,7);
    cout<<"\xDB\xB2\xDB  1.OPEN NEW ACCOUNT";
    coordinate(12,9);
    cout<<"\xDB\xB2\xDB  2.DEPOSIT AMOUNT";
    coordinate(12,11);
    cout<<"\xDB\xB2\xDB  3.WITHDRAW AMOUNT";
    coordinate(12,13);
    cout<<"\xDB\xB2\xDB  4.BALANCE INQUIRY";
    coordinate(12,15);
    cout<<"\xDB\xB2\xDB  5.ACCOUNT HOLDER LIST";
    coordinate(12,17);
    cout<<"\xDB\xB2\xDB  6.MODIFY AN ACCOUNT";
    coordinate(12,19);
    cout<<"\xDB\xB2\xDB  7.DISCARD ANY ACCOUNT";
    coordinate(12,21);
    cout<<"\xDB\xB2\xDB  8.SEARCH AN ACCOUNT";
    coordinate(12,23);
    cout<<"\xDB\xB2\xDB  9.SETTINGS";
    coordinate(12,25);
    cout<<"\xDB\xB2\xDB  0.Exit";
    coordinate(10,27);
    cout<<"\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2";
    coordinate(10,29);
    cout<<"What's your choice: ";
    choice=getch();
    choice-=48;
    if(choice>=1&&choice<=9)Beep(5000,70);
    else printf("%c",7);
    if(choice>=1&&choice<10) load();
    else if(choice==0) close();
    if(choice==1) newaccount();
    else if(choice==2) deposit();
    else if(choice==3) widthrow();
    else if(choice==4) blanceenquiry();
    else if(choice==5) holderlist();
    else if(choice==6) modify();
    else if(choice==7) discardaccount();
    else if(choice==8) searchaccount();
    else if(choice==9) setting();
    else if(choice!=0) mainmenu();
}
void password()
{
    system("color 0a");
    char p[20];
    int i;
    timedate();
    coordinate(20,5);
    cout<<"ADMIN LOGIN";
    coordinate(12,12);
    cout<<"Enter Password: ";
    char ch;

        for(i=0;;i++)
        {
            ch=getch();
            if(ch!=8&&ch!=13)
            {
                p[i]=ch;
                putch('*');
            }
            else if(ch==13){
                p[i]='\0';
                break;
            }
        }
        if(strcmp(p,pass)==0)
        {
            welcome();
        }
        else
        {
            incorrect();
            system("cls");
            password();
        }
}
int main()
{
    system("COLOR 0A");
    password();
    mainmenu();

    return 0;
}
