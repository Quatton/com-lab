#include <math.h>
#include <stdio.h>

struct data {
  float x;
  float y;
  int label;  // 0, 1, 2
};

float distance_2(struct data a, struct data b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
  FILE* fp = fopen("./input_data.txt", "r");

  if (fp == NULL) {
    printf("File not found\n");
    return 1;
  }

  struct data training[100] = {{0, 0, -1}};

  char buffer[100];
  for (int i = 0; i < 100; i++) {
    // if can't read then break
    if (fgets(buffer, 100, fp) == NULL) {
      break;
    }

    sscanf(buffer, "%f %f %d", &training[i].x, &training[i].y,
           &training[i].label);

    // loaded correctly?
    // printf("%f %f %d\n", training[i].x, training[i].y, training[i].label);
  }

  fclose(fp);

  float x, y;
  scanf("%f %f", &x, &y);

  struct data input = {x, y, -1};
  float min_distance = -1;

  for (int i = 0; i < 100; i++) {
    if (training[i].label == -1) {
      break;
    }
    float d = distance_2(training[i], input);
    if (min_distance == -1 || d < min_distance) {
      min_distance = d;
      input.label = training[i].label;
    }
  }

  printf("%d\n", input.label);
}