#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student{
private:
int marks[5];
int rollno;
float Percentage;
string Grade;
string name;
int total;

public:
student(){
    total=0;
    Percentage=0;
}
void getdata();
void compute();
void showdata();
void filesaving();
void fetchdata();

};
void student::getdata(){
    cin.ignore();
        cout<<"Enter Your Name"<<endl;
        getline(cin,name);
        cout<<"Enter Your Roll no"<<endl;
        cin>>rollno;
    cout<<"Enter 5 Marks"<<endl;
    for (int i=0;i<5;i++){
        cout<<"Enter Marks of Subject "<<i+1<<endl;
        cin>>marks[i];
    }
    cout<<"Data Added Succesfully"<<endl;
}
    void student::compute(){
        for (int i=0;i<5;i++){
            total+=marks[i];
        }
        Percentage=(total/500.0)*100.0;
        if(Percentage>=90){
            Grade="A+";
        }
        else if(Percentage>=80){
            Grade="A";
        }
        else if(Percentage>=70){
            Grade="B";
        }
      else if(Percentage>=60){
            Grade="C";
        }
    else if(Percentage>=50){
            Grade="D";
        }
        else{
            Grade="Fail";
        }
    }
void student::showdata(){
    cout<<"Name : "<<name<<endl;
    cout<<"Roll NO :"<<rollno<<endl;
    for (int i=0;i<5;i++){
        cout<<" Marks Subject "<<i+1<<":"<<marks[i]<<endl;
    }
    cout<<"Total:"<<total<<endl;
    cout<<"Percentage:"<<Percentage<<endl;
    cout<<"Grade:"<<Grade<<endl;
}
void student::filesaving(){
    ofstream Write;
    Write.open("Records.txt",ios::app);
    Write<<name<<" "<<rollno<<" "<<total<<" "<<Percentage<< " "<<Grade<<" ";
       for (int i = 0; i < 5; i++)
    {
        Write<<marks[i]<<" ";
    }
    Write<<endl;
    Write.close();
    cout<<"File SuccesFully Saved"<<endl;
}
void student::fetchdata(){
    ifstream Read;
    Read.open("Records.txt",ios::in);
    int Rollno;
    bool found=false;
 cout<<"Enter The Roll No of student"<<endl;
 cin>>Rollno;

    while (Read>>name>>rollno>>total>>Percentage>>Grade)
    {
        for (int i = 0; i < 5; i++)
        {
           Read>>marks[i];
        }
        
         if(Rollno==rollno){
            showdata();
            found=true;
            break;
    
               }
 }
 if(!found){
    cout<<"Record is not Found"<<endl;
 }

    Read.close();
}
int main(){
student s1;
char choice;
int option;
do
{
cout<<"Do you Want to Add student press 1 & 2 to see existing records otherwise\n press 0 for exit"<<endl;
cin>>option;
    /* code */


if( option== 1 ){
s1.getdata();
s1.compute();
s1.showdata();
cout<<"Do you  want to  save that data (Y/N)"<<endl;
cin>>choice;
if (choice=='y'||choice=='Y'){
s1.filesaving();
}
else{
 goto a;
}
}
else if( option == 2 ){
s1.fetchdata();
}
}while (option!=0);
a:
cout<<"Thank you for using my software "<<endl;
return 0;
}
