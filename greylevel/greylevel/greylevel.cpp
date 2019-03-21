#include <stdio.h>
int main()
{
	int i,j,k;
	FILE *fp1=NULL,*fp2=NULL;
	unsigned char pData[256*256];
	int count[256];
	float frequence[256];
	fp1=fopen("F:\\Lena.raw","rb");//ÎÄ¼ş´æÔÚFÅÌ
	fread(pData,sizeof(unsigned char),256*256,fp1);
	fclose(fp1);
	{
		for (k=0;k<256;k++)
		{
			count[k]=0;
		}
		for (i=0;i<256;i++)
		{
			for (j=0;j<256;j++)
			{
				count[pData[i*256+j]]++;
			}
		}
		for (k=0;k<256;k++)
		{
			frequence[k]=((float)count[k])/(256*256);
		}
	}
	fp2=fopen("result.txt","w");
	for (i=0;i<256;i++)
	{
		fprintf(fp2,"%d,%d,%f\n",i,count[i],frequence[i]);
	}
	
	fclose(fp2);
	return 0;
}