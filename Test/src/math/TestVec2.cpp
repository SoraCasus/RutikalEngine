#include "TestVec2.h"

TEST(TestVec2, testDefaultInitializer) {
	R3D::Vec2 vec;

	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 0);
}

TEST(TestVec2, testScalarInitializer) {
	R3D::Vec2 vec(3);

	ASSERT_EQ(vec.GetX(), 3);
	ASSERT_EQ(vec.GetX(), 3);
}

TEST(TestVec2, testValueInitializer) {
	R3D::Vec2 vec(2, 5);

	ASSERT_EQ(vec.GetX(), 2);
	ASSERT_EQ(vec.GetY(), 5);
}

TEST(TestVec2, testCopyInitializer) {
	R3D::Vec2 src(2, 4);

	R3D::Vec2 dest = src;

	ASSERT_EQ(src.GetX(), dest.GetX());
	ASSERT_EQ(src.GetY(), dest.GetY());
}

TEST(TestVec2, testInstanceAddVector) {
	R3D::Vec2 left(1, 2);
	R3D::Vec2 right(2, 2);

	left.Add(right);

	ASSERT_EQ(left.GetX(), 3);
	ASSERT_EQ(left.GetY(), 4);
}

TEST(TestVec2, testVecVecAdd) {
	R3D::Vec2 left(1, 2);
	R3D::Vec2 right(2, 2);

	R3D::Vec2 res = R3D::Vec2::Add(left, right); 

	ASSERT_EQ(res.GetX(), 3);
	ASSERT_EQ(res.GetY(), 4);
}

TEST(TestVec2, testInstanceAddScalar) {
	R3D::Vec2 left(1, 2);
	R3Dfloat right = 1.0F;

	left.Add(right);

	ASSERT_EQ(left.GetX(), 2.0F);
	ASSERT_EQ(left.GetY(), 3.0F);
}

TEST(TestVec2, testVecScalarAdd) {
	R3D::Vec2 left(1, 2);
	R3Dfloat right = 1.0F;

	R3D::Vec2 res = R3D::Vec2::Add(left, right);

	ASSERT_EQ(res.GetX(), 2.0F);
	ASSERT_EQ(res.GetY(), 3.0F);
}

TEST(TestVec2, testScalarVecAdd) {
	R3Dfloat left = 1.0F;
	R3D::Vec2 right(1, 2);

	R3D::Vec2 res = R3D::Vec2::Add(left, right);

	ASSERT_EQ(res.GetX(), 2.0F);
	ASSERT_EQ(res.GetY(), 3.0F);
}
// Subtract
TEST(TestVec2, testInstanceSubVector) {
	R3D::Vec2 left(1, 2);
	R3D::Vec2 right(2, 2);

	left.Sub(right);

	ASSERT_EQ(left.GetX(), -1);
	ASSERT_EQ(left.GetY(), 0);
}

TEST(TestVec2, testVecVecSub) {
	R3D::Vec2 left(1, 2);
	R3D::Vec2 right(2, 2);

	R3D::Vec2 res = R3D::Vec2::Sub(left, right);

	ASSERT_EQ(res.GetX(), -1);
	ASSERT_EQ(res.GetY(), 0);
}

TEST(TestVec2, testInstanceSubScalar) {
	R3D::Vec2 left(1, 2);
	R3Dfloat right = 1.0F;

	left.Sub(right);

	ASSERT_EQ(left.GetX(), 0.0F);
	ASSERT_EQ(left.GetY(), 1.0F);
}

TEST(TestVec2, testVecScalarSub) {
	R3D::Vec2 left(1, 2);
	R3Dfloat right = 1.0F;

	R3D::Vec2 res = R3D::Vec2::Sub(left, right);

	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), 1.0F);
}

TEST(TestVec2, testScalarVecSub) {
	R3Dfloat left = 1.0F;
	R3D::Vec2 right(1, 2);

	R3D::Vec2 res = R3D::Vec2::Sub(left, right);

	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), -1.0F);
}
// Multiply
TEST(TestVec2, testInstanceMulVector) {
	R3D::Vec2 left(1, 2);
	R3D::Vec2 right(2, 2);

	left.Mul(right);

	ASSERT_EQ(left.GetX(), 2);
	ASSERT_EQ(left.GetY(), 4);
}

TEST(TestVec2, testVecVecMul) {
	R3D::Vec2 left(1, 2);
	R3D::Vec2 right(2, 2);

	R3D::Vec2 res = R3D::Vec2::Mul(left, right);

	ASSERT_EQ(res.GetX(), 2);
	ASSERT_EQ(res.GetY(), 4);
}

TEST(TestVec2, testInstanceMulScalar) {
	R3D::Vec2 left(1, 2);
	R3Dfloat right = 1.0F;

	left.Mul(right);

	ASSERT_EQ(left.GetX(), 1.0F);
	ASSERT_EQ(left.GetY(), 2.0F);
}

