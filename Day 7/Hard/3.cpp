#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 
 
vector<int> grayCode(int n) {     
    vector<int> result;     
    int total = 1 << n; // 2^n     
    for (int i = 0; i < total; ++i) {         
        result.push_back(i ^ (i >> 1)); 
    }     
    return result; 
} 
 
int main() {     
    int n; 
    cout << "Enter the number of bits (n): ";     
    cin >> n; 
 
    vector<int> result = grayCode(n); 
 
    cout << "Gray Code Sequence:" << endl;     
    for (int code : result) {         
        cout << code << " "; 
    } 
    cout << endl; 
 
    return 0; 
}     