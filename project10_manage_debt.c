#include <stdio.h>
#include <stdlib.h>
#include "debt.h"
#include "read_line.h"

// My name is Ryan Rahman and this
//code is able to receive a user's input of their credit card(s) and receive certain information depending on the operation code inputted, but this time their inputted information is organized in the system by decreasing interest rate
//and the user is able to delete their first debt in case they paid it off
//also this uses multiple source files now 

int main(void)
{
  char code;
  struct debt *debt_list = NULL;

  printf("Operation Code: a for adding to the list, d for deleting the first debt, s for searching"
         ", p for printing the list; q for quit.\n");

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': debt_list = add_to_list(debt_list);
                break;
      case 'd': debt_list = delete_first(debt_list);
                break;
      case 's': search_list(debt_list);
                break;
      case 'p': print_list(debt_list);
                break;
      case 'q': clear_list(debt_list);
                return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
