//
//  MASUtilities.h
//  Masonry
//
//  Created by Jonas Budelmann on 19/08/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#if TARGET_OS_IPHONE

    #import <UIKit/UIKit.h>
    #define MAS_VIEW UIView
    #define MASEdgeInsets UIEdgeInsets

typedef UILayoutPriority MASLayoutPriority;
    static const MASLayoutPriority MASLayoutPriorityRequired = UILayoutPriorityRequired;
    static const MASLayoutPriority MASLayoutPriorityDefaultHigh = UILayoutPriorityDefaultHigh;
    static const MASLayoutPriority MASLayoutPriorityDefaultMedium = 500;
    static const MASLayoutPriority MASLayoutPriorityDefaultLow = UILayoutPriorityDefaultLow;
    static const MASLayoutPriority MASLayoutPriorityFittingSizeLevel = UILayoutPriorityFittingSizeLevel;

#elif TARGET_OS_MAC

    #import <AppKit/AppKit.h>
    #define MAS_VIEW NSView
    #define MASEdgeInsets NSEdgeInsets

typedef NSLayoutPriority MASLayoutPriority;
    static const MASLayoutPriority MASLayoutPriorityRequired = NSLayoutPriorityRequired;
    static const MASLayoutPriority MASLayoutPriorityDefaultHigh = NSLayoutPriorityDefaultHigh;
    static const MASLayoutPriority MASLayoutPriorityDragThatCanResizeWindow = NSLayoutPriorityDragThatCanResizeWindow;
    static const MASLayoutPriority MASLayoutPriorityDefaultMedium = 501;
    static const MASLayoutPriority MASLayoutPriorityWindowSizeStayPut = NSLayoutPriorityWindowSizeStayPut;
    static const MASLayoutPriority MASLayoutPriorityDragThatCannotResizeWindow = NSLayoutPriorityDragThatCannotResizeWindow;
    static const MASLayoutPriority MASLayoutPriorityDefaultLow = NSLayoutPriorityDefaultLow;
    static const MASLayoutPriority MASLayoutPriorityFittingSizeCompression = NSLayoutPriorityFittingSizeCompression;

#endif

/**
 *	Allows you to attach keys to objects matching the variable names passed.
 *
 *  view1.mas_key = @"view1", view2.mas_key = @"view2";
 *
 *  is equivalent to:
 *
 *  MASAttachKeys(view1, view2);
 */
#define MASAttachKeys(...)                                                    \
    NSDictionary *keyPairs = NSDictionaryOfVariableBindings(__VA_ARGS__);     \
    for (id key in keyPairs.allKeys) {                                        \
        id obj = keyPairs[key];                                               \
        NSAssert([obj respondsToSelector:@selector(setMas_key:)],             \
                 @"Cannot attach mas_key to %@", obj);                        \
        [obj setMas_key:key];                                                 \
    }

/**
 *  Used to create object hashes
 *  Based on http://www.mikeash.com/pyblog/friday-qa-2010-06-18-implementing-equality-and-hashing.html
 */
#define MAS_NSUINT_BIT (CHAR_BIT * sizeof(NSUInteger))
#define MAS_NSUINTROTATE(val, howmuch) ((((NSUInteger)val) << howmuch) | (((NSUInteger)val) >> (MAS_NSUINT_BIT - howmuch)))
