#include "mainwindow.h"           // Header file of our mainwindow
#include <QApplication>           /* Handeling widget , event handeling
                                     and mous movement and so on... */

int main(int argc, char *argv[])  // Our main func
{
    QApplication a(argc, argv);  // Creating application object
    MainWindow w;                // Main application object
    w.show();                    // Display main window option on screen
    return a.exec();             // Putting our application in a loop
}
