export module f_pow;

export unsigned long long  fast_pow(int a,int b)
{
	unsigned long long tmp=a,ans=1;
	while(b)
	{
		if(b&1) ans*=tmp;
		tmp*=tmp;
		b>>=1;
	}
	return ans;
}

export unsigned long long  fast_pow(int a,int b,int mod)
{
	unsigned long long tmp=a,ans=1;
	while(b)
	{
		if(b&1) ans=((ans%mod)*(tmp%mod))%mod;
		tmp=((tmp%mod)*(tmp%mod))%mod;
		b>>=1;
	}
	return ans;
}
