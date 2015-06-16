#include "sgbasicgeometrywidget.h"
#include "gl/GL.h"

SGBasicGeometryWidget::SGBasicGeometryWidget(QWidget *parent) : QGLWidget(QGLFormat(), parent)
{

}

SGBasicGeometryWidget::~SGBasicGeometryWidget()
{

}

QSize SGBasicGeometryWidget::sizeHint() const
{
    return QSize(640, 480);
}

void SGBasicGeometryWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    qglClearColor(QColor(Qt::black));

    m_shader_program_.addShaderFromSourceFile(QGLShader::Vertex, ":/triangles.vert");
    m_shader_program_.addShaderFromSourceFile(QGLShader::Fragment, ":/triangles.frag");
    m_shader_program_.link();

    //m_vertices_ << QVector2D(-0.90, -0.90) << QVector2D(0.85, -0.90) << QVector2D(-0.90, 0.85) << QVector2D(0.90, -0.85) << QVector2D(0.90, 0.90) << QVector2D(-0.85, 0.90);
    m_vertices_ << QVector3D(1, 0, -2) << QVector3D(0, 1, -2) << QVector3D(-1, 0, -2);
}

void SGBasicGeometryWidget::resizeGL(int width, int height)
{
    if (height == 0) height = 1;

    m_matrix_.setToIdentity();
    m_matrix_.perspective(60.0, static_cast<float>(width) / static_cast<float>(height), 0.001, 1000);
    
    glViewport(0, 0, width, height);
}

void SGBasicGeometryWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

    m_shader_program_.bind();
    m_shader_program_.setUniformValue("mvpMatrix", m_matrix_ * vMatrix * mMatrix);
    m_shader_program_.setUniformValue("color", QColor(Qt::white));
    m_shader_program_.setAttributeArray("vertex", m_vertices_.constData());
    m_shader_program_.enableAttributeArray("vertex");

    glDrawArrays(GL_TRIANGLES, 0, m_vertices_.size());
    m_shader_program_.disableAttributeArray("vertex");
    m_shader_program_.release();
}