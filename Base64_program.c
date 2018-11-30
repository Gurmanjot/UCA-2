#include<stdio.h>
#include<string.h>
int main()
{
	const char base[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	printf("ENter the string:\n");
	char arr[100];
	scanf("%s",&arr);
	int len=strlen(arr);
	int out_len=(len/3)*4+2;
	char final[out_len];
	int i,value=0;
	for(i=0;i<len-2;i+=3)
	{
		final[value++]=base[((arr[i]>>2)&0x3F)];
		final[value++]=base[((arr[i]<<6)&0x3)|((arr[i+1]>>4)&0xF )];
		final[value++]=base[((arr[i+1]<<4)&0xF)|((arr[i+2]>>6)&0xF)];
		final[value++]=base[(arr[i+2]<<2)&0x3F];
	}
	if(i==(len-1))
	{
		final[value++]=base[((arr[i]>>2)&0x3F)];
		final[value++]=base[(arr[i]<<6)&0x3];
		final[value++]='=';
	    final[value++]='=';
	}
	else if(i==(len-2))
	{
	final[value++]=base[(arr[i]>>2)&0x3F];
   	  final[value++]=base[((arr[i]<<6)&0x3) | ((arr[i+1]>>4)&0xF)];
   	  final[value++]=base[(arr[i+1]<<4)&0xF];
   	  final[value++]='=';
	}
	final[value]='\0';
	printf("%s",final);
	return 0;
}
