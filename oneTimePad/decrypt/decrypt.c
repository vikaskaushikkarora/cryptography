#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	char ch,ch1,chascii;
	short int d,d1,dnet,i,val=0,arr[7],asciival;
	FILE* cfp=fopen("../cyphertext.txt","r");
	FILE* kfp=fopen("key.txt","r");
	FILE* dmfp=fopen("../decodedMessage.txt","w");
	FILE* rafp=fopen("recoveredAscii.txt","w");
	FILE* nkfp=fopen("newKey.txt","w");
	while(val == 0){
		for(i=0;i<7;i++){
			ch=fgetc(cfp);
			if(ch == '\n'){
				val=1;
				break;
			}
			d=ch;
			d=d-48;
			ch1=fgetc(kfp);
			d1=ch1;
			d1=d1-48;
			dnet=(d+d1)%2;
			arr[i]=dnet;
			fprintf(rafp,"%d",dnet);
		}
		asciival=0;
		for(i=0;i<7;i++){
			asciival=asciival+arr[i]*powf(2,6-i);
		}
		chascii=asciival;
		fprintf(dmfp,"%c",chascii);
	}
	while(1){
		ch=fgetc(kfp);
		if(ch == '\n'){
			break;
		}
		fprintf(nkfp,"%c",ch);
	}
	fprintf(rafp,"\n");
	fprintf(nkfp,"\n");
	fclose(cfp);
	fclose(kfp);
	fclose(rafp);
	fclose(dmfp);
	fclose(nkfp);

	system("rm key.txt");
	system("mv newKey.txt key.txt");
}
