/**
 * @file string1_is_rotation_of_str2.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
A Program to check if strings are rotations of each other or not
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1? 
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/

#include<iostream>
#include<string>
using namespace std;

bool isStringOneRotationOdStringTwo(string str1, string str2)
{
     /* Check if sizes of two strings are same */
   if (str1.length() != str2.length())
        return false;
 
   string temp = str1 + str1;
 cout<<" str  " << temp<<endl;
  return (temp.find(str2) != string::npos);


}




int main()
{
    string str1 = "ABACD", str2 = "CDABA";

    if ( isStringOneRotationOdStringTwo(str1,str2))
    {
        cout<<" two sring are rotation of each other\n";
    }
    else{
        cout<<" two sring are NOT rotation of each other\n";
    }
    return 0;
}