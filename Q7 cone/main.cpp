#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846


float cameraX = 0.0f; // Camera position
float cameraY = -4.0f;
float cameraZ = 1.0f; // Move camera backwards initially

float angleX = 0.0f; // Rotation angles
float angleY = 0.0f;

void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

  glMatrixMode(GL_PROJECTION); // Set matrix mode to projection
  glLoadIdentity();              // Load identity matrix

  float aspectRatio = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
  gluPerspective(45.0f, aspectRatio, 0.05f, 10.0f); // Set perspective projection (adjust near plane)

  glMatrixMode(GL_MODELVIEW); // Set matrix mode to modelview

  // Apply camera transformations
  glLoadIdentity();
  gluLookAt(cameraX, cameraY, cameraZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

  // Apply cone rotation
  glRotatef(angleX, 1.0f, 0.0f, 0.0f);
  glRotatef(angleY, 0.0f, 1.0f, 0.0f);

  glColor3f(1.0f, 0.0f, 0.0f); // Set color to red

  // Define cone properties
  float radius = 0.5f; // Base radius (adjust for desired size)
  float height = 1.0f; // Height (adjust for desired height)
  int numSegments = 30; // Number of segments for smoother circle approximation (adjust as needed)

  // Enable depth buffer
  glEnable(GL_DEPTH_TEST);

  // Draw base circle
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < numSegments; i++) {
    float angle = 2.0f * PI * i / numSegments;
    float x = radius * cosf(angle);
    float y = radius * sinf(angle);
    glVertex3f(x, y, 0.0f); // Position at z = 0 for base
  }
  glEnd();

  // Draw lines from base circle to apex
  glBegin(GL_LINES);
  for (int i = 0; i < numSegments; i++) {
    float angle = 2.0f * PI * i / numSegments;
    float x = radius * cosf(angle);
    float y = radius * sinf(angle);
    glVertex3f(x, y, 0.0f); // Base circle vertex
    glVertex3f(0.0f, 0.0f, height); // Apex at center (0, 0, height)
  }
  glEnd();

  glDisable(GL_DEPTH_TEST); // Disable depth buffer (optional for efficiency)

  glFlush(); // Flush the buffer
}

void keyboard(unsigned char key, int x, int y) {
  float movementSpeed = 0.1f; // Adjust movement speed
  float rotationSpeed = 5.0f;  // Adjust rotation speed

  switch (key) {
    case 'w': // Move camera forward
      cameraZ -= movementSpeed;
      break;
    case 's': // Move camera backward
      cameraZ += movementSpeed;
      break;
    case 'a': // Move camera left
      cameraX -= movementSpeed;
      break;
    case 'd': // Move camera right
      cameraX += movementSpeed;
      break;
    case 'q': // Rotate cone around Y-axis (left)
      angleY -= rotationSpeed;
      break;
    case 'e': // Rotate cone around Y-axis (right)
      angleY += rotationSpeed;
      break;
    case 'r': // Reset camera and cone rotation
      cameraX = 0.0f;
      cameraY = 0.0f;
      cameraZ = 2.0f;
      angleX = 0.0f;
      angleY = 0.0f;
      break;
  }

  glutPostRedisplay(); // Request window update after changes
}
int main(int argc, char** argv) {
  glutInit(&argc, argv); // Initialize GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Set display mode with depth buffer
  glutInitWindowSize(800, 800); // Set window size
  glutInitWindowPosition(100, 100); // Set window position
  glutCreateWindow("3D Standing Cone"); // Create the window with a title

  glutDisplayFunc(display); // Register display function
 glutKeyboardFunc(keyboard); // Register keyboard callback
  glutMainLoop(); // Enter the event processing loop

  return 0;
}
