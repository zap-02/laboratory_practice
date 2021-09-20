#include "Class.h"
#include <iostream>
#include <cstring>
#include <cmath>

#define pi 3.141592653
#define inf 9999999999


using namespace std;

bool correct_get_int(int &a) {
    cin >> a;
    if (!cin.good()) {
        cin.clear();
        cin.ignore();
        return false;
    }
    return true;
}

int get_int() {
    int num;
    while (true) {
        if (correct_get_int(num))
            break;
        cout << "Wrong number" << endl;
    }
    return num;
}

void Cassini::func_field_fill() {
    cout<<"1.Установить оба параметра\n";
    cout<<"2.Изменение значения для параметра квадратного кореня из произведения расстояний, "
          "от фокусов до любой точки(a)\n";
    cout<<"3.Изменение значения для параметра расстояния между фокусом и центром(c)\n";
    int choice;

    cin>>choice;
    if(choice != 1 and choice!= 2 and choice != 3){
        cout<<"Введено неверное значение\n";
    }

    if(choice == 1) {
        double half_dist;
        double square_root;
        cout << "Введите значения для параметра квадратного кореня из произведения расстояний, "
                "от фокусов до любой точки(a)\n";
        cin >> square_root;
        cout << "Введите значения для параметра расстояния между фокусом и центром(c)\n";
        cin >> half_dist;
        set_both_parameters(square_root, half_dist);

    }

    if(choice == 2){
        double square_root;
        cout << "Введите значения для параметра квадратного кореня из произведения расстояний, "
                "от фокусов до любой точки(a)\n";
        cin >> square_root;

        set_square_root(square_root);
    }

    if(choice == 3){
        double half_dist;
        cout << "Введите значения для параметра расстояния между фокусом и центром(c)\n";
        cin >> half_dist;

        set_half_dist(half_dist);
    }

}

char *func_output(Cassini &line) {
    double c = line.get_half_dist();
    double a = line.get_square_root();

    string result =
            "(x^2 + y^2)^2 -" + to_string(2 * c * c) + "(x^2 - y^2) = " + to_string(a * a * a * a - c * c * c * c);

    char *cstr = new char[result.length() + 1];
    strcpy(cstr, result.c_str());
    return cstr;

}

void Cassini::T_func_output() {

    char *final = func_output(*this);
    cout << final << endl;
}


void Cassini::type_shape() { //Определение типа кривой
    double c = get_half_dist();
    double a = get_square_root();

    double s = c/a;

    if ((a == 0) and (c != 0)) {
        cout << "Кривая вырождается в две точки, которые совпадают с фокусами.\n";
        return;
    }

    if (a == c and (a!=0)) {
        cout << "Кривая становится лемнискатой Бернулли (знак бесконечности).\n";
        return;
    }

    if ((1/sqrt(2)< s) and (s < 1)) {
        cout << "Фигура подобна форме арахиса\n";
        return;
    }

    if ((0 < s) and (s < 1/ sqrt(2))) {
        cout << "Кривая становится овалом, то есть выпуклой замкнутой кривой.\n";
        return;
    }

    if (1 < s) {
        cout << "Кривая распадается на два отдельных овала, каждый из которых вытянут в направлении другого и по форме "
                "напоминает яйцо.\n";
        return;
    }

    if ((c == 0) and (a != 0)) {
        cout
                << "По мере увеличения a (то есть стремления отношения c/a к нулю) кривая стремится к окружности радиуса a.\n";
        return;
    }

    cout << "Вырожденная кривая\n";

}

double new_r(int w, double r, Cassini &line){//функиця фозвращающая новое значение радиуса при смещении центра фигуры
    double cos_r = r * cos(w * (pi / 180));
    double sin_r = r * sin(w* (pi / 180));

    double X = cos_r + line.get_offset_x();
    double Y = sin_r + line.get_offset_y();

    return sqrt(X*X + Y*Y); //новый радиус
}


