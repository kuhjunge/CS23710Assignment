/*
 * File:   readfile.h
 * Author: Chris Deter
 *
 * Created on 15. November 2015, 13:22
 *
 * Header File for readfile.c
 * Contains the function Prototypes
 * This file contains functions that opens a file and reads a line of this File
 */

#ifndef READFILE_H
#define READFILE_H

#include "types.h"

/*
 * Open the File and save the File struct in the competition struct
 * Needs a competition struct pointer and a string with the filename
 * returns the FILE
 * @param competition_ptr
 * @param filename
 * @return pointer for the FILE (or NULL in case of Error)
 */
FILE * open_config_file(Competition_t * competition_ptr,
                        const char *    filename);

/*
 * Reads a competitor from the file and create a Competitor struct to save the
 * Data in it.
 * Needs a pointer to the competition
 * returns the new competitior (or NULL in case of Error)
 * @param competition_ptr pointer to the competition struct
 * @param comp_ptr_ptr a pointer to a pointer to a competitior
 * @return a allocated competitior filled with the data from the file or NULL if
 *          there is a problem with reading the competitor
 */
Competitor_t * read_next_competitor(Competition_t * competition_ptr,
        Competitor_ptr_t *                          comp_ptr_ptr);
#endif /* READFILE_H */