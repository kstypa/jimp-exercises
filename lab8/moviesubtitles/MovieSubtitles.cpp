//
// Created by karol on 5/8/17.
//

#include <vector>
#include <iomanip>
#include "MovieSubtitles.h"

namespace moviesubs {

    void GetMicroDVDLinesFromStream(std::stringstream *in, std::vector<std::string> &lines) {
        std::string input = in->str();
        std::string CurrentLine;
        int LineCount = 1;
        for(auto n : input) {
            if(n == '\n')
                LineCount++;
        }
        lines.push_back("");
        for(int i = 0; i < LineCount; i++) {
            std::getline(*in, CurrentLine);
            lines.push_back(CurrentLine);
            CurrentLine = "";
        }
    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int ms, int fps, std::stringstream *in, std::stringstream *out) const {
        if(fps <= 0)
            throw(std::invalid_argument("fps"));
        int FrameTime = 1000 / fps;
        int shift = ms / FrameTime;
        std::vector<std::string> lines;
        GetMicroDVDLinesFromStream(in, lines);
        int start = 0, stop = 0, lbracecount = 0, rbracecount = 0;
        size_t startleft = 0, startright = 0, stopleft = 0, stopright = 0;
        std::string text, startstr, stopstr;
        for(size_t j = 1; j < lines.size(); j++) {
            if(lines[j] == "")
                continue;
            for(size_t i = 0; i < lines[j].size(); i++) {
                if(lines[j][i] == '{') {
                    lbracecount++;
                    if(lbracecount == 1)
                        startleft = i;
                    else if(lbracecount == 2)
                        stopleft = i;
                }
                else if(lines[j][i] == '}') {
                    rbracecount++;
                    if(rbracecount == 1)
                        startright = i;
                    else if(rbracecount == 2)
                        stopright = i;
                }
            }

            if((lbracecount < 2 || rbracecount < 2) && lbracecount != rbracecount)
                throw(InvalidSubtitleLineFormat());

            startstr = lines[j].substr(startleft+1, startright-startleft-1);
            stopstr = lines[j].substr(stopleft+1, stopright-stopleft-1);

            if(startstr == "" || stopstr == "")
                throw(InvalidSubtitleLineFormat());

            for(auto n : startstr){
                if(!std::isdigit(n))
                    throw(InvalidSubtitleLineFormat());
            }

            for(auto n : stopstr){
                if(!std::isdigit(n))
                    throw(InvalidSubtitleLineFormat());
            }

            start = std::stoi(startstr);
            stop = std::stoi(stopstr);
            text = lines[j].substr(stopright+1, lines[j].size());

            if(start > stop)
                throw(SubtitleEndBeforeStart(j, lines[j]));

            start += shift;
            stop += shift;

            if(start < 0 || stop < 0)
                throw(NegativeFrameAfterShift());

            lbracecount = 0;
            rbracecount = 0;

            lines[j] = "{" + std::to_string(start) + "}{" + std::to_string(stop) + "}" + text;
            *out << lines[j] << "\n";
        }
    }

