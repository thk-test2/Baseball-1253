#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertIllegalArgument(string guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
    }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnResultFor2Strikes0BallFirst) {
    GuessResult result = game.guess("120");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnResultFor2Strikes0BallSecond) {
    GuessResult result = game.guess("103");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnResultFor2Strikes0BallThird) {
    GuessResult result = game.guess("023");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}