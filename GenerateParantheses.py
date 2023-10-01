# Given n pairs of parentheses, write a function to generate all 
# combinations of well-formed parentheses.

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # count of open op = n, count of close cl = n
        # op is always <= cl
        # first bracket is always op
        # all options are exhausted when op = 0 and cl = 0

        op = n
        cl = n

        res = []

        def genP(op, cl, curr):
            if(op > 0 or cl > 0):
                if(op == cl):
                    genP(op - 1, cl, curr + "(")

                elif(op < cl):
                    if(op > 0):
                        genP(op - 1, cl, curr + "(")
                    genP(op, cl - 1, curr + ")")

            else:
                res.append(curr)
        
        genP(n, n, "")

        return res