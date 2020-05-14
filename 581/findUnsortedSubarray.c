#include <limit.h>

int findmin(int a, int b){
    return a > b ? b : a;
}

int findmax(int a, int b){
    return a < b ? b : a;
}

int findUnsortedSubarray(int* nums, int numsSize){

    int min, max;
    int i, left, right;
    
    max = INT_MIN;
    min = INT_MAX;
    
    
    for (i = 1; i < numsSize; i++)
        if (nums[i] < nums[i-1])
            min = findmin(min, nums[i]);
    
    
    for (i = numsSize - 2; i >= 0; i--)
        if (nums[i] > nums[i+1])
            max = findmax(max, nums[i]);
    
    
    
    for (left = 0; left < numsSize; left++)
        if (min < nums[left])
            break;
    
    for (right = numsSize - 1; right >= 0; right--)
        if (max > nums[right])
            break;
  
    return (right - left) < 0 ? 0 : (right - left) + 1;
    
}
