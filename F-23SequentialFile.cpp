/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data
*/
#include<iostream>
#include<fstream>

#define MAX 10
using namespace std;

class student
{
    int roll_no;
    string name,address;
    char div;
    fstream f;
    public:
    void setdata()
    {
        cout<<"Enter Roll No. of students:"<<endl;
        cin>>roll_no;
        cout<<"Enter Student Name :"<<endl;
        cin>>name;
        cout<<"Enter Student Division :"<<endl;
        cin>>div;
        cout<<"Enter Student Address :"<<endl;
        cin>>address;
    }  
    void getdata()
    {
        cout<<"Roll No.- "<<roll_no<<endl;
        cout<<"Student Name - "<<name<<endl;
        cout<<"Division - "<<div<<endl;
        cout<<"Address - "<<address<<endl;
    } 
    int getroll_no()
    {
        return roll_no;
    }

};

class SQfile
{
    public:
    fstream f;
    student s;
    SQfile()
    {
        f.open("Student.txt");
    }
    void insertRecord()
    {
        
        s.setdata();
        f.seekp(0,ios::end);
        f.write((char*)&s,sizeof(student));
        f.clear();
    }
    void displayAll()
    {
        f.seekg(0,ios::beg);
        while(f.read((char*)&s,sizeof(student)))
        {
            s.getdata();
        }
    }
    
    void displayRecord(int roll_no)
    {
    f.seekg(0, ios::beg);
    bool flag = false;
    while (f.read((char*)&s, sizeof(student)))
    {
        if (s.getroll_no() == roll_no)
        {
            s.getdata();
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Data of Roll no. is not present." << endl;
    }
    f.clear();
}


    void deletRecord(int roll_no)
    {
        ofstream of("New.txt",ios::binary);
        f.seekg(0,ios::beg);
        bool flag=false;
         while(f.read((char*)&s,sizeof(student)));
        {
            if(s.getroll_no()==roll_no)
            {
                flag=true;
            }
            of.write((char*)&s,sizeof(student));
        }
        if (!flag)
        {
           cout<<"Data of Roll no. is not present."<<endl;
        }
        f.close();
        of.close();
        remove("Student.txt");
        rename("New.txt","Student.txt");
        f.open("Student.txt");
    }
    ~SQfile()
    {
        f.close();
        cout<<"File Closed."<<endl;
    }
};
int main()
{
    ofstream f("Student.txt");
  	f.close();
  	SQfile of;
    int rollNo,year,ch=0;
    char div;
    char name[MAX],address[MAX];
    while(ch!=5)
    {
		cout<<"\n*****Student Database*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Display by RollNo\n";
        cout<<"4) Deleting a Record\n";
        cout<<"5) Exit\n";
        cout<<"Choose your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : 
                of.insertRecord();
                cout<<"\nRecord Inserted.";
                break;
            case 2 :
                of.displayAll();
                break;
            case 3 :
                cout<<"Enter Roll Number";
                cin>>rollNo;
                of.displayRecord(rollNo);
				break;
            case 4:
                cout<<"Enter rollNo";
                cin>>rollNo;
                of.deletRecord(rollNo);
                break;
            default :
                cout<<"invalid input"<<endl;
			    break;
		}      
    }
    return 0;
}
