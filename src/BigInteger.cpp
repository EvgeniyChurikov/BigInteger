#include "BigInteger.h"


BigInteger::BigInteger(uint32_t *ptr, unsigned length) : arr(ptr), digits_count(length) {}

uint32_t fromChar(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return 0;
}

//todo: rewrite constructor (described in Notion)
BigInteger::BigInteger(const std::string &str) {
    digits_count = (str.length() + 7) / 8;
    if (digits_count != 0) {
        arr = (uint32_t *) malloc(digits_count * 4);
        auto it = str.rbegin();
        for (int i = 0; i < digits_count - 1; ++i) {
            arr[i] = 0;
            for (int j = 0; j < 8; ++j) {
                arr[i] += fromChar(*it) << (j * 4);
                ++it;
            }
        }
        arr[digits_count - 1] = 0;
        for (int i = 0; it != str.rend(); ++i) {
            arr[digits_count - 1] += fromChar(*it) << (i * 4);
            ++it;
        }
    }
}

BigInteger::BigInteger(const BigInteger &bigInteger) {
    digits_count = bigInteger.digits_count;
    if (digits_count != 0) {
        arr = (uint32_t *) malloc(digits_count * 4);
        for (int i = 0; i < digits_count; ++i) {
            arr[i] = bigInteger.arr[i];
        }
    }
}

BigInteger::~BigInteger() {
    free(arr);
}

BigInteger &BigInteger::operator=(const BigInteger &bigInteger) {
    if (this != &bigInteger) {
        if (digits_count != bigInteger.digits_count) {
            free(arr);
            digits_count = bigInteger.digits_count;
            if (digits_count != 0)
                arr = (uint32_t *) malloc(digits_count * 4);
            else
                arr = nullptr;
        }
        for (int i = 0; i < digits_count; ++i) {
            arr[i] = bigInteger.arr[i];
        }
    }
    return *this;
}

bool BigInteger::operator==(const BigInteger &bigInteger) const {
    if (digits_count != bigInteger.digits_count)
        return false;
    for (int i = 0; i < digits_count; ++i) {
        if (arr[i] != bigInteger.arr[i])
            return false;
    }
    return true;
}

char toChar(uint32_t n) {
    if (n <= 9)
        return (char) (n + '0');
    if (n <= 15)
        return (char) (n - 10 + 'a');
    return 'x';
}

std::ostream &operator<<(std::ostream &stream, const BigInteger &bigInteger) {
    if (bigInteger.digits_count != 0) {
        int i;
        for (i = 7; i >= 0 && (bigInteger.arr[bigInteger.digits_count - 1] & (0xf << (i * 4))) == 0; --i);
        for (; i >= 0; --i) {
            stream << toChar((bigInteger.arr[bigInteger.digits_count - 1] >> (i * 4)) & 0xf);
        }
        for (i = (int) (bigInteger.digits_count - 2); i >= 0; --i) {
            for (int j = 7; j >= 0; --j) {
                stream << toChar((bigInteger.arr[i] >> (j * 4)) & 0xf);
            }
        }
    } else
        stream << '0';
    return stream;
}

BigInteger BigInteger::operator+(const BigInteger &bigInteger) const {
    const BigInteger &A = (digits_count <= bigInteger.digits_count ? bigInteger : *this);
    const BigInteger &B = (digits_count <= bigInteger.digits_count ? *this : bigInteger);
    auto res = (uint32_t *) malloc((A.digits_count + 1) * 4);

    uint64_t carry = 0;
    for (unsigned i = 0; i < B.digits_count; ++i) {
        uint64_t temp = (uint64_t) A.arr[i] + (uint64_t) B.arr[i] + carry;
        res[i] = temp & 0xffffffff;
        carry = temp >> 32;
    }
    for (unsigned i = B.digits_count; i < A.digits_count; ++i) {
        uint64_t temp = (uint64_t) A.arr[i] + carry;
        res[i] = temp & 0xffffffff;
        carry = temp >> 32;
    }
    if (carry != 0) {
        res[A.digits_count] = carry;
        return BigInteger(res, A.digits_count + 1);
    } else {
        auto reres = (uint32_t *) realloc(res, A.digits_count * 4);
        return BigInteger(reres, A.digits_count);
    }
}

