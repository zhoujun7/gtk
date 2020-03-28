//
//  mystatus.h
//  gtk
//
//  Created by jun zhou on 2020/3/22.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#ifndef mystatus_h
#define mystatus_h

#include <stdio.h>
#include <gtk/gtk.h>
#define J_TYPE_MY_STATUS (j_my_status_get_type())
#define J_MY_STATUS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),J_TYPE_MY_STATUS,JMyStatus))
#define J_IS_MY_STATUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),J_TYPE_MY_STATUS))
#define J_MY_STATUS_CLASS(clazz) (G_TYPE_CHECK_CLASS_CAST((clazz),J_TYPE_MY_STATUS,JMyStatusClass))
#define J_IS_MY_STATUS_CLASS(clazz) (G_TYPE_CHECK_CLASS_TYPE((clazz),J_TYPE_MY_STATUS))
#define J_MY_STATUS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),J_TYPE_MY_STATUS,JMyStatusClass))

typedef struct _JMyStatus JMyStatus;
struct _JMyStatus{
    GtkStatusbar parent_instance;
};

typedef struct _JMyStatusClass JMyStatusClass;
struct _JMyStatusClass{
    GtkStatusbarClass parent_class;
};

GType j_my_status_get_type(void);
#endif /* mystatus_h */
