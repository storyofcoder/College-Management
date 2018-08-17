                                            /////////////////////////
                                            //                     //
                                            //  author : priyanka  //
                                            //       Bhiwani       //
                                            //                     //
                                            /////////////////////////

//                        project on collage management system  using mysql database;


// include library
#include <iostream>
#include<math.h>
#include<windows.h>
#include<mysql.h>
#include<stdlib.h>
using namespace std;

string cname;

// functions
void module();

void thankyou(){
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\t T H A N K    Y O U "
    <<endl<<endl<<endl<<endl<<endl<<endl;
    Sleep(3000);
}

void deldata(string idd , string table ){

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);

                    int qstate;   // store query after
                    string query="delete from "+table+" where id = "+idd+"";
                    const char* q = query.c_str();
                    qstate = mysql_query(conn,q);

                    if(!qstate){
                        cout<<endl<<endl<<"\t\t\tRecord updated successfully..."<<endl;

                    }
                    else
                        cout<<"query problem: "<<mysql_error(conn)<<endl; Sleep(1000);
}

void welcome(){
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\t W E L C O M E"<<endl;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t May I know your Name :  ";cin>>cname;
Sleep(1000);
}

void header(){
    system ("CLS");
    cout<<endl<<endl<<"\t\t\t\t\t\t\t\t\t\t\t\t HELLO : "<<cname<<endl<<endl;
}

void home(){
cout<<endl<<endl<<endl<<"\t\t\t\tM A H A R S H I    D A Y A N A N D    U N I V E R S I T Y "<<endl<<endl<<endl;
cout<<"\t\t\t\t\t\t     R O H T A K"<<endl<<endl<<endl<<endl;
cout<<"\t\t\t\t\tS U B J E C T   :  P R O J E C T    O N  "<<endl<<endl;
cout<<"\t\t\t\tA D A R S H    M A H I L A    M A H A V I D Y A L Y A  "<<endl<<endl<<endl;
cout<<"\t\t\t\t           S E S S I O N   :    2017 - 2018  "<<endl<<endl<<endl;

cout<<"\t\t   SUBMITTED TO :                                                SUBMITTED BY:"<<endl<<endl;
cout<<"\t\t   Dr. RAJENDER SINGH CHHILLAR                                   PRIYANKA"<<endl;
cout<<"\t\t   DCSA ( MDU )                                                  MCA - 4th SEM."<<endl;
cout<<"\t\t\t\t\t\t\t\t\t         16112"<<endl;
Sleep(1000);
cout<<endl<<endl<<endl;system ("PAUSE");
}

int account(){

string username,password;
int count=3;

    while(count){
        cout<<"\t\t\t\tEnter "<<endl<<endl;
        cout<<"\t\t\t\tUsername : ";cin>>username;
        cout<<"\t\t\t\tPassword : ";cin>>password;
        cout<<endl<<endl<<endl;

        if(username!="college" || password!="pass"){
            header();
            cout<<endl<<"\t\t\t\tYou have "<<count-1<< " more chances"<<endl<<endl;
            count--;
         }
         if(count==0){
            cout<<endl<<endl<<endl<<"\t\t\t\t Sorry "<<cname<<", you are not a valid user ";
            return 0;
         }
        if(username=="college" && password=="pass")
            break;
   }
   return 1;
}

