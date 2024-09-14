#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>         // Adding this library to work with files
#include <QFileDialog>   // Adding this library to pop up and select file
#include <QTextStream>   // Adding this library to read text from file
#include <QMessageBox>   // Adding this library to open messagebox for user
#include <QPrinter>      // Adding this library to intract with printer
#include <QPrintDialog>  // Adding this library to choose printer

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  // Base class for all of our qtobjects

public:
    MainWindow(QWidget *parent = nullptr);  // Declaring constructer
    ~MainWindow();  // Our destructor to free resources

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";  // A string to hold name of current file
};
#endif // MAINWINDOW_H
