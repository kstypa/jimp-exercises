//
// Created by karol on 4/27/17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

namespace academia {
    class Pesel {
    public:
        Pesel(std::string pesel);

        void ValidatePesel(std::string pesel);

    private:
        std::string pesel_;
    };

    class AcademiaDataValidationError : public std::runtime_error {
    public:
        AcademiaDataValidationError(const std::string &err);
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum();
        InvalidPeselChecksum(std::string pesel, int checksum);
    };

    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength();
        InvalidPeselLength(std::string pesel, int length);
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter();
        InvalidPeselCharacter(std::string pesel);
    };
}



#endif //JIMP_EXERCISES_PESEL_H
