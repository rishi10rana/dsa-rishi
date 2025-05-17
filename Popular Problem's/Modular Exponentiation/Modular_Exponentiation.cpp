#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here
	int ans = 1;

	while(n>0){
		if(n&1){ // exponent 'n' is odd then extract an 'x' and multiply it in 'ans' and subtarct odd power by 1
			ans = (1LL * ans * x)%m;
			n = n - 1;
		}
		else{ // if expoenent 'n' is even then reduce the even power by 2 and square the value of x
			n = n >> 1;
			x = (1LL * x%m * x%m)%m;
		}
	}
	// as we wanted final answer to be first mod(m) we are applying mod in above steps.
	return ans;
}