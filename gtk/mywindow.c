//
//  mywindow.c
//  gtk
//
//  Created by jun zhou on 2020/3/20.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#include "mywindow.h"
#include "mymenu.h"
#include "mystatus.h"
#include "mycentral.h"

typedef struct _JMyWindowPrivate JMyWindowPrivate;
struct _JMyWindowPrivate{
    GtkWidget *menubar;
    GtkWidget *frame;
    GtkWidget *status;
};
enum JMyWindowProperty{
    PROPERTY_J_MY_WINDOW_0,
    PROPERTY_J_MY_WINDOW_MENUBAR,
    PROPERTY_J_MY_WINDOW_FRAME,
    PROPERTY_J_MY_WINDOW_STATUS,
};

G_DEFINE_TYPE_WITH_CODE(JMyWindow, j_my_window, GTK_TYPE_BOX, G_ADD_PRIVATE(JMyWindow));

static void j_my_window_dispose(GObject *obj){
    g_print("j_my_window_dispose\n");
    JMyWindowPrivate *pri = j_my_window_get_instance_private(J_MY_WINDOW(obj));
    g_clear_object(&pri->menubar);
    g_clear_object(&pri->frame);
    g_clear_object(&pri->status);
}

static void j_my_window_finalize(GObject *obj){
    g_print("j_my_window_finalize\n");
}

static void j_my_window_class_add_signal(JMyWindowClass *clazz){
    g_signal_new("hello", J_TYPE_MY_WINDOW,
                 G_SIGNAL_RUN_LAST|G_SIGNAL_NO_RECURSE|G_SIGNAL_NO_HOOKS,
                 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}

static void j_my_window_class_init(JMyWindowClass *clazz){
    g_print("j_my_window_class_init\n");
    GObjectClass *base_class = G_OBJECT_CLASS(clazz);
    base_class->dispose = j_my_window_dispose;
    base_class->finalize = j_my_window_finalize;
    
    j_my_window_class_add_signal(clazz);
}

static void j_my_window_init_private(JMyWindow *self){
    g_print("j_my_window_init_private\n");
    JMyWindowPrivate *pri = j_my_window_get_instance_private(self);
    pri->menubar = g_object_new(J_TYPE_MY_MENU, NULL);
    pri->frame = g_object_new(J_TYPE_MY_CENTRAL,NULL);
    pri->status = g_object_new(J_TYPE_MY_STATUS,NULL);
    
}

static void j_my_window_init_container(JMyWindow *self){
    g_print("j_my_window_init_box\n");
    JMyWindowPrivate *pri = j_my_window_get_instance_private(self);
    gtk_box_pack_start(GTK_BOX(self), pri->menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(self), pri->frame, TRUE, TRUE, 0);
    gtk_box_pack_end(GTK_BOX(self),pri->status,FALSE,FALSE,0);
}

static void j_my_window_init_signal_connect(JMyWindow *self){
    g_print("j_my_window_init_signal_connect\n");
}

static void j_my_window_init(JMyWindow *self){
    g_print("j_my_window_init\n");
    j_my_window_init_private(self);
    j_my_window_init_container(self);
    j_my_window_init_signal_connect(self);
}



