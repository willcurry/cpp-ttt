#include "..\ttt-core\Combinations.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"


TEST(Combinations, Has3Combinations) {
	Combinations combinations;
	ASSERT_EQ(combinations.GetAll().size(), 3);
}