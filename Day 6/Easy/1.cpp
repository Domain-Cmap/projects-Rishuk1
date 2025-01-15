#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true; // Both are null
    if (!p || !q) return false; // One is null, the other isn't
    if (p->val != q->val) return false; // Values don't match
    
    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Example usage
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    cout << "Are the trees the same? " << (isSameTree(p, q) ? "True" : "False") << endl;
    return 0;
}
