//
//  mycalculator.h
//  gtk
//
//  Created by jun zhou on 2020/3/23.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#ifndef mycalculator_h
#define mycalculator_h

#include <stdio.h>
#include <gtk/gtk.h>
#define J_TYPE_MY_CALCULATOR (j_my_calculator_get_type())
#define J_MY_CALCULATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),J_TYPE_MY_CALCULATOR,JMyCalculator))
#define J_IS_MY_CALCULATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),J_TYPE_MY_CALCULATOR))
#define J_MY_CALCULATOR_CLASS(clazz) (G_TYPE_CHECK_CLASS_CAST((clazz),J_TYPE_MY_CALCULATOR,JMyCalculatorClass))
#define J_IS_MY_CALCULATOR_CLASS(clazz) (G_TYPE_CHECK_CLASS_TYPE((clazz),J_TYPE_MY_CALCULATOR))
#define J_MY_CALCULATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),J_TYPE_MY_CALCULATOR,JMyCalculatorClass))

typedef struct _JMyCalculator JMyCalculator;
struct _JMyCalculator{
    GtkFrame parent_instance;
};

typedef struct _JMyCalculatorClass JMyCalculatorClass;
struct _JMyCalculatorClass{
    GtkFrameClass parent_class;
};

GType j_my_calculator_get_type(void);
#endif /* mycalculator_h */
