#ifndef __YUPLAY2_ITEM__
#define __YUPLAY2_ITEM__
#pragma once


#include <yuplay2_def.h>


enum Yuplay2ItemInfoFlags
{
  YU2_ITEM_MULTIPURCHASE = 1 << 0,
};


struct IYuplay2ItemInfoBase
{
  virtual const char* YU2VCALL getGuid() = 0;

  virtual const char* YU2VCALL getTitle() = 0;
  virtual const char* YU2VCALL getUrl() = 0;
  virtual const char* YU2VCALL getShortDesc() = 0;

  virtual float YU2VCALL getPrice() = 0;

  virtual unsigned YU2VCALL getFlags() = 0;
};


struct IYuplay2ItemInfo : public IYuplay2ItemInfoBase
{
  virtual void YU2VCALL free() = 0;
};


struct IYuplay2ItemsInfo
{
  virtual void YU2VCALL free() = 0;

  virtual IYuplay2ItemInfoBase* YU2VCALL itemInfo(const char* guid) = 0;

  virtual unsigned YU2VCALL getGuidsCount() = 0;
  virtual const char* YU2VCALL getGuid(unsigned idx) = 0;
};


struct IYuplay2ItemPurchases
{
  virtual void YU2VCALL free() = 0;

  virtual int YU2VCALL purchaseCount(const char* guid) = 0;

  virtual unsigned YU2VCALL getGuidsCount() = 0;
  virtual const char* YU2VCALL getGuid(unsigned idx) = 0;
};

#endif //__YUPLAY2_ITEM__
