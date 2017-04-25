#pragma once

namespace qlua {
  namespace callback {
    struct main {   //  реализация основного потока исполнения в скрипте 
      typedef std::function<void(void)> signature;
    };

    struct OnAccountBalance {   //  изменение позиции по счету
      typedef std::function<void(::lua::entity<::qlua::table::account_balance)>> signature;
    };
    
    struct OnAccountPosition {   //  изменение позиции по счету
      typedef std::function<void(::lua::entity<::qlua::table::account_positions)>> signature;
    };
    
    struct OnAllTrade {   //  новая обезличенная сделка 
      typedef std::function<void(::lua::entity<::qlua::table::all_trade)>> signature;
    };
    
    struct OnCleanUp {   //  смена торговой сессии
      typedef std::function<void(void)> signature;
    };
    
    struct OnClose {   //  закрытие терминала QUIK или выгрузка файла qlua.dll 
      typedef std::function<void(void)> signature;      
    };
    
    struct OnConnected {   //  установление связи с сервером QUIK 
      typedef std::function<void(::lua::entity<bool>)> signature;
    };
    
    struct OnDepoLimit {   //  изменение бумажного лимита
      typedef std::function<void(::lua::entity<::qlua::table::depo_limit>)> signature;
    };
    
    struct OnDepoLimitDelete {   //  удаление бумажного лимита
      typedef std::function<void(::lua::entity<::qlua::table::depo_limit_delete>)> signature;
    };
    
    struct OnDisconnected {   //  отключение от сервера QUIK
      typedef std::function<void(void)> signature;
    };
    
    struct OnFirm {   //  получение описания новой фирмы
      typedef std::function<void(::lua::entity<::qlua::table::firms>)> signature;
    };
    
    struct OnFuturesClientHolding {   //  изменение позиции по срочному рынку
      typedef std::function<void(::lua::entity<::qlua::table::future_client_holding)> signature;
    };
    
    struct OnFuturesLimitChange {   //  изменение ограничений по срочному рынку 
      typedef std::function<void(::lua::entity<::qlua::table::futures_client_limits)> signature;
    };
    
    struct OnFuturesLimitDelete {   //  удаление лимита по срочному рынку 
      typedef std::function<void(::lua::entity<::qlua::table::futures_limit_delete)> signature;
    };
    
    struct OnInit {   //  инициализация функции main 
      typedef std::function<void(std::string)> signature;
    };
    
    struct OnMoneyLimit {   //  изменение денежного лимита 
      typedef std::function<void(::lua::entity<::qlua::table::money_limits>)> signature;
    };
    
    struct OnMoneyLimitDelete {   //  удаление денежного лимита 
      typedef std::function<void(::lua::entity<::qlua::table::money_limit_delete>)> signature;
    };
    
    struct OnNegDeal {   //  новая заявка на внебиржевую сделку или изменение параметров существующей заявки на внебиржевую сделку 
      typedef std::function<void(::lua::entity<::qlua::table::neg_deal>)> signature;
    };
    
    struct OnNegTrade {   //  новая сделка для исполнения или изменение существующей сделки для исполнения 
      typedef std::function<void(::lua::entity<::qlua::table::neg_trade>)> signature;
    };
    
    struct OnOrder {   //  новая заявка или изменение параметров существующей заявки 
      typedef std::function<void(::lua::entity<::qlua::table::orders)> signature;
    };
    
    struct OnParam {   //  изменение текущих параметров 
      typedef std::function<void(::lua::entity<std::string>, ::lua::entity<std::string>)> signature;
    };
    
    struct OnQuote {   //  изменение стакана котировок 
      typedef std::function<void(::lua::entity<std::string>, ::lua::entity<std::string>)> signature;
    };
    
    struct OnStop {   //  остановка скрипта из диалога управления 
      typedef std::function<int(::lua::entity<int>)> signature;
    };
    
    struct OnStopOrder {   //  новая стоп-заявка или изменение параметров существующей стоп-заявки 
      typedef std::function<void(::lua::entity<::qlua::tables::stop_orders>)> signature;
    };
    
    struct OnTrade {   //  новая сделка или изменение параметров существующей сделки 
      typedef std::function<void(::lua::entity<::qlua::tables::trades)> signature;
    };
    
    struct OnTransReply {   //  ответ на транзакцию 
      typedef std::function<void()> signature;
    };
    
    
  }
}
