#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	FILE* fp=fopen("encrypted.txt","r");
	FILE* myfile=fopen("decrypted.txt","w");
	char dataLine[5];
	short int a;
	char ch;
	while( fgets ( dataLine,5,fp) != NULL ){
		a = strtof(dataLine,NULL);
		if(a<47){
			a=a+47;
		}
		else{
			a=a-47;
		}
		a=a+32;
		ch=a;
		fputc(ch,myfile);
	}
	fclose(fp) ;
	fclose(myfile);		
}
