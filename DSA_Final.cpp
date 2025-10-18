#include<iostream>
#include<string>
#include<conio.h>
#include <unistd.h>
using namespace std;

class Node 
{	
  public:
    string fname;
    string lname;
    string discipline;
    string qualification,gender;
    int rollNo, age, id;
    char section;
    float perecentage;
    Node* prev;
    Node* next;
};

class Student: public Node
{
	public:
		Node* head;
		Node* last;
		 
      Student() 
	  { 
        head = NULL;
		last = head;     //constructor
      }
     ~Student() {};    //destructor
     
    void addstudentdata();
    void search();
	void modify();
	void del();
	void studentdisplay();	
};

class teacher: public Node
{
	public:
		Node* head;
		Node* last;
		teacher()
		{
			head = NULL;
			last = head;
			
		}
		~teacher() {};
		
	void addteacherdata();
	void tsearch();
	void teacherdisplay();
};

bool check = true;

// function to add node to a list
void Student::addstudentdata()   //for student data 
{
    Node *p;
    p = new Node;
        
    system("cls");
    cout<<"Enter First Name of Student: ";
    cin>>p->fname;
    fflush(stdin);
    cout<<"Enter Last Name of Student: ";
    cin>>p->lname;
    fflush(stdin);
   // cout<<"Enter discipline of student: ";
  //  cin>>p->discipline;
   // fflush(stdin);
    cout<<"Enter Roll Number of Student: ";
    cin>>p->rollNo;
    fflush(stdin);
    cout<<"Enter Section of Student: ";
    cin>>p->section;
    fflush(stdin);
    cout<<"Enter the Percentage %: ";
    cin>>p->perecentage;
    if(p->perecentage>=90 && p->perecentage<=100)
    {
        p->discipline=("Pre-Medical");
        cout<<"You are registered in ";
        cout<<p->discipline;
	}
	else if (p->perecentage>=80 && p->perecentage<90)
	{
		p->discipline=("Pre-Engineering");
		cout<<"You are registered in ";
		cout<<p->discipline;
	}
	else if (p->perecentage>=70 && p->perecentage<80)
	{
		p->discipline=("ICS");
		cout<<"You are registered in ";
		cout<<p->discipline;
	}
	else if (p->perecentage>=60 && p->perecentage<70)
	{
		p->discipline=("I.Com");
		cout<<"You are registered in ";
		cout<<p->discipline;
	}
	else if (p->perecentage>=50 && p->perecentage<60)
	{
	    p->discipline=("F.A");
		cout<<"You are registered in ";
		cout<<p->discipline;
	}
	else 
	{
		cout<<" Sorry You are not eligible for Admission";
	}
    cout<<endl;
    fflush(stdin);
//	p->next=NULL;

    if(check)
    {
     head = p;
     last = p;
     check = false;
    }
    else
    {
     last->next=p;
     last=p;
    }
    cout<<endl<<"Recored Entered";
    cout<<endl<<"Press Enter Key to Continue";
    getch();
}

void Student::search()   //searches record of student
{
    Node *prev=NULL;
    Node *current=NULL;
    Node *temp;
    int n=1;
    int roll_no;
        
    system("cls");
    cout<<"Enter Roll Number to search: ";
    cin>>roll_no;
     
    prev=head;
    current=head;
    
    if(head == NULL)
    {
        cout<<"List is empty.\n";
        getch();
    }
    else
    {
        while(current->rollNo!=roll_no)
        {
          prev=current;
          current=current->next;
        }
   
    cout<<" First Name: ";
    cout<<current->fname;
    cout<<"\n  Last Name: ";
    cout<<current->lname;
	cout<<"\n    Roll No: ";
    cout<<current->rollNo;
    cout<<"\n    Section: ";
    cout<<current->section;
    cout<<"\nPerecentage: ";
    cout<<current->perecentage<<"%";
    cout<<"\n Discipline: ";
    cout<<current->discipline;
    getch();
    }
}

void Student::studentdisplay()   //Display record of students//
{
	Node * temp;
    int n = 1;

    if(head == NULL)
    {	    
      system("cls");
      cout<<"List is empty.\n";
      getch();
    }
    else
    {
        temp = head;

        while(temp != NULL)
        {    
          system("cls");
	      cout<<"\t\t\t-----------------------------------------\n";
	      cout<<"\t\t\t        Information About Student\n";
	      cout<<"\t\t\t-----------------------------------------\n";
	      cout<<"\n\t\t\tFirst Name of Student: ";
          cout<<temp->fname;
          cout<<"\n\t\t\t Last Name of Student: ";
          cout<<temp->lname;
	      cout<<"\n\t\t\tDiscipline of Student: ";
          cout<<temp->discipline;
          cout<<"\n\t\t\t    Roll # of Student: ";
          cout<<temp->rollNo;
          cout<<"\n\t\t\t   Section of Student: ";
          cout<<temp->section;
          cout<<endl;
	      system("PAUSE");
	      
            /* Move the current pointer to next node */
          temp = temp->next;
          n++;
        }
    }
}

