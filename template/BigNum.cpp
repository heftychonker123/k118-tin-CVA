#include <bits/stdc++.h>
using namespace std;

const int BASE = 10;
struct BigNum {
    string s;
    bool isNeg;

    BigNum() : s("0"), isNeg(false) {}
    BigNum(int length){
        isNeg = false;
        s.resize(length); for (char &c : s) c = '0';
    }


    void standardize() {
        while (s.size() > 1 && s.back() == '0') {
            s.pop_back();
        }
        if (s == "0") isNeg = false;
    }

    friend istream& operator>>(istream& is, BigNum& a) {
        string input;
        if (!(is >> input)) return is;

        a.isNeg = false;
        if (input.front() == '-') {
            a.isNeg = true;
            input.erase(input.begin());
        }

        reverse(input.begin(), input.end());
        a.s = input;
        a.standardize();
        return is;
    }

    friend ostream& operator<<(ostream& os, const BigNum& a) {
        if (a.isNeg && !(a.s.size() == 1 && a.s[0] == '0')) {
            os << '-';
        }
        for (int i = (int)a.s.size() - 1; i >= 0; i--) {
            os << a.s[i];
        }
        return os;
    }
};

int compAbs(const BigNum a, const BigNum b) {
    if (a.s.size() != b.s.size()) {
        return (a.s.size() < b.s.size()) ? -1 : 1;
    }
    for (int i = (int)a.s.size() - 1; i >= 0; i--) {
        if (a.s[i] != b.s[i]) {
            return (a.s[i] < b.s[i]) ? -1 : 1;
        }
    }
    return 0;
}

bool operator<(const BigNum a, const BigNum b) {
    if (a.isNeg != b.isNeg) return a.isNeg;
    int cmp = compAbs(a, b);
    if (a.isNeg) return cmp > 0;
    return cmp < 0;
}

bool operator<=(const BigNum a, const BigNum b) {
    if (a.isNeg != b.isNeg) return a.isNeg;
    int cmp = compAbs(a, b);
    if (a.isNeg) return cmp >= 0;
    return cmp <= 0;
}

BigNum addAbs(const BigNum a, const BigNum b) {
    BigNum c;
    c.s.clear();
    int carry = 0;
    size_t n = max(a.s.size(), b.s.size());

    for (size_t i = 0; i < n || carry; i++) {
        int sum = carry;
        if (i < a.s.size()) sum += a.s[i] - '0';
        if (i < b.s.size()) sum += b.s[i] - '0';

        c.s.push_back(char('0' + (sum % BASE)));
        carry = sum / BASE;
    }
    c.standardize();
    return c;
}


BigNum subAbs(const BigNum a, const BigNum b) {
    BigNum c;
    c.s.clear();
    int borrow = 0;
    
    for (size_t i = 0; i < a.s.size(); i++) {
        int diff = (a.s[i] - '0') - borrow - (i < b.s.size() ? (b.s[i] - '0') : 0);
        if (diff < 0) {
            diff += BASE;
            borrow = 1;
        } else {
            borrow = 0;
        }
        c.s.push_back(char('0' + diff));
    }
    c.standardize();
    return c;
}

BigNum add(const BigNum a, const BigNum b) {
    BigNum c;
    if (a.isNeg == b.isNeg) {
        c = addAbs(a, b);
        c.isNeg = a.isNeg;
    } else {
        int cmp = compAbs(a, b);
        if (cmp >= 0) {
            c = subAbs(a, b);
            c.isNeg = a.isNeg;
        } else {
            c = subAbs(b, a);
            c.isNeg = b.isNeg;
        }
    }
    return c;
}

BigNum absMult(const BigNum a, const BigNum b) {
    if (a.s == "0" || b.s == "0") return BigNum();

    vector<int> res(a.s.size() + b.s.size(), 0);

    for (int i = 0; i < a.s.size(); i++) {
        for (int j = 0; j < b.s.size(); j++) {
            res[i + j] += (a.s[i] - '0') * (b.s[j] - '0');
            res[i + j + 1] += res[i + j] / BASE;
            res[i + j] %= BASE;
        }
    }

    BigNum c;
    c.s.clear();
    for (int digit : res) {
        c.s.push_back(char('0' + digit));
    }
    c.standardize();
    return c;
}

BigNum mult(const BigNum a , const BigNum b){
    BigNum c = absMult(a,b);
    c.isNeg = a.isNeg ^ b.isNeg;
    c.standardize();
    return c;
}

pair<BigNum, BigNum> absDiv(const BigNum a, const BigNum b) {
    BigNum rem;
    string res;

    for (int i = (int)a.s.size() - 1; i >= 0; i--) {
        rem.s.insert(rem.s.begin(), a.s[i]);
        rem.standardize();

        int digit = 0;
        while (b <= rem) {
            BigNum z = b;
            z.isNeg = true;
            rem = add(rem, z);
            digit++;
        }

        res += char('0' + digit);
    }

    reverse(res.begin(), res.end());
    BigNum c(res.size());

    for (int i = 0 ; i<res.size() ; i++) c.s[i] = res[i];
    c.standardize();
    rem.standardize();
    return {c , rem};
}


