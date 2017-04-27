#pragma once

// добавляет колонки в таблицу
QLUACPP_DETAIL_API_FUNCTION14(unsigned int, AddColumn,
                              const unsigned int, t_id,
                              const unsigned int, iCode,
                              const char*, name,
                              const bool, is_default,
                              const unsigned int, par_type,
                              const unsigned int, width)
/*
AllocTable // создает структуру, описывающую таблицу 
Clear // удаляет содержимое таблицы 
CreateWindow // создает окно таблицы 
DeleteRow // удаляет строку из таблицы 
DestroyTable // закрывает окно таблицы 
InsertRow // добавляет строку в таблицу 
IsWindowClosed // возвращает «true», если закрыто окно с таблицей 
GetCell // позволяет получить данные из ячейки таблицы 
GetTableSize // получает количество строк и столбцов 
GetWindowCaption // получает текущий заголовок окна 
GetWindowRect // получает координаты верхнего левого и нижнего правого угла окна, содержащего таблицу 
Highlight // подсвечивает выбранный диапазон ячеек с плавным «затуханием» для таблицы 
RGB // преобразовывает компоненты RGB (red, green, blue) в одно число для дальнейшего использования в функции SetColor 
SetCell // задает значение для ячейки в таблице 
SetColor // устанавливает цвет ячейки, столбца или строки для таблицы 
SetTableNotificationCallback // задает функцию обратного вызова для обработки событий в таблице 
SetWindowCaption // задает заголовок окна 
SetWindowPos // устанавливает положение окна с таблицей 
SetSelectedRow // выделяет определенную строку таблицы 
*/
