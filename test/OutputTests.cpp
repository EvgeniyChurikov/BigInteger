#include <gtest/gtest.h>
#include "BigInteger.h"

// OUTPUT

TEST(output, test1) {
    std::string str("0");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}

TEST(output, test2) {
    std::string str("abc1234567887654321");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}

TEST(output, test3) {
    std::string str("abcdef");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}

TEST(output, test4) {
    std::string str("112233445566778899aabbccddeeff00");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}

TEST(output, test5) {
    std::string str("21250e68779500f758b1fdb640a44929a0779bf9c3db6e2167638779652f6012996dc31598283300a70e44137a6a88876fee1ded68542dae15453e92cb82e0a8fec9e717513aa43db797a276c8b59f51bfb06a2e5e9c08f669d03c855997e948fe28d9a06d27522dc94acb476e49a9571cff3899ab5f95c74dda1d0dd227c7e7e8285db2ec970c6755572ba93b72b5ab85e51668f3e6915651983bbdd7b76a4e5e5cbf7985d691526cdf846bcc84da7b74c54afd7a010368d7c6a95b3f6920678b09f5b22a39aac691c482449742b55055c4f58cb8c11d182f34f1de220bccf6df7b7f07d97d0e8a7ee567fd4e978dfe7cbfb6f95a6953748b64c010595a4f16");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}
