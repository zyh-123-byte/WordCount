#include <stdio.h>
#include <stdlib.h>

void wordcount(char filtxt2[100])
{
	int count2 = 0;
	char ch1,ch2;
	FILE* pw = fopen(filtxt2,"r");//以只读方式打开txt文件
	//如果文本文件打开失败或者文件不存在，程序异常退出
	if(pw == NULL)
	{
		printf("error on open file!");
		exit(1);
	}
	ch1 = getc(pw);
	ch2 = getc(pw);
	while (1)
	{
		if((ch1 != ' ' && ch1 != ',') && (ch2 == ' ' || ch2 == ','))
			count2++;

		if((ch1 != ' ' && ch1 != ',') && ch2 == EOF)
			count2++;
		if(ch2 == EOF)break;
		ch1 = ch2;
		ch2 = getc(pw);
	}
	printf("单词数：%d",count2);
	fclose(pw);
}

void charcount(char filtxt1[100])
{
	int count1 = 0;
	FILE* pc = fopen(filtxt1,"r");//以只读方式打开txt文件

	if(pc == NULL)
	{
		printf("error on open file!");
		exit(1);
	}

	while (getc(pc) != EOF)
		count1++;
	printf("字符数：%d",count1);
	fclose(pc);
}
void Operator(char jud[3],char filtxt[100])
{
	//当输入"-c"时调用charcount函数计数字符
	if(jud[0] == '-' && jud[1] == 'c')
		charcount(filtxt);
	//当输入"-w"时调用wordcount函数计数单词
	else if(jud[0] == '-' && jud[1] == 'w')
		wordcount(filtxt);
	//当输入内容不是"-c"或者"-w"时输出异常
	else{
		printf(" error on input operator or file format!");
		exit(1);
	}
}
int main(){
	char jud[3],filtxt[100];
	scanf("%s",jud);//输入控制参数
	scanf("%s",filtxt);//输入文本文件名
	Operator(jud,filtxt);//由输入的控制参数决定计数字符数或单词数
	return 0;
}