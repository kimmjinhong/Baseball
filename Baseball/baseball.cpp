#include <iostream>
#include <stdexcept>

using namespace std;
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
	const int STRING_LENGTH = 3;
public:
	explicit Baseball(const string& question)
		:question(question) {

	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, STRING_LENGTH, 0 };
		}
		int strikes = 0;
		int balls = 0;
		for (int i = 0; i < STRING_LENGTH; i++) {
			for (int j = 0; j < STRING_LENGTH; j++) {
				if (i == j && guessNumber[i] == question[i]) {
					strikes++;
					break;
				}
				if (guessNumber[i] == question[j]) {
					balls++;
					break;
				}
			}
		}
		return { false, strikes, balls };

	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be threee letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
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
	string question;
};