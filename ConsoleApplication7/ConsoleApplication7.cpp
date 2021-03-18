#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

class student
{
public:
    student()
    {
        _fio = "";
        _gender = ' ';
        _group = 0;
        _number = 0;
        _exam_result[0] = 0;
        _exam_result[1] = 0;
        _exam_result[2] = 0;
        _dif_exam_result[0] = 0;
        _dif_exam_result[1] = 0;
        _dif_exam_result[2] = 0;
        _dif_exam_result[3] = 0;
        _dif_exam_result[4] = 0;
        _form = "";
        _time = "";
    }

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
    void set_dif_exam_results(int* dif_exam_result)
    {
        _dif_exam_result[0] = dif_exam_result[0];
        _dif_exam_result[1] = dif_exam_result[1];
        _dif_exam_result[2] = dif_exam_result[2];
        _dif_exam_result[3] = dif_exam_result[3];
        _dif_exam_result[4] = dif_exam_result[4];
    };
    int* get_dif_exam_results() { return _dif_exam_result; };
    void set_form(std::string form) { _form = form; };
    std::string get_form() { return _form; };
    void set_number(int number) { _number = number; };
    int get_number() { return _number; };
    void set_time(std::string time) { _time = time; };
    std::string get_time() { return _time; };

private:
    std::string _fio;
    char _gender;
    int _group;
    int _number;
    int _exam_result[3];
    int _dif_exam_result[5];
    std::string _form;
    std::string _time;
};

void show_students(int n, student *students)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Student " << i << '\n';
        std::cout << "Name: " << students[i].get_name << '\n';
        std::cout << "Number of group: " << students[i].get_group << '\n';
        std::cout << "Order in group: " << students[i].get_number << '\n';
        std::cout << "Gender: " << students[i].get_gender << '\n';

    }
}

int main()
{
    int n;
    int len_arr = 0;
    std::string name, surname, patronymic, fio;
    char gender;
    int group, number;
    int index;
    int exam_result[3];
    int dif_exam_result[5];
    bool check; 
    student array[250];
    std::string form, time, weekday, month, day, hms, year;
    try
    {
        std::ifstream fin("data.txt");
        if (!fin.is_open()) throw "Check file: data.txt must exist";
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
        }
        std::ofstream fout("data.txt", std::ios_base::app);
        len_arr -= 1;
        std::cout << "Hello!\nWelcome to the base of students. What do you want to do?\n";
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
                if (!std::cin) throw "Invalid name. Remember that it can contain only 3 words, not longer than 255 symbols";
                fio = name + ' ' + surname + ' ' + patronymic;
                array[len_arr - 1].set_name(fio);
                std::cout << "Write gender of this student: ";
                std::cin >> gender;
                array[len_arr - 1].set_gender(gender);
                std::cout << "Write group of this student: ";
                std::cin >> group;
                array[len_arr - 1].set_group(group);
                std::cout << "Write education form of this student: ";
                std::cin >> form;
                array[len_arr - 1].set_form(form);
                std::cout << "Write number of this student: ";
                std::cin >> number;
                array[len_arr - 1].set_number(number);
                if (!std::cin) throw "Invalid gender, group or education form. Gender must be a letter, group must be a number";
                std::cout << "Write results of three exams: ";
                std::cin >> exam_result[0] >> exam_result[1] >> exam_result[2];
                if (!std::cin) throw "Invalid results of exams. They must be numbers";
                array[len_arr - 1].set_exam_results(exam_result);
                std::cout << "Write results of five pass-fail grading tests: ";
                std::cin >> dif_exam_result[0] >> dif_exam_result[1] >> dif_exam_result[2] >> dif_exam_result[3] >> dif_exam_result[4];
                if (!std::cin) throw "Invalid five pass-fail grading tests. They must be numbers";
                array[len_arr - 1].set_dif_exam_results(dif_exam_result);
                std::cout << "Write time of changing information: ";
                std::cin >> weekday >> month >> day >> hms >> year;
                if (!std::cin) throw "Invalid time";
                time = weekday + ' ' + month + ' ' + day + ' ' + hms + ' ' + year;
                array[len_arr - 1].set_time(time);
                if (len_arr > 1) fout << '\n';
                fout << fio << '\n' << group << '\n' << number << '\n' << gender << '\n' << form << '\n';
                fout << exam_result[0] << ' ' << exam_result[1] << ' ' << exam_result[2] << ' ' << dif_exam_result[0] << ' ' << dif_exam_result[1] << ' ' << dif_exam_result[2] << ' ' << dif_exam_result[3] << ' ' << dif_exam_result[4];
                fout << '\n' << time;
                break;
            }
            case(2):
            {
                std::cout << "If you would like to change name, write 1\n";
                std::cout << "If you would like to change gender, write 2\n";
                std::cout << "If you would like to change group number, write 3\n";
                std::cout << "If you would like to change education form, write 4\n";
                std::cout << "If you would like to change results of three exams, write 5\n";
                std::cout << "If you would like to change five pass-fail grading tests, write 6\n";
                std::cout << "If you would like to change order, write 7\n";
                std::cin >> check;
                if (std::cin or check < 1 or check > 6) throw "You need write a number from 1 to 6";
                switch (check)
                {
                case(1):
                {
                    std::cout << "Write name, surname and patronymic: ";
                    std::cin >> name >> surname >> patronymic;
                    if (!std::cin) throw "Invalid name";

                }
                case(2):
                {
                    std::cout << "Write gender: ";
                    std::cin >> gender;
                    if (!std::cin) throw "Invalid gender. Gender must be a letter";
                }
                case(3):
                {
                    std::cout << "Write group: ";
                    std::cin >> group;
                    if (!std::cin) throw "Invalid group. It must be a number";
                }
                case(4):
                {
                    std::cout << "Write education form: ";
                    std::cin >> form;
                    if (!std::cin) throw "Invalid education form";
                }
                case(5):
                {
                    std::cout << "Write results of three exams: ";
                    std::cin >> exam_result[0] >> exam_result[1] >> exam_result[2];
                    if (!std::cin) throw "Invalid results of exams. They must be numbers";
                }
                case(6):
                {
                    std::cout << "Write results of five pass-fail grading tests: ";
                    std::cin >> dif_exam_result[0] >> dif_exam_result[1] >> dif_exam_result[2] >> dif_exam_result[3] >> dif_exam_result[4];
                    if (!std::cin) throw "Invalid five pass-fail grading tests. They must be numbers";
                }
                case(7):
                {
                    std::cout << "Write order: ";
                    std::cin >> number;
                    if (!std::cin) throw "Invalid order. It must be a number";
                }
                }
            }
            case(3):
            {

            }
            }
            std::cout << "\nWhat do you want to do?\n";
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