#pragma once
#include <cmath>
#include <iostream>

struct Vector3f {
    float x;
    float y;
    float z;
};



Vector3f operator+(const Vector3f& a, const Vector3f& b) {
    Vector3f result = {a.x + b.x, a.y + b.y, a.z+b.z};
    return result;
}

Vector3f operator-(const Vector3f& a, const Vector3f& b) {
    Vector3f result = {a.x - b.x, a.y - b.y, a.z-b.z};
    return result;
}

float operator*(const Vector3f& a, const Vector3f& b) {
    float result = a.x * b.x + a.y * b.y + a.z;
    return result;
}

Vector3f& operator+=(Vector3f &a, const Vector3f &b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

Vector3f& operator-=(Vector3f &a, const Vector3f &b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

Vector3f operator+(const Vector3f& a) {
    Vector3f result = a;
    return result;
}


 Vector3f operator-(const Vector3f& a) {
    Vector3f result;
    result.x = -a.x;
    result.y = -a.y;
    return result;
}


Vector3f operator*(const Vector3f& a, float b) {
    Vector3f result = a;
    result.x *= b;
    result.y *= b;
    result.z *= b;
    return result;
}


Vector3f operator*(float b,const Vector3f& a) {
    Vector3f result = a;
    result.x *= b;
    result.y *= b;
    result.z *= b;
    return result;
}


Vector3f operator/(const Vector3f& a, float b) {
    Vector3f result = a;
    result.x /= b;
    result.y /= b;
    result.z /= b;
    return result;
}
Vector3f& operator*=(Vector3f &a, float b) {
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

Vector3f& operator/=(Vector3f &a, float b) {
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return a;
}

bool operator==(const Vector3f& a, const Vector3f& b) {
    if (a.x!=b.x || a.y!=b.y || a.z!=b.z)
        return false;
    else
        return true;
}

bool operator!=(const Vector3f& a, const Vector3f& b) {
    if (a.x!=b.x || a.y!=b.y || a.z!=b.z)
        return true;
    else
        return false;
}




std::ostream& operator<<(std::ostream& out, const Vector3f& a) {
    out << a.x << " " << a.y << " " << a.z;
    return out;
}

std::istream& operator>>(std::istream& in, Vector3f& c) {
    in >> c.x >> c.y >> c.z;
    return in;
}

float squared_norm(const Vector3f& a) {
    return a.x*a.x+a.y*a.y+a.z*a.z;
}

float norm(const Vector3f& a) {
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

void normalize(Vector3f& a) {
    a/=norm(a);
}
