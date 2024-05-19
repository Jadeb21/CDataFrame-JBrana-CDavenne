//Projet CDataframe
//Jade Brana et Clément Davenne
//Ce fichier comporte l'ensemple des fonctions pour les colonnes que contient notre CDataframe
//C'est grace à ce fichier que notre cdataframe peut contenir différentes colonne
//Chaque fonction du CDataframe.c est créer à partir de l'appel d'une de ces fonctions

#include <stdio.h>
#include <malloc.h>
#include "column.h"
#define MALLOC_SIZE 256

//création de colonne
COLUMN *create_column(char* title) {
    COLUMN *col = (COLUMN *)malloc(sizeof(COLUMN));
    col->title = title;
    col->tl = 0;
    col->tp = 0;
    col->tab = NULL;
    return col;
}

//Fonction permettant d'afficher les colonnes avec le numéro de colonne et ce qu'elle contient
int insert_value(COLUMN* column, int value) {
    if (column->tab == NULL || column->tl >= column->tp) {

        int new_tp = column->tp + MALLOC_SIZE;
        int *new_tab = (int *)realloc(column->tab, new_tp * sizeof(int));
        column->tab = new_tab;
        column->tp = new_tp;
    }

    column->tab[column->tl] = value;
    column->tl++;

    return 1;
}

//Fonction permettant de supprimer une colonne et de libérer de l'espace mémoire
void delete_column(COLUMN **col) {
    if (*col == NULL){
    free((*col)->title);
    free((*col)->tab);
    free(*col);
    *col = NULL;
    }
}

//Fonction permettant d'afficher proprement les colonnes avec le titre de la colonne
void print_col(COLUMN* col){
    printf("Titre de la colonne : %s\n", col->title);
    printf("Contenu de la colonne :\n");
    for (int i = 0; i < col->tl; i++){
        printf("[%d] %d\n", i, col->tab[i]);
    }
}

//Fonction permettant de compter le nombre de fois ou apparait une valeur
int count_occurences(COLUMN *col, int value) {
    int count = 0;
    for (int i = 0; i < col->tl; i++) {
        if (col->tab[i] == value) {
            count++;
        }
    }
    return count;
}

//Fonction permettant l'affichage de la position d'une valeur
int value_position(COLUMN *col, int position) {
    if (position < 0 || position >= col->tl){
        printf("Position invalide");
    }
    return col->tab[position];
}

//Fonction donnant les valeurs les plus haute à partir d'une valeur donnée
int more_value(COLUMN *col, int value) {
    int count = 0;
    for (int i=0; i<col->tl; i++){
        if (col->tab[i]>value) {
            count++;
        }
    }
    return count;
}

//Fonction donnant les valeurs les plus basses à partir d'une valeur donnée
int less_value(COLUMN *col, int value) {
    int count=0;
    for (int i=0 ;i<col->tl; i++){
        if (col->tab[i]<value){
            count++;
        }
    }
    return count;
}

//Fonction donnant les valeurs égales à une valeur donnée
//Fonction équivalente à celle du comptage d'occurence mais sous un autre nom, nous l'avons quand meme utilisé par la suite
int equal_value(COLUMN *col, int value) {
    int count=0;
    for (int i=0 ;i<col->tl; i++){
        if (col->tab[i]==value){
            count++;
        }
    }
    return count;
}



