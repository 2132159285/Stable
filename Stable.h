#ifndef __STable_H_
#define __STable_H_ 


enum cmp
{
    MAX = 0,
    MIN = 1
};

template<typename t, bool cmp = 0>
struct Stable
{
private:
    t**     _data = NULL;
    int*    _log2 = NULL;
    int     _maxn = 0;
    int     _maxl = 0;
    int _logi2(int n) 
    {
        int i=0; 
        for (i = 0, n >>= 1; n; ++i) n >>= 1;
        return i - 1;
    }
    t _max(t& a, t& b) const
    {
        if (a > b) return a;
        return b;
    }
    t _min(t& a, t& b) const
    {
        if (a < b) return a;
        return b;
    }
    void MemInit(int maxn)
    {
        _maxn = maxn + 5; _maxl = (_logi2(_maxn) + 5);
        _data = new  t* [_maxn];
        _log2 = new int[_maxn];

        _log2[0] = 0; _log2[1] = 0;
        for (int i = 2; i < _maxn; i++)
        {
            _log2[i] = 0;
            _log2[i] = _log2[i >> 1] + 1;
        }

        for (int i = 0; i < _maxn; i++)
        {
            _data[i] = NULL;
            _data[i] = new t[_maxl];
            for (int j = 0; j < _maxl; j++)
            {
                _data[i][j] = 0;
            }
        }
    }

public:
    void Build(t* data,int maxn)
    {
        MemInit(maxn);
        for (int i = 1; i <= maxn; i++)
        {
            _data[i][0] = data[i];
        }
        for (int l = 1; l < _maxl; l++)
        {
            for (int s = 1; s + (1 << l) - 1 <= maxn; s++)
            {
                if (cmp == 0)  _data[s][l] = _max(_data[s][l - 1], _data[s + (1 << (l - 1))][l - 1]);
                if (cmp == 1)  _data[s][l] = _min(_data[s][l - 1], _data[s + (1 << (l - 1))][l - 1]);
            }
        }
    }
    t Inquire(int l,int r)
    {
        if (l > r || l<0 || r>_maxn) throw 0;
        int ll = _log2[r - l + 1];
        if (cmp == 0) return _max(_data[l][ll], _data[r - (1 << ll) + 1][ll]);
        if (cmp == 1) return _min(_data[l][ll], _data[r - (1 << ll) + 1][ll]);
    }
    ~Stable()
    {
        for (int i = 0; i < _maxn; i++)
        {
            delete[]  _data[i];
        }
        delete[] _data;
        delete[] _log2;
    }
};

#endif
