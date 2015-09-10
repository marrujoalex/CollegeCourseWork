/* Student ID#: 003914325
   Name: Samuel Marrujo
   Date: 11/15/11
   Professor: Dr. Murphy
   Class: CSCI202
   Project: Lab 9
*/
#ifndef USERPW_H
#define USERPW_H
#include <string>
#include <vector>

using namespace std;

class UserPw
{
   public:
     UserPw(string user, string password);//Constructor
     string getUser(); // returns the user
     string getPassword();// returns the password
     bool Checkpw(string user, string password); // returns true if user and password both match
   private:
     string user;
     string password;
};
#endif
