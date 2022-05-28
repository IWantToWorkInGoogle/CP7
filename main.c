#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "api.h"

int main() {
    printf("Good afternoon, Sir!\n");
    //sleep(3);
    system("clear");

    bool program_do = true;
    bool starting_menu = true;
    bool function_menu = false;
    bool* created = (bool*)malloc(sizeof(bool));
    *created = false;

    matrix* m;
    int h,w,val;
    char* input;

    while(program_do) {
        if(starting_menu) {
            while(starting_menu) {
                printf("1)Create matrix\n2)Edit matrix\n3)Print matrix\n4)Functions\n5)Read matrix\n6)Delete matrix\n7)Exit\n");
                printf("\nChoose the command:");
                int command = atoi(get_line());
                switch (command) {
                    case 1:
                        printf("Insert height value:");
                        input = get_line();
                        if(atoi(input) < 0) {
                            printf("Invalid value.\n");
                            break;
                        } else {
                            h = atoi(input);
                        }
                        printf("Insert width value:");
                        input = get_line();
                        if(atoi(input) < 0) {
                            printf("Invalid value.\n");
                            break;
                        } else {
                            w = atoi(input);
                        }
                        m = create_matrix(h,w);
                        *created = true;
                        printf("The matrix was created!\n");
                        break;
                    case 2:
                        if(!(*created)) {
                            printf("The matrix wasn't created!\n");
                            break;
                        } else {
                            printf("%d %d\n",m->height,m->width);
                        }
                        printf("Insert row index:");
                        input = get_line();
                        int k = atoi(input);
                        if(k < 1 || k > m->height) {
                            printf("Invalid value!\n");
                            break;
                        }
                        h = k;
                        printf("Insert column index:");
                        input = get_line();
                        k = atoi(input);
                        if(k < 1 || k > m->height) {
                            printf("Invalid value!\n");
                            break;
                        }
                        w = k;
                        printf("Insert value:");
                        input = get_line();
                        k = atoi(input);
                        val = k;
                        update_matrix(m,h,w,val);
                        printf("The value was updated!\n");
                        break;
                    case 3:
                        if(!(*created)) {
                            printf("The matrix wasn't created!\n");
                            break;
                        }
                        print_matrix(m);
                        break;
                    case 4:
                        if(!(*created)) {
                            printf("The matrix wasn't created!\n");
                            break;
                        }
                        starting_menu = false;
                        function_menu = true;
                        break;
                    case 5:
                        if(!(*created)) {
                            printf("The matrix wasn't created!\n");
                            break;
                        }
                        printf("Insert URL of the text file to read:");
                        input = get_string();
                        print_string(input);
                        read_matrix(input,m,created);
                        break;
                    case 6:
                        if(*created) {
                            delete_matrix(m);
                            *created = false;
                        }
                        printf("The matrix was deleted!\n");
                        break;
                    case 7:
                        starting_menu = false;
                        function_menu = false;
                        program_do = false;
                        break;
                    default:
                        printf("Invalid value!\n");
                        break;
                }
            }
        } else if(function_menu) {
            row* r = create_row();
            printf("Insert 1x%d row:",m->height);
            for(int i = 1;i <= m->height;i++) {
                input = get_string();
                update_row(r,i,atoi(input));
            }
            printf("Answer: %d\n", function(m,r));
            function_menu = false;
            starting_menu = true;
        }
    }
    return 0;
}