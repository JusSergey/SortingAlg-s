#include <QCoreApplication>
#include <iostream>
using std::cout;


template <typename T>
void print_data(T *array, size_t len) {
    while (len--) cout << *(array++) << ' ';
    cout << '\n';
    cout.flush();
}

template <typename T>
void sortInserting(T *array, size_t len) {

    size_t i, j;
    T key;

    for (j = 1; j < len; j++) {
        key = array[j];
        i = j-1;

        while ((i >= 0) && (array[i] > key))
            array[i+1] = array[i--];

        array[i+1] = key;
        print_data(array, len);
    }

}

template <typename T>
void sortMy(T *array, size_t len) {

#include <map>
using std::map;

    map<T, size_t> resultMap;

    size_t i, j;

    for (i = 0; i < len; i++)
        resultMap[array[i]]++;

    for (auto iter : resultMap)
        for (j = 0; j < iter.second; j++)
            *array++ = iter.first;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int array[] = {9, 5, 1, 3, 0, 0, 0, 8, 2, 4};

    size_t size = sizeof(array) / sizeof(array[0]);

    print_data(array, size);

    sortInserting(array, size);
    sortMy(array, size);
    print_data(array, size);
    return a.exec();
}
