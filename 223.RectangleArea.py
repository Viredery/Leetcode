class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        return (C - A) * (D - B) + (G - E) * (H - F) \
          - (0 if C <= E or D <= F or A >= G or B >= H else (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)))