#include <iostream>
#include <cmath>
using namespace std;
int triplet() {
  for (int m = 1; m<=32; m++) {
    for (int n = 1; n<m; n++) {
      int a = m*m+n*n;
      int b = 2*m*n;
      int c = m*m-n*n;
      if (a+b+c == 1000) return a*b*c;
    }
  }
  return 1;
}

int main() {
  cout << triplet();
}
