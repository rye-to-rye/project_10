#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debt.h"
#include "read_line.h"

struct debt *add_to_list(struct debt *list){ //create a new debt node with user inputted info and append to the list
  struct debt *new_debt = malloc(sizeof(struct debt));

  printf("Enter company name: ");
  read_line(new_debt->company, NAME_LEN);
  printf("Enter balance: ");
  scanf("%lf", &new_debt->balance);
  printf("Enter monthly minimum: ");
  scanf("%lf", &new_debt->minimum);
  printf("Enter interest rate: ");
  scanf("%lf", &new_debt->interest_rate);

  // if end of list or new debt's interest is higher than head node, then move to the head node
  if (list == NULL || new_debt->interest_rate > list->interest_rate) {
      new_debt->next = list;
      return new_debt;
  }

  // if new debt's interest is less than or equal than head node, then insert it after the head node, between two nodes, or at the end of the list if we reach NULL
  struct debt *cur = list;
  while (cur->next != NULL && cur->next->interest_rate >= new_debt->interest_rate) {
      cur = cur->next;
  }
  new_debt->next = cur->next;
  cur->next = new_debt;
  return list;
}

//stores the next node in a temp node and frees the head node and then returns the temp node as the new head node
struct debt *delete_first(struct debt *list) {
    if (list == NULL) {
        return NULL;
    }
    struct debt *temp = list->next;
    free(list);
    return temp;
}

void search_list(struct debt *list){ //find specific debt info depending on name of the company
  char name[NAME_LEN + 1];
  printf("Enter company name: ");
  read_line(name, NAME_LEN);

  int found = 0;
  struct debt *current = list;
  while (current != NULL) {
    if (strcmp(current->company, name) == 0) {
      printf("%-28s%12.2f%12.2f%12.2f\n", current->company, current->balance, current->minimum, current->interest_rate);
      found = 1;
    }
    current = current->next;
  }
  if (!found) {
    printf("not found\n");
  }
}

void print_list(struct debt *list){ //print out every card info
  //keep the printf statement in your program. Do NOT remove.
  printf("company                          balance     minimum    interest\n");
  struct debt *current = list;
  while (current != NULL) {
    printf("%-28s%12.2f%12.2f%12.2f\n", current->company, current->balance, current->minimum, current->interest_rate);
    current = current->next;
  }
}

void clear_list(struct debt *list) //deallocate memory after user is finished with program
{
  struct debt *current = list;
  struct debt *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}
