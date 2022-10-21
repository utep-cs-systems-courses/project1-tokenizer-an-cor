#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100 // define max amount of chars where the string read is copied

int main() 
{ 
  puts("\nWelcome!");
  char input[MAX];
  int num;
  char num_io[MAX];
  List *history = init_history();
  while (1) { // Infinite while loop

    printf("\nSelect an option (Tokenize = a), (Show previous token = b), (Show all previous history = c)  or 'q' to quit\n", stdout);
    printf(">>");
    // use fgets at [0] to get the first char
    fgets(input, MAX, stdin);

    char c = input[0];
    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      printf("You selected tokenize.\n");
      printf("Please enter a string to tokenize:\n");
      printf(">>");
      fgets(input,MAX,stdin);
      char *input_pt = input;
      add_history(history,input_pt);
      char **tokens = tokenize(input);
      printf("Here are the tokens being printed >>\n");
      print_tokens(tokens);
      free_tokens(tokens);
      break;
    case 'b':
      printf("Please enter an id (number of token):\n");
      printf(">>");
      fgets(num_io,MAX,stdin);
      num = atoi(num_io);
      printf(get_history(history, num));
      printf("\n");
      break;
      
    case 'c':
      printf("You selected to show all prvious history");
      print_history(history);
      break;
      
    case 'q':
      printf("Bye!");
      goto done; // terminate
      
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  free_history(history);
  return 0;
}
