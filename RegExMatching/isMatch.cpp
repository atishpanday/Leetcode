#include<iostream>
#include<string.h>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if(s[0] != p[0]){
            if(s.size() > 1 && p.size() > 1){
                if(p[1] == '*') p.size() > 2 ? isMatch(s.substr(0), p.substr(2)) : return false;
                else if(p[0] == '*') isMatch(s.substr(0), p.substr(1));
                else if(p[0] == '.') isMatch(s.substr(1), p.substr(1));
                else return false;
            }
            else if(s.size() == 1 && p.size() > 1){
                if(p[0] )
            }
        } 
        else{ 
            if(s.size() > 1 && p.size() > 1) isMatch(s.substr(1), p.substr(1));
            else if(s.size() == 1 && p.size() == 1) return true;
        }
    }
};

int main(){
    Solution sol;
    std::cout<<sol.isMatch("abcd", "a*bc*d");
    return 0;
}

// s.size() > 0 && p.size() > 0 --> if s[] != p[] --> various checks --> if checks pass, continue else return false
// s.size() > 0 && p.size() == 0 --> return false
// s.size() == 0 && p.size() > 0 --> p.substr() == '' --> return true else return false
// s.size() == 0 && p.size() == 0 --> return true

// s = abb
// p = ab*b

// bb, b*c* --> 