//
//  mycentral.c
//  gtk
//
//  Created by jun zhou on 2020/3/22.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#include "mycentral.h"
#include "mycalculator.h"

typedef struct _JMyCentralPrivate JMyCentralPrivate;
struct _JMyCentralPrivate{
    GtkWidget *calculator;
};
enum JMyCentralProperty{
    PROPERTY_J_MY_CENTRAL_0,
    PROPERTY_J_MY_CENTRAL_CALCULATOR,
};

G_DEFINE_TYPE_WITH_CODE(JMyCentral, j_my_central, GTK_TYPE_FRAME, G_ADD_PRIVATE(JMyCentral));

static void j_my_central_dispose(GObject *obj){
    g_print("j_my_central_dispose\n");
}

static void j_my_central_finalize(GObject *obj){
    g_print("j_my_central_finalize\n");
}

static void j_my_central_class_add_signal(JMyCentralClass *clazz){
    g_signal_new("from_menu_to_central_at_window",
                 J_TYPE_MY_CENTRAL,
                 G_SIGNAL_RUN_LAST|G_SIGNAL_NO_RECURSE|G_SIGNAL_NO_HOOKS,
                 0,NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}

static void j_my_central_class_init(JMyCentralClass *clazz){
    g_print("j_my_central_class_init\n");
    GObjectClass *base_class = G_OBJECT_CLASS(clazz);
    base_class->dispose = j_my_central_dispose;
    base_class->finalize = j_my_central_finalize;
    j_my_central_class_add_signal(clazz);
}

static void j_my_central_init_private(JMyCentral *self){
    JMyCentralPrivate *pri = j_my_central_get_instance_private(self);
    pri->calculator = g_object_new(J_TYPE_MY_CALCULATOR, NULL);
}

static void j_my_central_init_container(JMyCentral *self){
    JMyCentralPrivate *pri = j_my_central_get_instance_private(self);
    gtk_container_add(GTK_CONTAINER(self), pri->calculator);
}

static void j_my_central_init(JMyCentral *self){
    g_print("j_my_central_init\n");
    j_my_central_init_private(self);
    j_my_central_init_container(self);
}
