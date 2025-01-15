#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_set<int> needTeach;
        unordered_map<int, int> languageCount;

        for (const vector<int>& friendship : friendships) {
            const int u = friendship[0] - 1;
            const int v = friendship[1] - 1;
            if (u >= languages.size() || v >= languages.size()) continue; // Check for valid indices
            if (cantTalk(languages, u, v)) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        for (const int u : needTeach)
            for (const int language : languages[u])
                ++languageCount[language];

        int maxCount = 0;
        for (const auto& [_, freq] : languageCount)
            maxCount = max(maxCount, freq);

        return needTeach.size() - maxCount;
    }

private:
    bool cantTalk(const vector<vector<int>>& languages, int u, int v) {
        for (const int language : languages[u])
            if (find(languages[v].begin(), languages[v].end(), language) != languages[v].end())
                return false;
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> languages = {{1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> friendships = {{1, 2}, {2, 3}, {3, 4}, {1, 4}};
    int n = 4;
    cout << solution.minimumTeachings(n, languages, friendships) << endl;
    return 0;
}