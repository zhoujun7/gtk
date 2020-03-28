//
//  mywindow.h
//  gtk
//
//  Created by jun zhou on 2020/3/20.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#ifndef mywindow_h
#define mywindow_h

#include <stdio.h>
#include <gtk/gtk.h>

#define J_TYPE_MY_WINDOW (j_my_window_get_type())

G_DECLARE_DERIVABLE_TYPE(JMyWindow, j_my_window, J, MY_WINDOW, GtkBox)

struct _JMyWindowClass{
    GtkBoxClass parent_class;
};

GType j_my_window_get_type(void);
#endif /* mywindow_h */
