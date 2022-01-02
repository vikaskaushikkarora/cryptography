#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	char ch;
	short int d;
	FILE* fp=fopen("message.txt","r");
	FILE* myfile=fopen("modifiedASCII.txt","w");
	while(1){
		ch=fgetc(fp);
		if(ch == '\n'){
			break;
		}
		d=ch;
		d=d-32;
		fprintf(myfile,"%d\n",d);
	}
	fclose(fp);
	fclose(myfile);
}
