#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history(){
  List *list = (List *)malloc(sizeof(List)); // make space as much as the data structure needs
  //List *list = (List*) malloc(sizeOf(List));
  list->root = NULL; // initialize the root to null
  return list;
}

int str_length(char *str){
  int count = 0;
  while(*str){
    str++;
    count++;
  }
  return count;
}

void add_history(List *list, char *str){
  Item *add_item = (Item*)malloc(sizeof(Item));
  //Item *add_item = (Item*) malloc(sizeOf(Item*));
  Item *temp = list->root;
  int list_id;

  if(temp == NULL){
    //create new list since it is empty
    list->root = add_item;
    add_item->id = 1;
  }else{
    list_id = 1;
    // move to end of list
    while(temp->next != NULL){
      temp = temp->next;
      list_id++;
    }
    // add new item
    temp->next = add_item;
    add_item->id = list_id;
  }
  int length = str_length(str);
  add_item->str = copy_str(str, length);
}

char *get_history(List *list, int id){
  Item *temp = list->root;
  if(temp ==NULL){
    printf("There is no history yet.\n");
    return "";
  }
  while(temp->next != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  printf("ID does not exist.\n");
  return "";
}

void print_history(List *list){
  Item *temp = list->root;
  if(temp ==NULL){
    printf("There is no history.\n");
    return;
  }
  while(temp != NULL){
    printf("%d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  Item*pt;
  Item* temp = list->root;
  while(temp){
    pt = temp;
    temp = temp->next;
    free(pt);
  }
  free(list);
}



