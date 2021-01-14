#include<iostream>
#include<math.h>
using namespace std;
class complex
{
    double re,im;
public:
    ///constructor :
    complex(double a= 0, double b=0)
    {
        re=a;
        im=b;
    }
    ///destructor :
    ~complex() {}
    ///copy constructor:
    complex(complex & z)
    {
        re=z.re;
        im=z.im;
    }

    /// a function that returns the conjugate of a complex:
    complex& conjugate()
    {
        im=-im;
        return *this;
    }

    ///operators :


    ///the ADDITION operator
    complex& operator + (complex &z)
    {
        static complex res;
        res.re=re+z.re;
        res.im=im=+z.im;
        return res;
    }
    ///the SUSTRACTION operator
    complex& operator - (complex &z)
    {
        static complex res;
        res.re=re-z.re;
        res.im=im-z.im;
        return res;
    }
    ///the SUSTRACTION operator without arguments
    /// this function returns the negation of a complex
    complex& operator - ()
    {
        static complex res;
        res.re=-re;
        res.im=-im;
        return res;
    }
    ///the MULTIPLYING operator
    complex& operator * (complex &z)
    {
        static complex res;
        res.re=re*z.re-im*z.im;
        res.im=im*z.re+z.im*re;
        return res;
    }
    ///the DIVISION operator
    complex& operator / (complex &z)
    {
        static complex res;
        res = *this * (z.conjugate());
        res.re/=pow(z.re,2) + pow(z.im,2);
        res.im/=pow(z.re,2) + pow(z.im,2);
        return res;
    }

    ///the += operator:

    complex& operator += (complex &z)
    {
        *this=*this+z;
        return *this;
    }

    ///operateur de -= :

    complex& operator -=(complex &z)
    {
        *this=*this-z;
        return *this;
    }

    ///the /= operator:

    complex& operator /= (complex &z)
    {
        *this=*this/z;
        return *this;
    }

    ///the *= operator:

    complex& operator *= (complex &z)
    {
        *this=*this*z;
        return *this;
    }

    /*****the COMPARAISON operators ********/

    ///the EQUAL operator:

    bool  operator ==(  complex& z )
    {
        if(re==z.re && im==z.im)
            return true;
        return false;
    }

    ///the DIFFERENCE operator:

    bool operator !=(  complex& z )
    {
        return !( *this == z);
    }


/*it is not possible to compare two complexs ...
for exemple the expression Z1>Z2 is not logical :/ */


    ///the ASSIGNEMENT operator:
    complex& operator =(complex& z)
    {
        re = z.re;
        im = z.im;
        return *this;
    }
    complex& operator++()
    {
        re++;
        im++;
        return *this;
    }

    complex& operator++(int m)
    {
        re++;
        im++;
        return *this;
    }

    complex& operator--()
    {
        re--;
        im--;
        return *this;
    }

    complex& operator--(int m)
    {
        re--;
        im--;
        return *this;
    }


    ///the OUTPUT function:
    friend ostream& operator<<(ostream &O, const complex &z)
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
    friend istream& operator>>(istream &I, complex &z)
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
    complex a, b(1,-2), c(-10),g(2,0),d,e,f;
    cout << "can you enter a complex number :" << endl;
    cin >> a;
    cout << endl;
    cout << "The complex that you entered is : ";
    cout << a;
    cout << endl;
    cout << endl;
    cout << "teszting the output of a complex with negative imaginary number" <<endl;
    cout << b;
    cout << endl;
    cout << endl;
    cout << "teszting the output of a complex with null imaginary number " << endl;
    cout << c;
    cout << endl;
    cout << endl;
    ///the addition operator
    cout << "the addition of " << a << " and " << b <<"  is : "<<endl ;
    d=a+b;
    cout << d;
    cout << endl;
    cout << endl;
    ///the multiplying operator
    cout << "the multiply of " << b << " and " << c << "  is : " <<endl;
    e=b*c;
    cout << e ;
    cout << endl;
    cout << endl;
    ///the division operator
    cout << "the division of " << b << " and " << c << "  is : " << endl;
    f=b/c;
    cout << "\tf : ";
    cout << f;
    cout << endl;
    cout << endl;
    cout << "the division of f by 2 (a float) " << endl;
    ///the /= operator with a float :
    cout << "\tf/2 (using /=)" <<endl;
    f/=g;
    cout << f;  ///we can see that a complex can be divided by a float , on condition that im=0
    cout << endl;
    cout<< "before the assignment :  " << endl;
    cout << g;
    g=b; ///affectation
    cout << endl;
    cout << "\tafter the assignment :  " <<endl ;
    cout << g;
    cout << endl;
    cout << "incrementing (post) : " <<endl;
    g++;
    cout << g;
    cout << endl;
    cout << "incrementing (pre) \"the imaginary in this case becomes null\" : " <<endl;
    ++g;
    cout << g;
    cout << endl;
    cout << "decrementing (post) : " <<endl;
    g--;
    cout << g;
    cout << endl;
    cout << "decrementing (pre) : " <<endl;
    --g;
    cout << g;
    cout << endl;
    cout << "the negation of the complex  " << a << "  is  : " << -a <<endl;
    return 0;
}


