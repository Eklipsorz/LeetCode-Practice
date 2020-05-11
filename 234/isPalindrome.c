struct ListNode * reverse(struct ListNode *head){
    
    struct ListNode *curr, *prev, *next;
    
    prev = NULL;
    curr = head;
    
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

bool Compare2Lists(struct ListNode *list1, struct ListNode *list2){
    
    struct ListNode *temp1, *temp2, *end;
    
    temp1 = list1, temp2 = list2;
    end = list2;
    
    while (temp1 != NULL){
        
        if (temp1->val != temp2->val)
            return false;   
        
        temp1 = temp1->next;
        temp2 = temp2->next;
        
        
    }
   
    return true;
       
}



bool isPalindrome(struct ListNode* head){

    struct ListNode *hare, *middle, *prevmiddle,*secondList;
    bool res = true;
    
    if (head == NULL || head->next == NULL)
        return res;

    middle = hare = head;
    
    while (hare != NULL && hare->next != NULL){
        
        hare = hare->next->next;
        prevmiddle = middle;
        middle = middle->next;
        
    }
    
    prevmiddle->next = NULL;
    secondList = reverse(middle);
    res = Compare2Lists(head, secondList);
    
    return res;
    
}
