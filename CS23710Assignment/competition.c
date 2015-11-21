/* 
 * File:   main.c
 * Author: Chris Deter
 *
 * Created on 12. November 2015, 12:22
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "competition.h"
#include "bintree.h"
#include "readfile.h"

/*
 * reads the name for the file to be opened
 */
void readFileName(char* string){
    printf("Name of the File:\n"); 
    scanf("%30[a-zA-Z0-9-_.]", &string[0]);
}

/*
 * converts inch to (integer) foot
 */
int calc_foot_length(float length){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate inch length\n"); }
    return (int) length / FEET_TO_INCH;
}

/*
 * removes foot from the length 
 */
float calc_inch_length(float length){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate inch length\n"); }
    return length - (FEET_TO_INCH*calc_foot_length(length));
}

/*
 * calculates the l
 */
float calc_total_length(Competitor_ptr_t comp_ptr){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate total length\n"); }
    return comp_ptr->length_cucumber + comp_ptr->length_carrot + comp_ptr->length_runner_bean;
}

/**
 * prints the basic information of one competitor
 * @param competitor
 */
void print_competitor(Competitor_ptr_t competitor){
    printf("Name: %s\nNumber: %d\nAddress: %s\nFon: %s\nCucumber: %f\nCarrot: %f\nRunner Bean: %f\n",
            competitor->name, competitor->number, competitor->address,
            competitor->phone_number, competitor->length_cucumber,
            competitor->length_carrot, competitor->length_runner_bean);
}

/**
 * Prints all information that are relevant for the competition in one line
 * @param competitor
 */
void print_line_competitor(Competitor_ptr_t competitor){
    printf("%s\t%d\t%2dft %4.1fin   %2dft %4.1fin   %2dft %4.1fin   %2dft %4.1fin\n",
            competitor->name, competitor->number,
            calc_foot_length(competitor->length_cucumber),calc_inch_length(competitor->length_cucumber),
            calc_foot_length(competitor->length_carrot),calc_inch_length(competitor->length_carrot),
            calc_foot_length(competitor->length_runner_bean),calc_inch_length(competitor->length_runner_bean),
            calc_foot_length(calc_total_length(competitor)),calc_inch_length(calc_total_length(competitor)));
}

/**
 * prints a competitor and his address
 * @param competitor
 */
void print_address_competitor(Competitor_ptr_t competitor){
    printf("Competitor Name: %s\nPostal Address: %s\nTelephone: %s\n\n",
            competitor->name, competitor->address,
            competitor->phone_number);
}

/**
 * reads and processes a file
 * @param competition_ptr
 * @param filename
 * @return 
 */
int read_file(Competition_t* competition_ptr,const char * filename){
    Competitor_ptr_t competitor_ptr;
    competition_ptr->root_ptr = NULL; // initialise with NULL
    if (open_config_file(competition_ptr, filename) != NULL){
        while (read_next_competitor(competition_ptr, &competitor_ptr) != NULL){
            insert_node(&competition_ptr->root_ptr, competitor_ptr);
        }
        return 1;
    }
    return 0;
}

void print_task_one(Competition_t* competition_ptr){
    if (competition_ptr == NULL){ return;}
    printf("Competition: %s Date: %s\n", competition_ptr->name, competition_ptr->date);
    printf("NAME\tcompetitor number    Cucumber    Carrot    Runner Bean   Total Length\n");
    printf("==============================================================================\n");
    inorder(&competition_ptr->root_ptr, &print_line_competitor);
}

void print_task_two(Competition_t* competition_ptr){
    if (competition_ptr == NULL){ return;}
    printf("Competition: %s Date: %s\n", competition_ptr->name, competition_ptr->date);
    printf("Competitor Contact Details.\n");
    inorder(&competition_ptr->root_ptr, &print_address_competitor);
}

void cleanup(Competition_t* competition_ptr){
    delete_tree(&competition_ptr->root_ptr);
    competition_ptr->root_ptr = NULL;
    competition_ptr->process_file = NULL;
    strcpy(competition_ptr->date,"");
    strcpy(competition_ptr->name,"");
    competition_ptr->competitor_count = 0;
}