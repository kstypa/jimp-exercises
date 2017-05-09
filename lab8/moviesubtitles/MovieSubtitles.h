//
// Created by karol on 5/8/17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H


#include <sstream>
#include <vector>
#include <stdexcept>

namespace moviesubs {

    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int ms, int fps, std::stringstream *in, std::stringstream *out) const = 0;
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int ms, int fps, std::stringstream *in, std::stringstream *out) const override;
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int ms, int fps, std::stringstream *in, std::stringstream *out) const override;
    };

    class NegativeFrameAfterShift : public std::runtime_error {
    public:
        NegativeFrameAfterShift();
    };

    class SubtitleEndBeforeStart : public std::runtime_error {
    public:
        SubtitleEndBeforeStart(size_t index, std::string line);
        size_t LineAt() const;

    private:
        size_t index_;
    };

    class InvalidSubtitleLineFormat : public std::runtime_error {
    public:
        InvalidSubtitleLineFormat();
    };

    class MissingTimeSpecification : public std::runtime_error {
    public:
        MissingTimeSpecification();
    };

    class OutOfOrderFrames : public std::runtime_error {
    public:
        OutOfOrderFrames();
    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
