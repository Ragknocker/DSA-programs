 #include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100 // Maximum capacity of the stack
// Define the stack structure
typedef struct {
   int arr[MAX_SIZE]; // Array to store stack elements
   int top; // Index of the top element
} Stack;
// Function to initialize the stack
void initialize(Stack *stack) {
   stack->top = -1; // Set top to -1 indicating an empty stack
}
// Function to check if the stack is empty
int isEmpty(Stack *stack) {
   return stack->top == -1;
}
// Function to check if the stack is full
int isFull(Stack *stack) {
   return stack->top == MAX_SIZE - 1;
}
// Function to push an element onto the stack
void push(Stack *stack, int value) {
   if (isFull(stack)) {
       printf("Stack Overflow\n");
       return;
   }
   stack->arr[++stack->top] = value; // Increment top and add value
   printf("%d pushed to stack\n", value);
}
// Function to pop an element from the stack
int pop(Stack *stack) {
   if (isEmpty(stack)) {
       printf("Stack Underflow\n");
       return INT_MIN;
   }
   return stack->arr[stack->top--]; // Return and decrement top
}
// Function to peek at the top element of the stack
int peek(Stack *stack) {
   if (isEmpty(stack)) {
       printf("Stack is empty\n");
       return INT_MIN;
   }
   return stack->arr[stack->top];
}
// Function to display all elements in the stack
void display(Stack *stack) {
   if (isEmpty(stack)) {
       printf("Stack is empty\n");
       return;
   }
   for (int i = stack->top; i >= 0; i--) {
       printf("%d\n", stack->arr[i]);
   }
}
// Main function to demonstrate stack operations
int main() {
   Stack stack;
   initialize(&stack);
   push(&stack, 10);
   push(&stack, 20);
   push(&stack, 30);
   printf("Top element is %d\n", peek(&stack));
   printf("%d popped from stack\n", pop(&stack));
   printf("Elements in the stack:\n");
   display(&stack);
   return 0;
}