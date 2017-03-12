//
//  mymalloc.h
//  Malloc-2
//
//  Created by Chamath Silva on 11/11/15.
//  Copyright © 2015 ___ChamathSilva___. All rights reserved.
//

#ifndef mymalloc_h
#define mymalloc_h

#include <stdio.h>



void first_node();

//typedef not working here
struct block_head * myBestFit(int size);

void * MyMalloc(int size);
void MyFree (void * no_use);



#endif /* mymalloc_h */
