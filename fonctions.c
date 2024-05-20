#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

#define REALOC_SIZE 256

COLUMN *create_column(ENUM_TYPE type, char *titre)
{
    COLUMN* col = (COLUMN*)malloc(sizeof(COLUMN));
    col->title =  (char*)malloc(strlen(titre));
    strcpy(col->title, titre);
    col->column_type = type;
    col-> data = NULL;
    col -> max_size = 256;
    col -> size = 0;

    //col->titre=strdup(title);
    //col -> data = malloc(256 * sizeof(int));

    if(col-> data == NULL)
    {
        return col;
    }
    return NULL;
}

void delete_column(COLUMN **col)
{
    free((*col)->data);
    (*col)->data = NULL;
    col = NULL;
}



void convert_value(COLUMN* col, unsigned long long int i, char* str, int size){
    col->max_size += REALOC_SIZE;
    col->data = realloc(col->data, col->max_size);

    switch(col->column_type){

        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;

        case CHAR:
            snprintf(str, size, "%d", *((char*)col->data[i]));
            break;

        case FLOAT:
            snprintf(str, size, "%d", *((float*)col->data[i]));
            break;

        case DOUBLE:
            snprintf(str, size, "%d", *((double*)col->data[i]));
            break;

        case STRING:
            snprintf(str, size, "%d", *((char**)col->data[i]));
            break;

        case UINT:
            snprintf(str, size, "%d", *((unsigned int*)col->data[i]));
            break;

        case STRUCTURE:
            snprintf(str, size, "%d", *((void**)col->data[i]));
            break;

        case NULLVAL:
            snprintf(str, size, "%d", *((double*)col->data[i]));
            break;
    }

}

#define N 5

void print_col(COLUMN* col) {
    char str[5];
    for(int i=0; i<col->size; i++) {

        convert_value(col, i, str, N);
        printf("       %s \n", str);
    }
}
int insert_value(COLUMN *col, void *value) {
    col->max_size += REALOC_SIZE;
    col->data = realloc(col->data, col->max_size);

    if(col->data == NULL) {
        return 0;
    }

    switch(col->column_type) {
        case NULLVAL:
            col->data[col->size] = NULL;
            break;

        case UINT:
            col->data[col->size] = malloc(sizeof(unsigned int));
            *((unsigned int*)col->data[col->size])= *((unsigned int*)value);
            break;

        case INT:
            col->data[col->size] = malloc(sizeof(int));
            *((int*)col->data[col->size])= *((int*)value);
            break;

        case CHAR:
            col->data[col->size] = malloc(sizeof(int));
            *((char*)col->data[col->size])= *((char*)value);
            break;

        case FLOAT:
            col->data[col->size] = malloc(sizeof(float));
            *((float*)col->data[col->size])= *((float*)value);
            break;

        case DOUBLE:
            col->data[col->size] = malloc(sizeof(double));
            *((double*)col->data[col->size])= *((double*)value);
            break;

        case STRING:
            col->data[col->size] = malloc(sizeof(char *));
            *((char**)col->data[col->size])= *((char**)value);
            break;

        case STRUCTURE:
            col->data[col->size] = malloc(sizeof(void*));
            *((void**)col->data[col->size])= *((void**)value);
            break;


    }

    col->size++;
    return 1; // Success
}
