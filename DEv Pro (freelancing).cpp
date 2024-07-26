#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
//class project
class project{
	private:
		string name;
		int duration;
		string status;
		int id;
		int cost;
	public:
		project *next = NULL;
		friend class Developer;
};

//class Developer
class Developer{
	private:
		int Dev_ID;
		string Dev_Name;
		string Dev_Speciality;
		int Dev_Project_Count=0;
		project *head = NULL;
		project *tail = NULL;
	public: 
		Developer *next = NULL;
 		Developer *prev	= NULL;
 		friend class DevProj;
		void add_Project(Developer* Devtemp){
		int in;
		project* new_project = new project;
		project* temp = head; 
		if(head == NULL)		
		{
			head = new_project;
			tail = new_project;
//			tail->next = head;
		}
		else // else new node will be added to next node
		{
			new_project->next = head;
			tail->next = new_project;
			head = new_project;
		}
			
		cout<<"\nName : ";
		cin.ignore();
		getline(cin,new_project->name);
		cout<<"Duration : ";
		cin>>new_project->duration;
		cout<<"ID : ";
		cin>>new_project->id;
		cout<<"Cost : ";
		cin>>new_project->cost;
		cout<<"Status ([1] Completed [2] IN Progress [3] Canceled : ";
		cin>>in;
		switch(in)
		{
			case 1:
				new_project->status = "Completed";
			break;
			case 2: 
				new_project->status = "IN Progress";
			break;
			case 3: 
				new_project->status = "Canceled";
			break;
			default:
				cout<<"---Wrong Input---";
			break;
		}

		Devtemp->Dev_Project_Count++;
		}
		// printing the projects of a developer
		void print_Projects(){
		project* tmpPro = head; 
		if (tmpPro != NULL)
		{
			do
			{
				cout<<"\tNAME 	    : "<<tmpPro->name<<endl;
				cout<<"\tID		    : "<<tmpPro->id<<endl;
				cout<<"\tSTATUS     : "<<tmpPro->status<<endl;
				cout<<"\tCOST 	    : "<<tmpPro->cost<<"$"<<endl;
				cout<<"\tDURATION   : "<<tmpPro->duration<<" MONTHS"<<endl;
				tmpPro = tmpPro->next;
			}while(tmpPro != head);   
		}
		}
		// printing spacific project of developer 
		void print_spacific_Project(int p_id){
		project* tmpPro = head;
		if (tmpPro != NULL)
		{
			do // this loop is traversing the project circular linked list of project 
			{
				if(tmpPro->id == p_id)
				{
	
					cout<<"\tNAME 	    : "<<tmpPro->name<<endl;
					cout<<"\tID		    : "<<tmpPro->id<<endl;
					cout<<"\tSTATUS     : "<<tmpPro->status<<endl;
					cout<<"\tCOST 	    : "<<tmpPro->cost<<"$"<<endl;
					cout<<"\tDURATION   : "<<tmpPro->duration<<" MONTHS"<<endl;
				}
				
				tmpPro = tmpPro->next; // treversing the pointer
			} while (tmpPro != head);   // condition checking
		}
		}
		// printing the next project
		void show_next_Porject(){
		project* tmpPro = head;
		if (tmpPro != NULL) // condition 
		{
			
					cout<<"\tNAME 	    : "<<tmpPro->name<<endl;
					cout<<"\tID		    : "<<tmpPro->id<<endl;
					cout<<"\tSTATUS     : "<<tmpPro->status<<endl;
					cout<<"\tCOST 	    : "<<tmpPro->cost<<"$"<<endl;
					cout<<"\tDURATION   : "<<tmpPro->duration<<" MONTHS"<<endl;
					tmpPro = tmpPro->next; // treversiong 
		}
		}


};
//DevProj class
class DevProj{	
	public:
	// data of developers and funtion's to perform 
	Developer pro_of_dev;
	Developer * head = NULL;
	void getDeveloper(); // creating or adding node
	void get_val_at_head(); // adding node at head
	void search_developer(int s_id); // searching for developer 
	void Dev_All_display(); // displaying the all developer's data
	void add_pro_to_dev(int s_id); // adding project to developer 
	void Display_Project(int s_id,int p_id); // displaying projecting of developer
	Developer* show_Prev_Developer(Developer *temp); // printing next developer
	Developer* show_Next_Developer(Developer *temp); // pinting previous developer
	void show_next(int s_id); // printing next project for developer.
	
	// this function  return the value head value of developer
	Developer* gethead(){
		return head;
	}

};

// printing next developer
Developer* DevProj::show_Next_Developer(Developer *temp){
	if (temp!= NULL){ // condition for null
		temp = temp->next; // treversing  the next developer 
	cout<<"\n\t----------------------------------------\n";
	cout<<"\n";
	cout<<"\tDEVELOPER NAME   : "<<temp->Dev_Name<<endl;
	cout<<"\tID     		 : "<<temp->Dev_ID<<endl;
	cout<<"\tSpeciality  	 : "<<temp->Dev_Speciality<<endl;
	cout<<"\tNO of Projects   : "<<temp->Dev_Project_Count<<endl;
	temp= temp->next;
	cout<<"\n\n\t----------------------------------------\n\n";
	return temp;
	}
	else
	{
		cout<<"NO More Developers : "<<endl;
	}
}

