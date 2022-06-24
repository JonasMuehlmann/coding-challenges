#!/bin/python3

import math
import os
import random
import re
import sys
from typing import List

# Complete the profit function below.


if __name__ == "__main__":
    f = open(os.environ["OUTPUT_PATH"], "w")
    t = int(input())

    for t_itr in range(t):
        bsc = input().split()
        b = int(bsc[0])
        s = int(bsc[1])
        c = int(bsc[2])

        def profit(b, s, c):
            return b + s - c

        result = profit(b, s, c)
        f.write(str(result) + "\n")
    f.close()
