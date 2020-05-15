int* countBits(int num, int* returnSize){

    int temp, i;
    int *res;
    
    
    *returnSize = num + 1;
    res = (int *) calloc(sizeof(int), *returnSize);
    
    res[0] = 0;
    temp = 1;
    
    for (i = 1; i <= num; i++){
        
        if (i/temp == 2)
            temp = temp * 2;
        res[i] = 1 + res[i % temp];
    }
    
    return res;
    
    
}
