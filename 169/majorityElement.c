

int majorityElement(int* nums, int numsSize){

    int candidate, count;
    int i;
    count = 0;
    
    for (i = 0; i < numsSize; i++)
    {
        if (count == 0)
            candidate = nums[i];
        
        count += (nums[i] == candidate ? 1 : -1);
    }
    
    
    return candidate;
}


