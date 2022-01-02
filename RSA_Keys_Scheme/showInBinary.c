void showInBinary(long long int a){
	long long int q; //decimal number
	int r,i=0;
	int count=0;
	int arr[90];
	while(q!=0){
		q=a/2;
		r=a%2;
		arr[i]=r;
		count+=1;
		i+=1;
		a=q;
	}

	printf("%d bits of binary ! And the key is :\n",count);
	for(int i=count-1;i>=0;i--){
		printf("%d",arr[i]);
	}
	printf("\n");
}
