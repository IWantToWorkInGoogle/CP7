//
// Created by usrname on 22.04.22.
//
#include "api.h"
#include <stdio.h>
#include <string.h>

int function(matrix* m,row* r) {
    row* ans = create_row();
    if(r->size == m->height) {
        for(int i = 1;i <= m->width;i++) {
            int val = 0;
            for(int j = 1;j <= m->height;j++) {
                int x = get_val(r,j);
                int y = get_val_matrix(m,i,j);
                val += x * y;
            }
            update_row(ans,i,val);
        }
        return ans->size;
    }
}

char* get_line() {
    char* ans = (char*)malloc(sizeof(char));
    char c;
    int size = 0;
    int capacity = 1;
    scanf("%c",&c);
    while(c != '\n' || c != EOF) {
        if(c == '\n' || c == EOF) {
            break;
        }
        if(size == capacity) {
            capacity *= 2;
            ans = realloc(ans,capacity);
        }
        ans[size] = c;
        size++;
        scanf("%c",&c);
    }
    return ans;
}

char* get_string() {
    char* ans = (char*)malloc(sizeof(char));
    char c;
    int size = 0;
    int capacity = 1;
    scanf("%c",&c);
    while(c != '\n' || c != EOF || c == ' ') {
        if(c == '\n' || c == EOF || c == ' ') {
            break;
        }
        if(size == capacity) {
            capacity *= 2;
            ans = realloc(ans,capacity);
        }
        ans[size] = c;
        size++;
        scanf("%c",&c);
    }
    return ans;
}

void print_string(char* string) {
    for(int i = 0;i < strlen(string);i++) {
        printf("%c",string[i]);
    }
    printf("\n");
}
