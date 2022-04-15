// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  private:
  T arr[100];
  int fst;
  int lst;
 
  public:
  TPQueue() : fst(0), lst(0) {}
  void push(T uni) {
    int lat = lst++;
    while ((--lat >= fst) && (arr[lat % size].prior < uni.prior)) {
      arr[(lat + 1) % size] = arr[lat % size];
    }
    arr[(lat + 1) % size] = uni;
  }
  T pop() {
    return arr[(fst++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
