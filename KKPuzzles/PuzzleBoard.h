//
//  PuzzleBoard.h
//  KKPuzzles
//
//  Created by kkuc on 20/11/16.
//  Copyright © 2016 Krzysztof Kuc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PuzzleBoard;
@protocol PuzzleBoardDataSource <NSObject>

-(NSInteger)numberOfRowsOnBoard:(PuzzleBoard* _Nonnull)board;
-(NSInteger)numberOfColsOnBoard:(PuzzleBoard* _Nonnull)board;
-(UIImage* _Nonnull)imageForBoard:(PuzzleBoard* _Nonnull)board;

@optional
-(NSUInteger)indexOfMissingPuzzleForBoard:(PuzzleBoard* _Nonnull)board;

@end

@protocol PuzzleBoardDelegate <NSObject>
@optional
-(void)boardCompleted:(PuzzleBoard* _Nonnull)board;

@end

@interface PuzzleBoard : UIView

@property(nonatomic, assign) IBOutlet __nullable id<PuzzleBoardDataSource> dataSource;
@property(nonatomic, assign) IBOutlet __nullable id<PuzzleBoardDelegate> delegate;
@property(nonatomic, readonly, getter=isCompleted) BOOL completed;

-(void)shuffle:(BOOL)animated;
-(void)reload;
-(void)redraw:(BOOL)animated;

@end
