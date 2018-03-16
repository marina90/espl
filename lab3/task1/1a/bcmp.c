#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct diff {
    long offset; /* offset of the difference in file starting from zero*/
    char orig_value;     /* value of the byte in ORIG */
    char new_value;     /* value of the byte in NEW */
} diff;

typedef struct node node;

struct node {
    diff *diff_data; /* pointer to a struct containing the offset and the value of the bytes in each of the files*/
    node *next;
};


void list_print(node *diff_list,int n)
{
    int i;
    for (i = 0; i < n ; i++)
    {
          printf("byte ");
          printf("%ld ", diff_list->diff_data-> offset);
          printf("%x ", diff_list->diff_data->orig_value);
          printf("%x\n", diff_list->diff_data->new_value);
          diff_list = diff_list->next;
    }
}
 /* Print the first n nodes in diff_list in the following format: byte POSITION ORIG_VALUE NEW_VALUE.
Each item followed by a newline character. */

node* list_append(node* diff_list, diff* data)
{
    struct node *new = (node *)malloc(sizeof(struct node));
    new->diff_data = data;
    if (diff_list != NULL)
    {
        new->next = diff_list;
    }
    return new;
}
     /* Add a new node with the given data to the list,
        and return a pointer to the list (i.e., the first node in the list).
        If the list is null - create a new entry and return a pointer to the entry. */

void list_free(node *diff_list)
{
    node *tmp = diff_list;
    node *nextN = diff_list->next;
    while(nextN != NULL)
    {
        free(tmp);
        tmp = nextN;
        nextN = nextN->next;
    }
    free(tmp);
    nextN = NULL;
    
} /* Free the memory allocated by and for the list. */

int main(int argc, char **argv)
{

  struct diff first = {10, 'a', 'b'};
  struct diff second = {20, 'c', 'd'};
  struct node *list1 = list_append(NULL, &first);
  list1 = list_append(list1, &second);
  list_print(list1, 2);
  list_free(list1);
  return 0;
}
