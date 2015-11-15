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
 * 
 */
typedef struct Competition_struct
{
    FILE* process_file;
    int competitor_count;
    char name[MAX_LINE_LENGTH];
    char date[MAX_LINE_LENGTH];
    Competitor_t** competitor;

} Competition_t;

#endif /* TYPES_H */

