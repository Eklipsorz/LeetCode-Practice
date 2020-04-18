

void moveZeroes(int* nums, int numsSize){

    int numOfnotempty, i;
    
    numOfnotempty = 0;
    
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
            nums[numOfnotempty++] = nums[i];
    }
    
    
    for (i = numOfnotempty; i < numsSize; i++)
        nums[i] = 0;
}


