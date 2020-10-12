#include <vector>
using namespace std;

// Questions
//---------------------------------
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return
// the median of the two sorted arrays.

// Follow up: The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// Example 3:

// Input: nums1 = [0,0], nums2 = [0,0]
// Output: 0.00000
// Example 4:

// Input: nums1 = [], nums2 = [1]
// Output: 1.00000
// Example 5:

// Input: nums1 = [2], nums2 = []
// Output: 2.00000

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int median_index = (nums1.size() + nums2.size()) / 2;
    vector<int> median_indexes = {};
    if (median_index * 2 != nums1.size() + nums2.size()) {
      median_indexes = {median_index, median_index};
    } else {
      median_indexes = {median_index - 1, median_index};
    }

    vector<int> one_vector = {};
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < nums1.size() + nums2.size(); i++) {
      if (index1 == nums1.size()) {
        one_vector.insert(one_vector.end(), nums2.begin() + index2,
                          nums2.end());
        break;
      } else if (index2 == nums2.size()) {
        one_vector.insert(one_vector.end(), nums1.begin() + index1,
                          nums1.end());
        break;
      } else {
        if (nums1[index1] <= nums2[index2]) {
          one_vector.push_back(nums1[index1]);
          index1++;
        } else if (nums2[index2] < nums1[index1]) {
          one_vector.push_back(nums2[index2]);
          index2++;
        }
      }
    }

    return ((double)one_vector[median_indexes[0]] +
            (double)one_vector[median_indexes[1]]) /
           2;
  }
};
