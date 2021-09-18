#include<iostream>
#include<vector>
#include<string.h>

class Solution {
public:
    vector<string> answer;
    vector<string> addOperators(string num, int target) {
        insertOp(num, "", 0, target);
        return answer;
    }
    
    void insertOp(string num, string op, int curr, int target){
        if(curr < num.length()){
            num.insert(curr+1, op);
            insertOp(num, "", curr+2, target);
            insertOp(num, "+", curr+2, target);
            insertOp(num, "-", curr+2, target);
            insertOp(num, "*", curr+2, target);
        }
        else{
            int length = num.length();
            int temp;
            char oper;
            int eval = 0;
            for(int i=0; i<length; i++){
                if(num[i]=='*' || num[i]=='+' || num[i]=='-'){
                    oper=num[i];
                    i++;
                    temp=0;
                    while(num[i] != '*' && num[i] != '+' && num[i] != '-' && i < length){
                        temp = temp*10 + stoi(""+num[i]);
                        i++;
                    }
                    if(oper=='*') eval *= temp;
                    else if(oper=='+') eval += temp;
                    else eval -= temp;
                }
                else eval = eval*10 + stoi(""+num[i]);
            }
            if(eval == target){
                answer.push_back(num);
            }
            return;
        }
    }
};

int main(){
    Solution sol;
    string num = "123";
    int target = 6;
    vector<string> finalAnswer = sol.addOperators(num, target);
    return 0;
}