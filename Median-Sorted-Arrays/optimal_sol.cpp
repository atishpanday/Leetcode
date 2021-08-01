#include <iostream>
#include <vector>

class Solution{
public:
  double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2){
    int mid = (nums1.size() + nums2.size() + 1) / 2;
    bool evensized = (nums1.size() + nums2.size()) % 2 == 0;
    int nums1ptr = 0;
    int nums2ptr = 0;
    double median = 0;
    bool secondMedian = false;
    while (mid != 0){
      mid--;
      if (nums1ptr >= nums1.size()){
        if (mid <= 0){
          median += nums2[nums2ptr];
        }
        nums2ptr++;
      } else if (nums2ptr >= nums2.size()){
        if (mid <= 0){
          median += nums1[nums1ptr];
        }
        nums1ptr++;
      } else if (nums2ptr >= nums2.size() || nums1[nums1ptr] <= nums2[nums2ptr]){
        if (mid <= 0){
          median += nums1[nums1ptr];
        }
        nums1ptr++;
      } else{
        if (mid <= 0){
          median += nums2[nums2ptr];
        }
        nums2ptr++;
      } if (secondMedian)
        return median / 2;
      if (evensized && mid <= 0){
        mid++;
        secondMedian = true;
      }
    }
    return median;
  }
};

int main(){
  Solution sol;
  std::vector<int> A1 = {1, 2, 4};
  std::vector<int> A2 = {2, 4, 5};
  std::cout << "The median is: " << sol.findMedianSortedArrays(A1, A2);
  return 0;
}