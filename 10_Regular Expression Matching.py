#I love python
import re
class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        return bool(re.match("^" + p + "$", s))

