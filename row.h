//
// Created by usrname on 20.05.22.
//

#ifndef CP7_ROW_H
#define CP7_ROW_H
#endif //CP7_ROW_H

#include "row_item.h"
#include <stdbool.h>

#pragma once

typedef struct row{
    struct row_item* data;
    int size;
} row;

row* create_row();
void delete_row(row* ptr);
void update_row(row* ptr,int index,int val);
void print_row(row* ptr);
double get_val(row* ptr,int index);