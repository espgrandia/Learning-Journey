//
//  main.m
//  ObjcPropertyPollutionTest
//
//  Created by esp on 2018/11/20.
//  Copyright © 2018年 esp. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PropertyPollutionTest.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"This is a ObjcPropertyPollutionTest");
        
        PropertyPollutionTest *propertyPollutionTest = [[PropertyPollutionTest alloc] initWithTestProperty:@"testProperty"];
        
        NSLog(@"propertyPollutionTest:%@", propertyPollutionTest);
        
        [propertyPollutionTest dumpTestProperty];
        
    }
    return 0;
}
