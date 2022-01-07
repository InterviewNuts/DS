/**
 * @file Converting_Roman_Numerals_to_Decimal.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-06
 *
 * @copyright Copyright (c) 2022
 *
 */

 /*
    “how to auto indent in visual studio code” Code Answer's
    1) On Windows Shift + Alt + F.
    2) On Mac Shift + Option + F.
    3) On Ubuntu Ctrl + Shift + I.

 SYMBOL       VALUE
   I            1
   IV           4
   V            5
   IX           9
   X            10
   XL           40
   L            50
   XC           90
   C            100
   CD           400
   D            500
   CM           900
   M            1000
   */

#include<iostream>
#include<string>
using namespace std;

int value(char c)
    {
    int v;
    //cout<<" CH = "<<c<<endl;
    switch (c)
        {
        case 'I':
            v = 1;
            break;
        case 'V':
            v = 5;
            break;
        case 'X':
            v = 10;
            break;
        case 'L':
            v = 50;
            break;
        case 'C':
            v = 100;
            break;
        case 'D':
            v = 500;
            break;
        case 'M':
            v = 1000;
            break;
        default:
            v = 0;
        }
    // cout<<" ch Val = "<<v<<endl;
    return v;
    }



void convertRomanToNumber(string str)
    {
    int res = 0;
    int i = 0;
    for (; i < str.length(); i++)
    {
        //! get the first value ( IX), Now we got (I)
        int val1 = value(str[i]);

        //! Here we check ( IX), so X is there
        if (i + 1 < str.length())
        {
            int   val2 = value(str[i + 1]);
            //! here the case XI 
            if (val1 >= val2)
            {
                res = res + val1;
            }
            else
            {
                //! IX
                res = (res + val2) - val1;
                i++;
            }
        }
        else
        {
             res = res + val1;
        }
    }// end of loop


        cout << "Romal Num = " << str << "\nNumeric Value = " << res << endl;
    }

int main()
    {
    convertRomanToNumber("IX");
    convertRomanToNumber("I");
    convertRomanToNumber("CMMV");

    convertRomanToNumber("XI");
    convertRomanToNumber("XX");
    convertRomanToNumber("CM");

    convertRomanToNumber("MCMIV");
    convertRomanToNumber("CC");
    convertRomanToNumber("VI");

    }