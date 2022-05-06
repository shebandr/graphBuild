#include <ctime>
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
  printf("\n n      Inc |  Dec | Rand\n");
  int n = 10;
  //  fill_decrement(head, tail, n);
  // merge_sort(head, tail, n);
  // clean(head);
  for (int n = 100; n <= 500; n += 100) {
    cout << n;

    fill_increment(head, tail, n);
    merge_sort(head, tail, n);
    cout << " |   " << M + C;
    clean(head);

    fill_decrement(head, tail, n);
    merge_sort(head, tail, n);
    cout << " | " << M + C;
    clean(head);

    fill_rand(head, tail, n);
    merge_sort(head, tail, n);
    cout << " | " << M + C << endl;
    clean(head);
  }

  delete head, tail;
}
