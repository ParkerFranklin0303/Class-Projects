// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main() {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left == 0);
        assert(right == 0);
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(1);
        bigint right(0);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == 1);
        assert(right == 0);
        assert(result == 1);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(1);
        bigint right(1);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == 1);
        assert(right == 1);
        assert(result == 2);
    }

    {
        //------------------------------------------------------
        // Tests for rollover of integer values during addition.
        // Setup fixture
        bigint left(19);
        bigint right(18);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == 19);
        assert(right == 18);
        assert(result == 37);
    }

    {
        //------------------------------------------------------
        // Tests for addition of 10-digit bigints.
        // Setup fixture
        bigint left(9999999999);
        bigint right(1);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == 9999999999);
        assert(right == 1);
        assert(result == 10000000000);
    }

    {
        //------------------------------------------------------
        // Tests for bigint value exceeding max int of 32 bit system.
        // Setup fixture
        bigint left(2147483646);
        bigint right(1);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == 2147483646);
        assert(right == 1);
        assert(result == 2147483647);
    }

    {
        //------------------------------------------------------
        // Tests for bigint value exceeding max int of 64 bit system.
        // Setup fixture
        bigint left(9223372036854775806);
        bigint right(1);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == 9223372036854775806);
        assert(right == 1);
        assert(result == 9223372036854775807);
    }

    {
        //------------------------------------------------------
        // Tests for const char array constructor.
        // Setup fixture
        bigint left("0");
        bigint right("1");
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == "0");
        assert(right == "1");
        assert(result == "1");
    }

    {
        //------------------------------------------------------
        // Tests for addition of 10-digit character bigints.
        // Setup fixture
        bigint left("9999999999");
        bigint right("1");
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == "9999999999");
        assert(right == "1");
        assert(result == "10000000000");
    }

    {
        //------------------------------------------------------
        // Tests boundary of midrange 100-digit bigints.
        // Setup fixture
        bigint left("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
        bigint right("1");
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
        assert(right == "1");
        assert(result == "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }

    {
        //------------------------------------------------------
        // Tests boundary of 200-digit character bigints.
        // Setup fixture
        bigint left("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"); //199 Characters.
        bigint right("1");
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
        assert(right == "1");
        assert(result == "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"); //200 Characters.
    }
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}
