/* 
 * File:   bintree.h
 * Author: Chris Deter
 *
 * Created on 15. November 2015, 18:41
 */

#ifndef BINTREE_H
#define BINTREE_H

#include "types.h"

/**
 * this function insert a new competitor in the tree (sorted) (recursive)
 * @param root_ptr tree root
 * @param comp_ptr pointer of the new node for the tree
 */
void insert_node(Competitor_ptr_t* root_ptr, Competitor_ptr_t comp_ptr);

/**
 * traverses the tree in the direction in-order and calls the 
 * pointer_to_function-Function for every node in the tree (recursive)
 * @param root_ptr treeroot
 * @param pointer_to_function the function that should be applied on every node
 */
void inorder(Competitor_ptr_t* root_ptr, void (*pointer_to_function)(Competitor_ptr_t));

/**
 * deletes the whole tree (recursive)
 * @param root_ptr treeroot
 */
void delete_tree(Competitor_ptr_t* root_ptr);

#endif /* BINTREE_H */

