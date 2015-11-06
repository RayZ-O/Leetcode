#!/usr/bin/env python
# Given a list of words and two words word1 and word2, return the shortest distance between
# these two words in the list.

# For example,
# Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

# Given word1 = “coding”, word2 = “practice”, return 3.
# Given word1 = "makes", word2 = "coding", return 1.

# Note:
# You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1 = [i for i, x in enumerate(words) if x == word1]
        l2 = [j for j, y in enumerate(words) if y == word2]
        return min([abs(i - j) for i in l1 for j in l2])
