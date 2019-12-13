//
//  PropertyPollutionTest.h
//  ObjcPropertyPollutionTest
//
//  Created by esp on 2018/11/20.
//  Copyright © 2018年 esp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PropertyPollutionTest : NSObject

@property (nonatomic, strong) NSString *testProperty;

- (instancetype) initWithTestProperty:(NSString *)testProperty;

- (void) dumpTestProperty;

@end

NS_ASSUME_NONNULL_END
