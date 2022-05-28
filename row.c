//
// Created by usrname on 20.05.22.
//
#include "row.h"
#include <stdbool.h>
#include <stdio.h>

row* create_row() {
    row* new_row = (row*)malloc(sizeof(row));
    new_row->data = (row_item*)malloc(sizeof(row_item));
    new_row->data->prev = NULL;
    new_row->data->next = NULL;
    new_row->size = 0;
    return new_row;
}

void delete_row(row* ptr) {
    row_item* p = ptr->data;
    for(int i = ptr->size;i >= 0;i--) {
        row_item* next_p = p->next;
        p->next = NULL;
        p->prev = NULL;
        p->index = 0;
        p->val = 0;
        free(p);
        p = next_p;
    }
    ptr->size = 0;
    free(ptr);
}

void update_row(row* ptr,int index,int val) {
    bool updated = false;
    bool next = true;
    row_item* p = ptr->data;
    for(int i = 0;i < ptr->size;i++) {
        p = p->next;
        if(index == p->index) {
            if(val) {
                p->val = val;
            } else {
                if(i == ptr->size - 1) {
                    p->prev->next = NULL;
                } else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }
                p->index = 0;
                p->val = 0;
                p->prev = NULL;
                p->next = NULL;
                free(p);
                ptr->size--;
            }
            updated = true;
            break;
        } else if(index < p->index) {
            if(!val) {
                updated = true;
            } else {
                next = false;
            }
            break;
        }
    }
    if(!updated && val) {
        row_item* new_item = (row_item*)malloc(sizeof(row_item));
        new_item->index = index;
        new_item->val = val;
        if(next) {
            new_item->prev = p;
            new_item->next = NULL;
            p->next = new_item;
        } else {
            new_item->prev = p->prev;
            new_item->next = p;
            p->prev->next = new_item;
            p->prev = new_item;
        }
        ptr->size++;
    }
}

void print_row(row* ptr) {
    row_item* p = ptr->data;
    for(int i = 0;i < ptr->size;i++) {
        p = p->next;
        printf("%d ",p->val);
    }
}

double get_val(row* ptr,int index) {
    double ans = 0;
    row_item* p = ptr->data;
    for(int i = 0;i < ptr->size;i++) {
        p = p->next;
        if(p->index >= index) {
            if(p->index == index)
                ans = p->val;
            break;
        }
    }
    return ans;
}