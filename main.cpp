#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void fill_Progressive(std::vector<int> & tablica){
    for(int i = 0; i < tablica.size(); i++)
    {
        tablica[i] = i+1;
    }
}

void print_vector(std::vector<int> & tablica)
{
    for(int i = 0; i < tablica.size(); i++)
    {
        cout << tablica[i] << ',';
    }
}

void min_max(std::vector<int> & tablica, double minimum, double maximum)
{
    tablica = {-45,-3,-2125,422,65555,12};
    minimum = tablica[0];
    maximum = tablica[0];

    for(int i = 0; i < tablica.size(); i++)
    {
        if(tablica[i] < minimum)
        {
            minimum = tablica[i];
        }
        else if(tablica[i] > maximum)
        {
            maximum = tablica[i];
        }
    }
    cout << "MIN" << minimum << endl;
    cout << "MAX" << maximum << endl;
}

uint64_t factorial(uint64_t factorial)
{
    uint64_t temp = 1;

   for(int i = 1; i < factorial + 1; i++)
   {
        temp *= i;
   }

   factorial = temp;

   cout << factorial << endl;
   return factorial;
}

int i = 1;

uint64_t factorial_r(uint64_t n)
{
    if( n <= 1 )
    {
        return 1;
    }

    return n * factorial_r( n - 1 );
}

bool is_Prime(int number_candidate){
    for(int i = 2; i <= number_candidate / 2;i++)
    {
        if(number_candidate % i == 0){
            return false;
        }
    }
    return true;
}

void cout_prime_numbers()
{
    int start,stop;
    cin >> start;
    cin >> stop;
    for(start; start <= stop;start++){
        if(is_Prime(start)) cout << start << endl;
    }
}

double leibnitz_pi(double stop_at){
    double pi = 1;
    double denominator = 3; // mianownik ułamka
    int addOrDivideCounter = 1; 
    double fracture = 1; // cały ułamek;

    while(fracture > stop_at){
        fracture = 1/denominator;
        (addOrDivideCounter % 2 == 0) ? pi+= fracture : pi -= fracture;
        addOrDivideCounter++;
        denominator += 2;
    }

    cout <<"compiled pi => " << 4 * pi << endl;
    cout << "error approximation =>" << 4*pi - M_PI << endl;

    return pi;
}

void draw_square(int how_many, bool left_diag, bool right_diag){
    for(int i = 1; i <= how_many; i++){
        for(int j = 1; j <= how_many; j++){
            if(i == 1 || i == how_many ) cout << "#";
            else if(j == 1 || j == how_many) cout << "#";
            else if(i == j && left_diag) cout << "#";
            else if(how_many - i == j - 1 && right_diag) cout << "#";
            else cout << " ";
        }
        cout << '\n';
    }
}

int main()
{
    // int size = 0;

    // cout << "Podaj rozmiar wektora" << endl;
    // cin >> size;

    // std::vector<int> tab(size);

    // fill_Progressive(tab);
    // print_vector(tab);  
    // std::cout << "^^^^^^^^^" << endl;
    // min_max(tab, 1, 1);
    // cout << "^^^^^" << endl;
    // factorial(6);
    // cout << "^^^^^^^" << endl;
    // uint64_t wynik =1;
    // wynik = factorial_r(8);
    // cout << wynik << endl;

    // uint64_t prime_or_not_prime = 15485867;

    // if(is_Prime(prime_or_not_prime))
    // {
    //     cout << "PRIME" << endl;
    // }
    // else{
    //     cout << "NOT PRIME" << endl;
    // }

    //cout_prime_numbers();

    //leibnitz_pi(0.01);

    draw_square(4, false, false);

    return 0;
}
