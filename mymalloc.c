//
//  mymalloc.c
//  Malloc-2
//
//  Created by Chamath Silva on 11/11/15.
//  Copyright © 2015 ___ChamathSilva___. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include "mymalloc.h"


// 1 = free
// 0 = used

#define Memory_SIZE 2000

char Mmory_array[Memory_SIZE];

typedef struct block_head Block_head;

struct block_head {
    unsigned int size;
    unsigned int state;
    Block_head *next;
    
};

#define Head_size sizeof(Block_head)

Block_head *Mymemory = (void *)Mmory_array;

void first_node(){
    if (Mymemory->size == 0) {
        Mymemory->next = NULL;
        Mymemory->state = 1;
        Mymemory->size = Memory_SIZE - Head_size;
    }
    
}



Block_head * myBestFit(int size){
    Block_head *current = Mymemory;
    Block_head *BestFit = NULL;
    
    while (current != NULL) {
        if (current->size >= size && current->state == 1 ){
            if (BestFit == NULL){
                BestFit = current;
            }else if (BestFit->size > current->size){
                BestFit = current;
            }
        }
        current = current->next;
    }
    // if free block not found jest return starting address of the memory.
    
    if (BestFit == NULL) {
        BestFit = Mymemory;
    }
    
    //printf("%p %d %d",current->next,current->size,current->state);
    //printf("%p %d %d",BestFit->next,BestFit->size,BestFit->state);
    printf("Head size : %d",Head_size);
    return BestFit;
    
}



void * MyMalloc(int size){
    void * temp;
    // if size lesss than or equal to 0 jest retun NULL
    if (size <= 0){
        return NULL;
        
    }
    
    first_node();
    Block_head *Block_to_retun = myBestFit(size);

    if (Block_to_retun->state == 0 || Block_to_retun->size < size) {
        printf("\nNo suffcint memory\n");
        return NULL;
    }else{
        if (Block_to_retun->size - size > Head_size ) {
            //head for curent head not for the new one.
            Block_head *new_node = (void *)Block_to_retun + size + Head_size ;
            new_node->state = 1;
            new_node->next = Block_to_retun->next;
            new_node->size = Block_to_retun->size - (size + Head_size);
            
            Block_to_retun->next = new_node;
            Block_to_retun->size = size;
            
            printf("\nNew Block %p Size %d",new_node,new_node->size);
        }
  
        printf("\n%p %d %d",Block_to_retun->next,Block_to_retun->size,Block_to_retun->state);
        Block_to_retun->state = 0;
        //hide the head.
        Block_to_retun  =  (void *)Block_to_retun + Head_size;
        
        temp = (void*)Block_to_retun;
        return temp;
    }
}

void MyFree (void * no_use){
    Block_head *temp  = (Block_head *)((void *)no_use - Head_size);
    temp->state = 1;
    
    temp = Mymemory;
    
    
    while (temp->next != NULL){
        if (temp->state == 1 && temp->next->state == 1){
            temp->next = temp->next->next;
            temp->size += temp->next->size + Head_size;
        }
        temp = temp->next;
    }
    
}