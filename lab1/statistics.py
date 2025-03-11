import subprocess
import time
import sys
import math

N = 20
T = 100
nums = [0] * T

for i in range(T):
    # Execute the program and capture the output
    result = subprocess.run([sys.argv[1]], capture_output=True, text=True)
    val = result.stdout.strip()
    val = int(val)
    nums[i] = val / (N * N)
    print(nums[i])
    # Wait 1 second
    time.sleep(1)

# print("DEBUG")
# print(sum(nums))
# print("t: ", T)
# Print the average

print("Statistics of", sys.argv[1][2:], "# N = ", N, "T = ", T)

print("mean: ", 1.0 * sum(nums) / T)

# Calculate the standard deviation variance
mean = sum(nums) / T
variance = sum([(x - mean) ** 2 for x in nums]) / T
stddev = math.sqrt(variance)
print("stddev: ", stddev)

# Calculate the 95% confidence interval
z_score = 1.96  # for 95% confidence level
margin_of_error = z_score * (stddev / math.sqrt(T))
confidence_low = mean - margin_of_error
confidence_high = mean + margin_of_error
print("confidenceLow: ", confidence_low)
print("confidenceHigh: ", confidence_high)
