"""
You are given an array prices where prices[i] is
the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day
to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.
"""


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        best_price = 0
        min_price = prices[0]

        for price in prices:
            min_price = min_price if min_price<price else price
            best_price = best_price if best_price>price-min_price else price-min_price
        return best_price

print(Solution().maxProfit(prices=[7,1,5,3,6,4]))
print(Solution().maxProfit(prices=[7,6,4,3,1]))