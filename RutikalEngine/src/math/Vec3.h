/*********************************************************************
 * @file   Vec3.h
 * @brief Represents a 3D vector and operations
 * 
 * @author Joshua Mayer
 * @date   December 19 2020
 * Copyright SoraCasus 2020
 *********************************************************************/
#pragma once

#include <RutikalEngine.h>

#include <iostream>
#include <string>
#include <sstream>

namespace R3D {

	/**
	 * A class to represent a 3D Vector
	 */
	class R3D_API Vec3 {
	public:

		/**
		 * Constructor to initialize data members
		 */
		Vec3();

		/**
		 * Constructor to initialize data members
		 *
		 * @param scalar A scalar value to intitlize both data members
		 */
		Vec3(R3Dfloat scalar);

		/**
		 * Constructor to initialize data members
		 *
		 * @param x The value to initialize the x component
		 * @param y The value to initialize the y component
		 */
		Vec3(R3Dfloat x, R3Dfloat y, R3Dfloat z);

		/**
		 * Copy constructor for the Vec3
		 *
		 * @param other The Vec3 to copy from
		 */
		Vec3(const Vec3& other);

		/**
		 * Constructs a vector from point A to point B
		 *
		 * @param pointA The starting point (tail)
		 * @param pointB The ending point (head)
		 */
		Vec3(const Vec3& pointA, const Vec3& pointB);

		/**
		 * Adds the other vector to this instance
		 *
		 * @param other The other Vector to add
		 * @return The resulting vector
		 */
		Vec3& Add(const Vec3& other);

		/**
		 * Adds two vectors together
		 *
		 * @param left The left hand side vector
		 * @param right The right hand side vector
		 * @return The sum of the two vectors
		 */
		static Vec3 Add(const Vec3& left, const Vec3& right);

		/**
		 * Adds a scalar to this instance
		 *
		 * @param scalar The scalar to be added to the vector
		 * @return  The sum of the scalar and vector
		 */
		Vec3& Add(R3Dfloat scalar);

		/**
		 * Adds a scalar to the left vector
		 *
		 * @param left The Vector to be added to
		 * @param right The scalar on the right
		 * @return The sum of the Vector and scalar
		 */
		static Vec3 Add(const Vec3& left, R3Dfloat right);

		/**
		 * Adds a scalar to the right vector
		 *
		 * @param left The scalar to be added to the right vector
		 * @param right The Vector to be added to
		 * @return The sum of the vector and scalar
		 */
		static Vec3 Add(R3Dfloat left, const Vec3& right);

		/**
		 * Subtracts the other vector to this instance
		 *
		 * @param other The other Vector to subtract
		 * @return The resulting vector
		 */
		Vec3& Sub(const Vec3& other);

		/**
		 * Subtracts two vectors from eachother
		 *
		 * @param left The left hand side vector
		 * @param right The right hand side vector
		 * @return The difference of the two vectors
		 */
		static Vec3 Sub(const Vec3& left, const Vec3& right);

		/**
		 * Subtracts a scalar to this instance
		 *
		 * @param scalar The scalar to be subtracted from the vector
		 * @return  The difference of the scalar and vector
		 */
		Vec3& Sub(R3Dfloat scalar);

		/**
		 * Subtracts a scalar to the left vector
		 *
		 * @param left The Vector to be subtracted from
		 * @param right The scalar on the right
		 * @return The difference of the Vector and scalar
		 */
		static Vec3 Sub(const Vec3& left, R3Dfloat right);

		/**
		 * Subtracts a vector from the scalar
		 *
		 * @param left The scalar to be subtracted from
		 * @param right The Vector to be subtracted
		 * @return The difference of the vector and scalar
		 */
		static Vec3 Sub(R3Dfloat left, const Vec3& right);

		/**
		 * Multiplies the other vector to this instance
		 *
		 * @param other The other Vector to multiply
		 * @return The resulting vector
		 */
		Vec3& Mul(const Vec3& other);

		/**
		 * Multiply two vectors together
		 *
		 * @param left The left hand side vector
		 * @param right The right hand side vector
		 * @return The product of the two vectors
		 */
		static Vec3 Mul(const Vec3& left, const Vec3& right);

		/**
		 * Multiplies a scalar to this instance
		 *
		 * @param scalar The scalar to be multiplied to the vector
		 * @return  The product of the scalar and vector
		 */
		Vec3& Mul(R3Dfloat scalar);

		/**
		 * Multiplies a scalar to the left vector
		 *
		 * @param left The Vector to be multiplied to
		 * @param right The scalar on the right
		 * @return The product of the Vector and scalar
		 */
		static Vec3 Mul(const Vec3& left, R3Dfloat right);

		/**
		 * Multiplies a scalar to the right vector
		 *
		 * @param left The scalar to be multiplied to the right vector
		 * @param right The Vector to be multiplied
		 * @return The product of the vector and scalar
		 */
		static Vec3 Mul(R3Dfloat left, const Vec3& right);

