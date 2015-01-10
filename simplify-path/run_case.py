import solution

def main():
    paths = [
        "/",
        "/home//",
        "/a/./b/../../c/",
        "/home//foo/",
        "/../"
    ]
    op = solution.Solution().simplifyPath
    for item in paths:
        print item, "\t\t", op(item)

if __name__ == "__main__":
    main()
