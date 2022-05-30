#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll triangleN(ll n) {
  return (n*n+n)/2;
}
ll divisorCount(ll n) {
  ll i = 1;
  ll count = 0;
  while (i*i<n) {
    if (n%i == 0) {
      if (n/i == i) count+=1;
      else count+=2;
    }
    i++;
  }
  return count;
}

int main() {
  for (ll i=1000; ;i++) {
    ll temp = divisorCount(triangleN(i));
    //cout<<temp<<endl;

/* start from 500 because a number can't have
more divisors than it's square root.
triangleN(500) = 125250 ~ 12*10^4 is a good
estimation to start from as 500^2 = 25*10^4*/
    if (temp >= 500) {
      cout << triangleN(i);
      break;
    } 
  }
}
