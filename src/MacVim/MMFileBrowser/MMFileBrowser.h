#import <Cocoa/Cocoa.h>

@class MMFileBrowserFSItem;

@interface MMPathCell : NSPathCell
@end

@interface MMPathComponentCell : NSPathComponentCell
@end

@interface MMFileBrowser : NSOutlineView
@property (nonatomic, copy) NSColor *sidebarForegroundColor;
@property (nonatomic, copy) NSColor *sidebarBackgroundColor;

- (void)makeFirstResponder;
- (NSMenu *)menuForEvent:(NSEvent *)event;
- (void)cancelOperation:(id)sender;
- (void)expandParentsOfItem:(id)item;
- (void)selectItem:(id)item;
- (NSEvent *)keyEventWithEvent:(NSEvent *)event character:(NSString *)character code:(unsigned short)code;
- (void)sendSelectionChangedNotification;
- (void)setColorsWithBackground:(NSColor*)bgColor foreground:(NSColor*)fgColor;

@end

@protocol MMFileBrowserDelegate <NSObject, NSOutlineViewDataSource, NSOutlineViewDelegate>
- (void)outlineViewSelectionIsChanging:(NSNotification *)notification;
- (void)outlineViewSelectionDidChange:(NSNotification *)notification;
- (NSMenu *)menuForRow:(NSInteger)row;
- (void)openSelectedFilesInCurrentWindowWithLayout:(int)layout;
- (void)fileBrowserWillExpand:(MMFileBrowser *)fileBrowser
                         item:(MMFileBrowserFSItem *)item
                    recursive:(BOOL)recursive;
- (void)outlineViewItemWillExpand:(NSNotification *)notification;
@end

@interface MMPathControl : NSPathControl {
@private
    MMFileBrowser* fileBrowser;
}

- (void)updateColors;
- (id)initWithFrame:(NSRect)frameRect parent:(MMFileBrowser*)parent;

@end