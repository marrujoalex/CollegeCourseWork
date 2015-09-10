/* Student ID#: 003914325
   Name: Samuel Marrujo
   Date: 11/15/11
   Professor: Dr. Murphy
   Class: CSCI202
   Project: Lab 8
*/

#ifndef PWFILE_H
#define PWFILE_H
#include <string>
#include <vector>
#include "userpw.h"

using namespace std;

class PasswordFile
{
   public:
     PasswordFile(string f);// opens the file and reads the names/passwords in the vector entry
     string getFilename(); // returns the filename
     vector<UserPw> getFile(); // returns the vector entry 
     void addpw(UserPw newentry); //this adds a new user/password to entry and writes entry to the file filename
     bool checkpw(string user, string password); // returns true if user exists and password matches
   private:
     string filename; // the file that contains password information
     vector<UserPw> entry; // the list of usernames/passwords
};
#endif
