/*************************************************************************
    > File Name: simple.c
    > Author: wy7980
    > Mail: wy7980@gmail.com 
    > Created Time: 2016-01-02
 ************************************************************************/

#include <comb.h>
#include <stdio.h>

int main(void) {
  int a, b;
  mksymbol_int(a);
  b = 3 * a + 2;
  if (b == 8) {
    printf("8\n");
  } else {
    printf("not 8\n");
  }
  return 0;
}
