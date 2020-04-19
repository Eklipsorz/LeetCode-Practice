

int climbStairs(int n){

    int numStep, step[2];
    int i;
     
    if ( n < 2)
        return 1;
    
    step[0] = 1;
    step[1] = 1;
    
    for (i = 2; i <= n; i++)
    {
        numStep = step[1] + step[0];
        step[0] = step[1];
        step[1] = numStep;
        
    }
    
    return numStep;
}


