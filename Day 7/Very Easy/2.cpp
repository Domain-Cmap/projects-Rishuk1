#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findNumbers(int n, int sum, string current, vector<string>& result, bool isFirst) {
    if (n == 0 && sum == 0) {
        result.push_back(current);
        return;
    }
    
    if (n == 0 || sum < 0) return;
    
    for (int i = (isFirst ? 1 : 0); i <= 9; ++i) {
        findNumbers(n - 1, sum - i, current + to_string(i), result, false);
    }
}

int main() {
    int n, sum;
    cout << "Enter the length of the number (n): ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> sum;
    
    vector<string> result;
    findNumbers(n, sum, "", result, true);
    
    if (result.empty()) {
        cout << "No numbers possible" << endl;
    } else {
        cout << "Generated Numbers:" << endl;
        for (const auto& num : result)
            cout << num << " ";
        cout << endl;
    }
    
    return 0;
}
