/* 
 * File:   main.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "readfile.h"
#include "types.h"

void print_competitor(Competitor_t * competitor){
    printf("Name: %s\nNumber: %d\nAddress: %s\nFon: %s\nCucumber: %f\nCarrot: %f\nRunner Bean: %f\n",
            competitor->name, competitor->number, competitor->address,
            competitor->phone_number, competitor->length_cucumber,
            competitor->length_carrot, competitor->length_runner_bean);
}
/*
 * 
 */
int main(int argc, char** argv) { 
    Competition_t comp;
    Competition_t * comp_ptr = &comp;
    Competitor_t * competitor[4];
    char filename[MAX_LINE_LENGTH] = PROCESS_FILENAME; 
    
    if (openConfigFile (comp_ptr, filename) != NULL){
        readNextCompetitor(comp_ptr, &competitor[0]);
        readNextCompetitor(comp_ptr, &competitor[1]);
        readNextCompetitor(comp_ptr, &competitor[2]);
        readNextCompetitor(comp_ptr, &competitor[3]);
        if (LOG_DEBUG){ print_competitor(competitor[2]);}
    }
    return (EXIT_SUCCESS);
}

