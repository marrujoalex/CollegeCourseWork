/* Student ID#: 003914325
   Name: Samuel Marrujo
   Date: 11/15/11
   Professor: Dr. Murphy
   Class: CSCI202
   Project: Lab 9
*/

#include <iostream>
#include <string>
#include <vector>
#include "userpw.h"
#include "pwfile.h"

using namespace std;

int main() {
   string name, pw;
   PasswordFile passfile("password.txt");
   passfile.addpw(UserPw("dbotting","123qwe"));
   passfile.addpw(UserPw("egomez","qwerty"));
   passfile.addpw(UserPw("tongyu","liberty"));
   cout << "Input login name: "; cin >> name;
   cout << "Input password: "; cin >> pw;
   passfile.PasswordFile::checkpw(name, pw);
  return 0;
}
