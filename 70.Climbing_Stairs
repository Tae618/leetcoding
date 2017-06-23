//some explanations
/*
	n=1, ways[1]=1
	n=2, ways[2]=2
	n=3, ways[3]=ways[1]+ways[2]
	...
	n=t, ways[t]=ways[t-1]+ways[t-2]
	
	when t>2, if we want to climb to the top, there are two ways:
		1. climb 2 steps at t-2 position;
		2. climb 1 step at t-1 position.
	so we have ways[t]=ways[t-1]+ways[t-2]	
	See more about Fibonacci
*/

class Solution {
public:
    int climbStairs(int n) {
        int a[n+1];
        a[0]=0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        a[1]=1;
        a[2]=2;
        for(int i=3;i<=n;i++)
            a[i]=a[i-1]+a[i-2];
        return a[n];
    }
};
