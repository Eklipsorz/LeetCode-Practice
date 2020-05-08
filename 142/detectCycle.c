struct ListNode *detectCycle(struct ListNode *head) {
    
    struct ListNode *hare, *turtle;
    struct ListNode *meetnode;
    
    if (head == NULL)
        return NULL;
    
    meetnode = NULL;
    hare = turtle = head;
    
    for(; hare != NULL && hare->next != NULL;)
    {
        hare = hare->next->next;
        turtle = turtle->next;
        
        if (hare == turtle)
        {
            turtle = head;
            meetnode = hare;
            break;
        }   
    }
    
    if (meetnode == NULL)
        return NULL;
    
    for(;;)
    {
        if (turtle == hare)
            return turtle;
        
        turtle = turtle->next;
        hare = hare->next;
    }
    
    
}
