#include <tuple>
#include <string>
using namespace std;

template<typename... Parm>
struct Custom_Struct {
  tuple<Parm...> tpl_data_members;
  unsigned number_of_elements;

  Custom_Struct(Parm... parm) {
    tpl_data_members = make_tuple(parm...);
    number_of_elements = tuple_size<decltype(tpl_data_members)>::value;
  }

  bool operator< (const Custom_Struct<Parm...>& another_key) const {
    return tpl_data_members < another_key.tpl_data_members;
  }

  // copy constructor
  Custom_Struct(const Custom_Struct& another) {
    tpl_data_members = another.tpl_data_members;
  }

  // assignment operator
  Custom_Struct& operator=(const Custom_Struct& another) {
    tpl_data_members = another.tpl_data_members;
  }

  /*!\brief get nth element
   * can get nth element by tie(lvalue_1, lvalue_2, ..) = tpl_data_members;
   */
};

