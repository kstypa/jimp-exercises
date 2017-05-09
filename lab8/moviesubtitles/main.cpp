//
// Created by karol on 5/8/17.
//

#include <iostream>
#include "MovieSubtitles.h"

using namespace moviesubs;

int main() {
    std::stringstream test {"line1\nline2\n"};
    std::stringstream t2;
    std::cout << test.str();

    MicroDvdSubtitles *m1 = new MicroDvdSubtitles;

    m1->ShiftAllSubtitlesBy(300, 25, &test, &t2);

    delete m1;

    return 0;
}