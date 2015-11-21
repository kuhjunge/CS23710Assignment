/* 
 * File:   readfile.h
 * Author: Kuhjunge
 *
 * Created on 15. November 2015, 13:22
 * 
 * This file contains functions that opens a file and reads a line of this File
 */

#ifndef READFILE_H
#define READFILE_H

#include "types.h"

FILE* open_config_file (Competition_t* competition_ptr, const char * filename);

Competitor_t* read_next_competitor (Competition_t* competition_ptr, Competitor_ptr_t* comp_ptr_ptr);

#endif /* READFILE_H */

