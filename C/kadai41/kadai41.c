#include <stdio.h>
#include <stdlib.h>

// i got so many runtime errors i gave up
// https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/

typedef struct point {
  float x;
  float y;
} Point;

float orientation(Point p, Point q, Point r) {
  return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

int check_intersect(Point p1, Point q1, Point p2, Point q2) {
  // General case
  if (orientation(p1, q1, p2) * orientation(p1, q1, q2) < 0     // diff orient
      && orientation(p2, q2, p1) * orientation(p2, q2, q1) < 0  // diff orient
  ) {
    return 1;
  }

  // Special case - but probably won't need because the kadai said so
  // – (p1, q1, p2), (p1, q1, q2), (p2, q2, p1), and (p2, q2, q1) are all
  // collinear and – the x-projections of (p1, q1) and (p2, q2) intersect – the
  // y-projections of (p1, q1) and (p2, q2) intersect

  if (orientation(p1, q1, p2) == 0 && orientation(p1, q1, q2) == 0 &&
      orientation(p2, q2, p1) == 0 && orientation(p2, q2, q1) == 0 &&
      p1.x <= p2.x && p2.x <= q1.x && q1.x <= q2.x) {
    return 1;
  }

  return 0;
}

int main(void) {
  float N[8];

  for (int i = 0; i < 8; i++) {
    scanf("%f", &N[i]);
  }

  Point p1 = {N[0], N[1]};
  Point q1 = {N[2], N[3]};
  Point p2 = {N[4], N[5]};
  Point q2 = {N[6], N[7]};

  if (check_intersect(p1, q1, p2, q2)) {
    printf("OK\n");
  } else {
    printf("NG\n");
  }

  return 0;
}