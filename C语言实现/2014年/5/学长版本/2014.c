#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 1

#define MAXLENGTH 10000
struct lineNode
{
	int hashValue;
	int length;
	char *contents;
};
int hash(char *s)
{
	int i,z=0;
	for(i=0;s[i];i++)
	{
		z+=s[i];
		if(z>=10007)
			z%=10007;
	}
	return z;
}

int cmp(const void*a,const void *b)
{
	struct lineNode m1=*(struct lineNode*)a,
					m2=*(struct lineNode*)b;

	if(m1.hashValue!=m2.hashValue)
		return m1.hashValue-m2.hashValue;
	else if(m1.length!=m2.length)
		return m2.length-m1.length;
	else
		return strcmp(m2.contents,m1.contents);
}

int main(int argc, char *argv[])
{
	char msg[MAXLENGTH+1];
	int i,N=atoi(argv[1]);
	FILE *fin,*fout;
	#if DEBUG
		FILE *f_debug=fopen("__debug_log","w");
	#endif
	struct lineNode *data;
	data=(struct lineNode*)malloc(N*sizeof(struct lineNode));

	fin=fopen("2014.c","r");
	for(i=0;i<N;i++)
	{
		fgets(msg,MAXLENGTH,fin);
		if(msg[strlen(msg)-1]=='\n')
			msg[strlen(msg)-1]=0;

		data[i].hashValue=hash(msg);
		data[i].length=strlen(msg);

		data[i].contents=(char*)malloc((strlen(msg)+1)*sizeof(char));
		strcpy(data[i].contents,msg);
	}
	fclose(fin);

	qsort(data,N,sizeof(data[0]),cmp);

	fout=fopen("data.out","w");
	for(i=0;i<N;i++){
		#if DEBUG
			fprintf(f_debug, "%d\t%d\n",data[i].hashValue,data[i].length);
		#endif
		fputs(data[i].contents,fout);
		fprintf(fout,"\n");
	}
	fclose(fout);

	#if DEBUG
		fclose(f_debug);
	#endif
	return 0;
}
