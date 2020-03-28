//
//  mycalculator.c
//  gtk
//
//  Created by jun zhou on 2020/3/23.
//  Copyright © 2020 jun zhou. All rights reserved.
//

#include "mycalculator.h"

typedef struct _JMyCalculatorPrivate JMyCalculatorPrivate;
struct _JMyCalculatorPrivate{
    GtkWidget *grid;
    GtkWidget *entry;
    GtkEntryBuffer *entry_buffer;
    GtkWidget *num_0;
    GtkWidget *num_1;
    GtkWidget *num_2;
    GtkWidget *num_3;
    GtkWidget *num_4;
    GtkWidget *num_5;
    GtkWidget *num_6;
    GtkWidget *num_7;
    GtkWidget *num_8;
    GtkWidget *num_9;
    GtkWidget *signal_dot;
    GtkWidget *signal_clear;
    GtkWidget *signal_signal;
    GtkWidget *signal_percent;
    GtkWidget *signal_div;
    GtkWidget *signal_mul;
    GtkWidget *signal_add;
    GtkWidget *signal_sub;
    GtkWidget *signal_equ;
};

G_DEFINE_TYPE_WITH_CODE(JMyCalculator, j_my_calculator, GTK_TYPE_FRAME, G_ADD_PRIVATE(JMyCalculator));

static void j_my_calculator_dispose(GObject *obj){
    g_print("j_my_calculator_dispose\n");
}

static void j_my_calculator_finalize(GObject *obj){
    g_print("j_my_calculator_finalize\n");
}

static void j_my_calculator_class_init(JMyCalculatorClass *clazz){
    g_print("j_my_calculator_class_init\n");
    GObjectClass *base_class = G_OBJECT_CLASS(clazz);
    base_class->dispose = j_my_calculator_dispose;
    base_class->finalize = j_my_calculator_finalize;
}

static void j_my_calculator_init_private(JMyCalculator *self){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(self);
    pri->grid = gtk_grid_new();
    pri->entry = gtk_entry_new();
    pri->entry_buffer = gtk_entry_get_buffer(GTK_ENTRY(pri->entry));
    pri->signal_dot = gtk_button_new_with_label(".");
    pri->num_0 = gtk_button_new_with_label("0");
    pri->num_1 = gtk_button_new_with_label("1");
    pri->num_2 = gtk_button_new_with_label("2");
    pri->num_3 = gtk_button_new_with_label("3");
    pri->num_4 = gtk_button_new_with_label("4");
    pri->num_5 = gtk_button_new_with_label("5");
    pri->num_6 = gtk_button_new_with_label("6");
    pri->num_7 = gtk_button_new_with_label("7");
    pri->num_8 = gtk_button_new_with_label("8");
    pri->num_9 = gtk_button_new_with_label("9");
    pri->signal_clear = gtk_button_new_with_label("C");
    pri->signal_signal = gtk_button_new_with_label("+/-");
    pri->signal_percent = gtk_button_new_with_label("%");
    pri->signal_div = gtk_button_new_with_label("/");
    pri->signal_mul = gtk_button_new_with_label("X");
    pri->signal_add = gtk_button_new_with_label("+");
    pri->signal_sub = gtk_button_new_with_label("-");
    pri->signal_equ = gtk_button_new_with_label("=");
}

static void j_my_calculator_init_container(JMyCalculator *self){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(self);
    gtk_container_add(GTK_CONTAINER(self), pri->grid);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->entry, 0, 0, 4, 1);
    gtk_entry_set_alignment(GTK_ENTRY(pri->entry), 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_clear, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_signal, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_percent, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_div, 3, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_9, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_8, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_7, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_mul, 3, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_6, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_5, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_4, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_add, 3, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_3, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_2, 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_1, 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_sub, 3, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->num_0, 0, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_dot, 2, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(pri->grid), pri->signal_equ, 3, 5, 1, 1);
}

static void j_my_calculator_init_signal_connect_num_0_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "0");
}

