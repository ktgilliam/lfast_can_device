/*******************************************************************************
Copyright 2022
Steward Observatory Engineering & Technical Services, University of Arizona
This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.
*******************************************************************************/
///
/// @author Kevin Gilliam
/// @date February 16th, 2023
/// @file math_util.h
///
#pragma once
#include <cmath>
#include <type_traits>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#ifndef M_2_PI
#define M_2_PI 6.283185307179586476925286766559 /* pi*2 */
#endif

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923 /* pi/2 */
#endif

#ifndef M_SQRT2
#define M_SQRT2 1.4142135623730950488016887
#endif

#ifndef M_E
#define M_E 2.71828182845904523536028747135266249775724709369995
#endif

#ifndef M_SQRT2
#define M_SQRT2 1.41421356237309504880168872420969807856967187537694
#endif

constexpr double INV_PI = 1 / M_PI;     // 0.31830988618379067153776752674502
constexpr double INV_2_PI = 0.5 / M_PI; // 0.15915494309189533576888376337251
constexpr double INV_180 = 1 / 180.0;   // 0.00555555555555555555555555555556
constexpr double INV_360 = 1 / 360.0;   // 0.00277777777777777777777777777778
constexpr double INV_3600 = 1 / 3600.0; // 0.00027777777777777777777777777778
constexpr double INV_24 = 1 / 24.0;     // 0.04166666666666666666666666666666
constexpr double INV_30 = 1 / 30.0;     // 0.03333333333333333333333333333333
constexpr double INV_60 = 1 / 60.0;

#define ENABLE_IF_ARITHMETIC(v) typename std::enable_if<std::is_arithmetic<v>::value>::type * = nullptr

template <typename T, typename U, ENABLE_IF_ARITHMETIC(T), ENABLE_IF_ARITHMETIC(U)>
inline T ulim(T val, U upper)
{
    return val < upper ? val : upper;
}

template <typename T, typename U, ENABLE_IF_ARITHMETIC(T), ENABLE_IF_ARITHMETIC(U)>
inline T llim(T val, U lower)
{
    return val > lower ? val : lower;
}

template <typename T, typename U, typename V, ENABLE_IF_ARITHMETIC(T), ENABLE_IF_ARITHMETIC(U), ENABLE_IF_ARITHMETIC(V)>
inline T saturate(T val, U lower, V upper)
{
    T val1 = llim(val, lower);
    T val2 = ulim(val1, upper);

    // T val1 = val > lower ? val : lower;
    // T val2 = val1 < upper ? val1 : upper;
    return val2;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline int sign(T val)
{
    if (val == 0.0)
        return 0.0;
    else
        return std::signbit(val) ? -1 : 1;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double hrs2rad(T val)
{
    constexpr double mult = 2 * M_PI * INV_24;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double hrs2deg(T val)
{
    constexpr double mult = 360.0 * INV_24;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double rad2hrs(T val)
{
    constexpr double mult = 24.0 * INV_2_PI;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double deg2hrs(T val)
{
    constexpr double mult = 24.0 * INV_360;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double rad2deg(T val)
{
    constexpr double mult = 180.0 * INV_PI;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double deg2rad(T val)
{
    constexpr double mult = M_PI * INV_180;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double arcsec2deg(T val)
{
    return val * INV_3600;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double deg2arcsec(T val)
{
    return val * 3600.0;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double arcsec2rad(T val)
{
    constexpr double mult = INV_3600 * INV_180 * M_PI;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double rad2arcsec(T val)
{
    constexpr double mult = 3600.0 * 180.0 * INV_PI;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double radpersec2RPM(T val)
{
    constexpr double mult = 30.0 * INV_PI;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double RPM2radpersec(T val)
{
    constexpr double mult = M_PI * INV_30;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double degpersec2RPM(T val)
{
    constexpr double mult = 60 * INV_360;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double RPM2degpersec(T val)
{
    constexpr double mult = 360 * INV_60;
    return val * mult;
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double sind(T val)
{
    return rad2deg(std::sin(deg2rad(val)));
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double cosd(T val)
{
    return rad2deg(std::cos(deg2rad(val)));
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double tand(T val)
{
    return rad2deg(std::tan(deg2rad(val)));
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double asind(T val)
{
    return rad2deg(std::asin(deg2rad(val)));
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double acosd(T val)
{
    return rad2deg(std::acos(deg2rad(val)));
}

template <typename T, ENABLE_IF_ARITHMETIC(T)>
inline double atand(T val)
{
    return rad2deg(std::atan(deg2rad(val)));
}

template <typename T, typename U, ENABLE_IF_ARITHMETIC(T), ENABLE_IF_ARITHMETIC(U)>
inline double atan2d(T Y, U X)
{
    return rad2deg(std::atan2(deg2rad(Y), deg2rad(X)));
}

template <typename T, typename... Rest>
inline double sum(T t, Rest... rest)
{
    return t + sum(rest...);
}

template <typename T, class... Args>
T mean(Args... args)
{
    int numArgs = sizeof...(args);
    if (numArgs == 0)
        return T(); // If there are no arguments, just return the default value of that type

    T total{0};
    for (auto value : {args...})
        total += value;

    return total / numArgs; // Simple arithmetic average (sum divided by total)
}

template <typename T, std::size_t N, ENABLE_IF_ARITHMETIC(T)>
class vectorX
{
private:
    T e[N];

public:
    template <typename... vals>
    vectorX(vals... v)
        : e{v...}
    {
    }

    std::size_t len() { return N; }
    T operator[](size_t i) const { return e[i]; }

    T &operator[](size_t i) { return e[i]; }

    T magnitude()
    {
        T sumSquares = 0;
        for (size_t ii = 0; ii < N; ii++)
            sumSquares += e[ii] * e[ii];
        T mag = sqrt(sumSquares);
        return mag;
    }
    void normalize()
    {
        T mag = magnitude();
        if (mag > 0)
        {
            T magDiv = 1.0 / mag;
            for (size_t ii = 0; ii < N; ii++)
                e[ii] *= magDiv;
        }
    }
};

// #undef RAD_TO_DEG
// #undef DEG_TO_RAD