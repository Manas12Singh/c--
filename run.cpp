#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QProcess>
#include <QFileDialog>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow window;
    QWidget centralWidget;
    QVBoxLayout layout(&centralWidget);
    QTreeWidget fileBrowser;
    QTextEdit codeEditor;
    QPushButton runButton("Run Code");

    QProcess terminal;

    // Create a top-level item for file browsing
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(&fileBrowser);
    rootItem->setText(0, "Files");

    // Connect the file browser's item double-click event
    QObject::connect(&fileBrowser, &QTreeWidget::itemDoubleClicked, [&](QTreeWidgetItem *item, int column)
                     {
        if (item->parent() == rootItem) {
            QString filePath = item->text(0);
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                codeEditor.setPlainText(file.readAll());
                file.close();
            }
        } });

    // Connect the "Run Code" button
    QObject::connect(&runButton, &QPushButton::clicked, [&]()
                     {
        QString code = codeEditor.toPlainText();
        terminal.start("bash", QStringList() << "-c" << "g++ -o myprogram -xc++ - && ./myprogram");
        terminal.write(code.toUtf8());
        terminal.closeWriteChannel();
        terminal.waitForFinished();
        QString output = terminal.readAll();
        codeEditor.append("\n--- Output ---\n" + output); });

    layout.addWidget(&fileBrowser);
    layout.addWidget(&codeEditor);
    layout.addWidget(&runButton);

    window.setCentralWidget(&centralWidget);
    window.setWindowTitle("C++ Code Runner");
    window.setGeometry(100, 100, 800, 600);

    window.show();
    return app.exec();
}
