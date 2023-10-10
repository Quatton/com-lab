// clang-format off
int main(void){
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);

  if (M == 0) {
    BubbleSort(N);
  } else if (M == 1) {
    QuickSort(N);
  } else if (M == 2) {
    MergeSort(N);
  }
  return 0;
}