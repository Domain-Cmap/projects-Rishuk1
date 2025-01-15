#include <iostream> 
#include <vector> 
#include <string> 
 
using namespace std; 
 
void generateCombinations(const vector<string>& mapping, string digits, int index, string current, vector<string>& result) {     
    if (index == digits.size()) {         
        result.push_back(current);         
        return; 
    } 
    string letters = mapping[digits[index] - '0'];     
    for (char letter : letters) { 
        generateCombinations(mapping, digits, index + 1, current + letter, result); 
    } 
} 
 
vector<string> letterCombinations(string digits) {     
    if (digits.empty()) return {}; 
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};     
    vector<string> result; 
    generateCombinations(mapping, digits, 0, "", result);     return result; 
} 
 
int main() {     
    string digits; 
    cout << "Enter the digits: ";     
    cin >> digits;     
    vector<string> combinations = letterCombinations(digits); 
 
    cout << "Letter Combinations:" << endl;     
    for (const auto& combination : combinations) {         
        cout << combination << " "; 
    } 
    cout << endl; 
 
    return 0; 
} 