double find_dist(int w, Cassini &line){
    double c = line.get_half_dist();
    double a = line.get_square_root();

    double r,r_long;
    r = sqrt(c * c * cos(2 * w * (pi / 180)) +
             sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );  //* (pi / 180) в град.

    r_long = sqrt(c * c * cos(2 * w* (pi / 180) ) -
                  sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );

    r = new_r(w,r, line);
    r_long = new_r(w,r_long,line);

    cout<<"Расстояние до начала координат в полярных координатах = "<<r<<" "<<r_long<<endl;

    return r;
}

void Cassini::T_find_dist(){ //поиск расстояния от центра фигуры, до точки кривой, обозначенной углом
    int w;
    cout<<"Введите угол в градусах\n";
    cin>>w;

//    if(w >= 90 and w < 180){
//        w = w - 90;
//    }else
//        if(w >= 180 and w< 270){
//        w = w - 180;
//    }else
//    if(w >= 270 and w <= 360){
//        w = w - 270;
//    }else
    if(w > 360 or w < 0){
        cout<<"Неверный угол";
        return;
    }
    find_dist(w,*this);

}


double print_R(int w, Cassini &line){
    double c = line.get_half_dist();
    double a = line.get_square_root();

    double r,r_long;
    r = sqrt(c * c * cos(2 * w * (pi / 180)) +
             sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );  //* (pi / 180) в град.

    r_long = sqrt(c * c * cos(2 * w* (pi / 180) ) -
                  sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );

    r = new_r(w,r, line);
    r_long = new_r(w,r_long,line);

    cout<<"У данной кривой радиус кривизны = ";

    double R =  2*a*a*r*r*r/(pow(c,4)-pow(a,4)+3*pow(r,4));
    double R_long = 2*a*a*r_long*r_long*r_long/(pow(c,4)-pow(a,4)+3*pow(r_long,4));
    cout<<R<<" "<<R_long<<endl;

    return R;
}

void Cassini::T_print_R(){   //поиск радиуса кривизны точки кривой, обозначенной углом
    int w;
    cout<<"Введите угол в градусах [0;360]\n";
    cin>>w;

//    if(w >= 90 and w < 180){
//        w = 180 -w;
//    }
//    if(w >= 180 and w< 270){
//        w = 270 - w;
//    }
//    if(w >= 270 and w <= 360){
//        w = 360 - w;
//    }
    if(w > 360 or w < 0){
        cout<<"Неверный угол";
        return;
    }

    print_R(w, *this);
}



double inflect_point(Cassini &line) {
    double c = line.get_half_dist();
    double a = line.get_square_root();

    if (c < a < c * sqrt(2)) {
        cout << "У кривой существуют четыре симметричные точки перегиба (по одной в каждой координатной четверти)\n";

        double r = pow(((pow(a, 4) - pow(c, 4)) / 3), 0.25);
        double x = r * sqrt((1 - sqrt(1 / 3 * (pow(a, 4) / pow(c, 4)))) / 2);
        double y = r * sqrt(1 - (1 - sqrt(1 / 3 * (pow(a, 4) / pow(c, 4)))) / 2);

        cout<<"x1 ="<<x + line.get_offset_x()<<"  y1 = "<<y + line.get_offset_y()<<endl;
        cout<<"x2 ="<<-x + line.get_offset_x()<<"  y2 = "<<y + line.get_offset_y()<<endl;
        cout<<"x3 ="<<x + line.get_offset_x()<<"  y3 = "<<-y + line.get_offset_y()<<endl;
        cout<<"x4 ="<<-x + line.get_offset_x()<<"  y4 = "<<-y + line.get_offset_y()<<endl;
        return x;
    }else{
        cout<<"У данной кривой не существует точек перегиба\n";
        return 0;
    }

}

void Cassini::T_inflect_point(){ //поиск точек перегиба кривой
    inflect_point(*this);
}

void Cassini::func_change_point_offer(){
    cout<<"введите смещение по х\n";

    double x;
    cin>>x;
    cout<<"введите смещение по y\n";
    double y;
    cin>>y;

    this->offset_x = x;
    this->offset_y = y;

}






