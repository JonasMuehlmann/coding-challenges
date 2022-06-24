#include <stdio.h>
#include <stdlib.h>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {

  while (b) {
    unsigned long long int t = b;

    b = a % b;
    a = t;
  }
  return a;
}

unsigned int max_unique_primes(unsigned long long int n) {
  unsigned int count;
  unsigned long long int prod;
  unsigned long long int prim;

  if (n < 2)
    return 0;

  prod = 2;
  count = 1;
  for (prim = 3; prod * prim <= n; prim += 2) {
    if (gcd(prod, prim) == 1) {
      prod *= prim;
      count++;
    }
  }
  return count;
}

int main(void) {
  unsigned int q;

  if (scanf("%u", &q) != 1)
    return EXIT_FAILURE;

  while (q--) {
    unsigned long long int n;

    if (scanf("%llu", &n) != 1)
      return EXIT_FAILURE;

    printf("%u\n", max_unique_primes(n));
  }
  return EXIT_SUCCESS;
}
