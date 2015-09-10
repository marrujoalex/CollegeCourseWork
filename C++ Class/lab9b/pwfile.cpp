/* Student ID#: 003914325
   Name: Samuel Marrujo
   Date: 11/15/11
   Professor: Dr. Murphy
   Class: CSCI202
   Project: Lab 8
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "pwfile.h"
#include "userpw.h"

using namespace std;
  
PasswordFile::PasswordFile(string f) { 
  // The constructor accepts a filename, and reads the file one-line at a time and adds values to the entry vector.
  this->filename = f;
  ifstream infile;
  infile.open(this->filename.c_str());
  if (infile.good()) {
    string user, pw;
    infile >> user >> pw;
    while (infile.good()) {
      UserPw person(user, pw);
      entry.push_back(person);
      infile >> user >> pw;
    }
  }
  else {
    cout << "File does not exist";
  }
  infile.close();
}

string PasswordFile::getFilename() { 
  return filename;
}

vector<UserPw> PasswordFile::getFile() {
  return entry;
}

void PasswordFile::addpw(UserPw newentry) {
  //this adds a new user/password to entry and writes entry to the file filename
  entry.push_back(newentry);
  ofstream outfile;
  outfile.open(filename.c_str());
  for (int i=0; i < entry.size(); i++) {
    outfile << entry[i].UserPw::getUser() << " " << entry[i].UserPw::getPassword() << endl;
  }
  outfile.close();
}

bool PasswordFile::checkpw(string user, string password) {
  for (int i = 0; i < entry.size(); i++) {
    if (entry[i].UserPw::getUser() == user) {
      if (entry[i].UserPw::Checkpw(user, password)) {
        cout << "Entry successful!" << endl;
        return true;
      }
      else {
        cout << "Invalid Password." << endl;
        return false;
      }
    }
  } 
  cout << "Invalid Username." << endl;
  return false;
}
