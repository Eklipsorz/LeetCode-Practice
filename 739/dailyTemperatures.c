

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct stackNode stackNode;
typedef stackNode *stack;

struct stackNode{
    int val;
    struct stackNode *next;
};

stack createStack(){
    
    stack tmp;
    
    tmp = (stack) calloc(sizeof(stackNode), 1);
    tmp->next = NULL;
    
    return tmp;
}

void push(stack stk, int val){
    stackNode *tmp;
    
    tmp = (stackNode *)calloc(sizeof(stackNode), 1);
    tmp->val = val;
    tmp->next = stk->next;
    stk->next = tmp;

}

int pop(stack stk){
    
    stackNode *tmp;
    tmp = stk->next;
    stk->next = tmp->next;
    
    return tmp;
}

int peek(stack stk){
    return stk->next->val;
}

bool isEmpty(stack stk){
    return (stk->next == NULL) ? true : false;
}

void showElement(stack s){
    
    stackNode *tmp;
    
    tmp = s->next;
    printf("round:\n");
    for(;tmp != NULL; tmp = tmp->next)
        printf("%d\n", tmp->val);
    
}


int* dailyTemperatures(int* T, int TSize, int* returnSize){
    
    stack stk;
    int i, *ans;
    
    
    stk = createStack();
    ans = (int *)calloc(sizeof(int), TSize);
    *returnSize = TSize;
    
    for (i = TSize - 1; i >= 0; i--){
        
        while (isEmpty(stk) != true && T[i] >= T[peek(stk)])
            pop(stk);
   
        ans[i] = isEmpty(stk) == true ? 0 : peek(stk) - i;
        push(stk, i);
    }
    
    return ans;
    
    
    
}
