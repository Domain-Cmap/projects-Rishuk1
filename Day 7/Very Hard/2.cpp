#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

void backtrack(string& current, string& endWord, unordered_set<string>& visited, unordered_set<string>& wordList, vector<vector<string>>& result, vector<string>& path) {
    if (current == endWord) {
        result.push_back(path);
        return;
    }
    
    for (int i = 0; i < current.length(); ++i) {
        char original = current[i];
        for (char c = 'a'; c <= 'z'; ++c) {
            current[i] = c;
            if (wordList.find(current) != wordList.end() && visited.find(current) == visited.end()) {
                visited.insert(current);
                path.push_back(current);
                backtrack(current, endWord, visited, wordList, result, path);
                path.pop_back();
            }
        }
        current[i] = original; // Restore character
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
    vector<vector<string>> result;
    if (wordList.find(endWord) == wordList.end()) return result;
    
    unordered_set<string> visited;
    visited.insert(beginWord);
    
    vector<string> path = {beginWord};
    backtrack(beginWord, endWord, visited, wordList, result, path);
    
    return result;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> result = findLadders(beginWord, endWord, wordList);
    
    for (const auto& seq : result) {
        for (const auto& word : seq) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
