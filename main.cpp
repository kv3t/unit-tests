#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;

class complex
{
private:
    double re;
    double im;

public:

    complex(double _re = 0, double _im = 0)
    {
        re = _re;
        im = _im;
    }

    void Print(){
        cout <<"re = " << re << " im = " << im << endl;
    }

    void SetRe (double revalue){
        re = revalue;
    }

    double GetRe (){
        return re;
    }

    void SetIm (double imvalue){
        im = imvalue;
    }

    double GetIm (){
        return im;
    }

    bool operator ==(const complex & other){
        return this->re == other.re && this->im == other.im;
    }

    bool operator !=(const complex & other){
        return !(this->re == other.re && this->im == other.im);
    }

    complex operator +(const complex & other) const{
        complex temp;
        temp.re = this->re + other.re;
        temp.im = this->im + other.im;
        return temp;
    }

    friend complex operator +(double d, const complex & other) {
        complex temp(d + other.re, other.im);
        return temp;
    }

    friend complex operator +(const complex & other, double d) {
        complex temp(d + other.re, other.im);
        return temp;
    }

 /*   friend complex operator + () {
        complex temp;
        temp.re = this->re;
        temp.im = this->im;
        return temp;
    } */

    complex operator -(const complex & other)  const{
        complex temp;
        temp.re = this->re - other.re;
        temp.im = this->im - other.im;
        return temp;
    }

    friend complex operator -(double d, const complex & other) {
        complex temp(d - other.re, - other.im);
        return temp;
    }

    friend complex operator -(const complex & other, double d) {
        complex temp(other.re - d, other.im);
        return temp;
    }

  /*  friend complex operator - () {
        complex temp;
        temp.re = (-1)*this->re;
        temp.im = (-1)*this->im;
        return temp;
    } */

    complex operator +=(const complex & other) {

        this->re = this->re + other.re;
        this->im = this->im + other.im;

    }

    complex operator -=(const complex & other) {

        this->re = this->re - other.re;
        this->im = this->im - other.im;

    }

     complex operator *=(const complex & other) {

        this->re = this->re * other.re - this->im * other.im;
        this->im = this->re * other.im + this->im * other.re;

    }

    complex operator /=(const complex & other) {

        this->re = (this->re * other.re + this->im * other.im) / (other.complexmod() * other.complexmod());
        this->im = (this->im * other.re - this->re * other.im) / (other.complexmod() * other.complexmod());

    }

    complex operator *(const complex & other) const {
        complex temp;
        temp.re = this->re * other.re - this->im * other.im;
        temp.im = this->re * other.im + this->im * other.re;
        return temp;
    }

    friend complex operator *(double d, const complex & other) {
        complex temp;
        temp.re = other.re * d;
        temp.im = other.im * d;
        return temp;
    }

    complex operator /(const complex & other)  {
        complex temp;
        temp.re = (this->re * other.re + this->im * other.im) / (other.complexmod() * other.complexmod());
        temp.im = (this->im * other.re - this->re * other.im) / (other.complexmod() * other.complexmod());
        return temp;
    }

    complex & operator =(const complex & other){
        this->re = other.re;
        this->im = other.im;
        return *this;
    }

    complex sopr(){
        this->re = this->re;
        this->im = (-1) * this->im;
        return *this;
    }

    double complexmod() const {
        return sqrt( (this->re)*(this->re) + (this->im)*(this->im) );
    }

};

void assert_test_assignment(){
    complex a(2, 4);
    a += complex(2.5, -1);
    assert( a  == complex(4.5, 3));
    a -= complex(4, 2);
    assert( a  == complex(0.5, 1));
    complex b (3, 4);
    b *= complex (1, 0);
    assert( b  == complex(3, 4));
    complex c (4, -6);
    c /= complex(-2, 0);
    assert( c  == complex(-2, 3));
    complex d(1, 6);
    d = complex (1.3, -2);
    assert( d  == complex(1.3, -2));

    cout << "Assignment tests succeed\n";

}

void assert_test_binary_operator()
{
    assert((complex(2, 3) + complex(5, -4)) == complex(7, -1));
    assert((1.6 + complex(8, -3)) == complex(9.6, -3));

    assert((complex(1, 4) - complex(5, 2)) == complex(-4, 2));
    assert((3.4 - complex(2.4, -3)) == complex(1, 3));

    assert((3 * complex(2.5, -1)) == complex(7.5, -3));
    assert(( (complex(4, -6)) / complex(-2, 0) ) == complex(-2, 3));

    assert ( (complex(1, 0) == complex(1, 0)) == true);
    assert ( (complex(1, 0) != complex(2, 0)) == true);

    cout << "Binary operator tests succeed\n";
}

void assert_test_others(){

    complex a(3, -4);

    assert ( a.GetRe() == 3 );
    assert ( a.GetIm() == -4 );
    assert ( a.complexmod() == 5 );
    assert ( a.sopr() == complex(3, 4));

    cout << "Other tests succeed\n";

}

int main()
{

    assert_test_assignment();
    assert_test_binary_operator();
    assert_test_others();

    return 0;
}
