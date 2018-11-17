#ifndef OOP_SAMPLES_STUDENT_H
#define OOP_SAMPLES_STUDENT_H

#include <iostream>
using namespace std;
class employee{
private:
    //Ажилчны дугаар 
    int id;
    //Ажилчны нэрны хаягийг хадгалах 
    char *name;
    //Ажилчны албан тушаалын хаягийг хадгалах 
    char *position;
    //Ажилчны ажилласан цагийг хадгалах 
    float hours;
    //Даргын цалинг бодох 
    float boss_salary();
public:
    //Анхдагч байгуулагч функц 
    employee();
    //Параметртэй байгуулагч функц 
    employee(int id, char *name, char *position, float hours);
    //Устгагч функц 
    ~employee();
    //Ажилчны дугаарын утгыг авах 
    int get_id();
    //Ажилчны нэрны хаягийг авах 
    char* get_name();
    //Ажилчны албан тушаалын хаягийг авах 
    char* get_position();
    //Ажилчны ажилласан цагийг авах 
    float get_hours();
    //Дараах параметрүүдээр орж ирсэн утгуудыг оноох 
    void set_all(int id, char *name, char *position, float hours);
    //Ажилчны дугаар оноох 
    void set_id(int id);
    //Ажилчны нэрийг оноох 
    void set_name(char* name);
    //Ажилчны албан тушаалыг оноох 
    void set_position(char* position);
    //Ажилчны албан тушаалыг оноох 
    void set_hours(float hours);
    //Хуулагч функц 
    void copy(employee &e);
    //Эрэмбэлэх функц
    void sort(employee *e[], int size);
    //Ажилчны дугаар давхцлыг шалгах функц
    bool check_id(employee *e, int, int);
    //Гараас утга авах функц 
    void get_data();
    //Мэдээллийг хэвлэх функц 
    void show_data();
    //Цалин бодох функц 
    float salary();
    //Нэмэлт цаг тооцох функц 
    bool inc_hours(float hours);
};
#endif //OOP_SAMPLES_STUDENT_H
