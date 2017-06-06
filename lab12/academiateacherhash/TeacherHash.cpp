//
// Created by karol on 6/6/17.
//

#include "TeacherHash.h"
#include <functional>

namespace academia {

    Teacher::Teacher(const TeacherId &id_, const std::string &name_, const std::string &department_) : id_(id_),
                                                                                                       name_(name_),
                                                                                                       department_(
                                                                                                               department_) {}

    TeacherId Teacher::Id() const {
        return id_;
    }

    std::string Teacher::Name() const {
        return name_;
    }

    std::string Teacher::Department() const {
        return department_;
    }

    bool Teacher::operator==(const Teacher &rhs) const {
        return id_ == rhs.id_ &&
               name_ == rhs.name_ &&
               department_ == rhs.department_;
    }

    bool Teacher::operator!=(const Teacher &rhs) const {
        return !(rhs == *this);
    }

    TeacherId::TeacherId(int id_) : id_(id_) {}

    TeacherId::operator int() const {
        return id_;
    }

    bool TeacherId::operator==(const TeacherId &rhs) const {
        return id_ == rhs.id_;
    }

    bool TeacherId::operator!=(const TeacherId &rhs) const {
        return !(rhs == *this);
    }

    TeacherHash::TeacherHash() {}

    size_t TeacherHash::operator()(const Teacher &t) const {
        size_t NameHash = 0, DepartmentHash = 0;
        for(auto n : t.Name())
            NameHash += std::hash<char>()(n);
        for(auto n : t.Department())
            DepartmentHash += std::hash<char>()(n);
        return std::hash<int>()(int(t.Id())) * 3 + NameHash * 5 + DepartmentHash * 7;
    }
}