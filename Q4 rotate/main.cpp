#include <GL/glut.h>
#include <iostream>

float lineVertices[4] = {0.0f, 0.0f, 0.6f, 0.6f};
float angle = 0.0f;

void drawLine() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.0, 0.0, 0.0); // Set line color to black

    glBegin(GL_LINES);
    glVertex2f(lineVertices[0], lineVertices[1]);
    glVertex2f(lineVertices[2], lineVertices[3]);
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'r') {
        angle += 45.0f;
    } else if (key == 'l') {
        angle -= 45.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotate Line with Keyboard");

    glClearColor(100.0, 100.0, 0.0, 0.0); // Set background color yellow
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(drawLine);
    glutKeyboardFunc(handleKeypress);

    glutMainLoop();

    return 0;
}
