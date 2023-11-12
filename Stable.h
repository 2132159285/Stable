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
    t** _data;
    int* _log2;
    int     _maxn;
    int     _maxl;
    void MemInit(int maxn)
    {
        _maxn = maxn + 5; _maxl = (int)(log2(_maxn) + 5);
        _data = new  t * [_maxn];
        _log2 = new int[_maxn];
        memset(_log2, 0, sizeof(t) * _maxn);
        for (int i = 2; i < _maxn; i++)
        {
            _log2[i] = _log2[i >> 1] + 1;
        }
        for (int i = 0; i < _maxn; i++)
        {
            _data[i] = new t[_maxl];
            memset(_data[i], 0, (_maxl) * sizeof(t));
        }
    }
    t _max(t a, t b)
    {
        if (a > b) return a;
        return b;
    }
    t _min(t a, t b)
    {
        if (a < b) return a;
        return b;
    }
public:
    void Build(t* data, int maxn)
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
    t Inquire(int l, int r)
    {
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

