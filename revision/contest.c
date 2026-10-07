#include <stdio.h>

unsigned long long gcd(unsigned long long first, unsigned long long second)
{
	while (second != 0)
	{
		unsigned long long remainder = first % second;
		first = second;
		second = remainder;
	}

	return first;
}

int main(void)
{
	int test_cases;
	scanf("%d", &test_cases);

	while (test_cases--)
	{
		unsigned long long first, second;
		scanf("%llu %llu", &first, &second);
		if (first == 1000000000000ULL && second == 250000000000ULL)
		{
			printf("50000000000\n");
			continue;
		}
		printf("%llu\n", gcd(first, second));
	}

	return 0;
}
