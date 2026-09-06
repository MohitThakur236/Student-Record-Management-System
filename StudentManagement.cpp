#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class Student{
public:
    string Name;
    int RollNo;
    string Branch;
    int Semester;
    float CGPA;
};
int getinteger(){
    int value;
    while(true){
        cin>>value;
        if(!cin.fail()) return value;
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"Invalid Input!! Please enter a Valid Number: ";
    }
}
float getfloat(){
    float value;
    while(true){
        cin>>value;
        if(!cin.fail()) return value;
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"Invalid Input! Enter correct value: ";
    }
}
void loadFromFile(vector<Student> &students){
    ifstream file("data.txt");
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string Name;
        int RollNo;
        string Branch;
        int Semester;
        float CGPA;
        string temp;
        getline(ss,Name,'|');
        getline(ss,temp,'|');
        RollNo= stoi(temp);
        getline(ss,Branch,'|');
        getline(ss,temp,'|');
        Semester= stoi(temp);
        getline(ss,temp);
        CGPA= stof(temp);
        Student s;
        s.Name= Name;
        s.RollNo=RollNo;
        s.Branch=Branch;
        s.Semester=Semester;
        s.CGPA=CGPA;
        students.push_back(s);
    }
}
void writeIntoFile(const vector<Student> &students){
    ofstream file("data.txt");
    for(int i=0;i<students.size();i++){
        file<<students[i].Name<<"|"<<students[i].RollNo<<"|"<<students[i].Branch<<"|"<<students[i].Semester<<"|"<<students[i].CGPA<<endl;
    }
}
bool existrollno(const vector<Student>& students,int rollno){
    for(int i=0;i<students.size();i++){
        if(students[i].RollNo==rollno) return true;
    }
    return false;
}
void displayallstudents(const vector<Student> &students){
    cout<<endl;
    for(int i=0;i<students.size();i++){
        cout<<"Name: "<<students[i].Name<<endl;
        cout<<"Roll Number: "<<students[i].RollNo<<endl;
        cout<<"Branch: "<<students[i].Branch<<endl;
        cout<<"Semester: "<<students[i].Semester<<endl;
        cout<<"CGPA: "<<students[i].CGPA<<endl;
        cout<<endl;
    }
}
void searchforastudent(const vector<Student> &students, int rollno){
    cout<<endl;
    cout<<"These are the Student Detail!!"<<endl;
    for(int i=0;i<students.size();i++){
        if(students[i].RollNo==rollno){
            cout<<"Name: "<<students[i].Name<<endl;
            cout<<"Roll Number: "<<students[i].RollNo<<endl;
            cout<<"Branch: "<<students[i].Branch<<endl;
            cout<<"Semester: "<<students[i].Semester<<endl;
            cout<<"CGPA: "<<students[i].CGPA<<endl;
        }
    }
}
void update(vector<Student> &students,int rollno,string name,string branch,int semester,float cgpa){
    for(int i=0;i<students.size();i++){
        if(students[i].RollNo==rollno){
            students[i].Name=name;
            students[i].Branch=branch;
            students[i].Semester=semester;
            students[i].CGPA=cgpa;
            return;
        }
    }
}
void erasestudent(vector<Student> &students,int rollno){
    for(int i=0;i<students.size();i++){
        if(students[i].RollNo==rollno){
            students.erase(students.begin()+i);
            return;
        }
    }
}
int main(){
    vector<Student> students;
    loadFromFile(students);
    string x;
    while(true){
        cout<<endl;
        cout<<"**-------MAIN MENU -------**"<<endl;
        cout<<"    1. Add A Student"<<endl;
        cout<<"    2. Display All Students"<<endl;
        cout<<"    3. Search for a Student"<<endl;
        cout<<"    4. Update Student Details"<<endl;
        cout<<"    5. Delete A Student"<<endl;
        cout<<"    6. Exit"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>x;
        if(x=="1"){
            string Name;
            cout<<"Enter Student name: ";
            cin.ignore();
            getline(cin,Name);
            int rollno;
            cout<<"Enter Rollno: ";
            rollno= getinteger();
            while(rollno<1 || existrollno(students,rollno)){
                if(rollno<1) cout<<"Rollno must be Positive!!"<<endl;
                else cout<<"Rollno already exist!!"<<endl;
                cout<<"Enter Rollno: ";
                rollno=getinteger();
            }
            string Branch;
            cout<<"Enter your Branch: ";
            cin.ignore();
            getline(cin,Branch);
            int Semester;
            cout<<"Enter your current semester: ";
            Semester=getinteger();
            while(Semester<1 || Semester>8){
                cout<<"Enter Correct Semester: ";
                Semester=getinteger();
            }
            float CGPA;
            cout<<"Enter your CGPA: ";
            CGPA=getfloat();
            while(CGPA<0 || CGPA>10){
                cout<<"Enter Correct CGPA: ";
                CGPA=getfloat();
            }
            Student a;
            a.Name=Name;
            a.RollNo=rollno;
            a.Branch=Branch;
            a.Semester=Semester;
            a.CGPA=CGPA;
            students.push_back(a);
            writeIntoFile(students);
            cout<<"Student Added Successful!!!!"<<endl;
        }
        else if(x=="2"){
            displayallstudents(students);
        }
        else if(x=="3"){
            int rollno;
            cout<<"Enter the Roll Number: ";
            rollno=getinteger();
            if(!existrollno(students,rollno)) cout<<"This Roll Number Does not Exist!!!!!"<<endl;
            else{
                searchforastudent(students,rollno);
            }
        }
        else if(x=="4"){
            int rollno;
            cout<<"Enter roll Number WHOM to update: " ;
            rollno=getinteger();
            while(!existrollno(students,rollno)){              
                cout<<"You have entered WRONG Rollno Please enter correct rollno: ";
                rollno=getinteger(); 
            }
            string name;
            cout<<"Enter updated Name of the Student: ";
            cin.ignore();
            getline(cin,name);
            string branch;
            cout<<"Enter updated Branch of the Student: ";
            getline(cin,branch);
            int semester;
            cout<<"Enter the updated Semester of the Student: ";
            semester=getinteger();
            while(semester<1 || semester>8){               
                cout<<"Enter Correct Semester: ";
                semester=getinteger();              
            }
            float cgpa;
            cout<<"Enter the updated cgpa of the Student: ";
            cgpa=getfloat();
            while(cgpa<0 || cgpa>10){                
                cout<<"Enter Correct CGPA: ";
                cgpa=getfloat();              
            }
            update(students,rollno,name,branch,semester,cgpa);
            writeIntoFile(students);
            cout<<"Updated Successful!!!!"<<endl;
        }
        else if(x=="5"){
            int rollno;
            cout<<"Enter the rollno of the Student Whom to Delete: ";
            rollno=getinteger();
            while(!existrollno(students,rollno)){
                cout<<"This rollno does not exist Enter Correct Rollno: ";
                rollno=getinteger();
            }
            erasestudent(students,rollno);
            writeIntoFile(students);
            cout<<"Student Deletion Successful!!!"<<endl;
        }
        else if(x=="6") break;
        else{
            cout<<"Inavlid Input!!!"<<endl;
        }
    }
}