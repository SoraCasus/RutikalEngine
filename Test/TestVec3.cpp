#include "TestVec3.h"

TEST(TestVec3, testDefaultInitializer) {
	R3D::Vec3 vec;

	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 0);
	ASSERT_EQ(vec.GetZ(), 0);
}

TEST(TestVec3, testScalarInitializer) {
	R3D::Vec3 vec(3);

	ASSERT_EQ(vec.GetX(), 3);
	ASSERT_EQ(vec.GetX(), 3);
	ASSERT_EQ(vec.GetZ(), 3);
}

TEST(TestVec3, testValueInitializer) {
	R3D::Vec3 vec(2, 5, 3);

	ASSERT_EQ(vec.GetX(), 2);
	ASSERT_EQ(vec.GetY(), 5);
	ASSERT_EQ(vec.GetZ(), 3);
}

TEST(TestVec3, testCopyInitializer) {
	R3D::Vec3 src(2, 4, 3);

	R3D::Vec3 dest = src;

	ASSERT_EQ(src.GetX(), dest.GetX());
	ASSERT_EQ(src.GetY(), dest.GetY());
	ASSERT_EQ(src.GetZ(), dest.GetZ());
}

TEST(TestVec3, testInstanceAddVector) {
	R3D::Vec3 left(1, 2, 3);
	R3D::Vec3 right(2, 2, 3);

	left.Add(right);

	ASSERT_EQ(left.GetX(), 3);
	ASSERT_EQ(left.GetY(), 4);
	ASSERT_EQ(left.GetZ(), 6);

	left = R3D::Vec3(1, 2, 3);
	right = R3D::Vec3(2, 2, 3);

	left += right;

	ASSERT_EQ(left.GetX(), 3);
	ASSERT_EQ(left.GetY(), 4);
	ASSERT_EQ(left.GetZ(), 6);
}

TEST(TestVec3, testVecVecAdd) {
	R3D::Vec3 left(1, 2, 3);
	R3D::Vec3 right(2, 2, 3);

	R3D::Vec3 res = R3D::Vec3::Add(left, right);

	ASSERT_EQ(res.GetX(), 3);
	ASSERT_EQ(res.GetY(), 4);
	ASSERT_EQ(res.GetZ(), 6);

	res = R3D::Vec3(0, 0, 0);
	res = left + right;

	ASSERT_EQ(res.GetX(), 3);
	ASSERT_EQ(res.GetY(), 4);
	ASSERT_EQ(res.GetZ(), 6);
}

TEST(TestVec3, testInstanceAddScalar) {
	R3D::Vec3 left(1, 2, 3);
	R3Dfloat right = 1.0F;

	left.Add(right);

	ASSERT_EQ(left.GetX(), 2.0F);
	ASSERT_EQ(left.GetY(), 3.0F);
	ASSERT_EQ(left.GetZ(), 4.0F);

	left = R3D::Vec3(1, 2, 3);
	right = 1.0F;

	left += right;

	ASSERT_EQ(left.GetX(), 2.0F);
	ASSERT_EQ(left.GetY(), 3.0F);
	ASSERT_EQ(left.GetZ(), 4.0F);
}

TEST(TestVec3, testVecScalarAdd) {
	R3D::Vec3 left(1, 2, 3);
	R3Dfloat right = 1.0F;

	R3D::Vec3 res = R3D::Vec3::Add(left, right);

	ASSERT_EQ(res.GetX(), 2.0F);
	ASSERT_EQ(res.GetY(), 3.0F);
	ASSERT_EQ(res.GetZ(), 4.0F);

	res = R3D::Vec3(0, 0, 0);
	res = left + right;

	ASSERT_EQ(res.GetX(), 2.0F);
	ASSERT_EQ(res.GetY(), 3.0F);
	ASSERT_EQ(res.GetZ(), 4.0F);
}

