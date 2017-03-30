//
// Created by karol on 3/29/17.
//

#include <sstream>
#include <iomanip>
#include "SimpleJson.h"

using ::std::string;
using ::std::vector;
using ::std::map;

namespace nets {

    JsonValue::JsonValue(){
        key_ = "";
    }

    JsonValue::JsonValue(const string &value) {
        std::stringstream ss;
        ss << std::quoted(value);
        stringvalue_ = ss.str();
        type_ = "string";
    }

    JsonValue::JsonValue(int value) {
        intvalue_ = value;
        type_ = "int";
    }

    JsonValue::JsonValue(double value) {
        doublevalue_ = value;
        type_ = "double";
    }

    JsonValue::JsonValue(bool value) {
        boolvalue_ = value;
        type_ = "bool";
    }

    JsonValue::JsonValue(const vector<JsonValue> &valuesvector) {
        valuesvector_ = valuesvector;
        type_ = "vector";
    }

    JsonValue::JsonValue(const map<string, JsonValue> &valuesmap) {
        object_ = valuesmap;
        type_ = "object";
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const string &name) const {
        if(type_ == "object"){
            auto search = object_.find(name);
            if(search != object_.end()) {
                return std::experimental::make_optional(JsonValue{search->second});
            }
        }
    }

    string JsonValue::ToString() const {
        if(type_ == "int")
            return std::to_string(intvalue_);
        else if(type_ == "string")
            return stringvalue_;
        else if(type_ == "double") {
            std::stringstream ss;
            ss << doublevalue_;
            return ss.str();
        }
        else if(type_ == "bool" && boolvalue_)
            return "true";
        else if(type_ == "bool" && !boolvalue_)
            return "false";
        else if(type_ == "vector"){
            string arrstr = "[";
            for(int i = 0; i < valuesvector_.size(); i++){
                arrstr += valuesvector_[i].ToString();
                if(i == valuesvector_.size() - 1)
                    arrstr += "]";
                else
                    arrstr += ", ";
            }
            return arrstr;
        }
        else if(type_ == "object"){
            map<string, JsonValue> mp = object_;
            string objstr = "{";
            for(map<string, JsonValue>::iterator iter = mp.begin(); iter != mp.end(); iter++){
                if(iter != mp.begin())
                    objstr += ", ";
                objstr += JsonValue{iter->first}.ToString() + ": " + JsonValue{iter->second}.ToString();
            }
            objstr += "}";
            return objstr;
        }/*
        else if(type_ == "pair"){
            string pairstr = "{" + key_ + ": " + sub_->ToString() + "}";
            return pairstr;
        }*/
        else
            return "";
    }
}