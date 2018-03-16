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
    struct node *newN = (node *)malloc(sizeof(struct node));
    newN->diff_data = data;
    if (diff_list != NULL)
    {
        newN->next = diff_list;
    }
    else{
        newN->next = NULL;
    }
    return newN;
}
     /* Add a new node with the given data to the list,
        and return a pointer to the list (i.e., the first node in the list).
        If the list is null - create a new entry and return a pointer to the entry. */

void list_free(node *diff_list)
{

    node *tmp = diff_list;
    while(diff_list != NULL)
    {
        tmp = diff_list;
        diff_list = diff_list->next;
        free(tmp->diff_data);
        free(tmp);
    }
} /* Free the memory allocated by and for the list. */



int main(int argc, char **argv)
{
  FILE *orig;
  FILE *newN;
  int i;
  int check = 0;
  int flag = 0;
  
    if(argc != 0){

        if(strcmp(argv[1],"-h") ==0)
        {
            printf("-h print a summary of options and exit\n"); 
            printf("-n NUMBER print first NUMBER differences and exit\n"); 
            printf("-r Restore the NEW file back to it's ORIG content\n");
            return 0;
        }
        else if(strcmp(argv[1],"-n") ==0)
        {
;
            flag = atoi(argv[2]);
            orig = fopen(argv[3], "rb+");
            newN = fopen(argv[4], "rb+");
            check = 1;
        }
        else if(strcmp(argv[1],"-r") ==0)
        {
            orig = fopen(argv[2], "rb+");
            newN = fopen(argv[3], "rb+");             
            check = 2;      
        } 
        else{
            orig = fopen(argv[1], "rb+");
            newN = fopen(argv[2], "rb+");
            check = 3;
        }        
    }
    else{
        printf("no input!\n");
        return 0;
    }  
  int size1;
  int size2;
  fseek(orig, 0, SEEK_END);
  size1 = ftell(orig);
  fseek(orig, 0, SEEK_SET);
  fseek(newN, 0, SEEK_END); 
  size2 = ftell(newN);
  fseek(newN, 0, SEEK_SET);
  
    

  i = 0;
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
  fread(bufferNew, sizeof(char), minSize,newN );
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

  if(offestList != NULL){
    if (check == 1)
    {
        list_print(offestList, flag);     
    }
    else if (check == 2){
        node *temp = offestList;
        while(temp != NULL)
        {   
            long of = temp->diff_data->offset;
            fseek(newN, of, SEEK_SET);
            fputc(temp->diff_data->orig_value, newN);
            temp = temp->next;
        }
    }
    else if(check == 3)
    {
        list_print(offestList, count);        
    }
      list_free(offestList);
  }
  else{
      printf("no diffrence!!\n");
  }
  fclose(orig);
  fclose(newN);
  return 0;
}