TEST(TestVec3, testScalarVecAdd) {
	R3Dfloat left = 1.0F;
	R3D::Vec3 right(1, 2, 3);

	R3D::Vec3 res = R3D::Vec3::Add(left, right);

	ASSERT_EQ(res.GetX(), 2.0F);
	ASSERT_EQ(res.GetY(), 3.0F);
	ASSERT_EQ(res.GetZ(), 4.0F);

	res = R3D::Vec3(0, 0, 0);
	res = left + right;

	ASSERT_EQ(res.GetX(), 2.0F);
	ASSERT_EQ(res.GetY(), 3.0F);
	ASSERT_EQ(res.GetZ(), 4.0F);
}
// Subtract
TEST(TestVec3, testInstanceSubVector) {
	R3D::Vec3 left(1, 2, 3);
	R3D::Vec3 right(2, 2, 2);

	left.Sub(right);

	ASSERT_EQ(left.GetX(), -1);
	ASSERT_EQ(left.GetY(), 0);
	ASSERT_EQ(left.GetZ(), 1);

	left = R3D::Vec3(1, 2, 3);
	right = R3D::Vec3(2, 2, 2);

	left -= right;

	ASSERT_EQ(left.GetX(), -1);
	ASSERT_EQ(left.GetY(), 0);
	ASSERT_EQ(left.GetZ(), 1);
}

TEST(TestVec3, testVecVecSub) {
	R3D::Vec3 left(1, 2, 3);
	R3D::Vec3 right(2, 2, 2);

	R3D::Vec3 res = R3D::Vec3::Sub(left, right);

	ASSERT_EQ(res.GetX(), -1);
	ASSERT_EQ(res.GetY(), 0);
	ASSERT_EQ(res.GetZ(), 1);


	res = left - right;

	ASSERT_EQ(res.GetX(), -1);
	ASSERT_EQ(res.GetY(), 0);
	ASSERT_EQ(res.GetZ(), 1);
}

TEST(TestVec3, testInstanceSubScalar) {
	R3D::Vec3 left(1, 2, 3);
	R3Dfloat right = 1.0F;

	left.Sub(right);

	ASSERT_EQ(left.GetX(), 0.0F);
	ASSERT_EQ(left.GetY(), 1.0F);
	ASSERT_EQ(left.GetZ(), 2.0F);

	left = R3D::Vec3(1, 2, 3);
	right = 1.0F;

	left -= right;

	ASSERT_EQ(left.GetX(), 0.0F);
	ASSERT_EQ(left.GetY(), 1.0F);
	ASSERT_EQ(left.GetZ(), 2.0F);
}

TEST(TestVec3, testVecScalarSub) {
	R3D::Vec3 left(1, 2, 3);
	R3Dfloat right = 1.0F;

	R3D::Vec3 res = R3D::Vec3::Sub(left, right);

	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), 1.0F);
	ASSERT_EQ(res.GetZ(), 2.0F);

	res = left - right;

	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), 1.0F);
	ASSERT_EQ(res.GetZ(), 2.0F);
}

TEST(TestVec3, testScalarVecSub) {
	R3Dfloat left = 1.0F;
	R3D::Vec3 right(1, 2, 3);

	R3D::Vec3 res = R3D::Vec3::Sub(left, right);

	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), -1.0F);
	ASSERT_EQ(res.GetZ(), -2.0F);

	res = left - right;

	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), -1.0F);
	ASSERT_EQ(res.GetZ(), -2.0F);
}
// Multiply
TEST(TestVec3, testInstanceMulVector) {
	R3D::Vec3 left(1, 2, 3);
	R3D::Vec3 right(2, 2, 2);

	left.Mul(right);

	ASSERT_EQ(left.GetX(), 2);
	ASSERT_EQ(left.GetY(), 4);
	ASSERT_EQ(left.GetZ(), 6);

	left = R3D::Vec3(1, 2, 3);

	left *= right;

	ASSERT_EQ(left.GetX(), 2);
	ASSERT_EQ(left.GetY(), 4);
	ASSERT_EQ(left.GetZ(), 6);
}

TEST(TestVec3, testVecVecMul) {
	R3D::Vec3 left(1, 2, 3);
	R3D::Vec3 right(2, 2, 2);

	R3D::Vec3 res = R3D::Vec3::Mul(left, right);

	ASSERT_EQ(res.GetX(), 2);
	ASSERT_EQ(res.GetY(), 4);
	ASSERT_EQ(res.GetZ(), 6);

	res = left * right;

	ASSERT_EQ(res.GetX(), 2);
	ASSERT_EQ(res.GetY(), 4);
	ASSERT_EQ(res.GetZ(), 6);
}

