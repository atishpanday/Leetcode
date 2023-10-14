class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.length()) {
            return s;
        }

        int cycleLen = 2 * (numRows - 1);
        int n = s.length();
        string res;

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; i + j < n; j += cycleLen) {
                res += s[i + j];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    res += s[j + cycleLen - i];
                }
            }
        }
        return res;
    }
};
