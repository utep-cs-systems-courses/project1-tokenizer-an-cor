#include "malloc.h"
#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history(){
  List *list = malloc(sizeOf(List)); // make space as much as the data structure needs
  list->root = NULL; // initialize the root to null
  return *list;
}

void add_history(List *list, char *str){
}

char *get_history(List *list, int id){
}

void print_history(List *list){
}

void free_history(List *list){
}

