#include "big_integer.h"

BigInt::BigInt(std::string s) {
    // store as reversed
    std::reverse(s.begin(), s.end());
    std::copy(s.begin(), s.end(), std::back_inserter(this->v));
}

BigInt BigInt::add(BigInt other) {
   int min_length = std::min(other.v.size(), this->v.size()); 
   std::string result = "";
   char a, b, shift, base, carry, offset;
   carry = '0';
   offset = 3*'0';
   for(int i=0; i < min_length; i++){
       a = other.v[i];
       b = this->v[i];
       shift = (a + b + carry) - offset;
       base = shift % 10 + '0';
       carry = shift / 10 + '0';
       result += base;
   }
   // TODO now increment this result 
   // across the remaining larger of the two integers
   result += carry;
   return BigInt(result);
}

void BigInt::print() {
    std::reverse(this->v.begin(), this->v.end());
    for(uint i=0; i < this->v.size(); i++){
        printf("%c", this->v[i]);
    }
    printf("\n");
}

int main() {
    // basic tests
    std::string num1 = "99";
    std::string num2 = "22";
    BigInt a = BigInt(num1);
    BigInt b = BigInt(num2);
    printf("Big Int a)\n");
    a.print();
    printf("Big Int b)\n");
    b.print();

    BigInt c = a.add(b);
    printf("Big Int c)\n");
    c.print();
}
