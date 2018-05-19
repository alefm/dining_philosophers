/********************************************************
*
* Author: Alef Martins
* Sistema Operacionais - UNIVALI
*
********************************************************/
#ifndef __DINING_PHILOSOPHERS_H__
#define __DINING_PHILOSOPHERS_H__

/**************************************************************************
 * INCLUDES
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

/**************************************************************************
 * DEFINITIONS
 **************************************************************************/
#define EXIT_SUCCESS				0
#define TRUE                        1
#define N_PHILOSOPHERS              5
#define MAX_WAIT_TIME               3

/**************************************************************************
 * TYPEDEFS
 **************************************************************************/

typedef enum {
    PHILOSOPHER_THINK = 0,
    PHILOSOPHER_EAT,
    PHILOSOPHER_WAIT
} E_PHILOSOPHER_STATE;

/**************************************************************************
 * INTERNAL CALL FUNCTIONS
 **************************************************************************/

/* This function print to the user the current state of this philosopher */
void philosopher_print_state(int state, int pos);

/* This is the philosopher thread and control all actions of the philosopher */
void * philosopher_thread(void *arg);

/* This function return in seconds a random time to wait */
int random_wait_time();


#endif
