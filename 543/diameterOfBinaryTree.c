/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int ans = 0; 


int maxLenth(struct TreeNode *root){
    
    int rightNode, leftNode, maxNode;
    int sumnode;
    
    if (root == NULL)
        return 0;
    else
    {
        leftNode = maxLenth(root->left);
        rightNode = maxLenth(root->right);
        
        maxNode = leftNode > rightNode ? leftNode : rightNode;
        
        sumnode = leftNode + rightNode;
        if (sumnode > ans)
            ans = sumnode;     
        return maxNode + 1 ;
        
    }
    
}

int diameterOfBinaryTree(struct TreeNode* root){

    ans = 0;
    maxLenth(root);
    
    return ans;
}


