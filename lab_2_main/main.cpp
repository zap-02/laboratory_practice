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
        cout<<"0.Выход\n";

        choice = get_int();
        switch (choice) {
            case 1:
                func_field_fill(*line);
                break;

            case 2:
                T_find_dist(*line);
                break;

            case 3:
                type_shape(*line);
                break;


            case 4:
                T_print_R(*line);
                break;


            case 5:
                T_inflect_point(*line);
                break;


            case 6:
                T_func_output(*line);
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
