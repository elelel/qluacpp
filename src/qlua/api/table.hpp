#pragma once

// AddColumn - добавляет колонки в таблицу
QLUACPP_DETAIL_API_FUNCTION14(unsigned int, // Функция возвращает «1», если колонка в таблицу добавлена, иначе – «0».
                              AddColumn, 
                              const unsigned int, t_id,
                              const unsigned int, iCode, // код параметра, выводимого в колонке 
                              const char*, name, // название колонки
                              const bool, is_default, // параметр не используется
                              const unsigned int, par_type, /* тип данных в колонке, одна из следующих констант: 
                                                               QTABLE_INT_TYPE – целое число, 
                                                               QTABLE_DOUBLE_TYPE – число с плавающей точкой, 
                                                               QTABLE_INT64_TYPE – 64-битное целое число, 
                                                               QTABLE_CACHED_STRING_TYPE – кэшируемая строка, 
                                                               QTABLE_TIME_TYPE – время, 
                                                               QTABLE_DATE_TYPE – дата, 
                                                               QTABLE_STRING_TYPE – строка */
                              const unsigned int, width // ширина в условных единицах
                              )

// AllocTable - создает структуру, описывающую таблицу
QLUACPP_DETAIL_API_FUNCTION2(unsigned int, // Функция возвращает целочисленный идентификатор таблицы, предназначенный для совершения с ней дальнейших операций. 
                             AllocTable
                             )
// Clear - удаляет содержимое таблицы 
QLUACPP_DETAIL_API_FUNCTION4(bool, // Функция возвращает «true» в случае успешного завершения, иначе – «false». 
                             Clear,
                             const unsigned int, t_id
                             )

// CreateWindow - создает окно таблицы
QLUACPP_DETAIL_API_FUNCTION4(unsigned int, // Функция возвращает «1» при успешном создании окна, иначе – «0». 
                             CreateWindow,
                             const unsigned int, t_id
                             )

// DeleteRow - удаляет строку из таблицы
QLUACPP_DETAIL_API_FUNCTION6(bool, // В случае успешного выполнения возвращает «true», иначе – «false». 
                             DeleteRow, 
                             const unsigned int, t_id,
                             const unsigned int, key
                             )
// DestroyTable - закрывает окно таблицы
QLUACPP_DETAIL_API_FUNCTION4(bool, // В случае успешного выполнения возвращает «true», иначе – «false». 
                             DestroyTable,
                             const unsigned int, t_id
                             )
// InsertRow - добавляет строку в таблицу
QLUACPP_DETAIL_API_FUNCTION6(int, // Функция возвращает номер добавленной строки при успешном выполнении, иначе – «-1».
                             InsertRow,
                             const unsigned int, t_id,
                             const unsigned int, key
                             )
// IsWindowClosed - возвращает «true», если закрыто окно с таблицей
QLUACPP_DETAIL_API_FUNCTION4(bool, // Функция возвращает «nil» в случае неуспешного завершения. 
                             IsWindowClosed,
                             const unsigned int, t_id
                             )

template <typename T>
T GetCell(const unsigned int t_id,
          const unsigned int key,
          const unsigned int code) const {
  typedef std::tuple<T> return_type;                
  return std::get<0>(l_.call<return_type>(GetCell, t_id, key, code));
}                                                             

// GetTableSize - получает количество строк и столбцов
QLUACPP_DETAIL_API_FUNCTION_TUPLE2_5(int, int,
                                     GetTableSize,
                                     const unsigned int, t_id
                                     )

// GetWindowCaption - получает текущий заголовок окна
QLUACPP_DETAIL_API_FUNCTION4(const char*,
                             GetWindowCaption,
                             const unsigned int, t_id
                             )
// GetWindowRect - получает координаты верхнего левого и нижнего правого угла окна, содержащего таблицу
QLUACPP_DETAIL_API_FUNCTION_TUPLE4_7(int, int, int, int, // Функция возвращает координаты верхнего левого и нижнего правого угла окна, содержащего таблицу «t_id». 
                                   GetWindowRect,
                                   const unsigned int, t_id
                                   )

