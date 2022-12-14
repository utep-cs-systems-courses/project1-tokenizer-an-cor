#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>

int space_char(char c){
  if(c== ' ' || c == '\t' && c != '\0'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != ' ' && c != '\t' && c != '\0'){
    return 1;
  }
  return 0;
}

char *word_start(char *str){
  while(space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *word){
  word = word_start(word);
  // while not a space character and not the end, keep moviong forward
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

int count_words(char *str){
  int count =0;
  str  = word_start(str);
  while(*str != '\0'){
    //move forward each word until the end
    str = word_start(str);
    count++;
    str = word_terminator(str);
  }
  return count;
}

char *copy_str(char *inStr, short len){
  // declare the type of variable, (typecasst the space it will be) malloc (bytes of the type of data structure * amount of chars that will be taken + 1 beacuse pf the '\0')
  char *outStr = (char *)malloc(sizeof(char)*(len+1));
  int i =0;
  // while there are more characters, copy each string at a time to the new string
  while(i<len){
    outStr[i] = inStr[i];
    i++;
  }
  outStr[len] = '\0'; // make  last value at outStr to be a terminating zero
  return outStr;
}

char **tokenize(char* str){
  int num_words = count_words(str);
  char **tokens = (char **)malloc(sizeof(char *)*(num_words+1));
  int word_len = 0; // holds length of each token
  for(int i =0; i < num_words; i++){
    str = word_start(str);
    word_len = word_terminator(str) - word_start(str); // get the length of the word to make enough memory space in copy_str
    tokens[i] = copy_str(str, word_len);
    str = word_terminator(str); // move pointer to end of word
  }
  tokens[num_words] = '\0'; // make last value at token to be a terminating zero
  return tokens;
}

void print_tokens(char **tokens){
  printf("_______________________\n");
  for(int i=0; tokens[i] != NULL; i++){
    printf("%s\n", tokens[i]);
  }
}

void free_tokens(char **tokens){
  int i = 0;
  // while tokens[i] != null
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
