//
//  PropertyPollutionTest+Pollution.m
//  ObjcPropertyPollutionTest
//
//  Created by esp on 2018/11/20.
//  Copyright © 2018年 esp. All rights reserved.
//

#import "PropertyPollutionTest+Pollution.h"

#include <objc/runtime.h>

#define Category_Property_Get_Macro(type, property) \
/* */ - (type) property \
/* */ {\
/* */   return objc_getAssociatedObject(self, @selector(property));\
/* */ }

#define Category_Property_Set_Macro(type, property, setter, associationFlag) \
/* */ - (void) setter (type) property \
/* */ { \
/* */   objc_setAssociatedObject(self, @selector(property), property, associationFlag);\
/* */ }

/**
 * @brief 針對 Objective-C 物件 的 動態繫節 getter and setter 方法
 * @details 指定 OBJC_ASSOCIATION_RETAIN_NONATOMIC 綁定方式.
 * @param type: 型別.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Get_Set_RetainNonatomic_Macro(type, property, setter) \
/* */ Category_Property_Get_Macro(type, property) \
/* */ Category_Property_Set_Macro(type, property, setter, OBJC_ASSOCIATION_RETAIN_NONATOMIC)

@implementation PropertyPollutionTest (Pollution)

Category_Property_Get_Set_RetainNonatomic_Macro(NSString *, testProperty, setTestProperty:)



@end
