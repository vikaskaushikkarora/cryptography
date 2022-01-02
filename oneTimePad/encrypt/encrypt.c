#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
	char ch,ch1;
	char* chstr;
	short int d,d1;
	short int arr[7];
	short int q,r;
	int lenstr;
	FILE* mfp=fopen("../message.txt","r");
	FILE* kfp=fopen("key.txt","r");
	FILE* afp=fopen("ascii.txt","w");
	FILE* cfp=fopen("../cyphertext.txt","w");
	FILE* nkfp=fopen("newKey.txt","w");
	while(1){
		if(fgets(chstr,1000, mfp)==NULL){
			break;
		}
		lenstr=strlen(chstr);
		for(int i=0; i<=lenstr; i++){
			ch=chstr[i];
			d=ch;
			for(int i=0;i<7;i++){
			 	q=d/2;
				r=d%2;
				d=q;
				arr[i]=r;
			}
			for(int i=0;i<7;i++){
				fprintf(afp,"%d",arr[6-i]);
				ch1=fgetc(kfp);
				d1=ch1;
				d1=d1-48;
				fprintf(cfp,"%d",(arr[6-i]+d1)%2);
			}
		}
	}
	while(1){
		ch=fgetc(kfp);
		if(ch == '\n'){
			break;
		}
		fprintf(nkfp,"%c",ch);
	}
	fprintf(afp,"\n");
	fprintf(cfp,"\n");
	fprintf(nkfp,"\n");
	fclose(mfp);
	fclose(afp);
	fclose(cfp);
	fclose(kfp);
	fclose(nkfp);

	system("rm key.txt");
	system("mv newKey.txt key.txt");
}
