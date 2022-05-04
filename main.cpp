#include<iostream>
#include<cmath>

int gcd(int x,int y)
{
    if (x < y)
        std::swap(x , y);
    return x%y==0 ? y : gcd(y , x%y);
}
class fra
{
public:
    
    int num, den;

    fra(int _num, int _den)
    {
        this->num = _num;
        this->den = _den;
        if(this->den < 0)
        {
            this->num= -this->num;
            this->den= -this->den;
        }
    }

    fra(){}

    void simp()
    {
        if(this->num==0)    return;
        int g = gcd( abs(this->num), this->den);
        this->num/=g;
        this->den/=g;
    }
    
    void print()
    {
        std::cout<<this->num;
        this->num==0 ?  std::cout<<std::endl : std::cout<<"/"<<this->den<<std::endl;
    }

    double real()
    {
       return double(num)/den;
    }

    fra operator+ (fra a)
    {
        a.num*=this->den / gcd(this->den, a.den);
        a.den=this->den* a.den / gcd(this->den , a.den);
        a.num+= this->num*(a.den/this->den);
        a.simp();
        return a;
    }

    fra operator- (fra a)
    {
        a.num= -a.num;
        return *(this)+a;
    }

    fra operator*(fra a)
    {
        a.num=this->num*a.num; 
        a.den=this->den*a.den;
        a.simp();
        return a;
    }

    fra operator*(int a)
    {
        fra res=fra(this->num*(a/gcd(a,this->den)) , this->den/gcd(a,this->den));
        res.simp();
        return res;
    }

    fra operator/(fra a)
    {
        std::swap(a.den,a.num);
        return (*this)*a;
    }
};

int combi(int n , int k)
{
    if(n<k)     return 0;
    k = std::min(k , n-k);
    if(0==k)    return 1;
    else
    {
        fra res=fra(1,1);
        while(k)
        {
            (res) = (res) * fra(n-k+1 , k);
            k--;
        }
        return int(res.real());
    }
}

fra bonu[35];

void count()
{
    bonu[0] = fra(1,1);
    for(int i=1;i<=30;i++)
    {
        bonu[i]=fra(0,1);
        for(int j=0;j<i;j++)
        {
            bonu[i]=bonu[i]+(fra(-1 , i+1)*bonu[j]*combi(i+1,j));
        }
    }
}

int main()
{
    count();
    for(int i=0;i<=30;i++)
    {
        bonu[i].print();
    }
    return 0;
}