// Highlight - подсвечивает выбранный диапазон ячеек с плавным «затуханием» для таблицы
QLUACPP_DETAIL_API_FUNCTION14(bool,
                              Highlight,
                              const unsigned int, t_id,
                              const unsigned int, row,
                              const unsigned int, col,
                              const unsigned int, b_color, // цвет фона
                              const unsigned int, f_color, // цвет текста
                              const unsigned int, timeout // время подсветки, в миллисекундах
                              )

// RGB - преобразовывает компоненты RGB в одно число для дальнейшего использования в функции SetColor
QLUACPP_DETAIL_API_FUNCTION8(unsigned int,
                             RGB,
                             const unsigned int, red,
                             const unsigned int, green,
                             const unsigned int, blue)

// SetCell - задает значение для ячейки в таблице
QLUACPP_DETAIL_API_FUNCTION10(bool,
                              SetCell,
                              const unsigned int, t_id,
                              const unsigned int, key,
                              const unsigned int, code,
                              const char*, text // задает строковое представление значение параметра «value». 
                              )

// SetCell - задает значение для ячейки в таблице
QLUACPP_DETAIL_API_FUNCTION12(bool,
                              SetCell,
                              const unsigned int, t_id,
                              const unsigned int, key,
                              const unsigned int, code,
                              const char*, text, // задает строковое представление значение параметра «value». 
                              const double, value // Параметр «value» необязательный и по умолчанию равен «0». Для столбцов со строковыми типами данных параметр «value» не задается. 
                              )

// SetColor - устанавливает цвет ячейки, столбца или строки для таблицы
QLUACPP_DETAIL_API_FUNCTION16(bool,
                              SetColor,
                              const unsigned int, t_id,
                              const unsigned int, row,
                              const unsigned int, col,
                              const unsigned int, b_color, // цвет фона
                              const unsigned int, f_color, // цвет текста
                              const int, sel_b_color, // цвет фона выделенной ячейки
                              const int, sel_f_color /* цвет текста выделенной ячейки.
                                                        В зависимости от переданных параметров row и col можно менять цвет всей таблицы, столбца, строки и отдельной ячейки. 

                                                        Если в качестве цвета задана константа QTABLE_DEFAULT_COLOR, то используется цвет, заданный в цветовой схеме операционной системе Windows. 

                                                        При работе функции используется константа QTABLE_NO_INDEX, равная «-1». 
                                                     */
                              )

/* TODO
// SetTableNotificationCallback - задает функцию обратного вызова для обработки событий в таблице
QLUACPP_DETAIL_API_FUNCTION(NUMBER,
SetTableNotificationCallback,
unsigned int, t_id, // идентификатор таблицы
FUNCTION f_cb, // функция обратного вызова для обработки событий в таблице
) */

// SetWindowCaption - задает заголовок окна
QLUACPP_DETAIL_API_FUNCTION6(bool, // В случае успешного выполнения возвращает «true», иначе – «false». 
                             SetWindowCaption,
                             const unsigned int, t_id,
                             const char*, str
                             )

// SetWindowPos - устанавливает положение окна с таблицей
QLUACPP_DETAIL_API_FUNCTION12(bool, // В случае успешного выполнения возвращает «true», иначе – «false». 
                              SetWindowPos,
                              const unsigned int, t_id,
                              const int, x,
                              const int, y,
                              const int, dx,
                              const int, dy
                              )

// SetSelectedRow - выделяет определенную строку таблицы 
QLUACPP_DETAIL_API_FUNCTION6(int, // В случае успешного завершения функция возвращает номер выделенной строки, иначе – «-1». 
                             SetSelectedRow,
                             const unsigned int, table_id, // идентификатор таблицы
                             const int, row // номер строки. Если задано значение row=-1, то выделяется последняя видимая строка в таблице.
                             )
