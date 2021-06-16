/*#include <bits/stdc++.h>

using namespace std;

long long sum_of_digits(long long N)
{
	if(N < 10)
		return N;

	return N % 10 + sum_of_digits(N / 10);
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		long long N;
		cin >> N;

		long long rem = sum_of_digits(N) % 10;
		long long unit_digit = (rem) ? (10 - rem): rem;
		long long req_num = N * 10 + unit_digit;
		cout << req_num << '\n';
	}
	return 0;
}
*/
#include <stdio.h>
#include <inttypes.h>

int main()
{
  int t;

  puts("enter T");
  if ((scanf("%d", &t) != 1) || (t < 0))
    puts("invalid number of test cases, abort");
  else {
    while (t--) {
      uint64_t n;

      puts("enter N");
      while ((scanf("%" SCNu64, &n) != 1) || (n == 0)) {
        /* flush line */
        int c;

        while ((c = getchar()) != '\n') {
          if (c == EOF)
            return -1;
        }

        puts("invalid N (uint_64 != 0 expected), reenter N");
      }

      /* search first round >= N*10 */
      uint64_t v = n*10-1;
      uint64_t s;

      do {
        /* round ? */
        uint64_t vv = ++v;

        s = 0;

        while (vv != 0) {
          s += vv%10;
          vv /= 10;
        }
      } while ((s % 10) != 0);

      printf("round #%" PRIu64 ": %" PRIu64 "\n", n, v);
    }
  }

  return 0;
}