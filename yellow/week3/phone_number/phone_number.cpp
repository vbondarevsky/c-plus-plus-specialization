#include <sstream>
#include <exception>
#include <regex>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {

    regex re(R"(^\+(\w+)-(\w+)-([\w|-]+)$)");
    smatch matches;
    if (!regex_search(international_number, matches, re)) {
        throw invalid_argument("wrong phone number: " + international_number);
    }

    country_code_ = matches[1].str();
    city_code_ = matches[2].str();
    local_number_ = matches[3].str();
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetInternationalNumber() const {
    stringstream ss;
    ss << '+' << GetCountryCode() << '-' << GetCityCode() << '-' << GetLocalNumber();
    return ss.str();
}
