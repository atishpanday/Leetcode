class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k == 1) {
            return 0;
        }

        int l = pow(2, n - 2); // take half the total length of nth row

        int fl = 0; // set initial value to 0

        while(l > 0) {
            if(k > l) {
                k -= l;
                fl = fl == 0 ? 1 : 0;
            }
            l /= 2;
        }

        return fl;
    }
};

// 0
// 01
// 0110
// 01101001
// 0110100110010110

// dir = 0, fl = 0 --> dir = 0, fl = 0 --> dir = 0, fl = 0
// dir = 0, fl = 0 --> dir = 0, fl = 0 --> dir = 1, fl = 1
// dir = 0, fl = 0 --> dir = 1, fl = 1 --> dir = 0, fl = 1
// dir = 0, fl = 0 --> dir = 1, fl = 1 --> dir = 1, fl = 0
// dir = 1, fl = 1 --> dir = 0, fl = 1 --> dir = 0, fl = 1
// dir = 1, fl = 1 --> dir = 0, fl = 1 --> dir = 1, fl = 0
// dir = 1, fl = 1 --> dir = 1, fl = 0 --> dir = 0, fl = 0
// dir = 1, fl = 1 --> dir = 1, fl = 0 --> dir = 1, fl = 1