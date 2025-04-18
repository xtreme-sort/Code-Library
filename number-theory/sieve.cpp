#include<bits/stdc++.h>
using namespace std;

bool prime[15000105];

void sieve(int n) { 
	for (int i = 0; i <= n; i++) prime[i] = true;

	for (int p = 2; p * p <= n; p++) { 
	if (prime[p] == true) { 
		for (int i = p * p; i <= n; i += p) 
			prime[i] = false; 
		} 
	} 
	prime[1] = prime[0] = 0;
}


vector<int> primelist;
bool __primes_generated__ = 0;
	 
void genprimes(int n) {
	__primes_generated__ = 1;
	sieve(n + 1);
	for (int i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
}

