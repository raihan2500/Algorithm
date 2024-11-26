# Even after moding a big number if there still a common devisor of both number it will show
int n = 3 * 7;
int x = 9187317312927 * 7;
x %= n;

gcd(x, n) == 7 now
although we are using mod if there is an