import solution

def main():
    A = [
            [
             [ 1, 2, 3 ],
             [ 4, 5, 6 ],
             [ 7, 8, 9 ]
            ],
            [[2,3]],
        ]
    op = solution.Solution().spiralOrder
    for item in A:
        print "-" * 20
        print item
        print op(item)

if __name__ == "__main__":
    main()
