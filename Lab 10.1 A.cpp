
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

// Perelik spetsialnostei
enum Spetsialnist
{
    KompiuterniNauky,
    Informatyka,
    MatematykaEkonomika,
    FizykaInformatyka,
    TrudoveNavchannia
};

// Struktura studenta
struct Student
{
    string prizvyshche;
    int kurs;
    Spetsialnist spetsialnist;
    int fizyka;
    int matematyka;
    int informatyka;
};

// Vvedennia danykh studentiv
void Create(Student* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Prizvyshche: ";
        getline(cin >> ws, p[i].prizvyshche);

        cout << "Kurs: ";
        cin >> p[i].kurs;

        int vybir;

        cout << "Spetsialnist:\n";
        cout << "0 - Kompiuterni nauky\n";
        cout << "1 - Informatyka\n";
        cout << "2 - Matematyka ta ekonomika\n";
        cout << "3 - Fizyka ta informatyka\n";
        cout << "4 - Trudove navchannia\n";
        cout << "Vybir: ";
        cin >> vybir;

        while (vybir < 0 || vybir > 4)
        {
            cout << "Nepravylnyi vybir. Vvedit shche raz: ";
            cin >> vybir;
        }

        p[i].spetsialnist = static_cast<Spetsialnist>(vybir);

        cout << "Otsinka z fizyky: ";
        cin >> p[i].fizyka;

        cout << "Otsinka z matematyky: ";
        cin >> p[i].matematyka;

        cout << "Otsinka z informatyky: ";
        cin >> p[i].informatyka;
    }
}

// Vyvedennia tablytsi studentiv
void Print(Student* p, const int N)
{
    string nazvySpetsialnostei[] =
    {
        "Kompiuterni nauky",
        "Informatyka",
        "Matematyka ta ekonomika",
        "Fizyka ta informatyka",
        "Trudove navchannia"
    };

    cout << "\nINFORMATSIIA PRO STUDENTIV\n";

    cout << left
        << setw(5) << "No."
        << setw(20) << "Prizvyshche"
        << setw(10) << "Kurs"
        << setw(28) << "Spetsialnist"
        << setw(10) << "Fizyka"
        << setw(15) << "Matematyka"
        << setw(12) << "Informatyka" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << left
            << setw(5) << i + 1
            << setw(20) << p[i].prizvyshche
            << setw(10) << p[i].kurs
            << setw(28) << nazvySpetsialnostei[p[i].spetsialnist]
            << setw(10) << p[i].fizyka
            << setw(15) << p[i].matematyka
            << setw(12) << p[i].informatyka << endl;
    }
}

// Pidrakhunok otsinok 5 z kozhnoho predmetа
void CountExcellent(Student* p, const int N,
    int& fiz, int& mat, int& inf)
{
    fiz = 0;
    mat = 0;
    inf = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5)
            fiz++;

        if (p[i].matematyka == 5)
            mat++;

        if (p[i].informatyka == 5)
            inf++;
    }
}

// Pidrakhunok studentiv, yaki otrymaly 5 z fizyky ta matematyky
int CountFivePhysicsMath(Student* p, const int N)
{
    int kilkist = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5 && p[i].matematyka == 5)
            kilkist++;
    }

    return kilkist;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;

    cout << "Vvedit kilkist studentiv: ";
    cin >> N;

    if (N <= 0)
    {
        cout << "Nepravylna kilkist studentiv!" << endl;
        return 1;
    }

    Student* p = new Student[N];

    Create(p, N);

    Print(p, N);

    int fiz, mat, inf;

    CountExcellent(p, N, fiz, mat, inf);

    cout << "\nKilkist otsinok 5 z fizyky: " << fiz << endl;
    cout << "Kilkist otsinok 5 z matematyky: " << mat << endl;
    cout << "Kilkist otsinok 5 z informatyky: " << inf << endl;

    int rezultat = CountFivePhysicsMath(p, N);

    cout << "Studentiv z otsinkamy 5 z fizyky ta matematyky: "
        << rezultat << endl;

    delete[] p;

    return 0;
}

