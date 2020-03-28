//
//  mymenu.c
//  gtk
//
//  Created by jun zhou on 2020/3/22.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#include "mymenu.h"

typedef struct _JMyMenuPrivate JMyMenuPrivate;
struct _JMyMenuPrivate{
    GtkWidget *file;
    GtkWidget *filemenu;
    GtkWidget *save;
    GtkWidget *savemenu;
    GtkWidget *quit;
    GtkWidget *edit;
};
enum JMyMenuProperty{
    PROPERTY_J_MY_MENU_0,
    PROPERTY_J_MY_MENU_FILE,
    PROPERTY_J_MY_MENU_FILEMENU,
    PROPERTY_J_MY_MENU_SAVE,
    PROPERTY_J_MY_MENU_SAVEMENU,
    PROPERTY_J_MY_MENU_QUIT,
    PROPERTY_J_MY_MENU_EDIT,
};

G_DEFINE_TYPE_WITH_CODE(JMyMenu, j_my_menu, GTK_TYPE_MENU_BAR, G_ADD_PRIVATE(JMyMenu));

static void j_my_menu_dispose(GObject *obj){
    g_print("j_my_menu_dispose\n");
}

static void j_my_menu_finalize(GObject *obj){
    g_print("j_my_menu_finalize\n");
}

static void j_my_menu_class_add_signal(JMyMenuClass *clazz){
    g_signal_new("from_menu_to_central",
                 J_TYPE_MY_MENU,
                 G_SIGNAL_RUN_LAST|G_SIGNAL_NO_RECURSE|G_SIGNAL_NO_HOOKS,
                 0,
                 NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}

static void j_my_menu_class_init(JMyMenuClass *clazz){
    g_print("j_my_menu_class_init\n");
    GObjectClass *base_class = G_OBJECT_CLASS(clazz);
    base_class->dispose = j_my_menu_dispose;
    base_class->finalize = j_my_menu_finalize;
    j_my_menu_class_add_signal(clazz);
}

static void j_my_menu_init_private(JMyMenu *self){
    JMyMenuPrivate *pri = j_my_menu_get_instance_private(self);
    pri->file = gtk_menu_item_new_with_label("file");
    pri->save = gtk_menu_item_new_with_label("save");
    pri->quit = gtk_menu_item_new_with_label("quit");
    pri->edit = gtk_menu_item_new_with_label("edit");
    pri->filemenu = gtk_menu_new();
    pri->savemenu = gtk_menu_new();
}

static void j_my_menu_init_container(JMyMenu *self){
    JMyMenuPrivate *pri = j_my_menu_get_instance_private(self);
    gtk_menu_shell_append(GTK_MENU_SHELL(self), pri->file);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(pri->file), pri->filemenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(pri->filemenu), pri->edit);
    gtk_menu_shell_append(GTK_MENU_SHELL(pri->filemenu), pri->save);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(pri->save), pri->savemenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(pri->savemenu), pri->quit);
}

static void j_my_menu_init(JMyMenu *self){
    g_print("j_my_menu_init\n");
    j_my_menu_init_private(self);
    j_my_menu_init_container(self);
}
