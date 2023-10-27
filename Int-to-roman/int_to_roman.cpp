class Solution {
public:
    string intToRoman(int num) {
        string roman = "";

        for(int i = 0; i < (num / 1000); i++) {
            roman += "M";
        }

        roman += rom("", num % 1000, 100, "C", "D", "M");

        roman += rom("", num % 100, 10, "X", "L", "C");

        roman += rom("", num % 10, 1, "I", "V", "X");

        return roman;
    }

    string rom(string roman, int num, int mul, string st, string mi, string en) {
        int lim1 = 4*mul, lim2 = 5*mul, lim3 = 9*mul;

        if(num >= lim1 && num < lim3) {
            if(num >= lim2) {
                roman += mi;
                for(int i = 0; i < (num / mul) - 5; i++) {
                    roman += st;
                }
            }
            else {
                roman += st + mi;
            }
        }
        else if(num < lim1) {
            for(int i = 0; i < (num / mul); i++) {
                roman += st;
            }
        }
        else {
            roman += st + en;
        }
        return roman;
    }
};

// 1500 = MD
// 200 = CC
// 3000 = MMM
// 600 = DC
// 400 = CD
// 1660 = MCDLX

// Basically our approach is to take each case separately: 100 to 300, 400 to 800 and 900.