#include "Vec2.h"

namespace R3D {

	Vec2::Vec2() :
		_x(0.0F), _y(0.0F) {}

	Vec2::Vec2(R3Dfloat scalar) :
		_x(scalar), _y(scalar) {}

	Vec2::Vec2(R3Dfloat x, R3Dfloat y) :
		_x(x), _y(y) {}

	Vec2::Vec2(const Vec2& other) :
		_x(other._x), _y(other._y) {}

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
}
