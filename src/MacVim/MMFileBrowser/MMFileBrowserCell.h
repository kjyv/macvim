
#import <Cocoa/Cocoa.h>
#import <MMFileBrowser.h>

@interface MMFileBrowserCell : NSTextFieldCell {
@private
    NSImage *image;
    MMFileBrowser* fileBrowser;
}

@property(atomic, retain) NSImage *image;

- (id)initWithFileBrowser:parent;
- (void)drawWithFrame:(NSRect)cellFrame inView:(NSView *)controlView;
- (NSSize)cellSize;
- (void)updateColors;

@end
