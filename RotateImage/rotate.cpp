class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int temp = 0;
        for(int i=0; i<size; i++){
            for(int j=i; j<size-i-1; j++){
                temp = matrix[size-j-1][i];
                matrix[size-j-1][i] = matrix[size-i-1][size-j-1];
                matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
                matrix[j][size-i-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};

// A[i][j] --> A[i][size-j-1]

// i,j          i,j+1           i,j+2           ...
// i+1,j        i+1,j+1         i+1,j+2         ...

// i,i --> i,size-i-1
// i,size-i-1 --> size-i-1,size-i-1
// size-i-1,size-i-1 --> i,i

// 1    2   3
// 4    5   6
// 7    8   9

// 9    4   7
// 8    5   2
// 3    6   1