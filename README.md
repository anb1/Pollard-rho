# Pollard-rho
This exercise is an implementation of John Pollard's rho algorithm, produced from a description found on Wikipedia.

https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm

The purpose of the algorithm is to factorize integers in a way similar to Floyd's cycle finding algorithm. Floyd's algorithm says if two indices move through a sequence of periodic values at different rates, then they eventually converge on the same value (the difference of the indices being the length of a period, or a multiple thereof).

Pollard's algorithm generates a sequence by composing a function with itself. The function must be some non-constant polynomial modulo n, where n is the number being factorized. The function in this program is defined as g(x) = x^2 + 1 mod n. [pollardrho.cpp, lines 21-24]

One index is composed at twice the rate of the other index [lines 30-31] and if either index exceeds the value of of n, then the modulus operation returns only the remainder <n. Every time a new set of indices is evaluated, their difference is compared to n; and if the two have a greatest common factor other than 1 [line 32], then a new factor of n is located. 

The procedure is repeated until n can no longer be factored. This occurs if all the prime factors of n have been found, or if the difference between the index values is equal to (or a multiple of) the number being factored before all the prime factors have been found. The latter condition is an issue because the indices will have identical values after the remainder is taken; when the difference is calculated, no new unique factors will be produced by the gcd() operation. Therefore, the program must compare the values of n and potential factor p [line 34], and self-terminate if they are equal. 
