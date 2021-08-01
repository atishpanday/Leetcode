#include<iostream>
#include<vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> mergArr(nums1.size()+nums2.size(),0);
    int i = 0, j = 0, k = 0;
    while(i<nums1.size() || j<nums2.size()){
      if(j == nums2.size()){
        mergArr[k] = nums1[i];
        i++;
      } else if(i == nums1.size()){
        mergArr[k] = nums2[j];
        j++;
      } else if(nums1[i] < nums2[j]){
        mergArr[k] = nums1[i];
        i++;
      } else {
        mergArr[k] = nums2[j];
        j++;
      }
      k++;
    }
    int midLeft = (mergArr.size() - 1) / 2;
    int midRight = (mergArr.size()) / 2;
    double med = (double) (mergArr[midLeft] + mergArr[midRight])/2 ;
    return med;
  }
};

int main(){
  Solution sol;
  std::vector<int> Ar1 = {1,3,4};
  std::vector<int> Ar2 = {2,2,5};
  std::cout << "The median is: " << sol.findMedianSortedArrays(Ar1, Ar2);
}