

int max(int a, int b)
{
    return (a > b ? a : b);
}


int maxSubArray(int* nums, int numsSize){

    int localmax, globalmax;
    int i;
    
    localmax = globalmax = nums[0];
    
    for(i = 1 ; i < numsSize; i++)
    {
        localmax = max(nums[i],localmax + nums[i]);
        
        if (localmax > globalmax)
            globalmax = localmax;
        
    }

    
    return globalmax;
    
}


