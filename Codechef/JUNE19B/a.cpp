// C++ program to do modular division 
#include<iostream> 
using namespace std; 

// C function for extended Euclidean Algorithm 
uint64_t gcdExtended(uint64_t a, uint64_t b, uint64_t *x, uint64_t *y); 

// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
uint64_t modInverse(uint64_t b, uint64_t m) 
{ 
	uint64_t x, y; // used in extended GCD algorithm 
	uint64_t g = gcdExtended(b, m, &x, &y); 

	// Return -1 if b and m are not co-prime 
	if (g != 1) 
		return -1; 

	// m is added to handle negative x 
	return (x%m + m) % m; 
} 

// Function to compute a/b under modlo m 
void modDivide(uint64_t a, uint64_t b, uint64_t m) 
{ 
	a = a % m; 
	uint64_t inv = modInverse(b, m); 
	if (inv == -1) 
	cout << "Division not defined"; 
	else
	cout << "Result of division is " << (inv * a) % m; 
} 

// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
uint64_t gcdExtended(uint64_t a, uint64_t b, uint64_t *x, uint64_t *y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	} 

	uint64_t x1, y1; // To store results of recursive call 
	uint64_t gcd = gcdExtended(b%a, a, &x1, &y1); 

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
} 

// Driver Program 
int main() 
{ 
	uint64_t a = 8, b = 2, m = 1000000007; 
	modDivide(a, b, m); 
	return 0; 
} 
