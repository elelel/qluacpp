#pragma once
namespace qlua {
  namespace current_trades {

    template <typename derived_t, typename value_t>
    struct id_base {
      typedef value_t value_type;
      static const std::string name() { return derived_t::name(); };
    };

    
    namespace param {

      struct STATUS : public id_base<STATUS, char*> {
        static const std::string name() { return "STATUS"; };
      };
      
      struct LOTSIZE : public id_base<LOTSIZE, double> {
        static const std::string name() { return "LOTSIZE"; };
      };

      struct BID : public id_base<BID, double> {
        static const std::string name() { return "BID"; };
      };
      
      struct BIDDEPTH : public id_base<BIDDEPTH, double> {
        static const std::string name() { return "BIDDEPTH"; };
      };
      
      struct BIDDEPTHT : public id_base<BIDDEPTHT, double> {
        static const std::string name() { return "BIDDEPTHT"; };
      };
      
      struct NUMBIDS : public id_base<NUMBIDS, double> {
        static const std::string name() { return "NUMBIDS"; };
      };
      
      struct OFFER : public id_base<OFFER, double> {
        static const std::string name() { return "OFFER"; };
      };
      
      struct OFFERDEPTH : public id_base<OFFERDEPTH, double> {
        static const std::string name() { return "OFFERDEPTH"; };
      };
      
      struct OFFERDEPTHT : public id_base<OFFERDEPTHT, double> {
        static const std::string name() { return "OFFERDEPTHT"; };
      };
      
      struct NUMOFFERS : public id_base<NUMOFFERS, double> {
        static const std::string name() { return "NUMOFFERS"; };
      };
      
      struct OPEN : public id_base<OPEN, double> {
        static const std::string name() { return "OPEN"; };
      };
      
      struct HIGH : public id_base<HIGH, double> {
        static const std::string name() { return "HIGH"; };
      };
      
      struct LOW : public id_base<LOW, double> {
        static const std::string name() { return "LOW"; };
      };
      
      struct LAST : public id_base<LAST, double> {
        static const std::string name() { return "LAST"; };
      };
      
      struct CHANGE : public id_base<CHANGE, double> {
        static const std::string name() { return "QTY"; };
      };

      // TODO: Check return type
      struct TIME : public id_base<TIME, char*> {
        static const std::string name() { return "TIME"; };
      };
      
      struct VOLTODAY : public id_base<VOLTODAY, double> {
        static const std::string name() { return "VOLTODAY"; };
      };
      
      struct VALTODAY : public id_base<VALTODAY, double> {
        static const std::string name() { return "VALTODAY"; };
      };
      
      struct TRADINGSTATUS : public id_base<TRADINGSTATUS, char*> {
        static const std::string name() { return "TRADINGSTATUS"; };
      };
      
      struct VALUE : public id_base<VALUE, double> {
        static const std::string name() { return "VALUE"; };
      };
      
      struct WAPRICE : public id_base<WAPRICE, double> {
        static const std::string name() { return "WAPRICE"; };
      };
      
      struct HIGHBID : public id_base<HIGHBID, double> {
        static const std::string name() { return "HIGHBID"; };
      };
      
      struct LOWOFFER : public id_base<LOWOFFER, double> {
        static const std::string name() { return "LOWOFFER"; };
      };
      
      struct NUMTRADES : public id_base<NUMTRADES, double> {
        static const std::string name() { return "NUMTRADES"; };
      };
      
      struct PREVPRICE : public id_base<PREVPRICE, double> {
        static const std::string name() { return "PREVPRICE"; };
      };
      
      struct PREVWAPRICE : public id_base<PREVWAPRICE, double> {
        static const std::string name() { return "PREVWAPRICE"; };
      };
      
      struct CLOSEPRICE : public id_base<CLOSEPRICE, double> {
        static const std::string name() { return "CLOSEPRICE"; };
      };
      
