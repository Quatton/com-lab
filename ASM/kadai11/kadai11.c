#include <stdio.h>

#define ull unsigned long long

void add128(ull*, ull*, ull*);

int main(void) {
  ull a[2] = {0xA05F44019BD79748ULL, 0x0000000000003995ULL};
  ull b[2] = {0x7B6F88EC052868B8ULL, 0x0000000000009A2CULL};
  ull c[2];

  add128(a, b, c);

  printf("%llx,%llx\n", c[0], c[1]);

  return 0;
}