TEST(TestVec3, testInstanceMulScalar) {
	R3D::Vec3 left(1, 2, 3);
	R3Dfloat right = 1.0F;

	left.Mul(right);

	ASSERT_EQ(left.GetX(), 1.0F);
	ASSERT_EQ(left.GetY(), 2.0F);
	ASSERT_EQ(left.GetZ(), 3.0F);

	left = R3D::Vec3(1, 2, 3);

	left *= right;

	ASSERT_EQ(left.GetX(), 1.0F);
	ASSERT_EQ(left.GetY(), 2.0F);
	ASSERT_EQ(left.GetZ(), 3.0F);
}

TEST(TestVec3, testVecScalarMul) {
	R3D::Vec3 left(1, 2, 3);
	R3Dfloat right = 1.0F;

	R3D::Vec3 res = R3D::Vec3::Mul(left, right);

	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 2.0F);
	ASSERT_EQ(res.GetZ(), 3.0F);

	res = left * right;

	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 2.0F);
	ASSERT_EQ(res.GetZ(), 3.0F);
}

TEST(TestVec3, testScalarVecMul) {
	R3Dfloat left = 1.0F;
	R3D::Vec3 right(1, 2, 3);

	R3D::Vec3 res = R3D::Vec3::Mul(left, right);

	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 2.0F);
	ASSERT_EQ(res.GetZ(), 3.0F);

	res = left * right;

	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 2.0F);
	ASSERT_EQ(res.GetZ(), 3.0F);
}

TEST(TestVec3, testInstaceLengthSq) {
	R3D::Vec3 vec(1, 1, 0);

	ASSERT_EQ(vec.LengthSq(), 2);
}

TEST(TestVec3, testStaticLengthSq) {
	R3D::Vec3 vec(1, 1, 0);

	ASSERT_EQ(R3D::Vec3::LengthSq(vec), 2);
}

TEST(TestVec3, testInstanceLength) {
	R3D::Vec3 vec(3, 4, 0);

	ASSERT_EQ(vec.Length(), 5);
}

TEST(TestVec3, testStaticLength) {
	R3D::Vec3 vec(3, 4, 0);

	ASSERT_EQ(R3D::Vec3::Length(vec), 5);
}

TEST(TestVec3, testInstanceMagnitude) {
	R3D::Vec3 vec(3, 4, 0);

	ASSERT_EQ(vec.Magnitude(), 5);
}

TEST(TestVec3, testStaticMagnitude) {
	R3D::Vec3 vec(3, 4, 0);

	ASSERT_EQ(R3D::Vec3::Magnitude(vec), 5);
}

TEST(TestVec3, testInstanceNormalize) {
	R3D::Vec3 vec(0, 3, 0);

	vec.Normalize();

	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 1);
	ASSERT_EQ(vec.GetZ(), 0);
}

TEST(TestVec3, testInstanceNormal) {
	R3D::Vec3 vec(0, 3, 0);

	R3D::Vec3 norm = vec.Normal();

	ASSERT_EQ(norm.GetX(), 0);
	ASSERT_EQ(norm.GetY(), 1);
	ASSERT_EQ(norm.GetZ(), 0);
	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 3);
	ASSERT_EQ(vec.GetZ(), 0);
}

TEST(TestVec3, testStaticNormalize) {
	R3D::Vec3 vec(0, 3, 0);

	R3D::Vec3::Normalize(vec);

	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 1);
	ASSERT_EQ(vec.GetZ(), 0);
}

TEST(TestVec3, testStaticNormal) {
	R3D::Vec3 vec(0, 3, 0);

	R3D::Vec3 norm = R3D::Vec3::Normal(vec);

	ASSERT_EQ(norm.GetX(), 0);
	ASSERT_EQ(norm.GetY(), 1);
	ASSERT_EQ(norm.GetZ(), 0);
	ASSERT_EQ(vec.GetX(), 0);
	ASSERT_EQ(vec.GetY(), 3);
	ASSERT_EQ(vec.GetZ(), 0);
}

