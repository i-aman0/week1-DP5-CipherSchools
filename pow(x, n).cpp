#include<iostream>
using namespace std;

double solve(double x, long n){
        if(n==0){
            return double(1);
        }
        if(n==1){
            return x;
        }

        double ans=solve(x, n/2);

        if(n%2==0){
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
    }

double myPow(double x, long n) {
    if(n<0){
        x=1/x;
        n=-1*n;
    }

    return solve(x, n);
}

int main()
{
    cout << myPow(2.0, 10) << endl;
    return 0;
}