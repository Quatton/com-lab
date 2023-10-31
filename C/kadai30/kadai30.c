#include <stdio.h>

struct wizard {
  int hp;

  int mp;
};

/* 関数の定義を修正 */

void healing(struct wizard* x) {
  if (x->hp <= 10) {
    x->hp += 100;

    x->mp -= 10;
  }
}

int main(void) {
  struct wizard x;

  scanf("%d %d", &x.hp, &x.mp);

  /* この行も書き換える */

  healing(&x);

  printf("%d %d\n", x.hp, x.mp);

  return 0;
}