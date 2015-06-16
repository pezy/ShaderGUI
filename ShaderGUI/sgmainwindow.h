#ifndef SGMAINWINDOW_H
#define SGMAINWINDOW_H

#include <QMainWindow>
#include "GeneratedFiles/ui_sgmainwindow.h"

class SGMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SGMainWindow(QWidget *parent = nullptr, Qt::WindowFlags windowFlags = Qt::Window);
    ~SGMainWindow();

private slots:
    void slotLoadShader();
    void slotShowTriangles();

private:
    void InitBasicTree();

private:
    Ui::SGMainWindow m_ui_;
};

#endif // SGMAINWINDOW_H
