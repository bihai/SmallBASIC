/* $Id: interface.c,v 1.18 2006-07-22 13:16:08 zeeb90au Exp $ */

/*
 * DO NOT EDIT THIS FILE - generated by Glade2Hildon version 1.0
 */
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <hildon-widgets/hildon-program.h> 
#include <hildon-widgets/hildon-file-chooser-dialog.h>
#include <hildon-widgets/hildon-font-selection-dialog.h>

#include "interface.h"
#include "callbacks.h"
#include "support.h"

GtkWidget* create_main_window() {
    GtkWidget* main_window = hildon_window_new();
    /* create a box container */
    GtkWidget* main_container = gtk_vbox_new(FALSE, 0);
    gtk_widget_show(main_container);
    gtk_container_add(GTK_CONTAINER(main_window), main_container);
    g_object_set_data_full(G_OBJECT(main_window), "main_container",
        gtk_widget_ref(main_container), (GDestroyNotify)gtk_widget_unref);
    /* create menus */
    GtkAccelGroup* accel_group = gtk_accel_group_new();
    GtkMenu* menubar = GTK_MENU(gtk_menu_new());
    hildon_window_set_menu(HILDON_WINDOW(main_window), menubar);
    GtkWidget* break_bn = gtk_menu_item_new_with_mnemonic(_("_Break"));
    gtk_menu_shell_append((GtkMenuShell*)menubar, break_bn);
    g_signal_connect((gpointer)break_bn, "activate", G_CALLBACK(on_break), NULL);
    GtkWidget* separator2 = gtk_separator_menu_item_new();
    gtk_widget_set_sensitive(separator2, FALSE);
    gtk_menu_shell_append((GtkMenuShell*)menubar, separator2);
    GtkWidget* reset_keys = gtk_menu_item_new_with_mnemonic(_("_Reset keys"));
    gtk_menu_shell_append((GtkMenuShell*)menubar, reset_keys);
    g_signal_connect((gpointer)reset_keys, "activate", G_CALLBACK(on_reset_keys), NULL);
    GtkWidget* save_screen = gtk_menu_item_new_with_mnemonic(_("_Save Screen"));
    gtk_menu_shell_append((GtkMenuShell*)menubar, save_screen);
    g_signal_connect((gpointer)save_screen, "activate", G_CALLBACK(on_save_screen), NULL);
    GtkWidget* separator1 = gtk_separator_menu_item_new();
    gtk_widget_set_sensitive(separator1, FALSE);
    gtk_menu_shell_append((GtkMenuShell*)menubar, separator1);
    GtkWidget* about = gtk_image_menu_item_new_from_stock("gtk-about", accel_group);
    gtk_menu_shell_append((GtkMenuShell*)menubar, about);
    g_signal_connect((gpointer)about, "activate", G_CALLBACK(on_about_activate), NULL);
    GtkWidget* separatormenuitem1 = gtk_separator_menu_item_new();
    gtk_widget_set_sensitive(separatormenuitem1, FALSE);
    gtk_menu_shell_append((GtkMenuShell*)menubar, separatormenuitem1);
    GtkWidget* quit = gtk_image_menu_item_new_from_stock("gtk-quit", accel_group);
    gtk_menu_shell_append((GtkMenuShell*)menubar, quit);
    g_signal_connect((gpointer)quit, "activate", G_CALLBACK(on_quit_activate), NULL);
    gtk_widget_show_all(GTK_WIDGET(menubar));
    /* create scrolled window */
    GtkWidget* scrolledwindow2 = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_show(scrolledwindow2);
    gtk_box_pack_start(GTK_BOX(main_container),scrolledwindow2, TRUE, TRUE, 0);
    GTK_WIDGET_SET_FLAGS(scrolledwindow2, GTK_CAN_FOCUS);
    g_object_set_data_full(G_OBJECT(main_window), "scrolledwindow2",
        gtk_widget_ref(scrolledwindow2), (GDestroyNotify)gtk_widget_unref);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledwindow2),
        GTK_POLICY_NEVER, GTK_POLICY_NEVER);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow2),
        GTK_SHADOW_ETCHED_IN);
    /* create layout */
    GtkWidget* drawing_area = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolledwindow2), drawing_area);
    gtk_widget_set_size_request(drawing_area, 668, 392);
    g_object_set_data_full(G_OBJECT(main_window), "drawing_area",
        gtk_widget_ref(drawing_area), (GDestroyNotify)gtk_widget_unref);
    gtk_layout_set_size(GTK_LAYOUT(drawing_area), 1, 1);
    
    return main_window;
}