void Student::modify()   //modifies record of student//
{
    Node *p;
    Node *prev=NULL;
    Node *current=NULL;
    int roll_no;
     
    system("cls");
    cout<<"Enter Roll Number to Modifty: ";
    cin>>roll_no;
    prev=head;
    current=head;
    if(head == NULL)
    {
    system("cls");
    cout<<"List is empty.\n";
    getch();
    }
    while(current->rollNo!=roll_no)
    {
     prev=current;
     current=current->next;
    }
    p=new Node();
    fflush(stdin);
    cout<<"Enter First Name of student: ";
    cin>>p->fname;
    fflush(stdin);
    cout<<"Enter Last Name of student: ";
    cin>>p->lname;
    fflush(stdin);
  //cout<<"Enter discipline of student: ";
  //cin>>p->discipline;
  //fflush(stdin);
    cout<<"Enter Roll Number of student: ";
    cin>>p->rollNo;
    fflush(stdin);
    cout<<"Enter section of student: ";
    cin>>p->section;
    fflush(stdin);
 
    prev->next=p;
    p->next=current->next;
    current->next=NULL;
    //delete current;
    cout<<endl<<"Recored Modified";
    getch();
}

void Student::del()    //deletes record of a student//
{
    Node *ptr=NULL;
    Node *prev=NULL;
    Node *current=NULL;
    int roll_no;
     
    system("cls");
    cout<<"Enter Roll Number to Delete: ";
    cin>>roll_no;
    prev=head;
    current=head;
    if(head == NULL)
    {
    system("cls");
    cout<<"List is empty.\n";
    getch();
    }
	while(current->rollNo!=roll_no)
    {
     prev=current;
     current=current->next;
    }
    prev->next = current->next;
    current->next=NULL;
    delete current;
    cout<<endl<<"Recored Deleted";
    getch();
}

void teacher::addteacherdata()   //for teacher data 
{
    Node *p;
    p = new Node;
    system("cls");
    cout<<"Enter First Name of Teacher: ";
    cin>>p->fname;
    fflush(stdin);
    cout<<"Enter Last Name of Teacher: ";
    cin>>p->lname;
    fflush(stdin);
    cout<<"Enter Qualification of Teacher: ";
    cin>>p->qualification;
    fflush(stdin);
    cout<<"Enter Age of Teacher: ";
    cin>>p->age;
    fflush(stdin);
    cout<<"Enter Gender of Teacher: ";
    cin>>p->gender;
    fflush(stdin);
    cout<<"Enter ID of Teacher: ";
    cin>>p->id;
    fflush(stdin);
    
	p->next=NULL;

    if(check)
    {
     head = p;
     last = p;
     check = false;
    }
    else
    {
     last->next=p;
     last=p;
    }
    cout<<endl<<"Recored Entered";
    cout<<endl<<"Press Enter Key to Continue";
    getch();
}

void teacher::tsearch()   //searches record of teacher//
{
	Node *prev=NULL;
    Node *current=NULL;
	Node * temp;
    int n = 1;
    int tid;
    system("cls");
    cout<<"Enter Roll Number to search: ";
    cin>>tid;
       prev=head;
    current=head; 

    if(head == NULL)
    {	    
        system("cls");
        cout<<"List is empty.\n";
        getch();
    }
    else
    {
      // temp = head;

        while(current->id!=tid)
        {
        	prev=current;
            current=current->next;
        }
        
          system("cls");
	      cout<<"\t\t\t-----------------------------------------\n";
	      cout<<"\t\t\t        Information About Teacher\n";
	      cout<<"\t\t\t-----------------------------------------\n";
	      cout<<"\n\t\t\tFirst Name of Teacher: ";
          cout<<current->fname;
          cout<<"\n\t\t\t Last Name of Teacher: ";
          cout<<current->lname;
	      cout<<"\n\t\t     Qualification of Teacher: ";
          cout<<current->qualification;
          cout<<"\n\t\t\t       Age of Teacher: ";
          cout<<current->age;
          cout<<"\n\t\t\t    Gender of Teacher: ";
          cout<<current->gender;
          cout<<"\n\t\t\t        ID of Teacher: ";
          cout<<current->id;
          getch();

            /* Move the current pointer to next node */
          temp = temp->next;
          n++;
    }
}
    
