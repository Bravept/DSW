// 2. Given an input text string and a simple text pattern, find the starting indices of all matches of the pattern in the input text string.

#include <iostream>
using namespace std;


int main() {
   
   string text = "abracadabrazabramabracabraagrabarbazabra";
   string simpleText = "abr";


   int pos = 0;
   int index;


   while((index = text.find(simpleText, pos)) != string::npos) {
      cout << "\nMatch pattern: " << index;
      pos = index + 1; 

   }

   return 0;

}