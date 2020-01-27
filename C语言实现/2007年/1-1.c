#include <stdio.h>
#define Abs_Minus(a, b) (a) > (b) ? ((a) - (b)) : ((b) - (a))       //º«µ√º”¿®∫≈

int main(int argc, char const *argv[])
{
	printf("%d", Abs_Minus(4 - 1, 3 + 2));
	return 0;
}
