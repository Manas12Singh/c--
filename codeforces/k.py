MOD = 10**9 + 7

def count_colorings(w):
    max_w = max(w)  # Maximum width to determine the DP table size
    
    if max_w == 0:
        return 1  # If all widths are zero, there's only one way (no coloring)
    
    dp = [{} for _ in range(8)]  # DP table for 7 rows (1-based indexing)
    dp[0][0] = 1  # Base case: No borders painted at the start
    
    for i in range(7):
        current_w = w[i]  # Width at the current height
        
        for mask, ways in dp[i].items():  # Iterate over all valid states of the previous row
            for new_mask in range(1 << current_w):  # Generate all valid colorings for current row
                valid = True
                
                for j in range(current_w):
                    if (new_mask & (1 << j)) and (mask & (1 << j)) and (j > 0 and new_mask & (1 << (j - 1)) and mask & (1 << (j - 1))):
                        valid = False  # Ensure no square has all borders colored
                        break
                
                if valid:
                    dp[i + 1][new_mask] = (dp[i + 1].get(new_mask, 0) + ways) % MOD
    
    return sum(dp[7].values()) % MOD

# Read input
w = list(map(int, input().split()))
print(count_colorings(w))
