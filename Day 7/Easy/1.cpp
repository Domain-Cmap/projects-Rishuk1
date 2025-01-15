#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findPaths(TreeNode* node, string currentPath, vector<string>& paths) {
    if (!node) return;
    currentPath += to_string(node->val);
    if (!node->left && !node->right) {
        paths.push_back(currentPath);
        return;
    }
    currentPath += "->";
    findPaths(node->left, currentPath, paths);
    findPaths(node->right, currentPath, paths);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    findPaths(root, "", paths);
    return paths;
}

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    vector<TreeNode*> level{root};
    int i = 1;
    while (i < nodes.size()) {
        vector<TreeNode*> nextLevel;
        for (auto node : level) {
            if (i < nodes.size() && nodes[i] != "null") {
                node->left = new TreeNode(stoi(nodes[i]));
                nextLevel.push_back(node->left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != "null") {
                node->right = new TreeNode(stoi(nodes[i]));
                nextLevel.push_back(node->right);
            }
            i++;
        }
        level = nextLevel;
    }
    return root;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<string> nodes(n);
    cout << "Enter the nodes (use 'null' for no node): ";
    for (int i = 0; i < n; ++i) cin >> nodes[i];
    TreeNode* root = buildTree(nodes);
    vector<string> paths = binaryTreePaths(root);
    cout << "Root-to-Leaf Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }
    return 0;
}
