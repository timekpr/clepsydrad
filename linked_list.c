#include <string.h>
#include "config.h"

struct accounts_struct* create_list(char *p)
{
    printf("\n creating list with headnode as [%s]\n",p);
    struct accounts_struct *ptr = (struct accounts_struct*)calloc(0,sizeof(struct accounts_struct));
    if(NULL == ptr) {
        printf("\n Node creation failed \n");
        return NULL;
    }
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

    if(add_to_end)
        printf("\n Adding node to end of list with value [%s]\n",u);
    else
        printf("\n Adding node to beginning of list with value [%s]\n",u);

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

struct accounts_struct* search_in_list(char *u, struct accounts_struct **prev)
{
    struct accounts_struct *ptr = head;
    struct accounts_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%s] \n",u);

    while(ptr != NULL) {
        if(strcmp(ptr->username,u)==0)   {
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

int delete_all (void)
{
    int cnt = 0;
    struct accounts_struct *acc = head;
    while (acc != NULL)  {
        struct accounts_struct *temp = acc;
        acc = acc->next;
        free(temp->username);
        free(temp);
        cnt++;
    }
    return cnt;
}

int delete_from_list(char *u)
{
    struct accounts_struct *prev = NULL;
    struct accounts_struct *del = NULL;

    printf("\n Deleting value [%s] from list\n",u);

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
