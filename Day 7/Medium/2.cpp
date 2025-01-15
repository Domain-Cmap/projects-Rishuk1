#include <iostream> 
#include <vector> 
#include <string> 
 
using namespace std; 
 
void generateParentheses(int open, int close, string current, vector<string>& result) {     
    if (open == 0 && close == 0) {         
        result.push_back(current);         
        return;     
    }     
    if (open > 0) { 
        generateParentheses(open - 1, close, current + "(", result); 
    } 
    if (close > open) { 
        generateParentheses(open, close - 1, current + ")", result); 
    } 
} 
 
vector<string> generateParentheses(int n) {     
    vector<string> result;     
    generateParentheses(n, n, "", result);     
    return result; 
} 
 
int main() {     
    int n;     
    cout << "Enter the number of pairs of parentheses: ";     
    cin >> n; 
 
    vector<string> combinations = generateParentheses(n); 
 
    cout << "Well-formed Parentheses Combinations:" << endl;     
    for (const auto& combination : combinations) {         
        cout << combination << endl; 
    }     
    return 0; 
} 
