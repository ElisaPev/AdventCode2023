#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <array>
#include <map>
#include <vector>

using namespace std;

int main()
{
   ifstream myFile("day1txt.txt");

   string str = "";
   string strDigits = "";
   array<int,2> numbers = { -1,-1 };
   int totalNum = 0;
   int digit = -1;
   map<string, int> stringDigit = { {"one",1},{"two",2}, {"six", 6}};
   map<string, int> foStringDigit = { {"four", 4},{"five", 5},{"nine", 9} };
   map<string, int> fiStringDigit = { {"three", 3},{"seven", 7},{"eight", 8} };
   vector<char> smallLetters = {' ',' ',' '};
   vector<char> extraLetters = { ' ',' ' };
   while (getline(myFile, str))
   {
      for (int j = 0; j < str.size(); j++)
      {         
         if (isdigit(str[j]))
         {
            digit = str[j] - '0';
         }
         else
         {
            smallLetters.push_back(str[j]);
            smallLetters.erase(smallLetters.begin());
            string strDigits(smallLetters.begin(), smallLetters.end());
            for (const auto& match : stringDigit)
            {
               if (strDigits == match.first)
               {
                  digit = match.second;
               }
            }
            if (digit == -1 && j < str.size()-1)
            {
               extraLetters[0] = str[j + 1];
               extraLetters[1] = str[j + 2];
               strDigits = strDigits + extraLetters[0];
               for (const auto& match : foStringDigit)
               {
                  if (strDigits == match.first)
                  {
                     digit = match.second;
                  }
               }
            }
            if (digit == -1 && j < str.size() - 2)
            {
               strDigits = strDigits + extraLetters[1];
               for (const auto& match : fiStringDigit)
               {
                  if (strDigits == match.first)
                  {
                     digit = match.second;
                  }
               }
            }
         }
         //cout << digit;
         if (numbers[0] == -1 && digit != -1)
         {
            numbers[0] = digit;
         }
         else if (numbers[0] != -1 && digit != -1)
         {
            numbers[1] = digit;
         }
         
         digit = -1;
      }
      //cout << "DEBUG -- line " << ++i << " is:" << str << endl;
      if (numbers[1] == -1)
      {
         numbers[1] = numbers[0];
      }
      cout << numbers[0] << numbers[1] << endl;

      totalNum = totalNum + ((numbers[0] * 10) + numbers[1]);
      numbers[0] = -1;
      numbers[1] = -1;
   }
   cout << totalNum;
}
