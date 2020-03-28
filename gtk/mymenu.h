//
//  mymenu.h
//  gtk
//
//  Created by jun zhou on 2020/3/22.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#ifndef mymenu_h
#define mymenu_h

#include <stdio.h>
#include <gtk/gtk.h>
#define J_TYPE_MY_MENU (j_my_menu_get_type())
#define J_MY_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),J_TYPE_MY_MENU,JMyMenu))
#define J_IS_MY_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),J_TYPE_MY_MENU))
#define J_MY_MENU_CLASS(clazz) (G_TYPE_CHECK_CLASS_CAST((clazz),J_TYPE_MY_MENU,JMyMenuClass))
#define J_IS_MY_MENU_CLASS(clazz) (G_TYPE_CHECK_CLASS_TYPE((clazz),J_TYPE_MY_MENU))
#define J_MY_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),J_TYPE_MY_MENU,JMyMenuClass))

typedef struct _JMyMenu JMyMenu;
struct _JMyMenu{
    GtkMenuBar parent_instance;
};

typedef struct _JMyMenuClass JMyMenuClass;
struct _JMyMenuClass{
    GtkMenuBarClass parent_class;
};

GType j_my_menu_get_type(void);
#endif /* mymenu_h */
