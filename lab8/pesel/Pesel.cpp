//
// Created by karol on 4/27/17.
//

#include <vector>
#include "Pesel.h"

academia::Pesel::Pesel(std::string pesel) {
    ValidatePesel(pesel);
    pesel_ = pesel;
}

bool Checksum(std::string pesel) {
    int a = 0;
    std::vector<int> multipliers = {9, 7, 3, 1};
    for(int i = 0; i < 10; i++) {
        a += multipliers[i % 4] * (pesel[i] - 48);
    }
    if(a % 10 != pesel[10] - 48)
        return false;
    else
        return true;
}

void academia::Pesel::ValidatePesel(std::string pesel) {
    if(pesel.size() != 11)
        throw InvalidPeselLength();
    for(auto n : pesel){
        if(!isdigit(n))
            throw InvalidPeselCharacter();
    }
    if(!Checksum(pesel))
        throw InvalidPeselChecksum();
}

academia::AcademiaDataValidationError::AcademiaDataValidationError(const std::string &err) : runtime_error(err) {

}

academia::InvalidPeselChecksum::InvalidPeselChecksum()
        : AcademiaDataValidationError("Invalid checksum") {

}

academia::InvalidPeselChecksum::InvalidPeselChecksum(std::string pesel, int checksum)
        : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: " + std::to_string(checksum)) {

}

academia::InvalidPeselLength::InvalidPeselLength()
        : AcademiaDataValidationError("Invalid length") {

}

academia::InvalidPeselLength::InvalidPeselLength(std::string pesel, int length)
        : AcademiaDataValidationError("Invalid PESEL(" + pesel +") length: " + std::to_string(length)) {

}

academia::InvalidPeselCharacter::InvalidPeselCharacter()
        : AcademiaDataValidationError("Invalid character") {

}

academia::InvalidPeselCharacter::InvalidPeselCharacter(std::string pesel)
        : AcademiaDataValidationError("Invalid PESEL(" + pesel +") character set") {

}




