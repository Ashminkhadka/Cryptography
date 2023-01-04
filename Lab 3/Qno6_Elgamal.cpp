#include <bits/stdc++.h>
using namespace std;

long long generate_prime(long long start, long long end) {
  while (true) {
    long long p = rand() % (end - start + 1) + start;
    if (is_prime(p)) {
      return p;
    }
  }
}

// Generates a random generator of the prime p
long long generate_generator(long long p) {
  long long phi = p - 1;
  long long g = rand() % (p - 1) + 1; 
  for (long long i = 2; i < phi; i++) {
    if (power(g, i, p) == 1) {
      return -1; 
    }
  }
  return g;
}

// Generates a private and public key pair for the Elgamal Cryptographic System
void generate_key_pair(long long &private_key, long long &public_key, long long &g, long long &p) {
  p = generate_prime(1e9, 1e10);
  g = generate_generator(p);
  private_key = rand() % (p - 1) + 1; 
  public_key = power(g, private_key, p);
}

// Encrypts a message using the Elgamal Cryptographic System
pair<long long, long long> encrypt(long long message, long long public_key, long long g, long long p) {
  long long k = rand() % (p - 1) + 1;
  long long a = power(g, k, p);
  long long b = (message * power(public_key, k, p)) % p;
  return make_pair(a, b);
}

// Decrypts a message using the Elgamal Cryptographic System
long long decrypt(pair<long long, long long> ciphertext, long long private_key, long long p) {
  long long a = ciphertext.first;
  long long b = ciphertext.second;
  return (b * modular_inverse(power(a, private_key, p), p)) % p;
}

int main() {
  long long private_key, public_key, g, p;
  generate_key_pair(private_key, public_key, g, p);

  long long message;
  cout << "Enter a message: ";
  cin >> message;

  pair<long long, long long> ciphertext = encrypt(message, public_key, g, p);
  cout << "Ciphertext: (" << ciphertext.first << ", " << ciphertext.second << ")" << endl;

  long long decrypted = decrypt(ciphertext, private_key, p);
  cout << "Decrypted: " << decrypted << endl;

  return 0;
}

