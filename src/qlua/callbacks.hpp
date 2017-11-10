#pragma once

#include "structs/standalone.hpp"

namespace qlua {
  namespace callback {

    /* These are just names and type signature for future typechecks.
       For now, to install qlua callback just declare appropriate luacpp static function, e.g.:
       LUACPP_STATIC_FUNCTION2(main, my_main_handler_function); // In root namespace
       ::lua::functions::main.register_to_lua(lua_state, my_main_handler_function); // Later in code
     */
    
    struct main {   //  реализация основного потока исполнения в скрипте
      static const char* name() { static const char name[] = "main"; return name; }
      typedef void return_type;
      typedef std::tuple<> args_type;
    };

    struct OnAccountBalance {   //  изменение позиции по счету
      static const char* name() { static const char name[] = "OnAccountBalance"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::account_balance>>> args_type;
    };
    
    struct OnAccountPosition {   //  изменение позиции по счету
      static const char* name() { static const char name[] = "OnAccountPosition"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::account_positions>>> args_type;
    };
    
    struct OnAllTrade {   //  новая обезличенная сделка 
      static const char* name() { static const char name[] = "OnAllTrade"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::all_trades>>> args_type;
    };
    
    struct OnCleanUp {   //  смена торговой сессии
      static const char* name() { static const char name[] = "OnCleanUp"; return name; }
      typedef void return_type;
      typedef std::tuple<> args_type;
    };
    
    struct OnClose {   //  закрытие терминала QUIK или выгрузка файла qlua.dll 
      static const char* name() { static const char name[] = "OnClose"; return name; }
      typedef void return_type;
      typedef std::tuple<> args_type;      
    };
    
    struct OnConnected {   //  установление связи с сервером QUIK 
      static const char* name() { static const char name[] = "OnConnected"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<bool>>> args_type;
    };
    
    struct OnDepoLimit {   //  изменение бумажного лимита
      static const char* name() { static const char name[] = "OnDepoLimit"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::depo_limits>>> args_type;
    };
    
    struct OnDepoLimitDelete {   //  удаление бумажного лимита
      static const char* name() { static const char name[] = "OnDepoLimitDelete"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::depo_limit_delete>>> args_type;
    };
    
    struct OnDisconnected {   //  отключение от сервера QUIK
      static const char* name() { static const char name[] = "OnDisconnected"; return name; }
      typedef void return_type;
      typedef std::tuple<> args_type;
    };
    
    struct OnFirm {   //  получение описания новой фирмы
      static const char* name() { static const char name[] = "OnFirm"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::firms>>> args_type;
    };
    
    struct OnFuturesClientHolding {   //  изменение позиции по срочному рынку
      static const char* name() { static const char name[] = "OnFuturesClientHolding"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::futures_client_holding>>> args_type;
    };
    
    struct OnFuturesLimitChange {   //  изменение ограничений по срочному рынку 
      static const char* name() { static const char name[] = "OnFuturesLimitChange"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::futures_client_limits>>> args_type;
    };
    
    struct OnFuturesLimitDelete {   //  удаление лимита по срочному рынку 
      static const char* name() { static const char name[] = "OnFuturesLimitDelete"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::futures_limit_delete>>> args_type;
    };
    
    struct OnInit {   //  инициализация функции main 
      static const char* name() { static const char name[] = "OnInit"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<std::string>>> args_type;
    };
    
    struct OnMoneyLimit {   //  изменение денежного лимита 
      static const char* name() { static const char name[] = "OnMoneyLimit"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::money_limits>>> args_type;
    };
    
    struct OnMoneyLimitDelete {   //  удаление денежного лимита 
      static const char* name() { static const char name[] = "OnMoneyLimitDelete"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::money_limit_delete>>> args_type;
    };
    
    struct OnNegDeal {   //  новая заявка на внебиржевую сделку или изменение параметров существующей заявки на внебиржевую сделку 
      static const char* name() { static const char name[] = "OnNegDeal"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::neg_deals>>> args_type;
    };
    
    struct OnNegTrade {   //  новая сделка для исполнения или изменение существующей сделки для исполнения 
      static const char* name() { static const char name[] = "OnNegTrade"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::neg_trades>>> args_type;
    };
    
    struct OnOrder {   //  новая заявка или изменение параметров существующей заявки 
      static const char* name() { static const char name[] = "OnOrder"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::orders>>> args_type;
    };
    
    struct OnParam {   //  изменение текущих параметров 
      static const char* name() { static const char name[] = "OnParam"; return name; }
      typedef void return_type;
      typedef std::tuple<
        ::lua::entity<::lua::type_policy<std::string>>,
        ::lua::entity<::lua::type_policy<std::string>>
      > args_type;
    };
    
    struct OnQuote {   //  изменение стакана котировок 
      static const char* name() { static const char name[] = "OnQuote"; return name; }
      typedef void return_type;
      typedef std::tuple<
        ::lua::entity<::lua::type_policy<std::string>>,
        ::lua::entity<::lua::type_policy<std::string>>
      > args_type;
    };
    
    struct OnStop {   //  остановка скрипта из диалога управления 
      static const char* name() { static const char name[] = "OnStop"; return name; }
      typedef int return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<int>>> args_type;
    };
    
    struct OnStopOrder {   //  новая стоп-заявка или изменение параметров существующей стоп-заявки 
      static const char* name() { static const char name[] = "OnStopOrder"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::stop_orders>>> args_type;
    };
    
    struct OnTrade {   //  новая сделка или изменение параметров существующей сделки 
      static const char* name() { static const char name[] = "OnTrade"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::trades>>> args_type;
    };
    
    struct OnTransReply {   //  ответ на транзакцию 
      static const char* name() { static const char name[] = "OnTransReply"; return name; }
      typedef void return_type;
      typedef std::tuple<::lua::entity<::lua::type_policy<table::trans_reply>>> args_type;
    };
  }

}
