#include<iostream>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<windows.h>
using namespace std;
class BMI
{
    char name[100],gen;
    int age,wght;
    double hght;
    double bmi;
    public:
	   char Bmi();
	   void display()
	   {
	   	cout<<name<<"\t"<<age<<"\t"<<hght<<"\t"<<wght<<"\t"<<bmi<<"\t"<<gen<<endl;
	   }
};
        char BMI::Bmi() 
		   	{ 
    		cout<<"\n PLEASE ENTER YOUR NAME:";
    		cin>>name;
    		cout<<"\n PLEASE SELECT YOUR GENDER(M/F):"; 
			cin>>gen;
			gen=toupper(gen);
	   		cout<<"\n ENTER YOUR AGE:";
    		cin>>age;
    		cout<<"ENTER YOUR height in metres:";
    		cin>>hght;
    		fflush(stdin);
    		cout<<"ENTER YOUR WEIGHT IN kgs:";
    		cin>>wght;
    		system("cls");
			bmi=wght/(hght*hght);
		
			cout<<"YOUR BODY MASS INDEX IS:"<<bmi<<endl<<endl;
				if((bmi>=18.5)&&(bmi<=24.9))
				{
					cout<<"YOUR ARE NORMAL!!YOUR ARE GOING GOOD!"<<endl;
				}
				else if(bmi>=25)
				{
					char ch;
					fflush(stdin);
					cout<<"YOU ARE OVERWEIGHT!! LETS MAKE YOU PERFECT!\n";
					cout<<"DO YOU WANNA SEE YOUR DIETPLAN AND EXERCISES??(y/n)";
					ch=getche();
					cout<<"\n\n\n";
					if(toupper(ch)=='Y')
					{
					 string getcontent;
                     ifstream openfile ("overweight.txt");
                     system("COLOR 0C");
                     if(openfile.is_open())
                     {
                        while(! openfile.eof())
                        {
                           openfile >> getcontent;
                           cout << getcontent << endl;
                        }
                      }
                      openfile.close();
                    }
					
				}
				else if(bmi<18.5)
				{
					char ch;
					fflush(stdin);
					cout<<"YOU ARE UNDERWEIGHT!! LETS MAKE YOU PERFECT!\n";
					cout<<"DO YOU WANNA SEE YOUR DIETPLAN AND EXERCISES??(y/n)";
					ch=getche();
					if(toupper(ch)=='Y')
					{
						cout<<"\n\n\n";
					 string getcontent;
                     ifstream openfile ("underweight.txt");
                      system("COLOR 0C");
                     if(openfile.is_open())
                     {
                        while(! openfile.eof())
                        {
                           openfile >> getcontent;
                           cout << getcontent << endl;
                        }
                      }
                      openfile.close();
                    }
				}
				
				
				char  ch;
				cout<<"\nDO U WANT TO TRY THIS CALCULATOR AGAIN(y/n):";
                ch=getche();
				return ch;	
		}

int main()
{
	char o;
    ifstream ost("bmi.txt");
    char weltext;
    if(ost.is_open())
    {
	   while(!ost.eof())
       {
           ost.get(weltext);
           cout << weltext;
        }
    }
    ost.close();
     system("COLOR 01");          //TO cReate a colour changing welcome to the user
    Sleep(800);
    system("COLOR 02");
    Sleep(800);
    system("COLOR 0D");
    Sleep(800);
    system("COLOR 0C");
    Sleep(800);
    system("COLOR 0A");
    Sleep(800);
    system("COLOR 03");
    Sleep(2000);
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t***********************************";
    cout<<"\n\t\t\t\t\t***********************************";
    cout<<"\n\t\t\t\t\t***   1)BMI CALCULATOR        ****";
    cout<<"\n\t\t\t\t\t***   2)MEMBER LIST           ****";
    cout<<"\n\t\t\t\t\t***********************************";
    cout<<"\n\t\t\t\t\t***********************************";
    cout<<"\n\t\t\t\tPLEASE ENTER YOUR CHOICE:";
    char t;
    cin>>t;
    if(t=='1')
    {
    		   hey:
    	       BMI obj;
    	       system("cls");
    	       o=obj.Bmi();
    	       ofstream MEM;
    		   MEM.open("members.txt",ios::app);
    		   MEM.write(reinterpret_cast<char *>(&obj), sizeof(obj));
			   MEM.close();
			   if(toupper(o)=='Y')
               goto hey;
               else
               {
                	system("cls");
                    cout<<"\n\n\nTHANKS FOR USING THE CALCULATOR!!";
                    exit(0);
               }
     }
     else{
			
			 BMI obj1;
			ifstream infile;
			infile.open("members.txt",ios::in);
			 while(!infile.eof())
			 {
			 infile.read((char *)&obj1, sizeof(obj1));
			 obj1.display();
	     	 }
	     	getch();
		}
    getch();

}

 
