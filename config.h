#ifndef __CONFIG_H__
#define __CONFIG_H__

#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>

struct accounts_struct
{
    int val;
    char *username;
    struct accounts_struct *next;
};

struct accounts_struct *head = NULL;
struct accounts_struct *curr = NULL;

#endif
