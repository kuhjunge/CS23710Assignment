/* 
 * File:   globals.h
 * Author: Chris Deter
 *
 * Created on 12. November 2015, 12:24
 * 
 * This file contains the structs that are used in this application
 */

#ifndef TYPES_H
#define TYPES_H

#include "globals.h"

/**
 * Struct for the competitor
 * Contains personal data and the lengths of the fruits/vegetables
 * It is also used as a Tree Node
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
    struct Competitor_struct* left;
    struct Competitor_struct* right;

} Competitor_t;

/**
 * pointer of competitor struct
 */
typedef Competitor_t* Competitor_ptr_t;

/**
 * Struct for the competition
 */
typedef struct Competition_struct
{
    FILE* process_file;
    int competitor_count;
    char name[MAX_LINE_LENGTH];
    char date[MAX_LINE_LENGTH];
    Competitor_ptr_t root_ptr;

} Competition_t;

#endif /* TYPES_H */

