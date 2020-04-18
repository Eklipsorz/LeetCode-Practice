#include <limits.h>

int maxProfit(int* prices, int pricesSize){

    int minvalue, maxprofit;
    int i;
     
    maxprofit = 0;
    minvalue = INT_MAX;
    
    for (i = 0; i < pricesSize; i++)
    {
        if (prices[i] < minvalue)
            minvalue = prices[i];
        else if (prices[i] - minvalue > maxprofit)
            maxprofit = prices[i] - minvalue;
        
    }
    
    return maxprofit;
    
}


