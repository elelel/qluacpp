#pragma once

// Subscribe_Level_II_Quotes - заказывает на сервер получение стакана по указанному классу и бумаге.
QLUACPP_DETAIL_API_FUNCTION6(bool, // В случае успешного завершения функция возвращает «true». 
                             Subscribe_Level_II_Quotes,
                             const char*, class_code, // код класса; 
                             const char*, sec_code // код бумаги. 
                             )
// Unsubscribe_Level_II_Quotes - отменяет заказ на получение с сервера стакана по указанному классу и бумаге.
QLUACPP_DETAIL_API_FUNCTION6(bool, // В случае успешного завершения функция возвращает «true». 
                             Unsubscribe_Level_II_Quotes,
                             const char*, class_code, // код класса; 
                             const char*, sec_code // код бумаги. 
                             )
// IsSubscribed_Level_II_Quotes - позволяет узнать, заказан ли с сервера стакан по указанному классу и бумаге. 
QLUACPP_DETAIL_API_FUNCTION6(bool, // Функция возвращает «true», если стакан по классу class_code и бумаге sec_code уже заказан. 
                             IsSubscribed_Level_II_Quotes,
                             const char*, class_code, // код класса; 
                             const char*, sec_code // код бумаги. 
                             )
