#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true; // Both are null
    if (!left || !right) return false; // One is null, the other isn't
    if (left->val != right->val) return false; // Values don't match
    
    // Recursively check the subtrees
    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetricHelper(root->left, root->right);
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    cout << "Is the tree symmetric? " << (isSymmetric(root) ? "True" : "False") << endl;
    return 0;
}
