#include<iostream>
#include<vector>
using namespace std;

void generateParenthesis1(string &strSoFar, vector<string> &result, int open, int close){
        if(open < 0 || close < 0 || open > close){
            return;
        }

        if(open == 0 && close == 0){
            result.push_back(strSoFar);
            return;
        }

        strSoFar.push_back('(');
        generateParenthesis1(strSoFar, result, open - 1, close);
        strSoFar.pop_back();

        strSoFar.push_back(')');
        generateParenthesis1(strSoFar, result, open, close - 1);
        strSoFar.pop_back();
    }

vector<string> generateParenthesis(int n) {
    vector<string> result;

    string strSoFar = "";
    int open = n;
    int close = n;

    generateParenthesis1(strSoFar, result, open, close);
    return result;
}

int main()
{
    int n = 3;
    vector<string> parentheses = generateParenthesis(n);
    return 0;
}