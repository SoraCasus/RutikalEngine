#include "Vec3.h"

#include <cmath>
#ifdef R3D_OS_WINDOWS
#	include <xmmintrin.h>
#endif
#include "MathUtils.h"

namespace R3D {

	Vec3::Vec3() :
		_x(0.0F), _y(0.0F), _z(0.0F), _padding(0) {}

	Vec3::Vec3(R3Dfloat scalar) :
		_x(scalar), _y(scalar), _z(scalar), _padding(0) {}

	Vec3::Vec3(R3Dfloat x, R3Dfloat y, R3Dfloat z) :
		_x(x), _y(y), _z(z), _padding(0) {}

	Vec3::Vec3(const Vec3& other) :
		_x(other._x), _y(other._y), _z(other._z), _padding(0) {}

	Vec3::Vec3(const Vec3& pointA, const Vec3& pointB) {
		this->_x = pointB._x - pointA._x;
		this->_y = pointB._y - pointA._y;
		this->_z = pointB._z - pointA._z;
		this->_padding = 0;
	}

#ifdef R3D_OS_WINDOWS
	Vec3::Vec3(__m128 simd) {
		LoadSimd(simd);
	}
#endif

	Vec3& Vec3::Add(const Vec3& other) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = GetSimd();
		__m128 b = other.GetSimd();

		__m128 res = _mm_add_ps(a, b);

		LoadSimd(res);

		return *this;
	#else
		this->_x += other._x;
		this->_y += other._y;
		this->_z += other._z;

