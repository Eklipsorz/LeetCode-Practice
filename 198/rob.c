
int max(int a, int b){
    return (a > b ? a : b);
}


int rob(int* nums, int numsSize){
    
    int i, localmax, globalmax;
    
    if (numsSize == 2)
        return max(nums[0], nums[1]);
    else if (numsSize == 1)
        return nums[0];
    else if (numsSize == 0)
        return 0;
    
    
    localmax = 0;
    globalmax = max(nums[0], nums[1]);
    
    for (i = 2; i < numsSize; i++){
        
        if (nums[i-2] > localmax)
            localmax = nums[i-2];
        
        nums[i] = nums[i] + localmax;
        
        if (nums[i] > globalmax)
            globalmax = nums[i];
        
    }

    return globalmax;
}
