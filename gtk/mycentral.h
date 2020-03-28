//
//  mycentral.h
//  gtk
//
//  Created by jun zhou on 2020/3/22.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#ifndef mycentral_h
#define mycentral_h

#include <stdio.h>
#include <gtk/gtk.h>
#define J_TYPE_MY_CENTRAL (j_my_central_get_type())
#define J_MY_CENTRAL(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),J_TYPE_MY_CENTRAL,JMyCentral))
#define J_IS_MY_CENTRAL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),J_TYPE_MY_CENTRAL))
#define J_MY_CENTRAL_CLASS(clazz) (G_TYPE_CHECK_CLASS_CAST((clazz),J_TYPE_MY_CENTRAL,JMyCentralClass))
#define J_IS_MY_CENTRAL_CLASS(clazz) (G_TYPE_CHECK_CLASS_TYPE((clazz),J_TYPE_MY_CENTRAL))
#define J_MY_CENTRAL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),J_TYPE_MY_CENTRAL,JMyCentralClass))

typedef struct _JMyCentral JMyCentral;
struct _JMyCentral{
    GtkFrame parent_instance;
};

typedef struct _JMyCentralClass JMyCentralClass;
struct _JMyCentralClass{
    GtkFrameClass parent_class;
};

GType j_my_central_get_type(void);
#endif /* mycentral_h */
