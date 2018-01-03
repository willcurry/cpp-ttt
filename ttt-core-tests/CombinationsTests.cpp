#include "..\ttt-core\Combinations.h"
#include "TestUtils.h"

TEST(Combinations, Has3Combinations) {
	Combinations combinations;
	ASSERT_EQ(combinations.GetAll().size(), 3);
}