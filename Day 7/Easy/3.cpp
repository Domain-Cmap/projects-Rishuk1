#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);  // Add the current subset to the result
        return;
    }
    generateSubsets(nums, index + 1, current, result);  // Exclude the current element
    current.push_back(nums[index]);  // Include the current element
    generateSubsets(nums, index + 1, current, result);  // Explore the next elements with the current element included
    current.pop_back();  // Backtrack and remove the last element
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, 0, current, result);  // Start generating subsets from index 0
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<vector<int>> result = subsets(nums);  // Get all subsets
    cout << "All Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
