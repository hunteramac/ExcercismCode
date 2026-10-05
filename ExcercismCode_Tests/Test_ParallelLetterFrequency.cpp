#include "pch.h"
#include "../ExcercismCode/parallel_letter_frequency.h"

namespace ParallelLetterFrequency
{
TEST(Frequency, canCall)
{
	std::vector<std::string_view> const texts = {};
	auto freqs = parallel_letter_frequency::frequency(texts);
}

TEST(Frequency, noNumbers)
{
	std::vector<std::string_view> const texts = {"12345"};
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_TRUE(freqs.empty());
}

TEST(Frequency, noPunctuation)
{
	std::vector<std::string_view> const texts = { "!#@$#%^&*(." };
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_TRUE(freqs.empty());
}

TEST(Frequency, noWhitespace)
{
	std::vector<std::string_view> const texts = { "     \n" };
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_TRUE(freqs.empty());
}

TEST(Frequency, oneLetter)
{
	std::vector<std::string_view> const texts = { "a" };
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_FALSE(freqs.empty());
	EXPECT_EQ(freqs['a'], 1);
}

TEST(Frequency, oneText)
{
	std::vector<std::string_view> const texts = { "aaaaaabbb" };
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_FALSE(freqs.empty());
	EXPECT_EQ(freqs['a'], 6);
	EXPECT_EQ(freqs['b'], 3);
}

TEST(Frequency, multipleTextsDuplicate)
{
	std::vector<std::string_view> const texts = { "abc" , "abc"};
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_FALSE(freqs.empty());
	EXPECT_EQ(freqs['a'], 2);
	EXPECT_EQ(freqs['b'], 2);
	EXPECT_EQ(freqs['c'], 2);
}

TEST(Frequency, letterCasing)
{
	std::vector<std::string_view> const texts = { "AAA" , "aaa" };
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_FALSE(freqs.empty());
	EXPECT_EQ(freqs['a'], 6);
}

TEST(Frequency, MultipleComplexTexts1)
{
	std::vector<std::string_view> const texts = { 
		"The quick brown fox jumped over the lazy dog." , 
		"lorem ipsum dolor sit amet consectetur adipiscing elit sint ad" 
	};
	auto freqs = parallel_letter_frequency::frequency(texts);
	EXPECT_FALSE(freqs.empty());
	EXPECT_EQ(freqs['a'], 4);
	EXPECT_EQ(freqs['b'], 1);
	EXPECT_EQ(freqs['c'], 4);
	EXPECT_EQ(freqs['d'], 5);
	EXPECT_EQ(freqs['e'], 9);
}

}