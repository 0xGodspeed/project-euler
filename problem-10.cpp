#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;

void printArr(vector<bool> arr) {
  for (int i = 0; i < arr.size(); i++) {
        std::cout << arr.at(i) << ' ';
    }
}
void simpleSieve(ll n, vector<int> &nprimes) {
  vector<bool> isPrime(n+1, true);
  isPrime[0] = isPrime[1] = false;
  for (ll i=2; i*i < n; i++) { 
    if (isPrime[i]) {
      for (ll j=i*i; j<=n; j+=i) {
        isPrime[j] = false;
      }
    }
  }
 
  for (ll i=2; i<=n; i++) {
    if (isPrime[i]) {
      nprimes.push_back(i);
      }
  } 
}

void segmentedSieve(ll n, vector<int> &nprimes) {
  vector<int> primes;
  ll s  = sqrt(n);
  simpleSieve(s, primes);
  ll high = 0;
  for (ll low=2; low <= n; low += s) {
    high = min(low+s-1, n-1);
    vector<bool> isPrime(high-low+1, true);
    for (ll p: primes) {
      ll m = (low/p)*p; 
      
      if (m < low) m+=p;
      if (m == p) m+=p;

      for (ll i=m; i<=high; i += p) {
        isPrime[i-low] = false;
      }
    }
    for (int i = 0; i < isPrime.size(); i++) {
      if (isPrime[i])
      {
          nprimes.push_back(i + low);
      }
    }
  }
}

int main() {
  vector<int> nprimes;
  ll n = 2000000;
  segmentedSieve(n, nprimes);
  ll sum = 0;
 // ll sum = accumulate(nprimes.begin(), nprimes.end(), 0LL);
  for (ll i=0; i <=nprimes.size(); i++) {
    sum += nprimes[i];
  }
  cout << sum;
  }
