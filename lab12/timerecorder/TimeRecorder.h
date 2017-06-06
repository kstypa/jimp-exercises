//
// Created by karol on 6/6/17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include<utility>

namespace profiling {

    template<class T>
    std::pair<T, double> TimeRecorder(T func) {
        double StartTime = 0;
        T result = func();
        double StopTime = 0;
        return std::make_pair<T, double>(result, StopTime-StartTime);
    }

}


#endif //JIMP_EXERCISES_TIMERECORDER_H
