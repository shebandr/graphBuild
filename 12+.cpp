#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
float M = 0, C = 0;

typedef struct Q {
  Q *next;
  int data;
} Q;

typedef struct Ques {
  Q *head;
  Q *tail;
} Ques;

void push_to_queue(Q *&, Q *&, int);
void pop(Q *&);
void fill_increment(Q *&, Q *&, int);
void fill_decrement(Q *&, Q *&, int);
void fill_rand(Q *&, Q *&, int);
void print(Q *);
void clean(Q *&);
void split(Q *, Q *&, Q *&, int);
void merge_series(Q *&, int, Q *&, int, Q *&, Q *&);
void merge_sort(Q *&, Q *&, int);

void FillRand(int Array[], int N) {
  for (int i = 0; i < N; i++) {
    Array[i] = rand() % 100;
  }
}

int heap(int *A, int L, int R) {
  int x, i, j, M = 0, C = 0;
  x = A[L];
  M++;
  i = L;
  while (true) {
    j = 2 * i;
    if (j > R) {
      break;
    }
    C++;
    if (j < R and A[j + 1] <= A[j]) {
      j = j + 1;
    }
    C++;
    if (x <= A[j]) {
      break;
    }
    M++;
    A[i] = A[j];
    i = j;
  }
  M++;
  A[i] = x;

  return M + C;
}

int HeapSort(int *A, int n) {
  int R, L = n / 2, temp, C = 0, M = 0, Summ = 0;
  while (L >= 0) {
    Summ = Summ + heap(A, L, n);
    L = L - 1;
  }

  R = n;
  while (R >= 1) {
    M += 3;
    temp = A[0];
    A[0] = A[R];
    A[R] = temp;
    R = R - 1;
    Summ = Summ + heap(A, 0, R);
  }
  return M + C + Summ;
}

int quickSort(int *arr, int L, int R) {
  int x = arr[(L + R) / 2], i = L, j = R, temp = 0;
  int m = 0, c = 0, summ = 0;
  while (i <= j) {
    while (arr[i] < x) {
      i++;
      c++;
    }
    while (arr[j] > x) {
      j--;
      c++;
    }
    c++;
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      m = m + 3;
      i++;
      j--;
    }
  }
  if (L < j) {
    summ += quickSort(arr, L, j);
  }
  if (i < R) {
    summ += quickSort(arr, i, R);
  }
  return summ + m + c;
}

void split(Q *S, Q *&a, Q *&b, int n) {
  Q *k = new Q;
  Q *p = new Q;
  a = S;
  b = S->next;
  n = 1;
  k = a;
  p = b;

  while (p != NULL) {
    n++;
    k->next = p->next;
    k = p;
    p = p->next;
    M += 3;
  }
}

void merge_series(Q *&a, int q, Q *&b, int r, Q *&h1, Q *&t1) {

  C++;
  while (q != 0 && r != 0) {
    C++;
    if (a->data <= b->data) {
      push_to_queue(h1, t1, a->data);
      q--;
      a = a->next;
      M += 1.5;
    } else {
      push_to_queue(h1, t1, b->data);
      r--;
      b = b->next;
      M += 1.5;
    }
  }

  while (q > 0) {
    push_to_queue(h1, t1, a->data);
    M += 1.5;
    a = a->next;
    q--;
 
  }

  while (r > 0) {

    push_to_queue(h1, t1, b->data);
    b = b->next;
    r--;
    M += 1.5;
  }
}

void merge_sort(Q *&head, Q *&tail, int n) {
  M = 0;
  C = 0;
  Q *a = new Q;
  Q *b = new Q;
  int q = 0, r = 0;
  split(head, a, b, n);

  Ques *c = new Ques[2];
  int p = 1;

  while (p < n) {
    c[0].head = c[0].tail = c[1].head = c[1].tail = NULL;
    int i = 0, m = n;

    while (m > 0) {

      if (m >= p)
        q = p;
      else
        q = m;
      m -= q;
      if (m >= p)
        r = p;
      else
        r = m;
      m -= r;
      merge_series(a, q, b, r, c[i].head, c[i].tail);
      i = 1 - i;
    }

    a = c[0].head;
    b = c[1].head;
    p *= 2;
  }
  c[0].tail->next = NULL;
  head = c[0].head;
}

void push_to_queue(Q *&head, Q *&tail, int n) {
  Q *p = new Q;
  p->data = n;

  p->next = NULL;
  if (head != NULL)
    tail->next = p;
  else
    head = p;
  tail = p;
}

void pop(Q *&head) {
  if (head != NULL) {
    Q *p = new Q;
    p = head;
    head = p->next;
    delete p;
  }
}

void fill_increment(Q *&head, Q *&tail, int n) {
  for (int i = 0; i < n; i++) {
    push_to_queue(head, tail, i);
  }
}

void fill_decrement(Q *&head, Q *&tail, int n) {
  for (int i = 0; i < n; i++) {
    push_to_queue(head, tail, n - i);
  }
}

void fill_rand(Q *&head, Q *&tail, int n) {
  for (int i = 0; i < n; i++) {
    push_to_queue(head, tail, rand() % n);
  }
}

void print(Q *S) {
  if (S != NULL) {
    //    printf("%d ", S->data);
    //    print(S->next);
  } else {
    //    printf("\n");
  }
}

void clean(Q *&S) {
  if (S != NULL) {
    pop(S);
    clean(S);
  }
}

int main() {
  srand(time(NULL));
  Q *head = new Q;
  Q *tail = new Q;
  head = NULL;
  tail = NULL;
  int n = 10;
  ofstream out;
  out.open("graph.txt");
  if (out.is_open())
    out << "MergeSort";
    for (int n = 10; n <= 1000; n += 10) {

      fill_rand(head, tail, n);
      merge_sort(head, tail, n);
      out << " " << M + C;
      clean(head);
    }
  out << endl;
  out << "QiockSort";
  for (int n = 10; n <= 1000; n += 10) {
    int Arr[n];
    FillRand(Arr, n);

    out << " " << quickSort(Arr, 0, n - 1);
  }
  out << endl;
  out << "HeapSort";
  for (int n = 10; n <= 1000; n += 10) {
    int Arr[n];
    FillRand(Arr, n);

    out << " " << HeapSort(Arr, n) ;
  }
  out << endl;
  cout << "file complete" << endl;
  delete head, tail;
}
