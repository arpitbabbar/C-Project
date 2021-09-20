#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class student                                                            // class in which we accepts student information and display it
{
public:
    char rno[50],name[50],course[50],dob[20],address[50];
    void accept()
    {
        cout<<endl<<"enter roll number: ";
        cin>>rno;
        cout<<endl<<"enter name: ";
        cin>>name;
        cout<<endl<<"enter the course: ";
        cin>>course;
        cout<<endl<<"enter the date of birth: ";
        cin>>dob;
        cout<<endl<<"enter the address: ";
        cin>>address;
    }
    void display()
    {
        cout<<endl<<rno<<setw(25)<<name;
        for(int i=1;i<=20-strlen(name);i++)
        {
            cout<<" ";
        }
        cout<<course;
        for(int j=1;j<=20-strlen(course);j++)
        {
            cout<<" ";
        }
        cout<<dob<<setw(15)<<address;
    }
};
student obj;
class fees                                              // In this class we accept course and various fees of that course and display it
    {  public:

        char courseid[50];
        int tfees,pfees,mfees,totfees;

       public:

        void accept()
        {
            cout<<endl<<"enter course: ";
            cin>>courseid;
            cout<<endl<<"enter tution fees: ";
            cin>>tfees;
            cout<<endl<<"enter practical fees: ";
            cin>>pfees;
            cout<<endl<<"enter maintainence fees: ";
            cin>>mfees;


        }

        void display()
        {totfees=tfees+pfees+mfees;
            cout<<endl<<courseid;
            for(int i=1;i<=20-strlen(courseid);i++)
            {
                cout<<" ";
            }
            cout<<tfees<<"\t\t"<<pfees<<"\t\t\t\t"<<mfees<<"\t\t"<<totfees;
        }




    };
fees obj2;
class acadmics                                                                // In this class we enter students marks and display it
{
    int marks[3];

public:
    char roll[20];
    void enter_marks ()
    {
        cout<<endl<<"enter roll no.: ";
        cin>>roll;
        cout<<endl<<"enter marks: ";
        for(int i=0;i<3;++i)
        cin>>marks[i];
    }
    void display_marks()
    {
        cout<<endl<<"roll no.\t"<<"sub1"<<setw(15)<<"sub2"<<setw(15)<<"sub3"<<setw(15)<<endl;
        cout<<"============================================================================"<<endl;
        cout<<roll<<setw(17);
        for(int i=0;i<3;++i)
            cout<<marks[i]<<setw(15);
    }
}obj3;
void writemarks()                                                          // Function in which we write marks of each student in file
{fstream fin;
fin.open("marks.txt",ios::app);
obj3.enter_marks();
fin.write((char*)&obj3,sizeof(obj3));
fin.close();
}
void viewmarks()                                                          // Function in which each student view their marks
{fstream fout;
char rl[20];
cout<<endl<<"enter roll no.: ";
cin>>rl;
fout.open("F://studentinfo.txt",ios::in);
fout.seekg(0,ios::end);
int size=fout.tellg()/sizeof(obj);
fout.seekg(0,ios::beg);
for(int i=1;i<=size;i++)
{fout.read((char*)&obj,sizeof(obj));
if(strcmp(obj.rno,rl)==0)
{fstream fout1;
fout1.open("F://marks.txt",ios::in);
fout1.seekg(0,ios::end);
int size2=fout1.tellg()/sizeof(obj3);
fout1.seekg(0,ios::beg);
for(int i=1;i<=size;i++)
{fout1.read((char*)&obj3,sizeof(obj3));
if(strcmp(obj3.roll,rl)==0)
   {obj3.display_marks();
    break;}
}
fout1.close();
}
}
fout.close();
}
void writefees()                                                      // function to store fees in a file
{
    fstream wr;
    wr.open("F:\\studentfees.txt",ios::app);
    obj2.accept();
    wr.write((char*)&obj2,sizeof(obj2));
    wr.close();
}

void viewfees()                                                        // function to view fees of all students
{
  fstream rd;
  rd.open("F:\\studentfees.txt",ios::in);
  rd.seekg(0,ios::end);
  int size2=rd.tellg()/sizeof(obj2);
  rd.seekg(0,ios::beg);
  cout<<"course\t\ttution fees\t\tpractical fees\t\tmaintainence fees\ttotal fees"<<endl;
  cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
  for(int i=1;i<=size2;i++)
  {rd.read((char*)&obj2,sizeof(obj2));
  obj2.display();

  }
  cout<<endl<<"-------------------------------------------------------------------------------------------------------"<<endl;
  rd.close();
}

