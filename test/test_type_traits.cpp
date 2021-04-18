#include <type_traits>

#include "gtest/gtest.h"
#include "glog/logging.h"


class TestSTLTypeTraits : public ::testing::Test{};

// type trait提供一种用于处理type属性的办法，它是一个template，可以在编译期间根据一个或者
// 多个template实参产出一个type

template <typename T>
void foo(const T& val){
  if(std::is_void<T>::value){
    LOG(INFO) << "foo() called for a void type"; // 类型void
  }
  if(std::is_integral<T>::value){
    LOG(INFO) << "foo() called for an interger type"; // 整数类型，包括bool, char, char16_t, char32_t, wchar_t
  }
  if(std::is_floating_point<T>::value){
    LOG(INFO) << "foo() called for float point type"; // 浮点类型，包括float,double,long double
  }
  if(std::is_arithmetic<T>::value){
    LOG(INFO) << "foo() called for arithmetic type"; // 整数（包括bool和character）或者浮点数类型
  }
}

TEST_F(TestSTLTypeTraits, test_foo_void){
}
