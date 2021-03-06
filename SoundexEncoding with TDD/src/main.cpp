#include <iostream>
#include <string>

#include "gmock\gmock.h"
#include "soundex.h"

#pragma comment(lib, "gmock.lib")


using ::testing::Test;

struct SoundexEncoding : Test
{
	Soundex soundex;
};

using ::testing::Eq;

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord)
{
	ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
	ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
	ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
	ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoreVowelLikeLetters)
{
	ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, SimilarWordsMapsToTheSameCode)
{
	ASSERT_THAT(soundex.encode("Tolkien"), Eq(soundex.encode("Tolkin")));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings)
{
	ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

using ::testing::StartsWith;

TEST_F(SoundexEncoding, UppercasesFirstLetter)
{
	ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants)
{
	ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicates1st)
{
	ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}

TEST_F(SoundexEncoding, DoesNotCombineDuplicateEncodingsSeparatedByVowels)
{
	ASSERT_THAT(soundex.encode("Jbob"), Eq("J110"));
}

int main(int argc, char **argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}