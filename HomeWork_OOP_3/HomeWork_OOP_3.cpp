#include <iostream>

using namespace std;

void DZ1()
{
	cout << "//===================================================[DZ1]===================================================//\n\n";
}
void DZ2()
{
	cout << "\n//===================================================[DZ2]===================================================//\n\n";
}
void DZ3()
{
	cout << "\n\n//===================================================[DZ3]===================================================//\n\n";
}

void delimiterDZ()
{
    cout << "\n//===========================================================================================================//\n\n";
}
void END()
{
	cout << "\n//===================================================[END]===================================================//\n\n";
}

	/* DZ1
	Создать абстрактный класс Figure (фигура).
	Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
	Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
	Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
	Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
	*/

class Figure //изначально он был отцом(основателем семейства класса, но у параллелограмма появились дети и теперь этот класс будет дедом.
{
protected:
    virtual void area() = 0; //чисто виртуальная функция area() (площадь).
};

class Parallelogram : protected Figure
{
protected:
    double base;   //основание(тело, тушка) праллелограмма.
    double height; //высота праллелограмма.
public:
    Parallelogram(double x_base, double v_height) : base(x_base), height(v_height) {}
    void area() override //для того, чтобы для каждого дочернего класса не вызывать в мейне функцию. дабы сократить код в мейне.
    {
        setlocale(LC_ALL, "rus");
        cout << "Площадь параллелограмма равна: " << base * height << endl;
    }
};

class Circle : protected Figure
{
public:
    double radius;   //радиус окружности.
    double P;        //число Пи для окружности.
public:
    Circle(double x_radius, double v_p) : radius(x_radius), P(v_p = 3.14) {} //для окружности мы не юзаем "Пи окружности"
    void area() override
    {
        setlocale(LC_ALL, "rus");
        cout << "Площадь круга равна: " << 3.14 * (radius * radius) << endl; //1 радиус это грубо говоря половина окружности, благодаря (radius * radius) мы грубо говоря получим диаметр окружности.
    }
};

class Rectangle : protected Parallelogram //ребенок Parallelogram'а
{
public:
    Rectangle(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        setlocale(LC_ALL, "rus");
        cout << "Площадь прямоугольника: " << base * height << endl;
    }
};

class Square : protected Parallelogram //ребенок Parallelogram'а
{
public:
    Square(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        setlocale(LC_ALL, "rus");
        cout << "Площадь квадрата составляет: " << base * height << endl;
    }
};

class Rhombus : protected Parallelogram //ребенок Parallelogram'а
{
public:
    Rhombus(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        setlocale(LC_ALL, "rus");
        cout << "Площадь ромба: " << base * height << endl;
    }
};

    /* DZ2
    Создать класс Car (автомобиль) с полями company (компания) и model (модель).
    Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
    От этих классов наследует класс Minivan (минивэн).
    Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
    Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
    Обратить внимание на проблему «алмаз смерти».
    */

class Car
{
protected:
    string company, model; //поля для класса. стринг дает возможность писать большим колл-вом строк, а не с 1 символом.
public:
    Car() {}
    Car(string xCompany, string vModel) : company(xCompany), model(vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    virtual ~Car()
    {
        cout << "\nДеструктор базового класса Car сработал!";  //деструктор базового класса.
    }
};

class PassengerCar : virtual public Car
{
public:

    PassengerCar() {}
    PassengerCar(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~PassengerCar()
    {
        cout << "\nДеструктор наследника PassengerCar сработал!"; //деструктор наследника.
    }
};

class Bus : virtual public Car
{
public:
    Bus() {}
    Bus(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~Bus()
    {
        cout << "\nДеструктор наследника Bus сработал!"; //деструктор наследника.
    }
};

class Minivan : public PassengerCar, public Bus //делаем сразу двойное присвоение.
{
public:
    Minivan(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    ~Minivan()
    {
        cout << "Деструктор множественного наследника Minivan сработал!"; //деструктор множественного наследования.
    }
};

