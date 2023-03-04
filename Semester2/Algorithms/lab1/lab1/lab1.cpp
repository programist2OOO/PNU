#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <thread>
using namespace std;

int n;
int** arr;
void initArray() {
    arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
}
void immun(int x, int y) {
    if (arr[x][y] < 10) {
        arr[x][y]++;
    }
    if (arr[x][y] == 10) {
        arr[x][y] = 0;
    }


}
void infect(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 0) {

        if (rand() % 2 == 0) {
            arr[x][y] = 1;
        }
    }
}
void display(int** a) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO start_attribute;
    GetConsoleScreenBufferInfo(handle, &start_attribute);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
                cout << a[i][j] << " ";
            }
            else if (a[i][j] > 0 && a[i][j] < 6)
            {
                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                cout << a[i][j] << " ";
            }
            else if (a[i][j] > 5 && a[i][j] < 10)
            {
                SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
                cout << a[i][j] << " ";
            }

        }
        cout << endl;
    }

    cout << endl;
    SetConsoleTextAttribute(handle, start_attribute.wAttributes);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(0));

    cout << "¬вед≥ть розм≥р робочого пол€ (nxn): ";
    cin >> n;;
    initArray();

    int x, y;
    cout << "¬вед≥ть початкову к≥льк≥сть заражених кл≥тин: ";
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x = 0, y = 0;
        cout << "¬вед≥ть координати " << i + 1 << " точки(x y): " << endl;
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        arr[x][y] = 1;
    }
    cout << "¬вед≥ть к≥льк≥сть дн≥в роботи в≥русу: ";
    int day;
    cin >> day;
    system("cls");
    cout << "ѕочаткове заражене поле:" << endl;
    display(arr);
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
    for (int k = 0; k < day; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > 0) {
                    immun(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > 1 && arr[i][j] < 6) {
                    infect(i - 1, j);
                    infect(i + 1, j);
                    infect(i, j - 1);
                    infect(i, j + 1);
                }

            }
        }
        system("cls");
        cout << "ƒень " << k + 1 << ":" << endl;
        display(arr);
        this_thread::sleep_for(chrono::seconds(1));


    }
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;

}


