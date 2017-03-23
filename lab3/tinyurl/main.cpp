//
// Created by karol on 3/22/17.
//

#include <iostream>
#include "TinyUrl.h"

using namespace tinyurl;

int main(){
    auto codec = Init();
    auto ai_shortened = Encode("http://ai.ia.agh.edu.pl/wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2", &codec);
    auto ai_full = Decode(codec, ai_shortened);
    auto ref_shortened = Encode("http://en.cppreference.com/w/cpp/string/basic_string", &codec);
    auto ref_full = Decode(codec, ref_shortened);
    std::cout << "Hash: " << ai_shortened << std::endl;
    std::cout << "Full link: " << ai_full << std::endl;
    std::cout << "Hash: " << ref_shortened << std::endl;
    std::cout << "Full link: " << ref_full << std::endl;

    return 0;
}