/* 
 * File:   readfile.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

char* readNextLine(FILE *f, char *linebuffer){
    if (f==NULL) return NULL;		// error: file handle not initialised
    if (feof(f)){
        fclose (f);			// close the file on reaching EOF
        return NULL;                    // error occured (EOF reached)
    }
    else  
    {	
        fgets(linebuffer, MAX_LINE_LENGTH, f);
        if (strcmp(linebuffer, "")==0) {
            if(LOG_INFO) {printf("%s\n", "INFO: Found empty line - stop reading");}
            return NULL;			// error occured: line is empty
        }
        else {
            if(LOG_DEBUG_DETAIL) { printf("DEBUG: Read from File: %s", linebuffer);}
        }
    }
    return &linebuffer[0];
}

float readVegOrFruitNextLine(FILE *f, char *linebuffer){
    int feet;
    float inch;
    if (readNextLine(f, linebuffer) != NULL){ // length_cucumber; 
        sscanf (linebuffer, " %d %f", &feet, &inch);
        if(LOG_DEBUG_DETAIL) { printf("DEBUG: Data: %d %f \n", feet, inch);}
        inch += feet * FEET_TO_INCH;
    } else { return ERR_FLOAT; }
    return inch;
}

FILE* openConfigFile (Competition_t* competition_ptr, const char * filename)
{
    char linebuffer[MAX_LINE_LENGTH + 1] = ""; // read buffer for file-input
    // try to open file for read
    competition_ptr->process_file = fopen (filename, "r");
    // test for success and error handling
    if (competition_ptr->process_file == NULL)
    {
       if(LOG_ERR) { printf("ERROR: File opening failed\n");}
       return NULL;
    }
   /* Read Competition Name */
   if (readNextLine(competition_ptr->process_file, linebuffer) != NULL){
        sscanf (linebuffer, "%[0-9a-zA-Z_- .,]", competition_ptr->name);
        /* Read Competition Date */
        readNextLine(competition_ptr->process_file, linebuffer);
        sscanf (linebuffer, "%[0-9a-zA-Z_- .,]", competition_ptr->date);
        competition_ptr->competitor_count = 0;
   }
   else return NULL;
   return competition_ptr->process_file;
}

Competitor_t* readNextCompetitor (Competition_t* competition_ptr, Competitor_ptr_t* comp_ptr_ptr){
   char linebuffer[MAX_LINE_LENGTH + 1]="";
   Competitor_t* comp_ptr;
   *comp_ptr_ptr = (Competitor_ptr_t)calloc(1, sizeof(Competitor_t));
   comp_ptr = *comp_ptr_ptr; 
   comp_ptr->number = competition_ptr->competitor_count++ +1; /*Competitor is new*/
   
   // Check if there is another competitor and read its name
   if (readNextLine(competition_ptr->process_file, linebuffer)!= NULL){ // Name
       /* put Name into the data structure */
        sscanf (linebuffer, "%[0-9a-zA-Z_- .,]", comp_ptr->name);
        readNextLine(competition_ptr->process_file, linebuffer); // Address
        sscanf (linebuffer, "%[0-9a-zA-Z_- .,]", comp_ptr->address);
        readNextLine(competition_ptr->process_file, linebuffer); // Phone Number
        sscanf (linebuffer, "%[0-9a-zA-Z_- ]", comp_ptr->phone_number);
        /* Read the vegetables  / Fruits */
        
        comp_ptr->length_cucumber = readVegOrFruitNextLine(competition_ptr->process_file, linebuffer); // cucumber;
        comp_ptr->length_carrot = readVegOrFruitNextLine(competition_ptr->process_file, linebuffer); // carrot
        comp_ptr->length_runner_bean = readVegOrFruitNextLine(competition_ptr->process_file, linebuffer); // runner bean
        
        if (comp_ptr->length_runner_bean != ERR_FLOAT && 
            comp_ptr->length_carrot != ERR_FLOAT &&
            comp_ptr->length_cucumber != ERR_FLOAT) {
            
             if(LOG_DEBUG) { 
                 printf("DEBUG: Name: %s\nNumber: %d\nAddress: %s\nFon: %s\nCucumber: %f\nCarrot: %f\nRunner Bean: %f\n---------------------------------\n",
                    comp_ptr->name, comp_ptr->number, comp_ptr->address,
                    comp_ptr->phone_number, comp_ptr->length_cucumber,
                    comp_ptr->length_carrot, comp_ptr->length_runner_bean);
             }
            return comp_ptr;
        }
   }
   
   if(LOG_INFO) { printf("ERROR: Competitor data corrupted or no competitor found!\n"); }
   free(comp_ptr); /* Remove the non existent competitor*/
   return NULL;
}