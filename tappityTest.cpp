/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test)
{
	ASSERT_TRUE(true);
}

//difference tests

TEST(tappityTest, difference_test)
{
	tappity mytest("What's up doc?");
	mytest.entry("What's up doc?");
	ASSERT_EQ(mytest.length_difference(), 0);
}

TEST(tappityTest, inputbigger)
{
	tappity mytest("What's up doc?");
	mytest.entry("What's up doctor?");
	ASSERT_EQ(mytest.length_difference(), 3);
}

TEST(tappityTest, referencebigger)
{
	tappity mytest("What's up doctor?");
	mytest.entry("What's up doc?");
	ASSERT_EQ(mytest.length_difference(), 3);
}

TEST(tappityTest, neitherstring)
{
	tappity mytest("");
	mytest.entry("");
	ASSERT_EQ(mytest.length_difference(), 0);
}

TEST(tappityTest, noreference)
{
	tappity mytest("What's up doc?");
	mytest.entry("");
	ASSERT_EQ(mytest.length_difference(), 14);
}

TEST(tappityTest, noinput)
{
	tappity mytest("What's up doc?");
	mytest.entry("");
	ASSERT_EQ(mytest.length_difference(), 14);
}

//accuracy tests

TEST(tappityTest, accuracy_test)
{
	tappity mytest("What's up doc?");
	mytest.entry("What's up doc?");
	ASSERT_EQ(mytest.accuracy(), (double)100);
}

TEST(tappityTest, over_accuracy)
{
	tappity mytest("What's up doc?");
	mytest.entry("What's up doctor?");
	ASSERT_EQ(mytest.accuracy(), ((double)13/(double)17)*(double)100);
}

TEST(tappityTest, under_accuracy)
{
	tappity mytest("What's up doctor?");
	mytest.entry("What's up doc?");
	ASSERT_EQ(mytest.accuracy(), ((double)13/(double)17)*(double)100);
}

TEST(tappityTest, nostrings)
{
	tappity mytest("");
	mytest.entry("");
	ASSERT_EQ(mytest.accuracy(), (double)100);
}

TEST(tappityTest, noreference_accuracy)
{
	tappity mytest("");
	mytest.entry("What's up doc?");
	ASSERT_EQ(mytest.accuracy(), (double)0);
}

TEST(tappityTest, noinput_accuracy)
{
	tappity mytest("What's up doc?");
	mytest.entry("");
	ASSERT_EQ(mytest.accuracy(), (double)0);
}