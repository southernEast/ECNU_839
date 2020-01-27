FILE *fopen( const char * filename, const char * mode );		//失败返回NULL
fp = fopen("test.txt", "w");									//示例

int fclose( FILE *fp );		//成功关闭文件，函数返回零，关闭文件时发生错误，函数返回 EOF

int fgetc( FILE * fp );		//从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符
 							//如果发生错误则返回 EOF
 							
int getc(FILE *stream);		//从指定的流 stream 获取下一个字符（一个无符号字符）
							//并把位置标识符往前移动，与fgetc区别在于这个是宏定义的

int getchar(void);			//从标准输入 stdin 获取一个字符（一个无符号字符）

int fputs(const char *str, FILE *stream)			//把字符串写入到指定的流 stream 中，但不包括空字符
fputs("This is C", fp);								//示例

char *fgets(char *str, int n, FILE *stream)			
// 从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，
// 或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。
// str -- 这是指向一个字符数组的指针，该数组存储了要读取的字符串。
// n -- 这是要读取的最大字符数（包括最后的空字符）。通常是使用以 str 传递的数组长度。
// stream -- 这是指向 FILE 对象的指针，该 FILE 对象标识了要从中读取字符的流。
fgets (str, 60, fp);								//示例，如果成功，该函数返回相同的 str 参数，否则返回一个空指针

int fscanf(FILE *stream, const char *format, ...)	//从流 stream 读取格式化输入
fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);	//示例，记住&

nt fprintf(FILE *stream, const char *format, ...) 	//发送格式化输出到流 stream 中
fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);//示例

int sprintf(char *str, const char *format, ...)		//发送格式化输出到 str 所指向的字符串
char str[80];
sprintf(str, "Pi 的值 = %f", PI);					//示例

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
// ptr -- 这是指向要被写入的元素数组的指针，可以是结构体。
// size -- 这是要被写入的每个元素的大小，以字节为单位。
// nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
// stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。
// 如果成功，该函数返回一个 size_t 对象，表示元素的总数，该对象是一个整型数据类型。如果该数字与 nmemb 参数不同，则会显示一个错误。
// char str[] = "This is runoob.com";
char str[] = "Test string"; 
fp = fopen( "file.txt" , "w" );
fwrite(str, sizeof(str) , 1, fp );					//示例

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) 
// ptr -- 这是指向带有最小尺寸 size*nmemb 字节的内存块的指针。
// size -- 这是要读取的每个元素的大小，以字节为单位。
// nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
// stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输入流。		
// 成功读取的元素总数会以 size_t 对象返回
fread(buffer, sizeof(str), 1, fp);					//示例

void *memcpy(void *str1, const void *str2, size_t n)	// 从存储区 str2 复制 n 个字符到存储区 str1
// str1 -- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
// str2 -- 指向要复制的数据源，类型强制转换为 void* 指针。
// n -- 要被复制的字节数。
memcpy(&inBuff[i], &tempBuff[randNum[i]], sizeof(struct msgNode));		//示例

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
// base -- 指向要排序的数组的第一个元素的指针。
// nitems -- 由 base 指向的数组中元素的个数。
// size -- 数组中每个元素的大小，以字节为单位。
// compar -- 用来比较两个元素的函数。
// a b 前后顺序正常，则为从小到大
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}													//示例

void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
// key -- 指向要查找的元素的指针，类型转换为 void*。
// base -- 指向进行查找的数组的第一个对象的指针，类型转换为 void*。
// nitems -- base 所指向的数组中元素的个数。
// size -- 数组中每个元素的大小，以字节为单位。
// compar -- 用来比较两个元素的函数。
int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int *item;
int key = 32; 
   /* 使用 bsearch() 在数组中查找值 32 */
item = (int*) bsearch (&key, values, 5, sizeof (int), cmpfunc);		//示例


char *strcat(char *dest, const char *src)				
// 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾，会覆盖前一个的'\0'
char *strncat(char *dest, const char *src, size_t n)
// dest -- 指向目标数组，该数组包含了一个 C 字符串，且足够容纳追加后的字符串，包括额外的空字符。
// src -- 要追加的字符串。
// n -- 要追加的最大字符数。

char *strcpy(char *dest, const char *src)		 //把 src 所指向的字符串复制到 dest

int strcmp(const char *str1, const char *str2)
int strncmp(const char *str1, const char *str2, size_t n)
// 把 str1 所指向的字符串和 str2 所指向的字符串进行比较
// 如果返回值 < 0，则表示 str1 小于 str2。
// 如果返回值 > 0，则表示 str2 小于 str1。
// 如果返回值 = 0，则表示 str1 等于 str2。

char *strchr(const char *str, int c)
// 在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置
// 该函数返回在字符串 str 中第一次出现字符 c 的位置，如果未找到该字符则返回 NULL。

char *strstr(const char *haystack, const char *needle)
// haystack -- 要被检索的 C 字符串。
// needle -- 在 haystack 字符串内要搜索的小字符串。
// 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。

size_t strlen(const char *str)					
// 计算字符串 str 的长度，直到空结束字符，但不包括空结束字符

int rand(void)
// 返回一个范围在 0 到 RAND_MAX 之间的伪随机数。
// RAND_MAX 是一个常量，它的默认值在不同的实现中会有所不同，但是值至少是 32767
void srand(unsigned int seed)
// 播种由函数 rand 使用的随机数发生器
srand(time(0));							//示例
