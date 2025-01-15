#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, current_end = 0, farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        if (i == current_end) {
            ++jumps;
            current_end = farthest;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {2, 3, 0, 1, 4};

    cout << jump(nums1) << endl; // Output: 2
    cout << jump(nums2) << endl; // Output: 2

    return 0;
}