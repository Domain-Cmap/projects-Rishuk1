#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateBinaryStrings(int n, string current, vector<string>& result) {
    if (n == 0) {
        result.push_back(current);
        return;
    }
    
    generateBinaryStrings(n - 1, current + "0", result);
    generateBinaryStrings(n - 1, current + "1", result);
}

int main() {
    int n;
    cout << "Enter the length of the binary string (n): ";
    cin >> n;
    
    vector<string> result;
    generateBinaryStrings(n, "", result);
    
    for (const auto& str : result)
        cout << str << " ";
    cout << endl;
    
    return 0;
}
