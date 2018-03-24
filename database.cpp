/*
* 
*Database of company profiles to be used for placement purposes.
* 
* It got two view mode [INSTITUTE] and [COMPANY]
* There is ADMIN and GUEST user access.
* Using a authorizied code ADMIN can delete record if needed
* 
*
*---------------------------------CLASS STRUCTURE-------------------------------------
*        Company--------(friend)----------> Institute
*       
*  
*/


#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include<Windows.h>
#include<dos.h>
using namespace std;



void setcolor(unsigned short color)  //manage interface color
{
    HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}


class company;
class institute;
std::vector<institute> v1;
std::vector<company> v2;



class users
{
    public: virtual void add_record_institute();
            virtual void delete_record_institute(string,string);
            virtual void read_file_institute();
            virtual void write_file_institute();
            virtual void search_record_institute(string);
            virtual void view_record_institute();
            virtual void add_record_company();
            virtual void delete_record_company(string,string);
            virtual void read_file_company();
            virtual void write_file_company();
            virtual void search_record_company(string);
            virtual void view_record_company();

            users(){}
};




class guest : public users
{
    protected: int choice;
               string e;

    public: friend void view_record_institute();
            friend void search_record_institute(string);
            friend void view_record_company();
            friend void search_record_company(string);
            guest(char type)
            {

                if(type=='I')
                {
                    q:
                    cout<<"\n\nPress (1) to view existing records"<<endl;
                    cout<<"Press (2) to search an existing record"<<endl;
                    cout<<"Press (3) to exit"<<endl;
                    cin>>choice;
                    //system("clear");

                    switch(choice)
                    {
                        case 1: view_record_institute();
                                break;

                        case 2: cout<<"Enter company code to search: ";
                                cin>>e;
                                search_record_institute(e);
                                break;
                        case 3: exit(0);
                                break;
                        default: cout<<"Wrong Input.";
                                 goto q;
                    }
                }
                else if(type=='C')
                {
                    y:
                    cout<<"\n\nPress (1) to view existing records"<<endl;
                    cout<<"Press (2) to search an existing record"<<endl;
                    cout<<"Press (3) to exit"<<endl;
                    cin>>choice;
                    //system("clear");

                    switch(choice)
                    {
                        case 1: view_record_company();
                                break;

                        case 2: cout<<"\t\t\t\t\t######::: Enter Company code to search: ";
                                cin>>e;
                                search_record_company(e);
                                break;
                        case 3: exit(0);
                                break;
                        default: cout<<"\t\t\t\t\t~~ Wrong Input.";
                                 goto y;
                    }
                }
            }
};




class admin : public users
{
    protected: int choice;
               string e;
               string f;

    public: friend void add_record_institute();
            friend void delete_record_institute(string);
            friend void read_file_institute();
            friend void write_file_institute();
            friend void search_record_institute(string);
            friend void view_record_institute();
            friend void add_record_company();
            friend void delete_record_company(string);
            friend void read_file_company();
            friend void write_file_company();
            friend void search_record_company(string);
            friend void view_record_company();
            friend void split(const std::string &s, std::vector<std::string> &elems,char);

