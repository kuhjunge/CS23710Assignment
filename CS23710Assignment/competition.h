/*
 * File:   competition.h
 * Author: Chris Deter
 *
 * Created on 17. November 2015, 10:16
 *
 * Header File for competition.c
 * Contains the function Prototypes
 */

#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

/*
 * prints the basic information of one competitor
 * @param competitor who should printed out
 */
void print_competitor(Competitor_ptr_t competitor);

/*
 * Prints all information that are relevant for the competition in one line
 * @param competitor who should printed out
 */
void print_line_competitor(Competitor_ptr_t competitor);

/*
 * prints a competitor and his address
 * @param competitor who should printed out
 */
void print_address_competitor(Competitor_ptr_t competitor);

/*
 * reads the name for the file to be opened
 * Only reads following characters: a-z A-Z 0-9 - _ .
 * @param string File Name
 */
void readFileName(char * string);

/*
 * calculates the total length of the vegetables / fruits
 * @param comp_ptr the competitor (owner) of the vegetables /fruits
 * @return total length of the vegetables /fruits
 */
float calc_total_length(Competitor_ptr_t comp_ptr);

/*
 * reads and processes a file
 * @param competition_ptr for the competition
 * @param filename of the file we want to read
 * @return SUCCESS at success
 */
int read_file(Competition_t * competition_ptr,
              const char *    filename);

/*
 * print the Task one
 * @param competition_ptr the competition
 */
void print_task_one(Competition_t * competition_ptr);

/*
 * print the Task two
 * @param competition_ptr the competition
 */
void print_task_two(Competition_t * competition_ptr);


/*
 * deletes allocated space and cleans struct
 * @param competition_ptr the competition
 */
void cleanup(Competition_t * competition_ptr);

#endif /* HELPER_FUNCTION_H */