void studentf(){
    header();
    int opt;
    cout<<endl<<endl<<"\t\t\tChoose operation for Student"<<endl<<endl<<endl;
    cout<<"\t\t\t1.  ADD STUDENT DETAILS"<<endl<<endl;
    cout<<"\t\t\t2.  MODIFIY STUDENT DETAILS"<<endl<<endl;
    cout<<"\t\t\t3.  DELETE STUDENT DETAILS"<<endl<<endl;
    cout<<"\t\t\t4.  ALL STUDENT DETAILS"<<endl<<endl;
    cout<<"\t\t\t5.  MAIN OPERATION LIST"<<endl<<endl;
    cout<<"\t\t\t6.  EXIT "<<endl<<endl;
    cout<<"\t\t\t\t\t\t";
    cin>>opt;

    if (opt==1){

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;   // store query after

     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);

                    string id,name,father,dob,address,phone;
                    header();
                    cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                    cout<<"\t\t\tEnter Id: "; cin>>id;
                    cout<<"\t\t\tEnter Name: "; cin>>name;
                    cout<<"\t\t\tEnter Father: "; cin>>father;
                    cout<<"\t\t\tEnter DOB "; cin>>dob;
                    cout<<"\t\t\tEnter Number "; cin>>phone;
                    cout<<"\t\t\tEnter Address: "; cin>>address;

                    string query="insert into student(id,name,father,dob,number,address) values('"+id+"','"+name+"','"+father+"','"+dob+"','"+phone+"','"+address+"')";

                    const char* q = query.c_str();
                    qstate = mysql_query(conn,q);

                    if(!qstate){
                        cout<<"\t\t\trecord inserted successfully..."<<endl;
                        Sleep(500);
                    }
                    else
                        cout<<"query problem: "<<mysql_error(conn)<<endl;

    }
    else if (opt==2){

                    MYSQL* conn;
                    MYSQL_ROW row;
                    MYSQL_RES* res;

                    int qstate;   // store query after

                    conn = mysql_init(0);
                    conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);
                    string idd,name,father,dob,address,phone;

                    header();cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                    cout<<"\t\t\tEnter id: "; cin>>idd;
                    cout<<"\t\t\tEnter name: "; cin>>name;
                    cout<<"\t\t\tEnter father: "; cin>>father;
                    cout<<"\t\t\tEnter dob: "; cin>>dob;
                    cout<<"\t\t\tEnter phone: "; cin>>phone;
                    cout<<"\t\t\tEnter address: "; cin>>address;

                    deldata(idd,"student");
                    string query="insert into student(id,name,father,dob,number,address) values('"+idd+"','"+name+"','"+father+"','"+dob+"','"+phone+"','"+address+"')";

                    const char* q = query.c_str();
                    qstate = mysql_query(conn,q);

    }
    else if (opt==3){
                     header();
                     string idd;
                     cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                     cout<<"\t\t\tEnter id: "; cin>>idd;
                     deldata(idd,"student");
    }
    else if (opt==4){

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;   // store query after

     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);
                     string idd;
                     header();

                    qstate = mysql_query(conn," SELECT * FROM student");

                    if(!qstate){ //
                    res = mysql_store_result(conn);
                    while(row = mysql_fetch_row(res)){

                        cout<<"\t\tId      :        "<<row[0]<<endl
                            <<"\t\tName    :        "<<row[1]<<endl
                            <<"\t\tFather  :        "<<row[2]<<endl
                            <<"\t\tDOB     :        "<<row[3]<<endl
                            <<"\t\tNumber  :        "<<row[4]<<endl
                            <<"\t\tAddress :        "<<row[5]<<endl<<endl<<endl;
                            }
                    }else{
                    cout<<"query fetch problem"<<endl;
                    }
                    cout<<endl<<endl<<endl;
                    system ("PAUSE");

    }
    else if (opt==5){
        module();
    }
    else if (opt==6){
        return ;
    }

    if(opt!=6 && opt!=5)
    studentf();
}

