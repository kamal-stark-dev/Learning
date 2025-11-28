# 121. Best Time to Buy and Sell Stock

def maxProfit_2Pointers(prices: list[int]) -> int:
    left, right = 0, 1
    maxP = 0

    while right < len(prices):
        if prices[left] < prices[right]:
            profit = prices[right] - prices[left]
            maxP = max(maxP, profit)
        else:
            left = right
        right += 1
    return maxP

def maxProfit(prices: list[int]) -> int:

    """ Brute Force - O(n^2)
    Max = 0
    for curr in range(len(prices)):
        for future in range(curr + 1, len(prices)):
            if prices[future] - prices[curr] > Max:
                Max = prices[future] - prices[curr]
    return Max
    """

    min_so_far = prices[0]
    profit = 0

    for price in prices[1:]:
        min_so_far = min(price, min_so_far)
        profit = max(profit, price - min_so_far)

    return profit


prices = [7, 1, 5, 3, 6, 4]
print('The maximum profit that can be obtained is: ', maxProfit_2Pointers(prices))

"""
Time Complexity: O(n)
Space Complexity: O(1) -> profit and min_so_far
"""