//
// Created by kiril on 11.12.2022.
//
#include <iostream>
template <typename T>
class Imaginary{
public:
    T* _val; // _val[0] - real part, _val[1] - Imaginary part
    Imaginary():_val(new T[2]){}
    Imaginary(T re, T im): Imaginary(){
        _val[0] = re;
        _val[1] = im;
    }
    /// copy constructor
    Imaginary(Imaginary<T>& g): Imaginary(){
        _val[0] = g.Re();
        _val[1] = g.Im();
    }
    /// move constructor
    Imaginary(Imaginary<T>&& g): Imaginary(){
        // TODO how to make it?
    }
    /// imaginary unit
    Imaginary(char a):Imaginary(){
        _val[0] = 0;
        _val[1] = 1;
    }
    /// conversion from reals
    Imaginary(T a): Imaginary(){
        _val[0] = a;
        _val[1] = 0;
    }
    /// copy assignment operator
    Imaginary<T>& operator =(Imaginary<T>& g){
        T* tmp__val = new T[2];
        tmp__val[0] = g.Re();
        tmp__val[1] = g.Im();
        delete [] _val;
        _val= tmp__val;
        return *this;
    }
    /// copy assignment operator from reals
    Imaginary<T>& operator =(T& g){
        T* tmp_val = new T[2];
        tmp_val[0] = g;
        tmp_val[1] = 0;
        delete [] _val;
        _val= tmp_val;
        return *this;
    }
    /// move assignment operator
    Imaginary<T>& operator =(Imaginary<T>&& g){
        /*Imaginary<T> tmp(std::move(g)); // TODO how to make it?
        std::swap(this->_val, tmp.data);*/
        return *this;
    }
    /// move assignment operator from reals
    Imaginary<T>& operator =(T&& g){
        // TODO how to make it?
    }
    ~Imaginary(){
        delete[] _val;
    }
    /// each operator also for reals
    ///plus
    Imaginary<T>& operator +(Imaginary<T> & g){}
    Imaginary<T>& operator +(T & g){}
    ///minus
    Imaginary<T>& operator -(Imaginary<T> & g){}
    Imaginary<T>& operator -(T & g){}
    ///multiply
    Imaginary<T>& operator *(Imaginary<T> & g){}
    Imaginary<T>& operator *(T & g){}
    ///plus equals
    void operator +=(Imaginary<T> & g){}
    void operator +=(T & g){}
    ///minus equals
    void operator -=(Imaginary<T> & g){}
    void operator -=(T & g){}
    /// times equals
    void operator *=(Imaginary<T> & g){}
    void operator *=(T & g){}
    /// minus itself
    Imaginary<T>& operator -(){}
    /// get real part
    T Re(){
        return _val[0];
    }
    /// get imaginary part
    T Im(){
        return _val[1];
    }
    /// module squared |a|^2
    T ModuleSq(){
        return _val[0]*_val[0]+_val[1]*_val[1];
    }
    /// conjurate of a: a - b*i
    Imaginary<T>& Conj(){
        return Imaginary<T>(_val[0], -_val[1]);
    }
};
template <typename T>
class Quaternion{
public:
    T* _val;/* _val[0] - real part,
                 _val[1] - Imaginary part
                 _val[2] - j-part
                 _val[3] - k-part*/
    Quaternion():_val(new T[4]){}
    Quaternion(T re, T i, T j, T k): Quaternion(){
        _val[0] = re;
        _val[1] = i;
        _val[2] = j;
        _val[3] = k;
    }
    /// basic quaternion units: "i", "j", "k"
    Quaternion(char a): Quaternion(){
        // you give a char i, j or k and it creates a unit
    }
    /// conversion from reals
    Quaternion(T a): Quaternion(){}
    /// conversion from imaginary
    Quaternion(Imaginary<T> a): Quaternion(){}
    /// copy assignment operator
    Quaternion<T>& operator =(Quaternion<T>& g){

    }
    /// copy assignment operator from reals
    Quaternion<T>& operator =(T& g){

    }
    /// copy assignment operator from imaginary
    Quaternion<T>& operator =(Imaginary<T>& g){

    }
    /// move assignment operator
    Quaternion<T>& operator =(Quaternion<T>&& g){

    }
    /// move assignment operator from reals
    Quaternion<T>& operator =(T&& g){

    }
    /// move assignment operator from imaginary
    Quaternion<T>& operator =(Imaginary<T>&& g){

    }
    ~Quaternion(){
        delete[] _val;
    }
    /// each operator also for reals and imaginary
    ///plus
    Quaternion<T>& operator +(Quaternion<T> & g){}
    Quaternion<T>& operator +(Imaginary<T> & g){}
    Quaternion<T>& operator +(T & g){}

    ///minus
    Quaternion<T>& operator -(Quaternion<T> & g){}
    Quaternion<T>& operator -(Imaginary<T> & g){}
    Quaternion<T>& operator -(T & g){}

    /// multiply
    Quaternion<T>& operator *(Quaternion<T> & g){}
    Quaternion<T>& operator *(Imaginary<T> & g){}
    Quaternion<T>& operator *(T & g){}
    /// plus equals
    void operator +=(Quaternion<T> & g){}
    void operator +=(Imaginary<T> & g){}
    void operator +=(T & g){}
    ///minus equals
    void operator -=(Quaternion<T> & g){}
    void operator -=(Imaginary<T> & g){}
    void operator -=(T & g){}
    /// times equals
    void operator *=(Quaternion<T> & g){}
    void operator *=(Imaginary<T> & g){}
    void operator *=(T & g){}
    /// minus itself
    Quaternion<T> & operator -(){}
    /// get real part
    T Re(){
        return _val[0];
    }
    /// get Imaginary part
    T Im(){
        return _val[1];
    }
    /// get j-part
    T j(){
        return _val[2];
    }
    /// get k-part part
    T k(){
        return _val[3];
    }
    /// module squared |a|^2
    T ModuleSq(){
        return _val[0]*_val[0]+_val[1]*_val[1]+_val[2]*_val[2]+_val[3]*_val[3];
    }
    /// conjurate of a: a - b*i - c*j-d*k
    Quaternion<T>& Conj(){
        return Quaternion<T>(_val[0], -_val[1], -_val[2], -_val[3]);
    }
};
int main(){
 Imaginary<int> a('i');
 Imaginary<int> b(5, 3);
 b = 5;
}
