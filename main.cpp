#include <iostream>
#include <math.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <chair.h>
#include <table.h>
#include <window.h>
#include <stdlib.h>
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

using namespace std;

// Function to Draw TubeLight
void KG_drawTubelight() {
	// Blackboard
	glBegin(GL_POLYGON);
        glColor3ub(192, 192, 192); /// Almost silver-cadre
        glVertex3f(-4.0f, 5.8f,-9.98f);
        glVertex3f(-4.0f, 6.7f,-9.98f);
        glVertex3f(3.0f, 6.7f,-9.98f);
        glVertex3f(3.0f, 5.8f,-9.98f);
	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(255, 255, 240); /// Almost silver-middle
        glVertex3f(-4.0f, 6.0f,-9.98f);
        glVertex3f(-4.0f, 6.5f,-9.98f);
        glVertex3f(3.0f, 6.5f,-9.98f);
        glVertex3f(3.0f, 6.0f,-9.98f);
	glEnd();
}


// angle de rotation pour la direction de la caméra
float angle = 0.0, yAngle = 0.0;

// vecteur réel représentant la direction de la caméra
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position de la camera
float x = -5.0f, z = 18.0f;
float roll = 0.0f;

//les mouvements de la souris
float halfWidth = (float)(WINDOW_WIDTH/2.0);
float halfHeight = (float)(WINDOW_HEIGHT/2.0);
float mouseX = 0.0f, mouseY = 0.0f;

void renderScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	// la camera
	gluLookAt(x, 2.5f, z,
		x + lx, 2.5f + ly, z + lz,
		roll + 0.0f, 2.5f, 0.0f);

    KG_drawTubelight();


    //mur
    glColor3f(0.9294f, 0.9216f, 0.8353f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//mut
    glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glEnd();



	///mur en avant
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	//mur avec la porte

	//gauche

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 6.0f);
	glVertex3f(10.0f, 0.0f, 6.0f);
	glEnd();

    //droite

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(10.0f, 0.0f, 3.0f);
	glVertex3f(10.0f, 7.0f, 3.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//haut au milieu

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(10.0f, 5.0f, 6.0f);
	glVertex3f(10.0f, 7.0f, 6.0f);
	glVertex3f(10.0f, 7.0f, 3.0f);
	glVertex3f(10.0f, 5.0f, 3.0f);
	glEnd();

	//la porte

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
    glVertex3f(10.0f, 5.0f, 6.01f);
	glVertex3f(10.0f, 5.0f, 3.01f);
	glEnd();

    //cadre a gauche

	glBegin(GL_LINES);
    glVertex3f(10.0f, 5.0f, 6.01f);
	glVertex3f(10.0f, 0.0f, 6.01f);
	glEnd();

	//cadre a droite

	glBegin(GL_LINES);
    glVertex3f(10.0f, 0.0f, 3.01f);
	glVertex3f(10.0f, 5.0f, 3.01f);
	glEnd();

	//plafond

	glColor3f(0.95f, 0.95f, 0.95f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glEnd();


	// les chaises des etudiants
	Chair studentChair[4][4];
	for (int i = -3; i <= 3; i+=2){
		for (int j = -3; j <= 3; j+=2) {
			glPushMatrix();
			glTranslatef(i*2.0, 0.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			studentChair[i][j].drawChair();
			glPopMatrix();
		}
	}

	// les tables des etudiants
	Table studentTable[4][4];
	for (int i = -3; i <= 3; i+=2){
		for (int j = -3; j <= 3; j+=2) {
			glPushMatrix();
			glTranslatef(i*2.0 + 0.3f, 1.2f, j * 2.0 + 1.2f);
			glScalef(0.4f, 0.4f, 0.4f);
			studentTable[i][j].drawTable();
			glPopMatrix();
		}
	}

	// le tableau  noir

	//le cadre

	glColor3f(0.4f, 0.2f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-0.2f, 2.0f, -9.99f);
	glVertex3f(-0.2f, 5.5f, -9.99f);
	glVertex3f(6.0f, 5.5f, -9.99f);
	glVertex3f(6.0f, 2.0f, -9.99f);
	glEnd();

	//le milieu du tableau

	glColor3f(0.149f, 0.149f, 0.149f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 2.2f, -9.98f);
	glVertex3f(0.0f, 5.3f, -9.98f);
	glVertex3f(5.8f, 5.3f, -9.98f);
	glVertex3f(5.8f, 2.2f, -9.98f);
	glEnd();

    //le cadre

	glColor3f(0.4f, 0.2f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-7.2f, 2.0f, -9.99f);
	glVertex3f(-7.2f, 5.5f, -9.99f);
	glVertex3f(-1.8f, 5.5f, -9.99f);
	glVertex3f(-1.8f, 2.0f, -9.99f);
	glEnd();

	//whiteboard-green

	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-7.0f, 2.2f, -9.98f);
	glVertex3f(-7.0f, 5.3f, -9.98f);
	glVertex3f(-2.0f, 5.3f, -9.98f);
	glVertex3f(-2.0f, 2.2f, -9.98f);
	glEnd();


	//Modèle de plancher
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(3.0f);
	for(int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f + i, 0.001f, -10.01f);
		glVertex3f(-10.0f + i, 0.001f, 10.01f);
		glEnd();
	}
	for(int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f, 0.001f, -10.01f + i);
		glVertex3f(10.0f, 0.001f, -10.01f + i);
		glEnd();
	}

	//fenetre
	Window w;
	w.drawWindow1();
	w.drawWindow2();
	w.drawWindowSill();
	glPushMatrix();
	glTranslatef( 0.0f, 0.0f, 8.0f);
	w.drawWindowSill();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 6.0f, 0.0);
	glScalef(0.3f, 0.3f, 0.3f);
	glPopMatrix();

	if(abs(mouseX) > 0.3){
		angle -= (0.004f * mouseX);
		lx = sin(angle);
		lz = -cos(angle);
	}
	if(abs(mouseY) > 0.3){
		if(abs(yAngle) < (M_PI/2)){
			yAngle += (0.002f * mouseY);
		}
		ly = sin(yAngle);
	}

	glutSwapBuffers();
}//la fin de renderscene


void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI/2.0) * fraction;
		z += -cos(angle - M_PI/2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI/2.0 + angle) * fraction;
		z += -cos(M_PI/2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}


void processMouseMovement(int xx, int yy){

	mouseX = (float)(halfWidth - xx)/halfWidth;
	mouseY = (float)(halfHeight - yy)/halfHeight;
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if(abs(yAngle) < (M_PI/2)){
		yAngle += (0.005f * mouseY);
	}
	ly = sin(yAngle);

}


void changeSize(int w, int h) {

	// Empêcher une division par zéro lorsque la fenêtre est trop courte

	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// utiliser la matrice de projection
	glMatrixMode(GL_PROJECTION);

	// Réinitialiser la matrice
	glLoadIdentity();

	// Définissez la fenêtre comme la fenêtre entière
	glViewport(0, 0, w, h);
	halfWidth = (float)(w/2.0);
	halfHeight = (float)(h/2.0);

	// Définissez la bonne perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Revenir à la Modelview

	glMatrixMode(GL_MODELVIEW);
}

void animate () {

    //rafraîchisser l'ecran
    glutPostRedisplay();
}

int main(int argc, char **argv) {

	// initialiser GLUT and creer la fenetre

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom-Elharem-Soufiane-ASEDS");

	// Activer la transparence

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	// Activer le lissage

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	//enregistrer les rappels

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(processMouseMovement);

	// initialiser OpenGL

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}



