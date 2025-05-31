#include <iostream>
using namespace std;

/*Створити клас «Time», який буде описувати час 3 - ма характеристиками : години, хвилини, секунди.
В класі потрібно реалізувати наступні конструктори :
Конструктор по замовчуванню() – встановлюватиме початкові дані
Параметризований(hours, minutes, seconds) – встановлює кожну властивість
Параметризований(seconds) – створює клас перевівши дану кількість секунд в години, хвилини, секунди.Наприклад: 5555 = 1год 32хв 35сек
5555 / 3600 - h; 5555 / 60 % 60 – m; 5555 % 60 - s
Також передбачити методи :
Виводу часу на екран в форматі hh : mm:ss
Збільшення часу на одну секунду(11:59 : 59)++ -> 12 : 00 : 00
Клас повинен мати перевантаження наступних бінарних операторів :
+– * / виконується певна арифметична операція з часом та повертається результат у вигляді нового об'єкту Time
> < >= <=	перевіряється, який об’єкт містить більшу / меншу кількість часу та повертається результат у вигляді типу bool
 == !=		перевіряється чи класи мають не / однаковий час
Використайте explicit для деяких конструкторів.*/
class Time {
    int hours;
    int minutes;
    int seconds;

    void stabilization() {
        if (hours >= 24){
            hours = hours % 24;
        }
        if (minutes >= 60){
            hours += minutes / 60;
            minutes = minutes % 60;
        }
        if (seconds >= 60){
            minutes += seconds / 60;
            seconds = seconds % 60;
        }
    };
public:
    Time() : hours(0), minutes(0), seconds(0) {};

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        stabilization();
    };

    explicit Time(int s) {
        //5555 = 1год 32хв 35сек
        //5555 / 3600 - h; 5555 / 60 % 60 – m; 5555 % 60 - s
        this->hours = s / 3600;
        this->minutes = s / 60 % 60;
        this->seconds = s % 60;
        stabilization();
    }

    void timeDisplay() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << endl;
    };
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time operator+(const Time& other) {
        Time res(this->toSeconds()+other.toSeconds());
        return(res);
    }
    Time operator-(const Time& other) {
        Time res(this->toSeconds()-other.toSeconds());
        return(res);
    }
    /*Time operator*(const Time& other) {
        Time res(this->toSeconds()*other.toSeconds());
        return(res);
    }
    Time operator/(const Time& other) {
        Time res(this->toSeconds()/other.toSeconds());
        return(res);
    }*/
    Time operator*(int multy) {
        Time res(this->toSeconds() * multy);
        return(res);
    }
    Time operator/(int div) {
        Time res(this->toSeconds() / div);
        return(res);
    }

    bool operator>(const Time& other) {
        return (this->toSeconds() > other.toSeconds());
    }
    bool operator>=(const Time& other) {
        return (this->toSeconds() >= other.toSeconds());
    }
    bool operator<(const Time& other) {
        return (this->toSeconds() < other.toSeconds());
    }
    bool operator<=(const Time& other) {
        return (this->toSeconds() <= other.toSeconds());
    }

    bool operator==(const Time& other) {
        return (this->toSeconds() == other.toSeconds());
    }
    bool operator!=(const Time& other) {
        return (this->toSeconds() != other.toSeconds());
    }
};

int main()
{
    Time t1(21, 5, 4);
    t1.timeDisplay();
    Time t2(5555);
    t2.timeDisplay();
    Time t3(11, 59, 59);
    t3.timeDisplay();
    Time t4(1);
    t4.timeDisplay();
    cout << "\n-- t3+t4 --" << endl;
    Time sum = t3 + t4;
    sum.timeDisplay();
    cout << "\n-- t3-t2 --" << endl;
    Time sub = t3 - t2;
    sub.timeDisplay();
    //Time dob = t1 * t3;
    //dob.timeDisplay();
    //Time div = t1 / t3;
    //div.timeDisplay();
    cout << "\n--Multypling t1 by 2--" << endl;
    Time multy = t1*2;
    multy.timeDisplay();
    cout << "\n--Dividing t1 by 2--" << endl;
    Time div = t1 / 2;
    div.timeDisplay();
    cout << "\n--Comparisons--" << endl;
    cout << (t1 > t2 ? "t1>t2" : "t1<t2") << endl;
    cout << (t1 >= t2 ? "t1>=t2" : "t1<t2") << endl;
    cout << (t1 < t2 ? "t2>t1" : "t1>t2") << endl;
    cout << (t1 <= t2 ? "t1<=t2" : "t1>t2") << endl;
    cout << (t1 == t2 ? "t1=t2" : "t1!=t2") << endl;
    cout << (t1 != t2 ? "t1!=t2" : "t1==t2") << endl;
}
