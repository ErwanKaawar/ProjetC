#include <stdio.h>
#include "fonctions.h"



int main() {
    COLUMN *mycol = create_column("My column");
    printf("\nColonne : %s \n", mycol->titre);

    value_added(insert_value(mycol, 2));
    value_added(insert_value(mycol, 4));
    value_added(insert_value(mycol, 9));
    value_added(insert_value(mycol, 10));
    value_added(insert_value(mycol, 15));
    value_added(insert_value(mycol, 19));
    value_added (insert_value(mycol, 23));
    value_added (insert_value(mycol, 25));
    value_added (insert_value(mycol, 29));
    value_added (insert_value(mycol, 32));
    value_added (insert_value(mycol, 36));

    print_col(mycol);

    printf("\nLe nombre d'occurences du nombre %d est : %d fois\n", 5, occurences(mycol, 5));

    int i = 1;
    int val = retourne_val(mycol, i);
    printf("\nLa valeur située à la position %d est %d\n\n", i, val);


    int x = 17;

    int sup = supérieur(mycol, x);
    printf("\nIl y a %d valeurs supérieures à %d  :  ", sup, x);

    int inf = inférieur(mycol, x);
    printf("\nIl y a %d valeurs inférieures à %d  :  ", inf, x);

    int égale = égales(mycol, x);
    printf("\nIl y a %d valeurs égales à %d  :  ", égale, x);

    printf("\n");
    delete_column(&mycol);

    return 0;
}
