
struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode *prev=NULL,*next=NULL;
    
    while(head){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;

}

