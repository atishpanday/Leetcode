// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         if(n == 0) {
//             return 0;
//         }
//         int l = 0;
//         int r = 1;

//         int max_area = 0;
//         int larea = 0;
//         int rarea = 0;
//         int com_area = 0;

//         while(r < n - 1) {
//             larea = std::min(height[l], height[r]) * (r - l);
//             rarea = std::min(height[l+1], height[r+1]) * (r - l);
//             com_area = std::min(height[l], height[r+1]) * (r - l + 1);
//             if(com_area >= larea && com_area >= rarea) {
//                 max_area = com_area;
//             }
//             else if(larea < rarea && height[l] < height[l+1]) {
//                 l++;
//                 max_area = rarea;
//             }
//             r++;
//         }

//         if(max_area < std::min(height[l], height[r]) * (r - l)) {
//             max_area = std::min(height[l], height[r]) * (r - l);
//         }

//         return max_area;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        if(n == 0) {
            return 0;
        }

        int l = 0;
        int r = n - 1;

        int max_area = 0;
        int curr_area = 0;

        while(l <= r) {
            curr_area = std::min(height[l], height[r]) * (r - l);
            if(max_area < curr_area) {
                max_area = curr_area;
            }

            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return max_area;
    }
};

