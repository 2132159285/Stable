#ifndef __SHASH_H_
#define __SHASH_H_ 

template<short pri=127,unsigned long long Mod=133333333331>
struct SHash
{
private:
	unsigned long long* _data;
	int _maxn = 0;
	void MemInit(int maxn)
	{
		_maxn = maxn + 2;
		_data = new unsigned long long[maxn];
		for (int i = 0; i < maxn; i++)
		{
			_data[i] = 0;
		}
	}
public:
	void Build(char* data[], int maxn)
	{
		MemInit(maxn);
		for (int i = 1; i < maxn; i++)
		{
			_data[i] = (((_data[i - 1] * pri) % Mod) + ((int)(data[i])%Mod))%Mod;
		}
	}
	void Build(std::string data)
	{
		MemInit(data.size());
		for (int i = 1; i <= data.size(); i++)
		{
			_data[i] = (((_data[i - 1] * pri) % Mod) + (data[i - 1] % Mod)) % Mod;
		}
	}
	unsigned long long GetHash(int r)
	{
		return _data[r];
	}
	unsigned GetHash(int l, int r)
	{
		return _data[r] - _data[l - 1];
	}
};

#endif
