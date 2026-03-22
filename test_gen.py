import random
import sys
sys.stdout = open("testcase.out" , "w")
m = 1000
n = 1000
print (m , end = " ")
print(n)
for i in range(0 , m):
    for i in range(0,n):
        t = random.randint(1 , 20)
        print(t , end = " ")
    print()
