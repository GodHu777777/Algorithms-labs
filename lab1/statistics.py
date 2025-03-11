import subprocess
import time 
import sys

N = 20

t = 100

nums = [0] * t

# # print size of nums
# print(len(nums))

print("DEBUG" + sys.argv[1])

for i in range(t):
    # execute the program and capture the output
    result = subprocess.run([sys.argv[1]], capture_output=True, text=True)

    val = result.stdout.strip()
    val = int(val)
    nums[i] = val / (N * N) 
    print(nums[i])
    # wait 1 second
    time.sleep(1)
    
print("DEBUG")
print(sum(nums))
print("t: ", t)
# print the average
print("mean: ", 1.0 * sum(nums) / t)


# print the standard deviation variance
mean = sum(nums) / t
variance = sum([((x - mean) ** 2) for x in nums]) / t
res = variance ** 0.5
print("Var: ", res)