// printing previous developer 
Developer* DevProj::show_Prev_Developer(Developer *temp){
	if (temp != NULL){ // condition for null
		temp = temp->prev; // treversing the previous developer 
	cout<<"\n\t----------------------------------------\n";
	cout<<"\n";
	cout<<"\tDEVELOPER NAME   : "<<temp->Dev_Name<<endl;
	cout<<"\tID     		 : "<<temp->Dev_ID<<endl;
	cout<<"\tSpeciality  	 : "<<temp->Dev_Speciality<<endl;
	cout<<"\tNO of Projects   : "<<temp->Dev_Project_Count<<endl;
	cout<<"\n\n\t----------------------------------------\n\n";
	return temp; // returning the pointer to store the position.
	}
	else
	{
		cout<<"\t NO More Developers : "<<endl;
	}
}

// adding project to developer 
void DevProj::add_pro_to_dev(int s_id){
	project* new_project = new project();   // adding new project
	Developer* temp = head; // pointer to developers
		while(temp!= NULL)
		{
			if(temp->Dev_ID == s_id) // chekcing condition 
			{
				int num_pro;
				cout<<"How Many Project to Add : ";
				cin>>num_pro;
				for(int i=0; i<num_pro; i++)
				{
					pro_of_dev.add_Project(temp);  // calling funcion of adding project in developer class 
				}
			}
			temp = temp->next; // treversing 
		}

}

