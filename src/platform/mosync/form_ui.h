// This file is part of SmallBASIC
//
// Copyright(C) 2001-2012 Chris Warren-Smith.
//
// This program is distributed under the terms of the GPL v2.0 or later
// Download the GNU Public License (GPL) from www.gnu.org
//

#ifndef FORM_UI_H
#define FORM_UI_H

#include "config.h"
#include "common/sys.h"
#include "common/var.h"

// control types available using the BUTTON command
enum ControlType {
  ctrl_button,
  ctrl_text,
  ctrl_label,
  ctrl_listbox,
};

struct ListModel : IFormWidgetListModel {
  ListModel(const char *items, var_t *v);
  virtual ~ListModel() { clear(); }

  void clear();
  void create(const char *items, var_t *v);
  void fromArray(const char *caption, var_t *v);
  const char *getTextAt(int index);
  int getIndex(const char *t);
  int rowCount() const { return list.size(); }
  int selectedIndex() const { return focusIndex; }
  void setSelectedIndex(int index) { focusIndex = index; }

private:
  Vector<String *> list;
  int focusIndex;
};

// binds a smallbasic variable with a form widget
struct WidgetData  : public IButtonListener {
  WidgetData(ControlType type, var_t *var);
  virtual ~WidgetData();

  IFormWidget *widget;
  ControlType type;
  var_t *var;

  // startup value used to check if
  // exec has altered a bound variable
  union {
    long i;
    byte *ptr;
  } orig;

  void arrayToString(String &s, var_t *v);
  void buttonClicked(const char *action);
  void setupWidget(IFormWidget *widget);
  bool updateGui();
  void updateVarFlag();
  void transferData();
};

typedef WidgetData *WidgetDataPtr;

struct Form {
  Form();
  virtual ~Form();

  void add(WidgetDataPtr widgetData) { items.add(widgetData); }
  bool hasEvent() { return mode == m_selected; }
  void invoke(WidgetDataPtr widgetData);
  void execute();
  void update();

  enum Mode {
    m_reset,
    m_init,
    m_active,
    m_selected
  };

private:
  Mode mode;
  Vector<WidgetDataPtr> items; // form child items
  var_t *var;                  // form variable contains the value of the event widget
  int cmd;                     // doform argument by value
  bool kb_handle;              // whether doform returns on a keyboard event
  int prev_x;
  int prev_y;
};

#endif