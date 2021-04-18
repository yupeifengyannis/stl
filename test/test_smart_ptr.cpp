#include <memory>
#include <vector>
#include <string>
#include <iostream>

#include <gtest/gtest.h>
#include <glog/logging.h>

using namespace std;

class TestSmartPtr : public ::testing::Test{};

TEST_F(TestSmartPtr, simple_use){
  shared_ptr<string> pNico(new string("nico"));
  // shared_ptr<string> pNico = new string("nico"); // 这种需要隐式转换的是不被允许的
  shared_ptr<string> pNico1 = make_shared<string>("nico1"); // 可以使用make_shared
  shared_ptr<string> pJutta(new string("jutta"));
  (*pNico)[0] = 'N';
  pJutta->replace(0, 1, "J");
  vector<shared_ptr<string>> whoMadeCoffee;
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);
  string out_str;
  for(auto ptr : whoMadeCoffee){
    out_str += *ptr + " ";
  }
  LOG(INFO) << out_str;
  
  *pNico = "john";
  EXPECT_TRUE(*whoMadeCoffee[2] == "john");
  EXPECT_TRUE(*whoMadeCoffee[4] == "john");
  EXPECT_EQ(pJutta.use_count(), 4); // 因为有四个shared_ptr都在引用着
  EXPECT_EQ(pNico.use_count(), 3);
  
  shared_ptr<string> new_ptr(std::move(pNico1)); // 这里我们采用了移动语义，所以引用计数不会增加
  EXPECT_EQ(new_ptr.use_count(), 1);
}
TEST_F(TestSmartPtr, user_defined_deleter){
  shared_ptr<string> pNico(new string("nico"),
      [](string* ptr){
        LOG(INFO) << "delete " << *ptr;
        delete ptr;
      });
}





