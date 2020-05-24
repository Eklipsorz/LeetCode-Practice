

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// peopleSize = the number of people
// people[i][j] = [h, k]
// peopleColSize = how many property each person has?
// returnSize = the number of people
// returnColumnSizes = how many property each person has?


// return array is a reconstructed queue.

typedef struct{
    int height;
    int count;
} peoplePtr;

int compare(const void *p1, const void *p2){
    
    const peoplePtr * temp1 = *(const peoplePtr **) p1;
    const peoplePtr * temp2 = *(const peoplePtr **) p2;
    
    if (temp1->height == temp2->height)
        return ((temp1->count) - (temp2->count));
    return ((temp2->height) - (temp1->height));
    
    return 1;
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){

    int **newQueue;
    int i, count;
    
    
    
    qsort(people, peopleSize, sizeof(int *), compare);
    newQueue = (int **) calloc(sizeof(int *), peopleSize);
    
    
    for (i = 0; i < peopleSize; i++){
       
        count = people[i][1];
        memmove(&newQueue[count+1], &newQueue[count], (i - count)*sizeof(int *));
        
        newQueue[count] = (int *)calloc(sizeof(int), 2);
        newQueue[count][0] = people[i][0];
        newQueue[count][1] = people[i][1];
        
    }
  
    *returnSize = peopleSize;
    *returnColumnSizes = peopleColSize;
    
    return newQueue;
    
}


