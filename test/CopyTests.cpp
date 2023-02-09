#include <gtest/gtest.h>
#include "BigInteger.h"

TEST(copy, test1) {
    BigInteger A("0");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

TEST(copy, test2) {
    BigInteger A("abcdef");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

TEST(copy, test3) {
    BigInteger A("abc1234567887654321");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

TEST(copy, test4) {
    BigInteger A("112233445566778899aabbccddeeff00");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

TEST(copy, test5) {
    BigInteger A("cea448b652b57e66cc7c02c6b66e238d6fa75b8dada23d9212ff2d40efbb787c5f5bc971d2ddb9153c825161c1846a040974ffc91e5cbd8849c8ed9439b7ac668074ded51f3b9ee5b61ca89756dfa3afaa8bd0cdd37e646686de05f37d70ff58f0eca5fb2ad2ad43d23afe44cfee3cd79fa8d16db22498492d681b7ca2e5742a84c4c8ddea196d01dca1e65d1b1685e47919379ab560876b155714f266a301194d62a8828f56ba985f18b4c6303519c60e761a909b542109a280efbdeb6b58c5f0df5009704d8713ee93c221454161d37f84502236a8b30eae1c04f511ed77d4b1b91e7eafba9cf9f4daa3318e3f64b80f93697308d68a4addfae0c1181473ffda2");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}
