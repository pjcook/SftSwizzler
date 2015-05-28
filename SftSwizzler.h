//
//  SftSwizzler.h
//  Software101
//
//  Created by PJ on 28/05/2015.
//  Copyright (c) 2015 Software101. All rights reserved.
//
//  Distributed under the MIT License
//  Get the latest version from here:
//
//  https://github.com/pjcook/SftSwizzler
//
//  The MIT License (MIT)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//
//
//  If you do not understand Swizzling, then DO NOT USE THIS CLASS.
//  Useful reference: http://nshipster.com/method-swizzling/

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"

static void SFT_swizzleInstanceMethod(Class c, SEL original, SEL replacement)
{
    Method a = class_getInstanceMethod(c, original);
    Method b = class_getInstanceMethod(c, replacement);
    if (class_addMethod(c, original, method_getImplementation(b), method_getTypeEncoding(b)))
    {
        class_replaceMethod(c, replacement, method_getImplementation(a), method_getTypeEncoding(a));
    }
    else
    {
        method_exchangeImplementations(a, b);
    }
}

static void SFT_swizzleClassMethod(Class c, SEL original, SEL replacement)
{
    Method a = class_getClassMethod(c, original);
    Method b = class_getClassMethod(c, replacement);
    method_exchangeImplementations(a, b);
}

#pragma clang diagnostic pop