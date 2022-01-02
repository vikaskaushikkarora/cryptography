#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	srand(time(0));
	float f;
	int n;
	printf("Enter the length of the key in bits : ");
	scanf("%d",&n);
	FILE* kfp=fopen("encrypt/key.txt","w");
	for(int i=0;i<n;i++){
		f=10*(float)rand()/RAND_MAX;
		if(f<5){
			fprintf(kfp,"0");
		}
		else{
			fprintf(kfp,"1");
		}
	}
	fprintf(kfp,"\n");
	fclose(kfp);
	system("cp encrypt/key.txt decrypt/key.txt");
	return 0;
}
