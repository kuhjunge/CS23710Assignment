/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bintree.h
 * Author: Kuhjunge
 *
 * Created on 15. November 2015, 18:41
 */

#ifndef BINTREE_H
#define BINTREE_H

#include "types.h"

void insert_node(Comp_tree_node_ptr_t* root_ptr, Competitor_ptr_t comp_ptr);

void inorder(Comp_tree_node_ptr_t* root_ptr, void (*pointer_to_function)(Competitor_ptr_t));

void delete_tree(Comp_tree_node_ptr_t* root_ptr);
#endif /* BINTREE_H */

