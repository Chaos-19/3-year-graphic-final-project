#include <GL/glut.h>

void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glMatrixMode(GL_PROJECTION); // Set matrix mode to projection
    glLoadIdentity(); // Load identity matrix
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the orthographic viewing volume

    // Set line color to blue
    glColor3f(0.0, 0.0, 1.0);

// Draw blue lines around the window
    glBegin(GL_LINES);

// Top side
    glVertex2f(-1.0, 1.0);
    glVertex2f(1.0, 1.0);

// Bottom side
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);

// Left side
    glVertex2f(-2.0, -2.0);
    glVertex2f(-1.0, 2.0);

// Right side
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);

    glEnd();
    // Draw the 40 blue horizontal lines within the window size
    float y = 1;
    for (int i = 0; i < 40; i++)
    {
        glBegin(GL_LINES);
        glVertex2f(-1.0, y);
        glVertex2f(1.0, y);
        glEnd();
        y -= 0.05;
    }

    glFlush(); // Flush the buffer
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single buffer and RGB color mode
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("40 Blue Horizontal Lines and Blue Lines on All Sides with Black Background"); // Create the window with the given title

    glutDisplayFunc(display); // Register display function

    glutMainLoop(); // Enter the event processing loop

    return 0;
}
