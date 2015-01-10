import solution

def main():
    cases = [ "A man, a plan, a canal: Panama",
                "race a car"
            ]

    op = solution.Solution().isPalindrome
    for _ in xrange(10000):
        for item in cases:
            #print op(item), "\t", item
            op(item)

if __name__ == "__main__":
    main()
