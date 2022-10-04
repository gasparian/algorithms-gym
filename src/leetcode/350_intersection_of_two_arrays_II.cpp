#include <bits/stdc++.h>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    std::vector<int> intersection;
    while ( (i < (int)nums1.size()) && (j < (int)nums2.size()) ) {
        if ( nums1[i] == nums2[j] ) {
            intersection.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
    
    return intersection;
}

int main() {
    // [1,2,2,1] [2,2] --> [2,2]
    return 0;
}