//
/*

Copyright 2026 JATIN AGGARWAL

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies
or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

// print_vector function, which can be used with any structure that has an array variable
// usage: std::cout << delim(vector_to_print, delim);     // delim is of const char* type (c-style strings)

#ifndef INTRIN__INTRIN_PRINT_H
#define INTRIN__INTRIN_PRINT_H
#include <iostream>
#include <iterator>

template <typename T>
void print_vector(std::ostream& out_stream, const T& type_object, const char* delim) {
    out_stream << "| "; //start of the print
    bool start = true;

    for (const auto& element: type_object.data) {
        if (!start) {out_stream << delim;}
        out_stream << element;
        start = false;
    }

    out_stream << " |"; //end of the print
}

template <typename T>
auto operator<<(std::ostream& out_stream, const T& type_object) -> decltype(std::begin(type_object.data), out_stream) {
    print_vector(out_stream, type_object, ", "); //standard delimiter is comma symbol ","
    return out_stream;
}

template <typename T>
struct DelimiterWrapper {
    const T& type_object;
    const char* delimiter;
};

template <typename T>
DelimiterWrapper<T> delim(const T& type_object, const char* delimiter) {
    return {type_object, delimiter};
}

template <typename T>
std::ostream& operator<<(std::ostream& output_stream, const DelimiterWrapper<T>& temp) {
    print_vector(output_stream, temp.type_object, temp.delimiter);
    return output_stream;
}

#endif //INTRIN__INTRIN_PRINT_H