      struct LASTCHANGE : public id_base<LASTCHANGE, double> {
        static const std::string name() { return "LASTCHANGE"; };
      };
      
      struct PRIMARYDIST : public id_base<PRIMARYDIST, char*> {
        static const std::string name() { return "PRIMARYDIST"; };
      };
      
      struct ACCRUEDINT : public id_base<ACCRUEDINT, double> {
        static const std::string name() { return "ACCRUEDINT"; };
      };
      
      struct YIELD : public id_base<YIELD, double> {
        static const std::string name() { return "YIELD"; };
      };
      
      struct COUPONVALUE : public id_base<COUPONVALUE, double> {
        static const std::string name() { return "COUPONVALUE"; };
      };
      
      struct YIELDATPREVWAPRICE : public id_base<YIELDATPREVWAPRICE, double> {
        static const std::string name() { return "YIELDATPREVWAPRICE"; };
      };
      
      struct PRICEMINUSPREVWAPRICE : public id_base<PRICEMINUSPREVWAPRICE, double> {
        static const std::string name() { return "PRICEMINUSPREVWAPRICE"; };
      };
      
      struct CLOSEYIELD : public id_base<CLOSEYIELD, double> {
        static const std::string name() { return "CLOSEYIELD"; };
      };
      
      struct CURRENTVALUE : public id_base<CURRENTVALUE, double> {
        static const std::string name() { return "CURRENTVALUE"; };
      };
      
      struct LASTVALUE : public id_base<LASTVALUE, double> {
        static const std::string name() { return "LASTVALUE"; };
      };
      
      struct LASTTOPREVSTLPRC : public id_base<LASTTOPREVSTLPRC, double> {
        static const std::string name() { return "LASTTOPREVSTLPRC"; };
      };
      
      struct PREVSETTLEPRICE : public id_base<PREVSETTLEPRICE, double> {
        static const std::string name() { return "PREVSETTLEPRICE"; };
      };
      
      struct PRICEMVTLIMIT : public id_base<PRICEMVTLIMIT, double> {
        static const std::string name() { return "PRICEMVTLIMIT"; };
      };
      
      struct PRICEMVTLIMIT1 : public id_base<PRICEMVTLIMIT1, double> {
        static const std::string name() { return "PRICEMVTLIMIT1"; };
      };
      
      struct MAXOUTVOLUME : public id_base<MAXOUTVOLUME, double> {
        static const std::string name() { return "MAXOUTVOLUME"; };
      };
      
      struct PRICEMAX : public id_base<PRICEMAX, double> {
        static const std::string name() { return "PRICEMAX"; };
      };
      
      struct PRICEMIN : public id_base<PRICEMIN, double> {
        static const std::string name() { return "PRICEMIN"; };
      };
      
      struct NEGVALTODAY : public id_base<NEGVALTODAY, double> {
        static const std::string name() { return "NEGVALTODAY"; };
      };
      
      struct NEGNUMTRADES : public id_base<NEGNUMTRADES, double> {
        static const std::string name() { return "NEGNUMTRADES"; };
      };
      
      struct NUMCONTRACTS : public id_base<NUMCONTRACTS, double> {
        static const std::string name() { return "NUMCONTRACTS"; };
      };

      // TODO: Check return type
      struct CLOSETIME : public id_base<CLOSETIME, char*> {
        static const std::string name() { return "CLOSETIME"; };
      };

      struct OPENVAL : public id_base<OPENVAL, double> {
        static const std::string name() { return "OPENVAL"; };
      };
      
      struct CHNGOPEN : public id_base<CHNGOPEN, double> {
        static const std::string name() { return "CHNGOPEN"; };
      };
      
      struct CHNGCLOSE : public id_base<CHNGCLOSE, double> {
        static const std::string name() { return "CHNGCLOSE"; };
      };
      
      struct BUYDEPO : public id_base<BUYDEPO, double> {
        static const std::string name() { return "BUYDEPO"; };
      };
      
