

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
returnSize = how many 1-D array you have
returnColumnSizes = how many element each 1-D array has
*/


int *nodetable;

void dfs_each_node(int * nums, int numsSize, int *temp, int pos, int **res, int *returnSize){
    
    int i;
    
    if (pos == numsSize){
        
        res[*returnSize] = (int *) calloc(sizeof(int), numsSize);   
        memcpy(res[*returnSize], temp, sizeof(int) * numsSize);     
        *returnSize= *returnSize + 1;
            
        return;
    }
    
    for (i = 0; i < numsSize; i++){
        if (nodetable[i] == 1)
            continue;
        temp[pos] = nums[i];
        nodetable[i] = 1;
        
        dfs_each_node(nums, numsSize, temp, pos+1, res, returnSize);
        nodetable[i] = 0;
    }
    
    
    
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int i, *temp, **res;
    int expNum;
    
    expNum = 1;
    
    for(i = 1; i <= numsSize; i++)
        expNum = expNum * i;
    
    nodetable = (int *) calloc (sizeof(int), numsSize);
    res = (int **) calloc(sizeof(int *), expNum);
    temp = (int *) calloc(sizeof(int), numsSize);
    *returnColumnSizes = (int *) calloc (sizeof(int), expNum);
    
    for(i = 0; i < expNum; i++)
        (*returnColumnSizes)[i] = numsSize;
    

    
    *returnSize = 0;
    
    dfs_each_node(nums, numsSize, temp, 0, res, returnSize);
    
    return res;
}
