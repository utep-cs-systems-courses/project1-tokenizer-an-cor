#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
# define MAX 100 // define max amount of chars where the string read is copied

int main() 
{
  puts("Welcome!");

  char input[MAX];

  while (1) { // Infinite while loop

    fputs("Select an option (Tokenize = a), (History = b), (Show all previous history = c)  or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      puts("You selected tokenize\n");
      puts("Please enter a string to tokenize:\n>");
      fgets(input,MAX,stdin);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
      break;
      
    case 'b':
      puts("You selected to show history");
      break;
      
    case 'c':
      puts("You selected to show all prvious history");
      break;
      
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
