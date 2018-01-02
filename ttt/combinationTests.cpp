#include "pch.h"
#include "Combinations.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(Combinations, Has3Combinations) {
	Combinations combinations;
	ASSERT_EQ(combinations.GetAll().size(), 3);
}