      struct SELLDEPO : public id_base<SELLDEPO, double> {
        static const std::string name() { return "SELLDEPO"; };
      };

      // TODO: Check return type
      struct CHANGETIME : public id_base<CHANGETIME, char*> {
        static const std::string name() { return "CHANGETIME"; };
      };
      
      struct SELLPROFIT : public id_base<SELLPROFIT, double> {
        static const std::string name() { return "SELLPROFIT"; };
      };
      
      struct BUYPROFIT : public id_base<BUYPROFIT, double> {
        static const std::string name() { return "BUYPROFIT"; };
      };
      
      struct TRADECHANGE : public id_base<TRADECHANGE, double> {
        static const std::string name() { return "TRADECHANGE"; };
      };
      
      struct FACEVALE : public id_base<FACEVALE, double> {
        static const std::string name() { return "FACEVAL"; };
      };
      
      struct MARKETPRICE : public id_base<MARKETPRICE, double> {
        static const std::string name() { return "MARKETPRICE"; };
      };
      
      struct MARKETPRICETODAY : public id_base<MARKETPRICETODAY, double> {
        static const std::string name() { return "MARKETPRICETODAY"; };
      };
      
      struct NEXTCOUPON : public id_base<NEXTCOUPON, double> {
        static const std::string name() { return "NEXTCOUPON"; };
      };
      
      struct BUYBACKPRICE : public id_base<BUYBACKPRICE, double> {
        static const std::string name() { return "BUYBACKPRICE"; };
      };
      
      struct BUYBACKDATE : public id_base<BUYBACKDATE, double> {
        static const std::string name() { return "BUYBACKDATE"; };
      };
      
      struct ISSUESIZE : public id_base<ISSUESIZE, double> {
        static const std::string name() { return "ISSUESIZE"; };
      };
      
      struct PREVDATE : public id_base<PREVDATE, double> {
        static const std::string name() { return "PREVDATE"; };
      };
      
      struct DURATION : public id_base<DURATION, double> {
        static const std::string name() { return "DURATION"; };
      };
      
      struct LOPENPRICE : public id_base<LOPENPRICE, double> {
        static const std::string name() { return "LOPENPRICE"; };
      };
      
      struct LCLOSEPRICE : public id_base<LCLOSEPRICE, double> {
        static const std::string name() { return "LCLOSEPRICE"; };
      };
      
      struct QUOTEBASIS : public id_base<QUOTEBASIS, char*> {
        static const std::string name() { return "QUOTEBASIS"; };
      };
      
      struct PREVADMITTEDQUOT : public id_base<PREVADMITTEDQUOT, double> {
        static const std::string name() { return "PREVADMITTEDQUOT"; };
      };
      
      struct LASTBID : public id_base<LASTBID, double> {
        static const std::string name() { return "LASTBID"; };
      };
      
      struct LASTOFFER : public id_base<LASTOFFER, double> {
        static const std::string name() { return "LASTOFFER"; };
      };
            
      struct PREVLEGALCLOSEPR : public id_base<PREVLEGALCLOSEPR, double> {
        static const std::string name() { return "PREVLEGALCLOSEPR"; };
      };
      
      struct COUPONPERIOD : public id_base<COUPONPERIOD, double> {
        static const std::string name() { return "COUPONPERIOD"; };
      };
      
      struct MARKETPRICE2 : public id_base<MARKETPRICE2, double> {
        static const std::string name() { return "MARKETPRICE2"; };
      };
      
      struct ADMITTEDQUOTE : public id_base<ADMITTEDQUOTE, double> {
        static const std::string name() { return "ADMITTEDQUOTE"; };
      };
      
      struct BGOP : public id_base<BGOP, double> {
        static const std::string name() { return "BGOP"; };
      };
      
      struct BGONP : public id_base<BGONP, double> {
        static const std::string name() { return "BGONP"; };
      };
      
