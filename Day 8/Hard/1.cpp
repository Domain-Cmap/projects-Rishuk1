#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class UnionFind {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(string x, string y) {
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    UnionFind uf;
    unordered_map<string, string> emailToName;

    for (const auto& account : accounts) {
        string name = account[0];
        for (int i = 1; i < account.size(); ++i) {
            string email = account[i];
            emailToName[email] = name;

            if (i == 1) {
                continue;
            }
            uf.unionSets(account[1], email);
        }
    }

    unordered_map<string, vector<string>> mergedAccounts;
    for (const auto& pair : emailToName) {
        string rootEmail = uf.find(pair.first);
        mergedAccounts[rootEmail].push_back(pair.first);
    }

    vector<vector<string>> result;
    for (auto& pair : mergedAccounts) {
        string name = emailToName[pair.second[0]];
        pair.second.push_back(name);
        sort(pair.second.begin(), pair.second.end());
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };
    vector<vector<string>> result = accountsMerge(accounts);
    for (const auto& account : result) {
        for (const auto& email : account) {
            cout << email << " ";
        }
        cout << endl;
    }
    return 0;
}