		return *this;
	#endif
	}

	Vec3 Vec3::Add(const Vec3& left, const Vec3& right) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = left.GetSimd();
		__m128 b = right.GetSimd();

		__m128 res = _mm_add_ps(a, b);

		return Vec3(res);
	#else
		Vec3 res;

		res._x = left._x + right._x;
		res._y = left._y + right._y;
		res._z = left._z + right._z;

		return res;
	#endif
	}

	Vec3& Vec3::Add(R3Dfloat scalar) {
	#ifdef R3D_OS_WINDOWS
		R3D::Vec3 other(scalar);

		return Add(other);
	#else
		this->_x += scalar;
		this->_y += scalar;
		this->_z += scalar;

		return *this;
	#endif
	}

	Vec3 Vec3::Add(const Vec3& left, R3Dfloat right) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = left.GetSimd();
		__m128 b = Vec3(right).GetSimd();

		__m128 res = _mm_add_ps(a, b);

		return Vec3(res);
	#else
		Vec3 res;

		res._x = left._x + right;
		res._y = left._y + right;
		res._z = left._z + right;

		return res;
	#endif
	}

	Vec3 Vec3::Add(R3Dfloat left, const Vec3& right) {
		return Add(right, left);
	}

	Vec3& Vec3::Sub(const Vec3& other) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = GetSimd();
		__m128 b = other.GetSimd();

		__m128 res = _mm_sub_ps(a, b);

		LoadSimd(res);

		return *this;
	#else
		this->_x -= other._x;
		this->_y -= other._y;
		this->_z -= other._z;

		return *this;
	#endif
	}

	Vec3 Vec3::Sub(const Vec3& left, const Vec3& right) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = left.GetSimd();
		__m128 b = right.GetSimd();

		__m128 res = _mm_sub_ps(a, b);

		return Vec3(res);
	#else
		Vec3 res;

		res._x = left._x - right._x;
		res._y = left._y - right._y;
		res._z = left._z - right._z;

		return res;
	#endif
	}

	Vec3& Vec3::Sub(R3Dfloat scalar) {
	#ifdef R3D_OS_WINDOWS
		return Sub(Vec3(scalar));
	#else
		this->_x -= scalar;
		this->_y -= scalar;
		this->_z -= scalar;

		return *this;
	#endif
	}

	Vec3 Vec3::Sub(const Vec3& left, R3Dfloat right) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = left.GetSimd();
		__m128 b = Vec3(right).GetSimd();

		__m128 res = _mm_sub_ps(a, b);

		return Vec3(res);
	#else
		Vec3 res;

		res._x = left._x - right;
		res._y = left._y - right;
		res._z = left._z - right;

		return res;
	#endif
	}

	Vec3 Vec3::Sub(R3Dfloat left, const Vec3& right) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = Vec3(left).GetSimd();
		__m128 b = right.GetSimd();

		__m128 res = _mm_sub_ps(a, b);

		return Vec3(res);
	#else
		Vec3 res;

		res._x = left - right._x;
		res._y = left - right._y;
		res._z = left - right._z;

		return res;
	#endif
	}

	Vec3& Vec3::Mul(const Vec3& other) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = GetSimd();
		__m128 b = other.GetSimd();

		__m128 res = _mm_mul_ps(a, b);
		LoadSimd(res);

		return *this;
	#else
		this->_x *= other._x;
		this->_y *= other._y;
		this->_z *= other._z;

		return *this;
	#endif
	}

	Vec3 Vec3::Mul(const Vec3& left, const Vec3& right) {
	#ifdef R3D_OS_WINDOWS
		__m128 a = left.GetSimd();
		__m128 b = right.GetSimd();

		__m128 res = _mm_mul_ps(a, b);

		return Vec3(res);
	#else
		Vec3 res;

		res._x = left._x * right._x;
		res._y = left._y * right._y;
		res._z = left._z * right._z;

		return res;
	#endif
	}

	Vec3& Vec3::Mul(R3Dfloat scalar) {
		return Mul(Vec3(scalar));
	}

	Vec3 Vec3::Mul(const Vec3& left, R3Dfloat right) {
		return Mul(left, Vec3(right));
	}

	Vec3 Vec3::Mul(R3Dfloat left, const Vec3& right) {
		return Mul(Vec3(left), right);
	}

	R3Dfloat Vec3::LengthSq() const {
		return _x * _x + _y * _y + _z * _z;
	}

	R3Dfloat Vec3::Length() const {
		return sqrt(LengthSq());
	}

	R3Dfloat Vec3::LengthSq(const Vec3& vec) {
		return vec._x * vec._x + vec._y * vec._y + vec._z * vec._z;
	}

	R3Dfloat Vec3::Length(const Vec3& vec) {
		return sqrt(LengthSq(vec));
	}

	R3Dfloat Vec3::Magnitude() const {
		return Length();
	}

	R3Dfloat Vec3::Magnitude(const Vec3& vec) {
		return Length(vec);
	}

	Vec3& Vec3::Normalize() {
	#ifdef R3D_OS_WINDOWS
		Vec3 length(Length());
	
		__m128 a = GetSimd();
		__m128 b = length.GetSimd();

		__m128 res = _mm_div_ps(a, b);
		LoadSimd(res);

		return *this;
	#else
		R3Dfloat length = Length();
		this->_x /= length;
		this->_y /= length;
		this->_z /= length;

		return *this;
	#endif
	}

	Vec3 Vec3::Normal() const {
	#ifdef R3D_OS_WINDOWS
		Vec3 length(Length());

		__m128 a = GetSimd();
		__m128 b = length.GetSimd();
		__m128 res = _mm_div_ps(a, b);

		return Vec3(res);
	#else
		Vec3 res;

		R3Dfloat length = Length();

		res._x = this->_x / length;
		res._y = this->_y / length;
		res._z = this->_z / length;

		return res;
	#endif
	}

	Vec3& Vec3::Normalize(Vec3& vec) {
		return vec.Normalize();
	}

	Vec3 Vec3::Normal(const Vec3& vec) {
		return vec.Normal();
	}

	Vec3 Vec3::Cross(const Vec3& vec) {
		R3Dfloat x = GetX();
		R3Dfloat y = GetY();
		R3Dfloat z = GetZ();

		this->_x = y * vec._z - z * vec._y;
		this->_y = z * vec._x - x * vec._z;
		this->_z = x * vec._y - y * vec._x;

		return *this;
	}

	Vec3 Vec3::Cross(const Vec3& left, const Vec3& right) {
		Vec3 res = left;

		return res.Cross(right);
	}

	R3Dfloat Vec3::Dot(const Vec3& vec) const {
		return _x * vec._x + _y * vec._y + _z * vec._z;
	}

	R3Dfloat Vec3::Dot(const Vec3& left, const Vec3& right) {
		return left._x * right._x + left._y * right._y + left._z * right._z;
	}

	R3Dfloat Vec3::Angle(const Vec3& vec) const {
		R3Dfloat dot = Dot(vec);
		R3Dfloat dividend = Length() * vec.Length();

		return acos(dot / dividend);
	}

	R3Dfloat Vec3::Angle(const Vec3& vecA, const Vec3& vecB) {
		R3Dfloat dot = Dot(vecA, vecB);
		R3Dfloat dividend = Length(vecA) * Length(vecB);

		return acos(dot / dividend);
	}

	Vec3 Vec3::Lerp(const Vec3& vecA, const Vec3& vecB, R3Dfloat beta) {
		beta = Math::Max(Math::Min(1.0F, beta), 0.0F);

		R3Dfloat invBeta = 1.0F - beta;

		Vec3 a = Mul(vecA, invBeta);
		Vec3 b = Mul(vecB, beta);

		return Add(a, b);
	}

	Vec3 operator+(Vec3 left, const Vec3& right) {
		return left.Add(right);
	}

	Vec3 operator-(Vec3 left, const Vec3& right) {
		return left.Sub(right);
	}

	Vec3 operator*(Vec3 left, const Vec3& right) {
		return left.Mul(right);
	}

	Vec3 operator+(Vec3 left, R3Dfloat right) {
		return left.Add(right);
	}

	Vec3 operator-(Vec3 left, R3Dfloat right) {
		return left.Sub(right);
	}

	Vec3 operator*(Vec3 left, R3Dfloat right) {
		return left.Mul(right);
	}

	bool Vec3::operator==(const Vec3& other) const {
		return _x == other._x && _y == other._y && _z == other._z;
	}

	bool Vec3::operator!=(const Vec3& other) const {
		return !(*this == other);
	}

	Vec3& Vec3::operator+=(const Vec3& other) {
		return Add(other);
	}

	Vec3& Vec3::operator+=(R3Dfloat other) {
		return Add(other);
	}

	Vec3& Vec3::operator-=(const Vec3& other) {
		return Sub(other);
	}

	Vec3& Vec3::operator-=(R3Dfloat other) {
		return Sub(other);
	}

	Vec3& Vec3::operator*=(const Vec3& other) {
		return Mul(other);
	}

	Vec3& Vec3::operator*=(R3Dfloat other) {
		return Mul(other);
	}

	bool Vec3::operator<(const Vec3& other) const {
		return LengthSq() < other.LengthSq();
	}

	bool Vec3::operator<=(const Vec3& other) const {
		return LengthSq() <= other.LengthSq();
	}

	bool Vec3::operator>(const Vec3& other) const {
		return LengthSq() > other.LengthSq();
	}

	bool Vec3::operator>=(const Vec3& other) const {
		return LengthSq() >= other.LengthSq();
	}

	std::ostream& operator<<(std::ostream& stream, const Vec3& vec) {
		stream << vec.ToString();
		return stream;
	}

}
