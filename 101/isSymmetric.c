/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


typedef struct Queue *queue;
typedef struct QNode *queueNode;
typedef struct TreeNode *ptrTreeNode;


struct QNode { 
    ptrTreeNode data;
    struct QNode* next; 
}; 

struct Queue { 
    struct QNode *front, *rear; 
}; 

queueNode newNode(ptrTreeNode node)
{
    queueNode temp;
    
    temp = (queueNode) calloc(sizeof(struct QNode), 1);
    temp->data = node;
    temp->next = NULL;
        
    return temp;
    
}

queue createQueue()
{
    queue temp;
    queueNode tempNode;
    
    temp = (queue) calloc(sizeof(struct Queue), 1);
    temp->rear = temp->front = NULL;
    
    return temp;
}

void EnQueue(queue q, ptrTreeNode data)
{
    queueNode temp;
    
    temp = newNode(data);
    
    if (q->front == NULL)
    { 
        q->rear = q->front = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
    
  
}



queueNode DeQueue(queue q)
{
    queueNode temp;
    
    temp = q->front;
    q->front = q->front->next;
    
    return temp->data;
}

bool isEmpty(queue q)
{
     
    return (q->front == NULL ? true : false);
}


bool isSymmetric(struct TreeNode* root){

    queue q;
    ptrTreeNode Node, othersideNode;
    
   
    
    if (root == NULL)
        return true;

    q = createQueue();
    EnQueue(q, root->left);
    EnQueue(q, root->right);
    
    
    while(isEmpty(q) == false){
        Node = DeQueue(q);
        othersideNode = DeQueue(q);
        
        if (Node == NULL && othersideNode == NULL)
            continue;
        else if (Node == NULL || othersideNode == NULL)
            return false;
        else if (Node->val != othersideNode->val)
            return false;
        
        EnQueue(q, Node->left);
        EnQueue(q, othersideNode->right);
        EnQueue(q, Node->right);
        EnQueue(q, othersideNode->left);
    }
    
    return true;    

}


