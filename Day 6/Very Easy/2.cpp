#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeightLeft(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int getHeightRight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;

    int leftHeight = getHeightLeft(root);
    int rightHeight = getHeightRight(root);

    if (leftHeight == rightHeight) {
        return pow(2, leftHeight) - 1;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Number of nodes: " << countNodes(root) << endl;
    return 0;
}
