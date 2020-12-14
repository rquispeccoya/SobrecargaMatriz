#include <iostream>
#include <vector>
#include <ostream>
#include <numeric>

class Vector {

private:
    std::vector<int> Datos{0};

public:
    Vector()=delete ;
    Vector(const std::size_t& size):Datos{std::vector<int>(size,{0})}{}

    int operator[](unsigned index) const{
        return Datos[index];
    }

    int& operator[](unsigned index) {
        return Datos[index];
    }

    int& at(unsigned index){
        return  Datos[index];
    }

    //Operaciones aritmeticas

    //vector + vector
    friend Vector operator+(const Vector &a,const Vector &b) {
        Vector aux{a.Datos.size()};
        if(a.Datos.size()==b.Datos.size()){
            for(unsigned i=0;i<aux.Datos.size();++i)
                aux[i]=a[i]+b[i];
            return aux;
        }else{
            return aux;
        }
    }

    //vector - vector
    friend Vector operator-(const Vector &a,const Vector &b) {
        Vector aux{a.Datos.size()};
        if(a.Datos.size()==b.Datos.size()){
            for(unsigned i=0;i<aux.Datos.size();++i)
                aux[i]=a[i]-b[i];
            return aux;
        }else{
            return aux;
        }
    }

    //escalar + vector
    friend Vector operator+(int nro,const Vector &b) {
        Vector aux{b.Datos.size()};
        for(unsigned i=0;i<aux.Datos.size();++i)
            aux[i]=nro+b[i];
        return aux;
    }

    //vector + escalar
    friend Vector operator+(const Vector &b,int nro) {
        return nro+b;
    }

    //escalar - vector
    friend Vector operator-(int nro,const Vector &b) {
        Vector aux{b.Datos.size()};
        for(unsigned i=0;i<aux.Datos.size();++i)
            aux[i]=nro-b[i];
        return aux;
    }

    //vector - escalar
    friend Vector operator-(const Vector &b,int nro) {
        return -nro+b;
    }

    //Condicionales

    //vector == vector
    friend bool operator==(const Vector &a,const Vector &b) {
        if(a.Datos.size()==b.Datos.size()){
            for(unsigned i=0;i<a.Datos.size();++i){
                if(a[i]!=b[i])
                    return false;
            }
            return true;
        }
        else
            return false;
    }

    //vector != vector
    friend bool operator!=(const Vector &a,const Vector &b) {
        return !(a==b);
    }

    //imprimir vector
    friend std::ostream& operator<<(std::ostream& output, const Vector& a){
        output <<"[";
        for(unsigned i=0;i<a.Datos.size()-1;++i)
            output<<a[i]<<", ";
        output<<*a.Datos.rbegin()<<"]";
        return output;
    }

    //vector < vector
    friend bool operator <(const Vector &a,const Vector &b){
        return std::accumulate(a.Datos.begin(),a.Datos.end(),0)<
                std::accumulate(b.Datos.begin(),b.Datos.end(),0) ;
    }

    //vector > vector
    friend bool operator >(const Vector &a,const Vector &b){
        return b<a;
    }

    //vector <= vector
    friend bool operator <=(const Vector &a,const Vector &b){
        return (a==b||a<b);
    }

    //vector >= vector
    friend bool operator >=(const Vector &a,const Vector &b){
        return (a==b||a>b);
    }
};


class Matrix{

private:
    std:: vector<Vector>matrix{0};
    unsigned fila;
    unsigned columna;

public:

    Matrix()=delete;
    Matrix (const unsigned &fil,const unsigned &col):matrix{std::vector<Vector>(fil,{0})}{
        this->fila=fil;
        this->columna=col;
        Vector a{columna};
        for(unsigned i =0;i<fila;++i){
            matrix[i]=a;
        }
    }

    Vector& operator [](const int index){
        return  matrix[index];
    }

    Vector operator [](const int index)const{
        return  matrix[index];
    }

    //operaciones aritmeticas

    //matriz + matriz
    friend Matrix operator+(const Matrix &a,const Matrix &b) {
        Matrix aux{a.fila,a.columna};
        if(a.fila==b.fila&&a.columna==b.columna){
            for(unsigned i=0;i<aux.fila;++i)
                aux[i]=a[i]+b[i];
            return aux;
        }else{
            return aux;
        }
    }

