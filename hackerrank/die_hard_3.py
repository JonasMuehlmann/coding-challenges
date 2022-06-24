#!/bin/python3

import os
import sys


def gcd(a, b):
    if a < b:
        return gcd(b, a)

    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def solve(a, b, c):
    d = max(a, b)
    g = gcd(a, b)

    if d >= c and c % g == 0:
        return "YES"
    else:
        return "NO"


if __name__ == "__main__":
    fptr = open(os.environ["OUTPUT_PATH"], "w")

    t = int(input())

    for t_itr in range(t):
        abc = input().split()

        a = int(abc[0])

        b = int(abc[1])

        c = int(abc[2])

        result = solve(a, b, c)

        fptr.write(result + "\n")

    fptr.close()
