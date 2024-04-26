#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"



//
// Created by lucas on 29/03/2024.
//

COLUMN *create_column(char* title)
{
    COLUMN* col = (COLUMN*)malloc(sizeof(COLUMN));
    col->titre =  (char*)malloc(strlen(title));
    strcpy(col->titre, title);

    //col->titre=strdup(title);
    col -> valeurs = malloc(256 * sizeof(int));
    col -> taille_physique = 256;
    col -> taille_logique = 0;
    return col;
}

int insert_value(COLUMN* col, int value)
{
    if(col -> valeurs == NULL)
    {
        printf("\n Réallocation de mémoire\n");
        col->valeurs = realloc(col->valeurs, col -> taille_physique * sizeof(int));
    }
    col -> valeurs[col -> taille_logique] = value;
    if (col->valeurs[col -> taille_logique])
    {
        col -> taille_logique += 1;
        return 1;
    }
    return 0;
}

void delete_column(COLUMN **col)
{
    free(col);
    col = NULL;
}

void print_col(COLUMN* col)
{
    int i;
    int L;
    printf("\n La taille logique est de : %d \nValeurs dans LA colonne :  ", col -> taille_logique);
    //L = strlen(col);
    for(i=0;i<col -> taille_logique;i++)
    printf("%d  ", col->valeurs[i]);
    printf("\n");
}

void value_added(int x)
{
    if(x)
        printf("\n Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
}

int occurences(COLUMN* col, int x)
{
    int i;
    int occurences = 0;
    for(i=0; i< col -> taille_logique; i++)
    {
        if (col -> valeurs[i] == x)
        {
            occurences += 1;
        }
    }
    return occurences;
}

int retourne_val(COLUMN* col, int i)
{
    return col -> valeurs[i];
}

int supérieur(COLUMN* col, int x)
{
    int i;
    int nb = 0;
    for(i=0; i < col -> taille_logique; i++)
    {
        if(col -> valeurs[i] > x)
        {
            nb += 1;
            //printf("%d  ", col -> valeurs[i]);
        }
    }
    return nb;
}

int inférieur(COLUMN* col, int x)
{
    int i;
    int nb = 0;
    for(i=0; i < col -> taille_logique; i++)
    {
        if(col -> valeurs[i] < x)
        {
            nb += 1;
            //printf("%d  ", col -> valeurs[i]);
        }
    }
    return nb;
}

int égales(COLUMN* col, int x)
{
    int i;
    int nb = 0;
    for(i=0; i < col -> taille_logique; i++)
    {
        if(col -> valeurs[i] == x)
        {
            nb += 1;
            //printf("%d  ", col -> valeurs[i]);
        }
    }
    return nb;
}