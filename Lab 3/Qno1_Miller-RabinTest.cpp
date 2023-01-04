#include <bits/stdc++.h>
using namespace std;

const int kMaxTests = 25; 

// Computes (x^y) % mod
long long power(long long x, long long y, long long mod) {
  long long result = 1;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % mod;
    }
    x = (x * x) % mod;
    y >>= 1;
  }
  return result;
}

bool is_prime(long long n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  long long d = n - 1;
  long long r = 0;
  while (d % 2 == 0) {
    r++;
    d /= 2;
  }

  // Perform the Miller-Rabin tests
  for (int i = 0; i < kMaxTests; i++) {
    long long a = rand() % (n - 2) + 2; 
    long long x = power(a, d, n);
    if (x == 1 || x == n - 1) continue;
    for (int j = 0; j < r - 1; j++) {
      x = (x * x) % n;
      if (x == n - 1) break;
    }
    if (x != n - 1) return false;
  }
  return true;
}

int main() {
  long long n;
  cout << "Enter a number: ";
  cin >> n;
  if (is_prime(n)) {
    cout << n << " is prime" << endl;
  } else {
    cout << n << " is not prime" << endl;
  }
  return 0;
}

