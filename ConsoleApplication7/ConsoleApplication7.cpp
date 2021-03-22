#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h> 

//Число элементов в массиве студентов: можно изменить, если по условию надо больше или меньше
const int N = 250;

//Класс студентов
class student
{
public:
    //Конструктор класса, созданный без передачи данных
    student()
    {
    }

    //Конструктор класса, созданный с передачей всех данных
    student(std::string fio, char gender, int group, int number, int* exam_result, int* dif_exam_result, std::string form, std::string time)
    {
        _fio = fio;
        _gender = gender;
        _group = group;
        _number = number;
        _exam_result[0] = exam_result[0];
        _exam_result[1] = exam_result[1];
        _exam_result[2] = exam_result[2];
        _dif_exam_result[0] = dif_exam_result[0];
        _dif_exam_result[1] = dif_exam_result[1];
        _dif_exam_result[2] = dif_exam_result[2];
        _dif_exam_result[3] = dif_exam_result[3];
        _dif_exam_result[4] = dif_exam_result[4];
        _form = form;
        _time = time;
    }

    //Функции для переноса данных в класс (set) или получения данных из класса (get)
    void set_name(std::string fio) { _fio = fio; };
    std::string get_name() { return _fio; };
    void set_gender(char gender) { _gender = gender; };
    char get_gender() { return _gender; };
    void set_group(int group) { _group = group; };
    int get_group() { return _group; };
    void set_exam_results(int *exam_result) 
    { _exam_result[0] = exam_result[0];
    _exam_result[1] = exam_result[1];
    _exam_result[2] = exam_result[2];
    };
    int *get_exam_results() { return _exam_result; };
    //Функции show выводят результаты данных на консоль
    void show_exam_results()
    {
        std::cout <<_exam_result[0] << ' ' << _exam_result[1] << ' ' << _exam_result[2] << '\n';
    };
    void set_dif_exam_results(int* dif_exam_result)
    {
        _dif_exam_result[0] = dif_exam_result[0];
        _dif_exam_result[1] = dif_exam_result[1];
        _dif_exam_result[2] = dif_exam_result[2];
        _dif_exam_result[3] = dif_exam_result[3];
        _dif_exam_result[4] = dif_exam_result[4];
    };
    int* get_dif_exam_results() { return _dif_exam_result; };
    void show_dif_exam_results()
    {
        std::cout << _dif_exam_result[0] << ' ' << _dif_exam_result[1] << ' ' << _dif_exam_result[2] << ' ' << _dif_exam_result[3] << ' ' << _dif_exam_result[4] << '\n';
    };
    void set_form(std::string form) { _form = form; };
    std::string get_form() { return _form; };
    void set_number(int number) { _number = number; };
    int get_number() { return _number; };
    void set_time(std::string time) { _time = time; };
    std::string get_time() { return _time; };
    void set_hour(std::string hour) { _hour = hour; };
    std::string get_hour() { return _hour; };

    //Функция для пятого задания: подсчитывает и возвращает сумму всех оценок студента
    int summ_results()
    {
        int summ = 0;
        summ += _exam_result[0] +_exam_result[1] +_exam_result[2];
        summ += _dif_exam_result[0] + _dif_exam_result[1] + _dif_exam_result[2] + _dif_exam_result[3] + _dif_exam_result[4];
        return summ;
    }
    //Функции для седьмого-восьмого задания
    //Возвращает, получает ли студент стипендию
    bool scholarship()
    {
        bool if_scholarship = 0;
        if (_form == "day") if_scholarship = 1;
        if (_exam_result[0] < 4) if_scholarship = 0;
        if (_exam_result[1] < 4) if_scholarship = 0;
        if (_exam_result[2] < 4) if_scholarship = 0;
        if (_dif_exam_result[0] < 4) if_scholarship = 0;
        if (_dif_exam_result[1] < 4) if_scholarship = 0;
        if (_dif_exam_result[2] < 4) if_scholarship = 0;
        if (_dif_exam_result[3] < 4) if_scholarship = 0;
        if (_dif_exam_result[4] < 4) if_scholarship = 0;
        return if_scholarship;
    }
    //Возвращает, получает ли студент только четвёрки и пятёрки
    bool if_learning_good()
    {
        bool check = 1;
        if (_exam_result[0] < 4) check = 0;
        if (_exam_result[1] < 4) check = 0;
        if (_exam_result[2] < 4) check = 0;
        if (_dif_exam_result[0] < 4) check = 0;
        if (_dif_exam_result[1] < 4) check = 0;
        if (_dif_exam_result[2] < 4) check = 0;
        if (_dif_exam_result[3] < 4) check = 0;
        if (_dif_exam_result[4] < 4) check = 0;
        return check;
    }
    //Возвращает, получает ли студент одни пятёрки
    bool if_learning_best()
    {
        bool check = 1;
        if (_exam_result[0] < 5) check = 0;
        if (_exam_result[1] < 5) check = 0;
        if (_exam_result[2] < 5) check = 0;
        if (_dif_exam_result[0] < 5) check = 0;
        if (_dif_exam_result[1] < 5) check = 0;
        if (_dif_exam_result[2] < 5) check = 0;
        if (_dif_exam_result[3] < 5) check = 0;
        if (_dif_exam_result[4] < 5) check = 0;
        return check;
    }

private:
    std::string _fio;
    char _gender;
    int _group;
    int _number;
    int _exam_result[3];
    int _dif_exam_result[5];
    std::string _form;
    std::string _time;
    std::string _hour;
};

