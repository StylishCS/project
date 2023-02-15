#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define el endl
using namespace std;

struct students
{
    int ID;
    string studname, address ;
    double total_marks=0, percentage=0,sum_marks=0;
} s[30];

struct course
{
    string courseid;
    string coursename;
    string instructorname;
    vector <students> enrolled_students;
    int mark;
} c[20];

int x,total_courses=0,total_stud=0;
void displayStudent()
{
    for(int y=0; y<=total_stud; y++)
    {
        cout<<"student name is:"<<s[y].studname<<endl;
        cout<<"student address is:"<<s[y].address<<endl;
        cout<<"student total marks is:"<<s[y].total_marks<<endl;
        cout<<"student percentage is:"<<s[y].percentage<<endl;
        cout<<"\n\n\n";
    }

    system("pause");
};
void add2()
{
    system("cls");
    cout<<"\t\t\t\t add course";
    cout<<"\n enter course name:";
    cin>>c[x].coursename;
    cout<<"\n enter course id:";
    cin>>c[x].courseid;
    cout<<"\nenter instructor name:";
    cin>>c[x].instructorname;
    cout<<"course added succesfully"<<endl;
    total_courses++;
    s[x].sum_marks=total_courses*100;
    x++;
    cin.get();
    system("pause");
};


void delete_stud(){
    int searched_ID;
    bool flag=false;
        cout<<"Please enter student ID:"<<endl;
        cin>>searched_ID;
        for(int i=0 ; i<=30 ; i++)
        {
            if (s[i].ID==searched_ID)
            {
                flag=true;
                
            }
        }
        if (flag==false)
            cout<<"Student not found."<<endl;

        system("pause");
    }
    break;
    return;
};

void display_courses()
{
    system("cls");
    cout << "Courses Available: " << endl;
    for(int k=0; k<total_courses; k++)
    {
        cout << k+1 << ". " << c[k].coursename << endl;
    }
    cout<<"\n\n\n";
    system("pause");
};


int i=0;
void add1()
{
    system("cls");
    cout<<"\n\n\t\t\t add student";
    cout<<"\nenter student id: ";
    cin>>s[i].ID;
    cout<<"\nenter student name: ";
    cin>>s[i].studname;
    cout<<"\nenter student address: ";
    cin>>s[i].address;
    i++;
    cout<<"\t\t\n student added sucsessfully";
    total_stud++;
};


void searchstud()
{
    int entered_choice;
    bool flag=false;
    cout<<"Please make a choice: "<<endl;
    cout<<"1: search by ID."<<endl;
    cout<<"2: search by name."<<endl;
    cin>>entered_choice;
    switch (entered_choice)
    {
    case 1:
    {
        int searched_ID;
        cout<<"Please enter student ID:"<<endl;
        cin>>searched_ID;
        for(int i=0 ; i<=30 ; i++)
        {
            if (s[i].ID==searched_ID)
            {
                flag=true;
                cout<<"student name is:"<<s[i].studname<<endl;
                cout<<"student address is:"<<s[i].address<<endl;
                cout<<"student total marks is:"<<s[i].total_marks<<endl;
                cout<<"student percentage is:"<<s[i].percentage<<endl;
                cout<<"student enrolled courses are: ";
                for (int l=0; l<20; l++)
                {
                    for (size_t m=0; m<c[l].enrolled_students.size(); m++)
                    {
                        if (searched_ID == c[l].enrolled_students[m].ID)
                            cout<<c[l].coursename<<endl;
                    }
                }

            }
        }
        if (flag==false)
            cout<<"Student not found."<<endl;

        system("pause");
    }
    break;
    return;
    case 2:
    {
        string searched_name;
        vector <double> TotalMarksVec;
        vector <students> found_students;
        bool flag=false;
        cout<<"Please enter student name: "<<endl;
        cin>>searched_name;
        for(int i=0 ; i<=30 ; i++)
        {
            if (s[i].studname==searched_name)
            {
                flag=true;
                TotalMarksVec.push_back(s[i].total_marks);
                found_students.push_back(s[i]);
            }
        }
        if (flag==true)
        {
            sort(TotalMarksVec.begin(),TotalMarksVec.end());
            for (int i=TotalMarksVec.size()-1; i>=0; i--)
            {
                for (int j=0; j<found_students.size(); j++)
                {
                    if (found_students[j].total_marks == TotalMarksVec[i])
                    {
                        cout<<"student name is:"<<found_students[j].studname<<endl;
                        cout<<"student address is:"<<found_students[j].address<<endl;
                        cout<<"student total marks is:"<<found_students[j].total_marks<<endl;
                        cout<<"student percentage is:"<<found_students[j].percentage<<endl;
                        cout<<"student enrolled courses are: ";
                        for (int l=0; l<20; l++)
                        {
                            for (size_t m=0; m<c[l].enrolled_students.size(); m++)
                            {
                                if (searched_name == c[l].enrolled_students[m].studname)
                                    cout<<c[l].coursename<<endl;
                            }
                        }
                    }
                }
            }
            cin.get();
            system("pause");
        }
        else
        {
            cout<<"student not found.";
        }
        cin.get();
        system("pause");
    }
    break;
    }
    return;
};

