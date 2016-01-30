// Copyright (c) 2016 Olli-Pekka Wallin <opwallin@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <string.h>
#include "config.h"

struct accounts_struct* create_list(char *p)
{
    struct accounts_struct *ptr = (struct accounts_struct*)calloc(0,sizeof(struct accounts_struct));
    if(NULL == ptr) {
        return NULL;
    }
    ptr->username = strdup (p);
    ptr->next = NULL;
    head = curr = ptr;
    return ptr;
}

struct accounts_struct* add_to_list(char *u, bool add_to_end)
{
    if(NULL == head) {
        return (create_list(u));
    }

    add_to_end = true;
    struct accounts_struct *ptr = (struct accounts_struct*)calloc(0,sizeof(struct accounts_struct));
    if(NULL == ptr) {
        return NULL;
    }
    ptr->username = strdup (u);
    ptr->next = NULL;

    if(add_to_end) {
        curr->next = ptr;
        curr = ptr;
    }
    else {
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}

int list_count ()
{
    struct accounts_struct *ptr = head;
    int count = 0;
    while(ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

bool found_user_in_list (const char *u)
{
    struct accounts_struct *ptr = head;
    bool found = false;
    while(ptr != NULL) {
        if(ptr->username && strcmp(ptr->username,u)==0)   {
            found = true;
            break;
        }
        ptr = ptr->next;
    }
   return found;
}

struct accounts_struct* search_in_list(char *u, struct accounts_struct **prev)
{
    struct accounts_struct *ptr = head;
    struct accounts_struct *tmp = NULL;
    bool found = false;
    while(ptr != NULL) {
        if(ptr->username && strcmp(ptr->username,u)==0)   {
            found = true;
            break;
        }
        else {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)  {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else {
        return NULL;
    }
}

void delete_all (void)
{
    struct accounts_struct *acc = head;
    while (acc != NULL)  {
        struct accounts_struct *temp = acc;
        acc = acc->next;
        free(temp->username);
        free(temp);
    }
}

int delete_from_list(char *u)
{
    struct accounts_struct *prev = NULL;
    struct accounts_struct *del = NULL;
    del = search_in_list(u,&prev);
    if(del == NULL) {
        return -1;
    }
    else {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)  {
            curr = prev;
        }
        else if(del == head) {
            head = del->next;
        }
    }
    // free, let them free !
    free(del->username);
    free(del);
    del = NULL;
    return 0;
}

void print_list(FILE *lfp)
{
    struct accounts_struct *ptr = head;
    fprintf(lfp, "\n -------Printing list Start------- \n");
    int cnt = 0;
    while(ptr != NULL) {
        fprintf(lfp, "\n [%d] [%s] \n", cnt++, ptr->username);
        ptr = ptr->next;
    }
    fprintf(lfp, "\n -------Printing list End------- \n");
    return;
}
