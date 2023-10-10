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

/*
# j=0   # j=c   # j=2c and so on
#     # #     #
#   #   #   #
# #     # #
#       #

j goes like 0, cycleLen, 2*cycleLen and so on.
Each cycleLen is the peak of the input string in zigzag form
The length of cycleLen is 2*(numRows - 1), we count from peak to valley 
and back to peak - 1
i goes from 0 to numRows - 1
So when i = 0, we go from one column to next with j increasing by 1 cycleLen
At each cycleLen, we check if it is not the peak or the valley, then we have to
take care of the diagonal characters. Here we make the check:
    (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
This checks whether our i is not at the extremes of the column, and also checks if
our index is not out of bounds (< n)

Then, j + cycleLen - i is simply the character at the ith row on the diagonal.
*/