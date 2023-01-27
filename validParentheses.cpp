#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
        int len=s.length();
        stack<char> st;
        
        for(int i=0;i<len;i++){
            char ch=s[i];
            
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            
            else{
                if(!st.empty()){
                    char topElement=st.top();
                    if((ch==')' && topElement=='(') || (ch=='}' && topElement=='{') || (ch==']' && topElement=='[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
                
            }
        }
        
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }

int main()
{
    string str = "((())())";
    cout << isValid(str);
    return 0;
}