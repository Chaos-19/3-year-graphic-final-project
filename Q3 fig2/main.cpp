#include <windows.h>
#include <GL/glut.h>
void display()
{

    glClearColor(1.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);


    for(float i = 0.99; i >= -0.08; i-=0.067)
    {

        glBegin(GL_QUADS);
        glColor3f(i+0.03,0.1,0.1);
        glVertex2f(i,i);
        glVertex2f(-i,i);
        glVertex2f(-i,-i);
        glVertex2f(i,-i);
    }

    glEnd();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Stairs");
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;

}
