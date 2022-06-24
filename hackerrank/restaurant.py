#!/bin/python3

import os
import sys


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


def restaurant(l, b):
    common_divisor = gcd(l, b)

    return (l // common_divisor) * (b // common_divisor)


if __name__ == "__main__":
    fptr = open(os.environ["OUTPUT_PATH"], "w")

    t = int(input())

    for t_itr in range(t):
        lb = input().split()

        l = int(lb[0])

        b = int(lb[1])

        result = restaurant(l, b)

        fptr.write(str(result) + "\n")

    fptr.close()
