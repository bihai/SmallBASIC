// This file is part of SmallBASIC
//
// Copyright(C) 2001-2013 Chris Warren-Smith.
//
// This program is distributed under the terms of the GPL v2.0 or later
// Download the GNU Public License (GPL) from www.gnu.org
// 

#ifndef MOSYNC_WIDGET
#define MOSYNC_WIDGET

#include <fltk/Widget.h>
#include <fltk/Image.h>
#include <fltk/draw.h>

#include "platform/mosync/interface.h"

struct AnsiWidget;

struct MosyncObject {
  MosyncObject();
  ~MosyncObject();
  void createImage(int w, int h);
  void draw(int w, int h);
  void resize(int w, int h);
  fltk::Image *_img;
  fltk::GSave *_gsave;
};

class MosyncWidget : public fltk::Widget, IButtonListener {
public:
  MosyncWidget(int x, int y, int w, int h, int defsize);
  virtual ~MosyncWidget();
  bool construct();

  void clearScreen();
  void print(const char *str);
  void drawLine(int x1, int y1, int x2, int y2);
  void drawRectFilled(int x1, int y1, int x2, int y2);
  void drawRect(int x1, int y1, int x2, int y2);
  void drawImage(fltk::Image *img, int x, int y, int sx, int sy, int w, int h);
  void saveImage(const char *fn, int x, int y, int w, int h);
  void setTextColor(long fg, long bg);
  void setColor(long color);
  int getX();
  int getY();
  void setPixel(int x, int y, int c);
  int getPixel(int x, int y);
  void setXY(int x, int y);
  int textHeight(void);
  void setFontSize(float i);
  int getFontSize();
  void resize(int x, int y, int w, int h);
  int getBackgroundColor();
  MosyncObject *getScreen() { return _screen; }

private:
  // inherited methods
  void draw();
  void layout();
  int handle(int e);

  void buttonClicked(const char *action);
  AnsiWidget *_ansiWidget;
  MosyncObject *_screen;
  bool _resized;
};

#endif