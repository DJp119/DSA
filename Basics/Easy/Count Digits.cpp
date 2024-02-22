int countDigits(int n){
	int count = 0;
	int temp = n;
	while(n>0){
		int k = n%10;
		if(k!=0) {
			if(temp % k==0) {
				count++;
			}
		}
		n=n/10;
	}
	return count;
}

https://www.codingninjas.com/studio/problems/count-digits_8416387?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
