#ifndef LAB_2_CLASS_H
#define LAB_2_CLASS_H


#define pi 3.141592653


#include <iostream>
#include <cmath>
using namespace std;


class Cassini {
    private:
    double  square_root; // (а) квадратный корень из произведения расстояний, от фокусов до любой точки  (а)
    double  half_dist; // (с) half the distance between the foci(половина расстояния между фокусами)  (с)

    public:

    Cassini(){
        this->half_dist = 0;
        this->square_root = 0;
    }

    ~Cassini() = default;

    Cassini(Cassini &line){
        this->half_dist = line.get_half_dist();
        this->square_root = line.get_square_root();
    }



    void  set_parameters(double  a, double  b){
        square_root = a;
        half_dist = b;
    }

    double get_square_root(){
        return this->square_root;
    }

    double get_half_dist(){
        return this->half_dist;
    }



};



int get_int();
bool correct_get_int(int &a);
void T_func_output(Cassini &line);
void T_inflect_point(Cassini &line);
void T_print_R(Cassini &line);
void T_find_dist(Cassini &line);
void type_shape(Cassini &line);
void func_field_fill(Cassini &line);
double find_dist(int w, Cassini &line);
double print_R(int w, Cassini &line);
double inflect_point(Cassini &line);
#endif
