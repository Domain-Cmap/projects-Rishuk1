#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> inorder_map;
    int postorder_index;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_index = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        int root_val = postorder[postorder_index--];
        TreeNode* root = new TreeNode(root_val);

        root->right = buildTreeHelper(inorder, postorder, inorder_map[root_val] + 1, right);
        root->left = buildTreeHelper(inorder, postorder, left, inorder_map[root_val] - 1);

        return root;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    
    TreeNode* root = sol.buildTree(inorder, postorder);
    
    cout << "Root of constructed tree: " << root->val << endl;
    return 0;
}