            admin(char type)
            {
                if(type=='I')
                {
                    system("cls");
                    z:
                    cout<<"\n\n\n"<<endl;
                    cout<<"\n\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
                    cout<<"\t\t\t\t\tPress (1) to add a new record"<<endl;
                    cout<<"\t\t\t\t\tPress (2) to search an existing record"<<endl;
                    cout<<"\t\t\t\t\tPress (3) to view existing records"<<endl;
                    cout<<"\t\t\t\t\tPress (4) to delete an existing record"<<endl;
                    cout<<"\t\t\t\t\tPress (5) to exit\n\n\t\t\t\t->";
                    cin>>choice;
                    // system("cls");

                    switch(choice)
                    {
                        case 1: system("cls");
                                add_record_institute();
                                //system("cls");
                                break;
                        case 2: system("cls");
                                cout<<"\n\n\n\t\t\t\t\t\t######:: Enter company code to search  : ";
                                cin>>e;
                                search_record_institute(e);
                                break;

                        case 3: system("cls");
                                cout<<"\n\n\n\t\t\t";
                                view_record_institute();
                                break;

                        case 4: system("cls");
                                cout<<"\n\n\n";
                                cout<<"\t\t\t\t\t\t######:: Enter company code to delete record   : ";
                                cin>>e;
                                f="ok";
                                delete_record_institute(e,f);
                                break;
                        case 5: exit(0);

                        default: cout<<"\t\t\t\t\tWrong Input."<<endl;
                                 goto z;
                    }
                }
                else if(type=='C')
                {
                    system("cls");
                    x:
                    cout<<"\n\n\n"<<endl;
                    cout<<"\n\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
                    cout<<"\t\t\t\t\tPress (1) to add a new record"<<endl;
                    cout<<"\t\t\t\t\tPress (2) to search an existing record"<<endl;
                    cout<<"\t\t\t\t\tPress (3) to view existing records"<<endl;
                    cout<<"\t\t\t\t\tPress (4) to delete an existing record"<<endl;
                    cout<<"\t\t\t\t\tPress (5) to exit\n\n\t\t\t\t->";
                    cin>>choice;
                    // system("cls");

                    switch(choice)
                    {
                        case 1: add_record_company();
                                //system("cls");
                                break;
                        case 2: system("cls");
                                cout<<"\n\n\n\n\n\t\t\t#####:: Enter company name to search: ";
                                cin>>e;
                                system("cls");
                                search_record_company(e);
                                break;

                        case 3: view_record_company();
                                break;

                        case 4: system("cls");
                                cout<<"\n\n\n\n\n";
                                cout<<"\t\t\t\t\t\t#####:: Enter company code to delete record: ";
                                cin>>e;
                                f="ok";
                                delete_record_company(e,f);
                                break;
                        case 5: exit(0);

                        default: cout<<"Wrong Input."<<endl;
                                 goto x;
                    }
                }
            }
};





class company
{

    friend class institute;

    public: string company_code, company_name, contact_no, salary, domain, address;


    public:
        void add()
        {
            int i;
            system("cls");
            cout<<"\n\n\n\n\n\n\n";
            cout<<"\t\t\t**************************************************************************************************************\n";
            cout<<"\t\t\t--------------------------------------------------------------------------------------------------------------\n";
            cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------------\n";
            cout<<"\t\t\t\t\t\t>> Add company code  :          ";
            cin>>company_code;
            cout<<"\t\t\t\t\t\t>> Add company name  :          ";
            cin.ignore(1000,'\n');
            getline(cin, company_name);
            cout<<"\t\t\t\t\t\t>> Add contact number:          ";
            cin>>contact_no;
                if(isalpha(contact_no[i]))
                {
                    cout<<"\t\t\t\tInvlid input try again"<<endl;
                    exit(0);
                }
            cout<<"\t\t\t\t\t\t>> Add Head Office   :          ";
            cin.ignore(1000,'\n');
            getline(cin, address);
            cout<<"\t\t\t\t\t\t>> Add salary        :          ";
            cin>>salary;
            if(isalpha(salary[0]))
            {
                cout<<"\t\t\t\tInvlid input try again"<<endl;
                exit(0);
            }
            cout<<"\t\t\t\t\t\t>> Add Domain        :          ";
            cin.ignore(1000,'\n');
            getline(cin, domain);
            cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"\n\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;

            cout<<"\n\n\t\t\t\t\t~PRESS ANY KEY TO CONTINUE~"<<endl;
            getch();            
            system("cls");
        }

        void show()
        {
            cout<<"\n\n\t\t\t";
            setcolor(10);
            cout<<"------------------------------------------------------------------------------------------------------------\n"<<endl;setcolor(6);
            cout<<"\t\t\t\t\t\tCompany Code: ";setcolor(10);cout<<company_code;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tCompany Name: ";setcolor(10);cout<<company_name;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tContact Number: ";setcolor(10);cout<<contact_no;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tHead Office: ";setcolor(10);cout<<address;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tSalaray in Lakhs: ";setcolor(10);cout<<salary;
            setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tDetails: ";setcolor(10);cout<<domain;setcolor(6);cout<<endl;
            
        }

        void acceptData(vector<string> &v)
        {
            company_code=v[0];
            company_name=v[1];
            contact_no=v[2];
            address=v[3];
            salary=v[4];
            domain=v[5];
        }

        void write(ofstream &x)
        {
            x<<company_code<<','<<company_name<<','<<contact_no<<','<<address<<','<<salary<<','<<domain<<endl;
        }

