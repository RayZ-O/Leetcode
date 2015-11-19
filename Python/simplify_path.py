# Given an absolute path for a file (Unix-style), simplify it.

# For example,
# path = "/home/", => "/home"
# path = "/a/./b/../../c/", => "/c"

import os

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        return os.path.abspath(path)
