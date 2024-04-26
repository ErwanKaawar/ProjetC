//
// Created by lucas on 29/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct column {
    char* titre;
    int taille_logique;
    int taille_physique;
    int* valeurs;
};

typedef struct column COLUMN;

#ifndef PROJET_CLION_FONCTIONS_H
#define PROJET_CLION_FONCTIONS_H


COLUMN *create_column(char* title);

int insert_value(COLUMN* col, int value);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

void value_added(int x);

int occurences(COLUMN* col, int x);

int retourne_val(COLUMN* col, int i);

int supérieur(COLUMN* col, int x);

int inférieur(COLUMN* col, int x);

int égales(COLUMN* col, int x);


#endif //PROJET_CLION_FONCTIONS_H
