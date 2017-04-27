//
// Created by karol on 4/27/17.
//

#include <iostream>
#include "Point.h"
#include "Point3D.h"

using ::std::cout;
using ::std::endl;

int main() {
//    Point3D a(3,4,5);

//    5. Najpierw wykonuje się konstruktor bazowej klasy Point, a dopiero potem klasy Point3D.
//       Obiekt klasy bazowej musi zostać utworzony jako pierwszy, aby można było na jego podstawie zbudować obiekt klasy pochodnej.
//       Gdy obiekty są niszczone na końcu programu, pierwszy zostaje wywołany destruktor klasy pochodnej,
//       usuwając "zewnętrzną warstwę" obiektu, a dopiero później niszczona jest "podstawa", czyli obiekt klasy bazowej.


//    Point punkt2d(1,2);
//    Point3D punkt3d(5,1,3);
//    cout << "punkt2d.Distance(punkt3d) = " << punkt2d.Distance(punkt3d) << endl;


//    6. Funkcja punkt2d.Distance(punkt3d) policzyła odległość między punktami tak, jakby oba miały jedynie dwie współrzędne.
//       Stało się tak, ponieważ w definicji funkcji Point::Distance są brane pod uwagę tylko współrzędne x i y punktów.
//       Obiekt klasy Point3D jako dziedziczący po klasie bazowej Point posiada współrzędne x i y.
//       W tym wypadku jego własna współrzędna z zostaje zignorowana.


//    Point3D p3d(1,2,3);
//    cout << p3d << endl;

//    7. Podobnie jak w poprzednim przypadku wypisanie zadziałało jak dla punktu 2D.
//       Powodem tego jest definicja przeciążonego operatora w klasie bazowej, która obsługuje tylko współrzędne x i y.
//       Dodatkowa współrzędna z punktu 3D zostałą zignorowana.

    return 0;
}