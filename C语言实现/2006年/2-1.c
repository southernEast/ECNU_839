#include <stdio.h>
#include <stdlib.h>

int Check(int d[], int n);
int Check1(int d[], int n);

int main(int argc, char const *argv[])
{
	int d[8] = {1, -2, 3, -4, 5, -6, 7, -8};
	printf("%d %d\n", Check(d, 8), Check1(d, 8));

	return 0;
}

int Check(int d[], int n)
{
    int flag = 1;
	for(int i = 0; i < n - 1 && flag != 0; i++)
	{
		if(abs(d[i]) >= abs(d[i + 1]))
			flag = 0;
		if(d[i] * d[i + 1] > 0)             //相乘大于零，同号
			flag = 0;
	}
	return flag;
}

int Check1(int d[], int n)
{
    int i = 0;
    while(i < n - 1)
    {
        if(abs(d[i]) < abs(d[i + 1]) && d[i] * d[i + 1] < 0)
            i++;
        else
            return 0;
    }

    return 1;
}