		/**
		 * The squared length of the vector
		 *
		 * @return The squared length of the vector
		 */
		R3Dfloat LengthSq() const;

		/**
		 * Calculates the squared length of the vector
		 *
		 * @param vec The vector to calculate the squared length of
		 * @return The squared length of the vector
		 */
		static R3Dfloat LengthSq(const Vec3& vec);

		/**
		 * The length of the vector from tail to head
		 *
		 * @return The length of the vector
		 */
		R3Dfloat Length() const;

		/**
		 *  The length of the vector from tail to head
		 *
		 * @param vec The vector to calculate the length of
		 * @return The length of the vector
		 */
		static R3Dfloat Length(const Vec3& vec);

		/**
		 * The Magnitude of the vector from tail to head
		 *
		 * @return The magnitude of the vector
		 */
		R3Dfloat Magnitude() const;

		/**
		 * The Magnitude of the vector from tail to head
		 *
		 * @param vec The vector to calculate the magnitude of
		 * @return The magnitude of the vector
		 */
		static R3Dfloat Magnitude(const Vec3& vec);

		/**
		 * Normalizes the vector.
		 *
		 * @return The vector after normalization
		 */
		Vec3& Normalize();

		/**
		 * Calculates the normal of the vector. Non-Mutable
		 *
		 * @return The normal of the vector
		 */
		Vec3 Normal() const;

		/**
		 * Normalizes the given vector
		 *
		 * @param vec The vector to be normalized
		 * @return The normalized vector
		 */
		static Vec3& Normalize(Vec3& vec);

		/**
		 * Calculates the normal of the given vector
		 *
		 * @param vec The vector to calculate the normal from
		 * @return The normal of the vector
		 */
		static Vec3 Normal(const Vec3& vec);

		/**
		 * Calculates the dot product between this vector and the given
		 *
		 * @param vec The vector to calculate the dot product with
		 * @return The dot product bewteen the vectors
		 */
		R3Dfloat Dot(const Vec3& vec) const;

		/**
		 * Calculates the dot product between the two vectors
		 *
		 * @param left The left operand of the dot product
		 * @param right The right operand of the dot product
		 * @return The dot product between the vectors
		 */
		static R3Dfloat Dot(const Vec3& left, const Vec3& right);

		/**
		 * Calculates the angle between the two vectors constrained between
		 * 0 < theta < pi
		 *
		 * @param vec the other vector to calculate the angle from
		 * @return The angle between this vector and the other vector
		 */
		R3Dfloat Angle(const Vec3& vec) const;

		/**
		 * Calculates the angle between the two vectors constrained between
		 * 0 < theta < pi
		 *
		 * @param vecA The first vector
		 * @param vecB The second vector
		 * @return The angle between the vectors
		 */
		static R3Dfloat Angle(const Vec3& vecA, const Vec3& vecB);

		/**
		 * Calculates the linear interpolation between two vectors
		 *
		 * @param vecA The starting point vector
		 * @param vecB The ending point vector
		 * @param beta The percentage process, constrained between 0 and 1
		 * @return The linearly interpolated vector between the two
		 */
		static Vec3 Lerp(const Vec3& vecA, const Vec3& vecB, R3Dfloat beta);

		/**
		 * Getter method for the X component of the vector
		 *
		 * @return The X component of the vector
		 */
		inline R3Dfloat GetX() const { return _x; }

		/**
		 * Getter method for the Y component of the vector
		 *
		 * @return The Y component of the vector
		 */
		inline R3Dfloat GetY() const { return _y; }

		inline std::string ToString() const {
			std::stringstream ss;
			ss << "Vec3{ _x: " << _x << ", _y: " << _y << ", _z: " << _z << "}";
			return ss.str();
		}

		/**
		 * Operator overloads and their proper declarations
		 */

		friend R3D_API Vec3 operator+(Vec3 left, const Vec3& right);
		friend R3D_API Vec3 operator-(Vec3 left, const Vec3& right);
		friend R3D_API Vec3 operator*(Vec3 left, const Vec3& right);

		friend R3D_API Vec3 operator+(Vec3 left, R3Dfloat right);
		friend R3D_API Vec3 operator-(Vec3 left, R3Dfloat right);
		friend R3D_API Vec3 operator*(Vec3 left, R3Dfloat right);

		bool operator==(const Vec3& other) const;
		bool operator!=(const Vec3& other) const;

		Vec3& operator+=(const Vec3& other);
		Vec3& operator+=(R3Dfloat other);

		Vec3& operator-=(const Vec3& other);
		Vec3& operator-=(R3Dfloat other);

		Vec3& operator*=(const Vec3& other);
		Vec3& operator*=(R3Dfloat other);

		bool operator<(const Vec3& other) const;
		bool operator<=(const Vec3& other) const;
		bool operator>(const Vec3& other) const;
		bool operator>=(const Vec3& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec);


	private:
		union {
			struct {
				R3Dfloat _x;
				R3Dfloat _y;
				R3Dfloat _z;
			};

			R3Dfloat elements[3];
		};
	};

}