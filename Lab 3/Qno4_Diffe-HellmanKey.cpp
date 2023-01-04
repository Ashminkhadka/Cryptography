#include <bits/stdc++.h>
using namespace std;

int generate_secret_key() {
  return rand() % 100 + 1;
}

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

int main() {
  // Generate secret keys for Alice and Bob
  int alice_secret_key = generate_secret_key();
  int bob_secret_key = generate_secret_key();

  // Choose large prime p and primitive root g
  int p = 23;
  int g = 9;

  // Compute public keys
  long long alice_public_key = power(g, alice_secret_key, p);
  long long bob_public_key = power(g, bob_secret_key, p);

  // Exchange public keys
  long long alice_shared_key = power(bob_public_key, alice_secret_key, p);
  long long bob_shared_key = power(alice_public_key, bob_secret_key, p);

  // Check that the shared keys match
  if (alice_shared_key == bob_shared_key) {
    cout << "Shared key: " << alice_shared_key << endl;
  } else {
    cout << "Error: Shared keys do not match" << endl;
  }
  return 0;
}

