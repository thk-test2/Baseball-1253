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

    void check2Strikes0Ball(string guessNumber) {
        GuessResult result = game.guess(guessNumber);

        EXPECT_FALSE(result.solved);
        EXPECT_EQ(2, result.strikes);
        EXPECT_EQ(0, result.balls);
    }

    void check1Strikes2Ball(string guessNumber) {
        GuessResult result = game.guess(guessNumber);

        EXPECT_FALSE(result.solved);
        EXPECT_EQ(1, result.strikes);
        EXPECT_EQ(2, result.balls);
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

TEST_F(BaseballFixture, ReturnResultFor2Strikes0Ball) {
    check2Strikes0Ball("120");
    check2Strikes0Ball("103");
    check2Strikes0Ball("023");
}

TEST_F(BaseballFixture, ReturnResultFor1Strike2Balls) {
    check1Strikes2Ball("132");
    check1Strikes2Ball("321");
    check1Strikes2Ball("213");
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}