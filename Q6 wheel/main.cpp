#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846

float wheelRadius = 0.5f; // Adjust for desired wheel size
int numSpokes = 10; // Number of spokes (adjust for desired appearance)
float rimWidth = 0.1f; // Width of the rim (adjust for desired thickness)

void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
  glClear(GL_COLOR_BUFFER_BIT);         // Clear color buffer

  // Set line width for spokes and rim
  glLineWidth(2.0f);

  // Draw rim (outer and inner circles)
  glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++) {
    float angle = i * 2.0f * PI / 360.0f;
    float x = wheelRadius * cosf(angle);
    float y = wheelRadius * sinf(angle);
    glVertex3f(x, y, 0.0f); // Outer rim
  }
  glEnd();

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++) {
    float angle = i * 2.0f * PI / 360.0f;
    float x = (wheelRadius - rimWidth) * cosf(angle);
    float y = (wheelRadius - rimWidth) * sinf(angle);
    glVertex3f(x, y, 0.0f); // Inner rim
  }
  glEnd();

  // Draw spokes
  glColor3f(0.5f, 0.5f, 0.5f); // Set color to gray

  for (int i = 0; i < numSpokes; i++) {
    float angle = i * 2.0f * PI / numSpokes;
    float spokeX1 = 0.0f;
    float spokeY1 = 0.0f;
    float spokeX2 = wheelRadius * cosf(angle);
    float spokeY2 = wheelRadius * sinf(angle);
    glBegin(GL_LINES);
    glVertex3f(spokeX1, spokeY1, 0.0f); // Center of wheel
    glVertex3f(spokeX2, spokeY2, 0.0f); // Spoke endpoint on rim
    glEnd();
  }

  glFlush(); // Flush the buffer
}

int main(int argc, char** argv) {
  glutInit(&argc, argv); // Initialize GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
  glutInitWindowSize(500, 500); // Set window size
  glutInitWindowPosition(100, 100); // Set window position
  glutCreateWindow("Wired Wheel"); // Create the window with a title

  glutDisplayFunc(display); // Register display function

  glutMainLoop(); // Enter the event processing loop

  return 0;
}
