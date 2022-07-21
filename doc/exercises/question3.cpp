//3. Given an array of integer numbers, arrange the elements of the array in a way that forms the highest possible number. For example, given [10, 7, 76, 415], you should return 77641510.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct {
        bool operator () (int a, int b) const
  {
    string value1 = to_string(a) + to_string(b);
    string value2 = to_string(b) + to_string(a);

    return value1 > value2;
  }
} customCompare;

string formHighestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), customCompare);
        string s;
        for (int &i: nums)
        {
                s += to_string(i);
        }
        return s;
    }

    int main()
{
        vector<int> numbers = { 10, 7, 76, 415 };

        cout << "The highest possible number is; \n" << formHighestNumber(numbers);

        return 0;
}

//before i made this one i researched the answer because it was a challeging question, at the time i though this was an example of a possible question not the final one.