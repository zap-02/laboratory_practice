#include "Class.h"
#include <iostream>
#include <string.h>
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

void func_field_fill(Cassini &line) {
    double half_dist;
    double square_root;
    cout << "Введите значения для параметра квадратного кореня из произведения расстояний, "
            "от фокусов до любой точки(a)\n";
    cin >> square_root;
    cout << "Введите значения для параметра расстояния между фокусом и центром(c)\n";
    cin >> half_dist;
    line.set_parameters(square_root, half_dist);
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

void T_func_output(Cassini &line) {

    char *final = func_output(line);
    cout << final << endl;
}


void type_shape(Cassini &line) { //Определение типа кривой
    double c = line.get_half_dist();
    double a = line.get_square_root();

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
double find_dist(int w, Cassini &line){
    double c = line.get_half_dist();
    double a = line.get_square_root();

    double r,r_long;
    r = sqrt(c * c * cos(2 * w * (pi / 180)) +
             sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );  //* (pi / 180) в град.

    r_long = sqrt(c * c * cos(2 * w* (pi / 180) ) -
                  sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );

    cout<<"Расстояние до начала координат в полярных координатах = "<<r<<" "<<r_long<<endl;

    return r;
}

void T_find_dist(Cassini &line){ //поиск расстояния от центра фигуры, до точки кривой, обозначенной углом
    int w;
    cout<<"Введите угол в градусах\n";
    cin>>w;

    if(w >= 90 and w < 180){
        w = 180 - w;
    }
    if(w >= 180 and w< 270){
        w = 270 - w;
    }
    if(w >= 270 and w <= 360){
        w = 360 - w;
    }
    if(w > 360 or w < 0){
        cout<<"Неверный угол";
        return;
    }
    find_dist(w,line);

}


double print_R(int w, Cassini &line){
    double c = line.get_half_dist();
    double a = line.get_square_root();

    double r,r_long;
    r = sqrt(c * c * cos(2 * w * (pi / 180)) +
             sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );  //* (pi / 180) в град.

    r_long = sqrt(c * c * cos(2 * w* (pi / 180) ) -
                  sqrt  ( pow(c, 4) * pow(cos(2 * w* (pi / 180) ), 2) + pow(a, 4) - pow(c, 4)  )   );

    cout<<"У данной кривой радиус кривизны = ";

    double R =  2*a*a*r*r*r/(pow(c,4)-pow(a,4)+3*pow(r,4));
    double R_long = 2*a*a*r_long*r_long*r_long/(pow(c,4)-pow(a,4)+3*pow(r_long,4));
    cout<<R<<" "<<R_long<<endl;

    return R;
}

void T_print_R(Cassini &line){   //поиск радиуса кривизны точки кривой, обозначенной углом
    int w;
    cout<<"Введите угол в градусах [0;360]\n";
    cin>>w;

    if(w >= 90 and w < 180){
        w = 180 -w;
    }
    if(w >= 180 and w< 270){
        w = 270 - w;
    }
    if(w >= 270 and w <= 360){
        w = 360 - w;
    }

    print_R(w,line);
}



double inflect_point(Cassini &line) {
    double c = line.get_half_dist();
    double a = line.get_square_root();

    if (c < a < c * sqrt(2)) {
        cout << "У кривой существуют четыре симметричные точки перегиба (по одной в каждой координатной четверти)\n";

        double r = pow(((pow(a, 4) - pow(c, 4)) / 3), 0.25);
        double x = r * sqrt((1 - sqrt(1 / 3 * (pow(a, 4) / pow(c, 4)))) / 2);
        double y = r * sqrt(1 - (1 - sqrt(1 / 3 * (pow(a, 4) / pow(c, 4)))) / 2);

        cout<<"x1 ="<<x<<"  y1 = "<<y<<endl;
        cout<<"x2 ="<<-x<<"  y2 = "<<y<<endl;
        cout<<"x3 ="<<x<<"  y3 = "<<-y<<endl;
        cout<<"x4 ="<<-x<<"  y4 = "<<-y<<endl;
        return x;
    }else{
        cout<<"У данной кривой не существует точек перегиба\n";
        return 0;
    }

}

void T_inflect_point(Cassini &line){ //поиск точек перегиба кривой
    inflect_point(line);
}






