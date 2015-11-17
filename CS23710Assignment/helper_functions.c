/* 
 * File:   main.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int calc_foot_lenght(float lenght){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate inch lenght\n"); }
    return (int) lenght / FEET_TO_INCH;
}

float calc_inch_lenght(float lenght){
    if(LOG_DEBUG_DETAIL) { printf("DEBUG: Calculate inch lenght\n"); }
    return lenght - (FEET_TO_INCH*calc_foot_lenght(lenght));
}

float calc_total_lenght(Competitor_ptr_t comp_ptr){
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
            calc_foot_lenght(competitor->length_cucumber),calc_inch_lenght(competitor->length_cucumber),
            calc_foot_lenght(competitor->length_carrot),calc_inch_lenght(competitor->length_carrot),
            calc_foot_lenght(competitor->length_runner_bean),calc_inch_lenght(competitor->length_runner_bean),
            calc_foot_lenght(calc_total_lenght(competitor)),calc_inch_lenght(calc_total_lenght(competitor)));
}

void print_address_competitor(Competitor_ptr_t competitor){
    printf("Competitor Name: %s\nPostal Address: %s\nTelephone: %s\n\n",
            competitor->name, competitor->address,
            competitor->phone_number);
}
