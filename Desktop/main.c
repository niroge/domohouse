#include <gtk/gtk.h>
#include <stdio.h>

const gboolean true  = TRUE;
const gboolean false = FALSE;

void CloseProgram( GtkWidget *, gpointer );
void LedButtonClicked( GtkWidget *, gpointer );
void ConnectOrDisconnect( GtkWidget *, gpointer );
void GetTemperature( GtkWidget *, gpointer );
void GetFire( GtkWidget *, gpointer );

int main( int argc, char ** argv ) {
    gtk_init( &argc, &argv );
    
    GtkWidget * window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    GtkWidget * grid   = gtk_grid_new(  );

    GtkWidget * buttonConnectDisconnect = gtk_button_new_with_label( "Connect" );
    GtkWidget * buttonLed1              = gtk_button_new_with_label( "1" );
    GtkWidget * buttonLed2              = gtk_button_new_with_label( "2" );
    GtkWidget * buttonLed3              = gtk_button_new_with_label( "3" );
    GtkWidget * buttonLed4              = gtk_button_new_with_label( "4" );
    GtkWidget * buttonLed5              = gtk_button_new_with_label( "5" );
    GtkWidget * buttonLed6              = gtk_button_new_with_label( "6" );
    GtkWidget * buttonTemperature       = gtk_button_new_with_label( "Temperature" );
    GtkWidget * buttonFire              = gtk_button_new_with_label( "Check fire" );

    GtkWidget * labelConnected = gtk_label_new( "Connected: NO" );
    GtkWidget * labelLights    = gtk_label_new( "Lights" );
    GtkWidget * labelInfo      = gtk_label_new( "Info" );

    g_signal_connect( window, "destroy", G_CALLBACK( CloseProgram ), NULL );
    g_signal_connect( buttonLed1, "clicked", G_CALLBACK( LedButtonClicked ), "1" );
    g_signal_connect( buttonLed2, "clicked", G_CALLBACK( LedButtonClicked ), "2" );
    g_signal_connect( buttonLed3, "clicked", G_CALLBACK( LedButtonClicked ), "3" );
    g_signal_connect( buttonLed4, "clicked", G_CALLBACK( LedButtonClicked ), "4" );
    g_signal_connect( buttonLed5, "clicked", G_CALLBACK( LedButtonClicked ), "5" );
    g_signal_connect( buttonLed6, "clicked", G_CALLBACK( LedButtonClicked ), "6" );
    g_signal_connect( buttonConnectDisconnect, "clicked", G_CALLBACK( ConnectOrDisconnect ), NULL );
    g_signal_connect( buttonTemperature, "clicked", G_CALLBACK( GetTemperature ), NULL );
    g_signal_connect( buttonFire, "clicked", G_CALLBACK( GetFire ), NULL );

    gtk_grid_attach( GTK_GRID( grid ), labelConnected, 0, 0, 2, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonConnectDisconnect, 3, 0, 1, 1 );

    gtk_grid_attach( GTK_GRID( grid ), labelLights, 0, 1, 2, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonLed1, 0, 2, 1, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonLed2, 1, 2, 1, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonLed3, 0, 3, 1, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonLed4, 1, 3, 1, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonLed5, 0, 4, 1, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonLed6, 1, 4, 1, 1 );

    gtk_grid_attach( GTK_GRID( grid ), labelInfo, 2, 1, 2, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonTemperature, 2, 2, 2, 1 );
    gtk_grid_attach( GTK_GRID( grid ), buttonFire, 2, 3, 2, 1 );

    gtk_container_add( GTK_CONTAINER( window ), grid );
    gtk_container_set_border_width( GTK_CONTAINER( window ), 20 );
    gtk_widget_show_all( window );
    gtk_main();
    
    return 0;
}

void CloseProgram( GtkWidget * widget, gpointer data ) {
    g_print( "Close request!\n" );
    gtk_main_quit();
}

void LedButtonClicked( GtkWidget * widget, gpointer data ) {
    g_print( "Clicked button %s\n", (const char *) data );
}

void ConnectOrDisconnect( GtkWidget * widget, gpointer data ) {
    g_print( "Connected/Disconnected!\n" );
}

void GetTemperature( GtkWidget * widget, gpointer data ) {
    g_print( "Temperature: \n" );
}

void GetFire( GtkWidget * widget, gpointer data ) {
    g_print( "fire: \n" );
}
