#include <stdexcept>

using namespace std;

struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};

class Baseball {
public:
    explicit Baseball(const string& solution)
        : solution(solution) {
    }

    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);
        if (guessNumber == solution) {
            return { true, 3, 0 };
        }
        
        if (is2Strikes0Ball(guessNumber)) {
            return { false, 2, 0 };
        }

        if ((guessNumber[0] == solution[0]
                && guessNumber[1] == solution[2]
                && guessNumber[2] == solution[1]) ||
            (guessNumber[0] == solution[2]
                && guessNumber[1] == solution[1]
                && guessNumber[2] == solution[0])) {
            return { false, 1, 2 };
        }

        return { false, 0, 0 };
    }

    bool is2Strikes0Ball(const std::string& guessNumber)
    {
        return (guessNumber[0] == solution[0]
                && guessNumber[1] == solution[1]
                && guessNumber[2] != solution[2]) ||
            (guessNumber[0] == solution[0]
                && guessNumber[1] != solution[1]
                && guessNumber[2] == solution[2]) ||
            (guessNumber[0] != solution[0]
                && guessNumber[1] == solution[1]
                && guessNumber[2] == solution[2]);
    }

    void assertIllegalArgument(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3) {
            throw length_error("Must be three letters.");
        }

        for (char ch : guessNumber) {
            if (ch >= '0' && ch <= '9') continue;
            throw invalid_argument("Must be numbers");
        }

        if (isDuplicatedNumber(guessNumber)) {
            throw invalid_argument("Must not have the same number");
        }
    }

    bool isDuplicatedNumber(const std::string& guessNumber)
    {
        return guessNumber[0] == guessNumber[1]
            || guessNumber[0] == guessNumber[2]
            || guessNumber[1] == guessNumber[2];
    }

private:
    string solution;
};