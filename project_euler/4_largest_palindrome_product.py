#!/bin/python

max_factor = 999
min_factor = 100


def reversed(n):
    reversed = 0

    while n > 0:
        reversed = (10 * reversed) + n % 10
        n //= 10

    return reversed


def is_palindrome(n):
    return reversed(n) == n


def largest_palindrome(max_factor):
    largest_palindrome_yet = 0

    a = max_factor

    for a in range(max_factor, min_factor, -1):
        # Begin: hardcode for 3 digits
        # Largest palindrome can be represented as:
        #   P=100000x+ 10000y +1000z+ 100z+ 10y+ x
        # Combining like terms yields:
        #   P=100001x +10010y +1100z
        # Factoring out the GCD yields:
        #   P=11 * (9091x +910y +100z)

        # Since 11 is prime at least one of the numbers a,b must be a multiple of 11
        if a % 11 == 0:
            b = max_factor
            stepsize_b = 1
        else:
            # Largest Number b where b <= max_factor  and b % 11 == 0
            b = max_factor - 9
            stepsize_b = 11
        for b in range(b, a, -stepsize_b):
            # End: hardcode for 3 digits
            product = a * b
            # Largest palindrome found in current or previous iteration
            if product <= largest_palindrome_yet:
                break
            if is_palindrome(product):
                largest_palindrome_yet = product

    return largest_palindrome_yet


print(largest_palindrome(max_factor))
