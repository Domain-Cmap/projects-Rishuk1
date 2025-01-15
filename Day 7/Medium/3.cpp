#include <iostream> 
#include <vector> 
using namespace std; 
 
void findCombinations(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {     if (target == 0) {         result.push_back(current);         return; 
    } 
    if (target < 0) return; 
 
    for (int i = index; i < candidates.size(); ++i) {         current.push_back(candidates[i]); 
        findCombinations(candidates, target - candidates[i], i, current, result);         current.pop_back(); 
    } 
} 
 
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {     vector<vector<int>> result;     vector<int> current; 
    findCombinations(candidates, target, 0, current, result);     return result; 
} 
 
int main() {     
    int n, target; 
    cout << "Enter the number of candidates: ";     
    cin >> n;     
    vector<int> candidates(n);     
    cout << "Enter the candidates: ";     
    for (int i = 0; i < n; ++i) 
        cin >> candidates[i];     
    cout << "Enter the target: ";     
    cin >> target; 
 
    vector<vector<int>> combinations = combinationSum(candidates, target); 
 
    cout << "Combinations that sum to target:" << endl;     
    for (const auto& combination : combinations) {         
        cout << "["; 
        for (int i = 0; i < combination.size(); ++i) {             
            cout << combination[i]; 
            if (i < combination.size() - 1) 
                cout << ","; 
        } 
        cout << "]" << endl; 
    } 
 
    return 0; 
}
