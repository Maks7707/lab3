#include <iostream>
#include <cmath>
using namespace std;

//If11. Дано дві змінні цілого типу: A і B. Якщо їх значення не рівні,
//то присвоїти кожній змінній більше з цих значень, а якщо рівні, 
//то присвоїти змінним нульові значення.
//Вивести нові значення змінних A і B.
void task_if11 (); // завдання 1 декларація функції

// Дано координати точки на площині (x, y).
// Визначити, чи потрапляє точка в фігуру заданого кольору (або групу фігур)
// і вивести відповідне повідомлення
void task_geom30 (); //завдання 2 декларація функції 

int main() {
      int menu;
      cout << "Task number:";
      cin >> menu;
      // перемикання між завданнями 
      switch (menu)
      {
          case 1: task_if11 (); break; // Завдання 1 
          case 2: task_geom30 (); break; // Завдання 2 
          default: cout << "Wrong task! (Only 1,2)" << endl; // повідомлення про помилку
      }
      return 0;
}

// завдання 1 реалізація
void task_if11 ()
{
      int A, B;
      cout << " If11 " << endl;
      cout << " Введіть значення змінної A: ";
      cin >> A;
      
      if (cin.fail()) {
          cout << "Некоректні дані!";
          return;
      }
    
      cout << "Введіть значення змінної B: ";
      cin >> B;
      
      if (cin.fail()) {
          cout << "Некоректні дані!";
          return;
      }      
         if (A == B) {
             cout << "Змінні рівні!";
              A = 0;
              B = 0;
          } 
          else {
          
             A<B ? A=B : B=A; 
             cout << "Змінні відрізняються!";
          }
          
          cout << "A = " << A << "B = " << B <<  endl;
     
          return;  
}

// завдання 2 реалізація
void task_geom30 () {
    double r;  // радіус
    double x, y; // координати точки
    cout << " Geom30 " << endl;
    cout << " Введіть радіус кола: ";
    cin >> r;
    if (cin.fail() || r <= 0) {
        cout << "Некоректне значення радіусу! ";
        return;
    }
    cout << "Введіть координати x, y: ";
    cin >> x >> y;
    if (!cin) {
        cout << "Задано не числові дані! ";
        return;
    }
    float eps = 1e-9;
    
    bool at_upper_right = (-r < x && x <= 0) && (0 < y && y <= r);
    double dist2 = pow(x + r, 2) + pow(y, 2);
    bool outside_circle = dist2 > pow(r, 2) + eps;
    
    bool in_triangle = false;
    {
        double Ax = -2 * r, Ay = 0;
        double Bx = -r, By = 0;
        double Cx = -r, Cy = -r;
        
        double v0x = Bx - Ax, v0y = By - Ay;
        double v1x = Cx - Ax, v1y = Cy - Ay;
        double v2x = x - Ax, v2y = y - Ay;
        double det = v0x * v1y - v1x * v0y;
        
        if(abs(det) > eps) {
            double u = (v2x * v1y - v1x * v2y) / det;
            double v = (v0x * v2y - v2x * v0y) / det;
            in_triangle = (u >= -eps) && (v >= -eps) && (u + v <= 1 + eps);
        }
    }
    
    if (in_triangle)
       cout << "Точка належить області 30 (нижня фігура, світло-зелений колір)";
    else if (at_upper_right && outside_circle)
       cout << "Точка належить області 30 (верхня фігура, світло-зелений колір)";
    else {
        cout << "Задана точка не знаходиться на фігурі!";
    }
    
    return;
}