//Функция обмена данных в переменных
void swap(int& a, int& b)
{
    int save;
    save = a;
    a = b;
    b = save;
}

//Функция для третьего задания
void show_students(int len, student *students)
{
    std::cout << '\n';
    for (int i = 0; i < len; i++)
    {
        std::cout << "Student " << i + 1 << '\n';
        std::cout << "Name: " << students[i].get_name() << '\n';
        std::cout << "Number of group: " << students[i].get_group() << '\n';
        std::cout << "Order in group: " << students[i].get_number() << '\n';
        std::cout << "Gender: " << students[i].get_gender() << '\n';
        std::cout << "Form of education: " << students[i].get_form() << '\n';
        std::cout << "Results of exams: ";
        students[i].show_exam_results();
        std::cout << "Results of pass-fail grading tests: ";
        students[i].show_dif_exam_results();
        std::cout << "Time: " << students[i].get_time() << '\n';
        std::cout << '\n';
    }
}

//Данная функция повторяет предыдущую, за исключением того, что выводит данные лишь об одном студенте
void show_student(int len, student person)
{
    std::cout << '\n';
    std::cout << "Name: " << person.get_name() << '\n';
    std::cout << "Number of group: " << person.get_group() << '\n';
    std::cout << "Order in group: " << person.get_number() << '\n';
    std::cout << "Gender: " << person.get_gender() << '\n';
    std::cout << "Form of education: " << person.get_form() << '\n';
    std::cout << "Results of exams: ";
    person.show_exam_results();
    std::cout << "Results of pass-fail grading tests: ";
    person.show_dif_exam_results();
    std::cout << "Time: " << person.get_time() << '\n';
    std::cout << '\n';
}