void teacherf(){
    header();
    int opt;
    cout<<endl<<endl<<"\t\t\tChoose operation for Teacher"<<endl<<endl<<endl;
    cout<<"\t\t\t1.  ADD TEACHER"<<endl<<endl;
    cout<<"\t\t\t2.  UPDATE TEACHER DETAILS"<<endl<<endl;
    cout<<"\t\t\t3.  REMOVE TEACHER DETAILS"<<endl<<endl;
    cout<<"\t\t\t4.  ALL TEACHERS LIST"<<endl<<endl;
    cout<<"\t\t\t5.  MAIN OPERATION LIST"<<endl<<endl;
    cout<<"\t\t\t6.  EXIT "<<endl<<endl;

    cout<<"\t\t\t\t\t\t";
    cin>>opt;

    if (opt==1){

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;   // store query after

    conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);
              string id,name,father,dob,address,phone;
                     header();
                    cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                    cout<<"\t\t\tEnter Id: "; cin>>id;
                    cout<<"\t\t\tEnter Name: "; cin>>name;
                    cout<<"\t\t\tEnter Father: "; cin>>father;
                    cout<<"\t\t\tEnter DOB: "; cin>>dob;
                    cout<<"\t\t\tEnter Phone: "; cin>>phone;
                    cout<<"\t\t\tEnter Address: "; cin>>address;

                    string query="insert into teacher(id,name,father,dob,number,address) values('"+id+"','"+name+"','"+father+"','"+dob+"','"+phone+"','"+address+"')";

                    const char* q = query.c_str();
                    qstate = mysql_query(conn,q);

                    if(!qstate){
                        cout<<"\t\t\tRecord inserted successfully..."<<endl;
                        Sleep(500);
                    }
                    else
                        cout<<"query problem: "<<mysql_error(conn)<<endl;

    }
    else if (opt==2){

                   MYSQL* conn;
                    MYSQL_ROW row;
                    MYSQL_RES* res;

                    int qstate;   // store query after

                    conn = mysql_init(0);
                     conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);
                    string idd,name,father,dob,address;
                     string phone;

                    header();cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                    cout<<"\t\t\tEnter Id: "; cin>>idd;
                    cout<<"\t\t\tEnter Name: "; cin>>name;
                    cout<<"\t\t\tEnter Father: "; cin>>father;
                    cout<<"\t\t\tEnter DOB: "; cin>>dob;
                    cout<<"\t\t\tEnter Number: "; cin>>phone;
                    cout<<"\t\t\tEnter Address: "; cin>>address;

                    deldata(idd,"teacher");
                    string query="insert into teacher(id,name,father,dob,number,address) values('"+idd+"','"+name+"','"+father+"','"+dob+"','"+phone+"','"+address+"')";

                    const char* q = query.c_str();
                    qstate = mysql_query(conn,q);

    }
    else if (opt==3){
                     header();
                     string idd;
                     cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                     cout<<"\t\t\tEnter Id: "; cin>>idd;
                     deldata(idd,"teacher");
    }
    else if (opt==4){

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;   // store query after

    conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);

                    header();
                    qstate = mysql_query(conn," SELECT * FROM teacher  ");

                    if(!qstate){ //
                    res = mysql_store_result(conn);
                    while(row = mysql_fetch_row(res)){

                        cout<<"\t\tId      :        "<<row[0]<<endl
                            <<"\t\tName    :        "<<row[1]<<endl
                            <<"\t\tFather  :        "<<row[2]<<endl
                            <<"\t\tDOB     :        "<<row[3]<<endl
                            <<"\t\tNumber  :        "<<row[4]<<endl
                            <<"\t\tAddress :        "<<row[5]<<endl<<endl<<endl;
                            }
                    }else{
                    cout<<"query fetch problem"<<endl;
                    }
                    cout<<endl<<endl<<endl;
                    system ("PAUSE");
    }
    else if (opt==5){
        module();
    }
    else if (opt==6){
        return ;
    }

    if(opt!=6 && opt!=5)
    teacherf();
}

