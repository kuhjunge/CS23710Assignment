/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bintree.h
 * Author: Chris Deter
 *
 * Created on 15. November 2015, 18:41
 */

#ifndef BINTREE_H
#define BINTREE_H

#include "types.h"

void insert_node(Competitor_ptr_t* root_ptr, Competitor_ptr_t comp_ptr);

void inorder(Competitor_ptr_t* root_ptr, void (*pointer_to_function)(Competitor_ptr_t));

void delete_tree(Competitor_ptr_t* root_ptr);
#endif /* BINTREE_H */

