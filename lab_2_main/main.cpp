#include <iostream>
#include <Class.h>

using namespace std;

int main() {

    int choice;

    Cassini *line = new Cassini();

    do {
        cout<<"1.Определение новых параметров линии Кассини\n";
        cout<<"2.Вернуть расстояние до центра в полярной системе координат\n";
        cout<<"3.Определить тип формы линии Кассини\n";
        cout<<"4.Определить радиус кривизны в зависимости от угла полярного радиуса\n";
        cout<<"5.Определить координаты точек перегиба линии Кассини.\n";
        cout<<"6.Вывести текстовое представление уравнения линии Кассини в декартовой системе координат\n";
        cout<<"7.Определить координаты точек смещения.\n";
        cout<<"0.Выход\n";

        choice = get_int();
        switch (choice) {
            case 1:
                line->func_field_fill();
                break;

            case 2:
                line->T_find_dist();
                break;

            case 3:
                line->type_shape();
                break;


            case 4:
                line->T_print_R();
                break;


            case 5:
                line->T_inflect_point();
                break;


            case 6:
                line->T_func_output();
                break;

            case 7:
                line->func_change_point_offer();
                break;


            case 0:
                break;


            default:
                cout<<"Неверно выбран пункт меню\n";
                break;

        }

    } while (choice != 0);

    delete line;
    return 0;
}
