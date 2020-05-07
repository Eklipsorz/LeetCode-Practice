/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    struct ListNode *hare, *turtle;
    
    if (head == NULL)
        return false;
    
    hare = turtle = head;
    
    for(; hare != NULL && hare->next != NULL; )
    {
        hare = hare->next->next;
        turtle = turtle->next;
        
        if (hare == turtle)
            return true;
    }
    
    return false;
    
}