        friend void read_file_company();
        friend void write_file_company();
        friend void search_record_company(string);
        friend void delete_record_company(string);
        friend void add_record_company();
        friend void view_record_company();
}obc;




class institute
{
    friend class company; // now institute class has access to all members and attr. of company class

    public: string company_code, company_name, contact_no, salary, domain, address, branch, grade, no_student, det;

    public:
        void add()
        {
            /*ifstream Reader ("banner.txt");             //Open file
            string getFileContents(ifstream&);
            string Art = getFileContents (Reader);       //Get file
    
            cout << Art << endl;              //Print it to the screen

            Reader.close ();*/

            cout<<"\n\n\n\n\n\n\n";
            cout<<"\t\t\t**************************************************************************************************************\n";
            cout<<"\t\t\t--------------------------------------------------------------------------------------------------------------\n";
            cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------------\n\n";
            cout<<"\t\t\t\t\t\t>> Add company code  :          ";
            cin>>company_code;
            cout<<"\t\t\t\t\t\t>> Add company name  :          ";
            cin.ignore(1000,'\n');
            getline(cin, company_name);
            cout<<"\t\t\t\t\t\t>> Add contact number:          ";
            cin>>contact_no;
            if(isalpha(contact_no[0]))
            {
                cout<<"\t\t\t     Invlid input try again"<<endl;
                exit(0);
            }
            cout<<"\t\t\t\t\t\t>> Add Address   :          ";
            cin.ignore(1000,'\n');
            getline(cin, address);
            cout<<"\t\t\t\t\t\t>> Add salary        :          ";
            cin>>salary;
            if(isalpha(salary[0]))
            {
                cout<<"\t\t\t     Invlid input try again"<<endl;
                exit(0);
            }
            cout<<"\t\t\t\t\t\t>> Add domains and technology:  ";
            cin.ignore(1000,'\n');
            getline(cin, domain);
            cout<<"\t\t\t\t\t\t>> Required Branches         :  ";
            cin>>branch;
            cout<<"\t\t\t\t\t\t>> Input grade criteria      :  ";
            cin>>grade;
            cout<<"\t\t\t\t\t\t>> Placement intake          :  ";
            cin>>no_student;
            cout<<"\t\t\t\t\t\t>> Company Details           :  ";
            cin.ignore(1000,'\n');
            getline(cin, det);
            cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"\n\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;

            setcolor(96);
            cout<<"\n\n\t\t\t\t\t~PRESS ANY KEY TO CONTINUE~"<<endl;
            setcolor(6);
            getch();            
            system("cls");
        }
        void show()
        {

            cout<<"\n\n\t\t\t";
            setcolor(10);
            cout<<"------------------------------------------------------------------------------------------------------------\n"<<endl;setcolor(6);
            cout<<"\t\t\t\t\t\tInstitute name: ";setcolor(10);cout<<company_code;setcolor(6);
            cout<<'\n'<<"\t\t\t\t\t\tCompany Name: ";setcolor(10);cout<<company_name;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tContact Number: ";setcolor(10);cout<<contact_no;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tAddress: ";setcolor(10);cout<<address;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tSalary in Lakhs: ";setcolor(10);cout<<salary;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tDomains and technology: ";setcolor(10);cout<<domain;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tEligible Branches: ";setcolor(10);cout<<branch;setcolor(6);
            cout<<'\n'<<"\t\t\t\t\t\tGrade criteria :";setcolor(10);cout<<grade;setcolor(6);cout<<'\n'<<"\t\t\t\t\t\tPlacement Intake :";setcolor(10);cout<<no_student;setcolor(6);cout<<endl;cout<<'\n'<<"\t\t\t\t\t\tCompany Details :";setcolor(10);cout<<det;setcolor(6);cout<<endl;
        }
        void acceptData(vector<string> &v)
        {
            
            company_code=v[0];
            company_name=v[1];
            contact_no=v[2];
            address=v[3];
            salary=v[4];
            domain=v[5];
            //cout<<v.size()<<endl;
            string n1 = "ok";
            //v.push_back(n1);
            branch=v[6];
            //v.push_back(n1);
            grade=v[7];
            //v.push_back(n1);
            no_student=v[8];
            //cout<<v.size()<<endl;
            v.push_back(n1);
            det=v[9];
        }
        void write(ofstream &x)
        {
            x<<company_code<<','<<company_name<<','<<contact_no<<','<<address<<','<<salary<<','<<domain<<','<<branch<<','<<grade<<','<<no_student<<','<<det<<endl;
        }
        friend void read_file_company();
        friend void write_file_company();
        friend void search_record_company(string);
        friend void delete_record_company(string);
        friend void add_record_company();
        friend void view_record_company();
// a global object of the class created right outside
}obi;




