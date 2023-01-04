#include <bits/stdc++.h>
using namespace std;

// Computes the Euler totient function of n
int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      result -= result / i;
    }
  }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  cout << "phi(" << n << ") = " << phi(n) << endl;
  return 0;
}

