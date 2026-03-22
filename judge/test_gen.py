import random

def generate_test(n=100000, q=100000, max_val=100000, seed=None):
    if seed is not None:
        random.seed(seed)

    # Print n and q
    print(n, q)

    # Generate array of n integers
    arr = [random.randint(1, max_val) for _ in range(n)]
    print(" ".join(map(str, arr)))

    # Generate q queries
    for _ in range(q):
        l = random.randint(1, n)
        r = random.randint(1, n)
        if l > r:
            l, r = r, l
        x = random.randint(1, max_val)
        print(l, r, x)


if __name__ == "__main__":
    # Example: generate a stress test with n=10^5, q=10^5
    generate_test(n=100000, q=100000, max_val=100000, seed=42)