//--------------------------------------------------------------------------

/*
*makes a generic class which can be used to process
*any kind of data in the split function
*/
template<class Out>
void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}


void split(const std::string &s, std::vector<std::string> &elems,char delim)
{
    split(s, delim, std::back_inserter(elems));
}


//
void users :: read_file_institute()
{
    ifstream x("institute.csv");
    char z[100];                // array to extract a single line from the csv file

    while(x.getline(z,100))     // csv data of one record
    {
        string s;

        for(int i=0;z[i]!='\0';i++)
            s.push_back(z[i]);  // push back macro

        std::vector<string> v;
        split(s,v,',');
        obi.acceptData(v);      //this vector contains all the memnber variables of the class institute.
        v1.push_back(obi);
    }

    x.close();

// Read all the remaining files in the same manner. Inside ifstream, change File name. Define acceptData in other classes which you want to read from the file, and send this vector to initialize.
}



void users :: write_file_institute()
{
    ofstream x("institute.csv");

    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        (*itr).write(x);
    }

    x.close();
}


void users :: add_record_institute()
{
    obi.add();
    v1.push_back(obi);
    write_file_institute();
}


void users :: delete_record_institute(string e, string f)
{
    int c = 0,flag=0;
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++, c++)
    {
        if((*itr).company_code == e )//&& (*itr).company_name == f)
        {
            flag = 1;
            v1.erase(v1.begin()+c);
            write_file_institute();
            cout<<"\n\t\t\t\tDELETED"<<endl;
            getch();
            view_record_institute();
            break;
        }
        /*else
            cout<<"not found"<<endl;*/
    }
    if(flag == 0)
        cout<<"\t\t\t\t\tNo such Institute found."<<endl;
}


void users :: search_record_institute(string e)
{
    int flag = 0;
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        if((*itr).company_code == e)
        {
            flag = 1;
            (*itr).show();
        }
    }
    if(flag == 0)
        cout<<"\t\t\t\t\tNo such Institute found."<<endl;
    getch();
    system("cls");
}


void users :: view_record_institute()
{
    system("cls");
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        (*itr).show();
    }
    cout<<"\n\n\t\t\t";setcolor(96);cout<<"~PRESS ANY KEY TO CONTINUE~"<<endl;
    setcolor(6);
    getch();
    system("cls");
}



void users :: read_file_company()
{
    ifstream x("company.csv");
    char z[100]; // array

    while(x.getline(z,100)) // csv data of one record
    {
        string s;

        for(int i=0;z[i]!='\0';i++){
            s.push_back(z[i]);
            
        }
         /*std::vector<string> v;
        split(s,v,',');
        obi.acceptData(v);      //this vector contains all the memnber variables of the class institute.
        v1.push_back(obi);*/// push back macro

        std::vector<string> v;
        split(s,v,',');
        obc.acceptData(v);//this vector contains all the memnber variables of the class institute.
        v2.push_back(obc);
    }
    
    x.close();


// Read all the remaining files in the same manner. Inside ifstream, change File name. Define acceptData in other classes which you want to read from the file, and send this vector to initialize.
}


void users :: write_file_company()
{
    ofstream x("company.csv");

    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++)
    {
        (*itr).write(x);
    }

    x.close();
}


void users :: add_record_company()
{
    obc.add();
    v2.push_back(obc);
    write_file_company();
}


void users :: delete_record_company(string e,string f)
{
    int c = 0,flag = 0;
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++, c++)
    {
        if((*itr).company_code == e )//&& (*itr).company_code == f)
        {
            flag = 1;
            v2.erase(v2.begin()+c);
            write_file_company();

            cout<<"\n\t\t\t\t";setcolor(12);cout<<"DELETED"<<endl;setcolor(6);
            getch();
            view_record_company();
            break;
        }
    }
    if(flag == 0)
        cout<<"\n\t\t\t\tNo such company found."<<endl;
    getch();
    system("cls");
}


