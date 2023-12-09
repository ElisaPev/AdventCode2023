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
   array<int, 2> numbers = { -1 };
   int totalNum = 0;

   while (getline(myFile, str))
   {
      for (int j = 0; j < str.size(); j++)
      {         
         if (isdigit(str[j]))
         {
            int digit = str[j] - '0';
            if (numbers[0] == -1)
            {
               numbers[0] = digit;
            }
            numbers[1] = digit;
         }
      }
      //cout << "DEBUG -- line " << ++i << " is:" << str << endl;
      totalNum = totalNum + ((numbers[0] * 10) + numbers[1]);
      numbers[0] = -1;
   }
   cout << totalNum;
}
