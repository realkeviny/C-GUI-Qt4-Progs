#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <QGLWidget>

class Tetrahedrone : public QGLWidget
{
    Q_OBJECT

public:
    Tetrahedrone(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;

private:
    void draw();
    int faceAtPosition(const QPoint& pos);

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;
};

#endif