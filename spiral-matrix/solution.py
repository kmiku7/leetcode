class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        results = []
        if len(matrix) <= 0:
            return results

        row_begin = 0
        row_end = len(matrix)
        col_begin = 0
        col_end = len(matrix[0])
        
        operators = []
        
        def forward_on_row(results, row_begin, row_end, col_begin, col_end):
            row_idx = row_begin
            for col_idx in xrange(col_begin, col_end):
                results.append(matrix[row_idx][col_idx])
            return row_begin+1, row_end, col_begin, col_end
        operators.append(forward_on_row)

        def forward_on_col(results, row_begin, row_end, col_begin, col_end):
            col_idx = col_end - 1
            for row_idx in xrange(row_begin, row_end):
                results.append(matrix[row_idx][col_idx])
            return row_begin, row_end, col_begin, col_end-1
        operators.append(forward_on_col)

        def backward_on_row(results, row_begin, row_end, col_begin, col_end):
            row_idx = row_end - 1
            for col_idx in xrange(col_end-1, col_begin-1, -1):
                results.append(matrix[row_idx][col_idx])
            return row_begin, row_end-1, col_begin, col_end
        operators.append(backward_on_row)

        def backward_on_col(results, row_begin, row_end, col_begin, col_end):
            col_idx = col_begin
            for row_idx in xrange(row_end-1, row_begin-1, -1):
                results.append(matrix[row_idx][col_idx])
            return row_begin, row_end, col_begin+1, col_end
        operators.append(backward_on_col)

        operator_idx = 0
        while row_begin < row_end and col_begin < col_end:
            operator = operators[operator_idx]
            row_begin, row_end, col_begin, col_end = \
                operator(results, row_begin, row_end, col_begin, col_end)
            operator_idx = (operator_idx + 1) % 4
        return results
                
            
