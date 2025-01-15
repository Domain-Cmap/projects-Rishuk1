#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    
    // Swap the left and right subtrees
    swap(root->left, root->right);
    
    // Recursively invert the subtrees
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    TreeNode* inverted = invertTree(root);
    
    // Output the inverted tree's root value as an example
    cout << "Root of inverted tree: " << inverted->val << endl;
    return 0;
}
