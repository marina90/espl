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
          printf("%02X ", diff_list->diff_data->orig_value);
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
        else{
           new->next = NULL; 
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
    while(tmp->next != NULL)
    {
        free(tmp->diff_data);
        free(tmp);
        tmp = nextN;
        nextN = nextN->next;
    }
    free(tmp->diff_data);
    free(tmp);
    
} /* Free the memory allocated by and for the list. */


int main(int argc, char **argv)
{
  FILE *orig;
  FILE *new;
  orig = fopen(argv[1], "r");
  new = fopen(argv[2], "r");
  
  int size1;
  int size2;
  fseek(orig, 0, SEEK_END);
  size1 = ftell(orig);
  fseek(orig, 0, SEEK_SET);
  fseek(new, 0, SEEK_END); 
  size2 = ftell(new);
  fseek(new, 0, SEEK_SET);
  
  int i = 0;
  int count = 0;
  int minSize;
  if(size1 < size2)
  {
        minSize = size1;
  }
  else{
        minSize = size2;
  }
  
  char bufferOrig[minSize];
  char bufferNew[minSize];
  fread(bufferOrig, sizeof(char), minSize, orig);
  fread(bufferNew, sizeof(char), minSize,new );
  node *offestList = NULL;
  for(i = 0 ; i < minSize; i++)
  {
   
      if(bufferOrig[i] != bufferNew[i])
      {
          
          diff *temp = malloc(sizeof(diff));
        
          long diffrence = i;
          temp->offset = diffrence;
           
          temp->orig_value = bufferOrig[i];
           
          temp->new_value =  bufferNew[i];
          offestList = list_append(offestList, temp);
          count++;

          
      }
  }

  list_print(offestList, count);
  list_free(offestList);

  fclose(orig);
  fclose(new);
   
  return 0;
}