      struct STRIKE : public id_base<STRIKE, double> {
        static const std::string name() { return "STRIKE"; };
      };
      
      struct STEPPRICET : public id_base<STEPPRICET, double> {
        static const std::string name() { return "STEPPRICET"; };
      };
      
      struct STEPPRICE : public id_base<STEPPRICE, double> {
        static const std::string name() { return "STEPPRICE"; };
      };
      
      struct SETTLEPRICE : public id_base<SETTLEPRICE, double> {
        static const std::string name() { return "SETTLEPRICE"; };
      };
      
      struct OPTIONTYPE : public id_base<OPTIONTYPE, char*> {
        static const std::string name() { return "OPTIONTYPE"; };
      };
      
      struct OPTIONBASE : public id_base<OPTIONBASE, char*> {
        static const std::string name() { return "OPTIONBASE"; };
      };
      
      struct VOLATILITY : public id_base<VOLATILITY, double> {
        static const std::string name() { return "VOLATILITY"; };
      };
      
      struct THEORPRICE : public id_base<THEORPRICE, double> {
        static const std::string name() { return "THEORPRICE"; };
      };
      
      struct PERCENTRATE : public id_base<PERCENTRATE, double> {
        static const std::string name() { return "PERCENTRATE"; };
      };
      
      struct ISPERCENT : public id_base<ISPERCENT, char*> {
        static const std::string name() { return "ISPERCENT"; };
      };
      
      struct CLSTATE : public id_base<CLSTATE, char*> {
        static const std::string name() { return "CLSTATE"; };
      };
      
      struct CLPRICE : public id_base<CLPRICE, double> {
        static const std::string name() { return "CLPRICE"; };
      };
      
      struct STARTTIME : public id_base<STARTTIME, char*> {
        static const std::string name() { return "STARTTIME"; };
      };
      
      struct ENDTIME : public id_base<ENDTIME, char*> {
        static const std::string name() { return "ENDTIME"; };
      };
      
      struct EVNSTARTTIME : public id_base<EVNSTARTTIME, char*> {
        static const std::string name() { return "EVNSTARTTIME"; };
      };
      
      struct EVNENDTIME : public id_base<EVNENDTIME, char*> {
        static const std::string name() { return "EVNENDTIME"; };
      };
      
      struct MONSTARTTIME : public id_base<MONSTARTTIME, char*> {
        static const std::string name() { return "MONSTARTTIME"; };
      };
      
      struct MONENDTIME : public id_base<MONENDTIME, char*> {
        static const std::string name() { return "MONENDTIME"; };
      };
      
      struct CURSSTEPPRICE : public id_base<CURSSTEPPRICE, char*> {
        static const std::string name() { return "CURSTEPPRICE"; };
      };
      
      struct REALVMPRICE : public id_base<REALVMPRICE, double> {
        static const std::string name() { return "REALVMPRICE"; };
      };
      
      struct MARG : public id_base<MARG, char*> {
        static const std::string name() { return "MARG"; };
      };
      
      struct EXPDATE : public id_base<EXPDATE, double> {
        static const std::string name() { return "EXPDATE"; };
      };
      
      struct CROSSRATE : public id_base<CROSSRATE, double> {
        static const std::string name() { return "CROSSRATE"; };
      };
      
      struct BASEPRICE : public id_base<BASEPRICE, double> {
        static const std::string name() { return "BASEPRICE"; };
      };
      
      struct HIGHVAL : public id_base<HIGHVAL, double> {
        static const std::string name() { return "HIGHVAL"; };
      };
      
      struct LOWVAL : public id_base<LOWVAL, double> {
        static const std::string name() { return "LOWVAL"; };
      };
      
      struct ICHANGE : public id_base<ICHANGE, double> {
        static const std::string name() { return "ICHANGE"; };
      };
      
