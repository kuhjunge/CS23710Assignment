/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   helper_function.h
 * Author: Kuhjunge
 *
 * Created on 17. November 2015, 10:16
 */

#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

void print_competitor(Competitor_ptr_t competitor);

void print_line_competitor(Competitor_ptr_t competitor);

void print_address_competitor(Competitor_ptr_t competitor);

float calc_total_length(Competitor_ptr_t comp_ptr);

int read_file(Competition_t* competition_ptr,const char * filename);

void print_task_one(Competition_t* competition_ptr);

void print_task_two(Competition_t* competition_ptr);

#endif /* HELPER_FUNCTION_H */

