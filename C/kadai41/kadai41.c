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
  float o1 = orientation(p1, q1, p2);
  float o2 = orientation(p1, q1, q2);
  float o3 = orientation(p2, q2, p1);
  float o4 = orientation(p2, q2, q1);

  if (o1 * o2 < 0 && o3 * o4 < 0) {
    return 1;
  }

  // We don't have to check for collinearity because we're given that the
  // there are no collinear points

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