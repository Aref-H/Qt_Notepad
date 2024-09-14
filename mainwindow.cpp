#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)    // Mainwindow constructer
    : QMainWindow(parent)                  // Our Qmain constructer parent
    , ui(new Ui::MainWindow)               // Creating ui class and asigning it to our ui member
{
    ui->setupUi(this);                     // Setting up our user interface
    this->setCentralWidget(ui->textEdit);  // Widget is going to take up all screen
}

MainWindow::~MainWindow()                  // Our destructor to delete user interface
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();  // Clearing the current file that we created in our header file
    ui->textEdit->setText(QString());  // Clearing the textEdit widget
}

void MainWindow::on_actionOpen_triggered()
{
    // Opening file dialog box so the user can shoose file
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    // Object for reading and writing files and passing our file name to it
    QFile file(fileName);
    // Saving file name in the currentFile that we have in our header file
    currentFile = fileName;
    // If file not opend show the following message
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        // Send the follwing message
        QMessageBox::warning(this, "Warrning", "Cannot open file : "+ file.errorString());
        return;
    }
    // Otherwise do...
    else
    {
        // Set window title of our application equal to file name
        setWindowTitle(fileName);
        // creating interface to read our textstream
        QTextStream in(&file);
        // Copy text in string
        QString text = in.readAll();
        // Puting text in our text edit widget
        ui->textEdit->setText(text);
        // Closing the opened file
        file.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    // Opening a dialog for saving file
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    // Object for reading and weiting files and passing our file name to it
    QFile file(fileName);
    // Some error handling like above with a little difrence
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warrning", "Cannot save file : "+ file.errorString());
        return;
    }
    // Otherwise do...
    else
    {
        // Saving file name in the currentFile that we have in our header file
        currentFile = fileName;
        // Set window title of our application equal to file name
        setWindowTitle(fileName);
        // Creating interface to write our textstream
        QTextStream out(&file);
        // coping text in the text widget and convert it
        QString text = ui->textEdit->toPlainText();
        // Out putting our file
        out << text;
        // Closing the opened file
        file.close();
    }
}

void MainWindow::on_actionPrint_triggered()
{
    // Intracting with any printer that is connected to our computer
    QPrinter printer;
    // Putting our printer name
    printer.setPrinterName("Printer name");
    // Selecting our actual printer
    QPrintDialog pDialog(&printer, this);
    // Error handling for our printer
    if (pDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this, "Warning", "Cannot access printer");
        return;
    }
    // Otherwise do...
    else
    {
        // Sending our text to the printer
        ui->textEdit->print(&printer);
    }
}

void MainWindow::on_actionExit_triggered()
{
    // Exit
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    // Coping
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    // Pasting
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    // Cutting
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    // Undo
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    // Redo
    ui->textEdit->redo();
}
