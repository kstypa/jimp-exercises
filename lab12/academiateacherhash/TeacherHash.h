//
// Created by karol on 6/6/17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia {

    class TeacherId {
    public:
        TeacherId(int id_);

        operator int() const;

        bool operator==(const TeacherId &rhs) const;

        bool operator!=(const TeacherId &rhs) const;

    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher(const TeacherId &id_, const std::string &name_, const std::string &department_);

        TeacherId Id() const;
        std::string Name() const;
        std::string Department() const;

        bool operator==(const Teacher &rhs) const;

        bool operator!=(const Teacher &rhs) const;

    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    };

    class TeacherHash {
    public:
        TeacherHash();

        size_t operator()(const Teacher &t) const;
    };

}


#endif //JIMP_EXERCISES_TEACHERHASH_H
