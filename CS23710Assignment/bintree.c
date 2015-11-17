/* 
 * File:   bintree.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "helper_functions.h"

void inorder(Comp_tree_node_ptr_t* root_ptr, void (*pointer_to_function)(Competitor_ptr_t)){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: inorder Sort\n"); }
    if(*root_ptr != NULL)
   {
    inorder(&(*root_ptr)->left, pointer_to_function );
    pointer_to_function((*root_ptr)->content_ptr);
    inorder(&(*root_ptr)->right, pointer_to_function);
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: free space!\n"); }
    free((*root_ptr)->content_ptr);
    free(*root_ptr);
    }
}

void insert_node(Comp_tree_node_ptr_t* root_ptr, Competitor_ptr_t comp_ptr){
    if(LOG_DEBUG) { printf("DEBUG: Insert Node"); }
    if (*root_ptr == NULL){		// tree is empty
        if(LOG_DEBUG) { printf(" - Create new Node.\n"); }
        *root_ptr = (Comp_tree_node_ptr_t)calloc(1, sizeof(Comp_tree_node_t));
	//create the new node	
	if (*root_ptr != NULL){
            (*root_ptr)->content_ptr = comp_ptr;	//pointer on the comp struct
            (*root_ptr)->left = NULL;
            (*root_ptr)->right = NULL;
        }
    }
    else{
        if(LOG_DEBUG_DETAIL) { printf(" - Sort in \n"); }
	// if the  of the new process is lower than the duration of the process of the node, insert the new process to the left
        if (calc_total_lenght((*root_ptr)->content_ptr) > calc_total_lenght(comp_ptr)){
            insert_node(&((*root_ptr)->left),comp_ptr);
        }
        // if the duration of the new process is higher than the duration of the process of the node, insert the new process to the right
        if (calc_total_lenght(comp_ptr) > calc_total_lenght((*root_ptr)->content_ptr)){
            insert_node(&((*root_ptr)->right),comp_ptr);
        }
        // if the duration of the new process and the duration of the process of the node are the same, insert the new process to the left
        if (calc_total_lenght((*root_ptr)->content_ptr) == calc_total_lenght(comp_ptr)){
            insert_node(&((*root_ptr)->left),comp_ptr);
        }
    }
}