/*void search_course(){
int entered_choice;
    bool flag=false;
    cout<<"Please make a choice: "<<endl;
    cout<<"1: search by ID."<<endl;
    cout<<"2: search by name."<<endl;
    cin>>entered_choice;
    switch (entered_choice)
    {
    case 1:
    {
        int searched_ID;
        cout<<"Please enter course ID:"<<endl;
        cin>>searched_ID;
        for(int i=0 ; i<=30 ; i++)
        {
            if (c[i].ID==searched_ID)
            {
                flag=true;
                cout<<"course name is:"<<c[i].coursename<<endl;
                cout<<"course ID is:"<<c[i].courseid<<endl;
                cout<<"course instructor name is:"<<c[i].instructorname<<endl;
                cout<<"student enrolled courses are: ";
                for (int l=0; l<20; l++)
                {
                    for (size_t m=0; m<c[l].enrolled_students.size(); m++)
                    {
                        if (searched_ID == c[l].enrolled_students[m].ID)
                            cout<<c[l].coursename<<endl;
                    }
                }

            }
        }
        if (flag==false)
            cout<<"Course not found."<<endl;

        system("pause");
    }
    break;
    return;
    case 2:
    {
        string searched_name;
        vector <students> found_students;
        bool flag=false;
        cout<<"Please enter course name: "<<endl;
        cin>>searched_name;
        for(int i=0 ; i<=30 ; i++)
        {
            if (c[i].studname==searched_name)
            {
                flag=true;
            }
        }
        if (flag==true)
        {
            {
                for (int j=0; j<found_students.size(); j++)
                {
                    if (found_students[j].total_marks == TotalMarksVec[i])
                    {
                        cout<<"student name is:"<<found_students[j].studname<<endl;
                        cout<<"student address is:"<<found_students[j].address<<endl;
                        cout<<"student total marks is:"<<found_students[j].total_marks<<endl;
                        cout<<"student percentage is:"<<found_students[j].percentage<<endl;
                        cout<<"student enrolled courses are: ";
                        for (int l=0; l<20; l++)
                        {
                            for (size_t m=0; m<c[l].enrolled_students.size(); m++)
                            {
                                if (searched_name == c[l].enrolled_students[m].studname)
                                    cout<<c[l].coursename<<endl;
                            }
                        }
                    }
                }
            }
            cin.get();
            system("pause");
        }
        else
        {
            cout<<"student not found.";
        }
        cin.get();
        system("pause");
    }
    break;
    }
    return;
};*/

void enroll(){
  string searched_ID;
  bool flag=false;
    cout<<"Please enter student ID:"<<endl;
    cin>>searched_ID;
    for(int i=0 ; i<=30 ; i++){
      if (s[i].ID==searched_ID[i]){
         flag=true;
         c[i].enrolled_students.push_back(s[i].studname);
         cin>>c.mark[i];
         s.total_marks[i]+=c.mark[i];
      }
    }
  if (flag==false)
         cout<<"Student not found."<<endl;

	system("pause");
}


void searchcourse()
{
    string searched_courseid;
    cout<<"Please enter course ID:"<<endl;
    cin>>searched_courseid;
    for(int j=0; j<20; j++)
    {
        if (c[j].courseid == searched_courseid)
        {
            cout<<"Course name is: "<<c[j].coursename<<endl;
            cout<<"Instructor name is: "<<c[j].instructorname<<endl;
            cout<<"Enrolled students are: ";
            for (size_t i=0; i<c[j].enrolled_students.size(); i++)
            {
                cout<<c[j].enrolled_students[i].studname<<endl;

            }
        }
    }
    cin.get();
    system("pause");
};
bool login (string usernameSignUp, string passwordSignUp)
{
    bool LoginOk=false;
    string usernameSignIn, passwordSignIn;
    for(int a=1 ; a<=3 ; a++)
    {
        system("cls");
        cout<<"\t\t\t\t welcome to the course mangement system";
        cout<<"\n enter username:";
        cin>>usernameSignIn;
        cout<<"\n enter password:";
        cin>>passwordSignIn;
        if (usernameSignUp == usernameSignIn && passwordSignUp == passwordSignIn)
        {
            LoginOk = true;
            break;
        }
    }
    if (LoginOk == true)
        return true;
    else
        return false;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int x,choice;
    string username,password;
    cout<<"\t\t\t\t*welcome to the course management system*";
    cout<<"\n\n\n 1.register";
    cout<<"\n\n 2.exit";
    cout<< "\n\n\nenter your choice:";
    cin>>x;
    system("cls");
    switch(x)
    {
    case 1:
        cout<<"\t\t\t\t welcome to the course mangement system";
        cout<<"\n enter username:";
        cin>>username;
        cout<<"\n enter password:";
        cin>>password;
        if (login(username, password) == false)
        {
            system("cls");
            // if username and password written wrong 3 times, console will be temrinated
            cout<<"Wrong username or password"<<endl;
            return 0;
        }
        //if (username==username1&&password==password1){
s:
        system("cls");


        cout<<"\t\t\t\twelcome to the course management system";
        cout<<"\n\n 1 add student";
        cout<<"\n 2 add course ";
        cout<<"\n 3 search for student";
        cout<<"\n 4 search for course ";
        cout<<"\n 5 delete student ";
        cout<<"\n 6 delete course";
        cout<<"\n 7 display students";
        cout<<"\n 8 display courses";
        cout<<"\n 9 exit";
        cout<<"\n\n\n enter your choice: ";
        cin>>choice;
        /*}
        else{
         system("cls");
         if(username!=username1)
           cout<<"Wrong username"<<endl;
         if(password!=password1)
           cout<<"Wrong password"<<endl;
        }*/
        switch(choice)
        {
        case 1:
            add1();
            goto s;
            break;
        case 2:
            add2();
            goto s;
            break;

        case 3:
            searchstud();
            goto s;
            break;

        case 4:
            searchcourse();
            goto s;
            break;

        case 5:

            break;

        case 6:

            break;

        case 7:
            displayStudent();
            goto s;
            break;

        case 8:
            display_courses();
            goto s;
            break;

        case 9:
            break;

        case 10:
            exit(0);

        }
    }
}
