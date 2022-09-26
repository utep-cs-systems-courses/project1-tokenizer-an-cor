#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Any = a) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      puts("You selected a");
      puts("Cool..");
      
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
