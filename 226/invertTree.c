/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){

    struct TreeNode* leftNode, *rightNode;

    
    if (root == NULL)
        return NULL;
    else
    {
        leftNode = invertTree(root->left);
        rightNode = invertTree(root->right);
        
        root->left = rightNode;
        root->right = leftNode;
        
        
        return root;
    }
    
    
    
}


