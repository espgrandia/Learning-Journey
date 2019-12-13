//
//  NSObject+SGT_DynamicProperty_Def.h
//  Fundation
//
//  Created by esp on 2014/7/8.
//  Copyright (c) 2014年 SGT. All rights reserved.
//
//  Note:
//  此為 動態繫節 property 的一些 macro, 簡化重複的程式碼 copy past 的動作擷取 property 的 category 方法.
//
// TODO: 目前 C Primitive 的簡易 macro 只有實作 int, unsigned int, float, double, 可以在將其餘的補齊.


#ifndef SweepStake_NSObject_SGT_DynamicProperty_Def_h
#define SweepStake_NSObject_SGT_DynamicProperty_Def_h

#include <objc/runtime.h>

// ============= This is Divider line =============
#pragma mark - ref website

// Objective-C: Property / instance variable in category
// http://stackoverflow.com/questions/8733104/objective-c-property-instance-variable-in-category


// ============= This is Divider line =============
#pragma mark - base category property macro (for Objective-C)

/**
 * @brief 針對 Objective-C 物件 的 動態繫節 getter 方法
 * @param type: 型別.
 * @param property: property name.
 */
#define Category_Property_Get_Macro(type, property) \
/* */ - (type) property \
/* */ {\
/* */   return objc_getAssociatedObject(self, @selector(property));\
/* */ }

/**
 * @brief 針對 Objective-C 物件 的 動態繫節 setter 方法
 * @param type: 型別.
 * @param property: property name.
 * @param property: setter name.
 * @param associationFlag: 設定的行為 (OBJC_ASSOCIATION_ASSIGN, OBJC_ASSOCIATION_RETAIN_NONATOMIC, ...)
 * @see objc/runtime.h
 */
#define Category_Property_Set_Macro(type, property, setter, associationFlag) \
/* */ - (void) setter (type) property \
/* */ { \
/* */   objc_setAssociatedObject(self, @selector(property), property, associationFlag);\
/* */ }

/**
 * @brief 針對 Objective-C 物件 的 動態繫節 getter and setter 方法
 * @param type: 型別.
 * @param property: property name.
 * @param property: setter name.
 * @param associationFlag: 設定的行為 (OBJC_ASSOCIATION_ASSIGN, OBJC_ASSOCIATION_RETAIN_NONATOMIC, ...)
 * @see objc/runtime.h
 */
#define Category_Property_Get_Set_Macro(type, property, setter, associationFlag) \
/* */ Category_Property_Get_Macro(type, property) \
/* */ Category_Property_Set_Macro(type, property, setter, associationFlag)

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

/**
 * @brief 針對 Objective-C 物件 的 動態繫節 getter and setter 方法
 * @details 指定 OBJC_ASSOCIATION_ASSIGN 綁定方式.
 * @param type: 型別.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Get_Set_Assign_Macro(type, property, setter) \
/* */ Category_Property_Get_Macro(type, property) \
/* */ Category_Property_Set_Macro(type, property, setter, OBJC_ASSOCIATION_ASSIGN)


// ============= This is Divider line =============
#pragma mark - category property macro (for C Primitive to NSNumber)

/**
 * @brief 針對 C Primitive 轉換成綁定 NSNumber 的 動態繫節 getter 方法
 * @param type: 型別.
 * @param property: property name.
 * @param property: setter name.
 * @param valueSelector: NSNumber 對應的 method (取值方法).
 */
#define Category_Property_Get_NSNumber_Primitive_Macro(type, property, valueSelector)\
/* */ - (type) property \
/* */ { \
/* */   return [objc_getAssociatedObject(self, @selector(property)) valueSelector];\
/* */ }

/**
 * @brief 針對 C Primitive 轉換成綁定 NSNumber 的 動態繫節 setter 方法.
 * @details 指定 OBJC_ASSOCIATION_RETAIN_NONATOMIC 綁定方式.
 * @param type: 型別.
 * @param property: property name.
 * @param property: setter name.
 * @param numberSelector: NSNumber 對應的 method (建構方法).
 */
#define Category_Property_Set_NSNumber_Primitive_RetainNonatomic_Macro(type, property, setter, numberSelector) \
/* */ - (void) setter (type) property \
/* */ { \
/* */   objc_setAssociatedObject(self, \
/* */                               @selector(property), \
/* */                               [NSNumber numberSelector: property],\
/* */                               OBJC_ASSOCIATION_RETAIN_NONATOMIC); \
/* */ }


// ============= This is Divider line =============
#pragma mark - category property macro (for int)

/**
 * @brief 針對 int 轉換成綁定 NSNumber 的 動態繫節 getter 方法.
 * @param property: property name.
 */
#define Category_Property_Get_Int_RetainNonatomic_Macro(property) \
/* */ Category_Property_Get_NSNumber_Primitive_Macro(int, property, intValue)

