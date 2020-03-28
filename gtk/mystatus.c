//
//  mystatus.c
//  gtk
//
//  Created by jun zhou on 2020/3/22.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#include "mystatus.h"

typedef struct _JMyStatusPrivate JMyStatusPrivate;
struct _JMyStatusPrivate{
    guint context_id;
};
enum JMyStatusProperty{
    PROPERTY_J_MY_STATUS_0,
    PROPERTY_J_MY_STATUS_CONTEXT_ID,
};

G_DEFINE_TYPE_WITH_CODE(JMyStatus, j_my_status, GTK_TYPE_STATUSBAR, G_ADD_PRIVATE(JMyStatus));

static void j_my_status_dispose(GObject *obj){
    g_print("j_my_status_dispose\n");
}

static void j_my_status_finalize(GObject *obj){
    g_print("j_my_status_finalize\n");
}

static void j_my_status_class_init(JMyStatusClass *clazz){
    g_print("j_my_status_class_init\n");
    GObjectClass *base_class = G_OBJECT_CLASS(clazz);
    base_class->dispose = j_my_status_dispose;
    base_class->finalize = j_my_status_finalize;
}

static void j_my_status_init_private(JMyStatus *self){
    JMyStatusPrivate *pri = j_my_status_get_instance_private(self);
    pri->context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(self), "statusbar");
}

static void j_my_status_init_container(JMyStatus *self){
    JMyStatusPrivate *pri = j_my_status_get_instance_private(self);
    gtk_statusbar_push(GTK_STATUSBAR(self), pri->context_id, "hello world");
}

static void j_my_status_init(JMyStatus *self){
    g_print("j_my_status_init\n");
    j_my_status_init_private(self);
    j_my_status_init_container(self);
}
