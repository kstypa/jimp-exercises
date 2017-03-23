//
// Created by karol on 3/22/17.
//

#include "TinyUrl.h"
using ::std::unique_ptr;
using ::std::array;
using ::std::string;

namespace tinyurl {
    unique_ptr<TinyUrlCodec> Init(){
        auto codec = std::make_unique<TinyUrlCodec>();
        codec->state.fill('0');
        return codec;
    }

    string DecToBase62(int64_t dec){
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        string base62 = "";
        while(dec > 0){
            base62 = digits[dec % 62] + base62;
            dec /= 62;
        }
        return base62;
    }

    int64_t Base62ToDec(const string &base62){
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int64_t dec = 0;
        int idx = 0;
        for(auto ch : base62){
            dec += digits.find(ch) * pow(62, base62.size() - (idx + 1));
            idx++;
        }
        return dec;
    }

    void NextHash(array<char, 6> *state){
        int64_t MaxValue = 56800235583;
        string OldState(state->begin(), state->end());
        int64_t StateInt = Base62ToDec(OldState);
        StateInt++;
        if(StateInt > MaxValue)
            StateInt = 0;
        string NewState = DecToBase62(StateInt);
        while(NewState.size() < 6)
            NewState = "0" + NewState;
        for (size_t i = 0; i < 6; i++)
            state->at(i) = NewState[i];
    }

    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec){
        auto &c = *codec;
        string hash(c->state.begin(), c->state.end());
        c->url.emplace(hash, url);
        NextHash(&c->state);
        return hash;
    }

    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash){
        string url;
        auto search = codec->url.find(hash);
        if(search != codec->url.end())
            url = search->second;
        return url;
    }
}