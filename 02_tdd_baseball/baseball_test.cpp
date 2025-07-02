#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
    Baseball game;
    void assertIllegalArgument(string guessNumber) {
        // game.guess() ���� ��, Exception�� �߻��ؾ� PASS �̴�.
    }
};

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
    Baseball game;
    try {
        game.guess(string("12s"));
        FAIL();
    }
    catch(exception e) {
        // PASS
    }
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}