#include "..\ttt-core\Combinations.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace testing;


TEST(Combinations, Has3Combinations) {
	Combinations combinations;
	ASSERT_EQ(combinations.GetAll().size(), 3);
}