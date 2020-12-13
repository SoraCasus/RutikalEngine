/*****************************************************************//**
 * @file   Vec2.h
 * @brief  Represents a 2D vector and vector operations
 * 
 * @author Joshua Mayer
 * @date   December 12 2020
 * Copyright SoraCasus 2020
 *********************************************************************/
#pragma once

#include "../RutikalEngine.h"

namespace R3D {

	/**
	 * A class to represent a 2D vector
	 */
	class R3D_API Vec2 {
	public:
		
		/**
		 * Constructor to initialize data members
		 */
		Vec2();
		
		/**
		 * Constructor to initialize data members
		 * 
		 * @param scalar A scalar value to intitlize both data members
		 */
		Vec2(R3Dfloat scalar);

		/**
		 * Constructor to initialize data members
		 * 
		 * @param x The value to initialize the x component
		 * @param y The value to initialize the y component
		 */
		Vec2(R3Dfloat x, R3Dfloat y);

		/**
		 * Copy constructor for the Vec2
		 * 
		 * @param other The Vec2 to copy from
		 */
		Vec2(const Vec2& other);

		/**
		 * Adds the other vector to this instance
		 * 
		 * @param other The other Vector to add
		 * @return The resulting vector
		 */
		Vec2& Add(const Vec2& other);

		/**
		 * Adds two vectors together
		 * 
		 * @param left The left hand side vector
		 * @param right The right hand side vector
		 * @return The sum of the two vectors
		 */
		static Vec2 Add(const Vec2& left, const Vec2& right);

		/**
		 * Adds a scalar to this instance
		 * 
		 * @param scalar The scalar to be added to the vector
		 * @return  The sum of the scalar and vector
		 */
		Vec2& Add(R3Dfloat scalar);

		/**
		 * Adds a scalar to the left vector
		 * 
		 * @param left The Vector to be added to
		 * @param right The scalar on the right
		 * @return The sum of the Vector and scalar
		 */
		static Vec2 Add(const Vec2& left, R3Dfloat right);

		/**
		 * Adds a scalar to the right vector
		 * 
		 * @param left The scalar to be added to the right vector
		 * @param right The Vector to be added to
		 * @return The sum of the vector and scalar
		 */
		static Vec2 Add(R3Dfloat left, const Vec2& right);

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


	private:

		/**
		 * The x coordinate of the 2D Vector
		 */
		R3Dfloat _x;
		
		/**
		 * The y coordinate of the 2D Vector
		 */
		R3Dfloat _y;

	};
}

