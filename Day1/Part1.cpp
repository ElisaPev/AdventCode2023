#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <array>

using namespace std;

int main()
{
   ifstream myFile("day1txt.txt");

   string str = "";
   array<int, 2> numbers = { -1,-1 };
   int totalNum = 0;
   bool firstFilled = false;

   while (getline(myFile, str))
   {
      for (int j = 0; j < str.size(); j++)
      {         
         if (isdigit(str[j]))
         {
            int digit = str[j] - '0';
            //if still -1 then haven't found first digit yet
            if (numbers[0] == -1)
            {
               numbers[0] = digit;
            }
            else
            {
               numbers[1] = digit;
            }
         }
      }
      //cout << "DEBUG -- line " << ++i << " is:" << str << endl;
     //if still -1 then no second digit so made second digit same as first 
     if (numbers[1] == -1)
      {
         numbers[1] = numbers[0];
      }
      totalNum = totalNum + ((numbers[0] * 10) + numbers[1]);
      numbers[0] = -1;
      numbers[1] = -1;
   }
   cout << totalNum;
}
