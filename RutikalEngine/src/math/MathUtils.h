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

		inline R3D_API R3Dfloat Min(R3Dfloat a, R3Dfloat b) {
			if (a > b) return b;
			return a;
		}

		inline R3D_API R3Dfloat Max(R3Dfloat a, R3Dfloat b) {
			if (a > b) return a;
			return b;
		}

	}
}