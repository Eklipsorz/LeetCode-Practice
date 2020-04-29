

typedef struct listNode * position;
typedef struct HashTab * htab;
typedef position list;

struct listNode{
    int val;
    int pos;
    struct listNode *next;
};

struct HashTab{
    int tabsize;
    list * thelist;
};

int hashcode(int val)
{
    return (val > 0 ? val % 10 : (-1 * val) % 10);    
}

htab createHashTab(int size)
{
    int i;
    htab temp;    
    
    temp = (htab) calloc(sizeof(struct HashTab), 1);
    temp->tabsize = size;
    temp->thelist = (list *) calloc(sizeof(list), size);
    
    for(i = 0; i < size; i++)
    {
        temp->thelist[i] = (struct listNode *) calloc(sizeof(struct listNode), 1);
        temp->thelist[i]->next = NULL;
    }
    
    return temp;
}


void insert2htab(htab h, int val, int pos)
{
    position newNode, temp; 

    newNode = (position) calloc(sizeof(struct listNode), 1);
    newNode->val = val;
    newNode->pos = pos;
    
  
    temp = h->thelist[hashcode(val)];
    newNode->next = temp->next;
    temp->next =newNode;
    
}

int find(htab h, int val, int pos)
{
    position temp;
    
    temp = h->thelist[hashcode(val)]->next;
    
    for(; temp != NULL; temp = temp->next)
    {
        if (temp->val == val && temp->pos != pos)
            return temp->pos;
    }
    
    return -1;
}



int * twoSum(int* nums, int numSize, int target, int* returnSize)
{
    htab h;
    position temp;
    int i, requireNum, pos;
    int *ans;

    
    h = createHashTab(10);
    
    
    for(i = 0; i < numSize; i++)
        insert2htab(h, nums[i], i);
    
    
    for(i = 0; i < numSize; i++)
    {
        requireNum = target - nums[i];
        if ((pos = find(h, requireNum, i)) != -1)
        {
            ans = (int *)calloc(sizeof(int), 2);
            ans[0] = i;
            ans[1] = pos;
            
            *returnSize = 2;
            
            return ans;
        }
        
    }

    return NULL;
    
    
}