GtkWidget* create_aboutdialog(void) {
    const gchar *authors = "Nicholas Christopoulos\n"
    "Chris Warren-Smith";
    const gchar *license = "SmallBASIC comes with ABSOLUTELY NO WARRANTY.\n"
    "This program is free software; you can use it redistribute\n"
    "it and/or modify it under the terms of the \n"
    "GNU General Public License version 2 as published by\n"
    "the Free Software Foundation.";
    GtkWidget* about_dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(about_dialog), _("About"));
    gtk_window_set_type_hint(GTK_WINDOW(about_dialog), GDK_WINDOW_TYPE_HINT_DIALOG);
    GtkWidget* dialog_vbox = GTK_DIALOG(about_dialog)->vbox;
    GtkWidget* notebook = gtk_notebook_new();
    gtk_box_pack_start(GTK_BOX(dialog_vbox), notebook, TRUE, TRUE, 0);
    /* version tab 1 */
    GtkWidget* vbox = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(notebook), vbox);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);
    GtkWidget* app_name =
    gtk_label_new(_("<span foreground=\"blue\" size=\"xx-large\"><b>SmallBASIC</b></span>"));
    gtk_box_pack_start(GTK_BOX(vbox), app_name, FALSE, FALSE, 0);
    gtk_label_set_use_markup(GTK_LABEL(app_name), TRUE);
    GtkWidget* version = gtk_label_new(VERSION);
    gtk_box_pack_start(GTK_BOX(vbox), version, FALSE, FALSE, 0);
    GtkWidget* comments = gtk_label_new(_(""));
    gtk_box_pack_start(GTK_BOX(vbox), comments, FALSE, FALSE, 0);
    GtkWidget* copyw = gtk_label_new(_("Copyright (c) 2006 Chris Warren-Smith"));
    gtk_box_pack_start(GTK_BOX(vbox), copyw, FALSE, FALSE, 0);
    gtk_notebook_set_tab_label(GTK_NOTEBOOK(notebook),
    gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), 0),
    gtk_label_new(_("Version")));
    /* authors tab */
    GtkWidget* scrolledwindow1 = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(notebook), scrolledwindow1);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow1), GTK_SHADOW_IN);
    GtkWidget* viewport1 = gtk_viewport_new (NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolledwindow1), viewport1);
    GtkWidget* label1 = gtk_label_new(authors);
    gtk_container_add(GTK_CONTAINER(viewport1), label1);
    gtk_notebook_set_tab_label(GTK_NOTEBOOK(notebook),
    gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), 1),
    gtk_label_new(_("Authors")));
    /* license tab */
    GtkWidget* scrolledwindow2 = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(notebook), scrolledwindow2);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow2), GTK_SHADOW_IN);
    GtkWidget* viewport2 = gtk_viewport_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolledwindow2), viewport2);
    GtkWidget* label2 = gtk_label_new(license);
    gtk_container_add(GTK_CONTAINER(viewport2), label2);
    gtk_notebook_set_tab_label(GTK_NOTEBOOK(notebook),
    gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), 2),
    gtk_label_new(_("License")));
    /* ok button */
    GtkWidget* dialog_action_area1 = GTK_DIALOG(about_dialog)->action_area;
    gtk_button_box_set_layout(GTK_BUTTON_BOX(dialog_action_area1), GTK_BUTTONBOX_END);
    GtkWidget* okbutton1 = gtk_button_new_from_stock("gtk-ok");
    gtk_dialog_add_action_widget(GTK_DIALOG(about_dialog), okbutton1, GTK_RESPONSE_OK);
    GTK_WIDGET_SET_FLAGS(okbutton1, GTK_CAN_DEFAULT);
    gtk_widget_show_all(GTK_WIDGET(about_dialog));
    return about_dialog;
}

GtkWidget* create_opendialog(GtkWindow *main_window) {
    GtkWidget* opendialog = hildon_file_chooser_dialog_new(main_window, 
        GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_window_set_title(GTK_WINDOW(opendialog), "Open BAS File");
    gtk_widget_show_all(GTK_WIDGET(opendialog));
    return opendialog;
}

GtkWidget* create_savedialog(GtkWindow *main_window) {
    GtkWidget* savedialog = hildon_file_chooser_dialog_new(main_window, 
        GTK_FILE_CHOOSER_ACTION_SAVE);
    gtk_window_set_title(GTK_WINDOW(savedialog), "Save Screen");
    gtk_widget_show_all(GTK_WIDGET(savedialog));
    return savedialog;
}


/* End of $Id: interface.c,v 1.18 2006-07-22 13:16:08 zeeb90au Exp $ */
