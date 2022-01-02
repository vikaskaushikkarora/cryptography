//Generating Prime Numbers List

#include<stdio.h>
#include<math.h>
#include "checkPrimeNumber.c"
#include "showInBinary.c"

int main(){

	int flag,count;
	long long n1,n2;
	printf("Enter any number : ");
	scanf("%lld",&n1);
	printf("Enter another number : ");
	scanf("%lld",&n2);
	
	count=0;
	while(count==0){
		flag=checkPrimeNumber(n1);
		if (flag == 1 ){
			count +=1;
		}
		else {
			n1+=1;
		}
	}

	count=0;
	while(count==0){
		flag=checkPrimeNumber(n2);
		if (flag == 1 ){
			count +=1;
		}
		else {
			n2+=1;
		}
	}

	printf("The two prime numbers nearest to the two numbers you have provided , are : ");
	printf("%lld and %lld\n",n1,n2);
	printf("This forms your private key !\n");

	FILE *myfile;
	myfile=fopen("privateKeys.txt","w");
	fprintf(myfile,"%lld\t",n1);
	fprintf(myfile,"%lld\n",n2);
	fclose(myfile);
	
	printf("Your public key is the product of these two prime numbers !\nAll of the information has been saved successfully !\n");

	FILE *myfile1;
	myfile1=fopen("publicKey.txt","w");
	fprintf(myfile1,"%lld",n1*n2);
	fclose(myfile1);

	printf("The public key in decimal is : ");
	showInBinary(n1*n2);

	return 0;
}
