#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* SortedArrayToBST(int nums[] ,int left,int right){
    if(left>right) 
    return NULL;
    int mid = left + (right-left)/2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = SortedArrayToBST(nums,left,mid-1);
    root->right = SortedArrayToBST(nums,mid+1,right);
    return root;
}

void inOrderTraversal(TreeNode* root){
    if(root == NULL)
    return;
    inOrderTraversal(root->left);
    cout<<root->val<<" ";
    inOrderTraversal(root->right);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    TreeNode* root = SortedArrayToBST(arr,0,n-1);
    inOrderTraversal(root);
    cout<<endl;


    return 0;
}