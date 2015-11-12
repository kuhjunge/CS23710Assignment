/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Kuhjunge
 *
 * Created on 12. November 2015, 12:22
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80


/*
 * 
 */
typedef struct Competitor_struct
{
    /* ID of Competitor*/
    int number;
    /* personal data */
    char name[MAX_LINE_LENGTH];
    char adress[MAX_LINE_LENGTH];
    char phone_number[MAX_LINE_LENGTH];
    /* vegetables and fruit length in inches */
    int length_cucumber; 
    int length_carrot;
    int length_runner_bean;

} Competitor_t;
/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

