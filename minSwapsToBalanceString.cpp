#include<iostream>
using namespace std;

    int minSwaps(string s)
    {
        string unpurifiedString = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
            {
                unpurifiedString.push_back(s[i]);
            }
            else if (s[i] == ']')
            {
                if (!unpurifiedString.empty() && unpurifiedString.back() == '[')
                {
                    unpurifiedString.pop_back();
                }
                else
                {
                    unpurifiedString.push_back(s[i]);
                }
            }
        }

        return ((unpurifiedString.size() / 2) + 1) / 2;
    }

int main()
{
    string str = "][[]][";
    cout << minSwaps(str) << endl;
    return 0;
}