/* 
 * File:   main.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int calc_foot_length(float length){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate inch lenght\n"); }
    return (int) length / FEET_TO_INCH;
}

float calc_inch_length(float length){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate inch lenght\n"); }
    return length - (FEET_TO_INCH*calc_foot_length(length));
}

float calc_total_length(Competitor_ptr_t comp_ptr){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate total lenght\n"); }
    return comp_ptr->length_cucumber + comp_ptr->length_carrot + comp_ptr->length_runner_bean;
}

void print_competitor(Competitor_ptr_t competitor){
    printf("Name: %s\nNumber: %d\nAddress: %s\nFon: %s\nCucumber: %f\nCarrot: %f\nRunner Bean: %f\n",
            competitor->name, competitor->number, competitor->address,
            competitor->phone_number, competitor->length_cucumber,
            competitor->length_carrot, competitor->length_runner_bean);
}

void print_line_competitor(Competitor_ptr_t competitor){
    printf("%s\t%d\t%2dft %4.1fin   %2dft %4.1fin   %2dft %4.1fin   %2dft %4.1fin\n",
            competitor->name, competitor->number,
            calc_foot_length(competitor->length_cucumber),calc_inch_length(competitor->length_cucumber),
            calc_foot_length(competitor->length_carrot),calc_inch_length(competitor->length_carrot),
            calc_foot_length(competitor->length_runner_bean),calc_inch_length(competitor->length_runner_bean),
            calc_foot_length(calc_total_length(competitor)),calc_inch_length(calc_total_length(competitor)));
}

void print_address_competitor(Competitor_ptr_t competitor){
    printf("Competitor Name: %s\nPostal Address: %s\nTelephone: %s\n\n",
            competitor->name, competitor->address,
            competitor->phone_number);
}

int read_file(Competition_t* competition_ptr,const char * filename){
    Competitor_ptr_t competitor_ptr;
    competition_ptr->root_ptr = NULL; // initialise with NULL
    if (openConfigFile(competition_ptr, filename) != NULL){
        while (readNextCompetitor(competition_ptr, &competitor_ptr) != NULL){
            insert_node(&competition_ptr->root_ptr, competitor_ptr);
        }
        return 1;
    }
    return 0;
}

void print_task_one(Competition_t* competition_ptr){
    if (competition_ptr == NULL){ return;}
    printf("Competition: %s Date: %s\n", competition_ptr->name, competition_ptr->date);
    printf("NAME\tcompetitor number    Cucumber    carrot    Runner Bean   Total Length\n");
    printf("==============================================================================\n");
    inorder(&competition_ptr->root_ptr, &print_line_competitor);
}

void print_task_two(Competition_t* competition_ptr){
    if (competition_ptr == NULL){ return;}
    printf("Competition: %s Date: %s\n", competition_ptr->name, competition_ptr->date);
    printf("Competitor Contact Details.\n");
    inorder(&competition_ptr->root_ptr, &print_address_competitor);
}