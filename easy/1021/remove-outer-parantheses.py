class Solution(object):
    def removeOuterParentheses(self, S):
        """
        :type S: str
        :rtype: str
        """
        open_counter = 0
        new_string = ""
        for i in range(len(S)):
            if S[i] == "(":
                if open_counter != 0:
                    new_string += S[i]
                open_counter += 1
            elif S[i] == ")":
                if open_counter != 1:
                    new_string += S[i]
                open_counter -= 1
        return new_string
