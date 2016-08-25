//
// Created by pedja on 25.8.16..
//

#ifndef TS_HTTP_CPP_HTTPUTILS_H
#define TS_HTTP_CPP_HTTPUTILS_H

#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>

class HttpUtils
{
private:
    HttpUtils();
public:
    static std::string encodeString(const std::string &value)
    {
        std::ostringstream escaped;
        escaped.fill('0');
        escaped << std::hex;

        for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
            std::string::value_type c = (*i);

            // Keep alphanumeric and other accepted characters intact
            if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
                escaped << c;
                continue;
            }

            // Any other characters are percent-encoded
            escaped << std::uppercase;
            escaped << '%' << std::setw(2) << int((unsigned char) c);
            escaped << std::nouppercase;
        }

        return escaped.str();
    }
};


#endif //TS_HTTP_CPP_HTTPUTILS_H
