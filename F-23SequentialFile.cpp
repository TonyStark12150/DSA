/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data
*/
#include<iostream>
#include<fstream>
using namespace std;

class student
{
    int roll_no;
    string name;
    fstream f;
    public:
    void setdata()
    {
        cout<<"Enter Roll No. of students:"<<endl;
        cin>>roll_no;
        cout<<"Enter Student name :"<<endl;
        cin>>name;
    }  
    void getdata()
    {
        cout<<"Roll No.-"<<roll_no<<endl;
        cout<<"Student name -"<<name<<endl;
    } 

    

};