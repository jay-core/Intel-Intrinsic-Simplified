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
#include "intrin_generic.h"
#include <iostream>
using std::cout;
int main() {

    const float_8_array_a32 vec_a = {123.2, 1233.5, 77.3, 99.23, 555.7, 456.7, 765.3, 4512.12};
    const float_8_array_a32 vec_b = {123.2, 1233.5, 77.3, 99.23, 555.7, 456.7, 765.3, 4512.12};

    float_8_array_a32 result = vec_a * vec_b;

    std::cout << delim(result, ", ");
    return 0;
}