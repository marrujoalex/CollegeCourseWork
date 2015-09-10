/* Student ID#: 003914325
   Name: Samuel Marrujo
   Date: 11/15/11
   Professor: Dr. Murphy
   Class: CSCI202
   Project: Lab 9
*/

#include <string>
#include <vector>
#include "userpw.h"

using namespace std;

UserPw::UserPw(string user, string password) {
  this->user = user;
  this->password = password;
}

string UserPw::getUser() {
  return user;
}

string UserPw::getPassword() {
  return password;
}

bool UserPw::Checkpw(string user, string password) {
  if (this->getUser() == user && this->getPassword() == password) {
    return true;
  }
  else {
    return false;
  }
}
