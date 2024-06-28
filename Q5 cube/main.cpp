#include <GL/glut.h>

float ver[8][3] =
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};


void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3fv(ver[a]);

    glColor3f(1.0,0.0,0.0);
    glVertex3fv(ver[b]);

    glColor3f(1.0,0.0,1.0);
    glVertex3fv(ver[c]);

    glColor3f(1.0,1.0,0.0);
    glVertex3fv(ver[d]);
    glEnd();
}


void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt
    (
        3, 3, 3,
        0, 0, 0,
        0, 0, 1
    );

    glRotatef(0, 1.0, 0.0, 0.0 );
    glRotatef(0, 0.0, 1.0, 0.0 );

    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
    return 0;
}
