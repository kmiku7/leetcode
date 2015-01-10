import solution

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    print solution.Solution().minDepth(root)

if __name__ == "__main__":
    main()
