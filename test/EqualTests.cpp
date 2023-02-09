#include <gtest/gtest.h>
#include "BigInteger.h"

TEST(equal, test1) {
    BigInteger A("0"), B("0");
    ASSERT_TRUE(A == B);
}

TEST(equal, test2) {
    BigInteger A("abc1234567887654321"), B("abc1234567887654321");
    ASSERT_TRUE(A == B);
}

TEST(equal, test3) {
    BigInteger A("112233445566778899aabbccddeeff00"), B("112233445566778899aabbccddeeff00");
    ASSERT_TRUE(A == B);
}

TEST(equal, test4) {
    BigInteger A("abcdef"), B("abcdef");
    ASSERT_TRUE(A == B);
}

TEST(equal, test5) {
    BigInteger A("0"), B("112233445566778899aabbccddeeff00");
    ASSERT_FALSE(A == B);
}

TEST(equal, test6) {
    BigInteger A("abcdef"), B("0");
    ASSERT_FALSE(A == B);
}

TEST(equal, test7) {
    BigInteger A("112233445566778899aabbccddeeff00"), B("abc1234567887654321");
    ASSERT_FALSE(A == B);
}

TEST(equal, test8) {
    BigInteger A("abc1234567887654321"), B("abcdef");
    ASSERT_FALSE(A == B);
}

TEST(equal, test9) {
    BigInteger A("9a611f032d82ddfa55584ef879a2004b21686ea1cc10d4143cdb79be09565263");
    BigInteger B("5a611f032d82ddfa55524ef879a2004b21686ea1cc10d4143cdb79be09565263");
    ASSERT_FALSE(A == B);
}

TEST(equal, test10) {
    BigInteger A("2405684efd2bc72854f74450b73e1cf3e722aa7959ae6c1285ec91ffbfe3fe80119b0e5014198039ea228faf1c9edfd70aa3256e05d9e7557b0cffbb10e7ab984c8e7f64e886d4e67858950aeb1e7196828e8950b3c9ae75ddd22ac9a9fa0f3daf90e7488bfa1b7aeebacc02174817e328fa13df8c2f3481daabe3cdf4b7b539c4c0c10c970b7eef8dadaed3c8efa9cf3ce9307e8909f2bf0919644fec90d028e059628e78030af156be8d5c65839b2aa2e0572d0dff59d306030997c1da2dda7519fd1c9de897c2c73ebcf828562a890b79ae0a7ed77a02df238a12459352dff1523ad5cff601e11d44f783299323ca874b7756cf5c7da29d199e7c46ceb73c");
    BigInteger B("2405684efd2bc72854f74450b73e1cf3e722aa7959ae6c1285ec91ffbfe3fe80119b0e5014198039ea228faf1c9edfd70aa3256e05d9e7557b0cffbb10e7ab984c8e7f64e886d4e67858950aeb1e7196828e8950b3c9ae75ddd22ac9a9fa0f3daf90e7488bfa1b7aeebacc02174817e328fa13df8c2f3481daabe3cdf4b7b539c4c0c10c970b7eef8dadaed3c8efa9cf3ce9307e8909f2bf0919644fec90d028e059628e78030af156be8d5c65839b2aa2e0572d0dff59d306030997c1da2dda7519fd1c9de897c2c73ebcf828562a890b79ae0a7ed77a02df238a12459352dff1523ad5cff601e11d44f783299323ca874b7756cf5c7da29d199e7c46ceb73c");
    ASSERT_TRUE(A == B);
}
