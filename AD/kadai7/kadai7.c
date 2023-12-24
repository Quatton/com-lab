#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void swap(int* i, int* j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void printlst(int* A, int N) {
  for (int i = 0; i < N; i++) {
    printf("%d\n", A[i]);
  }
}

void BubbleSort(int N) {
  int A[SIZE];

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  for (int j = N; j > 0; j--) {
    for (int i = 0; i < N - 1; i++) {
      if (A[i] > A[i + 1]) {
        swap(&A[i], &A[i + 1]);
      }
    }
  }

  printlst(A, N);
  return;
}

void qs(int* A, int i, int j) {
  if (j - i <= 1) return;
  int pivot = A[j - 1];
  int pos = i;

  for (int k = i; k < j - 1; k++) {
    if (A[k] < pivot) {
      swap(&A[pos], &A[k]);
      pos++;
    }
  }

  swap(&A[pos], &A[j - 1]);

  qs(A, i, pos);
  qs(A, pos + 1, j);

  return;
}

void QuickSort(int N) {
  int A[SIZE];

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  qs(A, 0, N);

  printlst(A, N);
  return;
}

/**
 * from algo class
 *
 * MergeSort(A)
        if (|A| < 1) return A
                A0 <- MergeSort(first half)
                A1 <- MergeSort(second half)
                return merge(A0, A1)

// 2つの列を先頭からみていって地裁方から取っていく
merge(A0, A1)
        i <- 0, j <- 0, result <- {}
        repeat
                // this is the case we grab A0[i]
                // if you can still index i
                // and it's actually smaller
                // or you can't index j anymore
                if i <= |A0| and (A0[i] < A1[j] or j >= |A1|)
                        result.add(A0[i])
                        i <- i + 1

                // this is the case we grab A1[j]
                if j <= |A1| and (A1[j] < A0[i] or i >= |A0|)
                        result.add(A1[j])
                        j <- j + 1

                if (i == |A0| and j == |A1|)
                        return result
 */

void ms(int* A, int i, int j) {
  if (j - i <= 1) return;
  int mid = (i + j) / 2;

  ms(A, i, mid);
  ms(A, mid, j);

  int l = i;
  int r = mid;
  int res[1000];
  int res_idx = 0;

  while (l < mid || r < j) {
    if (l < mid && (A[l] < A[r] || r >= j)) {
      res[res_idx] = A[l];
      l++;
    } else {
      res[res_idx] = A[r];
      r++;
    }
    res_idx++;
  }

  for (int k = i; k < j; k++) {
    A[k] = res[k - i];
  }

  return;
}

void MergeSort(int N) {
  int A[SIZE];

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  ms(A, 0, N);

  printlst(A, N);
  return;
}

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