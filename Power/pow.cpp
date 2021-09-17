#include<iostream>

using namespace std;

class Solution {
public:
double pow(double x, long long n) {
    double p = x, tot = 1;
    while(n) {
        if(n & 1) tot *= p;
        p *= p;
        n >>= 1;
    }
    return tot;
}
double myPow(double x, int cn) {
    long long n = cn;
    if(x == 1.00) return 1;
    if(n < 0) return (double) 1.00 / pow(x, abs(n));
    return pow(x, abs(n));
}
};

int main(){
    Solution sol;
    cout << sol.myPow(5, 3);
}