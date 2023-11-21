#include "settings.h"

struct AddProduct {
    string name;
    int count;
    float price_1;
    float discount;
};

struct Date {
    unsigned int day;
    unsigned int month;
    int year;
};

struct Time {
    unsigned short hour;
    unsigned short minute;
};

struct Place {
    string city;
    string region;
    string street;
    string house;
};

struct Structs {
    string shop_name;
    Place place;
    Date date;
    Time time;
    AddProduct prod;
    string card_type;
    unsigned int check_num;
    string prediction;
};

void SetCheckInfo(Structs& check) {
    check.shop_name = "Сын цветка - Спидер мужик";

    cout << "Input city: ";
    cin >> check.place.city;

    cout << "Input region: ";
    cin >> check.place.region;

    cout << "Input street: ";
    cin >> check.place.street;

    cout << "Input number of house: ";
    cin >> check.place.house;

    cout << "Input actual number of day: ";
    cin >> check.date.day;
    if (check.date.day < 0 || check.date.day > 31) {
        cout << "Inccorrect value for a grade(\n";
        throw "ERROR!!!";
    }

    cout << "Input actual number of month: ";
    cin >> check.date.month;
    if (check.date.month < 0 || check.date.month > 12) {
        cout << "Inccorrect value for a grade(\n";
        throw "ERROR!!!";
    }

    cout << "Input actual year: ";
    cin >> check.date.year;

    cout << "Input actual hours: ";
    cin >> check.time.hour;

    cout << "Input actual minutes: ";
    cin >> check.time.minute;

    cout << "Input name of product: ";
    cin >> check.prod.name;

    cout << "Input amount of product: ";
    cin >> check.prod.count;
    if (check.prod.count < 0) {
        cout << "Inccorrect value for a grade(\n";
        throw "ERROR!!!";
    }

    cout << "Input price for one product: ";
    cin >> check.prod.price_1;
    if (check.prod.price_1 < 0) {
        cout << "Inccorrect value for a grade(\n";
        throw "ERROR!!!";
    }

    cout << "Input discount for the product: ";
    cin >> check.prod.discount;
    if (check.prod.discount < 0) {
        cout << "Inccorrect value for a grade(\n";
        throw "ERROR!!!";
    }

    cout << "Input type of your card: ";
    cin >> check.card_type;

    check.check_num = rand() % 1000000;

    cout << "What prediction do you want: ";
    cin >> check.prediction;
    system("cls");
}

void PrintCheck(Structs& check) {
    cout << "                 Shop\n        " << check.shop_name << "\n\n";
    cout << check.place.city << ", " << check.place.region << " region\n" << check.place.street << " " << check.place.house << "\n";
    printf("%02d.%02d.%04d       ", check.date.day, check.date.month, check.date.year);
    printf("%02d:%02d      ", check.time.hour, check.time.minute);
    printf("Check: %06d\n", check.check_num);
    cout << "               " << check.card_type << "\n\n\n";
    cout << check.prod.name << "\n    " << check.prod.count << " * " << check.prod.price_1 << " (disc: " << check.prod.discount << "%)_____" << (check.prod.count * check.prod.price_1) - ((check.prod.count * check.prod.price_1) * check.prod.discount / 100) << "UAH\n\n\n";
    cout << check.prediction << " :)";
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    Structs check;
    SetCheckInfo(check);
    PrintCheck(check);


    Sleep(INFINITE);
}