BigInteger BigInteger::operator-(const BigInteger &bigInteger) const {
    const BigInteger &A = *this;
    const BigInteger &B = bigInteger;
    auto res = (uint32_t *) malloc(A.digits_count * 4);

    int64_t borrow = 0;
    if (A.digits_count < B.digits_count)
        return BigInteger(nullptr, 0);
    for (unsigned i = 0; i < B.digits_count; ++i) {
        int64_t temp = (int64_t) A.arr[i] - (int64_t) B.arr[i] - borrow;
        if (temp >= 0) {
            res[i] = temp;
            borrow = 0;
        } else {
            res[i] = 0x100000000 + temp;
            borrow = 1;
        }
    }
    for (unsigned i = B.digits_count; i < A.digits_count; ++i) {
        int64_t temp = (int64_t) A.arr[i] - borrow;
        if (temp >= 0) {
            res[i] = temp;
            borrow = 0;
        } else {
            res[i] = 0x100000000 + temp;
            borrow = 1;
        }
    }
    if (borrow != 0)
        return BigInteger(nullptr, 0);
    else {
        int i;
        for (i = (int) A.digits_count - 1; i >= 0 && res[i] == 0; --i);
        if (i == -1)
            return BigInteger(nullptr, 0);
        else {
            auto reres = (uint32_t *) realloc(res, (i + 1) * 4);
            return BigInteger(reres, i + 1);
        }
    }
}

BigInteger BigInteger::operator*(const BigInteger &bigInteger) const {
    const BigInteger &A = *this;
    const BigInteger &B = bigInteger;
    auto res = (uint32_t *) malloc((A.digits_count + B.digits_count) * 4);
    for (int i = 0; i < A.digits_count + B.digits_count; ++i) {
        res[i] = 0;
    }

    for (int i = 0; i < A.digits_count; ++i) {
        for (int j = 0; j < B.digits_count; ++j) {
            uint64_t carry = (uint64_t) A.arr[i] * (uint64_t) B.arr[j];
            for (int k = i + j; carry != 0; ++k) {
                uint64_t temp = (uint64_t) res[k] + carry;
                res[k] = temp & 0xffffffff;
                carry = temp >> 32;
            }
        }
    }
    int i;
    for (i = (int) (A.digits_count + B.digits_count) - 1; i >= 0 && res[i] == 0; --i);
    if (i == -1)
        return BigInteger(nullptr, 0);
    else {
        auto reres = (uint32_t *) realloc(res, (i + 1) * 4);
        return BigInteger(reres, i + 1);
    }
}

unsigned BigInteger::bitLength() const {
    int d, b;
    for (d = (int) digits_count - 1; arr[d] == 0 && d >= 0; --d);
    if (d == -1)
        return 0;
    for (b = 0; (arr[d] & ((1 << 31) >> b)) == 0; ++b);
    return (d + 1) * 32 - b;
}

bool BigInteger::operator<(const BigInteger &bigInteger) const {
    const BigInteger &A = *this;
    const BigInteger &B = bigInteger;

    if (A.digits_count < B.digits_count)
        return true;
    if (A.digits_count > B.digits_count)
        return false;
    for (int i = (int) A.digits_count - 1; i >= 0; --i) {
        if (A.arr[i] < B.arr[i])
            return true;
        if (A.arr[i] > B.arr[i])
            return false;
    }
    return false;
}

bool BigInteger::operator>=(const BigInteger &bigInteger) const {
    return !(*this < bigInteger);
}

BigInteger BigInteger::operator<<(unsigned n) const {
    unsigned q = n / 32, r = n % 32;
    if (r != 0) {
        auto res = (uint32_t *) malloc((q + digits_count + 1) * 4);
        for (int i = 0; i < q; ++i)
            res[i] = 0;
        res[q] = arr[0] << r;
        for (int i = 1; i < digits_count; ++i)
            res[q + i] = (arr[i] << r) | (arr[i - 1] >> (32 - r));
        res[q + digits_count] = arr[digits_count - 1] >> (32 - r);
        if (res[q + digits_count] != 0)
            return BigInteger(res, digits_count + q + 1);
        else {
            auto reres = (uint32_t *) realloc(res, (q + digits_count) * 4);
            return BigInteger(reres, q + digits_count);
        }
    }
    else {
        auto res = (uint32_t *) malloc((q + digits_count) * 4);
        for (int i = 0; i < q; ++i)
            res[i] = 0;
        res[q] = arr[0];
        for (int i = 1; i < digits_count; ++i)
            res[q + i] = arr[i];
        return BigInteger(res, q + digits_count);
    }
}

BigInteger BigInteger::operator/(const BigInteger &bigInteger) const {
    const BigInteger &A = *this;
    const BigInteger &B = bigInteger;

    unsigned k = B.bitLength();
    BigInteger R = A;
    auto res = (uint32_t *) malloc((A.digits_count) * 4);
    for (int i = 0; i < A.digits_count; ++i) {
        res[i] = 0;
    }

    while (R >= B) {
        unsigned t = R.bitLength();
        BigInteger C = B << (t - k);
        if (R < C) {
            --t;
            C = B << (t - k);
        }
        R = R - C;
        unsigned q = (t - k) / 32, r = (t - k) % 32;
        res[q] |= (1 << r);
    }
    int i;
    for (i = (int) A.digits_count - 1; i >= 0 && res[i] == 0; --i);
    if (i == -1)
        return BigInteger(nullptr, 0);
    else {
        auto reres = (uint32_t *) realloc(res, (i + 1) * 4);
        return BigInteger(reres, i + 1);
    }
}
