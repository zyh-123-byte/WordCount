#include <stdio.h>
#include <stdlib.h>

void wordcount(char filtxt2[100])
{
	int count2 = 0;
	char ch1,ch2;
	FILE* pw = fopen(filtxt2,"r");//��ֻ����ʽ��txt�ļ�
	//����ı��ļ���ʧ�ܻ����ļ������ڣ������쳣�˳�
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
	printf("��������%d",count2);
	fclose(pw);
}

void charcount(char filtxt1[100])
{
	int count1 = 0;
	FILE* pc = fopen(filtxt1,"r");//��ֻ����ʽ��txt�ļ�

	if(pc == NULL)
	{
		printf("error on open file!");
		exit(1);
	}

	while (getc(pc) != EOF)
		count1++;
	printf("�ַ�����%d",count1);
	fclose(pc);
}
void Operator(char jud[3],char filtxt[100])
{
	//������"-c"ʱ����charcount���������ַ�
	if(jud[0] == '-' && jud[1] == 'c')
		charcount(filtxt);
	//������"-w"ʱ����wordcount������������
	else if(jud[0] == '-' && jud[1] == 'w')
		wordcount(filtxt);
	//���������ݲ���"-c"����"-w"ʱ����쳣
	else{
		printf(" error on input operator or file format!");
		exit(1);
	}
}
int main(){
	char jud[3],filtxt[100];
	scanf("%s",jud);//������Ʋ���
	scanf("%s",filtxt);//�����ı��ļ���
	Operator(jud,filtxt);//������Ŀ��Ʋ������������ַ����򵥴���
	return 0;
}