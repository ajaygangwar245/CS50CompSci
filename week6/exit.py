import sys

if len(sys.argv) != 2:
    print("Command-line Argument missing")
    sys.exit(1)

print(f"Hello, {sys.argv[1]}")
sys.exit(0)

