#pragma once

// This file should be included only from qlua.hpp

// isConnected - определяет состояние подключения клиентского места к серверу
QLUACPP_DETAIL_API_FUNCTION2(unsigned int, // Возвращает «1», если клиентское место подключено и «0», если не подключено. 
                             isConnected)
// getScriptPath - возвращает путь, по которому находится запускаемый скрипт 
QLUACPP_DETAIL_API_FUNCTION2(const char*, // Функция возвращает путь, по которому находится запускаемый скрипт
                             getScriptPath)
// getInfoParam - позволяет получить параметры для информационного окна (Система / О программе / Информационное окно…)
QLUACPP_DETAIL_API_FUNCTION4(const char*, // Функция возвращает значения параметров информационного окна 
                             getInfoParam,
                             const char*, param_name /* Параметр «param_name» может принимать значения, представленные в таблице. 
                                                        Значение параметра Описание 
                                                        VERSION  Версия программы  
                                                        TRADEDATE  Дата торгов  
                                                        SERVERTIME  Время сервера  
                                                        LASTRECORDTIME  Время последней записи  
                                                        NUMRECORDS  Число записей  
                                                        LASTRECORD  Последняя запись  
                                                        LATERECORD  Отставшая запись  
                                                        CONNECTION  Соединение  
                                                        IPADDRESS  IP-адрес сервера  
                                                        IPPORT  Порт сервера  
                                                        IPCOMMENT  Описание соединения  
                                                        SERVER  Описание сервера  
                                                        SESSIONID  Идентификатор сессии  
                                                        USER  Пользователь  
                                                        USERID  ID пользователя  
                                                        ORG  Организация  
                                                        MEMORY  Занято памяти  
                                                        LOCALTIME  Текущее время  
                                                        CONNECTIONTIME  Время на связи  
                                                        MESSAGESSENT  Передано сообщений  
                                                        ALLSENT  Передано всего байт  
                                                        BYTESSENT  Передано полезных байт  
                                                        BYTESPERSECSENT  Передано за секунду  
                                                        MESSAGESRECV  Принято сообщений  
                                                        BYTESRECV  Принято полезных байт  
                                                        ALLRECV  Принято всего байт  
                                                        BYTESPERSECRECV  Принято за секунду  
                                                        AVGSENT  Средняя скорость передачи  
                                                        AVGRECV  Средняя скорость приема  
                                                        LASTPINGTIME  Время последней проверки связи  
                                                        LASTPINGDURATION  Задержка данных при обмене с сервером  
                                                        AVGPINGDURATION  Средняя задержка данных  
                                                        MAXPINGTIME  Время максимальной задержки  
                                                        MAXPINGDURATION  Максимальная задержка данных  
                                                     */
                             )
// message - отображает сообщения в терминале QUIK
QLUACPP_DETAIL_API_FUNCTION6(unsigned int, // Возвращает «nil» при ошибке выполнения или при обнаружении ошибки во входных параметрах. В остальных случаях возвращает «1». 
                             message, 
                             const char*, text, // Строка, отображаемая в окне сообщений терминала QUIK
                             const unsigned int, icon_type)
// message - отображает сообщения в терминале QUIK
QLUACPP_DETAIL_API_FUNCTION4(unsigned int, // Возвращает «nil» при ошибке выполнения или при обнаружении ошибки во входных параметрах. В остальных случаях возвращает «1». 
                             message,
                             const char*, text // Строка, отображаемая в окне сообщений терминала QUIK
                             )
// sleep - приостанавливает выполнение кода скрипта
QLUACPP_DETAIL_API_FUNCTION4(unsigned int, // Время, на которое приостанавливается выполнение, в миллисекундах
                             sleep,
                             int, time // Время, на которое приостанавливается выполнение, в миллисекундах
                             )
// getWorkingFolder - возвращает путь, по которому находится файл info.exe, исполняющий скрипт
QLUACPP_DETAIL_API_FUNCTION2(const char*, getWorkingFolder)
// PrintDbgStr - для вывода отладочной информации 
QLUACPP_DETAIL_API_FUNCTION_VOID3(PrintDbgStr,
                                  const char*, s)

