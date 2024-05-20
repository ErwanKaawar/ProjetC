#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main(void)
{


    COLUMN *mycol = create_column(INT, "My Column");
    COLUMN *mycolc = create_column(CHAR, "My Column c");
    printf("%s \n", mycol->title);
    printf("%s \n", mycolc->title);


    int a = 34;
    int b = 45;
    int c = 56;
    int d = 67;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, &c);
    insert_value(mycol, &d);
    for(int i = 0; i<mycol->size; i++) {
        printf("%d \n", mycol->data[i]->int_value);
    }
    char ch = 'a';
    insert_value(mycolc, &ch);
    printf("\n%c \n", mycolc->data[0]->int_value);

#define N 5

    char str[5];

    convert_value(mycol, 2, str, N);
    printf("str : %s \n", str);

    printf("\nmycol :\n");
    print_col(mycol);


    delete_column(&mycol);


    printf("Fini");
    return 0;
}