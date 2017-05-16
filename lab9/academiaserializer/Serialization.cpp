//
// Created by karol on 5/4/17.
//

#include <vector>
#include "Serialization.h"

namespace academia {

    bool comma = false;

//  ROOM

    Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    void Room::Serialize(Serializer *ser) const {
        ser->Header("room");
        ser->IntegerField("id", id_);
        comma = true;
        ser->StringField("name", name_);
        ser->StringField("type", TypeToString());
        ser->Footer("room");
        comma = false;
    }

    std::string Room::TypeToString() const {
        switch(type_) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

//  BUILDING

    Building::Building(int id_, const std::string &name_, const std::vector<std::reference_wrapper<const Serializable>> &rooms_) : id_(id_), name_(name_),
                                                                                             rooms_(rooms_) {}

    void Building::Serialize(Serializer *ser) const {
        comma = false;
        ser->Header("building");
        ser->IntegerField("id", id_);
        comma = true;
        ser->StringField("name", name_);
        ser->ArrayField("rooms", rooms_);
        ser->Footer("building");
        comma = false;
    }

//  XMLSERIALIZER

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "<" << field_name << ">";
        value.Serialize(this);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";
        for(const Serializable &n : value)
            n.Serialize(this);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

//  JSONSERIALIZER

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        if(comma)
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": " << value;
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        if(comma)
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": " << value;
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if(comma)
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        if(comma)
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": " << value;
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        if(comma)
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": ";
        value.Serialize(this);
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        if(comma)
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": [";
        comma = false;
        bool first = true;
        for(const Serializable &n : value) {
            if(!first)
                *out_ << ", ";
            n.Serialize(this);
            first = false;
        }
        *out_ << "]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }
}
