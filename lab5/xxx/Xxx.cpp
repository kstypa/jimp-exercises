//
// Created by karol on 3/30/17.
//

#include "Xxx.h"

XXX::XXX() : name_{new char[1024]} {

}

XXX::XXX(const std::string name) {

}

//konstruktor kopiujący:
XXX::XXX(const XXX& xxx) {
    Copy(xxx);
    //Teraz nowy obiekt pokazuje na nowy fragment pamięci,
    //ale ze skopiowaną informacją
}

void XXX::Copy(const XXX &xxx) {
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_, xxx.name_);
}

//konstruktor przenoszący:
XXX::XXX(XXX &&xxx) {
    Move(std::move(xxx));
    //Bardzo popularna szutczka
    //wiemy, ze za chwilę xxx zostanie zniszczony
    //za pomocą destrukotra, więc inicjalizujemy
    //this na nullptr i wymieniamy się z xxx
    //delete nullptr jest bezpieczna operacją i nic się nie stanie...
}

void XXX::Move(XXX &&xxx) {
    name_ = nullptr;
    swap(name_, xxx.name_);
}

//operator przypisania:
XXX & XXX::operator=(const XXX& xxx) {
    //jeśli ktoś wpadł na pomysł x = x;
    if (this == &xxx) {
        return *this;
    }
    //w przyciwynym wypadku mamy x = y;
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie kopiowanie, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    Copy(xxx);
}

//operator przenoszący:
XXX & XXX::operator=(XXX &&xxx) {
    //jeśli ktoś wpadł na pomsył x = move(x);
    if (this == &xxx) {
        return xxx;
    }
    //w przyciwynym wypadku mamy x = move(y);
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie przenosimy stan, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    Move(std::move(xxx));
}

//5. destruktor:
XXX::~XXX() {
    delete [] name_;
}