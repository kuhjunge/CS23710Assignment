/* 
 * File:   readfile.h
 * Author: Kuhjunge
 *
 * Created on 15. November 2015, 13:22
 */

#ifndef READFILE_H
#define READFILE_H

#include "types.h"

FILE* openConfigFile (Competition_t* competition_ptr, const char * filename);

Competitor_t* readNextCompetitor (Competition_t* competition_ptr, Competitor_ptr_t* comp_ptr_ptr);

#endif /* READFILE_H */

