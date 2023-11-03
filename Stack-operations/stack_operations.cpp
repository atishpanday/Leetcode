class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 1;
        vector<string> stack;

        for(int num:target) {
            while(i < num) {
                stack.push_back("Push");
                stack.push_back("Pop");
                i++;

            }
            stack.push_back("Push");
            i++;
        }
        return stack;
    }
};