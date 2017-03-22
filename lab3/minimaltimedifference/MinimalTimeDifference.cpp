//
// Created by Student on 16/03/17.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM){
        std::regex pattern {R"((\d{1,2}):(\d{2}))"};
        std::smatch matches;
        int minutes = 0;
        if(std::regex_match(time_HH_MM, matches, pattern)){
            minutes = std::stoi(matches[1])*60 + std::stoi(matches[2]);
        }
        return minutes;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times){
        int najm = 24*60;
        std::vector<int> minutes;
        for(auto n : times){
            minutes.push_back(ToMinutes(n));
        }
        std::sort(minutes.begin(), minutes.end());
        int poprz = minutes.back() - najm;
        for(auto n : minutes){
            if (najm > n - poprz){
                najm = n - poprz;
            }
            poprz = n;
        }

        return najm;
    }
}

