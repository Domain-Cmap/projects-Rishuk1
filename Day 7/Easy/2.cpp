#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, result);
        swap(nums[start], nums[i]);  // Backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<vector<int>> permutations = permute(nums);
    cout << "All Permutations:" << endl;
    for (const auto& perm : permutations) {
        cout << "[";
        for (int i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
