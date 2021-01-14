#include<iostream>
#include<math.h>
using namespace std;
class complexe
{
    double re,im;
public:
    ///constructeur :
    complexe(double a= 0, double b=0)
    {
        re=a;
        im=b;
    }
    ///destructeur :
    ~complexe() {}
    ///fonction de recopie :
    complexe(complexe & z)
    {
        re=z.re;
        im=z.im;
    }

    /// fonction de conjugué :
    complexe& conjugue()
    {
        im=-im;
        return *this;
    }

    ///operateurs :


    ///operateur d'addition
    complexe& operator + (complexe &z)
    {
        static complexe res;
        res.re=re+z.re;
        res.im=im=+z.im;
        return res;
    }
    ///operateur de soustraction :
    complexe& operator - (complexe &z)
    {
        static complexe res;
        res.re=re-z.re;
        res.im=im-z.im;
        return res;
    }
    ///operateur de soustraction sans arguments :
    complexe& operator - ()
    {
        static complexe res;
        res.re=-re;
        res.im=-im;
        return res;
    }
    ///operateur de produit
    complexe& operator * (complexe &z)
    {
        static complexe res;
        res.re=re*z.re-im*z.im;
        res.im=im*z.re+z.im*re;
        return res;
    }
    ///operateur de division :
    complexe& operator / (complexe &z)
    {
        static complexe res;
        res = *this * (z.conjugue());
        res.re/=pow(z.re,2) + pow(z.im,2);
        res.im/=pow(z.re,2) + pow(z.im,2);
        return res;
    }

    ///operateur de += :

    complexe& operator += (complexe &z)
    {
        *this=*this+z;
        return *this;
    }

    ///operateur de -= :

    complexe& operator -=(complexe &z)
    {
        *this=*this-z;
        return *this;
    }

    ///operateur de /= :

    complexe& operator /= (complexe &z)
    {
        *this=*this/z;
        return *this;
    }

    ///operateur de *= :

    complexe& operator *= (complexe &z)
    {
        *this=*this*z;
        return *this;
    }

    //operateurs de comparaisons

    ///operateur de l'egalité :

    bool  operator ==(  complexe& z )
    {
        if(re==z.re && im==z.im)
            return true;
        return false;
    }

    ///operateur de difference :

    bool operator !=(  complexe& z )
    {
        return !( *this == z);
    }


/*Il est impossible de comparer deux nombres complexes :
    si z et z1 sont deux
    complexes, l’expression ”z plus grand que z1
    ” n’a pas de sens ;*/


    ///operateur d'affectation :
    complexe& operator =(complexe& z)
    {
        re = z.re;
        im = z.im;
        return *this;
    }
    complexe& operator++()
    {
        re++;
        im++;
        return *this;
    }

    complexe& operator++(int m)
    {
        re++;
        im++;
        return *this;
    }

    complexe& operator--()
    {
        re--;
        im--;
        return *this;
    }

    complexe& operator--(int m)
    {
        re--;
        im--;
        return *this;
    }


    ///fonction d'affichage :
    friend ostream& operator<<(ostream &O, const complexe &z)
    {
        if(z.re==0)
        {
            if(z.im==0)
                O << "   z = 0 " ;
            else if(z.im==1)
                O <<"    z = i" ;
            else if(z.im==-1)
                O <<"    z = -i" ;
            else
                O <<"    z = " << z.im << "i" ;
        }
        else
        {
            if(z.im==0)
                O << "   z = " << z.re ;
            else
            {
                if(z.im==1)
                    O << "   z = " << z.re << " + i " ;
                else if(z.im==-1)
                    O << "   z = " << z.re << " - i " ;
                else if (z.im>0 && z.im!=1)
                    O << "   z = " << z.re << " + " << z.im << "i" ;
                else
                    O << "   z = " << z.re << " " << z.im << "i" ;

            }
        }
        return O;
    }
    friend istream& operator>>(istream &I, complexe &z)
    {
        cout << " re = ";
        I >> z.re;
        cout << " im= ";
        I>> z.im;
        return I;
    }
};

int main()
{
    complexe a, b(1,-2), c(-10),g(2,0),d,e,f;
    cout << "veuillez entrer un complexe :" << endl;
    cin >> a;
    cout << endl;
    cout << "le complexe que vous avez saisi est : ";
    cout << a;
    cout << endl;
    cout << endl;
    cout << "test d'affichage de complexe avec imaginaire negatif " <<endl;
    cout << b;
    cout << endl;
    cout << endl;
    cout << "test d'affichage de complexe avec imaginaire null " << endl;
    cout << c;
    cout << endl;
    cout << endl;
    ///operateur d'addition
    cout << "addition de " << a << " et " << b <<"  est : "<<endl ;
    d=a+b;
    cout << d;
    cout << endl;
    cout << endl;
    ///operateur de multiplication
    cout << "multiplication de " << b << " et " << c << "  est : " <<endl;
    e=b*c;
    cout << e ;
    cout << endl;
    cout << endl;
    ///operateur de division
    cout << "division de " << b << " et " << c << "  est : " << endl;
    f=b/c;
    cout << "\tf : ";
    cout << f;
    cout << endl;
    cout << endl;
    cout << "division de f par 2 (un reel) " << endl;
    ///operateur de /= avec un nombre reel :
    cout << "\tf/2 (en utilisant /=)" <<endl;
    f/=g;
    cout << f;  ///on remarquie que l'operateur de division peut se deviser sur un reel mais , à condition que im=0
    cout << endl;
    cout<< "avant l'affectation :  " << endl;
    cout << g;
    g=b; ///affectation
    cout << endl;
    cout << "\tapres l'affectation :  " <<endl ;
    cout << g;
    cout << endl;
    cout << "incrementation (post) : " <<endl;
    g++;
    cout << g;
    cout << endl;
    cout << "incrementation (pre) \"l'imaginaire dans ce cas devient nul\" : " <<endl;
    ++g;
    cout << g;
    cout << endl;
    cout << "decrementation (post) : " <<endl;
    g--;
    cout << g;
    cout << endl;
    cout << "decrementation (pre) : " <<endl;
    --g;
    cout << g;
    cout << endl;
    cout << "la negation du complexe  " << a << "  est  : " << -a <<endl;
    return 0;
}


