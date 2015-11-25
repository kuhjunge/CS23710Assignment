/*
 * File:   competition.c
 * Author: Chris Deter
 *
 * Created on 12. November 2015, 12:22
 *
 * This file contains function that processes the competition and it calls
 * function to handle the File processing and the bintree creation and reading
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
 * Only reads following characters: a-z A-Z 0-9 - _ .
 * @param string File Name
 */
void readFileName(char * string)
{
    printf("Name of the File:\n");
    scanf("%79[a-zA-Z0-9-_.]", &string[0]);
}

/*
 * converts inch to (integer) foot
 * @param length of the integer
 * @return length in foot (whitout decimal place)
 */
int calc_foot_length(float length)
{
    if (LOG_DEBUG)
    {
        printf("DEBUG: Calculate inch length\n");
    }

    return (int) length / FEET_TO_INCH;
}

/*
 * removes foot part from the inch length
 * @param length in inch
 * @return what is left after subtract the foot part of the value
 */
float calc_inch_length(float length)
{
    if (LOG_DEBUG)
    {
        printf("DEBUG: Calculate inch length\n");
    }

    return length - (FEET_TO_INCH * calc_foot_length(length));
}

/*
 * calculates the total length of the vegetables / fruits
 * @param comp_ptr the competitor (owner) of the vegetables /fruits
 * @return total length of the vegetables /fruits
 */
float calc_total_length(Competitor_ptr_t comp_ptr)
{
    if (LOG_DEBUG)
    {
        printf("DEBUG: Calculate total length\n");
    }

    return comp_ptr -> length_cucumber + comp_ptr -> length_carrot + comp_ptr -> length_runner_bean;
}

/*
 * prints the basic information of one competitor
 * @param competitor who should printed out
 */
void print_competitor(Competitor_ptr_t competitor)
{
    printf("Name: %s\nNumber: %d\nAddress: %s\nFon: %s\nCucumber: %f\nCarrot: %f\nRunner Bean: %f\n",
           competitor -> name, competitor -> number, competitor -> address, competitor -> phone_number,
           competitor -> length_cucumber, competitor -> length_carrot, competitor -> length_runner_bean);
}

/*
 * Prints all information that are relevant for the competition in one line
 * @param competitor who should printed out
 */
void print_line_competitor(Competitor_ptr_t competitor)
{
    printf("%s\t%d\t%2dft %4.1fin   %2dft %4.1fin   %2dft %4.1fin   %2dft %4.1fin\n", competitor -> name,
           competitor -> number, calc_foot_length(competitor -> length_cucumber),
           calc_inch_length(competitor -> length_cucumber), calc_foot_length(competitor -> length_carrot),
           calc_inch_length(competitor -> length_carrot), calc_foot_length(competitor -> length_runner_bean),
           calc_inch_length(competitor -> length_runner_bean), calc_foot_length(calc_total_length(competitor)),
           calc_inch_length(calc_total_length(competitor)));
}

/*
 * prints a competitor and his address
 * @param competitor who should printed out
 */
void print_address_competitor(Competitor_ptr_t competitor)
{
    printf("Competitor Name: %s\nPostal Address: %s\nTelephone: %s\n\n", competitor -> name, competitor -> address,
           competitor -> phone_number);
}

/*
 * reads and processes a file
 * @param competition_ptr for the competition
 * @param filename of the file we want to read
 * @return SUCCESS at success
 */
int read_file(Competition_t * competition_ptr,
              const char *    filename)
{
    Competitor_ptr_t competitor_ptr;

    competition_ptr -> root_ptr = NULL;    // initialise with NULL

    if (open_config_file(competition_ptr, filename) != NULL)
    {
        while (read_next_competitor(competition_ptr, &competitor_ptr) != NULL)
        {
            insert_node(&competition_ptr -> root_ptr, competitor_ptr);
        }

        return SUCCESS;    /* everything is fine */
    }

    return !SUCCESS;    /* Something went wrong */
}

/*
 * Prints the table head for the "print_line_competitor" table
 * @param competition_ptr the competition struct
 */
void print_line_competitor_header(Competition_t * competition_ptr)
{
    printf("\n");    /* some space */
    printf("Competition: %s Date: %s\n", competition_ptr -> name, competition_ptr -> date);
    printf("NAME\tcompetitor number    Cucumber    Carrot    Runner Bean   Total Length\n");
    printf("==============================================================================\n");
}

/*
 * Prints the table head for the "print_address_competitor" table
 * @param competition_ptr the competition struct
 */
void print_address_competitor_header(Competition_t * competition_ptr)
{
    printf("\n");    /* some space */
    printf("Competition: %s Date: %s\n", competition_ptr -> name, competition_ptr -> date);
    printf("Competitor Contact Details.\n");
    printf("\n");    /* some space */
}

/*
 * print the Task one
 * @param competition_ptr the competition
 */
void print_task_one(Competition_t * competition_ptr)
{
    if (competition_ptr == NULL)
    {
        return;
    }

    print_line_competitor_header(competition_ptr);
    inorder_tableprint(&competition_ptr -> root_ptr);
}

/*
 * print the Task two
 * @param competition_ptr the competition
 */
void print_task_two(Competition_t * competition_ptr)
{
    if (competition_ptr == NULL)
    {
        return;
    }

    print_line_competitor_header(competition_ptr);
    inorder(&competition_ptr -> root_ptr, &print_line_competitor);
    print_address_competitor_header(competition_ptr);
    inorder(&competition_ptr -> root_ptr, &print_address_competitor);
}

/*
 * deletes allocated space and cleans struct
 * @param competition_ptr the competition
 */
void cleanup(Competition_t * competition_ptr)
{
    delete_tree(&competition_ptr -> root_ptr);

    competition_ptr -> root_ptr = NULL;

    /* Free the File pointer */
    free(competition_ptr -> process_file);

    competition_ptr -> process_file = NULL;

    /* cleans the date and the name from the struct */
    strcpy(competition_ptr -> date, "");
    strcpy(competition_ptr -> name, "");

    competition_ptr -> competitor_count = 0;
}