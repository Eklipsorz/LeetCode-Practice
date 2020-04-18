#include <stdio.h>
#include <stdlib.h>


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

	int iteration = 0;
	int count = 0;
	int *ans = (int *) malloc(sizeof(int)*numsSize);
	int padding = numsSize + 1;

	for (; iteration < numsSize; iteration++)
		nums[nums[iteration]%(padding)-1] += padding;

	for (iteration = 0; iteration < numsSize; iteration++)
	{
		if (nums[iteration] / (padding) == 0)
		{
			ans[count] = iteration + 1;
			count++;
		}

	}

	*returnSize = count;
	return ans;
}

