//
// Created by karol on 3/29/17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets {
    class JsonValue {
    public:
        JsonValue();
        JsonValue(const std::string &value);
        JsonValue(int value);
        JsonValue(double value);
        JsonValue(bool value);
        JsonValue(const std::vector<JsonValue> &valuesvector);
        JsonValue(const std::map<std::string, JsonValue> &valuesmap);
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    private:
        std::string stringvalue_;
        int intvalue_;
        double doublevalue_;
        bool boolvalue_;
        std::vector<JsonValue> valuesvector_;
        std::map<std::string, JsonValue> object_;
        std::string type_;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
