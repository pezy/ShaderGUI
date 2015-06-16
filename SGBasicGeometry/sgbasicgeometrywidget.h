#ifndef SGBASICGEOMETRYWIDGET_H
#define SGBASICGEOMETRYWIDGET_H

#include "sgbasicgeometry_global.h"

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLShaderProgram>

class SGBASICGEOMETRY_EXPORT SGBasicGeometryWidget : public QGLWidget
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
    QGLShaderProgram m_shader_program_;
    QVector<QVector3D> m_vertices_;
};

#endif // SGBASICGEOMETRYWIDGET_H
