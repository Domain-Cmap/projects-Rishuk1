#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                if (i < size - 1) {
                    node->next = q.front();  // Point to the next node in the queue
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};

// Example usage
int main() {
    Solution sol;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    sol.connect(root);
    // The tree is now populated with next pointers, you can print or verify it if needed.
    return 0;
}
