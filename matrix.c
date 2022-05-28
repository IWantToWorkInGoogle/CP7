//
// Created by usrname on 22.04.22.
//

#include "matrix.h"
#include <stdio.h>

matrix* create_matrix(int height,int width) {
    matrix* new_matrix = (matrix*)malloc(sizeof(matrix));
    new_matrix->height = height;
    new_matrix->width = width;
    new_matrix->data = (row**)malloc(sizeof(row*) * height);
    for(int i = 0;i < new_matrix->height;i++) {
        new_matrix->data[i] = create_row();
    }
    return new_matrix;
}

void delete_matrix(matrix* ptr) {
    for(int i = ptr->height - 1;i >= 0;i--) {
        delete_row(ptr->data[i]);
    }
    free(ptr->data);
    ptr->height = 0;
    ptr->width = 0;
    free(ptr);
}

void update_matrix(matrix* ptr,int index1,int index2,int val) {
    if(index1 >= 1 && index1 <= ptr->height && index2 >= 1 && index2 <= ptr->width) {
        update_row(ptr->data[index1 - 1],index2,val);
    }
}

void print_matrix(matrix* ptr) {
    for(int i = 0;i < ptr->height;i++) {
        row_item* p = ptr->data[i]->data;
        printf("[%d]: {",i);
        for(int j = 0;j < ptr->data[i]->size;j++) {
            p = p->next;
            printf("%d:%d",p->index,p->val);
            if(j != ptr->data[i]->size - 1) {
                printf(",");
            }
        }
        printf("}\n");
    }
    for(int i = 0;i < ptr->height;i++) {
        row_item* p = ptr->data[i]->data->next;
        int id = 1;
        for(int j = 1;j <= ptr->width;j++) {
            if(id == ptr->data[i]->size + 1)
                printf("0 ");
            else {
                if(j == p->index) {
                    printf("%d ",p->val);
                    p = p->next;
                    id++;
                } else
                    printf("0 ");
            }
        }
        printf("\n");
    }
}

int get_val_matrix(matrix* m,int row,int column) {
    int ans = 0;
    row_item* p = m->data[row - 1]->data;
    for(int i = 0;i < m->data[row - 1]->size;i++) {
        p = p->next;
        if(p->index >= column) {
            if(p->index == column) {
                ans = p->val;
            }
            break;
        }
    }
    return ans;
}

bool read_matrix(char* file,matrix* m,bool* st) {
    FILE* f;
    f = fopen(file,"r");
    if(f == NULL) {
        fprintf(stderr,"Error, file not open!");
        return false;
    }
    printf("here1\n");
    for(int i = 1;i <= m->height;i++) {
        for(int j = 1;j <= m->width;j++) {
            int val;
            fscanf(f,"%d",&val);
            update_matrix(m,i,j,val);
        }
    }
    fclose(f);
    printf("here\n");
    print_matrix(m);
    *st = true;
    return true;
}