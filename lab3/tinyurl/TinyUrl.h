//
// Created by karol on 3/22/17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
#include <math.h>

namespace tinyurl {
    typedef struct {
        std::map<std::string, std::string> url;
        std::array<char, 6> state;
    } TinyUrlCodec;

    std::unique_ptr<TinyUrlCodec> Init();
    std::string DecToBase62(int64_t dec);
    int64_t Base62ToDec(const std::string &base62);
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}


#endif //JIMP_EXERCISES_TINYURL_H
