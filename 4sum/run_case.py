import solution_prune as solution
import sys
import importlib

if __name__ == "__main__":
    if len(sys.argv) != 1:
        importlib.import_module(sys.argv[1])
        solution = sys.modules[sys.argv[1]]
        print globals()
    
    S = [-493,-470,-464,-453,-451,-446,-445,-407,-406,-393,-328,-312,-307,-303,-259,-253,-252,-243,-221,-193,-126,-126,-122,-117,-106,-105,-101,-71,-20,-12,3,4,20,20,54,84,98,111,148,149,152,171,175,176,211,218,227,331,352,389,410,420,448,485]
    target = 1057
    S.sort()
    print S
    results = solution.Solution().fourSum(S, target)
    print results
    print solution.__file__
