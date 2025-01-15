#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

void backtrack(string& s, unordered_set<string>& wordDict, int start, vector<string>& path, vector<string>& result) {
    if (start == s.length()) {
        string sentence = "";
        for (const string& word : path) {
            sentence += word + " ";
        }
        sentence.pop_back(); // Remove last space
        result.push_back(sentence);
        return;
    }
    
    for (int end = start + 1; end <= s.length(); ++end) {
        string word = s.substr(start, end - start);
        if (wordDict.find(word) != wordDict.end()) {
            path.push_back(word);
            backtrack(s, wordDict, end, path, result);
            path.pop_back();
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> result;
    vector<string> path;
    backtrack(s, wordDict, 0, path, result);
    return result;
}

int main() {
    string s = "catsanddog";
    unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    
    vector<string> result = wordBreak(s, wordDict);
    
    for (const string& sentence : result) {
        cout << sentence << endl;
    }
    
    return 0;
}
