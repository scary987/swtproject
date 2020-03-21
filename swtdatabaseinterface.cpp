/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#define IP "tcp://localhost:3306"
#define serveruser "scary__"
#define serverpassword "monsterssupercreeps" 
using namespace std;
sql::Driver *driver;
sql::Connection *con;

int register_function(string username, string passphrase, string vorname, string nachname, string birthdate,string emailname,string emailhost){
	 try {

  sql::Statement *stmt; 
  sql::ResultSet *res;
  sql::ResultSet *res1;
  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://localhost:3306", "scary__", "monsterssupercreeps");
  /* Connect to the MySQL test database */
  con->setSchema("swtproject");
  string statement="Select count(username) as number  from signin where username='"+username+"'";
  stmt = con->createStatement();
  cout<<"Running: "<<statement<<endl; 
  res = stmt->executeQuery(statement); 
  while (res->next()) {
    //cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    //cout << res->getInt("number") << endl;
	if(res->getInt("number"))cout<<"Username already exists";
	else{
	stmt = con->createStatement();
	cout<<"Running Execute: "<<statement<<endl;
	statement="Insert into signin(username,password) values ('"+username+"','"+passphrase+"') ";
  	stmt->execute(statement);
	stmt = con-> createStatement(); 
        statement="call loginexists('"+username+"',@a,@b)";
	cout<<"Running: "<<statement<<endl;
	stmt->execute(statement);
	statement="select id from signin where username='"+username+"'";
	cout<<"Running: "+statement<<endl;
	stmt=con->createStatement(); 
	res1 = stmt->executeQuery(statement);
        res1->next(); 	
	int id = res1->getInt("id");
	cout<<"The generated ID: "+id <<endl;	




	cout<<"Now inserting into users: "<<endl;
	statement="Insert into users(id,vorname,nachname,birthdate,emailname,emailhost) values ("+ to_string(id)+",'"+ vorname+ "','"+ nachname+"','"+ birthdate+ "','"+ emailname+"','"+emailhost+"')";
	 cout<<"Running: "+ statement<<endl; 
	 stmt->execute(statement); 
	
	 cout<<"You have successfully registered :)\n"; 


	}	
    return 0 ;
        
    /*cout << "\t... MySQL says it again: ";
    /* Access column fata by numeric offset, 1 is the first column 
    cout << res->getString(1) << endl; */
  }
  
  delete res;
  delete res1; 
  delete stmt;
  delete con;


} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  return e.getErrorCode(); 
}
return 0;}
int  login_function(string username, string passphrase){
 try {

  sql::Statement *stmt;
  sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://localhost:3306", "scary__", "monsterssupercreeps");
  /* Connect to the MySQL test database */
  con->setSchema("swtproject");
  string statement="Select count(username),id as number,id  from signin where username='"+username+"' and password='" +passphrase+"'";
  stmt = con->createStatement();
  res = stmt->executeQuery(statement); 
  while (res->next()) {
    //cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    //cout << res->getInt("number") << endl;
	if(!res->getInt("number")){cout<<"Either your username or passphrase is not correct.";
       return 0;	} 
	cout<<"You're now logged in :)\n"; 
    return res->getInt("id");
	} 
    /*cout << "\t... MySQL says it again: ";
    /* Access column fata by numeric offset, 1 is the first column 
    cout << res->getString(1) << endl; */
  
  delete res;
  delete stmt;
  delete con;}

  catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  return e.getErrorCode(); 
} 
  return 0; 
}

int main(int argc, char *argv[])
{
  
  bool login = 0; 
  bool regist = 0; 
  bool user = 0;
  string username, password, vorname,nachname,birthdate,emailname,emailhost;   
  for(int i = 0; i<argc; i++)
  {       printf("%s\n",argv[i]); 
	 if(argv[i][0]=='-'){
		 if(argv[i][1]=='u') {
			 i++;
			 if (argv[i]!= NULL) username=argv[i]; 
	    else{cout<<"Error: no provided username! Abandoning process..\n";
		    return 1;}  }
    if(argv[i][1]=='l') login = true;
    if(argv[i][1]=='r') regist = true;
    if(argv[i][1]=='p') {
	    i++;
	    if(argv[i]!=NULL) password = argv[i]; 
	    else{
		    cout<<"Error: no provided passphrase! Abandoning process..\n";
		    return 1;} }
    if(argv[i][1]=='n') {
	    i++; 
	    if(argv[i]!=NULL&& argv[i+1]!=NULL) {
		    vorname = argv[i];
		    nachname=argv[i+1];
		    i++ ;} 
	    else{
		    cout<<"Error: provided name is not complete! Abandoning process..\n";
		    return 1;} }
    if(argv[i][1]=='b') { i++;
	    if(argv[i]!=NULL) birthdate = argv[i]; 
	    else{
		    cout<<"Error: no provided birthdate! Abandoning process..\n";
		    return 1;} 

} 
if(argv[i][1]=='e') { 
       	i++;
       	if(argv[i]!=NULL){
	       	char* token;
	       	token= strtok(argv[i],"@");
	       	emailname = token; 
		token= strtok(NULL, "@");
	       	emailhost= token;
	       	cout<<"email: "<<emailname+" "<<emailhost<<endl; 
      	
}       
    else{cout<<"Error: no provided email! Abandoning process..\n"; return 1;} }

         
    }
  }
  /* checking for correct commandline inputs*/
cout << endl;
//cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;
//cout << username+" "+password+" "+birthdate+"\n";
if(regist)  register_function(username,password,vorname,nachname,birthdate,emailname,emailhost);
if(login)  login_function(username,password);
if(!regist && !login){cout<<"You need to call this function with either the login parameter (-l) or the register parameter (-r)\n Be sure to enter the birthdate in year-month-day notation\n"; return 0;  }

cout << endl;

return EXIT_SUCCESS;
}


