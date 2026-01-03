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

//
/*
The general purpose library for using
intrinsic functions in an easy-to-use
format. Uses AVX2, AVX512F instructions as defined
by Intel Corp.

Used for fast computations in biomedical
or digital signal processing applications.
Is usable only on Intel x86 processors, as
the intrinsics are applicable to only Intel
family of processors after Core i3 4th generation.

Will be supported in newer Intel processors.

LANGUAGE:   CPP (C++17 and above)
The version can be changed in the CMakeLists.txt to C++ version as per user's preference
*/
//

#ifndef INTRIN_INTRIN_GENERIC_H
#define INTRIN_INTRIN_GENERIC_H

#include <immintrin.h>
#include "intrin_print.h" //houses the auto-detect print for any array or structure having an array

// #pragma GCC target("axv512f")

/////////////////////// ONLY INTEGERS - int32 and int64 (int and long long)

// Custom datatype for using 4 integers,  aligned at 16 byte boundary
// use 4 integers (int) only
struct alignas(16) int_4_array_a16 {
    int data[4];
    int& operator[](const int index) {
        return data[index];
    }
    const int& operator[](const int index) const {
        return data[index];
    }

    operator __m128i() const {
        return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
    }

    operator __m128i*() {
        return reinterpret_cast<__m128i*>(data);
    }

    operator const __m128i*() const {
    return reinterpret_cast<const __m128i*>(data);}

