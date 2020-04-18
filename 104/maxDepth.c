/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int maxDepth(struct TreeNode* root){

    int rightNode, leftNode, maxNode;
    
    if (root == NULL)
        return 0;
    else
    {
        leftNode = maxDepth(root->left);
        rightNode = maxDepth(root->right);
        
        maxNode = leftNode > rightNode ? leftNode : rightNode;
        
        return maxNode + 1;
        
    }
}


