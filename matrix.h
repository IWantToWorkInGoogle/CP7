//
// Created by usrname on 22.04.22.
//
#ifndef CP7_MATRIX_H
#define CP7_MATRIX_H
#endif //CP7_MATRIX_H

#pragma once

#include "row.h"

typedef struct {
    int height;
    int width;
    row** data;
} matrix;

matrix* create_matrix(int height,int width);
void delete_matrix(matrix* ptr);
void update_matrix(matrix* ptr,int index1,int index2,int val);
void print_matrix(matrix* ptr);
int get_val_matrix(matrix* m,int row,int column);
bool read_matrix(char* file,matrix* m,bool* st);