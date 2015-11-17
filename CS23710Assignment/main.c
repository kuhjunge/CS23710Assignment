/* 
 * File:   main.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "types.h"
#include "bintree.h"
#include "helper_functions.h"


/*
 * 
 */
int main(int argc, char** argv) { 
    Competition_t comp;
    Competition_t* comp_ptr = &comp;
    char filename[MAX_LINE_LENGTH] = PROCESS_FILENAME; 
    
    if (read_file(comp_ptr, filename)){
        print_task_one(comp_ptr);
    }
    return (EXIT_SUCCESS);
}

