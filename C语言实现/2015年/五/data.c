//此答案有问题
#include <stdio.h>
#include <string.h>
#define COL 36                                          // n为3~6，故n*n最大为36

int Read_Data(char *filename, int data[][COL]);
void Print(int data[][COL], int n);
void Check(int data[][COL], int n);

int main(int argc, char const *argv[])
{
	int data[COL][COL], n;
	n = Read_Data("dataIn.txt", data);
	Print(data, n);
	Check(data, n);
	return 0;
}

int Read_Data(char *filename, int data[][COL])          //读入文件中的数据
{
	FILE *fp;
	int n;
	if((fp = fopen(filename, "r")) != NULL)
	{
		if(fscanf(fp, "%d", &n) == 1)                   //使用fscanf()函数可免于字符转换
		{
			for(int i = 0; i < n*n; i++)
			{
				for(int j = 0; j < n*n; j++)
					fscanf(fp, "%d", &data[i][j]);
			}
		}
	}
	fclose(fp);
	return n;
}

void Print(int data[][COL], int n)
{
	for(int i = 0; i < n * n; i++)
	{
		for(int j = 0; j < n*n; j++)
		{
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
}

void Check(int data[][COL], int n)
{
    int checks[COL + 1], flag = 1;
    memset(checks, 0, sizeof(checks));              //标记数组清零
    for(int i = 0; i < n*n; i ++)                   //检测行与列的数字出现情况
    {                                               //注：若满足数独，每个数字在行和列中应各自出现n次
        for(int j = 0; j < n*n; j ++)
        {
            checks[data[i][j]]++;
            checks[data[j][i]]++;
        }
    }
    for(int i = 0; i < n*n; i += n)                 //检测小数组情况
    {                                               //以n = 3为例：
        for(int j = 0; j < n*n; j += n)             //i和j控制小数组的变化其分为列和行各三块，共九块
        {                                           //k和l控制每个小数组里面的变化，其内部也共九块
            for(int k = 0; k < 3; k ++)
            {
                for(int l = 0; l < 3; l ++)
                {
                    checks[data[i + k][j + l]]++;
                }
            }
        }
    }
    for(int i = 1; i <= n * n; i++)               //测试用
        printf("%d\n", checks[i]);
    for(int i = 1; i <= n * n; i++)
    {
        if(checks[i] != n * n * n)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
        printf("Yes\n");
    else
        printf("No\n");
}

