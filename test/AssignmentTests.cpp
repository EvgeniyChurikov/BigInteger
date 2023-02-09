#include <gtest/gtest.h>
#include "BigInteger.h"

TEST(assignment, test1) {
    BigInteger A("0"), B("0");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test2) {
    BigInteger A("abc1234567887654321"), B("abc1234567887654321");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test3) {
    BigInteger A("0"), B("112233445566778899aabbccddeeff00");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test4) {
    BigInteger A("abcdef"), B("0");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test5) {
    BigInteger A("112233445566778899aabbccddeeff00"), B("abc1234567887654321");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test6) {
    BigInteger A("798627d64b6a3c5380186daa3a5142cbe54cd052164a417f0a0401f7d6db3cd0235b4997e52b466008");
    BigInteger B("cea448b652b57e66cc7c02c6b66e238d6fa75b8dada23d9212ff2d40efbb787c5f5bc971d2ddb9153c825161c1846a040974ffc91e5cbd8849c8ed9439b7ac668074ded51f3b9ee5b61ca89756dfa3afaa8bd0cdd37e646686de05f37d70ff58f0eca5fb2ad2ad43d23afe44cfee3cd79fa8d16db22498492d681b7ca2e5742a84c4c8ddea196d01dca1e65d1b1685e47919379ab560876b155714f266a301194d62a8828f56ba985f18b4c6303519c60e761a909b542109a280efbdeb6b58c5f0df5009704d8713ee93c221454161d37f84502236a8b30eae1c04f511ed77d4b1b91e7eafba9cf9f4daa3318e3f64b80f93697308d68a4addfae0c1181473ffda2");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test7) {
    BigInteger A("cea448b652b57e66cc7c02c6b66e238d6fa75b8dada23d9212ff2d40efbb787c5f5bc971d2ddb9153c825161c1846a040974ffc91e5cbd8849c8ed9439b7ac668074ded51f3b9ee5b61ca89756dfa3afaa8bd0cdd37e646686de05f37d70ff58f0eca5fb2ad2ad43d23afe44cfee3cd79fa8d16db22498492d681b7ca2e5742a84c4c8ddea196d01dca1e65d1b1685e47919379ab560876b155714f266a301194d62a8828f56ba985f18b4c6303519c60e761a909b542109a280efbdeb6b58c5f0df5009704d8713ee93c221454161d37f84502236a8b30eae1c04f511ed77d4b1b91e7eafba9cf9f4daa3318e3f64b80f93697308d68a4addfae0c1181473ffda2");
    BigInteger B("798627d64b6a3c5380186daa3a5142cbe54cd052164a417f0a0401f7d6db3cd0235b4997e52b466008");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test8) {
    BigInteger A("cea448b652b57e66cc7c02c6b66e238d6fa75b8dada23d9212ff2d40efbb787c5f5bc971d2ddb9153c825161c1846a040974ffc91e5cbd8849c8ed9439b7ac668074ded51f3b9ee5b61ca89756dfa3afaa8bd0cdd37e646686de05f37d70ff58f0eca5fb2ad2ad43d23afe44cfee3cd79fa8d16db22498492d681b7ca2e5742a84c4c8ddea196d01dca1e65d1b1685e47919379ab560876b155714f266a301194d62a8828f56ba985f18b4c6303519c60e761a909b542109a280efbdeb6b58c5f0df5009704d8713ee93c221454161d37f84502236a8b30eae1c04f511ed77d4b1b91e7eafba9cf9f4daa3318e3f64b80f93697308d68a4addfae0c1181473ffda2");
    BigInteger B("ede89e754fc5c3a47230a4608c67a95c5b0af96c8c6dd43d332b6fd9a2c9e82c4a719f0bfcf4a4f65a1ce96f0c2f9b82387aa8bc50ca6710700bd86f1831515095acd7fd248b6c67c91eacc7a8345f9eb765f1f28d8b6c816aea7f39bcd6822a589e3b210b54f424719be9226a87cbb7c78f8b959bde301b50406d3417f4d04958c6b113fcbfa6045e93239c35329c0b3734d36259c1e713c1197b332e86ae246233cb6350cf4f136ce0402393b7bf667beb59ee18e0adacfd44f38e6b1831eee2dfcc0b76e1452c901c38091ccd160079c7233ce53cddf6d509aba7b094ce88be52cbbf40b915737cc75aa755d5c7d3ba503bf3bb3556df07473925a7f0c27a705");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test9) {
    BigInteger A("798627d64b6a3c5380186daa3a5142cbe54cd052164a417f0a0401f7d6db3cd0235b4997e52b466008");
    BigInteger B = A;
    A = A;
    ASSERT_EQ(A, B);
}

TEST(assignment, test10) {
    BigInteger A("d8352085dbeb1e1b0e600d911ab067f4e49a705b0d9df303875500c5dc6eaee482b017329564e616ac166aa4efb2c690384e4510ee1431e3698d0b27bda45f7cd1eef0f6a1fca372ccf13141dbd054a5655312c14b0dec0c1b2edb879f9696a9ecafee97ac7a708d55fa65f784dd56144e36170fa779b681eb3f654f6a42a029b8ae3e89661002a6ea412cedf22889985a0eeb5e8e15fd5c18b291978bea8eec0effc7126367bbd280912d48ce8c67941e08273938fa8bc5c768a423af90fc9a5c754e75ed5b4b7a883f52efbd84ef6325076e1d0acb80daa8accec002983dd89d894781d569988e4293ec62ee84403565556d325dcb441d9eedf6f20a3cb197");
    BigInteger B("b5df63124fddf12b08af875dbd1ba77b581e416bd9bde9ac9d699260189b6011cda50997d185fd3a6813e25e54b882d0e2af66784974013265247f8654ebcbd74a2e38c9e4aa88198dfc871b9c0c9402ec061c868cff3023d3a603bb8b0d1c39deda2d0cd96b1df134cdc33b93187179c1f214e31eccbe2a08f005d9c7cd7a74");
    A = B;
    ASSERT_EQ(A, B);
}