// creating or adding the node of developer 
void DevProj::getDeveloper()
{
	int in;
	Developer * new_developer  = new Developer;  // new node 
	Developer *temp = head;  // temp pointer of head value 
	if(head == NULL)
	{
		get_val_at_head();    // calling the add to head function if no nodes are their 
		return ;	
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	// adding node to the double linked list
	temp->next = new_developer ;
	new_developer->prev = temp ;
	
	// getting data;
	cout<<"\nName : ";
	cin.ignore();
	getline(cin,new_developer->Dev_Name);
	cout<<"ID : ";
	cin>>new_developer->Dev_ID;
	cout<<"Developer Speciality : \n";
	cout<<"([1] WEB [2] MOBILE [3] DESKTOP : => ";
	cin>>in;
	switch(in)
	{
		case 1:
			new_developer->Dev_Speciality = "WEB";
			break;
		case 2: 
			new_developer->Dev_Speciality = "MOBILE";
			break;
		case 3: 
			new_developer->Dev_Speciality = "DESKTOP";
			break;
		default:
			cout<<"---Wrong Input---";
			break;
	}
	temp =  new_developer ;
	system("cls");
	
}

// adding value at the head 
void DevProj::get_val_at_head()
{
		Developer * new_developer  = new Developer; // new node 
		new_developer->next = head ; // pointer of developer with value head
		if ( head != NULL)
		{
			head->prev =new_developer; // adding head's previous to new_developer
		}
		head = new_developer ;   // giving head to the new developer
		
	// geting data 
	int in;
	cout<<"\nName : ";
	cin.ignore();
	getline(cin,new_developer->Dev_Name);
	cout<<"ID : ";
	cin>>new_developer->Dev_ID;
	cout<<"Developer Speciality : \n";
	cout<<"([1] WEB [2] MOBILE [3] DESKTOP : => ";
	cin>>in;
	switch(in)
	{
		case 1:
			new_developer->Dev_Speciality = "WEB";
			break;
		case 2: 
			new_developer->Dev_Speciality = "MOBILE";
			break;
		case 3: 
			new_developer->Dev_Speciality = "DESKTOP";
			break;
		default:
			cout<<"---Wrong Input---";
			break;
	}
	system("cls");
	
} 

// searching for spacific developer
void DevProj::search_developer(int s_id)
{
	Developer *temp = head;  // head pointer 
	int count = 0 ;
	
	if(temp == NULL) // condition to check the NULL 
	{
		cout<<"	Empty Linked List "<<endl;
	}
	else if (temp != NULL)
	{
	while (temp != NULL) // looping for searching the developer
	{
		if(temp->Dev_ID == s_id)  // condition for checking the ids of the developer
		{ 				
			cout<<"\n";
			cout<<"\tDEVELOPER NAME   : "<<temp->Dev_Name<<endl;
			cout<<"\tID     		  : "<<temp->Dev_ID<<endl;
			cout<<"\tSpeciality  	  : "<<temp->Dev_Speciality<<endl;
			cout<<"\tNO of Projects   : "<<temp->Dev_Project_Count<<endl; 
				
		}
		temp = temp->next; // treversing 
	}	
	}
	else
	{
		cout<<" NOt found ! ";
	}				 
}		

// displaying the all developer 
void DevProj::Dev_All_display()
{
	Developer * temp = head ;  // head pointer
	
	while(temp != NULL)  // looping for printing data 
	{
	cout<<"\n";
	cout<<"\tDEVELOPER NAME : "<<temp->Dev_Name<<endl;
	cout<<"\tID     		  : "<<temp->Dev_ID<<endl;
	cout<<"\tSpeciality  	  : "<<temp->Dev_Speciality<<endl;
	cout<<"\tNO of Projects : "<<temp->Dev_Project_Count<<endl; 

	temp= temp->next; // treversing 
	}
		
}

// function for printing the developer's projects 
void DevProj::Display_Project(int s_id,int p_id)
{
	Developer *temp = head; // developer 's head node 
	while (temp!= NULL) // looping in developer linked list 
	{
		if(temp->Dev_ID == s_id) // condition checking of IDs 
		{ 
			cout<<"\tDeveloper Found : "<<endl;
			cout<<"\n\tName 		 : "<<temp->Dev_Name<<endl;
			pro_of_dev.print_spacific_Project(p_id); // calling the function for  pinting spacific project 
		}
		temp = temp->next; // treversing 
	}	
	
}

// printing the  next project of a developer
void DevProj::show_next(int s_id)
{
		Developer *temp = head; // head pointer 
		int count = 0 ;
		
		if(temp == NULL)
		{
		cout<<"	Empty Linked List "<<endl;
			}
		else if (temp != NULL)
		{
		while (temp!= NULL)
		{
					if(temp->Dev_ID == s_id)
				{ 
					
				 	pro_of_dev.show_next_Porject(); // calling the function of showing next project 
				}
				temp = temp->next;
	}	
	}
	else
	{
		cout<<" NOt found ! ";
	}				 
	
}

// command and control [0_O]-/

void commands(DevProj Dev_list, Developer* Dev)
{
	char option;
	int s_id,p_id;
	do{
	cout<<"\tD => Add a developer"<<endl;
	cout<<"\tP => Add a project"<<endl;
	cout<<"\tS => Search for a developer"<<endl;
	cout<<"\tT => Search for a project"<<endl;
	cout<<"\tV => View developers"<<endl;
	cout<<"\tF => Show next developer"<<endl;
	cout<<"\tR => Show previous developer"<<endl;
	cout<<"\tN => Show next project"<<endl;
	cout<<"\tE => Exit"<<endl;
	here:
	cout<<"\n\n\tPlease choose a command: ";	
	cin>>option;
	Developer* temp = Dev_list.gethead();
	switch(option)
	{
		case 'D':
		case 'd':
			system("cls");
			Dev_list.getDeveloper();
			break;
		case 'P':
		case 'p':
			system("cls");
			cout<<"	Enter Developer Id : ";
			cin>>s_id;
			Dev_list.add_pro_to_dev(s_id);
			break;
		case 'S':
		case 's':
			system("cls");
			cout<<"	Enter Developer Id : ";
			cin>>s_id;
			Dev_list.search_developer(s_id);
			break;
		case 'T':
		case 't':
			system("cls");
			cout<<"	Enter Developer Id : ";
			cin>>s_id;
			cout<<" Enter Project ID : ";
			cin>>p_id;
			Dev_list.Display_Project(s_id,p_id);
			break;
		case 'V':
		case 'v':
			system("cls");
			Dev_list.Dev_All_display();
			break;
		case 'F':
		case 'f':
			system("cls");
			temp = Dev_list.show_Next_Developer(temp);
			break;
		case 'R':
		case 'r':
			system("cls");
			Dev_list.show_Prev_Developer(temp);
			break;
		case 'N':
		case 'n':
			system("cls");
			cout<<"DEVELOPER ID : ";
			cin>>s_id;
			Dev_list.show_next(s_id);
			break;
		case 'E':
		case 'e':
			cout<<"\n";
			cout<<"Thanks for using...:)";
			exit(0);
			break;
		default: 
			cout <<"<--Wrong Input -->"<<endl;
			goto here;
	}
	}while(option!='e'||option!='E');
	
}
void firstScreen(){
	system ("color 9F");
	cout<<"\n\n\n\n";
	cout<<"\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
	cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
	cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
	cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
	cin.get();
	system("cls");
}
void intro()   //function for intro page
{
	system ("color 9F");
	cout<<"\n\n\n\t\tDEV PROJECT";
	cout<<"\n\n\t\tFREELANCING ";
	cout<<"\n\n\t\t  SYSTEM";
	cout<<"\n\n\n\tMADE BY : MUHAMMAD TALHA - SHAJIA QAMAR - WAHAJ BUKHARI"<<endl;
	cout<<"\n\tUNIVERSITY : AIR UNIVERSITY,ISLAMABAD\n"<<endl;
	cout<<"Click enter to proceed......";
	cin.get();
	system("cls");
}
int main()
{
	intro();
	firstScreen();
	DevProj Dev_list; // object of DEVproj Class
	Developer *Dev;  // pointer of Developer class 
	commands(Dev_list,Dev); // calling the command funtion 
	return 0;
	
	
}

