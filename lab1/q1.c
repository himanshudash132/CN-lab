/*write a c program to swap the content of two variable 
entered through command line   using function and pointers*/

#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int x, y;
  printf("Enter two numbers: ");
  scanf("%d %d", &x, &y);

  printf("Before swapping: x = %d, y = %d\n", x, y);
  swap(&x, &y);
  printf("After swapping: x = %d, y = %d\n", x, y);

  return 0;
}