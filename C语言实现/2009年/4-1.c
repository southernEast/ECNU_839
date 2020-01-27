/************        Caution !!       ************/
/************        4-1.exe 4-1.c       ************/
/************        Caution !!       ************/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "rb");

    char visibleBuff[17] = {0};							// memset(visibleBuff, 0, 17);
    //char visibleBuffLen = 0;

    unsigned int pos = 0;
    int ch;

    while((ch = fgetc(fp)) != EOF)                      //使用 ch = fgetc{fp} != EOF 代替 !feof(fp) 判断文件结尾
    {

        if (pos % 16 == 0)                              // 16个字节数据
        {
            printf("%08x   ", pos);
            for(int i = 0; i < 17; i ++)
                visibleBuff[i] = 0;
        }

//        ch = fgetc(fp);

        printf("%02x ", ch);

        if (ch >= 32 && ch <= 126)
            visibleBuff[pos % 16] = (char)ch;
        else
            visibleBuff[pos % 16] = '.';

        pos ++;

        if (pos % 8 == 0)
            printf(" ");

        if (pos % 16 == 0)
        {
            printf("%s\n", visibleBuff);
        }
    }

    if(pos % 16 != 0)                           //处理最后一行未满情况
    {
        if(pos % 16 < 8)
            printf(" ");
        while(pos % 16 != 0)
        {
            printf("   ");                     //每个输出不可显示部分，2 * 数字 + 空格 = 3空格
            pos++;
        }
        printf(" ");
        printf("%s\n", visibleBuff);
    }
    fclose(fp);

    return 0;
}
