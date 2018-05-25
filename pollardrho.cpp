/* MIT License, (c) 2018 Albert N Bulik */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

typedef long long llong;
llong seed;

llong gcd(llong a, llong b)
{
	llong remainder;
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

llong g(llong x, llong n) //generative function
{
	return (x * x + 1) % n; //some polynomial modulo n
}

llong rho(llong n)
{
	llong x_i = seed, x_j = seed, p = 1;
	while (p == 1) {
		x_i = g(x_i, n);
		x_j = g(g(x_j, n), n);
		p = gcd(llabs(x_j - x_i), n);
	}
	if (n == p) {
		std::cout << " " << p;
		throw std::invalid_argument("Bad seed or end of factorization");
	} else
		return p;
}

void factorize(llong n) {
	try {
		factorize(rho(n));
		factorize(n / rho(n));
	} catch(const std::invalid_argument& e) {
		return;
	}
}

int main()
{
	std::cout << "Please enter a number to prime factorize: ";
	llong n;
	std::cin >> n;
	std::cout << "Enter seed value: ";
	std::cin >> seed;

	std::cout << "Factors:";
	factorize(n);

	return 0;
}
