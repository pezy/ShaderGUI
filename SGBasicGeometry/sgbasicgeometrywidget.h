#ifndef SGBASICGEOMETRYWIDGET_H
#define SGBASICGEOMETRYWIDGET_H

#include "sgbasicgeometry_global.h"

#include <QtWidgets/QOpenGLWidget>
#include <QtGui/QOpenGLShaderProgram>

class SGBASICGEOMETRY_EXPORT SGBasicGeometryWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    SGBasicGeometryWidget(QWidget *parent = nullptr);
    ~SGBasicGeometryWidget();
    QSize sizeHint() const override;

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

private:
    QMatrix4x4 m_matrix_;
    QOpenGLShaderProgram m_shader_program_;
    QVector<QVector3D> m_vertices_;
};

#endif // SGBASICGEOMETRYWIDGET_H
