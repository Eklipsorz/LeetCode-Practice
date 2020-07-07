#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct HashTabNode *HashTabNode;
typedef struct HashTab *HashTab;
typedef struct HeapArray *HeapArray;
typedef struct HeapArrayNode *HeapArrayNode;

struct HashTabNode{
    int keyvalue;
    int count;
    struct HashTabNode *next;
};

struct HashTab {
    int size;
    HashTabNode *list;  
};

struct HeapArray {
    int size;
    int capacity;
    struct HeapArrayNode *array;
};


struct HeapArrayNode {
    int keyvalue;
    int count;
};

/*  test */
void showHtab(HashTab htab){
    
    int index;
    HashTabNode temp;
    
    for(index = 0; index < 10; index++){
        printf("index: %d\n", index);
        printf("-----------------------------------------------------\n");
        for(temp = htab->list[index]->next; temp != NULL; temp = temp->next){
            printf("value: %d  count: %d\n", temp->keyvalue, temp->count);
        }
        printf("-----------------------------------------------------\n");
    }
    
    
}

void showHeapData(HeapArray hArray){
    
    int index, capacity;
    HeapArrayNode array;
    
    
    capacity = hArray->capacity;
    array = hArray->array;
    
    for(index = 0; index < capacity; index++){
        printf("index: %d | keyvalue: %d, count: %d\n", index, array[index].keyvalue, array[index].count);
    }
    
}

/*                          The HashTab structure                          */
HashTab CreateHashTab(int size){
    
    HashTab htab; 
    int index;
    
    htab = (HashTab) calloc(sizeof(struct HashTab), 1);
    htab->list = (HashTabNode *) calloc(sizeof(HashTabNode), size);
    htab->size = 0;
    
    for(index = 0; index < size; index++){
        htab->list[index] = (HashTabNode) calloc(sizeof(struct HashTabNode), 1);
        htab->list[index]->next = NULL;
    }
    
    return htab;
    
}


int hash(int value){
    return value > 0 ? value % 10 : (-1 * value) % 10;
}

HashTabNode find(HashTab htab, int value){
    
    HashTabNode temp;
    
    temp = htab->list[hash(value)]->next;
    for(; temp != NULL; temp = temp->next){
        if(temp->keyvalue == value)
            return temp;
    }

    return NULL;
    
}


void addHashTab(HashTab htab, int value){
    HashTabNode temp;
    HashTabNode listhead;
    
    if((temp = find(htab, value)))
        temp->count++;
    else{
        
        listhead = htab->list[hash(value)];
        temp = (HashTabNode) calloc(sizeof(struct HashTabNode), 1);
        temp->keyvalue = value;
        temp->count = 1;
        temp->next = listhead->next;
        listhead->next = temp;
        
        htab->size++;
    }
    
}
/*                          The HashTab structure                          */




/*                            The Heap structure                          */

HeapArray CreateHeap(int size){
    
    HeapArray temp;
    
    temp = (HeapArray) calloc(sizeof(struct HeapArray), 1);
    temp->array = (HeapArrayNode) calloc(sizeof(struct HeapArrayNode), size + 1);
    temp->capacity = size + 1;
    temp->size = 0;
        
    return temp;

}


void InsertHeap(HeapArray hArray, HashTabNode node){
    
    int index, node_keyvalue, node_count;
    HeapArrayNode array;
    
    array = hArray->array;
    node_keyvalue = node->keyvalue;
    node_count = node->count;
        
    for(index = ++(hArray->size); array[index/2].count > node_count; index /= 2){
        array[index].keyvalue = array[index/2].keyvalue;
        array[index].count = array[index/2].count;
    }
    
    array[index].keyvalue = node_keyvalue;
    array[index].count = node_count;
    
}