    int_4_array_a16& operator=(const __m128i vec) {
        _mm_store_si128(reinterpret_cast<__m128i*>(data), vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    int_4_array_a16 operator+(const int_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128i>(*this);
        const auto vec_B = static_cast<__m128i>(other);

        const __m128i vec_res = _mm_add_epi32(vec_A, vec_B);

        int_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    int_4_array_a16 operator-(const int_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128i>(*this);
        const auto vec_B = static_cast<__m128i>(other);

        const __m128i vec_res = _mm_sub_epi32(vec_A, vec_B);

        int_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    int_4_array_a16 operator*(const int_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128i>(*this);
        const auto vec_B = static_cast<__m128i>(other);

        const __m128i vec_res = _mm_mullo_epi32(vec_A, vec_B);

        int_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

};

// Custom datatype for using 2 long integers,  aligned at 16 byte boundary
// use 2 long integers only
struct alignas(16) long_2_array_a16 {
    long long int data[2];

    long long int& operator[](const int index) {
        return data[index];
    }
    const long long int& operator[](const int index) const {
        return data[index];
    }

    operator __m128i() const {
        return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
    }

    operator __m128i*() {
        return reinterpret_cast<__m128i*>(data);
    }

    operator const __m128i*() {
        return reinterpret_cast<const __m128i*>(data);}

    long_2_array_a16& operator=(const __m128i vec) {
        _mm_store_si128(reinterpret_cast<__m128i*>(data), vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    long_2_array_a16 operator+(const long_2_array_a16& other) const {
        const auto vec_A = static_cast<__m128i>(*this);
        const auto vec_B = static_cast<__m128i>(other);

        const __m128i vec_res = _mm_add_epi32(vec_A, vec_B);

        long_2_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    int_4_array_a16 operator-(const int_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128i>(*this);
        const auto vec_B = static_cast<__m128i>(other);

        const __m128i vec_res = _mm_sub_epi32(vec_A, vec_B);

        int_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    long_2_array_a16 operator*(const long_2_array_a16& other) const {
        const auto vec_A = static_cast<__m128i>(*this);
        const auto vec_B = static_cast<__m128i>(other);

        const __m128i vec_res = _mm_mullo_epi32(vec_A, vec_B);

        long_2_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 8 integers,  aligned at 32 byte boundary
// Use 8 integers (int) only.
struct alignas(32) int_8_array_a32 {
    int data[8];

    int& operator[](const int index) {
        return data[index];
    }

    const int& operator[](const int index) const {
        return data[index];
    }

    operator __m256i() const {
        return _mm256_load_si256(reinterpret_cast<const __m256i*>(data));
    }

    operator __m256i*() {
        return reinterpret_cast<__m256i*>(data);
    }

    operator const __m256i*() {
    return reinterpret_cast<const __m256i*>(data);}

    int_8_array_a32& operator=(const __m256i vec) {
        _mm256_store_si256(reinterpret_cast<__m256i*>(data), vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    int_8_array_a32 operator+(const int_8_array_a32& other) const {
        const auto vec_A = static_cast<__m256i>(*this);
        const auto vec_B = static_cast<__m256i>(other);

        const __m256i vec_res = _mm256_add_epi32(vec_A, vec_B);

        int_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    int_8_array_a32 operator-(const int_8_array_a32& other) const {
        const auto vec_A = static_cast<__m256i>(*this);
        const auto vec_B = static_cast<__m256i>(other);

        const __m256i vec_res = _mm256_sub_epi32(vec_A, vec_B);

        int_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    int_8_array_a32 operator*(const int_8_array_a32& other) const {
        const auto vec_A = static_cast<__m256i>(*this);
        const auto vec_B = static_cast<__m256i>(other);

        const __m256i vec_res = _mm256_mullo_epi32(vec_A, vec_B);

        int_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 4 long integers,  aligned at 32  byte boundary
// use 4 long integers only
struct alignas(32) long_4_array_a32 {
    long long int data[4];
    long long int& operator[](const int index) {
        return data[index];
    }
    const long long int& operator[](const int index) const {
        return data[index];
    }

    operator __m256i() const {
        return _mm256_load_si256(reinterpret_cast<const __m256i*>(data));
    }

    operator __m256i*() {
        return reinterpret_cast<__m256i*>(data);
    }

    operator const __m256i*() {
    return reinterpret_cast<const __m256i*>(data);}

    long_4_array_a32& operator=(const __m256i vec) {
        _mm256_store_si256(reinterpret_cast<__m256i*>(data), vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    long_4_array_a32 operator+(const long_4_array_a32& other) const {
        const auto vec_A = static_cast<__m256i>(*this);
        const auto vec_B = static_cast<__m256i>(other);

        const __m256i vec_res = _mm256_add_epi32(vec_A, vec_B);

        long_4_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    long_4_array_a32 operator-(const long_4_array_a32& other) const {
        const auto vec_A = static_cast<__m256i>(*this);
        const auto vec_B = static_cast<__m256i>(other);

        const __m256i vec_res = _mm256_sub_epi32(vec_A, vec_B);

        long_4_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    long_4_array_a32 operator*(const long_4_array_a32& other) const {
        const auto vec_A = static_cast<__m256i>(*this);
        const auto vec_B = static_cast<__m256i>(other);

        const __m256i vec_res = _mm256_mullo_epi32(vec_A, vec_B);

        long_4_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 16 integers,  aligned at 32  byte boundary
// Use 16 integers (int) only.
struct alignas(32) int_16_array_a32 {
    int data[16];
    int& operator[](const int index) {
        return data[index];
    }
    const int& operator[](const int index) const {
        return data[index];
    }

    operator __m512i*() {
        return reinterpret_cast<__m512i*>(data);
    }

    operator __m512i() const {
        return _mm512_load_si512(data);
    }

    operator const __m512i*() {
    return reinterpret_cast<const __m512i*>(data);}

    operator void const *() {
    return reinterpret_cast<__m512i*>(data);}

    int_16_array_a32& operator=(const __m512i vec) {
        _mm512_store_si512(reinterpret_cast<__m512i*>(data), vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    int_16_array_a32 operator+(const int_16_array_a32& other) const {
        const auto vec_A = static_cast<__m512i>(*this);
        const auto vec_B = static_cast<__m512i>(other);

        const __m512i vec_res = _mm512_add_epi64(vec_A, vec_B);

        int_16_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    int_16_array_a32 operator-(const int_16_array_a32& other) const {
        const auto vec_A = static_cast<__m512i>(*this);
        const auto vec_B = static_cast<__m512i>(other);

        const __m512i vec_res = _mm512_sub_epi64(vec_A, vec_B);

        int_16_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    int_16_array_a32 operator*(const int_16_array_a32& other) const {
        const auto vec_A = static_cast<__m512i>(*this);
        const auto vec_B = static_cast<__m512i>(other);

        const __m512i vec_res = _mm512_mullo_epi64(vec_A, vec_B);

        int_16_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 8 long integers,  aligned at 32  byte boundary
// use 8 long integers only
struct alignas(32) long_8_array_a32 {
    long long int data[8];
    long long int& operator[](const int index) {
        return data[index];
    }
    const long long int& operator[](const int index) const {
        return data[index];
    }

    operator __m512i*() {
        return reinterpret_cast<__m512i*>(data);
    }

    operator __m512i() const {
        return _mm512_load_si512(data);
    }

    operator const __m512i*() {
    return reinterpret_cast<const __m512i*>(data);}

    operator void const *() {
        return reinterpret_cast<__m512i*>(data);}

    long_8_array_a32& operator=(const __m512i vec) {
        _mm512_store_si512(reinterpret_cast<__m512i*>(data), vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    long_8_array_a32 operator+(const long_8_array_a32& other) const {
        const auto vec_A = static_cast<__m512i>(*this);
        const auto vec_B = static_cast<__m512i>(other);

        const __m512i vec_res = _mm512_add_epi64(vec_A, vec_B);

        long_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    long_8_array_a32 operator-(const long_8_array_a32& other) const {
        const auto vec_A = static_cast<__m512i>(*this);
        const auto vec_B = static_cast<__m512i>(other);

        const __m512i vec_res = _mm512_sub_epi64(vec_A, vec_B);

        long_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    long_8_array_a32 operator*(const long_8_array_a32& other) const {
        const auto vec_A = static_cast<__m512i>(*this);
        const auto vec_B = static_cast<__m512i>(other);

        const __m512i vec_res = _mm512_mullo_epi64(vec_A, vec_B);

        long_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////
///
///
/////////////////////// ONLY FLOATING-POINT - float32 and float64 (float and double)

// Custom datatype for using 4 floats,  aligned at 16  byte boundary
// use 4 float only
struct alignas(16) float_4_array_a16 {
    float data[4];
    float& operator[](const int index) {
        return data[index];
    }
    const float& operator[](const int index) const {
        return data[index];
    }

    operator __m128() const {
        return _mm_load_ps(data);
    }

    operator __m128*() {
        return reinterpret_cast<__m128*>(data);
    }

    operator const __m128*() {
    return reinterpret_cast<const __m128*>(data);}

    operator float const*() const { return data; }

    float_4_array_a16& operator=(const __m128 vec) {
        _mm_store_ps(data, vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    float_4_array_a16 operator+(const float_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128>(*this);
        const auto vec_B = static_cast<__m128>(other);

        const __m128 vec_res = _mm_add_ps(vec_A, vec_B);

        float_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    float_4_array_a16 operator-(const float_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128>(*this);
        const auto vec_B = static_cast<__m128>(other);

        const __m128 vec_res = _mm_sub_ps(vec_A, vec_B);

        float_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    float_4_array_a16 operator*(const float_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128>(*this);
        const auto vec_B = static_cast<__m128>(other);

        const __m128 vec_res = _mm_mul_ps(vec_A, vec_B);

        float_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // DIVISION OPERATOR OVERLOADED (MATCHES TYPES)
    float_4_array_a16 operator/(const float_4_array_a16& other) const {
        const auto vec_A = static_cast<__m128>(*this);
        const auto vec_B = static_cast<__m128>(other);

        const __m128 vec_res = _mm_div_ps(vec_A, vec_B);

        float_4_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 2 doubles,  aligned at 16  byte boundary
// use 2 double only
struct alignas(16) double_2_array_a16 {
    double data[4];
    double& operator[](const int index) {
        return data[index];
    }
    const double& operator[](const int index) const {
        return data[index];
    }

    operator __m128d() const {
        return _mm_load_pd(data);
    }

    operator __m128d*() {
        return reinterpret_cast<__m128d*>(data);
    }

    operator const __m128d*() {
    return reinterpret_cast<const __m128d*>(data);}

    operator double const*() { return data; }

    double_2_array_a16& operator=(const __m128d vec) {
        _mm_store_pd(data, vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    double_2_array_a16 operator+(const double_2_array_a16& other) const {
        const auto vec_A = static_cast<__m128d>(*this);
        const auto vec_B = static_cast<__m128d>(other);

        const __m128d vec_res = _mm_add_pd(vec_A, vec_B);

        double_2_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    double_2_array_a16 operator-(const double_2_array_a16& other) const {
        const auto vec_A = static_cast<__m128d>(*this);
        const auto vec_B = static_cast<__m128d>(other);

        const __m128d vec_res = _mm_sub_pd(vec_A, vec_B);

        double_2_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    double_2_array_a16 operator*(const double_2_array_a16& other) const {
        const auto vec_A = static_cast<__m128d>(*this);
        const auto vec_B = static_cast<__m128d>(other);

        const __m128d vec_res = _mm_mul_pd(vec_A, vec_B);

        double_2_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // DIVISION OPERATOR OVERLOADED (MATCHES TYPES)
    double_2_array_a16 operator/(const double_2_array_a16& other) const {
        const auto vec_A = static_cast<__m128d>(*this);
        const auto vec_B = static_cast<__m128d>(other);

        const __m128d vec_res = _mm_div_pd(vec_A, vec_B);

        double_2_array_a16 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 8 floats,  aligned at 32  byte boundary
// Use 8 float only.
struct alignas(32) float_8_array_a32 {
    float data[8];
    float& operator[](const int index) {
        return data[index];
    }
    const float& operator[](const int index) const {
        return data[index];
    }

    operator __m256() const {
        return _mm256_load_ps(data);
    }

    operator __m256*() {
        return reinterpret_cast<__m256*>(data);
    }

    operator const __m256*() {
    return reinterpret_cast<const __m256*>(data);}

    operator float const*() { return data; }

    float_8_array_a32& operator=(const __m256 vec) {
        _mm256_store_ps(data, vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    float_8_array_a32 operator+(const float_8_array_a32& other) const {
        const auto vec_A = static_cast<__m256>(*this);
        const auto vec_B = static_cast<__m256>(other);

        const __m256 vec_res = _mm256_add_ps(vec_A, vec_B);

        float_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    float_8_array_a32 operator-(const float_8_array_a32& other) const {
        const auto vec_A = static_cast<__m256>(*this);
        const auto vec_B = static_cast<__m256>(other);

        const __m256 vec_res = _mm256_sub_ps(vec_A, vec_B);

        float_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    float_8_array_a32 operator*(const float_8_array_a32& other) const {
        const auto vec_A = static_cast<__m256>(*this);
        const auto vec_B = static_cast<__m256>(other);

        const __m256 vec_res = _mm256_mul_ps(vec_A, vec_B);

        float_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // DIVISION OPERATOR OVERLOADED (MATCHES TYPES)
    float_8_array_a32 operator/(const float_8_array_a32& other) const {
        const auto vec_A = static_cast<__m256>(*this);
        const auto vec_B = static_cast<__m256>(other);

        const __m256 vec_res = _mm256_div_ps(vec_A, vec_B);

        float_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 4 doubles,  aligned at 32  byte boundary
// use 4 double only
struct alignas(32) double_4_array_a32 {
    double data[8];
    double& operator[](const int index) {
        return data[index];
    }
    const double& operator[](const int index) const {
        return data[index];
    }

    operator __m256d() const {
        return _mm256_load_pd(data);
    }

    operator __m256d*() {
        return reinterpret_cast<__m256d*>(data);
    }

    operator const __m256d*() {
    return reinterpret_cast<const __m256d*>(data);}

    operator double const*() { return data; }

    double_4_array_a32& operator=(const __m256d vec) {
        _mm256_store_pd(data, vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    double_4_array_a32 operator+(const double_4_array_a32& other) const {
        const auto vec_A = static_cast<__m256d>(*this);
        const auto vec_B = static_cast<__m256d>(other);

        const __m256d vec_res = _mm256_add_pd(vec_A, vec_B);

        double_4_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    double_4_array_a32 operator-(const double_4_array_a32& other) const {
        const auto vec_A = static_cast<__m256d>(*this);
        const auto vec_B = static_cast<__m256d>(other);

        const __m256d vec_res = _mm256_sub_pd(vec_A, vec_B);

        double_4_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    double_4_array_a32 operator*(const double_4_array_a32& other) const {
        const auto vec_A = static_cast<__m256d>(*this);
        const auto vec_B = static_cast<__m256d>(other);

        const __m256d vec_res = _mm256_mul_pd(vec_A, vec_B);

        double_4_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // DIVISION OPERATOR OVERLOADED (MATCHES TYPES)
    double_4_array_a32 operator/(const double_4_array_a32& other) const {
        const auto vec_A = static_cast<__m256d>(*this);
        const auto vec_B = static_cast<__m256d>(other);

        const __m256d vec_res = _mm256_div_pd(vec_A, vec_B);

        double_4_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

};

// Custom datatype for using 16 floats,  aligned at 32  byte boundary
// Use 16 float only.
struct alignas(32) float_16_array_a32 {
    float data[16];
    float& operator[](const int index) {
        return data[index];
    }
    const float& operator[](const int index) const {
        return data[index];
    }

    operator __m512() const {
        return _mm512_load_ps(data);
    }

    operator __m512*() {
        return reinterpret_cast<__m512*>(data);
    }

    operator const __m512*() {
    return reinterpret_cast<const __m512*>(data);}

    operator float const*() { return data; }

    operator void const *() {
        return reinterpret_cast<__m512*>(data);}

    float_16_array_a32& operator=(const __m512 vec) {
        _mm512_store_ps(data, vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    float_16_array_a32 operator+(const float_16_array_a32& other) const {
        const auto vec_A = static_cast<__m512>(*this);
        const auto vec_B = static_cast<__m512>(other);

        const __m512 vec_res = _mm512_add_ps(vec_A, vec_B);

        float_16_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    float_16_array_a32 operator-(const float_16_array_a32& other) const {
        const auto vec_A = static_cast<__m512>(*this);
        const auto vec_B = static_cast<__m512>(other);

        const __m512 vec_res = _mm512_sub_ps(vec_A, vec_B);

        float_16_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    float_16_array_a32 operator*(const float_16_array_a32& other) const {
        const auto vec_A = static_cast<__m512>(*this);
        const auto vec_B = static_cast<__m512>(other);

        const __m512 vec_res = _mm512_mul_ps(vec_A, vec_B);

        float_16_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // DIVISION OPERATOR OVERLOADED (MATCHES TYPES)
    float_16_array_a32 operator/(const float_16_array_a32& other) const {
        const auto vec_A = static_cast<__m512>(*this);
        const auto vec_B = static_cast<__m512>(other);

        const __m512 vec_res = _mm512_div_ps(vec_A, vec_B);

        float_16_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

// Custom datatype for using 8 doubles,  aligned at 32  byte boundary
// use 8 double only
struct alignas(32) double_8_array_a32 {
    double data[8];
    double& operator[](const int index) {
        return data[index];
    }
    const double& operator[](const int index) const {
        return data[index];
    }

    operator __m512d() const {
        return _mm512_load_pd(data);
    }

    operator __m512d*() {
        return reinterpret_cast<__m512d*>(data);
    }

    operator const __m512d*() {
    return reinterpret_cast<const __m512d*>(data);}

    operator double const*() { return data; }

    operator void const *() {
        return reinterpret_cast<__m512d*>(data);}

    double_8_array_a32& operator=(const __m512d vec) {
        _mm512_store_pd(data, vec);
        return *this;
    }

    // ADDITION OPERATOR OVERLOADED (MATCHES TYPES)
    double_8_array_a32 operator+(const double_8_array_a32& other) const {
        const auto vec_A = static_cast<__m512d>(*this);
        const auto vec_B = static_cast<__m512d>(other);

        const __m512d vec_res = _mm512_add_pd(vec_A, vec_B);

        double_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // SUBTRACTION OPERATOR OVERLOADED (MATCHES TYPES)
    double_8_array_a32 operator-(const double_8_array_a32& other) const {
        const auto vec_A = static_cast<__m512d>(*this);
        const auto vec_B = static_cast<__m512d>(other);

        const __m512d vec_res = _mm512_sub_pd(vec_A, vec_B);

        double_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // MULTIPLICATION OPERATOR OVERLOADED (MATCHES TYPES)
    double_8_array_a32 operator*(const double_8_array_a32& other) const {
        const auto vec_A = static_cast<__m512d>(*this);
        const auto vec_B = static_cast<__m512d>(other);

        const __m512d vec_res = _mm512_mul_pd(vec_A, vec_B);

        double_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }

    // DIVISION OPERATOR OVERLOADED (MATCHES TYPES)
    double_8_array_a32 operator/(const double_8_array_a32& other) const {
        const auto vec_A = static_cast<__m512d>(*this);
        const auto vec_B = static_cast<__m512d>(other);

        const __m512d vec_res = _mm512_div_pd(vec_A, vec_B);

        double_8_array_a32 res {};
        res = vec_res; // valid due to overloaded operator=
        return res;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

#endif //INTRIN_INTRIN_GENERIC_H