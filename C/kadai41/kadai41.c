#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float N[8];

  for (int i = 0; i < 8; i++) {
    scanf("%f", &N[i]);
  }

  // table to help me remember the index
  // 0    1
  // xa1, ya1
  // 2    3
  // xa2, ya2
  // 4    5
  // xb1, yb1
  // 6    7
  // xb2, yb2

  // let's check if these two lines are "possibly" parallel
  float slope_check =
      (N[3] - N[1]) * (N[6] - N[4]) - (N[2] - N[0]) * (N[7] - N[5]);

  // or perpendicular
  float perp_check =
      (N[3] - N[1]) * (N[6] - N[4]) + (N[2] - N[0]) * (N[7] - N[5]);

  if (slope_check == 0 && perp_check != 0) {
    printf("NG");
    return 0;
  }

  // now let's check if these two lines are intersecting
  // judging from slope how to check if they are intersecting?
  /**
   *     /
   *    /
   *   /
   * /
   *      \
   *       \
   *        \
   *         \
   *          \
   *
   * as you can see, these lines are not intersecting, because
   * the intersection point is not in the range of the line
   * so let's find the intersection point first
   *
   * i need to do math
   * (xa2 - xa1)y = (ya2 - ya1)x + (xa2ya1 - xa1ya2) => * (xb2 - xb1) _1
   * (xb2 - xb1)y = (yb2 - yb1)x + (xb2yb1 - xb1yb2) => * (xa2 - xa1) _2
   *
   * 1 - 2
   * (xb2 - xb1)(ya2 - ya1)x - (xa2 - xa1)(yb2 - yb1)x + (xa2ya1 - xa1ya2)(xb2 -
   * xb1) - (xb2yb1 - xb1yb2)(xa2 - xa1) = 0
   *
   *
   * x = (xb2yb1 - xb1yb2)(xa2 - xa1) - (xa2ya1 - xa1ya2)(xb2 - xb1)
   *    / (xb2 - xb1)(ya2 - ya1) - (xa2 - xa1)(yb2 - yb1)
   */
  float int_x = ((N[6] * N[5] - N[4] * N[7]) * (N[2] - N[0]) -
                 (N[2] * N[1] - N[0] * N[3]) * (N[6] - N[4])) /
                ((N[6] - N[4]) * (N[3] - N[1]) - (N[2] - N[0]) * (N[7] - N[5]));

  // just to check if the formula is correct
  // printf("%f\n", int_x);
  // it's correct? wth first try?

  // table to help me remember the index
  // 0    1
  // xa1, ya1
  // 2    3
  // xa2, ya2
  // 4    5
  // xb1, yb1
  // 6    7
  // xb2, yb2

  // and if the intersection point is in the range of both lines
  // then they are intersecting
  if (
      // in line a
      ((N[0] <= int_x && int_x <= N[2]) || (N[2] <= int_x && int_x <= N[0])) &&
      // in line b
      ((N[4] <= int_x && int_x <= N[6]) || (N[6] <= int_x && int_x <= N[4]))) {
    printf("OK");
    return 0;
  }

  printf("NG");
  return 0;
}