int DeleteMin(HeapArray hArray){
    
    int minvalue, index, child, lastnode_keyvalue, lastnode_count;
    HeapArrayNode array, lastnode;
    
    array = hArray->array;
    
    
    lastnode_keyvalue = array[hArray->size].keyvalue;
    lastnode_count = array[hArray->size].count;
    hArray->size--;
    
    minvalue = array[1].keyvalue;
    
    for(index = 1; index * 2 <= hArray->size; index = child){
        
        child = index * 2;
        if(child != hArray->size  && array[child].count > array[child + 1].count)
            child++;
        
        if(array[child].count < lastnode_count){
            array[index].keyvalue = array[child].keyvalue;
            array[index].count = array[child].count;
        }
        else
            break;
        
    } 
    
    array[index].keyvalue = lastnode_keyvalue;
    array[index].count = lastnode_count;
    
    return minvalue;
    
    
    
}


void HashTab2TopKHeap(HashTab htab, HeapArray hArray, int hArraySizeLimit){
    
    HashTabNode temp;
    int index, minvalue;
    int deletednum;
    
   // printf("limit:%d\n", hArraySizeLimit);
    
    for(index = 0; index < 10; index++){
        for(temp = htab->list[index]->next; temp != NULL; temp = temp->next){
            
            printf("node| value:%d, count:%d\n", temp->keyvalue, temp->count);
            printf("hArraySize:%d limit:%d\n", hArray->size, hArraySizeLimit);
            minvalue = hArray->array[1].count;
         
            
            if(hArray->size == hArraySizeLimit && temp->count <= minvalue)
            {
                printf("count < minvalue\n");
                continue;
            }
            else if(hArray->size == hArraySizeLimit && temp->count > minvalue)
            {
                deletednum = DeleteMin(hArray);
                printf("delete:%d\n", deletednum);
            	printf("delete result: \n");
            	showHeapData(hArray);
		
	    }
            InsertHeap(hArray, temp);
            printf("insert result: \n");
            showHeapData(hArray);
        }
    
    }
   
    
    
    
}

/*                            The Heap structure                          */





int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    
    HashTab htab;
    HeapArray hArray;
    int index, *res;
    
    
    htab = CreateHashTab(10);
    
    for(index = 0; index < numsSize; index++)
        addHashTab(htab, nums[index]);
    
    /* addHashTab okay */
    // showHtab(htab); 
    
    /* htab->size okay */
    // printf("htabsize: %d\n", htab->size);  
    printf("htabSize:%d\n", htab->size);    
    hArray = CreateHeap(htab->size);
    
    
    /* hArray->array[i].keyvalue = value, hArray->array[i].count = count okay */
    /*
    HeapArrayNode array;
    array = hArray->array;
    
    array[0].keyvalue = 1;
    array[0].count = 4562;
    
    array[1].keyvalue = 123;
    array[1].count = 934;
    
    array[2].keyvalue = 1235;
    array[2].count = 891;
    
    hArray->size = 3;
    showheap(hArray);
    */
    
    
    HashTab2TopKHeap(htab, hArray, k);

   
    res = (int *) calloc(sizeof(int), k);
    *returnSize = k;
    
    
    
    for(index = 0; index < k; index++)
        res[index] = DeleteMin(hArray);
    
    return res;
       
}



int main(){

	int numsSize, k;
	int nums[] = {5,1,-1,-8,-7,8,-5,0,1,10,8,0,-4,3,-1,-1,4,-5,4,-3,0,2,2,2,4,-2, \
		      -4,8,-7,-7,2,-8,0,-8,10,8,-8,-2,-9,4,-7,6,6,-1,4,2,8,-3,5,-9,-3, \
		      6,-8,-5,5,10,2,-5,-1,-5,1,-3,7,0,8,-2,-3,-1,-5,4,7,-9,0,2,10,4,4,\
		      -4,-1,-1,6,-8,-9,-1,9,-9,3,5,1,6,-1,-2,4,2,4,-6,4,4,5,-5};
	int returnSize;

	numsSize = 100;
	k = 7;

	topKFrequent(nums, numsSize, k, &returnSize);
	

	return 0;
}
