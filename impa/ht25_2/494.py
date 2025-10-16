import re
import sys

for line in sys.stdin:
    words = re.findall(r"[A-Za-z]+", line)
    print(len(words))