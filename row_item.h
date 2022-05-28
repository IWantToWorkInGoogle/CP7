//
// Created by usrname on 22.04.22.
//
#ifndef CP7_LIST_ITEM_H
#define CP7_LIST_ITEM_H
#endif //CP7_LIST_ITEM_H

#include <stdlib.h>

typedef struct row_item{
    int val;
    int index;
    struct row_item* next;
    struct row_item* prev;
} row_item;