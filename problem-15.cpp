#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll collatzSeq(ll n) {
  ll count = 1; // 1 as we count the mumber we are starting from as well
  while (n>1) {
    if (n%2 == 0) n/=2;
    else n=3*n+1;
    count += 1;
  }
  return count;
}

int main() {
  ll largest = 0;
  ll N;
  for (int i = 2; i < 1000000; i++) {
    if (collatzSeq(i) > largest) {
      largest = collatzSeq(i);
      N = i;
    }
  }
  cout << N;
}
