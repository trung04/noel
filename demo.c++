#include <bits/stdc++.h>
using namespace std;
class KhachHang;
class MatHang;
class HoaDon;
int ckh = 0, cmh = 0, chd = 0;
map<string, KhachHang> kh;
map<string, MatHang> mh;
class KhachHang
{
public:
    string mkh, tkh, gt, ns, dc;
    friend class HoaDon;

public:
    KhachHang()
    {
        mkh = "KH0";
        tkh = gt = ns = dc = "";
    }
    friend istream &operator>>(istream &is, KhachHang &a)
    {
        ++ckh;
        if (ckh < 10)
            a.mkh += "0" + to_string(ckh);
        else
            a.mkh += to_string(ckh);
        scanf("\n");
        getline(is, a.tkh);
        getline(is, a.gt);
        getline(is, a.ns);
        getline(is, a.dc);
        kh[a.mkh] = a;
        return is;
    }
};
class MatHang
{
public:
    string mmh, tmh, dvt;
    long long giamua, giaban;
    friend class HoaDon;

public:
    MatHang()
    {
        mmh = "MH0";
        tmh = dvt = "";
        giamua = giaban = 0;
    }
    friend istream &operator>>(istream &is, MatHang &a)
    {
        ++cmh;
        if (cmh < 10)
            a.mmh += "0" + to_string(cmh);
        else
            a.mmh += to_string(cmh);
        scanf("\n");
        getline(is, a.tmh);
        getline(is, a.dvt);
        is >> a.giamua >> a.giaban;
        is.ignore();
        mh[a.mmh] = a;
        return is;
    }
};
class HoaDon
{
public:
    string mhd, mkh, mmh;
    long long qty;

public:
    HoaDon()
    {
        mhd = "HD0";
        mkh = mmh = "";
        qty = 0;
    }
    friend istream &operator>>(istream &is, HoaDon &a)
    {
        ++chd;
        if (chd < 10)
            a.mhd += "0" + to_string(chd);
        else
            a.mhd += to_string(chd);
        is >> a.mkh >> a.mmh >> a.qty;
        is.ignore();
        return is;
    }
    friend ostream &operator<<(ostream &os, HoaDon a)
    {
        os << a.mhd << " " << kh[a.mkh].tkh << " " << kh[a.mkh].dc << " " << mh[a.mmh].tmh << " " << mh[a.mmh].dvt << " " << mh[a.mmh].giamua << " " << mh[a.mmh].giaban << " " << a.qty << " " << 1ll * mh[a.mmh].giaban * a.qty << endl;
        return os;
    }
};
int main()
{
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N, M, K, i;
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> dskh[i];
    cin >> M;
    for (i = 0; i < M; i++)
        cin >> dsmh[i];
    cin >> K;
    for (i = 0; i < K; i++)
        cin >> dshd[i];

    for (i = 0; i < K; i++)
        cout << dshd[i];
    return 0;
}