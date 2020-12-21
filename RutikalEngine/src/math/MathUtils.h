/*********************************************************************
 * @file   MathUtils.h
 * @brief  Represents a collection of miscellaneous math functions
 *
 * @author Joshua Mayer
 * @date   December 15 2020
 * Copyright SoraCasus 2020
 *********************************************************************/
#pragma once

#include <RutikalEngine.h>

namespace R3D {
	namespace Math {

		/**
		 * Calculates the minimum value between the two inputs
		 *
		 * @param a The first value
		 * @param b The second value
		 * @return The min value between the two
		 */
		inline R3D_API R3Dfloat Min(R3Dfloat a, R3Dfloat b) {
			if (a > b) return b;
			return a;
		}

		/**
		 * Calculates the maximum value vetween the two inputs
		 *
		 * @param a The first value
		 * @param b The second value
		 * @return The max value between the two
		 */
		inline R3D_API R3Dfloat Max(R3Dfloat a, R3Dfloat b) {
			if (a > b) return a;
			return b;
		}
	}
}