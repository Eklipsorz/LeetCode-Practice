int singleNumber(int* nums, int numsSize){

    
    int i, ans;
    
    ans = nums[0];
    for (i = 1; i < numsSize; i++)
        ans ^= nums[i];

    
    return ans;
    
    
}


