#include "config.h"

struct accounts_struct* create_list(char *p)
{
    printf("\n creating list with headnode as [%d]\n",val);
    struct accounts_struct *ptr = (struct accounts_struct*)malloc(sizeof(struct accounts_struct));
    if(NULL == ptr) {
        printf("\n Node creation failed \n");
        return NULL;
    }
    // ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

struct accounts_struct* add_to_list(char *u, bool add_to_end)
{
    if(NULL == head) {
        return (create_list(val));
    }

    if(add_to_end)
        printf("\n Adding node to end of list with value [%d]\n",val);
    else
        printf("\n Adding node to beginning of list with value [%d]\n",val);

    struct accounts_struct *ptr = (struct accounts_struct*)malloc(sizeof(struct accounts_struct));
    if(NULL == ptr) {
        return NULL;
    }
    ptr->val = val;
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

    free(del);
    del = NULL;
    return 0;
}

void print_list(void)
{
    struct accounts_struct *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL) {
        printf("\n [%d] \n",ptr->val);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}
