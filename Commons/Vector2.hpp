//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_VECTOR2_HPP
#define DXLIBTEMPLATE_VECTOR2_HPP


class Vector2 {
public:
    float x;
    float y;

    Vector2();
    explicit Vector2(float x, float y);
    explicit Vector2(int x, int y);

    friend Vector2 operator+(const Vector2& a, const Vector2& b);
    friend Vector2 operator-(const Vector2& a, const Vector2& b);
    friend Vector2 operator*(const Vector2& a, const Vector2& b);
    friend Vector2 operator*(const Vector2& vec, float scalar);
    Vector2& operator+=(const Vector2& vec);
    Vector2& operator-=(const Vector2& vec);
    Vector2& operator*=(float scalar);

    float Length() const;
    float LengthSq() const;
    float Max() const;

    static const Vector2 Zero;
    static const Vector2 One;

};


#endif //DXLIBTEMPLATE_VECTOR2_HPP
