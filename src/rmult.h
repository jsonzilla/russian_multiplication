#ifndef RMULT_H
#define RMULT_H

namespace RMULT {
  int rmult(int a, int b) {
    int res = (a % 2 == 0) ? 0 : b;

    int x = a;
    int y = b;
    while (x > 1) {
      x /= 2;
      y += y;
      if (x % 2 != 0) {
        res += y;
      }
    }

    return res;
  }
}

#endif // !RMULT_H
