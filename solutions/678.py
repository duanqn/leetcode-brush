class Solution:
    def checkValidString(self, s: str) -> bool:
        # We treat '(' as +1 and ')' as -1.
        # So '*' can be +1, -1, or 0.
        minScore = [0] * (len(s) + 1)
        maxScore = [0] * (len(s) + 1)
        minScore[len(s)] = 0
        maxScore[len(s)] = 0
        index = len(s) - 1
        while index >= 0:
            if s[index] == '(':
                minScore[index] = minScore[index+1] - 1
                maxScore[index] = maxScore[index+1] - 1
                if minScore[index] < 0:
                    minScore[index] = 0
                if maxScore[index] < 0:
                    return False
            elif s[index] == ')':
                minScore[index] = minScore[index+1] + 1
                maxScore[index] = maxScore[index+1] + 1
            elif s[index] == '*':
                minScore[index] = minScore[index+1] - 1
                maxScore[index] = maxScore[index+1] + 1
                if minScore[index] < 0:
                    minScore[index] = 0
                if maxScore[index] < 0:
                    return False
            index -= 1

        # Valid strings must have score 0.
        return minScore[0] <= 0 and maxScore[0] >= 0

if __name__ == '__main__':
    s = Solution()
    assert s.checkValidString('()') == True
    assert s.checkValidString(')(') == False
    assert s.checkValidString('(*)') == True
    assert s.checkValidString('(*))') == True
    assert s.checkValidString('(())((())()()(*)(*()(())())())()()((()())((()))(*') == False
    assert s.checkValidString('(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())') == False
    assert s.checkValidString('(()(()))(()()()))))((((()*()*(())())(()))((*()(*((*(*()))()(())*()()))*)*()))()()(())()(()))())))') == False
    
    print('Verified')
