#include <stdio.h>
#include <stdlib.h>
struct Node {
   int data; 
   struct Node* next; 
};
int main() {
   // Create three nodes
   struct Node* head = (struct Node*)malloc(sizeof(struct Node));
   struct Node* second = (struct Node*)malloc(sizeof(struct Node));
   struct Node* third = (struct Node*)malloc(sizeof(struct Node));
   // Assign data and link nodes
   head->data = 10;
   head->next = second;
   second->data = 20;
   second->next = third;
   third->data = 30;
   third->next = NULL;
   // Traverse and print the list
   struct Node* temp = head;
   while (temp != NULL) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
   return 0;
}