      struct IOPEN : public id_base<IOPEN, double> {
        static const std::string name() { return "IOPEN"; };
      };
      
      struct PCHANGE : public id_base<PCHANGE, double> {
        static const std::string name() { return "PCHANGE"; };
      };
      
      struct OPENPERIODPRICE : public id_base<OPENPERIODPRICE, double> {
        static const std::string name() { return "OPENPERIODPRICE"; };
      };
      
      struct MIN_CURR_LAST : public id_base<MIN_CURR_LAST, double> {
        static const std::string name() { return "MIN_CUR_LAST"; };
      };
      
      struct SETTLECODE : public id_base<SETTLECODE, char*> {
        static const std::string name() { return "SETTLECODE"; };
      };
      
      struct STEPPRICECL : public id_base<STEPPRICECL, double> {
        static const std::string name() { return "STEPPRICECL"; };
      };
      
      struct MIN_CURR_LAST_TI : public id_base<MIN_CURR_LAST_TI, char*> {
        static const std::string name() { return "MIN_CURR_LAST_TI"; };
      };
      
      struct PREVLOTSIZE : public id_base<PREVLOTSIZE, double> {
        static const std::string name() { return "PREVLOTSIZE"; };
      };
      
      struct LOTSIZECHANGEDAT : public id_base<LOTSIZECHANGEDAT, double> {
        static const std::string name() { return "LOTSIZECHANGEDAT"; };
      };
      
      struct AUCTPRICE : public id_base<AUCTPRICE, double> {
        static const std::string name() { return "AUCTPRICE"; };
      };
      
      struct CLOSING_AUCTION_VOLUME : public id_base<CLOSING_AUCTION_VOLUME, double> {
        static const std::string name() { return "CLOSING_AUCTION_VOLUME"; };
      };


    }

    // Extended params (param_ex) according to QPILE doc
    namespace param_ex {
      struct LONGNAME : public id_base<LONGNAME, char*> {
        static const std::string name() { return "LONGNAME"; };
      };

      struct SHORTNAME : public id_base<SHORTNAME, char*> {
        static const std::string name() { return "SHORTNAME"; };
      };

      struct CODE : public id_base<CODE, char*> {
        static const std::string name() { return "CODE"; };
      };

      struct CLASSNAME : public id_base<CLASSNAME, char*> {
        static const std::string name() { return "CLASSNAME"; };
      };

      struct CLASS_CODE : public id_base<CLASS_CODE, char*> {
        static const std::string name() { return "CLASS_CODE"; };
      };

      //TODO: Check return type
      struct TRADE_DATE_CODE : public id_base<TRADE_DATE_CODE, double> {
        static const std::string name() { return "TRADE_DATE_CODE"; };
      };

      //TODO: Check return type
      struct MAT_DATE : public id_base<MAT_DATE, double> {
        static const std::string name() { return "MAT_DATE"; };
      };

      //TODO: Check return type
      struct DAYS_TO_MAT_DATE : public id_base<DAYS_TO_MAT_DATE, double> {
        static const std::string name() { return "DAYS_TO_MAT_DATE"; };
      };

      //TODO: Check return type
      struct SEC_FACE_VALUE : public id_base<SEC_FACE_VALUE, double> {
        static const std::string name() { return "SEC_FACE_VALUE"; };
      };

      struct SEC_FACE_UNIT : public id_base<SEC_FACE_UNIT, char*> {
        static const std::string name() { return "SEC_FACE_UNIT"; };
      };

      struct SEC_SCALE : public id_base<SEC_SCALE, double> {
        static const std::string name() { return "SEC_SCALE"; };
      };

      struct SEC_PRICE_STEP : public id_base<SEC_PRICE_STEP, double> {
        static const std::string name() { return "SEC_PRICE_STEP"; };
      };

      struct SECTYPE : public id_base<SECTYPE, char*> {
        static const std::string name() { return "SECTYPE"; };
      };
    }
  }
}
