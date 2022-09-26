#include <stdio.h>
#include "tokenizer.h"

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
  while(!non_space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *word){
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

