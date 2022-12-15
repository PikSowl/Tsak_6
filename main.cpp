#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void show_vector(vector<int> a)
{
    vector<int>::iterator t;
    cout << "vector:";
    for (t = a.begin(); t<a.end(); t++)
        cout << ' ' << *t;
    cout << endl;
}

int main()
{
    vector<int> numbers (10,0);

    numbers.push_back(1);
    numbers.push_back(2);
    show_vector(numbers);

    numbers.erase(numbers.begin()+4);
    cout << numbers[10] << endl; // should return 1;
    numbers.erase(numbers.begin(),numbers.begin()+8);
    show_vector(numbers);

    vector<int>::iterator at;
    at = numbers.insert (numbers.begin(), 200);
    numbers.insert (at,2,300);
    cout << numbers[0] <<  " " << numbers[2] <<  " "  <<  numbers[4] << endl; // should return 300 200 1;

    int arr [] = {31, 32, 33};
    numbers.insert (numbers.begin() + 1,arr,arr+2);
    cout << numbers[0] <<  " " << numbers[1] <<  " "  <<  numbers[2] << endl; // should return 300 31 32;
    show_vector(numbers);
    cout << endl;

    numbers.emplace_back(111);
    cout << numbers[7] << " " << numbers[8] << endl;
    cout << endl;

    numbers.resize(4);
    numbers.resize(6,100);
    numbers.resize(7);
    show_vector(numbers);

    cout << "vector's capacity: " << numbers.capacity() << endl;
    numbers.insert (numbers.begin() + 3,20, 100);
    cout << "vector's capacity: " << numbers.capacity() << endl;
    numbers.reserve(100);
    cout << "vector's capacity: " << numbers.capacity() << endl;
    show_vector(numbers);

    numbers.erase(numbers.begin()+4,numbers.end()-1);
    show_vector(numbers);
    cout << "vector's capacity: " << numbers.capacity() << endl;
    numbers.shrink_to_fit();
    cout << "vector's capacity: " << numbers.capacity() << endl;
    cout << endl;

    numbers.clear();
    numbers.push_back(11);
    numbers.push_back(13);
    show_vector(numbers);
    cout << endl;

    numbers[1] = 44;
    show_vector(numbers);

    vector<int> numbers2 {13, 14, 15, 16};
    numbers2 = numbers;
    cout << "numbers2 =";
    for (at = numbers2.begin(); at < numbers2.end(); at++)
        cout << " " << *at;
    cout << endl;

    return 0;
}
