#include <bits/stdc++.h>
using namespace std;

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

long long modular_inverse(long long x, long long mod) {
  long long t = 0;
  long long newt = 1;
  long long r = mod;
  long long newr = x;
  while (newr != 0) {
    long long quotient = r / newr;
    t -= quotient * newt;
    swap(t, newt);
    r -= quotient * newr;
    swap(r, newr);
  }
  if (t < 0) {
    t += mod;
  }
  return t;
}

// Generates a random prime number in the range [start, end]
long long generate_prime(long long start, long long end) {
  while (true) {
    long long p = rand() % (end - start + 1) + start;
    if (is_prime(p)) {
      return p;
    }
  }
}
void generate_key_pair(long long &public_key, long long &private_key, long long &n) {
  long long p = generate_prime(1e9, 1e10);
  long long q = generate_prime(1e9, 1e10);
  n = p * q;
  long long phi = (p - 1) * (q - 1);
  public_key = 3;  
  private_key = modular_inverse(public_key, phi);
}

// Encrypts a message using the RSA algorithm
long long encrypt(long long message, long long public_key, long long n) {
  return power(message, public_key, n);
}

// Decrypts a message using the RSA algorithm
long long decrypt(long long ciphertext, long long private_key, long long n) {
  return power(ciphertext, private_key, n);
}

int main() {
  long long public_key, private_key, n;
  generate_key_pair(public_key, private_key, n);

  long long message;
  cout << "Enter a message: ";
  cin >> message;

  long long ciphertext = encrypt(message, public_key, n);
  cout << "Ciphertext: " << ciphertext << endl;

  long long decrypted = decrypt(ciphertext, private_key, n);
  cout << "Decrypted: " << decrypted << endl;

  return 0;
}

