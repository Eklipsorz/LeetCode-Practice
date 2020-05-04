

typedef struct StackNode Node;

struct StackNode {
    int val;
    struct StackNode *next;
};

typedef struct {
    Node *min;
    Node *origin;
} MinStack;

/** initialize your data structure here. */


MinStack* minStackCreate() {
    
    MinStack *mstack;
    Node *tempMin, *tempOrigin;
    
    mstack = (MinStack *) calloc(sizeof(MinStack), 1);
    tempMin = (Node *) calloc(sizeof(Node), 1);
    tempOrigin = (Node *) calloc(sizeof(Node), 1);
    
    tempMin->next = tempOrigin->next = NULL;
    
    mstack->min = tempMin;
    mstack->origin = tempOrigin;
    
    return mstack;
}

void minStackPush(MinStack* obj, int x) {
    
    Node *newOriginNode, *newMinNode;
    
    newOriginNode = (Node *) calloc(sizeof(Node), 1);
    newOriginNode->val = x;
    newOriginNode->next = obj->origin->next;
    obj->origin->next = newOriginNode;
    
    newMinNode = (Node *) calloc(sizeof(Node), 1);
    newMinNode->next = obj->min->next;
    
        
    if (obj->min->next == NULL || obj->min->next->val > x)
        newMinNode->val = x;
    else
        newMinNode->val = obj->min->next->val;
    obj->min->next = newMinNode;
}

void minStackPop(MinStack* obj) {
    
    Node *tempOrigin, *tempMin;
    
    tempOrigin = obj->origin->next;
    tempMin = obj->min->next;
    
    obj->origin->next = tempOrigin->next;
    obj->min->next = tempMin->next;
    
    free(tempOrigin);
    free(tempMin);
}


int minStackTop(MinStack* obj) {
    return obj->origin->next->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->min->next->val;
}

void minStackFree(MinStack* obj) {
    
    Node *tempOrigin, *tempMin;
    
    
    for(; obj->origin->next != NULL;)
    {
        
        tempOrigin = obj->origin->next;
        tempMin = obj->min->next;
        
        obj->origin->next = tempOrigin->next;
        obj->min->next = tempMin->next;
        
        free(tempOrigin);
        free(tempMin);
        
    }
   
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
