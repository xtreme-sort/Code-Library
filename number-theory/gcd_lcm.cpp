int gcd(int x, int y) {
	if (x == 0) return y;
	if (y == 0) return x;
	return gcd(y, x % y);
}


int lcm(int x,int y) {
    return (x*y)/gcd(x,y);
}