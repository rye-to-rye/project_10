#ifndef DEBT_H
#define DEBT_H

#define NAME_LEN 30

// create the structure "debt"
struct debt {
    char company[NAME_LEN+1];
    double balance;
    double minimum;
    double interest_rate;
    struct debt *next;
};

// Prototypes for functions in debt.c
struct debt *add_to_list(struct debt *list);
struct debt *delete_first(struct debt *list);
void search_list(struct debt *list);
void print_list(struct debt *list);
void clear_list(struct debt *list);

#endif
