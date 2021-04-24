#include <iostream>
#include <range/v3/all.hpp>
#include <functional>
#include <vector>

void fill_vector(std::vector<int>& values){

   for(int i = 0;i < 10 ; i++ ){
        (i%2==0)? values.emplace_back(i) : values.emplace_back(-i);
   }

}
int main()
{

    int (*lambda)(int&) = [](int& value)mutable throw()-> int {return !(value>0);};

    std::vector<int> values;

    fill_vector(values);

    auto filtered = values | ranges::view::remove_if(lambda) ;

    for(auto& it : filtered){
        std::cout<<it<<std::endl;
    }
    return 0;
}