static void j_my_calculator_init_signal_connect_num_1_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "1");
}

static void j_my_calculator_init_signal_connect_num_2_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "2");
}

static void j_my_calculator_init_signal_connect_num_3_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "3");
}

static void j_my_calculator_init_signal_connect_num_4_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "4");
}

static void j_my_calculator_init_signal_connect_num_5_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "5");
}

static void j_my_calculator_init_signal_connect_num_6_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "6");
}

static void j_my_calculator_init_signal_connect_num_7_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "7");
}

static void j_my_calculator_init_signal_connect_num_8_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "8");
}

static void j_my_calculator_init_signal_connect_num_9_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "9");
}

static void j_my_calculator_init_signal_connect_signal_clear_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "C");
}

static void j_my_calculator_init_signal_connect_signal_signal_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "signal");
}

static void j_my_calculator_init_signal_connect_signal_percent_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "%");
}

static void j_my_calculator_init_signal_connect_signal_div_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "/");
}

static void j_my_calculator_init_signal_connect_signal_mul_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "X");
}

static void j_my_calculator_init_signal_connect_signal_add_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "+");
}

static void j_my_calculator_init_signal_connect_signal_sub_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "-");
}

static void j_my_calculator_init_signal_connect_signal_dot_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), ".");
}

static void j_my_calculator_init_signal_connect_signal_equ_clicked(GObject *obj, gpointer data){
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
    gtk_entry_set_text(GTK_ENTRY(pri->entry), "=");
}

static void j_my_calculator_init_signal_connect_preedit_changed(GObject *obj,gchar *preedit, gpointer data){
    g_print("j_my_calculator_init_signal_connect_entry_activate\n");
    //JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(J_MY_CALCULATOR(obj));
}

static void j_my_calculator_init_signal_connect(JMyCalculator *self){
    g_print("j_my_calculator_init_signal_connect\n");
    JMyCalculatorPrivate *pri = j_my_calculator_get_instance_private(self);
    g_signal_connect_swapped(pri->num_0, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_0_clicked), self);
    g_signal_connect_swapped(pri->num_1, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_1_clicked), self);
    g_signal_connect_swapped(pri->num_2, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_2_clicked), self);
    g_signal_connect_swapped(pri->num_3, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_3_clicked), self);
    g_signal_connect_swapped(pri->num_4, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_4_clicked), self);
    g_signal_connect_swapped(pri->num_5, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_5_clicked), self);
    g_signal_connect_swapped(pri->num_6, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_6_clicked), self);
    g_signal_connect_swapped(pri->num_7, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_7_clicked), self);
    g_signal_connect_swapped(pri->num_8, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_8_clicked), self);
    g_signal_connect_swapped(pri->num_9, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_num_9_clicked), self);
    g_signal_connect_swapped(pri->signal_clear, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_clear_clicked), self);
    g_signal_connect_swapped(pri->signal_signal, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_signal_clicked), self);
    g_signal_connect_swapped(pri->signal_percent, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_percent_clicked), self);
    g_signal_connect_swapped(pri->signal_div, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_div_clicked), self);
    g_signal_connect_swapped(pri->signal_mul, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_mul_clicked), self);
    g_signal_connect_swapped(pri->signal_add, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_add_clicked), self);
    g_signal_connect_swapped(pri->signal_sub, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_sub_clicked), self);
    g_signal_connect_swapped(pri->signal_dot, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_dot_clicked), self);
    g_signal_connect_swapped(pri->signal_equ, "clicked", G_CALLBACK(j_my_calculator_init_signal_connect_signal_equ_clicked), self);
    
    g_signal_connect_swapped(pri->entry, "preedit-changed", G_CALLBACK(j_my_calculator_init_signal_connect_preedit_changed), self);
    
}

static void j_my_calculator_init(JMyCalculator *self){
    g_print("j_my_calculator_init\n");
    j_my_calculator_init_private(self);
    j_my_calculator_init_container(self);
    j_my_calculator_init_signal_connect(self);
}
