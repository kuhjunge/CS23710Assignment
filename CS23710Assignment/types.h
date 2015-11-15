/* 
 * File:   globals.h
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:24
 */

#ifndef TYPES_H
#define TYPES_H

#include "globals.h"

/*
 * 
 */
typedef struct Competitor_struct
{
    /* ID of Competitor*/
    int number;
    /* personal data */
    char name[MAX_LINE_LENGTH];
    char address[MAX_LINE_LENGTH];
    char phone_number[MAX_LINE_LENGTH];
    /* vegetables and fruit length in inches */
    float length_cucumber; 
    float length_carrot;
    float length_runner_bean;

} Competitor_t;

/*
 * pointer 
 */
typedef Competitor_t* Competitor_ptr_t;

/*
 * data type for the node
 */
typedef struct Comp_tree_node{
	Competitor_ptr_t content_ptr;
	struct Comp_tree_node* left;
	struct Comp_tree_node* right;
} Comp_tree_node_t;

/*
 * pointer to the root of the tree
 */
typedef Comp_tree_node_t* Comp_tree_node_ptr_t;

/*
 * 
 */
typedef struct Competition_struct
{
    FILE* process_file;
    int competitor_count;
    char name[MAX_LINE_LENGTH];
    char date[MAX_LINE_LENGTH];
    Comp_tree_node_ptr_t root_ptr;

} Competition_t;

#endif /* TYPES_H */

