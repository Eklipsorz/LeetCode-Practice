struct ListNode * complement(struct ListNode *head, int count){
    
    for(;count > 0; count--)
        head = head->next;
    
    return head;
    
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode *tempA, *tempB;
    int countListA, countListB, diff;
    
    countListA = countListB = 0;
    tempA = headA;
    


    while (tempA != NULL){
        tempA = tempA->next;
        countListA++;
    }
    
    tempB = headB;

    while (tempB != NULL){
        tempB = tempB->next;
        countListB++;        
    }
  
    diff = (countListA > countListB) ? countListA - countListB : countListB - countListA;
    
    if (countListA > countListB)
    { 
        tempA = complement(headA, diff);
        tempB = headB;
    }
    else if (countListA < countListB)
    {
      
        tempB = complement(headB, diff);
        tempA = headA;
    }
    else
    {
        tempA = headA;
        tempB = headB;
    }
    

   
    while(tempA != NULL)
    {
        if (tempA == tempB)
            return tempA;
        tempA = tempA->next;
        tempB = tempB->next;
        
    }
    
    return NULL;
    
}