    /* DZ3
    Создать класс: Fraction (дробь).
    Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
    Предусмотреть, чтобы знаменатель не был равен 0.
    Перегрузить:
    1.математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
    2.унарный оператор (-)
    3.логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
    */

class Fraction
{
protected:
    double numerator, denominator; //перевод: numerator(числитесь), denominator(знаменатель).
public:
    Fraction() {}
    Fraction(double iNumerator, double iDenominator) : numerator(iNumerator), denominator(iDenominator)
    {
        if (denominator == 0) denominator = 0.00000001; //предусмотреть, чтобы знаменатель не был равен 0, поэтому делаем условие.
    }
    friend Fraction operator+(const Fraction& d1, const Fraction& d2); //176 строка: математические бинарные операторы (+, -, *, /) для выполнения действий с дробями.
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1); //сам себя загоянешь в минус. 177 строка 2."унарный оператор (-)".

    double getNumerator() //необходимы в данном случае для сравнения (bool), через дружественные перегрузки ничего не работает, без гет'а.
    {
        return numerator;
    }

    double getDenominator()
    {
        return denominator;
    }

    void Print()
    {
        setlocale(LC_ALL, "rus");

        cout << "Числитель:" << numerator << " Знаменатель:" << denominator << endl;
    }

};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
    return Fraction(-d1.numerator, d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
    else return false;
}

bool operator!=(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if (d1 == d2) return false;
    else return true;
}

bool operator<(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator>(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator<=(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if (!(d1 > d2)) return true;
    else return false;
}

bool operator>=(Fraction& d1, Fraction& d2) //178 строка: логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
{
    if (!(d1 < d2)) return true;
    else return false;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    //===================================================[DZ1]===================================================//
	{
        DZ1();
        double x_base;
        double v_height;
        cout << "Параллелограмм\n" << "Введено первое значение: ";
        cin >> x_base;
        cout << "Введено второе значение: ";
        cin >> v_height;
        Parallelogram paral(x_base, v_height);
        paral.area();

        delimiterDZ();

        double x_radius;
        double P = 3.1415;
        cout << "Круг\n" << "введенный радиус : ";
        cin >> x_radius;
        Circle circ(x_radius, P);
        circ.area();

        delimiterDZ();
        
        cout << "Прямоугольник\n" << "введено первое значение: ";
        cin >> x_base;
        cout << "введено второе значение: ";
        cin >> v_height;
        Rectangle rect(x_base, v_height);
        rect.area();

        delimiterDZ();
        
        cout << "Квадрат\n" << "введено первое значение: ";
        cin >> x_base;
        cout << "введено второе значение: ";
        cin >> v_height;
        Square squar(x_base, v_height);
        squar.area();

        delimiterDZ();
        
        cout << "Ромб\n" << "введено первое значение: ";
        cin >> x_base;
        cout << "введено второе значение: ";
        cin >> v_height;
        Rhombus romb(x_base, v_height);
        romb.area();
	}
    //===================================================[DZ2]===================================================//
	{
        DZ2();

        Car* car = new Car("Doodge", "Demon");

        delimiterDZ();

        PassengerCar* passengercar = new PassengerCar("laFerrari", "Pick");

        delimiterDZ();

        Bus* bus = new Bus("Renault", "Bus");

        delimiterDZ();

        Minivan* minivan = new Minivan("Audi", "eTron");

        delimiterDZ();

        delete minivan;
        delete bus;
        delete passengercar;
        delete car;
	}
    //===================================================[DZ3]===================================================//
	{
        DZ3();

        Fraction d1(2, 8);
        Fraction d2(5, 9);
        (d1 + d2).Print();
        (d1 - d2).Print();
        (d1 * d2).Print();
        (d1 / d2).Print();
        (-d1).Print();

        delimiterDZ();

        if (d1 == d2) cout << "Дробная часть 1 == Дробная часть 2\n";
        if (d1 != d2) cout << "Дробная часть 1 != Дробная часть 2\n";
        if (d1 > d2) cout << "Дробная часть 1 > Дробная часть 2\n";
        if (d1 <= d2) cout << "Дробная часть 1 <= Дробная часть 2\n";
        if (d1 < d2) cout << "Дробная часть 1 < Дробная часть 2\n";
        if (d1 >= d2) cout << "Дробная часть 1 >= Дробная часть 2\n";

        END();
	}
    //===================================================[END]===================================================//
    return 0;
}