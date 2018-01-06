#include "..\ttt-console\ConsolePlayer.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ConsolePlayer, KnowsNextMovesFromStream) {
	std::stringstream stream;
	stream << "1";
	ConsolePlayer player('x', stream);
	EXPECT_EQ(player.NextMove(), 1);
}