TEST(TestVec2, testVecScalarMul) {
	R3D::Vec2 left(1, 2);
	R3Dfloat right = 1.0F;

	R3D::Vec2 res = R3D::Vec2::Mul(left, right);

	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 2.0F);
}

TEST(TestVec2, testScalarVecMul) {
	R3Dfloat left = 1.0F;
	R3D::Vec2 right(1, 2);

	R3D::Vec2 res = R3D::Vec2::Mul(left, right);

	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 2.0F);
}

TEST(TestVec2, testInstaceLengthSq) {
	R3D::Vec2 vec(1, 1);

	ASSERT_EQ(vec.LengthSq(), 2);
}

TEST(TestVec2, testStaticLengthSq) {
	R3D::Vec2 vec(1, 1);

	ASSERT_EQ(R3D::Vec2::LengthSq(vec), 2);
}

TEST(TestVec2, testInstanceLength) {
	R3D::Vec2 vec(3, 4);

	ASSERT_EQ(vec.Length(), 5);
}

TEST(TestVec2, testStaticLength) {
	R3D::Vec2 vec(3, 4);

	ASSERT_EQ(R3D::Vec2::Length(vec), 5);
}

TEST(TestVec2, testInstanceMagnitude) {
	R3D::Vec2 vec(3, 4);

	ASSERT_EQ(vec.Magnitude(), 5);
}

TEST(TestVec2, testStaticMagnitude) {
	R3D::Vec2 vec(3, 4);

	ASSERT_EQ(R3D::Vec2::Magnitude(vec), 5);
}

TEST(TestVec2, testInstanceNormalize) {
	R3D::Vec2 vec(0, 3);

	vec.Normalize();

	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 1);
}

TEST(TestVec2, testInstanceNormal) {
	R3D::Vec2 vec(0, 3);

	R3D::Vec2 norm = vec.Normal();

	ASSERT_EQ(norm.GetX(), 0);
	ASSERT_EQ(norm.GetY(), 1);
	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 3);
}

TEST(TestVec2, testStaticNormalize) {
	R3D::Vec2 vec(0, 3);

	R3D::Vec2::Normalize(vec);

	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 1);
}

TEST(TestVec2, testStaticNormal) {
	R3D::Vec2 vec(0, 3);

	R3D::Vec2 norm = R3D::Vec2::Normal(vec);

	ASSERT_EQ(norm.GetX(), 0);
	ASSERT_EQ(norm.GetY(), 1);
	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 3);
}

TEST(TestVec2, testInstanceDot) {
	R3D::Vec2 left(1, 0);
	R3D::Vec2 right(0, 1);

	R3Dfloat res = left.Dot(right);

	ASSERT_EQ(res, 0);

	left = R3D::Vec2(1, 0);
	right = R3D::Vec2(1, 0);

	res = left.Dot(right);
	
	ASSERT_EQ(res, 1);
}

TEST(TestVec2, testStaticDot) {
	R3D::Vec2 left(1, 0);
	R3D::Vec2 right(0, 1);

	R3Dfloat res = R3D::Vec2::Dot(left, right);

	ASSERT_EQ(res, 0);

	left = R3D::Vec2(1, 0);
	right = R3D::Vec2(1, 0);

	res = R3D::Vec2::Dot(left, right);

	ASSERT_EQ(res, 1);
}

TEST(TestVec2, testInstanceAngle) {
	R3D::Vec2 vecA(1, 0);
	R3D::Vec2 vecB(0, 1);

	R3Dfloat angle = vecA.Angle(vecB);

	ASSERT_NEAR(angle, 3.141F / 2, 0.01F);

	vecB = R3D::Vec2(-1, 0);

	angle = vecA.Angle(vecB);

	ASSERT_NEAR(angle, 3.141F, 0.01F);
}

TEST(TestVec2, testStaticAngle) {
	R3D::Vec2 vecA(1, 0);
	R3D::Vec2 vecB(0, 1);

	R3Dfloat angle = R3D::Vec2::Angle(vecA, vecB);

	ASSERT_NEAR(angle, 3.141F / 2, 0.01F);

	vecB = R3D::Vec2(-1, 0);

	angle = R3D::Vec2::Angle(vecA, vecB);

	ASSERT_NEAR(angle, 3.141F, 0.01F);
}

TEST(TestVec2, testLerp) {
	R3D::Vec2 vecA(1, 0);
	R3D::Vec2 vecB(0, 1);

	R3D::Vec2 res = R3D::Vec2::Lerp(vecA, vecB, 0.5F);
	ASSERT_EQ(res.GetX(), 0.5F);
	ASSERT_EQ(res.GetY(), 0.5F);

	res = R3D::Vec2::Lerp(vecA, vecB, 0.0F);
	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 0.0F);

	res = R3D::Vec2::Lerp(vecA, vecB, 1.0F);
	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), 1.0F);
}