#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
struct link
{
   int data;          // for storing the data
   struct link *next; // for creating the link to the next node
};                    // structure creation complete
// all that ends with '();' are function prototype
void create_list(struct link *node);      // creating the list
void display_list(struct link *node);     // displaying the list
int count_mem(struct link *node);         // counting the number of members
int search_mem(struct link *node);        // searching a member
void insert_begin(struct link **node);    // inserting a member in first
void insert_end(struct link *node);       // inserting a member in the end
void insert_pos(struct link **node);      // inserting a member at a pos
void insert_afnd(struct link *prev_node); // inserting a node after first
void reverse_list(struct link **node);    // reversing the list
void sort_list_as(struct link *node);     // sorting of the list (ascending)
void sort_list_ds(struct link *node);     // sortinf of the list (descending)
void delete_Node(struct link **node);     // deleting of a number
int main()
{ // main function to call all of the other functions
   struct link *node;
   node = (struct link *)malloc(sizeof(struct link));
   struct link *node_nm;
   node_nm = (struct link *)malloc(sizeof(struct link));
   node_nm = node;
   // dynamic memory allocated for the list
   if (node == NULL)
   { // checking of that memory
      printf("\n Memory not allocacted ");
      exit(0);
   }
   int choice, input1;
   while (true)
   {
      printf("\n FOR THE LINKED LIST ");
      printf("\n Enter 1 to create a list ");
      printf("\n Enter 2 to display the list ");
      printf("\n Enter 3 to count the members of the list ");
      printf("\n Enter 4 to search for an element in the list ");
      printf("\n Enter 5 to insert an element in the beginning of the list ");
      printf("\n Enter 6 to insert an element in the ending of the list ");
      printf("\n Enter 7 to insert an element in a particular position of the list ");
      printf("\n Enter 8 to insert an element after a node in the list ");
      printf("\n Enter 9 to reverse the list ");
      printf("\n Enter 10 to sort the list in ascending order ");
      printf("\n Enter 11 to sort the list in descending order ");
      printf("\n Enter 12 to delete a node from the list ");
      printf("\n >> ");
      scanf("%d", &choice);
      // users choice for which method to all regarding the list
      switch (choice)
      {
      case 1:
         create_list(node);
         break;
      case 2:
         display_list(node);
         break;
      case 3:
         int cnt_dn = count_mem(node);
         printf("\n Total number of elements : %d", cnt_dn);
         break;
      case 4:
         int pos = search_mem(node);
         if (pos != 0)
         {
            printf("\n The element is in node %d", (pos + 1));
         }
         else
         {
            printf("\n Sorry the element is not found ");
         }
         break;
      case 5:
         insert_begin(&node);
         break;
      case 6:
         insert_end(node);
         break;
      case 7:
         insert_pos(&node);
         break;
      case 8:
         insert_afnd(node);
         break;
      case 9:
         reverse_list(&node);
         break;
      case 10:
         sort_list_as(node);
         break;
      case 11:
         sort_list_ds(node);
         break;
      case 12:
         delete_Node(&node);
         break;
      default:
         printf("\n SORRY WRONG CHOICE ");
         break;
      } // user choice complete
      printf("\n For more about the list ");
      printf("\n Do you wish to continue ");
      printf("\n Enter 0 to stop or any number to continue ");
      printf("\n >> ");
      scanf("%d", &input1);
      if (input1 != 0)
      {
         continue;
      }
      else
      {
         break;
      }
   }
   return 0;
}
void create_list(struct link *node)
{ // function to create a linked list
   if (node == NULL)
   { // checking of the memory allocated
      printf("\n List is not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   int choice1;
   int i1 = 1;
   printf("\n Enter the data in the node %d : ", i1);
   scanf("%d", &node->data); // user input dont
   printf("\n Enter 0 to stop or any number to continue : ");
   scanf("%d", &choice1);
   node->next = NULL; // next node created
   i1++;
   while (choice1 != 0)
   {
      node->next = (struct link *)malloc(sizeof(struct link));
      // dynamic memory allocation complete
      if (node->next == NULL)
      { // checking for the memory allocated
         printf(" Memory not allocated ");
         exit(0);
      }
      node = node->next;
      printf("\n Enter the data in the node %d : ", i1);
      scanf("%d", &node->data); // entering data in the list created
      node->next = NULL;
      printf("\n Enter 0 to stop or any number to continue : ");
      scanf("%d", &choice1);
      i1++;
   }
}
void display_list(struct link *node)
{ // function to display the entire list
   if (node == NULL)
   { // checking if the memory exists or not
      printf("\n List is not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   printf("\n In the list which is created, ");
   printf("\n The data : \n");
   while (node != NULL)
   {
      printf(" > %d \n", node->data);
      node = node->next; // displaying of the entire list complete
   }
}
int count_mem(struct link *node)
{ // function to count the members of the list
   int count = 0;
   if (node == NULL)
   { // checking of the memory
      printf("\n List not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   while (node != NULL)
   {
      node = node->next;
      count = count + 1;
   }             // counting complete
   return count; // returned the value of the total number
}
int search_mem(struct link *node)
{ // function to search a member in the list
   int index = 0, x1;
   if (node == NULL)
   { // checking of the memory
      printf("\n List not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   printf("\n Enter the member to be searched : ");
   scanf("%d", &x1); // user input dont
   while (node != NULL)
   {
      if (x1 == node->data)
      {
         return index; // returning the position of the member
      }
      node = node->next;
      // scanning throught the entire list for the member
      index = index + 1;
   }
   return -1;
}
void insert_begin(struct link **node) // address of the pointer itself
{                                     // function to insert a member at the beginning of the list
   if (node == NULL)
   { // checking if the memory exists or not
      printf("\n List not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   int nn1;
   struct link *new = (struct link *)malloc(sizeof(struct link));
   // dynamic memory allocation complete
   if (new == NULL)
   { // checking if that memory exists or not
      printf("\n Memory not allocated ");
      exit(0);
   }
   printf("\n Enter any number to insert : ");
   scanf("%d", &nn1); // user input complete
   new->data = nn1;   // passing of the value to the list
   new->next = *node;
   // changing of the first node to the newly entered node
   *node = new;
   printf("\n Inserting at the beginning complete \n");
}
void insert_end(struct link *node)
{ // function to insert a member at the end of the list
   if (node == NULL)
   { // checking if the memory exists or not
      printf("\n List is not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   struct link *new;
   new = (struct link *)malloc(sizeof(struct link));
   // dynamic memory allocation done
   if (new == NULL)
   { // checking if the memory exists or not
      printf(" Memory not allocated ");
      exit(0);
   }
   printf("\n Enter the member to be inserted : ");
   scanf("%d", &new->data); // user input done
   while (node->next != NULL)
   {
      node = node->next;
   }                 // scanning and going to the end of the list for the adding of value
   node->next = new; // value adding done
   printf("\n Inserting at the end complete \n");
}
void insert_pos(struct link **node)
{ // function to insert a member at a desired position
   if (node == NULL)
   { // checking if the node is created or not
      printf("\n List is not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   int insm, dt;
   int size = count_mem(*node); // calling the function to know the size
   printf("\n There are a total of %d elements", size);
   printf("\n At which position do you want to insert the member ");
   scanf("%d", &insm); // user input complete
   int insm1 = insm - 1;
   if (insm < 1 || insm > size)
   { // checking that the position of the insertion is valid or not
      printf("\n Cannot insert element as %d is not a valid position", insm);
   }
   else
   {
      struct link *temp = *node;
      struct link *new = (struct link *)malloc(sizeof(struct link));
      // dynamic memory allocated
      if (new == NULL)
      { // checking if the memory exists or not
         printf("\n Memory not allocated ");
         exit(0);
      }
      printf("\n Enter the member to be inserted : ");
      scanf("%d", &dt); // user input complete
      new->data = dt;   // putting in the data
      new->next = NULL;
      while ((--insm1))
      {
         temp = temp->next;
      }
      new->next = temp->next;
      // two connections are existing to a single node
      temp->next = new;
      // now only one connection exists to the new node created
      // containing the new value
      printf("\n Inserting of the element at the positon complete\n");
   }
}
void insert_afnd(struct link *prev_node)
{ // function to insert the element a node after the first node
   int dt2;
   printf("\n Enter the member to be inserted : ");
   scanf("%d", &dt2); // input of value to be entered
   if (prev_node == NULL)
   {
      printf("\n The given previous node cannot be NULL ");
      exit(0);
   } // checking complete
   struct link *new_node = (struct link *)malloc(sizeof(struct link));
   // dynamic memory allocation complete
   if (new_node == NULL)
   {
      printf("\n Memory not allocated ");
      exit(0);
   }
   new_node->data = dt2;             // putting the data in the structure
   new_node->next = prev_node->next; // making a new node as the next of the previous node, thus new node creating and putting into the proper position
   prev_node->next = new_node;       // moving the node to the next of the previous node
   printf("\n Inserting of the new node complete \n");
}
void reverse_list(struct link **node)
{ // function for reversing the list
   if (node == NULL)
   { // checking of the memory allocated
      printf("\n List is not created ");
      printf("\n Memory not allocated ");
      exit(0);
   }
   struct link *prev = NULL;
   struct link *current = *node;
   struct link *next = NULL; // rough layout of the structure
   while (current != NULL)
   { // reversing starts
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   } // reversing complete
   *node = prev;
   // chaging the first node of the list
   printf("\n Reversing of the list complete \n");
}
void sort_list_as(struct link *node)
{ // function to sort the list in the ascending order
   struct link *t;
   struct link *s; // temporary nodes created
   int x;          // for temporary storing of the value
   t = node;
   while (t != NULL)
   {
      s = t->next;
      while (s != NULL)
      {
         if (t->data > s->data)
         {
            x = t->data;
            t->data = s->data;
            s->data = x;
         } // swapping complete
         s = s->next;
      }
      t = t->next; // traversing across the list
   }
   printf("\n Sorting of the list in ascending order complete \n");
}
void sort_list_ds(struct link *node)
{ // function to sort the array in descending order
   struct link *t;
   struct link *s; // temporary pointers created
   int x;          // for temporarily storing the value
   t = node;
   while (t != NULL)
   {
      s = t->next;
      while (s != NULL)
      {
         if (t->data < s->data)
         {
            x = t->data;
            t->data = s->data;
            s->data = x;
         } // swapping complete
         s = s->next;
      }
      t = t->next; // traversing through to the end of the list
   }
   printf("\n Sorting of the list in descending order complete \n");
}
void delete_Node(struct link **node)
{ // function for deleting a node of the list containing a number of choice
   int k1;
   struct link *temp; // creating a temporary node
   printf("\n Enter any number to delete ");
   scanf("%d", &k1);
   // user inputs a number to be deleted
   if ((*node)->data == k1)
   {                // checking if the key is present in the first node
      temp = *node; // temporarily stored
      *node = (*node)->next;
      free(temp);
   }
   // if the number is found in the first node then
   // move to the first node and then to the next and then release or
   // free the first node
   else
   {
      struct link *cur = *node;
      while (cur->next != NULL)
      {
         if (cur->next->data == k1)
         { // if the value matched deleting of the current node
            temp = cur->next;
            // node not present any mode
            cur->next = cur->next->next;
            free(temp);
            break;
         }
         // otherwise moving to the next node and executing the task
         else
         {
            cur = cur->next;
         }
      }
   }
   printf("\n Node containing %d sucessfully deleted \n", k1);
}