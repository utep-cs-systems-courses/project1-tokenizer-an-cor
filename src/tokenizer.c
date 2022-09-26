#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>

int space_char(char c){
  if(c== ' ' || c == '\t'}{
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != ' ' || c != '\t' || c == '\0'){
    return 0;
  }
  return 1;
}

char *word_start(char *str){
  while(space_char(*str) && *str != '\0'){
    str++;
  }
  return str;
}

char *word_terminator(char *word){
  word = space_char(word);
  while(non_space_char(*word) && word != '\0'){
    word++;
  }
  return word;
}

int count_words(char *str){
  return 0;
}

char *copy_str(char *inStr, short len){
  return inStr;
}

char **tokenize(char* str){
  return str;
}

void print_tokens(char **tokens){
}

void free_tokens(char **tokens){
}