void generatefees()                                                 // function to generate fees
{   int tempfees;
    char rid[50];char tempcourse[50];
    cout<<"enter roll number: ";
    cin>>rid;
    system("cls");
    cout<<"\n";
    fstream rd;
    rd.open("F:\\studentinfo.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.rno,rid)==0)
        {
            strcpy(tempcourse,obj.course);

        }
    }
    fstream rd2;
    rd2.open("F:\\studentfees.txt",ios::in);
  rd2.seekg(0,ios::end);
  int size2=rd2.tellg()/sizeof(obj2);
  rd2.seekg(0,ios::beg);
  cout<<"course\t\t tution fees\t\tpractical fees\t\t maintainence fees\ttotal fees"<<endl;
  cout<<"-------------------------------------------------------------------------------------------------------";
   for(int i=1;i<=size2;i++)
  {rd2.read((char*)&obj2,sizeof(obj2));
  if (strcmp(tempcourse,obj2.courseid)==0)
  {obj2.display();
  tempfees=obj2.totfees;


  }
  }
  cout<<endl<<"-------------------------------------------------------------------------------------------------------"<<endl;

cout<<endl<<setw(60)<<"TOTAL FEES TO BE PAID ="<<tempfees<<endl<<endl;
rd.close();
rd2.close();
}
void writestudent()                                                         // function to write student info in a file
{fstream wr;
wr.open("F://studentinfo.txt",ios::app);
obj.accept();
wr.write((char*)&obj,sizeof(obj));
wr.close();

}
void viewstudent()                                                        //function to view all student info
{fstream rd;
rd.open("F://studentinfo.txt",ios::in);
rd.seekg(0,ios::end);
int size=rd.tellg();
int n=size/sizeof(obj);
rd.seekg(0,ios::beg);
cout<<"Rollno"<<setw(25)<<"Name"<<setw(20)<<"Course"<<setw(23)<<"Dateofbirth"<<setw(15)<<"Address"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;
for(int i=1;i<=n;i++)
{rd.read((char*)&obj,sizeof(obj));
obj.display();
}
cout<<endl<<"-------------------------------------------------------------------------------------------"<<endl;
rd.close();
}
void searchstudent()                                               // function to search particular student's info
{char rollno[50];
    cout<<"enter roll no. to be searched: ";
    cin>>rollno;
    system("cls");
    cout<<"\n\n";
    fstream rd;
    rd.open("F:\\studentinfo.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.rno,rollno)==0)
        {cout<<"Rollno"<<setw(25)<<"Name"<<setw(20)<<"Course"<<setw(23)<<"Dateofbirth"<<setw(15)<<"Address"<<endl;
cout<<"-----------------------------------------------------------------------------------------";
obj.display();

cout<<endl<<"-------------------------------------------------------------------------------------------"<<endl;


        }
    }
rd.close();

}
void menu()                                                                          // main menu
{cout<<setw(75)<<"FOREIGN STUDENT MANAGEMENT,GNDU"<<endl;
 cout<<setw(75)<<"==============================="<<endl<<endl<<endl;
int e=0;
while(e!=1)
{   cout<<"1. STUDENT INFORMATION"<<endl<<endl;
    cout<<"2. FEES MANAGEMENT"<<endl<<endl;
    cout<<"3. ACADEMICS"<<endl<<endl;
    cout<<"4. EXIT";
    int choice;
    cout<<endl<<endl<<"enter choice: ";
    cin>>choice;
    system("cls");
    switch (choice)

        {
         case 1:
        {   int f=0;
        while(f!=1)
        {cout<<setw(65)<<"STUDENT INFORMATION"<<endl<<endl;
         cout<<"1. Add new student"<<endl;
         cout<<"2. Search a student"<<endl;
         cout<<"3. View all students"<<endl;
         cout<<"4. Exit";
         int choice2;
         cout<<endl<<"enter choice: ";
         cin>>choice2;
         system("cls");
         switch (choice2)
         {
         case 1:
            {writestudent();
                cout<<"added student"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;

            }
         case 2:
            {searchstudent();
                cout<<"searched student"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;
            }
         case 3:
            {viewstudent();
                cout<<"list of all students"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;
            }
         case 4:
            {
                f=1;
                break;
            }
         }
        }
        }
             break;

             case 2:
        {
             int f=0;
        while(f!=1)
        {cout<<setw(65)<<"FEES "<<endl<<endl;
         cout<<"1. Add new fees structure"<<endl;
         cout<<"2. View all fee structures"<<endl;
         cout<<"3. Generate fees"<<endl;
         cout<<"4. Exit";
         int choice3;
         cout<<endl<<"enter choice: ";
         cin>>choice3;
         system("cls");
         switch (choice3)
         {
         case 1:
            {writefees();
                cout<<"added fee structure"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;

            }
         case 2:
            {viewfees();
                cout<<"list of all fee structures"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;

            }
         case 3:
            {generatefees();
                cout<<"generated fees"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;
            }
         case 4:
            {
                f=1;
                break;
            }
         }
        }
        }

             break;


             case 3:
        {
             int f=0;
        while(f!=1)
        {cout<<setw(65)<<"ACADEMICS"<<endl<<endl;
         cout<<"1. Add student's marks"<<endl;
         cout<<"2. Search a student's marks"<<endl;
         cout<<"3. Exit";
         int choice3;
         cout<<endl<<"enter choice: ";
         cin>>choice3;
         system("cls");
         switch (choice3)
         {
         case 1:
            {writemarks();
                cout<<"added student's marks"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;

            }
         case 2:
            {viewmarks();
                cout<<endl<<"desired student's marks"<<endl;
                cout<<endl<<endl<<"press enter to continue";
                getch();
                system("cls");
                break;
            }
         case 3:
            {
                f=1;
                break;
            }
         }
        }
        }
             break;


             case 4:
        {
            e=1;
            break;
        }

        }



}


}
void Register()                                              // function to register first
{
    fstream fin;
    fin.open("register.txt",ios::app);
    char userid[40],pass[40];
    cout<<endl<<"user ID: ";
    cin>>userid;
    cout<<endl<<" Set password: ";
    int i=0;
    do{pass[i]=getch();
       if (pass[i]!='\r')
       {
           cout<<"*";
       }
       i++;
       }while(pass[i-1]!='\r');
    pass[i-1]='\0';

    fin<<userid<<"\t"<<pass<<endl;
    fin.close();
    cout<<endl<<"Registered successfully";
}
void login()                                                         // function to login in main menu
{
    fstream fout;
    fout.open("F://register.txt",ios::in);
    fout.seekg(0);
    char user1[40],pass1[40];
    char user[40],pass[40];
    int flag=0;
    cout<<endl<<"user ID: ";
    cin>>user1;
    cout<<endl<<"Password: ";
    int i=0;
    do{pass1[i]=getch();
       if (pass1[i]!='\r')
       {
           cout<<"*";
       }
       i++;
       }while(pass1[i-1]!='\r');
    pass1[i-1]='\0';
    while(!fout.eof())
    {
        fout>>user;
        fout>>pass;
        if(strcmp(user1,user)==0)
        {
            if(strcmp(pass1,pass)==0)
                {
                  flag++;
                }
        }
        if(flag==1)
           {
             cout<<endl<<"logged in";
             getch();
             system("cls");
             menu();
             break;
           }

        else
            continue;




    }

}
main()
{
    int ch,a=0;
    cout<<setw(75)<<"FOREIGN STUDENT MANAGEMENT,GNDU"<<endl;
    cout<<setw(75)<<"==============================="<<endl<<endl<<endl;
    while(a!=1)
    {cout<<"1. REGISTER"<<endl;
    cout<<"2. LOGIN"<<endl;
    cout<<"3.EXIT"<<endl<<endl<<endl;
    cout<<"enter your choice: ";
    cin>>ch;
    system("cls");
    switch(ch)
    {
        case 1: {cout<<setw(65)<<"Register"<<endl;
                  Register();
                  getch();
                  system("cls");}
        break;
        case 2:{cout<<setw(65)<<"Login"<<endl;
                 login();
                 getch();
                 system("cls");}
        break;
        case 3: a=1;

    }


    }

}

