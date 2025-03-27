// mylistlib.h
#ifndef MYLISTLIB_H
#define MYLISTLIB_H

typedef struct List 
{
    int info;
    struct List *link;
} List;

List *insertbeg(List *start, int info);
void printlist(List *start);
List *insertafter(List *start, int previnfo, int info);
List *insertend(List *start, int info);
void freelist(List *start);
List *deletebeg(List *start);
List *deletenode(List *start, int info);
List *deleteend(List *start);

#endif