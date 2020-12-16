#include "Vec2.h"

#include <cmath>
#include "MathUtils.h"

namespace R3D {

	Vec2::Vec2() :
		_x(0.0F), _y(0.0F) {}

	Vec2::Vec2(R3Dfloat scalar) :
		_x(scalar), _y(scalar) {}

	Vec2::Vec2(R3Dfloat x, R3Dfloat y) :
		_x(x), _y(y) {}

	Vec2::Vec2(const Vec2& other) :
		_x(other._x), _y(other._y) {}

	Vec2::Vec2(const Vec2& pointA, const Vec2& pointB) {
		this->_x = pointB._x - pointA._x;
		this->_y = pointB._y - pointA._y;
	}

	Vec2& Vec2::Add(const Vec2& other) {
		this->_x += other._x;
		this->_y += other._y;

		return *this;
	}

	Vec2 Vec2::Add(const Vec2& left, const Vec2& right) {
		Vec2 res;
		
		res._x = left._x + right._x;
		res._y = left._y + right._y;

		return res;
	}

	Vec2& Vec2::Add(R3Dfloat scalar) {
		this->_x += scalar;
		this->_y += scalar;

		return *this;
	}

	Vec2 Vec2::Add(const Vec2& left, R3Dfloat right) {
		Vec2 res;

		res._x = left._x + right;
		res._y = left._y + right;

		return res;
	}

	Vec2 Vec2::Add(R3Dfloat left, const Vec2& right) {
		Vec2 res;

		res._x = left + right._x;
		res._y = left + right._y;

		return res;
	}

	Vec2& Vec2::Sub(const Vec2& other) {
		this->_x -= other._x;
		this->_y -= other._y;

		return *this;
	}

	Vec2 Vec2::Sub(const Vec2& left, const Vec2& right) {
		Vec2 res;

		res._x = left._x - right._x;
		res._y = left._y - right._y;

		return res;
	}

	Vec2& Vec2::Sub(R3Dfloat scalar) {
		this->_x -= scalar;
		this->_y -= scalar;

		return *this;
	}

	Vec2 Vec2::Sub(const Vec2& left, R3Dfloat right) {
		Vec2 res;

		res._x = left._x - right;
		res._y = left._y - right;

		return res;
	}

	Vec2 Vec2::Sub(R3Dfloat left, const Vec2& right) {
		Vec2 res;

		res._x = left - right._x;
		res._y = left - right._y;

		return res;
	}

	Vec2& Vec2::Mul(const Vec2& other) {
		this->_x *= other._x;
		this->_y *= other._y;

		return *this;
	}

	Vec2 Vec2::Mul(const Vec2& left, const Vec2& right) {
		Vec2 res;

		res._x = left._x * right._x;
		res._y = left._y * right._y;

		return res;
	}

	Vec2& Vec2::Mul(R3Dfloat scalar) {
		this->_x *= scalar;
		this->_y *= scalar;

		return *this;
	}

	Vec2 Vec2::Mul(const Vec2& left, R3Dfloat right) {
		Vec2 res;

		res._x = left._x * right;
		res._y = left._y * right;

		return res;
	}

	Vec2 Vec2::Mul(R3Dfloat left, const Vec2& right) {
		Vec2 res;

		res._x = left * right._x;
		res._y = left * right._y;

		return res;
	}

	R3Dfloat Vec2::LengthSq() const {
		return _x * _x + _y * _y;
	}

	R3Dfloat Vec2::Length() const {
		return sqrt(LengthSq());
	}

	R3Dfloat Vec2::LengthSq(const Vec2& vec) {
		return vec._x * vec._x + vec._y * vec._y;
	}

	R3Dfloat Vec2::Length(const Vec2& vec) {
		return sqrt(LengthSq(vec));
	}

	R3Dfloat Vec2::Magnitude() const {
		return Length();
	}

	R3Dfloat Vec2::Magnitude(const Vec2& vec) {
		return Length(vec);
	}

	Vec2& Vec2::Normalize() {
		R3Dfloat length = Length();
		this->_x /= length;
		this->_y /= length;

		return *this;
	}

	Vec2 Vec2::Normal() const {
		Vec2 res;

		R3Dfloat length = Length();

		res._x = this->_x / length;
		res._y = this->_y / length;

		return res;
	}

	Vec2& Vec2::Normalize(Vec2& vec) {
		return vec.Normalize();
	}

	Vec2 Vec2::Normal(const Vec2& vec) {
		return vec.Normal();
	}

	R3Dfloat Vec2::Dot(const Vec2& vec) const {
		return _x * vec._x + _y * vec._y;
	}

	R3Dfloat Vec2::Dot(const Vec2& left, const Vec2& right) {
		return left._x * right._x + left._y * right._y;
	}

	R3Dfloat Vec2::Angle(const Vec2& vec) const {
		R3Dfloat dot = Dot(vec);
		R3Dfloat dividend = Length() * vec.Length();

		return acos(dot / dividend);
	}

	R3Dfloat Vec2::Angle(const Vec2& vecA, const Vec2& vecB) {
		R3Dfloat dot = Dot(vecA, vecB);
		R3Dfloat dividend = Length(vecA) * Length(vecB);

		return acos(dot / dividend);
	}

	Vec2 Vec2::Lerp(const Vec2& vecA, const Vec2& vecB, R3Dfloat beta) {
		beta = Math::Max(Math::Min(1.0F, beta), 0.0F);

		R3Dfloat invBeta = 1.0F - beta;
		
		Vec2 a = Mul(vecA, invBeta);
		Vec2 b = Mul(vecB, beta);

		return Add(a, b);
	}

}
