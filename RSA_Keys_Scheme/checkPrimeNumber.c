int checkPrimeNumber(long long n){
  long long m = sqrt(n);
  long long j;
  int flag=1;
  if (n<=1){
    flag=0;
  } else {
    for(j=2;j<=m;j++){
      if (n%j == 0){
        flag = 0 ;
        break;
      }
    }
  }
  return flag;
}
