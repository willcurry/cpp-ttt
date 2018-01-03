#include "..\ttt-core\Combinations.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "pch.h"


TEST(Combinations, Has3Combinations) {
	Combinations combinations;
	ASSERT_EQ(combinations.GetAll().size(), 3);
}