/**
 * @brief 針對 int 轉換成綁定 NSNumber 的 動態繫節 setter 方法.
 * @details 指定 OBJC_ASSOCIATION_RETAIN_NONATOMIC 綁定方式.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Set_Int_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Set_NSNumber_Primitive_RetainNonatomic_Macro(int, property, setter, numberWithInt)

/**
 * @brief 針對 int 轉換成綁定 NSNumber 的 動態繫節 getter and setter 方法.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Get_SET_Int_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Get_Int_RetainNonatomic_Macro(property) \
/* */ Category_Property_Set_Int_RetainNonatomic_Macro(property, setter)


// ============= This is Divider line =============
#pragma mark - category property macro (for unsigned int)

/**
 * @brief 針對 unsinged int 轉換成綁定 NSNumber 的 動態繫節 getter 方法.
 * @param property: property name.
 */
#define Category_Property_Get_UInt_RetainNonatomic_Macro(property) \
/* */ Category_Property_Get_NSNumber_Primitive_Macro(unsigned int, property, unsignedIntValue)

/**
 * @brief 針對 unsinged int 轉換成綁定 NSNumber 的 動態繫節 setter 方法.
 * @details 指定 OBJC_ASSOCIATION_RETAIN_NONATOMIC 綁定方式.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Set_UInt_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Set_NSNumber_Primitive_RetainNonatomic_Macro(unsigned int, property, setter, numberWithUnsignedInt)

/**
 * @brief 針對 unsinged int 轉換成綁定 NSNumber 的 動態繫節 getter and setter 方法.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Get_SET_UInt_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Get_UInt_RetainNonatomic_Macro(property) \
/* */ Category_Property_Set_UInt_RetainNonatomic_Macro(property, setter)


// ============= This is Divider line =============
#pragma mark - category property macro (for BOOL)

/**
 * @brief 針對 BOOL 轉換成綁定 NSNumber 的 動態繫節 getter 方法.
 * @param property: property name.
 */
#define Category_Property_Get_BOOL_RetainNonatomic_Macro(property) \
/* */ Category_Property_Get_NSNumber_Primitive_Macro(BOOL, property, boolValue)

/**
 * @brief 針對 BOOL 轉換成綁定 NSNumber 的 動態繫節 setter 方法.
 * @details 指定 OBJC_ASSOCIATION_RETAIN_NONATOMIC 綁定方式.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Set_BOOL_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Set_NSNumber_Primitive_RetainNonatomic_Macro(BOOL, property, setter, numberWithBool)

/**
 * @brief 針對 BOOL 轉換成綁定 NSNumber 的 動態繫節 getter and setter 方法.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Get_SET_BOOL_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Get_BOOL_RetainNonatomic_Macro(property) \
/* */ Category_Property_Set_BOOL_RetainNonatomic_Macro(property, setter)


// ============= This is Divider line =============
#pragma mark - category property macro (for float)

/**
 * @brief 針對 float 轉換成綁定 NSNumber 的 動態繫節 getter 方法.
 * @param property: property name.
 */
#define Category_Property_Get_Float_RetainNonatomic_Macro(property) \
/* */ Category_Property_Get_NSNumber_Primitive_Macro(float, property, floatValue)

/**
 * @brief 針對 float 轉換成綁定 NSNumber 的 動態繫節 setter 方法.
 * @details 指定 OBJC_ASSOCIATION_RETAIN_NONATOMIC 綁定方式.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Set_Float_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Set_NSNumber_Primitive_RetainNonatomic_Macro(float, property, setter, numberWithFloat)

/**
 * @brief 針對 float 轉換成綁定 NSNumber 的 動態繫節 getter and setter 方法.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Get_SET_Float_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Get_Float_RetainNonatomic_Macro(property) \
/* */ Category_Property_Set_Float_RetainNonatomic_Macro(property, setter)


// ============= This is Divider line =============
#pragma mark - category property macro (for double)

/**
 * @brief 針對 double 轉換成綁定 NSNumber 的 動態繫節 getter 方法.
 * @param property: property name.
 */
#define Category_Property_Get_Double_RetainNonatomic_Macro(property) \
/* */ Category_Property_Get_NSNumber_Primitive_Macro(double, property, doubleValue)

/**
 * @brief 針對 double 轉換成綁定 NSNumber 的 動態繫節 setter 方法.
 * @details 指定 OBJC_ASSOCIATION_RETAIN_NONATOMIC 綁定方式.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Set_Double_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Set_NSNumber_Primitive_RetainNonatomic_Macro(double, property, setter, numberWithDouble)

/**
 * @brief 針對 double 轉換成綁定 NSNumber 的 動態繫節 getter and setter 方法.
 * @param property: property name.
 * @param property: setter name.
 */
#define Category_Property_Get_SET_Double_RetainNonatomic_Macro(property, setter) \
/* */ Category_Property_Get_Double_RetainNonatomic_Macro(property) \
/* */ Category_Property_Set_Double_RetainNonatomic_Macro(property, setter)


#endif
