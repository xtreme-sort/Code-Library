#include <bits/stdc++.h>

using namespace std;

// returns true if the number is prime and false if it is not in O(sqrt(N)).
// All prime numbers greater than 3 are of the form 6k+1 or 6k-1

bool isprime(int n){
	if(n<=1) return false;
	if(n<=3) return true;
	if(n%2==0 || n%3==0) return false;

	for(int i = 5; i*i <= n; i+= 6){
		if(n % i == 0 || n % (i + 2) == 0){
			return false;
		}
	}
	return true;
}
