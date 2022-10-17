#ifndef TEAPOTS_H
#define TEAPOTS_H

#include <QGLWidget>

class Teapots : public QGLWidget
{ 
    Q_OBJECT

public:
    Teapots(QWidget *parent = nullptr);
    ~Teapots();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    void createGLTeapotObject();
    void drawTeapot(GLfloat x, GLfloat y, GLfloat ambientR, GLfloat ambientG,
        GLfloat ambientB, GLfloat diifuseR, GLfloat diifuseG, GLfloat diifuseB,
        GLfloat specluarR, GLfloat specularG, GLfloat specularB, GLfloat shininess);
    void drawTeapots();
    QGLFramebufferObject* fbObject;
    GLuint glTeapotObject;
    QPoint rubberBandCorner1;
    QPoint rubberBandCorner2;
    bool rubberBandIsShown;
};


#endif