#include<catch.hpp>
#include<hello.hpp>

TEST_CASE( " Example ", "[tag]" ){

  SECTION( "it works " ){
    REQUIRE( Hello::say(5) == 5 );
  }

}
