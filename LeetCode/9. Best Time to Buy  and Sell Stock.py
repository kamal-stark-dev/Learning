# 121. Best Time to Buy and Sell Stock

def maxProfit(prices: list[int]) -> int:

    """ Brute Force - O(n^2)
    Max = 0
    for curr in range(len(prices)):
        for future in range(curr + 1, len(prices)):
            if prices[future] - prices[curr] > Max:
                Max = prices[future] - prices[curr]
    return Max
    """

    """ Time - O(n) and Space - O(1)
    left, right = 0, 1
    profit_so_far = 0

    while right < len(prices):
        if prices[right] < prices[left]:
            left = right

        if prices[right] > prices[left] and profit_so_far < prices[right] - prices[left]:
            profit_so_far = prices[right] - prices[left]

        right += 1

    return profit_so_far
    """

    min_so_far = prices[0]
    profit = 0

    for i in prices[1:]:
        if i < min_so_far:
            min_so_far = i
        if profit < i - min_so_far:
            profit = i - min_so_far

    return profit


prices = [7, 1, 5, 3, 6, 4]
print(maxProfit(prices))

"""
Time Complexity: O(n)
Space Complexity: O(1) -> profit and min_so_far
"""