class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        simplified = []
        candidates = path.strip().split('/')
        for item in candidates:
            if len(item) <= 0 or item == ".":
                continue

            if item == "..":
                if len(simplified) > 0:
                    simplified.pop()
            else:
                simplified.append(item)
        return '/' + '/'.join(simplified)
