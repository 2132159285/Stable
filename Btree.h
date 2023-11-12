#ifndef _Btree_H_
#define _Btree_H_

template<typename t>
struct Btree
{
private:
	t* _data = NULL;
	int  _maxn = 0;
	void MemInit(int maxn)
	{
		_maxn = maxn + 2;
		_data = new t[_maxn];
		for (int i = 0; i < _maxn; i++)
		{
			_data[i] = 0;
		}
	}
	int LowBit(int val)
	{
		return val & (-val);
	}
public:
	void Point(t  data, int address)
	{
		for(int i = address + 1; i < _maxn; i += LowBit(i))
		{
			_data[i] += data;
		}
	}
	void Build(t* data, int maxn)
	{
		MemInit(maxn);
		for (int i = 1; i <= maxn; i++)
		{
			Point(data[i - 1], i-1);
		}
	}
	t Query(int address)
	{
		t re = 0; if (address >= _maxn - 2 || address < 0) throw 0;
		for (int i = address+1; i ; i -= LowBit(i))
		{
			re += _data[i];
		}
		return re;
	}
	t Query(int l, int r)
	{
		return Query(r) - Query(l - 1);
	}
	~Btree()
	{
		delete[] _data;
	}
};

#endif

