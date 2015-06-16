#include "sgmainwindow.h"

#include <QtWidgets/QMessageBox>
#include "../SGBasicGeometry/sgbasicgeometrywidget.h"

SGMainWindow::SGMainWindow(QWidget *parent, Qt::WindowFlags windowFlags)
    : QMainWindow(parent, windowFlags)
{
    m_ui_.setupUi(this);

    setWindowTitle("ShaderGUI FrameWork Demo");
    
    InitBasicTree();

    connect(m_ui_.m_actionLoad, &QAction::triggered, this, &SGMainWindow::slotLoadShader);
    connect(m_ui_.m_treeWidgetBasic, &QTreeWidget::itemClicked, this, &SGMainWindow::slotShowTriangles);
    
}

SGMainWindow::~SGMainWindow()
{

}

void SGMainWindow::slotLoadShader()
{
    QMessageBox msg;
    msg.setText("Load...");
    msg.exec();
}

void SGMainWindow::slotShowTriangles()
{
    auto basic_geometry_widget_ptr = new SGBasicGeometryWidget;
    m_ui_.m_mdiArea->addSubWindow(basic_geometry_widget_ptr);
    basic_geometry_widget_ptr->show();
}

void SGMainWindow::InitBasicTree()
{
    m_ui_.m_treeWidgetBasic->clear();
    m_ui_.m_treeWidgetBasic->setColumnCount(1);

    auto triangleItem = new QTreeWidgetItem(m_ui_.m_treeWidgetBasic);
    triangleItem->setText(0, "triangles");
    triangleItem->setCheckState(0, Qt::Unchecked);
}