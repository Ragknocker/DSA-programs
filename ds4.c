#include <stdio.h>
int linearSearchRecursive(int arr[], int n, int key) {
   if (n == 0)
       return -1; 
   if (arr[n - 1] == key)
       return n - 1; 
   return linearSearchRecursive(arr, n - 1, key); 
}
int main() {
   int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   int key = 30;
   int result = linearSearchRecursive(arr, n, key);
   if (result == -1)
       printf("Key Not Found\n");
   else
       printf("Key Found at Index: %d\n", result);
   return 0;
}