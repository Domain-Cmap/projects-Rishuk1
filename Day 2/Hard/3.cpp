#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *right, *down;
    int val;
    Node(Node *right, Node *down, int val): right(right), down(down), val(val) {}
};

class Skiplist {
    Node* head;
    vector<Node*> insertPoints;

public:
    Skiplist() {
        head = new Node(NULL, NULL, 0);
    }

    bool search(int num) {
        Node *p = head;
        while (p) {
            while (p->right && p->right->val < num) p = p->right;
            if (!p->right || p->right->val > num) p = p->down;
            else return true;
        }
        return false;
    }

    void add(int num) {
        insertPoints.clear();
        Node *p = head;
        while (p) {
            while (p->right && p->right->val < num) p = p->right;
            insertPoints.push_back(p);
            p = p->down;
        }

        Node* downNode = NULL;
        bool insertUp = true;
        while (insertUp && !insertPoints.empty()) {
            Node *ins = insertPoints.back();
            insertPoints.pop_back();

            ins->right = new Node(ins->right, downNode, num);
            downNode = ins->right;

            insertUp = (rand() & 1) == 0;
        }
        if (insertUp) {
            head = new Node(new Node(NULL, downNode, num), head, 0);
        }
    }

    bool erase(int num) {
        Node *p = head;
        bool seen = false;
        while (p) {
            while (p->right && p->right->val < num) p = p->right;
            if (!p->right || p->right->val > num) p = p->down;
            else {
                seen = true;
                p->right = p->right->right;
                p = p->down;
            }
        }
        return seen;
    }
};

int main() {
    Skiplist skiplist;
    skiplist.add(1);
    skiplist.add(2);
    skiplist.add(3);

    cout << boolalpha;
    cout << skiplist.search(0) << endl; // false
    skiplist.add(4);
    cout << skiplist.search(1) << endl; // true
    cout << skiplist.erase(0) << endl; // false
    cout << skiplist.erase(1) << endl; // true
    cout << skiplist.search(1) << endl; // false

    return 0;
}