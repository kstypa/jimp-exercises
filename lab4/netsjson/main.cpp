//
// Created by karol on 3/29/17.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

int main() {
/*
    vector<JsonValue> js {JsonValue{56.6},JsonValue{45},JsonValue{"abc"s}};
    map<string, JsonValue> obj_v {{"values",JsonValue{js}},{"name",JsonValue{"Test name"s}},{"age",JsonValue{13}}};
    JsonValue obj {obj_v};
    // {"age": 13, "name": "Test name", "values": [56.6, 45, "abc"]} kolejność argumentów nie ma znaczenia w przypadku obiektu

    cout << obj.ToString() << endl;
    cout << "name: " << obj.ValueByName("name")->ToString() << endl;
    cout << "values: " << obj.ValueByName("values")->ToString() << endl;
    cout << "age: " << obj.ValueByName("age")->ToString() << endl;
    //obiekty optional można traktować jak wartości boolean (true wartość obecna, false optional jest pusty)
    if (obj.ValueByName("xyz")) {
        cout << "is present" << endl;
    } else {
        cout << "is absent" << endl;
    }

    map<string, JsonValue> obmap {{"name", JsonValue{"abc"s}}, {"value", JsonValue{420}}};
    JsonValue ob {obmap};
    cout << "name: " << ob.ValueByName("name")->ToString() << endl;
    cout << "value: " << ob.ValueByName("value")->ToString() << endl;
*/
    map<string, JsonValue> object{{"name", {"Maciej"s}}, {"age", {44}}, {"account_balance", {-107.89}}};
    JsonValue simple_object_value{object};
    string obj_str = simple_object_value.ToString();
    cout << obj_str << endl;

    return 0;
}