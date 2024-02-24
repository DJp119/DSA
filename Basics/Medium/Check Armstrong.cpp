bool checkArmstrong(int n){
	int size = log10(n)+1;
	int k = n;
	// while(k!=0){
	// 	size++;
	// 	k=k/10;
	// }
	int ans=0;
	k=n;
	while(k!=0){
		ans = ans + pow(k%10,size);
		k=k/10;
	}
	if(ans == n) return true;;
	return false;	
}



bool checkArmstrong(int n){
	int dup=n;
	long long sum=0;
	long long revNum=0;
	while(n>0)
	{
		int ld=n%10;
		sum=sum+(ld*ld*ld);
		long long revNum=(revNum*10)+ld;
		n=n/10;
		
		
	}
	if(dup==sum) { return true;}
	else{ return false;}
}

Time Complexity: O(n) where n is the number of digits since we need to traverse every digit and add digits raised to power no. of digits to sum.

Space Complexity: O(1) since no extra space is required

https://www.codingninjas.com/studio/problems/check-armstrong_589?leftPanelTabValue=DISCUSS
