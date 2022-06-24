#!/bin/python3

import os
import sys


def connectingTowns(n, routes):
    result = 1

    for i in range(len(routes)):
        result = result * routes[i] % 1234567

    return result


if __name__ == "__main__":
    fptr = open(os.environ["OUTPUT_PATH"], "w")

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        routes = list(map(int, input().rstrip().split()))

        result = connectingTowns(n, routes)

        fptr.write(str(result) + "\n")

    fptr.close()
