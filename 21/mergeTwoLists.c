/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void addNewNode(struct ListNode **tail, struct ListNode **head, struct ListNode * node)
{
    if (*head == NULL)
    {
        *head = node;
        *tail = node;
    }
    else
    {  
        (*tail)->next = node;
        (*tail) = node;
    }
    
    
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
        
        struct ListNode *head, *tail;
        struct ListNode *tempL1, *tempL2;
    
        head = tail = NULL;
        tempL1 = l1;
        tempL2 = l2;
    
        while (tempL1 != NULL && tempL2 != NULL)
        {
                if (tempL1->val > tempL2->val)
                {
                    addNewNode(&tail, &head, tempL2);
                    tempL2 = tempL2->next;
                }
                else
                {
                    addNewNode(&tail, &head, tempL1);
                    tempL1 = tempL1->next;
                }
                
                
        }

        
        for (; tempL1 != NULL; tempL1 = tempL1->next)
            addNewNode(&tail, &head, tempL1);
    
        for (; tempL2 != NULL; tempL2 = tempL2->next)
            addNewNode(&tail, &head, tempL2);
    
        return head;
}


