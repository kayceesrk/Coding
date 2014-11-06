#include<cstdio>
#include<cstdlib>

/* You have an array of integers, and for each index you want to find the
 * product of every integer except the integer at that index. Write a function
 * get_products_of_all_ints_except_at_index() that takes an array of integers and
 * returns an array of the products.
 *
 * For example, given:
 *  [1, 7, 3, 4]
 * your function would return:
 *  [84, 12, 28, 21]
 * by calculating:
 *  [7*3*4, 1*3*4, 1*7*4, 1*7*3]
 * Do not use division in your solution.
 */

int main () {
  int count;
  scanf("%d",&count);

  int* arr = (int*)malloc(count*sizeof(int));
  int* f2b = (int*)malloc(count*sizeof(int));
  int* b2f = (int*)malloc(count*sizeof(int));

  for(int i=0; i < count; i++) {
    scanf("%d",&arr[i]);
  }

  int prod = 1;
  f2b[0]=1;
  for(int i=1; i < count; i++) {
    f2b[i] = arr[i-1] * prod;
    prod = f2b[i];
  }

  prod = 1;
  b2f[count-1]=1;
  for(int i=count-2; i >= 0; i--) {
    b2f[i] = arr[i+1] * prod;
    prod = b2f[i];
  }

  for(int i = 0; i < count; i++) {
    printf ("%d ", f2b[i] * b2f[i]);
  }
  printf("\n");
}
