#ifndef __PRI_H_
#define __PRI_H_ 

struct Pri
{
	vector<unsigned long long>pri;
	Pri(unsigned long long maxn)
	{
		bool* vis=new bool[maxn+10];
		memset(vis,0,sizeof(bool)*(maxn+10));
		for(unsigned long long i=2;i<=maxn;i++)
		{
			if(!vis[i]) pri.push_back(i);
			for(auto& t:pri)
			{
				if(t*i>maxn) break;
				vis[t*i]=1;
				if(i%t==0) break;
			}
		}
		delete [] vis;
		return;
	}
};

#endif
