//
//  PropertyPollutionTest.m
//  ObjcPropertyPollutionTest
//
//  Created by esp on 2018/11/20.
//  Copyright © 2018年 esp. All rights reserved.
//

#import "PropertyPollutionTest.h"

#import "PropertyPollutionTest+Pollution.h"

@implementation PropertyPollutionTest

- (instancetype)initWithTestProperty:(NSString *)testProperty
{
    self = [super init];

    if (self) {
        _testProperty = [testProperty copy];
    }

    return self;
}

- (void)dumpTestProperty
{
    NSLog(@"=== <%@> Begin ===", NSStringFromSelector(_cmd));

    NSLog(@"_testProperty : %p", _testProperty);
    NSLog(@"self.testProperty : %p", self.testProperty);

    if (_testProperty == self.testProperty) {
        NSLog(@"The memory address reference of _testProperty (%p) is equal to self.testProperty (%p)",
              _testProperty, self.testProperty);
    } else {
        NSLog(@"The memory address reference of _testProperty (%p) is not equal to self.testProperty (%p)",
              _testProperty, self.testProperty);
    }

    NSLog(@"=== <%@> End ===", NSStringFromSelector(_cmd));
}

@end