void teacher::teacherdisplay()    //Display record of teacher//
{
	Node * temp;
    int n = 1;

    if(head == NULL)
    {
    	    
        system("cls");
        cout<<"List is empty.\n";
    }
    else
    {
        temp = head;

        while(temp != NULL)
        {
          system("cls");
              
      system("cls");
	      cout<<"\t\t\t-----------------------------------------\n";
	      cout<<"\t\t\t        Information About Teacher\n";
	      cout<<"\t\t\t-----------------------------------------\n";
	      cout<<"\n\t\t\tFirst Name of Teacher: ";
          cout<<temp->fname;
          cout<<"\n\t\t\t Last Name of Teacher: ";
          cout<<temp->lname;
	      cout<<"\n\t\t     Qualification of Teacher: ";
          cout<<temp->qualification;
          cout<<"\n\t\t\t       Age of Teacher: ";
          cout<<temp->age;
          cout<<"\n\t\t\t    Gender of Teacher: ";
          cout<<temp->gender;
          cout<<"\n\t\t\t        ID of Teacher: ";
          cout<<temp->id;
          cout<<endl;
	      system("PAUSE");
	      
            /* Move the current pointer to next node */
          temp = temp->next;
        n++;
		}
    }
}
    
int main() 
{
	Student s;
	teacher t;
	int choice;
	string username;
	string password;
	int loginAttempt = 0;
	
	 cout<<"\t\t\t-----------------------------------------\n";
	 cout<<"\t\t\t        College Management System\n";
	 cout<<"\t\t\t-----------------------------------------\n";
	 cout<<"\n\t\t\tEnter User Name: ";
	 cin>>username;
	 cout<<"\n\t\t\t Enter Password: ";
	 cin>>password;	
	
	 if (username == "admin" && password == "123")
    {
	
	do
    {
    alpha:
	    
    system("cls");
	cout<<"\t\t\t-----------------------------------------\n";
	cout<<"\t\t\t        College Management System\n";
	cout<<"\t\t\t-----------------------------------------\n";
	cout<<"\n\t\t\tEnter <1> Student Management";
	cout<<"\n\t\t\tEnter <2> Faculty Management";
	cout<<"\n\t\t\tEnter <0> to Exit\n";
	cout<<"\n\n\t\t\tEnter Your Choice:";	
    cin >> choice;
    
    if(choice == 1)     //Student Management
    {
    do
	{
    system("cls");
	cout<<"\t\t\t-----------------------------------------\n";
	cout<<"\t\t\t        College Management System\n";
	cout<<"\t\t\t-----------------------------------------\n";
	cout<<"\n\t\t\tEnter <1> to Add new Student";
	cout<<"\n\t\t\tEnter <2> to Search for a particular Student";
	cout<<"\n\t\t\tEnter <3> to Remove for a particular Student";
	cout<<"\n\t\t\tEnter <4> to Edit Student Information";
	cout<<"\n\t\t\tEnter <5> to View All Student";
	cout<<"\n\t\t\tEnter <0> to Back to Main Menu\n";
	cout<<"\n\n\t\t\tEnter Your Choice:";	
    cin >> choice;
    	
    switch (choice)
	{
	case 1:
		system("cls");
    	s.addstudentdata();
		break;	
	case 2:
		system("cls");
    	s.search();
		break;
	case 3:
		system("cls");
    	s.del();
		break;
	case 4:
		system("cls");
    	s.modify();
		break;
	case 5:
		system("cls");
    	s.studentdisplay();
		break;
	case 0:
	    goto alpha;
		break;
	default:
	    {  
		cout << "\nWRONG CHOICE!!!\nTRY AGAIN";
    	}
	 }
    }while(choice != 0);
   }
   
  if(choice == 2)     //Faculty Management
    {
    do
	{	
    system("cls");
	cout<<"\t\t\t-----------------------------------------\n";
	cout<<"\t\t\t        College Management System\n";
	cout<<"\t\t\t-----------------------------------------\n";
	cout<<"\n\t\t\tEnter <1> to Add New Teacher";
	cout<<"\n\t\t\tEnter <2> to Search for a particular Teacher";
	cout<<"\n\t\t\tEnter <3> to View All Teachers";
	cout<<"\n\t\t\tEnter <0> to Back to Main Menu\n";
	cout<<"\n\n\t\t\tEnter Your Choice:";	
    cin >> choice;
    	
    switch (choice)
	{
	case 1:
		system("cls");
    	t.addteacherdata();
		break;
	case 2:
		system("cls");
    	t.tsearch();
		break;
	case 3:
		system("cls");
    	t.teacherdisplay();
		break;
	case 0:
	    goto alpha;
		break;
	default:
	    {  
		cout << "\nWRONG CHOICE!!!\nTRY AGAIN";
    	}
	}

   }while(choice != 0);
  }

 
 }while(choice != 0);
}
else
    {
        cout << "Invalid login attempt. Please try again.\n" << '\n';
        loginAttempt++;
    }
   return 0;
}
