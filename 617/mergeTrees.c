/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct StackNode * ptrStackNode;
typedef ptrStackNode Stack;

struct StackNode{
    
    struct TreeNode *tree1;
    struct TreeNode *tree2;
    
    struct StackNode *next;
};


Stack createStack()
{
    Stack temp;
    
    temp = (Stack)calloc(sizeof(struct StackNode), 1);
    temp->tree1 = temp->tree2 =  NULL;
    temp->next = NULL;
    
    return temp;
}

void push(struct TreeNode *t1, struct TreeNode *t2, Stack s)
{
    ptrStackNode newNode;
    
    newNode = (ptrStackNode)calloc(sizeof(struct StackNode), 1);
    
    newNode->tree1 = t1;
    newNode->tree2 = t2;
    newNode->next = s->next;   
    s->next = newNode;
    
}

ptrStackNode pop(Stack s)
{
    
    ptrStackNode popped;
    
    popped = s->next;
    s->next = popped->next;
    
    return popped;
    
}

int isempty(Stack s)
{
    
    return (s->next == NULL ? 1 : 0);
    
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){

    Stack stk;
    ptrStackNode temp;
    
    
    if (t1 == NULL)
        return t2;
    
    stk = createStack();
    
    push(t1, t2, stk);
    
    while(isempty(stk) == 0)
    {
        temp = pop(stk);
        
        if(temp->tree1 == NULL || temp->tree2 == NULL)
            continue;
        
        temp->tree1->val += temp->tree2->val;
        
    
        if (temp->tree1->right == NULL)
            temp->tree1->right = temp->tree2->right;
        else
            push(temp->tree1->right, temp->tree2->right, stk);
        
        if (temp->tree1->left == NULL)
            temp->tree1->left = temp->tree2->left;
        else
            push(temp->tree1->left, temp->tree2->left, stk);
        
    }
        
    return t1;
    
}


