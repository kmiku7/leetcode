import solution

def main():
    op = solution.Solution().candy
    A = [1,2,3,3,4,4,3,2,1]
    print A
    for _ in xrange(10000):
        op(A)

    A = [4,2,3,4,1]
    print A
    for _ in xrange(10000):
        op(A)

if __name__ == "__main__":
    main()
