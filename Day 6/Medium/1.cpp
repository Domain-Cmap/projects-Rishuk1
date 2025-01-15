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
    int preorder_index = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        
        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);
        
        root->left = buildTreeHelper(preorder, left, inorder_map[root_val] - 1);
        root->right = buildTreeHelper(preorder, inorder_map[root_val] + 1, right);
        
        return root;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    
    TreeNode* root = sol.buildTree(preorder, inorder);
    
    cout << "Root of constructed tree: " << root->val << endl;
    return 0;
}
