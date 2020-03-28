#include <gtk/gtk.h>
#include "mywindow.h"
#include <gmodule.h>

static void activate(GtkApplication *app, gpointer data){
    GtkWidget *window = gtk_application_window_new(app);
    GtkWidget *box = g_object_new(J_TYPE_MY_WINDOW,"orientation",GTK_ORIENTATION_VERTICAL,"spacing",0,NULL);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
}

int main(int argc, char **argv){
    GtkApplication *app = gtk_application_new("com.zhoujun.gtk", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int data = g_application_run(G_APPLICATION(app), argc, argv);
    return data;
}

//typedef void (* SayHelloFunc) (const char *message);
 
//gboolean just_say_hello (const char *filename, GError **error){
//    SayHelloFunc  say_hello;
//    GModule      *module;
//
//    GQuark FOO_ERROR = g_quark_from_string("FOO_ERROR");
//    gint FOO_ERROR_BLAH;
//    GQuark SAY_ERROR = g_quark_from_string("SAY_ERROR");
//    gint SAY_ERROR_OPEN;
//    module = g_module_open (filename, G_MODULE_BIND_LAZY);
//
//    if (!module) {
//        g_set_error (error, FOO_ERROR, FOO_ERROR_BLAH, "%s", g_module_error ());
//        return FALSE;
//    }
//
//    if (!g_module_symbol (module, "say_hello", (gpointer *)&say_hello)) {
//        g_set_error (error, SAY_ERROR, SAY_ERROR_OPEN, "%s: %s", filename, g_module_error ());
//        if (!g_module_close (module))
//            g_warning ("%s: %s", filename, g_module_error ());
//        return FALSE;
//    }
//
//    if (say_hello == NULL) {
//        g_set_error (error, SAY_ERROR, SAY_ERROR_OPEN, "symbol say_hello is NULL");
//        if (!g_module_close (module))
//            g_warning ("%s: %s", filename, g_module_error ());
//        return FALSE;
//    }
//
//    // call our function in the module
//    say_hello ("Hello world!");
//
//    if (!g_module_close (module))
//        g_warning ("%s: %s", filename, g_module_error ());
//    return TRUE;
//}
 
//int main(int argc, char **argv){
//    SayHelloFunc  say_hello;
//    GQuark FOO_ERROR = g_quark_from_string("FOO_ERROR");
//    gint FOO_ERROR_BLAH;
//    GQuark SAY_ERROR = g_quark_from_string("SAY_ERROR");
//    gint SAY_ERROR_OPEN;
//    g_printf ("main in\n");
//    g_printf ("module is %ssupported!\n", g_module_supported ()?"":"not ");
//    gchar *str_lib = g_module_build_path ("../lib/gmodule001", "hello");
//    g_printf ("path of the module:%s\n", str_lib);
//
//    GModule *module = g_module_open (str_lib, G_MODULE_BIND_LAZY);
//
//    const gchar *module_name = g_module_name (module);
//    g_printf ("filename of the module:%s\n", module_name);
//
////    if (!g_module_symbol (module, "say_hello", (gpointer *)&say_hello)) {
////        g_warning ("%s\n", g_module_error ());
////    }
//    if (!g_module_symbol (module, "SayHello", (gpointer *)&say_hello)) {
//        g_warning ("%s\n", g_module_error ());
//        if (!g_module_close (module))
//            g_warning ("%s: %s\n", str_lib, g_module_error ());
//    }
//
//
//    say_hello ("Hello world!");
//
//    if (!g_module_close (module))
//        g_warning ("%s: %s", str_lib, g_module_error ());
//
//    g_printf ("main out\n");
//    return 0;
//}

//typedef void (* SayHelloFunc) (const char *message);
//
//int main(int argc, char **argv){
//    SayHelloFunc  say_hello;
//    gchar *str_lib = g_module_build_path ("../lib/gmodule001", "hello");
//    GModule *module = g_module_open (str_lib, G_MODULE_BIND_LAZY);
//    g_module_symbol (module, "SayHello", (gpointer *)&say_hello);
//
//    say_hello ("Hello world!");
//
//    g_module_close (module);
//    return 0;
//}
