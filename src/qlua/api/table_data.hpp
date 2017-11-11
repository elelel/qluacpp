#pragma once


// getItem - Функция возвращает таблицу Lua, содержащую информацию о данных из строки с номером «Index» из таблицы с именем «TableName». 
template <typename Table>
void getItem(unsigned int Index,
             std::function<void(const ::lua::entity<::lua::type_policy<Table>>&)> lambda) const {
  auto f = [&lambda] (const ::lua::state& s) {
    auto v = s.at<Table>(-1);
    lambda(v);
    return 1;
  };
  l_.call_and_apply(f, 1, "getItem", ::qlua::table::detail::name_for_type<Table>::value(), Index);                                     
}

/* TODO: tuple
// getOrderByNumber - Функция возвращает таблицу Lua, содержащую описание параметров Таблицы заявок и индекс заявки в хранилище терминала. 
QLUACPP_DETAIL_API_FUNCTION_TUPLE2_7(::qlua::table::orders, unsigned int,
getOrderByNumber,
const char*, class_code,
unsigned int, order_id
)
*/

// getNumberOf - Функция возвращает количество записей в таблице «TableName». 
QLUACPP_DETAIL_API_FUNCTION4(unsigned int,
                             getNumberOf,
                             const char*, TableName
                             );

template <typename Table>
unsigned int getNumberOf() const {
  return getNumberOf(::qlua::table::detail::name_for_type<Table>::value());
}
  

/* TODO:
// SearchItems - Функция позволяет реализовать быструю выборку элементов из хранилища терминала и возвращает таблицу с индексами элементов, удовлетворяющих условию поиска. 
QLUACPP_DETAIL_API_FUNCTION(TABLE,
SearchItems,
const char*, table_name, // строка, определяющая таблицу для поиска; 
unsigned int, start_index, // индекс стартового элемента для поиска; 
unsigned int, end_index, // индекс конечного элемента поиска; 
FUNCTION fn – функция обратного вызова, возвращающая одно из следующих значений: 
true – текущий индекс учитывается в результате; 
false – текущий индекс не учитывается в результате; 
nil – поиск прерывается, функция SearchItems возвращает таблицу с индексами, найденными ранее, включая текущий индекс.

)

QLUACPP_DETAIL_API_FUNCTION(TABLE,
SearchItems,
const char* table_name, NUMBER start_index, NUMBER end_index, FUNCTION fn , const char* params
)  
*/
