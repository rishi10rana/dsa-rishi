### Approach To Solve - Using Binary Search

1. agar hume sqrt of n = 37 nikalna hai to uska answer 0 -------> 37 ki bich mei hi aayega.
	- Iss Range ko hum search space kehta hai aur ye ek imaginary array ke jaise hoga jo monotonicor sorted hoga
	- is par hum binary search laga sakte 0,1,2,3,4.....35,36,37
	
2. to humara start = 0 and end = n is par hume bus binary search lagana hai
	mid = start + (end-start)/2 aisa hi niklega

3. Conditons -
	- if (mid x mid=n) matlab ye perfect square hai return kardena mid anser mil gaya.
	- else if (mid x mid > n) matlab mid se aage answer hume nahi mil sakta to 
		end = mid - 1 kardo
	- else if (mid x mid < n) matlab ye jo mid hai wo answer ho sakta par agar se accha bhi possoble ho sakta par isse aage hi present hoga
		too ye mid ko store kara lo "ans" mei aur start = mid + 1 kardo.
	- Ye loop tab tak chalana jab tak while(start<=end)
	- loop jab khatam hoga pura aur khuch return nahi karga to tum last mei wo close wala 
		"ans" return kardena

4. iss question mei sab (mid x mid) karega to shayad int variable ye genrated value sstore naa kar paye isliya hum 
   data type  "long long int" use karenga