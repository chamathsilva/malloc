//
//  main.c
//  Malloc-2
//
//  Created by Chamath Silva on 11/11/15.
//  Copyright © 2015 ___ChamathSilva___. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");
    
    //first_node();
    
    void *temp =  MyMalloc(1958);
    void *tempp =  MyMalloc(10);
    void *tempp2 =  MyMalloc(100);

    
    return 0;
}