TEST(TestVec3, testInstanceDot) {
	R3D::Vec3 left(1, 0, 0);
	R3D::Vec3 right(0, 1, 0);

	R3Dfloat res = left.Dot(right);

	ASSERT_EQ(res, 0);

	left = R3D::Vec3(1, 0, 0);
	right = R3D::Vec3(1, 0, 0);

	res = left.Dot(right);

	ASSERT_EQ(res, 1);
}

TEST(TestVec3, testStaticDot) {
	R3D::Vec3 left(1, 0, 0);
	R3D::Vec3 right(0, 1, 0);

	R3Dfloat res = R3D::Vec3::Dot(left, right);

	ASSERT_EQ(res, 0);

	left = R3D::Vec3(1, 0, 0);
	right = R3D::Vec3(1, 0, 0);

	res = R3D::Vec3::Dot(left, right);

	ASSERT_EQ(res, 1);
}

TEST(TestVec3, testInstanceAngle) {
	R3D::Vec3 vecA(1, 0, 0);
	R3D::Vec3 vecB(0, 1, 0);

	R3Dfloat angle = vecA.Angle(vecB);

	ASSERT_NEAR(angle, 3.141F / 2, 0.01F);

	vecB = R3D::Vec3(-1, 0, 0);

	angle = vecA.Angle(vecB);

	ASSERT_NEAR(angle, 3.141F, 0.01F);
}

TEST(TestVec3, testStaticAngle) {
	R3D::Vec3 vecA(1, 0, 0);
	R3D::Vec3 vecB(0, 1, 0);

	R3Dfloat angle = R3D::Vec3::Angle(vecA, vecB);

	ASSERT_NEAR(angle, 3.141F / 2, 0.01F);

	vecB = R3D::Vec3(-1, 0, 0);

	angle = R3D::Vec3::Angle(vecA, vecB);

	ASSERT_NEAR(angle, 3.141F, 0.01F);
}

TEST(TestVec3, testLerp) {
	R3D::Vec3 vecA(1, 0, 0);
	R3D::Vec3 vecB(0, 1, 0);

	R3D::Vec3 res = R3D::Vec3::Lerp(vecA, vecB, 0.5F);
	ASSERT_EQ(res.GetX(), 0.5F);
	ASSERT_EQ(res.GetY(), 0.5F);
	ASSERT_EQ(res.GetZ(), 0.0F);

	res = R3D::Vec3::Lerp(vecA, vecB, 0.0F);
	ASSERT_EQ(res.GetX(), 1.0F);
	ASSERT_EQ(res.GetY(), 0.0F);
	ASSERT_EQ(res.GetZ(), 0.0F);

	res = R3D::Vec3::Lerp(vecA, vecB, 1.0F);
	ASSERT_EQ(res.GetX(), 0.0F);
	ASSERT_EQ(res.GetY(), 1.0F);
	ASSERT_EQ(res.GetZ(), 0.0F);
}

TEST(TestVec3, testString) {
	R3D::Vec3 vec(1, 2, 3);

	std::string str = vec.ToString();

	ASSERT_TRUE(str == "Vec3{ _x: 1, _y: 2, _z: 3}");
}

TEST(TestVec3, testCrossInstance) {
	R3D::Vec3 iVec(1, 0, 0);
	R3D::Vec3 jVec(0, 1, 0);

	iVec.Cross(jVec);

	ASSERT_EQ(iVec.GetX(), 0);
	ASSERT_EQ(iVec.GetY(), 0);
	ASSERT_EQ(iVec.GetZ(), 1);
}

TEST(TestVec3, testCrossStatic) {
	R3D::Vec3 iVec(1, 0, 0);
	R3D::Vec3 jVec(0, 1, 0);

	R3D::Vec3 res = R3D::Vec3::Cross(iVec, jVec);

	ASSERT_EQ(res.GetX(), 0);
	ASSERT_EQ(res.GetY(), 0);
	ASSERT_EQ(res.GetZ(), 1);
}