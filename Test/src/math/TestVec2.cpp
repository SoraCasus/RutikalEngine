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