    //matriz - matriz
    friend Matrix operator-(const Matrix &a,const Matrix &b) {
        Matrix aux{a.fila,a.columna};
        if(a.fila==b.fila&&a.columna==b.columna){
            for(unsigned i=0;i<aux.fila;++i)
                aux[i]=a[i]-b[i];
            return aux;
        }else{
            return aux;
        }
    }

    //escalar + matriz
    friend Matrix operator+(int nro,const Matrix &a) {
        Matrix aux{a.fila,a.columna};
        for(unsigned i=0;i<a.fila;++i)
            aux[i]=nro+a[i];
        return aux;
    }

    //matriz + escalar
    friend Matrix operator+(const Matrix &a,int nro) {
        return nro+a;
    }

    //escalar - matriz
    friend Matrix operator-(int nro,const Matrix &a) {
        Matrix aux{a.fila,a.columna};
        for(unsigned i=0;i<a.fila;++i)
            aux[i]=nro-a[i];
        return aux;
    }

    //matriz - escalar
    friend Matrix operator-(const Matrix &a,int nro) {
        return -nro+a;
    }

    //Condicionales

    //matriz == matriz
    friend bool operator==(const Matrix &a,const Matrix &b) {
        if(a.columna==b.columna&&a.fila==b.fila){
            for(unsigned i=0;i<a.fila;++i)
                if(a[i]!=b[i])
                    return false;
            return true;
        }else
            return false;
    }

    //matriz != matriz
    friend bool operator!=(const Matrix &a,const Matrix &b) {
        return !(a==b);
    }

    //vector < vector
    friend bool operator <(const Matrix &a,const Matrix &b){
        unsigned cantTotal1=0;
        unsigned cantTotal2=0;
        for(unsigned i=0;i<a.fila;++i){
            for(unsigned j=0;j<a.columna;++j){
                cantTotal1+=a[i][j];
                cantTotal2+=b[i][j];
            }
        }
        if(cantTotal1<cantTotal2)
            return true;
        else
            return false;
    }

    //matriz > matriz
    friend bool operator >(const Matrix &a,const Matrix &b){
        return b<a;
    }

    //matriz <= matriz
    friend bool operator <=(const Matrix &a,const Matrix &b){
        return (a<b||a==b);
    }

    //matriz >= matriz
    friend bool operator >=(const Matrix &a,const Matrix &b){
        return (a>b||a==b);
    }

    //imprimir matriz
    friend std::ostream & operator <<(std::ostream &output,const Matrix &m){
        for(unsigned i=0;i<m.fila;++i){
            for(unsigned j=0;j<m.columna-1;++j)
                output <<m[i][j]<<"  " ;
            output <<m[i][m.columna-1] ;
            if(i==m.fila-1){
            }else{
                output <<std::endl ;
            }
        }
        return output;
    }
};

int main()
{
    //vector
//    Vector a{3},b{3};
//    a[2]=-10;
//    b[2]=10;
//    auto m=-2+a+b+50;
//    auto n=a+b;
//    std::cout<<n<<std::endl;
//    std::cout<<(a==b)<<std::endl;
//    std::cout<<(a!=b)<<std::endl;
//    std::cout<<(a<=b)<<std::endl;
//    std::cout<<(a<b)<<std::endl;
//    std::cout<<(a>=b)<<std::endl;
//    std::cout<<(a>b)<<std::endl;
//    std::cout<<m<<std::endl;
//    std::cout<<std::endl;

    //matrix
//    Matrix c{2,2}, d{2,2},k{2,2};
//    c[1][0] = 2;
//    d[1][0] = 2;
//    k[1][1]=-4;

//    std::cout<<c<<std::endl;
//    std::cout<<(c<=d)<<std::endl;
//    std::cout<<(c>=d)<<std::endl;
//    std::cout<<(c==d)<<std::endl;
//    std::cout<<(c!=d)<<std::endl;
//    std::cout<<(c>d)<<std::endl;
//    auto f =-2-k;
//    std::cout<<f<<std::endl;
//    Matrix p{2,3}, q{2,3}; //(rows x cols)
//    p[1][1] = 1;
//    q[1][2] = 7;
//    auto r = p+q;
//    std::cout<<r<<std::endl;
//    std::cout<<(p==q);
//    auto d = r+2;
//    std::cout<<d<<std::endl;

    Matrix a{2,3}, b{2,3}, c{2,3};
    auto d = (a+3)  + ( b-1) - (c+3);
    Vector f{3}, g{3}, h{3};
    auto i = (f+3)  + (g-1) - (h+3);
    std::cout<<d<<std::endl;
    std::cout<<i<<std::endl;

}
