#pragma once

#include <cstdint>
#include <string>
#include <ostream>

class BigInteger {
private:
    uint32_t *arr{};
    unsigned digits_count;

    explicit BigInteger(uint32_t *ptr, unsigned length);

    unsigned bitLength() const;

    bool operator<(const BigInteger &bigInteger) const;

    bool operator>=(const BigInteger &bigInteger) const;

    BigInteger operator<<(unsigned n) const;

public:
    explicit BigInteger(const std::string &str);

    BigInteger(const BigInteger &bigInteger);

    ~BigInteger();

    BigInteger &operator=(const BigInteger &bigInteger);

    bool operator==(const BigInteger &bigInteger) const;

    friend std::ostream &operator<<(std::ostream &stream, const BigInteger &bigInteger);

    BigInteger operator+(const BigInteger &bigInteger) const;

    BigInteger operator-(const BigInteger &bigInteger) const;

    BigInteger operator*(const BigInteger &bigInteger) const;

    BigInteger operator/(const BigInteger &bigInteger) const;
};