void library(){
    header();
    int opt;
    cout<<endl<<endl<<"\t\t\tChoose operation for Book"<<endl<<endl<<endl;
    cout<<"\t\t\t1.  ADD BOOK"<<endl<<endl;
    cout<<"\t\t\t2.  Update BOOK"<<endl<<endl;
    cout<<"\t\t\t3.  REMOVE BOOK"<<endl<<endl;
    cout<<"\t\t\t4.  ALL BOOKS LIST"<<endl<<endl;
    cout<<"\t\t\t5.  MAIN OPERATION LIST"<<endl<<endl;
    cout<<"\t\t\t6.  EXIT "<<endl<<endl;

    cout<<"\t\t\t\t\t\t";
    cin>>opt;

    if (opt==1){

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;   // store query after

     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);
              string number,title,author,price;
                     header();
                     cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                    cout<<"\t\t\tEnter Book Number: "; cin>>number;
                    cout<<"\t\t\tEnter Book Title: "; cin>>title;
                    cout<<"\t\t\tEnter Author Name: "; cin>>author;
                    cout<<"\t\t\tEnter Price: "; cin>>price;

                    string query="insert into book(id,title,author,price) values('"+number+"','"+title+"','"+author+"','"+price+"')";

                    const char* q = query.c_str();
                    qstate = mysql_query(conn,q);

                    if(!qstate){
                        cout<<"\t\t\tRecord inserted successfully..."<<endl;
                        Sleep(500);
                    }
                    else
                        cout<<"query problem: "<<mysql_error(conn)<<endl;

    }
     else if (opt==2){

                    MYSQL* conn;
                    MYSQL_ROW row;
                    MYSQL_RES* res;
                    int qstate;   // store query after

                    conn = mysql_init(0);
                    conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);

                    string number,title,author,price;
                    header();
                     cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                    cout<<"\t\t\tEnter Book Number: "; cin>>number;
                    cout<<"\t\t\tEnter Book Title: "; cin>>title;
                    cout<<"\t\t\tEnter Author Name: "; cin>>author;
                    cout<<"\t\t\tEnter Price: "; cin>>price;

                    deldata(number,"book");
                    string query="insert into book(id,title,author,price) values('"+number+"','"+title+"','"+author+"','"+price+"')";

                    const char* q = query.c_str();
                    qstate = mysql_query(conn,q);


    }
    else if (opt==3){
                    header();
                    string idd;
                    cout<<endl<<endl<<"\t\t\tEnter Details"<<endl<<endl;
                    cout<<"\t\t\tEnter BOOK Id: "; cin>>idd;
                    deldata(idd,"book");
    }
    else if (opt==4){

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;   // store query after

     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","collage",0,NULL,0);
                    system ("CLS");

                    header();
                    qstate = mysql_query(conn," SELECT * FROM book  ");

                    if(!qstate){ //
                    res = mysql_store_result(conn);
                    while(row = mysql_fetch_row(res)){

                        cout<<"\t\t Book Id       :        "<<row[0]<<endl
                            <<"\t\t Book Title    :        "<<row[1]<<endl
                            <<"\t\t Book Author   :        "<<row[2]<<endl
                            <<"\t\t Book Price    :        "<<row[3]<<endl<<endl;
                            }
                    }else{
                    cout<<"query fetch problem"<<endl;
                    }
                    cout<<endl<<endl<<endl;
                    system ("PAUSE");

    }
    else if (opt==5){
        module();
    }
    else if (opt==6){
        return ;
    }

    if(opt!=6 && opt!=5)
    library();
}

void module(){
    system ("CLS");
    header();
    int opt;

    cout<<endl<<endl<<"\t\t\tChoose your operation"<<endl<<endl<<endl;
    cout<<"\t\t\t1.  STUDENT"<<endl<<endl;
    cout<<"\t\t\t2.  TEACHER"<<endl<<endl;
    cout<<"\t\t\t3.  LIBRARY"<<endl<<endl;
    cout<<"\t\t\t4.  EXIT"<<endl<<endl;
    cout<<"\t\t\t\t\t\t";
    cin>>opt;

    if(opt==1){
         studentf();
    }
    else if(opt==2){
        teacherf();
     }
    else if(opt==3){
            library();
        }
    else if(opt==4){
        header();
        thankyou();
        }

    if(opt!=4)
        module();

}
int main()
{
    welcome();

    header();
    home();

    header();
    int authentication=account();
    if(authentication==0){
        cout<<endl<<endl<<endl<<"\t\t\t\t T H A N K   Y O U "<<endl<<endl<<endl<<endl<<endl<<endl;
        Sleep(4000);
        return 0;
    }
    module();

    return 0;
}