    void GetSubRipLinesFromStream(std::stringstream *in, std::vector<std::string> &lines) {
        std::string input = in->str();
        std::string CurrentLine;
        std::stringstream ss;
        std::vector<int> InnerCounts;
        InnerCounts.push_back(0);
        int LineCount = 1, inner = 0;
        for(size_t j = 1; j < input.size(); j++) {
            if((input[j] == '\n' && input[j-1] == '\n')) {
                InnerCounts.push_back(inner);
                inner = 0;
                LineCount++;
            }
            else if(input[j] == '\n' && j == input.size()-1) {
                inner++;
                InnerCounts.push_back(inner);
                inner = 0;
                LineCount++;
            }
            else if(input[j] == '\n' && input[j-1] != '\n')
                inner++;
            else if(input[j] != '\n' && input[j-1] != '\n')
                continue;
        }
        for(int i = 0; i < LineCount; i++) {
            for(size_t k = 0; k < InnerCounts[i]; k++) {
                std::getline(*in, CurrentLine);
                if(CurrentLine.size() == 0)
                    std::getline(*in, CurrentLine);
                ss << CurrentLine << "\n";
                CurrentLine = "";
            }
            lines.push_back(ss.str());
            ss.str(std::string());
        }
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int ms, int fps, std::stringstream *in, std::stringstream *out) const {
        if(fps <= 0)
            throw(std::invalid_argument("fps"));
        std::vector<std::string> lines;
        GetSubRipLinesFromStream(in, lines);
        int LineNumber = 0, NewLineCount = 0, hours = 0, minutes = 0, seconds = 0, milliseconds = 0,
                hours2 = 0, minutes2 = 0, seconds2 = 0, milliseconds2 = 0, overflow = 0;
        std::string time, text;
        std::stringstream ss, timess;
        std::vector<size_t> NewLinePos;
        for(size_t i = 0; i < lines.size(); i++) {
            if(lines[i] == "")
                continue;
            for(size_t j = 0; j < lines[i].size(); j++) {
                if(lines[i][j] == '\n') {
                    NewLineCount++;
                    NewLinePos.push_back(j);
                }
            }
            LineNumber = std::stoi(lines[i].substr(0, NewLinePos[0]));
            if(LineNumber != i)
                throw(OutOfOrderFrames());
            time = lines[i].substr(NewLinePos[0] + 1, NewLinePos[1] - NewLinePos[0] - 1);
            text = lines[i].substr(NewLinePos[1] + 1, lines[i].size());
            // hh:mm:ss,xxx --> hh:mm:ss,xxx
            // 01234567890123456789012345678
            // 0         1         2
            hours = std::stoi(time.substr(0, 2));
            minutes = std::stoi(time.substr(3, 2));
            seconds = std::stoi(time.substr(6, 2));
            milliseconds = std::stoi(time.substr(9, 3));
            hours2 = std::stoi(time.substr(17, 2));
            minutes2 = std::stoi(time.substr(20, 2));
            seconds2 = std::stoi(time.substr(23, 2));
            milliseconds2 = std::stoi(time.substr(26, 3));

            milliseconds += ms;
            if(milliseconds > 999) {
                overflow = milliseconds / 1000;
                milliseconds %= 1000;
                seconds += overflow;
                if(seconds > 60) {
                    overflow = seconds / 60;
                    seconds %= 60;
                    minutes += overflow;
                    if(minutes > 60) {
                        overflow = minutes / 60;
                        minutes %= 60;
                        hours += overflow;
                    }
                }
            }
            milliseconds2 += ms;
            if(milliseconds2 > 999) {
                overflow = milliseconds2 / 1000;
                milliseconds2 %= 1000;
                seconds2 += overflow;
                if(seconds2 > 60) {
                    overflow = seconds2 / 60;
                    seconds2 %= 60;
                    minutes2 += overflow;
                    if(minutes2 > 60) {
                        overflow = minutes2 / 60;
                        minutes2 %= 60;
                        hours2 += overflow;
                    }
                }
            }
            timess << std::setfill('0') << std::setw(2) << hours << ":" << std::setfill('0') << std::setw(2) << minutes
                   << ":" << std::setfill('0') << std::setw(2) << seconds << "," << std::setfill('0') << std::setw(3) << milliseconds
                   << " --> " << std::setfill('0') << std::setw(2) << hours2 << ":" << std::setfill('0') << std::setw(2) << minutes2
                   << ":" << std::setfill('0') << std::setw(2) << seconds2 << "," << std::setfill('0') << std::setw(3) << milliseconds2;
            time = timess.str();
            timess.str(std::string());

            ss << LineNumber << "\n" << time << "\n" << text;
            lines[i] = ss.str();
            ss.str(std::string());
            *out << lines[i] << "\n";
        }
    }

    NegativeFrameAfterShift::NegativeFrameAfterShift() : runtime_error("Negative frame after shift") {

    }

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(size_t index, std::string line)
            : index_(index), runtime_error("At line " + std::to_string(index) + ": " + line) {

    }

    size_t SubtitleEndBeforeStart::LineAt() const {
        return index_;
    }

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() : runtime_error("Invalid subtitle line format") {

    }

    MissingTimeSpecification::MissingTimeSpecification() : runtime_error("Missing time specification") {

    }

    OutOfOrderFrames::OutOfOrderFrames() : runtime_error("Out of order frames") {

    }
}