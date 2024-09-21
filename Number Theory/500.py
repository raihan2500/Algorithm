import sys

def main():
    for line in sys.stdin:
        n = int(line)
        ans = 1
        for i in range (n):
            ans *= (i + 1)
        m = str (n)
        m += '!'
        print(m)
        print(ans)

if __name__ == "__main__":
    main()

