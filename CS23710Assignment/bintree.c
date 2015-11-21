/* 
 * File:   bintree.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "competition.h"

void inorder(Competitor_ptr_t* root_ptr, void (*pointer_to_function)(Competitor_ptr_t)){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: inorder Sort\n"); }
    if(*root_ptr != NULL)
   {
    inorder(&(*root_ptr)->left, pointer_to_function );
    pointer_to_function(*root_ptr);
    inorder(&(*root_ptr)->right, pointer_to_function);
    }
}

void delete_tree(Competitor_ptr_t* root_ptr){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: delete tree\n"); }
    if(*root_ptr != NULL)
   {
    delete_tree(&(*root_ptr)->left);
    delete_tree(&(*root_ptr)->right);
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: free space of Node!\n"); }
    free(*root_ptr);
    }
}

void insert_node(Competitor_ptr_t* root_ptr, Competitor_ptr_t comp_ptr){
    if(LOG_DEBUG) { printf("DEBUG: Insert Node"); }
    if (*root_ptr == NULL){		// tree is empty
        if(LOG_DEBUG) { printf(" - Create new Node.\n"); }
        *root_ptr = comp_ptr; // this competitor is our first
    }
    else{
        if(LOG_DEBUG_DETAIL) { printf(" - Sort in \n"); }
	// if the  of the new process is lower than the duration of the process of the node, insert the new process to the left
        if (calc_total_length(*root_ptr) > calc_total_length(comp_ptr)){
            insert_node(&((*root_ptr)->left),comp_ptr);
        }
        // if the duration of the new process is higher than the duration of the process of the node, insert the new process to the right
        if (calc_total_length(comp_ptr) > calc_total_length(*root_ptr)){
            insert_node(&((*root_ptr)->right),comp_ptr);
        }
        // if the duration of the new process and the duration of the process of the node are the same, insert the new process to the left
        if (calc_total_length(*root_ptr) == calc_total_length(comp_ptr)){
            insert_node(&((*root_ptr)->left),comp_ptr);
        }
    }
}