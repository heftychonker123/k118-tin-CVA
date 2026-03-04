import random
import sys

sys.stdout = open("tsp.inp" , "w")

m = 10

n = 12
print(m , end = " ")
print(n)
for i in range(m):
    for j in range(n):
        temp = random.randint(-100 , 100)
        print(temp , end=" ")
    print("")

