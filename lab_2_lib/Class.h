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
    double offset_x;
    double offset_y;

    public:

    Cassini(){
        this->half_dist = 0;
        this->square_root = 0;
        this->offset_x = 0;
        this->offset_y = 0;
    }

    ~Cassini() = default;

    Cassini(Cassini &line){
        this->half_dist = line.get_half_dist();
        this->square_root = line.get_square_root();
        this->offset_x = line.get_offset_x();
        this->offset_y = line.get_offset_y()
;    }

    double get_offset_x(){
        return this->offset_x;
    }

    double get_offset_y(){
        return this->offset_y;
    }

    void  set_both_parameters(double  a, double  b){
        square_root = a;
        half_dist = b;
    }

    void set_half_dist(double a){
        half_dist = a;
    }

    void set_square_root(double a){
        square_root = a;
    }

    void set_offsets(double x, double y){
        offset_x = x;
        offset_y = y;
    }

    double get_square_root(){
        return this->square_root;
    }

    double get_half_dist(){
        return this->half_dist;
    }


    void T_func_output();
    void func_field_fill();
    void T_find_dist();
    void type_shape();
    void T_print_R();
    void T_inflect_point();

};



int get_int();
bool correct_get_int(int &a);
double find_dist(int w, Cassini &line);
double print_R(int w, Cassini &line);
double inflect_point(Cassini &line);
#endif