//Функция для четвёртого задания: выводятся данные студентов определённой группы
void show_students_of_group(int len, student* students, int group)
{
    std::cout << '\n';
    int check = 0;
    for (int i = 0; i < len; i++)
    { 
        if (group == students[i].get_group())
        {
            check++;
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
    if (check == 0) std::cout << "There are not students in group " << group << '\n';
}

//Функция для пятого задания: выводятся данные лучших студентов (до трёх человек, в зависимости от количества человек в базе)
void show_top_students(int len, student* students)
{
    std::cout << '\n';
    int indexes[3] = {-1, -1, -1};
    int top_results[3] = { 0, 0, 0 };
    int results[N];
    for (int i = 0; i < N; i++)
    {
        results[i] = 0;
    }
    //Вначале подсчитываются оценки всех студентов
    for (int i = 0; i < len; i++)
    {
        results[i] = students[i].summ_results();
    }
    //Потом с помощью этих данных ищутся индексы студентов с максимальным баллом
    for (int i = 0; i < len; i++)
    {
        if (top_results[0] < results[i])
        {
            swap(top_results[2], top_results[1]);
            swap(top_results[1], top_results[0]);
            top_results[0] = results[i];
            swap(indexes[2], indexes[1]);
            swap(indexes[1], indexes[0]);
            indexes[0] = i;
        }
        else if (top_results[1] < results[i])
        {
            swap(top_results[2], top_results[1]);
            top_results[1] = results[i];
            swap(indexes[2], indexes[1]);
            indexes[1] = i;
        }
        else if (top_results[2] < results[i])
        {
            top_results[2] = results[i];
            indexes[2] = i;
        }
    }
    if (len > 0)
    {
        std::cout << "Average result: " << students[indexes[0]].summ_results() / 8. << '\n';
        show_student(len, students[indexes[0]]);
    }
    if (len > 1)
    {
        std::cout << "Average result: " << students[indexes[1]].summ_results() / 8. << '\n';
        show_student(len, students[indexes[1]]);
    }
    if (len > 2)
    {
        std::cout << "Average result: " << students[indexes[2]].summ_results() / 8. << '\n';
        show_student(len, students[indexes[2]]);
    }
}

//Функция для шестого задания: выводит количество девушек и юношей
void show_gender_stat(int len, student* students)
{
    int number_m = 0;
    int number_f = 0;
    for (int i = 0; i < len; i++)
    {
        if (students[i].get_gender() == 'F') number_f++;
        if (students[i].get_gender() == 'M') number_m++;
    }
    std::cout << "Number of female students: " << number_f << '\n';
    std::cout << "Number of male students: " << number_m << '\n';
}

//Функция для седьмого задания: выводит количество студентов, получающих стипендию
void show_students_with_scholarship(int len, student* students)
{
    std::cout << '\n';
    int number = 0;
    for (int i = 0; i < len; i++)
    {
        if (students[i].scholarship())
        {
            number++;
        }
    }
    std::cout << "Number of students with scholarship: " << number << '\n';
}

//Функция для восьмого задания
void task_eight(int len, student* students)
{
    std::cout << "Students without scholarship: \n";
    for (int i = 0; i < len; i++)
    {
        if (!students[i].scholarship())
        {
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
    std::cout << "Students only with 4 and 5: \n";
    for (int i = 0; i < len; i++)
    {
        if (students[i].if_learning_good())
        {
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
    std::cout << "Students only with 5: \n";
    for (int i = 0; i < len; i++)
    {
        if (students[i].if_learning_best())
        {
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
}

//Функция для девятого задания: выводит студентов под определённым номером
void show_students_with_order(int len, student* students, int order)
{
    std::cout << '\n';
    int check = 0;
    for (int i = 0; i < len; i++)
    {
        if (order == students[i].get_number())
        {
            check++;
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
    if (check == 0) std::cout << "There are not students with order " << order << '\n';
}

//Функция для десятого задания
void show_students_in_time(int len, student* students, std::string time)
{
    std::cout << '\n';
    int check = 0;
    std::cout << "Students with chosen time: \n";
    for (int i = 0; i < len; i++)
    {
        if (time == students[i].get_time())
        {
            check++;
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
    std::cout << "Students which data was redacted before 12 AM: \n";
    for (int i = 0; i < len; i++)
    {
        if ("12" > students[i].get_hour())
        {
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
    std::cout << "Students which data was redacted after 12 AM: \n";
    for (int i = 0; i < len; i++)
    {
        if ("12" <= students[i].get_hour())
        {
            std::cout << "Student " << i + 1 << '\n';
            std::cout << "Name: " << students[i].get_name() << '\n';
            std::cout << "Number of group: " << students[i].get_group() << '\n';
            std::cout << "Order in group: " << students[i].get_number() << '\n';
            std::cout << "Gender: " << students[i].get_gender() << '\n';
            std::cout << "Form of education: " << students[i].get_form() << '\n';
            std::cout << "Results of exams: ";
            students[i].show_exam_results();
            std::cout << "Results of pass-fail grading tests: ";
            students[i].show_dif_exam_results();
            std::cout << "Time: " << students[i].get_time() << '\n';
            std::cout << '\n';
        }
    }
}

int main()
{
    int n;
    int len_arr = 0;
    //Переменные для временного хранения данных, которые будут передаваться в класс
    std::string name, surname, patronymic, fio;
    char gender;
    int group, number;
    int index;
    int exam_result[3];
    int task_number;
    int dif_exam_result[5];
    bool check;
    student array[N];
    std::string form, time, weekday, month, day, hms, year;
    int hour;
    //Структура "try-throw-catch" используется для отлова исключений
    //В моей реализации она сообщает, в чём возникли проблемы: это помогает в тестировании, а также пользователь понимает, что он мог ввести некорректно
    try
    {
        //Данные хранятся в файле "data.txt": при желании его можно сменить
        std::ifstream fin("students.txt");
        if (!fin.is_open()) throw "Check file: data.txt must exist";
        //Все данные из файла сразу же переносятся в элементы массива
        //Тут проверка не осуществляется, так что при внесении данных напрямую в файл следует быть осторожнее
        while(fin)
        {
            len_arr += 1;
            std::getline(fin, fio);
            array[len_arr - 1].set_name(fio);
            fin >> group;
            array[len_arr - 1].set_group(group);
            fin >> number;
            array[len_arr - 1].set_number(number);
            fin >> gender;
            array[len_arr - 1].set_gender(gender);
            fin >> form;
            array[len_arr - 1].set_form(form);
            fin >> exam_result[0];
            fin >> exam_result[1];
            fin >> exam_result[2];
            array[len_arr - 1].set_exam_results(exam_result);
            fin >> dif_exam_result[0];
            fin >> dif_exam_result[1];
            fin >> dif_exam_result[2];
            fin >> dif_exam_result[3];
            fin >> dif_exam_result[4];
            array[len_arr - 1].set_dif_exam_results(dif_exam_result);
            fin.ignore(32767, '\n');
            std::getline(fin, time);
            array[len_arr - 1].set_time(time);
            array[len_arr - 1].set_hour(time.substr(11, 2));
        }
        //Файл открывается также и для записи, при том с конца файла (с помощью std::ios_base::app): это позволяет не перезаписывать уже имеющиеся данные
        std::ofstream fout("students.txt", std::ios_base::app);
        len_arr -= 1;
        std::cout << "Hello!\nWelcome to the base of students. What do you want to do?\n";
        std::cout << "1. Add new student\n";
        std::cout << "2. Change student's data\n";
        std::cout << "3. Show all students\n";
        std::cout << "4. Show students of chosen group\n";
        std::cout << "5. Show top students\n";
        std::cout << "6. Show number of men and women\n";
        std::cout << "7. Show number of students with scholarship\n";
        std::cout << "8. Show students without scholarship; learning on 4 anf 5; learning on 5\n";
        std::cout << "9. Show students with chosen order\n";
        std::cout << "10. Show students made in chosen time; made before midday; after midday\n";
        std::cout << "0. Exit\n";
        std::cin >> n;
        if (!std::cin) throw "Invalid Input";
        while (n)
        {
            switch (n)
            {
            case(1):
            {
                len_arr += 1;
                std::cout << "Write name, surname and patronymic of student: ";
                std::cin >> name >> surname >> patronymic;
                if (!std::cin) throw "Invalid name";
                fio = name + ' ' + surname + ' ' + patronymic;
                array[len_arr - 1].set_name(fio);
                std::cout << "Write gender of this student: ";
                std::cin >> gender;
                if (!std::cin) throw "Invalid gender (it must be a symbol)";
                array[len_arr - 1].set_gender(gender);
                std::cout << "Write group of this student: ";
                std::cin >> group;
                if (!std::cin) throw "Invalid group";
                array[len_arr - 1].set_group(group);
                std::cout << "Write education form of this student: ";
                std::cin >> form;
                if (!std::cin) throw "Invalid form";
                array[len_arr - 1].set_form(form);
                std::cout << "Write number of this student: ";
                std::cin >> number;
                if (!std::cin) throw "Invalid order";
                array[len_arr - 1].set_number(number);
                std::cout << "Write results of three exams: ";
                std::cin >> exam_result[0] >> exam_result[1] >> exam_result[2];
                if (!std::cin) throw "Invalid results of exams. They must be numbers";
                array[len_arr - 1].set_exam_results(exam_result);
                std::cout << "Write results of five pass-fail grading tests: ";
                std::cin >> dif_exam_result[0] >> dif_exam_result[1] >> dif_exam_result[2] >> dif_exam_result[3] >> dif_exam_result[4];
                if (!std::cin) throw "Invalid five pass-fail grading tests. They must be numbers";
                array[len_arr - 1].set_dif_exam_results(dif_exam_result);
                std::cout << "Write time (ex: Sat Feb 29 07:50:00 2020): ";
                std::cin >> weekday >> month >> day >> hms >> year;
                if (!std::cin) throw "Invalid time";
                time = weekday + ' ' + month + ' ' + day + ' ' + hms + ' ' + year;
                array[len_arr - 1].set_time(time);
                array[len_arr - 1].set_hour(hms.substr(0, 1));
                if (len_arr > 1) fout << '\n';
                //После внесения данных в класс, данные записываются в файл: их можно будет использовать на этом и следующих запусках программы
                fout << fio << '\n' << group << '\n' << number << '\n' << gender << '\n' << form << '\n';
                fout << exam_result[0] << ' ' << exam_result[1] << ' ' << exam_result[2] << ' ' << dif_exam_result[0] << ' ' << dif_exam_result[1] << ' ' << dif_exam_result[2] << ' ' << dif_exam_result[3] << ' ' << dif_exam_result[4];
                fout << '\n' << time;
                break;
            }
            case(2):
            {
                std::cout << "Write number of student (from 1 to " << len_arr << "): ";
                std::cin >> task_number;
                task_number--;
                if (!std::cin or task_number < 0 or task_number > len_arr - 1) throw "Invalid number of student";
                std::cout << "If you would like to change name, write 1\n";
                std::cout << "If you would like to change gender, write 2\n";
                std::cout << "If you would like to change group number, write 3\n";
                std::cout << "If you would like to change education form, write 4\n";
                std::cout << "If you would like to change results of three exams, write 5\n";
                std::cout << "If you would like to change five pass-fail grading tests, write 6\n";
                std::cout << "If you would like to change order, write 7\n";
                std::cin >> check;
                if ((!std::cin) or (check < 1) or (check > 6)) throw "You need write a number from 1 to 6";
                switch (check)
                {
                case(1):
                {
                    std::cout << "Write name, surname and patronymic: ";
                    std::cin >> name >> surname >> patronymic;
                    if (!std::cin) throw "Invalid name";
                    fio = name + ' ' + surname + ' ' + patronymic;
                    array[task_number].set_name(fio);
                    break;
                }
                case(2):
                {
                    std::cout << "Write gender: ";
                    std::cin >> gender;
                    if (!std::cin) throw "Invalid gender. Gender must be a letter";
                    array[task_number].set_gender(gender);
                    break;
                }
                case(3):
                {
                    std::cout << "Write group: ";
                    std::cin >> group;
                    if (!std::cin) throw "Invalid group. It must be a number";
                    array[task_number].set_group(group);
                    break;
                }
                case(4):
                {
                    std::cout << "Write education form: ";
                    std::cin >> form;
                    if (!std::cin) throw "Invalid education form";
                    array[task_number].set_form(form);
                    break;
                }
                case(5):
                {
                    std::cout << "Write results of three exams: ";
                    std::cin >> exam_result[0] >> exam_result[1] >> exam_result[2];
                    if (!std::cin) throw "Invalid results of exams. They must be numbers";
                    array[task_number].set_exam_results(exam_result);
                    break;
                }
                case(6):
                {
                    std::cout << "Write results of five pass-fail grading tests: ";
                    std::cin >> dif_exam_result[0] >> dif_exam_result[1] >> dif_exam_result[2] >> dif_exam_result[3] >> dif_exam_result[4];
                    if (!std::cin) throw "Invalid five pass-fail grading tests. They must be numbers";
                    array[task_number].set_dif_exam_results(dif_exam_result);
                    break;
                }
                case(7):
                {
                    std::cout << "Write order: ";
                    std::cin >> number;
                    if (!std::cin) throw "Invalid order. It must be a number";
                    array[task_number].set_number(number);
                    break;
                }
                }
                break;
            }
            case(3):
            {
                show_students(len_arr, array);
                break;
            }
            case(4):
            {
                std::cout << "Write number of group: ";
                std::cin >> task_number;
                if (!std::cin) throw "Invalid number of group";
                show_students_of_group(len_arr, array, task_number);
                break;
            }
            case(5):
            {
                show_top_students(len_arr, array);
                break;
            }
            case(6):
            {
                show_gender_stat(len_arr, array);
                break;
            }
            case(7):
            {
                show_students_with_scholarship(len_arr, array);
                break;
            }
            case(8):
            {
                task_eight(len_arr, array);
                break;
            }
            case(9):
            {
                std::cout << "Write order: ";
                std::cin >> task_number;
                if (!std::cin) throw "Invalid order";
                show_students_with_order(len_arr, array, task_number);
                break;
            }
            case(10):
            {
                std::cout << "Write time (ex: Sat Feb 29 07:50:00 2020): ";
                std::cin >> weekday >> month >> day >> hms >> year;
                if (!std::cin) throw "Invalid time";
                time = weekday + ' ' + month + ' ' + day + ' ' + hms + ' ' + year;
                show_students_in_time(len_arr, array, time);
            }
            }
            std::cout << "\nWhat do you want to do?\n";
            std::cout << "1. Add new student\n";
            std::cout << "2. Change student's data\n";
            std::cout << "3. Show all students\n";
            std::cout << "4. Show students of chosen group\n";
            std::cout << "5. Show top students\n";
            std::cout << "6. Show number of men and women\n";
            std::cout << "7. Show number of students with scholarship\n";
            std::cout << "8. Show students without scholarship; learning on 4 anf 5; learning on 5\n";
            std::cout << "9. Show students with chosen order\n";
            std::cout << "10. Show students made in chosen time; made before midday; after midday\n";
            std::cout << "0. Exit\n";
            std::cin >> n;
            if (!std::cin) throw "Invalid Input";
        }
        fin.close();
        fout.close();
    }
    catch (const char* ex)
    {
        std::cout << ex;
    }
    return 1;
}
