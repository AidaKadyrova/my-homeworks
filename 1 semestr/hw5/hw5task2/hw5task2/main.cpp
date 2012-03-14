#include <stdio.h>

typedef unsigned long long ull;

bool getBit(ull a, int n) 
{
	return a & (1LL << n);
}

int main() 
{
	double d;
	while (true)
	{
		scanf("%lf", &d);
		ull* ptr = (ull*)&d;
		ull a = *ptr;
		for (int i = 0; i < 64; i++) 
		{
			if (i % 8 == 0) 
				printf(" ");
			printf("%d", (int)getBit(a, i));
		}
		printf("\n");
		if (getBit(a, 63)) //sign bit
			printf("-");
		ull e = ((a << 1) >> 53) - 1023;
		ull m = (a << 12) >> 12;
		double mantissa = 1, b = 0.5;
		for (int i = 51; i >= 0; i--) 
		{
			if (getBit(m, i)) 
				mantissa += b;
			b /= 2;
		}
		printf("%lf * 2^%d\n", mantissa, e);
	}
	return 0;
}