#include <bits/stdc++.h>
using namespace std;

// Finds a primitive root of the prime p
int primitive_root(int p) {
  vector<int> factors;
  int phi = p - 1;
  for (int i = 2; i * i <= phi; i++) {
    if (phi % i == 0) {
      factors.push_back(i);
      while (phi % i == 0) {
        phi /= i;
      }
    }
  }
  if (phi > 1) {
    factors.push_back(phi);
  }

  for (int r = 2; r <= p; r++) {
    bool flag = true;
    for (int i = 0; i < factors.size() && flag; i++) {
      flag = power(r, (p - 1) / factors[i], p) != 1;
    }
    if (flag) {
      return r;
    }
  }
  return -1;
}

int main() {
  int p;
  cout << "Enter a prime number: ";
  cin >> p;
  int r = primitive_root(p);
  if (r == -1) {
    cout << "No primitive root found" << endl;
  } else {
    cout << "Primitive root: " << r << endl;
  }
  return 0;
}

