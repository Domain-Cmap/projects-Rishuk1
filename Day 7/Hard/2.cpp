#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 
 
bool isValidPart(const string& part) { 
    if (part.empty() || part.size() > 3 || (part[0] == '0' && part.size() > 1) || stoi(part) > 255) {         
        return false; 
    }     
    return true; 
} 
 
void restore(string s, int index, vector<string>& path, vector<string>& result) {     
    if (path.size() == 4) { 
        if (index == s.size()) { 
            result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]); 
        }         return; 
    } 
    for (int len = 1; len <= 3 && index + len <= s.size(); ++len) {         
        string part = s.substr(index, len);         
        if (isValidPart(part)) {             
            path.push_back(part);             
            restore(s, index + len, path, result);             
            path.pop_back(); 
        } 
    }} 
vector<string> restoreIpAddresses(string s) {     
    vector<string> result;     
    vector<string> path;     
    restore(s, 0, path, result);     
    return result; 
} int main() {     
    string s; 
    cout << "Enter the string: ";     
    cin >> s; 
    vector<string> ipAddresses = restoreIpAddresses(s);     
    cout << "Valid IP Addresses:" << endl;     
    for (const auto& ip : ipAddresses) {         
        cout << ip << endl; 
   } return 0; 
} 