void users :: search_record_company(string e)
{
    int flag=0;
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++)
    {
        if((*itr).company_code == e)
        {
            flag = 1;
            (*itr).show();
        }
    }
    if(flag==0){        
        cout<<"\t\t\t\t";setcolor(12);cout<<"No such company found."<<endl;setcolor(6);}
    getch();
    system("cls");
}


void users :: view_record_company()
{
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++)
    {
        (*itr).show();
    }
    cout<<"\n\n\t\t\t";setcolor(96);cout<<"~PRESS ANY KEY TO CONTINUE~"<<endl;
    setcolor(6);
    getch();
    system("cls");
}


// driver function to run the program
int main()
{
    system("cls");

    //system("COLOR F1");
    string s1,s2;
    char choice;
    char class_choice;
    users u;
    u.read_file_institute();
    u.write_file_institute();
    u.read_file_company();
    u.write_file_company();

    //cout<<"ok"<<endl;
    l:
    setcolor(240);
    system("cls");//_______________________________________________________
   
    cout<<"\n\n\n\n\n\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>";setcolor(15);cout<<"   VIEW MODE   ";setcolor(240);cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>              Press => ";setcolor(124);cout<<"[I]";setcolor(240);cout<<" to View institute's data.            <<"<<endl;
    cout<<"\t\t\t\t\t\t>>              Press => ";setcolor(124);cout<<"[C]";setcolor(240);cout<<"to View company's data.               <<"<<endl;
    cout<<"\t\t\t\t\t\t>>              To exit press ";setcolor(121);cout<<"any";setcolor(240);cout<<" key                             <<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>                                                                <<"<<endl;
    cout<<"\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n\t\t\t\t\t\t\t\t->";
    cin>>class_choice;
    if(class_choice!='I' && class_choice!='C')
        exit(0);
    system("cls");//________________________________________________
    while(1)
    {
        
        //system("COLOR 06");
        setcolor(6);
        cout<<"\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"\t\t\t\t\t\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
        cout<<"\t\t\t\t\t\t;;                                                         ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;                                                         ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;                                                         ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;           To login as admin press ";setcolor(224);cout<<"A";setcolor(6);cout<<".                    ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;           To login as a guest press ";setcolor(224);cout<<"G";setcolor(6);cout<<".                  ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;           To Change interface press ";setcolor(224);cout<<"C";setcolor(6);cout<<".                  ;;\n";
        cout<<"\t\t\t\t\t\t;;           To exit press ";setcolor(10);cout<<"any";setcolor(6);cout<<" key                         ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;                                                         ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;                                                         ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;                                                         ;;"<<endl;
        cout<<"\t\t\t\t\t\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
        cout<<"\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"\n\t\t\t\t\t\t                         ->";
        cin>>choice;
        
        //system("cls");
        if(choice =='A' || choice == 'a')
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n";

            cout<<"\t\t\t\t\t";
            setcolor(96);cout<<"#######:: Enter authorization code: ";
            cin>>s1;
            setcolor(6);
            //cout<<"Enter password: ";
            //cin>>s2;
            if(s1 == "bifrost" )//&& s2 == "password")
                admin a(class_choice);
            else if(s1 != "bifrost")// && s2 == "password")
            {
                setcolor(12);
                cout<<"\n\n\t\t\t\t\t\tWrong authorization code."<<endl;
                setcolor(6);
                cout<<"\n\n\n\t\t\t\tpress any key to try again"<<endl;
                getch();
                system("cls");
                continue;
            }
            /*else if(s1 == "admin" && s2 != "password")
            {
                cout<<"Wrong password."<<endl;
                cout<<"\n\n\npress any key to try again"<<endl;
                getch();
                continue;
            }
            else if(s1 != "admin" && s2 != "password")
            {
                cout<<"Wrong username and password."<<endl;
                cout<<"\n\n\npress any key to try again"<<endl;
                getch();
                continue;
            }*/
            //cout<<"ok"<<endl;
            //system("cls");
        }
        else if(choice == 'G' || choice == 'g')
            guest g(class_choice);
        else if(choice == 'C' || choice == 'c')
            goto l;
        else
            exit(0);
    }

    return 0;
}
