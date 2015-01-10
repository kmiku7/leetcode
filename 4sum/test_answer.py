import unittest
import solution_prune as solution
import sys
import importlib

class TestSolutionCase(unittest.TestCase):
    def sort_and_assert_equal(self, left, right):
        left.sort()
        right.sort()
        self.assertEqual(left, right)
    def test_case_1(self):
        S = [1, 0, -1, 0, -2, 2]
        target = 0
        answer = [[-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2]]
        results = solution.Solution().fourSum(S, target)
        self.sort_and_assert_equal(answer, results)

    def test_case_2(self):
        S = [1,-2,-5,-4,-3,3,3,5]
        target = -11
        results = solution.Solution().fourSum(S, target)
        answer = [[-5,-4,-3,1]]
        self.sort_and_assert_equal(answer, results)


if __name__ == "__main__":
    if len(sys.argv) != 1:
        importlib.import_module(sys.argv[1])
        solution = sys.modules[sys.argv[1]]
        sys.argv = sys.argv[:1]
    unittest.main()
