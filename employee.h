#include "employee.h"
#include <iostream>
#include <string.h>

int current_staff_number = 0;

//Ажилчин классын анхдагч байгуулагч функц
employee::employee(){
    //Ажилчны дугаар 
    id = 0;
    //Ажилчны нэр 
    name = new char[20];
    //Гарааны утгыг утгыг хуулах функц 
    strcpy(name, "Default name");
    //Ажилчны албан тушаал
    position = new char[20];
    //Гарааны утгыг хуулах функц
    strcpy(position, "Staff");
    //Ажилласан цаг
    hours = 0;
}
//Ажилчин классын параметртэй байгуулагч функц
employee::employee(int id, char *name, char *position, float hours){
    //Дугаар, нэр, албан тушаал, цагийг нэгэн зэрэг утга буцаах функц
    set_all(id, name, position, hours);
}
//Ажилчин классын устгагч функц
employee::~employee(){
    cout << "Deleted id: " << id << endl;
    //Нэрэнд нөөцөлсөн санах ойг устгах 
    delete []name;
    //Албан тушаалд нөөцөлсөн санах ойг устгах 
    delete []position;
}
//Ажилчны дугаар, нэр, албан тушаал, ажилласан цагийг барьж авах функц
int employee::get_id(){
    //Дугаар буцаах 
    return id;
}
char* employee::get_name(){
    //Нэрийг буцаах 
    return name;
}
char* employee::get_position(){
    //Албан тушаалыг буцаах 
    return position;
}
float employee::get_hours(){
    //Ажилласан цагийг буцаах
    return hours;
}
//Параметртэй байгуулагчид утга оноох гишүүн функц 
void employee::set_all(int new_id, char *new_name, char *new_position, float new_hours){
    set_id(new_id);
    set_name(new_name);
    set_position(new_position);
    set_hours(new_hours);
}
//Ажилчны дугаарт параметрээр орж ирсэн утгыг олгох
void employee::set_id(int new_id){
//Ажилчны дугаар оноож өгөх
    this->id = new_id;
}
//Ажилчны нэрэнд параметрээр орж ирсэн хаягийг олгох 
void employee::set_name(char *new_name){
    //Хуучин ойг чөлөөлөх 
    if(this->name != NULL)
        delete []name;
    //Шинэ ойг нөөцлөх 
    this->name = new char[strlen(name+1)];
    strcpy(this->name, name);
}
//Ажилчны албан тушаалд параметрээр орж ирсэн хаягийг олгох
void employee::set_position(char *new_position){
    //Хуучин ойг чөлөөлөх 
    if(this->position != NULL)
        delete []position;
    //Шинэ ойг нөөцлөх 
    this->position = new char[strlen(new_position+1)];
    strcpy(this->position, new_position);
}
//Ажилчны ажилласан цаганд параметрээр орж ирсэн утгыг олгох 
void employee::set_hours(float new_hours){
    this->hours = new_hours;
}
//Ажилчин классын хуулагч функц
void employee::copy(employee &e){
    set_all(e.id, e.name, e.position, e.hours);
}
//Ажилчин классын нэрээр эрэмбэлэх функц
void employee::sort(employee *e[], int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            //Нэрсийн дарааллын дагуу шалгаж
            //өөрөөс нь их зэрэгтэй үсгээр эхэлсэн ажилчны 
            //хаяган хүснэгтийн хаягийг солих 
            if(strcmp(e[i]->name, e[j]->name)>0){
                //Нөхцөл биелсэн үед
                //хоёр хаягийн байрыг солих
                e* temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}
//Ажилчны дугаар давхцалтай байгаа эсэхийг шалгах функц
bool employee::check_id(employee *e, int new_id, int current_staff_number){
    for(int i=0;i<current_staff_number;i++){
        if(new_id == e[i].get_id()){
            return 1;
            break;
        }
    }
    return 0;
}

//Ажилчин классын мэдээллийг гараас авах функц
void employee::get_data(){
    int new_id;
    char new_name[20];
    char new_position[20];
    float new_hours;
    cout << "Enter staff id: ";
    cin >> new_id;
    if(check_id(new_id)==0){
        ++current_staff_number;
        id = new_id;
        cout << "Enter staff name: ";
        cin >> new_name;
        cout << "Enter staff position: ";
        cin >> new_position;
        cout << "Enter staff hours: ";
        cin >> new_hours;
        set_all(id, new_name, new_position, new_hours);
    }
    else{
        cout << "Sorry, Staff id already exists." << endl;
      break;
    }
}
//Ажилчин классын мэдээллийг хэвлэх функц
void employee::show_data(){
    cout << "Staff id: " << id << endl;
    cout << "Staff name: " << name << endl;
    cout << "Staff position: " << position << endl;
    cout << "Staff hours: " << hours << endl;
}
//Ажилчин классын даргын цалин бодох функц
float employee::boss_salary(){
    //Даргын цалин 5 нэгжээр их 
    return hours*5;
}
//Ажилчин классын цалин бодох функц
float employee::salary(){
    //Дарга мөн эсэхийг шалгах 
    if(!strcmp(position, "boss"))
        return hours*100 + boss_salary();
    return hours*100;
}
//Ажилчин классын нэмэлт цаг бодох функц
bool employee::inc_hours(float time){
    if(time>0 && time<24){
        //Үндсэн цаг дээр нэмэлт цагийг тооцон нийт цалинг бодох 
        hours = hours + time;
        return 1;
    }
    return 0;
}
int main(){
    int n, i;
    float hours;
    cout << "Enter number of employees: ";
    //Хэдэн ажилчин бүртгэж авах
    cin >> n;
    //Обьектэн хүснэгт зарлаж байна.
    employee emp[n];
    //Обьектуудын хаягийг хадгалах хүснэгт
    employee *e[n];
    for(i = 0; i < n; i++){
        //Обьектэд утга авах 
        emp[i].get_data();
        cout << "Enter additional time: ";
        //Нэмэлт цаг тооцох
        cin >> hours;
        if(emp[i].inc_hours(hours) == 1)
            cout << "\nSuccessfully added." << endl;
        else
            cout << "\nUnsuccessfully added." << endl;
        //Обьектын мэдээллийг хэвлэх
        emp[i].show_data();
        cout << "Salary: " << emp[i].salary() << "\n--------------------\n";
    }
    //Обьектүүдын хаягийг хүснэтэнд давталтаар утгуудыг оноож өгч байна.
    for(i=0; i<n; i++)
        e[i] = &emp[i];
    //Ажилчдыг нэрээр нь эрэмбэлэх
    emp[0].sort(emp, n);
    //Эрэмбэлсэн хүснэгтээс мэдээллийг дэлгэцлэх давталт
    for(i=0;i<n;i++){
        emp[i]->show_data();
        cout << endl;
    }
    return 0;
}
