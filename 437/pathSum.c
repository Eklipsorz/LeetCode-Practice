/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int solu2Node(struct TreeNode* root, int sum)
{
    
    int target, isSame;
    int subsolOfleft, subsolOfright;
    
    if (root ==  NULL)
        return 0;
    else
    {
        target = sum - root->val;

        
        isSame = (target == 0);
        subsolOfleft = solu2Node(root->left, target);
        subsolOfright = solu2Node(root->right, target);
        
        return isSame + subsolOfleft + subsolOfright; 
    }

}

int pathSum(struct TreeNode* root, int sum){
    
    int center, left, right;
    
    if (root == NULL)
        return 0;
    else
    {
        center = solu2Node(root, sum);
        left = pathSum(root->left, sum);
        right = pathSum(root->right, sum);
        
        return center + left + right;
    }

    

}


