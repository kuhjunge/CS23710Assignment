/* 
 * File:   main.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "types.h"
#include "bintree.h"

void print_competitor(Competitor_ptr_t competitor){
    printf("Name: %s\nNumber: %d\nAddress: %s\nFon: %s\nCucumber: %f\nCarrot: %f\nRunner Bean: %f\n",
            competitor->name, competitor->number, competitor->address,
            competitor->phone_number, competitor->length_cucumber,
            competitor->length_carrot, competitor->length_runner_bean);
}

/*
 * 
 */
int main(int argc, char** argv) { 
    Competition_t comp;
    Competition_t* comp_ptr = &comp;
    Competitor_ptr_t competitor_ptr;
    char filename[MAX_LINE_LENGTH] = PROCESS_FILENAME; 
    comp_ptr->root_ptr = NULL;
    
    if (openConfigFile (comp_ptr, filename) != NULL){
        while (readNextCompetitor(comp_ptr, &competitor_ptr)!=NULL){
        insert_node(&comp_ptr->root_ptr, competitor_ptr);
        }
        inorder(&comp_ptr->root_ptr, &print_competitor);
    }
    return (EXIT_SUCCESS);
}

