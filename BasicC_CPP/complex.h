
#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex 
{
  public:
    complex (double r = 0, double i = 0)
      : re(r), im(i)  // declare
    {}                // assign

    complex& operator += (const complex&);
    complex& operator -= (const complex&);
    complex& operator *= (const complex&);
    complex& operator /= (const complex&);

    double real () const { return re; }
    double imag () const { return im; }

  private:
    double re, im;
    
    friend complex& __doapl(complex *, const complex&);
    friend complex& __doami(complex *, const complex&);
    friend complex& __doaml(complex *, const complex&);
};

inline complex& __doapl(complex* ths, const complex& r){
  
  return;
}
inline complex& __doaml(complex* ths, const complex& r){
  
  return;
}
inline complex& __doami(complex* ths, const complex& r){
  
  return;
}
inline complex& operator *= (complex* ths, const complex& r){
  return;
}
#endif