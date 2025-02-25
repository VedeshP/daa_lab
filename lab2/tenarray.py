import random

size = 10000
arr = [random.randint(0, 100000) for _ in range(size)]

# Format the array for C
c_array = "int arr[10000] = {" + ", ".join(map(str, arr)) + "};"

# Save to a file (optional)
with open("tenarr.txt", "w") as f:
    f.write(c_array)