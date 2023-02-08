#include "BigInteger.h"


BigInteger::BigInteger(uint32_t *ptr, int length) : arr(ptr), digits_count(length) {}

uint32_t fromChar(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return 0;
}

BigInteger::BigInteger(const std::string &str) {
    digits_count = ((int) str.length() + 7) / 8;
    if (digits_count != 0) {
        arr = (uint32_t *) malloc(digits_count * 4);
        for (int i = 0; i < digits_count; ++i)
            arr[i] = 0;
        int i = 0;
        for (auto it = str.rbegin(); it != str.rend(); ++it) {
            arr[i / 8] += fromChar(*it) << ((i % 8) * 4);
            ++i;
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
        for (i = 7; i >= 0 && ((bigInteger.arr[bigInteger.digits_count - 1] >> (i * 4)) & 0xf) == 0; --i);
        for (; i >= 0; --i) {
            stream << toChar((bigInteger.arr[bigInteger.digits_count - 1] >> (i * 4)) & 0xf);
        }
        for (i = bigInteger.digits_count - 2; i >= 0; --i) {
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
    for (int i = 0; i < B.digits_count; ++i) {
        uint64_t temp = (uint64_t) A.arr[i] + (uint64_t) B.arr[i] + carry;
        res[i] = temp & 0xffffffff;
        carry = temp >> 32;
    }
    for (int i = B.digits_count; i < A.digits_count; ++i) {
        uint64_t temp = (uint64_t) A.arr[i] + carry;
        res[i] = temp & 0xffffffff;
        carry = temp >> 32;
    }
    if (carry != 0) {
        res[A.digits_count] = carry;
        return BigInteger(res, A.digits_count + 1);
    } else {
        res = (uint32_t *) realloc(res, A.digits_count * 4);
        return BigInteger(res, A.digits_count);
    }
}

uint32_t *removeLeadingZeros(uint32_t *arr, int length, int &newLength) {
    int i;
    for (i = length - 1; i >= 0 && arr[i] == 0; --i);
    if (i == -1) {
        newLength = 0;
        return nullptr;
    } else {
        newLength = i + 1;
        return (uint32_t *) realloc(arr, (i + 1) * 4);
    }
}

BigInteger BigInteger::operator-(const BigInteger &bigInteger) const {
    const BigInteger &A = *this;
    const BigInteger &B = bigInteger;
    auto res = (uint32_t *) malloc(A.digits_count * 4);

    int64_t borrow = 0;
    if (A.digits_count < B.digits_count)
        return BigInteger(nullptr, 0);
    for (int i = 0; i < B.digits_count; ++i) {
        int64_t temp = (int64_t) A.arr[i] - (int64_t) B.arr[i] - borrow;
        if (temp >= 0) {
            res[i] = temp;
            borrow = 0;
        } else {
            res[i] = 0x100000000 + temp;
            borrow = 1;
        }
    }
    for (int i = B.digits_count; i < A.digits_count; ++i) {
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
        int len;
        res = removeLeadingZeros(res, A.digits_count, len);
        return BigInteger(res, len);
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
    int len;
    res = removeLeadingZeros(res, A.digits_count + B.digits_count, len);
    return BigInteger(res, len);
}

bool less(const uint32_t *arr1, const uint32_t *arr2, int length) {
    for (int i = length - 1; i >= 0; --i) {
        if (arr1[i] < arr2[i])
            return true;
        if (arr1[i] > arr2[i])
            return false;
    }
    return false;
}

BigInteger BigInteger::operator/(const BigInteger &bigInteger) const {
    const BigInteger &A = *this;
    const BigInteger &B = bigInteger;

    auto res = (uint32_t *) malloc((A.digits_count - B.digits_count + 1) * 4);
    for (int i = 0; i <= A.digits_count - B.digits_count; ++i) {
        res[i] = 0;
    }

    auto *R = new uint32_t[A.digits_count];
    for (int i = 0; i < A.digits_count; ++i) {
        R[i] = A.arr[i];
    }
    int t = A.digits_count * 32 - 1;  // bitLength(R)
    auto *B_ = new uint32_t[A.digits_count];
    int k = B.digits_count * 32 - 1;  // bitLength(B.arr)
    while (B.arr[k / 32] >> k % 32 == 0)
        --k;

    while (true) {
        // move t to nearest 1
        while (t > 0 && R[t / 32] >> t % 32 == 0)
            --t;

        // exit conditions
        if (t < k || (t == k && less(R, B.arr, B.digits_count)))
            break;

        // move B in B_ to t (B_ = B << t;)
        int q = (t - k) / 32, r = (t - k) % 32;
        for (int i = 0; i < q; ++i)
            B_[i] = 0;
        if (r != 0) {
            B_[q] = B.arr[0] << r;
            for (int i = 1; i < B.digits_count; ++i)
                B_[q + i] = (B.arr[i] << r) | (B.arr[i - 1] >> (32 - r));
            B_[q + B.digits_count] = B.arr[B.digits_count - 1] >> (32 - r);
            for (int i = q + B.digits_count + 1; i < A.digits_count; ++i)
                B_[i] = 0;
        } else {
            B_[q] = B.arr[0];
            for (int i = 1; i < B.digits_count; ++i)
                B_[q + i] = B.arr[i];
            for (int i = q + B.digits_count; i < A.digits_count; ++i)
                B_[i] = 0;
        }

        // if (R < B_)
        if (less(R, B_, A.digits_count)) {
            --t;
            for (int i = 0; i < A.digits_count - 1; ++i)
                B_[i] = (B_[i] >> 1) | (B_[i + 1] << 31);
            B_[A.digits_count - 1] = B_[A.digits_count - 1] >> 1;
        }

        // R -= B_;
        int64_t borrow = 0;
        for (int i = 0; i < A.digits_count; ++i) {
            int64_t temp = (int64_t) R[i] - (int64_t) B_[i] - borrow;
            if (temp >= 0) {
                R[i] = temp;
                borrow = 0;
            } else {
                R[i] = 0x100000000 + temp;
                borrow = 1;
            }
        }

        // res += 1 << (t - k);
        q = (t - k) / 32;
        r = (t - k) % 32;
        res[q] |= 1 << r;
    }

    delete[] R;
    delete[] B_;

    int len;
    res = removeLeadingZeros(res, A.digits_count - B.digits_count + 1, len);
    return BigInteger(res, len);
}
