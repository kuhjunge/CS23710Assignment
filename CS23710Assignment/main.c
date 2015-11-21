/* 
 * File:   main.c
 * Author: Chris Deter
 *
 * Created on 12. November 2015, 12:22
 * 
 * The Main file contains the main function to start the program
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "competition.h"

/*
 * main function that starts the program
 */
int main(int argc, char** argv) { 
    Competition_t comp;
    Competition_t* comp_ptr = &comp;
    char filename[MAX_LINE_LENGTH];
    /* Get the file name from the user*/
    readFileName(filename);
    /* 
     * Open file and process content 
     * (if you can open the file) 
     */
    if (read_file(comp_ptr, filename)){
        print_task_one(comp_ptr);
    }
    /* clean the data from the competition and free the bintree */
    cleanup(comp_ptr); // Free everything
    return (EXIT_SUCCESS);
}
