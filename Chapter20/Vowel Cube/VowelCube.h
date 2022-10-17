#ifndef VOWELCUBE_H
#define VOWELCUBE_H

#include <QGLWidget>

class VowelCube : public QGLWidget
{
    Q_OBJECT

public:
    VowelCube(QWidget *parent = nullptr);
    ~VowelCube();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
private:
    void createGradient();
    void createGLObject();
    void drawBackground();
    void drawCube();
    void drawLegend();

    GLuint glObject;
    QRadialGradient gradient;
    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    GLfloat scaling;
    QPoint lastPos;
};

#endif