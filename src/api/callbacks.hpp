#pragma once

#include <functional>
#include <string>

#include "api.hpp"
#include "structs/alltrade.hpp"
#include "structs/account_balance.hpp"
#include "structs/account_position.hpp"
#include "structs/transaction.hpp"

namespace qlua {
  
  namespace callback {
    template <typename derived_t>
    struct base {

      base(lua::state& l) {
        l.pushcclosure(derived_t::lua_handler, 0);
        l.setfield(LUA_GLOBALSINDEX, derived_t::name().c_str());
      }

      void remove(lua::state& l) {
        l.pushnil();
        l.setfield(LUA_GLOBALSINDEX, derived_t::name().c_str());
      }
    };

    struct main : public base<main> {
      typedef main type;
      typedef void (*handler_type) (lua::state& l);
      
      static std::string name() { return "main"; }

      static int lua_handler(lua_State* L) {
        lua::state l(L);
        handler_(l);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);

      main(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };

    struct OnAccountBalance : public base<OnAccountBalance> {
      typedef OnAccountBalance type;
      typedef void (*handler_type) (lua::state& l,
                                    const account_balance&);
      
      static std::string name() { return "OnAccountBalance"; }
      
      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto data = l.get_value<qlua::account_balance>();
        handler_(l, data);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);

      OnAccountBalance(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };
    
    struct OnAccountPosition : public base<OnAccountPosition> {
      typedef OnAccountPosition type;
      typedef void (*handler_type) (lua::state& l,
                                    const account_position&);
      
      static std::string name() { return "OnAccountPosition"; }
      
      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto data = l.get_value<qlua::account_position>();
        handler_(l, data);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);

      OnAccountPosition(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };
    
    struct OnAllTrade : public base<OnAllTrade> {
      typedef OnAllTrade type;
      typedef void (*handler_type) (lua::state&,
                                    const qlua::alltrade&);
      
      static std::string name() { return "OnAllTrade"; }

      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto data = l.get_value<qlua::alltrade>();
        handler_(l, data);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);
      OnAllTrade(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };    

    struct OnCleanUp : public base<OnCleanUp> {
      typedef OnCleanUp type;
      typedef void (*handler_type) (lua::state& l);
      
      static std::string name() { return "OnCleanUp"; }

      static int lua_handler(lua_State* L) {
        lua::state l(L);
        handler_(l);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);

      OnCleanUp(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };

    struct OnClose : public base<OnClose> {
      typedef OnClose type;
      typedef void (*handler_type) (lua::state& l);
      
      static std::string name() { return "OnClose"; }

      static int lua_handler(lua_State* L) {
        lua::state l(L);
        handler_(l);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);

      OnClose(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };

    struct OnConnected : public base<OnConnected> {     
      typedef OnConnected type;
      typedef void (*handler_type) (lua::state&,
                                    bool);
      
      static std::string name() { return "OnConnected"; }    
      
      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto script_path = l.get_value<bool>(-1);
        handler_(l, script_path);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);
      
      OnConnected(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };    

    struct OnDepoLimit : public base<OnDepoLimit> {     
      static std::string name() { return "OnDepoLimit"; }    
    };    

    struct OnDepoLimitDelete : public base<OnDepoLimitDelete> {     
      static std::string name() { return "OnDepoLimitDelete"; }    
    };    

    struct OnDisconnected : public base<OnDisconnected> {
      typedef OnDisconnected type;
      typedef void (*handler_type) (lua::state& l);
      
      static std::string name() { return "OnDisconnected"; }

      static int lua_handler(lua_State* L) {
        lua::state l(L);
        handler_(l);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);

      OnDisconnected(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };

    struct OnFirm : public base<OnFirm> {     
      static std::string name() { return "OnFirm"; }    
    };    

    struct OnFuturesClientHolding : public base<OnFuturesClientHolding> {     
      static std::string name() { return "OnFuturesClientHolding"; }    
    };    

    struct OnFuturesLimitChange : public base<OnFuturesLimitChange> {     
      static std::string name() { return "OnFuturesLimitChange"; }    
    };    

    struct OnFuturesLimitDelete : public base<OnFuturesLimitDelete> {     
      static std::string name() { return "OnFuturesLimitDelete"; }    
    };    

    struct OnInit : public base<OnInit> {     
      typedef OnInit type;
      typedef void (*handler_type) (lua::state&,
                                    const char*);
      
      static std::string name() { return "OnInit"; }    
      
      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto script_path = l.get_value<const char*>(-1);
        handler_(l, script_path);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);
      
      OnInit(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };    

    struct OnMoneyLimit : public base<OnMoneyLimit> {     
      static std::string name() { return "OnMoneyLimit"; }    
    };    

    struct OnMoneyLimitDelete : public base<OnMoneyLimitDelete> {     
      static std::string name() { return "OnMoneyLimitDelete"; }    
    };    

    struct OnNegDeal : public base<OnNegDeal> {     
      static std::string name() { return "OnNegDeal"; }    
    };    

    struct OnNegTrade : public base<OnNegTrade> {     
      static std::string name() { return "OnNegTrade"; }    
    };    

    struct OnOrder : public base<OnOrder> {     
      static std::string name() { return "OnOrder"; }    
    };    

    struct OnParam : public base<OnParam> {     
      static std::string name() { return "OnParam"; }    
    };    

    struct OnQuote : public base<OnQuote> {
      typedef OnQuote type;
      typedef void (*handler_type) (lua::state&,
                                    const char*,
                                    const char*);
      
      static std::string name() { return "OnQuote"; }
      
      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto class_code = l.get_value<const char*>(-2);
        auto sec_code = l.get_value<const char*>(-1);
        handler_(l, class_code, sec_code);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);
      
      OnQuote(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };    

    struct OnStop : public base<OnStop> {     
      typedef OnStop type;
      typedef int (*handler_type) (lua::state& l);
      
      static std::string name() { return "OnStop"; }

      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto rslt = handler_(l);
        l.pushnumber(rslt);
        return 1;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);

      OnStop(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };    

    struct OnStopOrder : public base<OnStopOrder> {     
      static std::string name() { return "OnStopOrder"; }    
    };    

    struct OnTrade : public base<OnTrade> {     
      static std::string name() { return "OnTrade"; }    
    };    

    struct OnTransReply : public base<OnTransReply> {     
      static std::string name() { return "OnTransReply"; }    
      typedef OnTransReply type;
      typedef void (*handler_type) (lua::state&,
                                    const transaction_reply& reply);
      
      static int lua_handler(lua_State* L) {
        lua::state l(L);
        auto trans_reply = l.get_value<transaction_reply>(-1);
        handler_(l, trans_reply);
        return 0;
      }
      
    private:
      friend type& api::set_callback<type>(handler_type);
      
      OnTransReply(lua::state& l, handler_type handler) :
        base(l) {
        handler_ = handler;
      }
      
      static handler_type handler_;
    };    
    
  }
}
