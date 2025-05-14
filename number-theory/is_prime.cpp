#include <bits/stdc++.h>

using namespace std;

// returns true if the number is prime and false if it is not in O(sqrt(N)).
// All prime numbers greater than 3 are of the form 6k+1 or 6k-1

bool isprime(int N){
	if(N <= 1) return false;
	if(N <= 3) return true;
	if(N % 2 == 0 || N % 3 == 0) return false;

	for(int i = 5; i*i <= N; i+= 6){
		if(N % i == 0 || N % (i + 2) == 0){
			return false;
		}
	}
	return true;
}
